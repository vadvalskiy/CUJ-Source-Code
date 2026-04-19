[Caption: <f>vector<bool><d>]

        // CLASS vector<_Bool, allocator>
typedef unsigned int _Vbase;
const int _VBITS = CHAR_BIT * sizeof (_Vbase);
typedef allocator<_Vbase> _Bool_allocator;    ///
///typedef bool _Bool;

///template<class A>
///    class vector<bool, class A  = allocator<bool> > {
class vector<_Bool, _Bool_allocator> {    ///
public:
///    typedef A::rebind<bool>::other _Bool_allocator;
    typedef _Bool_allocator A;    ///
    typedef _Bool T;
    typedef vector<T, A> Mytype;
    typedef vector<_Vbase, A> _Vbtype;
    typedef A allocator_type;
    typedef A::size_type size_type;
    typedef A::difference_type difference_type;
        // CLASS reference
    class reference {
    public:
        reference()
            : Mask(0), Ptr(0) {}
        reference(size_t O, _Vbase *P)
            : Mask((_Vbase)1 << O), Ptr(P) {}
        reference& operator=(const reference& X)
            {return (*this = bool(X)); }
        reference& operator=(bool V)
            {if (V)
                *Ptr |= Mask;
            else
                *Ptr &= ~Mask;
            return (*this); }
        void flip()
            {*Ptr ^= Mask; }
        bool operator~() const
            {return (!bool(*this)); }
        operator bool() const
            {return ((*Ptr & Mask) != 0); }
    protected:
        _Vbase Mask, *Ptr;
        };
    typedef const reference const_reference;
    typedef bool value_type;
        // CLASS iterator
    class iterator : public _Ranit<_Bool, difference_type> {
    public:
        iterator()
            : Off(0), Ptr(0) {}
        iterator(size_t O, _Vbase *P)
            : Off(O), Ptr(P) {}
        reference operator*() const
            {return (reference(Off, Ptr)); }
        iterator& operator++()
            {Inc();
            return (*this); }
        iterator operator++(int)
            {iterator Tmp = *this;
            Inc();
            return (Tmp); }
        iterator& operator--()
            {Dec();
            return (*this); }
        iterator operator--(int)
            {iterator Tmp = *this;
            Dec();
            return (Tmp); }
        iterator& operator+=(difference_type N)
            {Off += N;
            Ptr += Off / _VBITS;
            Off %= _VBITS;
            return (*this); }
        iterator& operator-=(difference_type N)
            {return (*this += -N); }
        iterator operator+(difference_type N) const
            {iterator Tmp = *this;
            return (Tmp += N); }
        iterator operator-(difference_type N) const
            {iterator Tmp = *this;
            return (Tmp -= N); }
        difference_type operator-(const iterator X) const
            {return (_VBITS * (Ptr - X.Ptr)
                + (difference_type)Off
                - (difference_type)X.Off); }
        reference operator[](difference_type N) const
            {return (*(*this + N)); }
        bool operator==(const iterator& X) const
            {return (Ptr == X.Ptr && Off == X.Off); }
        bool operator!=(const iterator& X) const
            {return (!(*this == X)); }
        bool operator<(const iterator& X) const
            {return (Ptr < X.Ptr
                || Ptr == X.Ptr && Off < X.Off); }
        bool operator>(const iterator& X) const
            {return (X < *this); }
        bool operator<=(const iterator& X) const
            {return (!(X < *this)); }
        bool operator>=(const iterator& X) const
            {return (!(*this < X)); }
    protected:
        void Dec()
            {if (Off != 0)
                --Off;
            else
                Off = _VBITS - 1, --Ptr; }
        void Inc()
            {if (Off < _VBITS - 1)
                ++Off;
            else
                Off = 0, ++Ptr; }
        size_t Off;
        _Vbase *Ptr;
        };
        // CLASS const_iterator
    class const_iterator : public iterator {
    public:
        const_iterator()
            : iterator() {}
        const_iterator(size_t O, const _Vbase *P)
            : iterator(O, (_Vbase *)P) {}
        const_iterator(const iterator& X)
            : iterator(X) {}
        const_reference operator*() const
            {return (reference(Off, Ptr)); }
        const_iterator& operator++()
            {Inc();
            return (*this); }
        const_iterator operator++(int)
            {const_iterator Tmp = *this;
            Inc();
            return (Tmp); }
        const_iterator& operator--()
            {Dec();
            return (*this); }
        const_iterator operator--(int)
            {const_iterator Tmp = *this;
            Dec();
            return (Tmp); }
        const_iterator& operator+=(difference_type N)
            {Off += N;
            Ptr += Off / _VBITS;
            Off %= _VBITS;
            return (*this); }
        const_iterator& operator-=(difference_type N)
            {return (*this += -N); }
        const_iterator operator+(difference_type N) const
            {const_iterator Tmp = *this;
            return (Tmp += N); }
        const_iterator operator-(difference_type N) const
            {const_iterator Tmp = *this;
            return (Tmp -= N); }
        difference_type operator-(const const_iterator X) const
            {return (_VBITS * (Ptr - X.Ptr)
                + (difference_type)Off
                - (difference_type)X.Off); }
        const_reference operator[](difference_type N) const
            {return (*(*this + N)); }
        bool operator==(const const_iterator& X) const
            {return (Ptr == X.Ptr && Off == X.Off); }
        bool operator!=(const const_iterator& X) const
            {return (!(*this == X)); }
        bool operator<(const const_iterator& X) const
            {return (Ptr < X.Ptr
                || Ptr == X.Ptr && Off < X.Off); }
        bool operator>(const const_iterator& X) const
            {return (X < *this); }
        bool operator<=(const const_iterator& X) const
            {return (!(X < *this)); }
        bool operator>=(const const_iterator& X) const
            {return (!(*this < X)); }
        };
    typedef reverse_iterator<const_iterator, value_type,
        const_reference, const_reference *, difference_type>
            const_reverse_iterator;
    typedef reverse_iterator<iterator, value_type,
        reference, reference *, difference_type>
            reverse_iterator;
    explicit vector(const A& Al = A())
        : Size(0), Vec(Al) {}
    explicit vector(size_type N, const bool V = false,
        const A& Al = A())
        : Vec(Nw(N), V ? -1 : 0, Al) {Trim(N); }
///    template<class It>
    typedef const_iterator It;    ///
    vector(It F, It L, const A& Al = A())
        : Size(0), Vec(Al)
        {insert(begin(), F, L); }
    ~vector()
        {Size = 0; }
    void reserve(size_type N)
        {Vec.reserve(Nw(N)); }
    size_type capacity() const
        {return (Vec.capacity() * _VBITS); }
    iterator begin()
        {return (iterator(0, Vec.begin())); }
    const_iterator begin() const
        {return (const_iterator(0, Vec.begin())); }
    iterator end()
        {iterator Tmp = begin();
        if (0 < Size)
            Tmp += Size;
        return (Tmp); }
    const_iterator end() const
        {const_iterator Tmp = begin();
        if (0 < Size)
            Tmp += Size;
        return (Tmp); }
    reverse_iterator rbegin()
        {return (reverse_iterator(end())); }
    const_reverse_iterator rbegin() const
        {return (const_reverse_iterator(end())); }
    reverse_iterator rend()
        {return (reverse_iterator(begin())); }
    const_reverse_iterator rend() const
        {return (const_reverse_iterator(begin())); }
    void resize(size_type N, bool X = false)
        {if (size() < N)
            insert(end(), N - size(), X);
        else if (N < size())
            erase(begin() + N, end()); }
    size_type size() const
        {return (Size); }
    size_type max_size() const
        {return (Vec.max_size() * _VBITS); }
    bool empty() const
        {return (size() == 0); }
    A get_allocator() const
        {return (Vec.get_allocator()); }
    const_reference at(size_type P) const
        {if (size() <= P)
            _Xran();
        return (*(begin() + P)); }
    reference at(size_type P)
        {if (size() <= P)
            _Xran();
        return (*(begin() + P)); }
    const_reference operator[](size_type P) const
        {return (*(begin() + P)); }
    reference operator[](size_type P)
        {return (*(begin() + P)); }
    reference front()
        {return (*begin()); }
    const_reference front() const
        {return (*begin()); }
    reference back()
        {return (*(end() - 1)); }
    const_reference back() const
        {return (*(end() - 1)); }
    void push_back(const bool X)
        {insert(end(), X); }
    void pop_back()
        {erase(end() - 1); }
///    template<class It>
    void assign(It F, It L)
        {erase(begin(), end());
        insert(begin(), F, L); }
///    template<class Pd, class T2>
///        void assign(Pd N, const T2& X = T2())
    void assign(size_type N, const bool X = false)    ///
        {erase(begin(), end());
        insert(begin(), N, X); }
    iterator insert(iterator P, const bool X = false)
        {size_type O = P - begin();
        insert(P, 1, X);
        return (begin() + O); }
    void insert(iterator P, size_type M, const bool X)
        {if (0 < M)
            {if (capacity() - size() < M)
                {size_type O = P - begin();
                Vec.resize(Nw(size() + M), 0);
                P = begin() + O; }
            copy_backward(P, end(), end() + M);
            fill(P, P + M, X);
            Size += M; }}
///    template<class It>
///        void insert(iterator P, It F, It L)
///        {insert(P, F, L, _Iter_cat(F)); }
///    template<class It>
///        void insert(iterator P, It F, It L,
///            input_iterator_tag)
///        {size_type O = P - begin();
///        for (; F != L; ++F, ++O)
///            insert(begin() + O, *F); }
///    template<class It>
///        void insert(iterator P, It F, It L,
///            forward_iterator_tag)
    void insert(iterator P, It F, It L)    ///
        {size_type M = 0;
        _Distance(F, L, M);
        if (0 < M)
            {if (capacity() - size() < M)
                {size_type O = P - begin();
                Vec.resize(Nw(size() + M), 0);
                P = begin() + O; }
            copy_backward(P, end(), end() + M);
            copy(F, L, P);
            Size += M; }}
    iterator erase(iterator P)
        {copy(P + 1, end(), P);
        Trim(Size - 1);
        return (P); }
    iterator erase(iterator F, iterator L)
        {iterator S = copy(L, end(), F);
        Trim(S - begin());
        return (F); }
    void clear()
        {erase(begin(), end()); }
    void flip()
        {for (_Vbtype::iterator S = Vec.begin();
            S != Vec.end(); ++S)
            *S = ~*S;
        Trim(Size); }
    bool operator==(const Mytype& X) const
        {return (Size == X.Size && Vec == X.Vec); }
    bool operator!=(const Mytype& X) const
        {return (!(*this == X)); }
    bool operator<(const Mytype& X) const
        {return (Size < X.Size
            || Size == X.Size && Vec < X.Vec); }
    bool operator>(const Mytype& X) const
        {return (X < *this); }
    bool operator<=(const Mytype& X) const
        {return (!(X < *this)); }
    bool operator>=(const Mytype& X) const
        {return (!(*this < X)); }
    void swap(Mytype& X)
        {STD swap(Size, X.Size);
        Vec.swap(X.Vec); }
    friend void swap(Mytype& X, Mytype& Y)
        {X.swap(Y); }
    static void swap(reference X, reference Y)
        {bool V = X;
        X = Y;
        Y = V; }
protected:
    static size_type Nw(size_type N)
        {return ((N + _VBITS - 1) / _VBITS); }
    void Trim(size_type N)
        {size_type M = Nw(N);
        if (M < Vec.size())
            Vec.erase(Vec.begin() + M, Vec.end());
        Size = N;
        N %= _VBITS;
        if (0 < N)
            Vec[M - 1] &= ((_Vbase)1 << N) - 1; }
    void _Xran() const
        {throw out_of_range("invalid vector<bool> subscript"); }
    size_type Size;
    _Vbtype Vec;
    };



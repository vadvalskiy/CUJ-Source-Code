#define DEQUEMAPSIZ    2
#define DEQUESIZ (4096 < sizeof (Ty) ? 1 : 4096 / sizeof (Ty))

        // TEMPLATE CLASS deque
template<class Ty, class A = allocator<Ty> >
    class deque {
public:
    typedef deque<Ty, A> Myt;
    typedef A allocator_type;
    typedef typename A::size_type size_type;
    typedef typename A::difference_type difference_type;
    typedef typename A::pointer Tptr;
    typedef typename A::const_pointer Ctptr;
    typedef A::rebind<Tptr>::other::pointer Mapptr;
    typedef typename A::reference reference;
    typedef typename A::const_reference const_reference;
    typedef typename A::value_type value_type;

        // CLASS iterator
    class const_iterator;
    class iterator : public Ranit<Ty, difference_type,
        Tptr, reference> {
    public:
        friend class deque<Ty, A>;
        friend class const_iterator;
        iterator()
            : First(0), Last(0), Next(0), Map(0) {}
        iterator(Tptr P, Mapptr M)
            : First(*M), Last(*M + DEQUESIZ),
                Next(P), Map(M) {}
        reference operator*() const
            {return (*Next); }
        Tptr operator->() const
            {return (&**this); }
        iterator& operator++()
            {if (++Next == Last)
                {First = *++Map;
                Last = First + DEQUESIZ;
                Next = First; }
            return (*this); }
        iterator operator++(int)
            {iterator Tmp = *this;
            ++*this;
            return (Tmp); }
        iterator& operator--()
            {if (Next == First)
                {First = *--Map;
                Last = First + DEQUESIZ;
                Next = Last; }
            --Next;
            return (*this); }
        iterator operator--(int)
            {iterator Tmp = *this;
            --*this;
            return (Tmp); }
        iterator& operator+=(difference_type N)
            {Add(N);
            return (*this); }
        iterator& operator-=(difference_type N)
            {return (*this += -N); }
        iterator operator+(difference_type N) const
            {iterator Tmp = *this;
            return (Tmp += N); }
        iterator operator-(difference_type N) const
            {iterator Tmp = *this;
            return (Tmp -= N); }
        difference_type operator-(const iterator& X) const
            {return (Map == X.Map ? Next - X.Next
                : DEQUESIZ * (Map - X.Map - 1)
                + (Next - First) + (X.Last - X.Next)); }
        reference operator[](difference_type N) const
            {return (*(*this + N)); }
        bool operator==(const iterator& X) const
            {return (Next == X.Next); }
        bool operator!=(const iterator& X) const
            {return (!(*this == X)); }
        bool operator<(const iterator& X) const
            {return (Map < X.Map
                || Map == X.Map && Next < X.Next); }
        bool operator<=(const iterator& X) const
            {return (!(X < *this)); }
        bool operator>(const iterator& X) const
            {return (X < *this); }
        bool operator>=(const iterator& X) const
            {return (!(*this < X)); }
    protected:
        void Add(difference_type N)
            {difference_type Off = N + Next - First;
            difference_type Moff = (0 <= Off)
                ? Off / DEQUESIZ
                : -((DEQUESIZ - 1 - Off) / DEQUESIZ);
            if (Moff == 0)
                Next += N;
            else
                {Map += Moff;
                First = *Map;
                Last = First + DEQUESIZ;
                Next = First + (Off - Moff * DEQUESIZ); }}
        Tptr First, Last, Next;
        Mapptr Map;
        };

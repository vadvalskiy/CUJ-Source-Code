------------------ Listing 2: The template class basic_string -------

template<class _E,
        class _T = string_char_traits<_E>,
        class _A = _ALLOCATOR(_E)>
        class basic_string {
public:
        typedef basic_string<_E, _T, _A> _Myt;
        typedef _T traits_type;
        typedef _SIZ_TYPE(_E, _A)::size_type size_type;
        typedef _SIZ_TYPE(_E, _A)::difference_type difference_type;
        typedef _PTR_TYPE(_E, _A)::pointer pointer;
        typedef _PTR_TYPE(_E, _A)::const_pointer const_pointer;
        typedef _PTR_TYPE(_E, _A)::reference reference;
        typedef _PTR_TYPE(_E, _A)::const_reference const_reference;
        typedef _PTR_TYPE(_E, _A)::value_type value_type;
        typedef _PTR_TYPE(_E, _A)::pointer iterator;
        typedef _PTR_TYPE(_E, _A)::const_pointer const_iterator;
        typedef reverse_iterator<const_iterator, value_type,
                const_reference, difference_type> const_reverse_iterator;
        typedef reverse_iterator<iterator, value_type,
                reference, difference_type> reverse_iterator;
#if _HAS_STATIC_MEMBER_INIT
        static const size_type npos = -1;
#else
        enum _Npos_enum {npos = ~0};    // CAN HAVE WRONG SIZE/TYPE
#endif
        basic_string(_A& _Al = _A())
                : allocator(_Al) {_Tidy(); }
        basic_string(const _Myt& _X, size_type _P = 0,
                size_type _N = npos, _A& _Al = _A())
                : allocator(_Al) {_Tidy(), assign(_X, _P, _N); }
        basic_string(const _E *_S, size_type _N = npos,
                _A& _Al = _A())
                : allocator(_Al) {_Tidy(), assign(_S, _N); }
        basic_string(size_type _N, _E _C, _A& _Al = _A())
                : allocator(_Al) {_Tidy(), assign(_N, _C); }
#if _HAS_MEMBER_TEMPLATES
        template<class _It>
#else
        typedef const_iterator _It;
#endif
                basic_string(_It _F, _It _L, _A& _Al = _A())
                : allocator(_Al) {_Tidy(); assign(_F, _L); }
        ~basic_string()
                {_Tidy(true); }
        _Myt& operator=(const _Myt& _X)
                {return (assign(_X)); }
        _Myt& operator=(const _E *_S)
                {return (assign(_S)); }
        _Myt& operator=(_E _C)
                {return (assign(1, _C)); }
        _Myt& operator+=(const _Myt& _X)
                {return (append(_X)); }
        _Myt& operator+=(const _E *_S)
                {return (append(_S)); }
        _Myt& operator+=(_E _C)
                {return (append(1, _C)); }
        _Myt& append(const _Myt& _X, size_type _P = 0,
                size_type _M = npos)
                {if (_X.size() < _P)
                        _Xran();
                size_type _N = _X.size() - _P;
                if (_N < _M)
                        _M = _N;
                if (npos - _Len <= _M)
                        _Xlen();
                if (0 < _M && _Grow(_N = _Len + _M))
                        {_T::copy(_Ptr + _Len, &_X.c_str()[_P], _M);
                        _Eos(_N); }
                return (*this); }
        _Myt& append(const _E *_S, size_type _M = npos)
                {if (_M == (size_type)npos)
                        _M = _T::length(_S);
                if (npos - _Len <= _M)
                        _Xlen();
                size_type _N;
                if (0 < _M && _Grow(_N = _Len + _M))
                        {_T::copy(_Ptr + _Len, _S, _M);
                        _Eos(_N); }
                return (*this); }
        _Myt& append(size_type _M, _E _C = _T::eos())
                {if (npos - _Len <= _M)
                        _Xlen();
                size_type _N;
                if (0 < _M && _Grow(_N = _Len + _M))
                        {_Memset(_Ptr + _Len, _C, _M);
                        _Eos(_N); }
                return (*this); }
#if _HAS_MEMBER_TEMPLATES
        template<class _It>
#endif
                _Myt& append(_It _F, _It _L)
                {insert(end(), _F, _L);
                return (*this); }
        _Myt& assign(const _Myt& _X, size_type _P = 0,
                size_type _M = npos)
                {if (_X.size() < _P)
                        _Xran();
                size_type _N = _X.size() - _P;
                if (_M < _N)
                        _N = _M;
                if (this == &_X)
                        remove(_P + _N), remove(0, _P);
                else if (_Grow(_N, true))
                        {_T::copy(_Ptr, &_X.c_str()[_P], _N);
                        _Eos(_N); }
                return (*this); }
        _Myt& assign(const _E *_S, size_type _N = npos)
                {if (_N == (size_type)npos)
                        _N = _T::length(_S);
                if (_Grow(_N, true))
                        {_T::copy(_Ptr, _S, _N);
                        _Eos(_N); }
                return (*this); }
        _Myt& assign(size_type _N, _E _C = _T::eos())
                {if (_N == (size_type)npos)
                        _Xlen();
                if (_Grow(_N, true))
                        {_Memset(_Ptr, _C, _N);
                        _Eos(_N); }
                return (*this); }
#if _HAS_MEMBER_TEMPLATES
        template<class _It>
#endif
                _Myt& assign(_It _F, _It _L)
                {return (replace(begin(), end(), _F, _L)); }
        _Myt& insert(size_type _P0, const _Myt& _X, size_type _P = 0,
                size_type _M = npos)
                {if (_Len < _P0 || _X.size() < _P)
                        _Xran();
                size_type _N = _X.size() - _P;
                if (_N < _M)
                        _M = _N;
                if (npos - _Len <= _M)
                        _Xlen();
                if (0 < _M && _Grow(_N = _Len + _M))
                        {_Memmove(_Ptr + _P0 + _M, _Ptr + _P0,
                                _Len - _P0);
                        _T::copy(_Ptr + _P0, &_X.c_str()[_P], _M);
                        _Eos(_N); }
                return (*this); }
        _Myt& insert(size_type _P0, const _E *_S,
                size_type _M = npos)
                {if (_Len < _P0)
                        _Xran();
                if (_M == (size_type)npos)
                        _M = _T::length(_S);
                if (npos - _Len <= _M)
                        _Xlen();
                size_type _N;
                if (0 < _M && _Grow(_N = _Len + _M))
                        {_Memmove(_Ptr + _P0 + _M, _Ptr + _P0,
                                _Len - _P0);
                        _T::copy(_Ptr + _P0, _S, _M);
                        _Eos(_N); }
                return (*this); }
        _Myt& insert(size_type _P0, size_type _M,
                _E _C = _T::eos())
                {if (_Len < _P0)
                        _Xran();
                if (npos - _Len <= _M)
                        _Xlen();
                size_type _N;
                if (0 < _M && _Grow(_N = _Len + _M))
                        {_Memmove(_Ptr + _P0 + _M, _Ptr + _P0,
                                _Len - _P0);
                        _Memset(_Ptr + _P0, _C, _M);
                        _Eos(_N); }
                return (*this); }
        iterator insert(iterator _P, _E _C = _T::eos())
                {size_type _P0 = _P - begin();
                insert(_P0, 1, _C);
                return (begin() + _P0); }
        void insert(iterator _P, size_type _M,
                _E _C = _T::eos())
                {size_type _P0 = _P - begin();
                insert(_P0, _M, _C); }
#if _HAS_MEMBER_TEMPLATES
        template<class _It>
#endif
                void insert(iterator _P, _It _F, _It _L)
                {size_type _M = 0;
                distance(_F, _L, _M);
                insert(size_type(_P - begin()), (const _E *)_F, _M); }
        _Myt& remove(size_type _P0 = 0, size_type _M = npos)
                {if (_Len < _P0)
                        _Xran();
                if (_Len - _P0 < _M)
                        _M = _Len - _P0;
                if (0 < _M)
                        {_Memmove(_Ptr + _P0, _Ptr + _P0 + _M,
                                _Len - _P0 - _M);
                        size_type _N = _Len - _M;
                        if (_Grow(_N))
                                _Eos(_N); }
                return (*this); }
        _Myt& remove(iterator _P)
                {return (remove(_P - begin(), 1)); }
        _Myt& remove(iterator _F, iterator _L)
                {return (remove(_F - begin(), _L - _F)); }
        _Myt& replace(size_type _P0, size_type _N0, const _Myt& _X,
                size_type _P = 0, size_type _M = npos)
                {if (_Len < _P0 || _X.size() < _P)
                        _Xran();
                size_type _N = _X.size() - _P;
                if (_N < _M)
                        _M = _N;
                if (npos - _M <= _Len - _N0)
                        _Xlen();
                size_type _Nm = _Len - _N0 - _P0;
                if (_M < _N0)
                        _Memmove(_Ptr + _P0 + _M, _Ptr + _P0 + _N0, _Nm);
                if ((0 < _M || 0 < _N0) && _Grow(_N = _Len + _M - _N0))
                        {if (_N0 < _M)
                                _Memmove(_Ptr + _P0 + _M, _Ptr + _P0 + _N0,
                                        _Nm);
                        _T::copy(_Ptr + _P0, &_X.c_str()[_P], _M);
                        _Eos(_N); }
                return (*this); }
        _Myt& replace(size_type _P0, size_type _N0, const _E *_S,
                size_type _M = npos)
                {if (_Len < _P0)
                        _Xran();
                if (_M == (size_type)npos)
                        _M = _T::length(_S);
                if (npos - _M <= _Len - _N0)
                        _Xlen();
                size_type _Nm = _Len - _N0 - _P0;
                if (_M < _N0)
                        _Memmove(_Ptr + _P0 + _M, _Ptr + _P0 + _N0, _Nm);
                size_type _N;
                if ((0 < _M || 0 < _N0) && _Grow(_N = _Len + _M - _N0))
                        {if (_N0 < _M)
                                _Memmove(_Ptr + _P0 + _M, _Ptr + _P0 + _N0,
                                        _Nm);
                        _T::copy(_Ptr + _P0, _S, _M);
                        _Eos(_N); }
                return (*this); }
        _Myt& replace(size_type _P0, size_type _N0,     size_type _M,
                _E _C = _T::eos())
                {if (_Len < _P0)
                        _Xran();
                if (_Len - _P0 < _N0)
                        _N0 = _Len - _P0;
                if (npos - _M <= _Len - _N0)
                        _Xlen();
                size_type _Nm = _Len - _N0 - _P0;
                if (_M < _N0)
                        _Memmove(_Ptr + _P0 + _M, _Ptr + _P0 + _N0, _Nm);
                size_type _N;
                if ((0 < _M || 0 < _N0) && _Grow(_N = _Len + _M - _N0))
                        {if (_N0 < _M)
                                _Memmove(_Ptr + _P0 + _M, _Ptr + _P0 + _N0,
                                        _Nm);
                        _Memset(_Ptr + _P0, _C, _M);
                        _Eos(_N); }
                return (*this); }
        _Myt& replace(iterator _F, iterator _L, const _Myt& _X)
                {return (replace(size_type(_F - begin()),
                        size_type(_L - _F), _X)); }
        _Myt& replace(iterator _F, iterator _L, const _E *_S,
                size_type _M = npos)
                {return (replace(size_type(_F - begin()),
                        size_type(_L - _F), _S, _M)); }
        _Myt& replace(iterator _F, iterator _L, size_type _M,
                _E _C = _T::eos())
                {return (replace(size_type(_F - begin()),
                        size_type(_L - _F), _M, _C)); }
#if _HAS_MEMBER_TEMPLATES
        template<class _It>
#endif
                _Myt& replace(iterator _F1, iterator _L1,
                        _It _F2, _It _L2)
                {size_type _M = 0;
                distance(_F2, _L2, _M);
                return (replace(size_type(_F1 - begin()),
                        size_type(_L1 - _F1), (const _E *)_F2, _M)); }
        iterator begin()
                {return (_Ptr); }
        const_iterator begin() const
                {return (begin()); }
        iterator end()
                {return (_Ptr == 0 ? 0 : _Ptr + _Len); }
        const_iterator end() const
                {return (end()); }
        reverse_iterator rbegin()
                {return (reverse_iterator(end())); }
        const_reverse_iterator rbegin() const
                {return (const_reverse_iterator(end())); }
        reverse_iterator rend()
                {return (reverse_iterator(begin())); }
        const_reverse_iterator rend() const
                {return (const_reverse_iterator(begin())); }
        const_reference at(size_type _P0) const
                {if (_Len <= _P0)
                        _Xran();
                return (_Ptr[_P0]); }
        reference at(size_type _P0)
                {if (_Len <= _P0)
                        _Xran();
                return (_Ptr[_P0]); }
        const_reference operator[](size_type _P0) const
                {return (_Ptr[_P0]); }
        reference operator[](size_type _P0)
                {_Grow(_Len);
                return (_Ptr[_P0]); }
        const _E *c_str() const
                {return (_Ptr != 0 ? _Ptr : _Null()); }
        const _E *data() const
                {return (0 < _Len ? _Ptr : 0); }
        size_type length() const
                {return (_Len); }
        size_type size() const
                {return (_Len); }
        size_type max_size() const
                {size_type _N = _MAX_SIZE(_E, allocator);
                return (_N <= 2 ? 1 : _N - 2); }
        void resize(size_type _N, _E _C = _T::eos())
                {_N <= _Len ? remove(_N) : append(_N - _Len, _C); }
        size_type capacity() const
                {return (_Res); }
        void reserve(size_type _N)
                {if (_Res < _N)
                        _Grow(_N), _Eos(_Len); }
        bool empty() const
                {return (_Len == 0); }
        size_type copy(_E *_S, size_type _N,
                size_type _P0 = 0) const
                {if (_Len < _P0)
                        _Xran();
                if (_Len - _P0 < _N)
                        _N = _Len - _P0;
                _T::copy(_S, _Ptr + _P0, _N);
                return (_N); }
        void swap(_Myt& _X)
                {_E *_Tp = _Ptr; _Ptr = _X._Ptr, _X._Ptr = _Tp;
                size_type _Tl = _Len; _Len = _X._Len, _X._Len = _Tl;
                size_type _Tr = _Res; _Res = _X._Res, _X._Res = _Tr; }
        size_type find(const _Myt& _X, size_type _P = 0) const
                {return (find(_X.c_str(), _P, _X.size())); }
        size_type find(const _E *_S, size_type _P = 0,
                size_type _N = npos) const
                {if (_Len0(_N, _S))
                        return (0);
                size_type _Nm;
                if (_P < _Len && _N <= (_Nm = _Len - _P))
                        {const _E *_U, *_V;
                        for (_Nm -= _N - 1, _V = _Ptr + _P;
                                (_U = _Memchr(_V, *_S, _Nm)) != 0;
                                _Nm -= _U - _V + 1, _V = _U + 1)
                                if (_T::compare(_U, _S, _N) == 0)
                                        return (_U - _Ptr); }
                return (npos); }
        size_type find(_E _C, size_type _P = 0) const
                {return (find((const _E *)&_C, _P, 1)); }
        size_type rfind(const _Myt& _X, size_type _P = npos) const
                {return (rfind(_X.c_str(), _P, _X.size())); }
        size_type rfind(const _E *_S, size_type _P = npos,
                size_type _N = npos) const
                {if (_Len0(_N, _S))
                        return (0);
                if (_N <= _Len)
                        for (const _E *_U = _Ptr
                                + (_P < _Len - _N ? _P : _Len - _N); ; --_U)
                                if (*_U == *_S && _T::compare(_U, _S, _N) == 0)
                                        return (_U - _Ptr);
                                else if (_U == _Ptr)
                                        break;
                return (npos); }
        size_type rfind(_E _C, size_type _P = npos) const
                {return (rfind((const _E *)&_C, _P, 1)); }
        size_type find_first_of(const _Myt& _X,
                size_type _P = 0) const
                {return (find_first_of(_X.c_str(), _P, _X.size())); }
        size_type find_first_of(const _E *_S, size_type _P = 0,
                size_type _N = npos) const
                {if (_Len0(_N, _S))
                        return (0);
                if (_P < _Len)
                        {const _E *const _V = _Ptr + _Len;
                        for (const _E *_U = _Ptr + _P; _U < _V; ++_U)
                                if (_Memchr(_S, *_U, _N) != 0)
                                        return (_U - _Ptr); }
                return (npos); }
        size_type find_first_of(_E _C, size_type _P = 0) const
                {return (find((const _E *)&_C, _P, 1)); }
        size_type find_last_of(const _Myt& _X,
                size_type _P = npos) const
                {return (find_last_of(_X.c_str(), _P, _X.size())); }
        size_type find_last_of(const _E *_S,
                size_type _P = npos, size_type _N = npos) const
                {if (_Len0(_N, _S))
                        return (0);
                if (0 < _Len)
                        for (const _E *_U = _Ptr
                                + (_P < _Len ? _P : _Len - 1); ; --_U)
                                if (_Memchr(_S, *_U, _N) != 0)
                                        return (_U - _Ptr);
                                else if (_U == _Ptr)
                                        break;
                return (npos); }
        size_type find_last_of(_E _C, size_type _P = npos) const
                {return (rfind((const _E *)&_C, _P, 1)); }
        size_type find_first_not_of(const _Myt& _X,
                size_type _P = 0) const
                {return (find_first_not_of(_X.c_str(), _P,
                        _X.size())); }
        size_type find_first_not_of(const _E *_S, size_type _P = 0,
                size_type _N = npos) const
                {if (_Len0(_N, _S))
                        return (0);
                if (_P < _Len)
                        {const _E *const _V = _Ptr + _Len;
                        for (const _E *_U = _Ptr + _P; _U < _V; ++_U)
                                if (_Memchr(_S, *_U, _N) == 0)
                                        return (_U - _Ptr); }
                return (npos); }
        size_type find_first_not_of(_E _C, size_type _P = 0) const
                {return (find_first_not_of((const _E *)&_C, _P, 1)); }
        size_type find_last_not_of(const _Myt& _X,
                size_type _P = npos) const
                {return (find_last_not_of(_X.c_str(), _P,
                        _X.size())); }
        size_type find_last_not_of(const _E *_S, size_type _P = npos,
                 size_type _N = npos) const
                {if (_Len0(_N, _S))
                        return (0);
                if (0 < _Len)
                        for (const _E *_U = _Ptr
                                + (_P < _Len ? _P : _Len - 1); ; --_U)
                                if (_Memchr(_S, *_U, _N) == 0)
                                        return (_U - _Ptr);
                                else if (_U == _Ptr)
                                        break;
                return (npos); }
        size_type find_last_not_of(_E _C, size_type _P = npos) const
                {return (find_last_not_of((const _E *)&_C, _P, 1)); }
        _Myt substr(size_type _P = 0, size_type _N = npos) const
                {return (_Myt(*this, _P, _N)); }
        int compare(const _Myt& _X, size_type _P = 0,
                size_type _M = npos) const
                {if (_Len < _P)
                        _Xran();
                size_type _N = _Len - _P;
                if (_X.size() < _M)
                        _M = _X.size();
                size_type _Ans = _T::compare(_Ptr + _P, _X.c_str(),
                        _N < _M ? _N : _M);
                return (_Ans != 0 ? _Ans : _N < _M ? -1
                        : _N == _M ? 0 : +1); }
        int compare(const _E *_S, size_type _P = 0,
                size_type _M = npos) const
                {if (_Len < _P)
                        _Xran();
                size_type _N = _Len - _P;
                if (_M == (size_type)npos)
                        _M = _T::length(_S);
                size_type _Ans = _T::compare(_Ptr + _P, _S,
                        _N < _M ? _N : _M);
                return (_Ans != 0 ? _Ans : _N < _M ? -1
                        : _N == _M ? 0 : +1); }
protected:
        _A allocator;
private:
        enum {_MIN_SIZE = sizeof (_E) <= 32 ? 31 : 7};
        void _Eos(_N)
                {_T::assign(_Ptr[_Len = _N], _T::eos()); }
        bool _Grow(size_type _N, bool _Trim = false)
                {if (max_size() < _N)
                        _Xlen();
                if (_N == 0)
                        _Tidy(true);
                else
                        {_Res = _N < _Len ? _Len : _N;
                        _E *_S = _ALLOCATE(_E, allocator, _Res + 1);
                        _Ptr = _T::copy(_S, _Ptr, _Len + 1); }
                size_type _Os = _Ptr == 0 ? 0 : _Res;
                if (_N == 0)
                        {if (_Trim && _MIN_SIZE < _Os)
                                _Tidy(true);
                        else if (_Ptr != 0)
                                _Eos(0);
                        return (0); }
                else if (_N == _Os || _N < _Os && !_Trim)
                        return (1);
                else
                        {size_type _Ns = _Ptr == 0 && _N < _Res ? _Res : _N;
                        if (max_size() < (_Ns |= _MIN_SIZE))
                                _Ns = max_size();
                        _E *_S;
                        _TRY_BEGIN
                                _S = _ALLOCATE(_E, allocator, _Ns + 1);
                        _CATCH_ALL
                                _Ns = _N;
                                _S = _ALLOCATE(_E, allocator, _Ns + 1);
                        _CATCH_END
                        if (0 < _Len)
                                _T::copy(_S, _Ptr,
                                        (_Len < _Ns ? _Len : _Ns) + 1);
                        _DEALLOCATE(_E, allocator, _Ptr);
                        _Ptr = _S;
                        _Res = _Ns;
                        return (1); }}
        static bool _Len0(size_type& _N, const _E *_S)
                {return (_N == 0 || _N == (size_type)npos &&
                        (_N = _T::length(_S)) == 0); }
        static const _E *_Null()
                {static const _E _C = _T::eos();
                return (&_C); }
        void _Tidy(bool _Built = false)
                {if (_Built && _Ptr != 0)
                        _DEALLOCATE(_E, allocator, _Ptr);
                _Ptr = 0, _Len = 0, _Res = 0; }
        _E *_Ptr;
        size_type _Len, _Res;
        };

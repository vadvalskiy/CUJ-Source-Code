#define _DEQUEMAPSIZ    8    /* at least 1 */
#define _DEQUESIZ (4096 < sizeof (_Ty) ? \
    1 : 4096 / sizeof (_Ty))

// code for deque base classes omitted

        // TEMPLATE CLASS deque
template<class _Ty, class _Ax = allocator<_Ty> >
    class deque
        : public _Deque_val<_Ty, _Ax> {
public:
// typedefs omitted

        // CLASS iterator
    class const_iterator;
    class iterator : public _Ranit<_Ty, _Dift, _Tptr, _Reft> {
    public:
        typedef _Ranit<_Ty, _Dift, _Tptr, _Reft> _Mybase;
        typedef typename _Mybase::iterator_category
            iterator_category;
        typedef typename _Mybase::value_type value_type;
        typedef typename _Mybase::difference_type
            difference_type;
        typedef typename _Mybase::pointer pointer;
        typedef typename _Mybase::reference reference;
        friend class deque<_Ty, _A>;
        friend class const_iterator;
        iterator()
            : _Idx(0), _Deque(0)
            {}
        iterator(difference_type _I, deque<_Ty, _A> *_P)
            : _Idx(_I), _Deque(_P)
            {}
        reference operator*() const
            {size_type _Block = _Idx / _DEQUESIZ;
            _Idx -= _Block * _DEQUESIZ;
            if (_Block <= _Deque->_Mapsize)
                _Block -= _Deque->_Mapsize;
            return ((_Deque->_Map)[_Block][_Idx]); }
        _Tptr operator->() const
            {return (&**this); }
        iterator& operator++()
            {++_Idx;
            return (*this); }
        iterator operator++(int)
            {iterator _Tmp = *this;
            ++*this;
            return (_Tmp); }
        iterator& operator--()
            {--_Idx;
            return (*this); }
        iterator operator--(int)
            {iterator _Tmp = *this;
            --*this;
            return (_Tmp); }
        iterator& operator+=(difference_type _N)
            {_Idx += _N;
            return (*this); }
        iterator& operator-=(difference_type _N)
            {return (*this += -_N); }
        iterator operator+(difference_type _N) const
            {iterator _Tmp = *this;
            return (_Tmp += _N); }
        iterator operator-(difference_type _N) const
            {iterator _Tmp = *this;
            return (_Tmp -= _N); }
        difference_type operator-(const iterator& _X) const
            {return (_Idx - _X._Idx); }
        reference operator[](difference_type _N) const
            {return (*(*this + _N)); }
        bool operator==(const iterator& _X) const
            {return (_Deque == _X._Deque && _Idx == _X._Idx); }
        bool operator!=(const iterator& _X) const
            {return (!(*this == _X)); }
        bool operator<(const iterator& _X) const
            {return (_Idx < _X._Idx); }
        bool operator<=(const iterator& _X) const
            {return (!(_X < *this)); }
        bool operator>(const iterator& _X) const
            {return (_X < *this); }
        bool operator>=(const iterator& _X) const
            {return (!(*this < _X)); }
    protected:
        difference_type _Idx;
        deque<_Ty, _A> *_Deque;
        };

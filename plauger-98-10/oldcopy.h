        // TEMPLATE FUNCTION uninitialized_copy
template<class _II, class _FI> inline
    _FI uninitialized_copy(_II _F, _II _L, _FI _X)
    {for (; _F != _L; ++_X, ++_F)
        _Construct(&*_X, *_F);
    return (_X); }
        // TEMPLATE FUNCTION uninitialized_fill
template<class _FI, class _Ty> inline
    void uninitialized_fill(_FI _F, _FI _L, const _Ty& _X)
    {for (; _F != _L; ++_F)
        _Construct(&*_F, _X); }
        // TEMPLATE FUNCTION uninitialized_fill_n
template<class _FI, class _S, class _Ty> inline
    void uninitialized_fill_n(_FI _F, _S _N, const _Ty& _X)
    {for (; 0 < _N; --_N, ++_F)
        _Construct(&*_F, _X); }

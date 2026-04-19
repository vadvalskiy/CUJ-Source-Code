        // TEMPLATE FUNCTION uninitialized_copy
template<class _II, class _FI> inline
    _FI uninitialized_copy(_II _F, _II _L, _FI _X)
    {return (_Uninit_copy(_F, _L, _X, _Val_type(_F))); }
template<class _II, class _FI, class _Ty> inline
    _FI _Uninit_copy(_II _F, _II _L, _FI _X, _Ty *)
    {_FI _Xs = _X;
    _TRY_BEGIN
    for (; _F != _L; ++_X, ++_F)
        _Construct(&*_X, _Ty(*_F));
    _CATCH_ALL
    for (; _Xs != _X; ++_Xs)
        _Destroy(&*_Xs);
    _RERAISE;
    _CATCH_END
    return (_X); }
        // TEMPLATE FUNCTION uninitialized_fill
template<class _FI, class _Tval> inline
    void uninitialized_fill(_FI _F, _FI _L, const _Tval& _V)
    {_Uninit_fill(_F, _L, _V, _Val_type(_F)); }
template<class _FI, class _Tval, class _Ty> inline
    void _Uninit_fill(_FI _F, _FI _L, const _Tval& _V, _Ty *)
    {_FI _Fs = _F;
    _TRY_BEGIN
    for (; _F != _L; ++_F)
        _Construct(&*_F, _Ty(_V));
    _CATCH_ALL
    for (; _Fs != _F; ++_Fs)
        _Destroy(&*_Fs);
    _RERAISE;
    _CATCH_END }
        // TEMPLATE FUNCTION uninitialized_fill_n
template<class _FI, class _S, class _Tval> inline
    void uninitialized_fill_n(_FI _F, _S _N, const _Tval& _V)
    {_Uninit_fill_n(_F, _N, _V, _Val_type(_F)); }
template<class _FI, class _S, class _Tval, class _Ty> inline
    void _Uninit_fill_n(_FI _F, _S _N, const _Tval& _V,
        _Ty *)
    {_FI _Fs = _F;
    _TRY_BEGIN
    for (; 0 < _N; --_N, ++_F)
        _Construct(&*_F, _Ty(_V));
    _CATCH_ALL
    for (; _Fs != _F; ++_Fs)
        _Destroy(&*_Fs);
    _RERAISE;
    _CATCH_END }

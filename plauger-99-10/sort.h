        // COMMON SORT PARAMETERS
const int _CHUNK_SIZE = 7;
const int _SORT_MAX = 32;

        // TEMPLATE FUNCTION sort
template<class _RI> inline
    void sort(_RI _F, _RI _L)
    {_Sort(_F, _L, _L - _F); }

template<class _RI, class _Pd> inline
    void _Sort(_RI _F, _RI _L, _Pd _Ideal)
    {_Pd _N;

    for (; 0 < _Ideal && _SORT_MAX < (_N = _L - _F); )
        {pair<_RI, _RI> _M = _Unguarded_partition(_F, _L);
        _Ideal /= 2, _Ideal += _Ideal / 2;
        if (_M.first - _F < _L - _M.second)
            _Sort(_F, _M.first, _Ideal), _F = _M.second;
        else
            _Sort(_M.second, _L, _Ideal), _L = _M.first; }

    if (_SORT_MAX <= _N)
        {make_heap(_F, _L);
        sort_heap(_F, _L); }
    else if (1 < _N)
        _Insertion_sort(_F, _L); }

template<class _RI> inline
    pair<_RI, _RI> _Unguarded_partition(_RI _F, _RI _L)
    {_RI _M = _F + (_L - _F) / 2;
    if (*_M < *_F)
        iter_swap(_F, _M);
    if (*(_L - 1) < *_M)
        iter_swap(_M, _L - 1);
    if (*_M < *_F)
        iter_swap(_F, _M);

    for (; ; ++_F)
        {_RI _F0 = _F;
        for (; _F < _L && !(*_M < *_F); ++_F)
            ;
        for (; _F0 < _L && !(*--_L < *_M); )
            ;
        if (_L <= _F)
            return (pair<_RI, _RI>(_L + 1, _F));

        iter_swap(_F, _L);
        if (_M == _F)
            _M = _L;
        else if (_M == _L)
            _M = _F; }}

template<class _BI> inline
    void _Insertion_sort(_BI _F, _BI _L)
    {if (_F != _L)
        for (_BI _M = _F; ++_M != _L; )
            if (*_M < *_F)
                {_BI _Mp1 = _M;
                rotate(_F, _M, ++_Mp1); }
            else
                {_BI _X = _M;
                for (_BI _X0 = _X; *_M < *--_X0; _X = _X0)
                    ;
                if (_X != _M)
                    {_BI _Mp1 = _M;
                    rotate(_X, _M, ++_Mp1); }}}

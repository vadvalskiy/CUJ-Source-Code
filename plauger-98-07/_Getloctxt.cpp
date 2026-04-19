template<class _It> inline
    int _Getloctxt(_It& _F, _It& _L, size_t _N, const char *_S)
    {for (size_t _I = 0; _S[_I] != (char)0; ++_I)
        if (_S[_I] == _S[0])
            ++_N;
    string _Str(_N, '\0');
    int _Ans = -2;
    for (size_t _J = 1; ; ++_J, ++_F, _Ans = -1)
        {bool  _Pfx;
        size_t _I, _K;
        for (_I = 0, _K = 0, _Pfx = false; _K < _N; ++_K)
            {for (; _S[_I] != (char)0 && _S[_I] != _S[0]; ++_I)
                ;
            if (_Str[_K] != '\0')
                _I += _Str[_K];
            else if (_S[_I += _J] == _S[0] || _S[_I] == (char)0)
                {_Str[_K] = _J < 127 ? _J : 127;
                _Ans = _K; }
            else if (_F == _L || _S[_I] != *_F)
                _Str[_K] = _J < 127 ? _J : 127;
            else
                _Pfx = true; }
        if (!_Pfx || _F == _L)
            break; }
    return (_Ans); }

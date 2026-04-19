        // TEMPLATE CLASS time_put
template<class _E,
    class _OI = ostreambuf_iterator<_E, char_traits<_E> > >
    class time_put : public locale::facet {
public:
    typedef _E char_type;
    typedef _OI iter_type;
    _OI put(_OI _F, ios_base& _X, _E _Fill, const tm *_Tp,
        const _E *_Ff, const _E *_Lf) const
        {const _E _Pct = _WIDEN(_E, '%');
        for (; _Ff != _Lf; ++_Ff)
            if (*_Ff != _Pct)
                *_F++ = *_Ff;
            else if (++_Ff == _Lf)
                {*_F++ = _Pct;
                break; }
            else
                {char _C = _NARROW(_E, *_Ff);
                char _Q = '\0';
                if (_C != 'E' && _C != 'O' && _C != 'Q'
                    && _C != '#')
                    ;
                else if (++_Ff == _Lf)
                    {*_F++ = _Pct, *_F++ = _C;
                    break; }
                else
                    _Q = _C, _C = _NARROW(_E, *_Ff);
                _F = do_put(_F, _X, _Fill, _Tp, _C, _Q); }
        return (_F); }
    _OI put(_OI _F, ios_base& _X, _E _Fill, const tm *_Tp,
        char _C, char _M = 0) const
        {return (do_put(_F, _X, _Fill, _Tp, _C, _M)); }
    static locale::id id;
    explicit time_put(size_t _R = 0);
protected:
    virtual ~time_put()
        {}
    virtual _OI do_put(_OI _F, ios_base& _X, _E, const tm *_Tp,
        char _C, char _M = 0) const
        {char _Fmt[5] = "!%x\0";
        size_t _I, _N;
        string _Str;
        if (_M == (_E)0)
            _Fmt[2] = _C;
        else
            _Fmt[2] = _M, _Fmt[3] = _C;
        for (_N = 16; ; _N *= 2)
            {_Str.append(_N, '\0');
            if (0 < (_I = _Strftime(&*_Str.begin(), _Str.size(),
                _Fmt, _Tp, _Tnames._Getptr())))
                break; }
        for (string::const_iterator _S = _Str.begin();
            0 < --_I; ++_F)
            *_F = _WIDEN(_E, *++_S);
        return (_F); }
private:
    _Locinfo::_Timevec _Tnames;
    };

template<class _E, class _OI>
    locale::id time_put<_E, _OI>::id;

        // TEMPLATE CLASS time_put_byname
template<class _E,
    class _OI = ostreambuf_iterator<_E, char_traits<_E> > >
    class time_put_byname : public time_put<_E, _OI> {
public:
    explicit time_put_byname(const char *_S, size_t _R = 0)
        : time_put<_E, _OI>(_Locinfo(_S), _R) {}
protected:
    virtual ~time_put_byname()
        {}
    };

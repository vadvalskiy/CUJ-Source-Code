        // TEMPLATE CLASS money_put
template<class _E,
    class _OI = ostreambuf_iterator<_E, char_traits<_E> > >
    class money_put : public locale::facet {
    typedef moneypunct<_E, false> _Mypunct0;
    typedef moneypunct<_E, true> _Mypunct1;
public:
    typedef _E char_type;
    typedef _OI iter_type;
    typedef basic_string<_E, char_traits<_E>, allocator<_E> >
        string_type;
    _OI put(_OI _F, bool _Intl, ios_base& _X, _E _Fill,
        long double _V) const
        {return (do_put(_F, _Intl, _X, _Fill, _V)); }
    _OI put(_OI _F, bool _Intl, ios_base& _X, _E _Fill,
        const string_type& _D) const
        {return (do_put(_F, _Intl, _X, _Fill, _D)); }
    static locale::id id;
    explicit money_put(size_t _R = 0);
protected:
    virtual ~money_put();
    virtual _OI do_put(_OI _F, bool _Intl,
        ios_base& _X, _E _Fill, long double _V) const
        {bool _Neg = false;
        if (_V < 0)
            _Neg = true, _V = -_V;
        size_t _Exp;
        for (_Exp = 0; 1e35 <= _V && _Exp < 5000; _Exp += 10)
            _V /= 1e10;
        string_type _D2;
        char _Buf[40];
        int _N = sprintf(_Buf, "%.0Lf", _V);
        for (int _I = 0; _I < _N; ++_I)
            _D2.append((typename string_type::size_type)1,
                _WIDEN(_E, _Buf[_I]));
        _D2.append(_Exp, _WIDEN(_E, '0'));
        return (_Putmfld(_F, _Intl, _X, _Fill, _Neg, _D2)); }
    virtual _OI do_put(_OI _F, bool _Intl,
        ios_base& _X, _E _Fill, const string_type& _D) const
        {const ctype<_E>& _Fac = _USE(_X.getloc(), ctype<_E>);
        const _E *_S = _D.c_str();
        bool _Neg = false;
        if (*_S == _WIDEN(_E, '-'))
            _Neg = true, ++_S;
        size_t _N;
        for (_N = 0; _Fac.is(ctype_base::digit, _S[_N]); ++_N)
            ;
        string_type _D2(_S, _N);
        if (_N == 0)
            _D2.append((typename string_type::size_type)1,
                _WIDEN(_E, '0'));
        return (_Putmfld(_F, _Intl, _X, _Fill, _Neg, _D2)); }
private:
    _OI _Putmfld(_OI _F, bool _Intl, ios_base& _X, _E _Fill,
        bool _Neg, string_type _D) const
        {const _Mpunct<_E> *_Pfac;
        if (_Intl)
            _Pfac = &_USE(_X.getloc(), _Mypunct1);
        else
            _Pfac = &_USE(_X.getloc(), _Mypunct0);
        size_t _Fd = _Pfac->frac_digits();
        const string _Gr = _Pfac->grouping();
        if (_Fd < _D.size() && '\0' < *_Gr.c_str())
            {const _E _Ks = _Pfac->thousands_sep();
            const char *_Pg = _Gr.c_str();
            size_t _I = _D.size() - _Fd;
            while (*_Pg != CHAR_MAX && '\0' < *_Pg && *_Pg < _I)
                {_D.insert(_I -= *_Pg, (size_t)1, _Ks);
                if ('\0' < _Pg[1])
                    ++_Pg; }}
        money_base::pattern _Pat;
        string_type _Sg;
        if (_Neg)
            {_Pat = _Pfac->neg_format();
            _Sg = _Pfac->negative_sign(); }
        else
            {_Pat = _Pfac->pos_format();
            _Sg = _Pfac->positive_sign(); }
        string_type _Cs;
        if (_X.flags() & ios_base::showbase)
            _Cs = _Pfac->curr_symbol();
        bool _Intern = false;
        size_t _M, _N;
        for (_M = 0, _N = 0; _N < 4; ++_N)
            switch (_Pat.field[_N])
        {case money_base::symbol:
            _M += _Cs.size();
            break;
        case money_base::sign:
            _M += _Sg.size();
            break;
        case money_base::value:
            _M += _D.size() + (0 < _Fd ? 1 : 0)
                + (_D.size() <= _Fd ? _Fd - _D.size() + 1 : 0);
            break;
        case money_base::space:
            _Intern = true; }
        _M = _X.width() <= 0 || _X.width() <= _M
            ? 0 : _X.width() - _M;
        ios_base::fmtflags _Afl =
            _X.flags() & ios_base::adjustfield;
        if (_Afl != ios_base::left
            && (_Afl != ios_base::internal || !_Intern))
            _F = _Rep(_F, _Fill, _M), _M = 0;
        for (_N = 0; _N < 4; ++_N)
            switch (_Pat.field[_N])
        {case money_base::symbol:
            _F = _Put(_F, _Cs.begin(), _Cs.size());
            break;
        case money_base::sign:
            if (0 < _Sg.size())
                _F = _Put(_F, _Sg.begin(), 1);
            break;
        case money_base::value:
            if (_Fd == 0)
                _F = _Put(_F, _D.begin(), _D.size());
            else if (_D.size() <= _Fd)
                {*_F++ = _WIDEN(_E, '0');
                *_F++ = _Pfac->decimal_point();
                _F = _Rep(_F, _WIDEN(_E, '0'), _Fd - _D.size());
                _F = _Put(_F, _D.begin(), _D.size()); }
            else
                {_F = _Put(_F, _D.begin(), _D.size() - _Fd);
                *_F++ = _Pfac->decimal_point();
                _F = _Put(_F, _D.end() - _Fd, _Fd); }
            break;
        case money_base::space:
            if (_Afl == ios_base::internal)
                _F = _Rep(_F, _Fill, _M), _M = 0; }
        if (1 < _Sg.size())
            _F = _Put(_F, _Sg.begin() + 1, _Sg.size() - 1);
        _X.width(0);
        return (_Rep(_F, _Fill, _M)); }
    static _OI _Put(_OI _F, string_type::const_iterator _S,
        size_t _N)
        {for (; 0 < _N; --_N, ++_F, ++_S)
            *_F = *_S;
        return (_F); }
    static _OI _Rep(_OI _F, _E _C, size_t _N)
        {for (; 0 < _N; --_N, ++_F)
            *_F = _C;
        return (_F); }
    };

template<class _E, class _OI>
    locale::id money_put<_E, _OI>::id;

        // TEMPLATE CLASS money_get
template<class _E,
    class _II = istreambuf_iterator<_E, char_traits<_E> > >
    class money_get : public locale::facet {
    typedef moneypunct<_E, false> _Mypunct0;
    typedef moneypunct<_E, true> _Mypunct1;
public:
    typedef _E char_type;
    typedef _II iter_type;
    typedef basic_string<_E, char_traits<_E>, allocator<_E> >
        string_type;
    _II get(_II _F, _II _L, bool _Intl, ios_base& _X,
        ios_base::iostate& _St, long double& _V) const
        {return (do_get(_F, _L, _Intl, _X, _St, _V)); }
    _II get(_II _F, _II _L, bool _Intl, ios_base& _X,
        ios_base::iostate& _St, string_type& _D) const
        {return (do_get(_F, _L, _Intl, _X, _St, _D)); }
    static locale::id id;
    explicit money_get(size_t _R = 0);
protected:
    virtual ~money_get();
    virtual _II do_get(_II _F, _II _L, bool _Intl, ios_base& _X,
        ios_base::iostate& _St, long double& _V) const
        {string_type _Str = _Getmfld(_F, _L, _Intl, _X);
        if (_F == _L)
            _St |= ios_base::eofbit;
        if (_Str.size() == 0)
            _St |= ios_base::failbit;
        else
            {string _Str2;
            _Str2.reserve(_Str.size());
            for (size_t _I = 0; _I < _Str.size(); ++_I)
                _Str2 += _NARROW(_E, _Str[_I]);
            const char *_Eb = _Str2.c_str();
            char *_Ep;
            errno = 0;
            const long double _Ans = _Stold(_Eb, &_Ep, 0);
            if (_Ep == _Eb || errno != 0)
                _St |= ios_base::failbit;
            else
                _V = _Ans; }
        return (_F); }
    virtual _II do_get(_II _F, _II _L, bool _Intl, ios_base& _X,
        ios_base::iostate& _St, string_type& _D) const
        {string_type _Str = _Getmfld(_F, _L, _Intl, _X);
        if (_F == _L)
            _St |= ios_base::eofbit;
        if (_Str.size() == 0)
            _St |= ios_base::failbit;
        else
            _D = _Str;
        return (_F); }
private:
    string_type _Getmfld(_II& _F, _II& _L, bool _Intl,
        ios_base& _X) const
        {const _Mpunct<_E> *_Pfac;
        if (_Intl)
            _Pfac = &_USE(_X.getloc(), _Mypunct1);
        else
            _Pfac = &_USE(_X.getloc(), _Mypunct0);
        const ctype<_E>& _Fac2 = _USE(_X.getloc(), ctype<_E>);
        bool _Bad = false, _Neg = false;
        string_type _Sg, _Str;
        const money_base::pattern _Pat = _Pfac->neg_format();
        for (size_t _N = 0; !_Bad && _N < 4; ++_N)
            switch (_Pat.field[_N])
        {case money_base::symbol:
            {string_type _Cs = _Pfac->curr_symbol();
            string_type::const_iterator _S;
            if (_X.flags() & ios_base::showbase)
                ;
            else if (_N == 3 && _Sg.size() == 0
                || _F == _L || *_F != *_Cs.c_str())
                _Cs.erase();
            for (_S = _Cs.begin(); _F != _L && _S != _Cs.end()
                && *_F == *_S; ++_S, ++_F)
                ;
            if (_S != _Cs.end())
                _Bad = true; }
            break;
        case money_base::sign:
            {if (_F == _L)
                ;
            else if (0 < (_Pfac->positive_sign()).size()
                && _Pfac->positive_sign()[0] == *_F)
                ++_F, _Sg = _Pfac->positive_sign();
            else if (0 < (_Pfac->negative_sign()).size()
                && _Pfac->negative_sign()[0] == *_F)
                ++_F, _Sg = _Pfac->negative_sign(), _Neg = true;
            if (_Sg.size() == 1)
                _Sg.erase(); }
            break;
        case money_base::value:
            {int _Nfd = 0;
            int _Fd = _Pfac->frac_digits();
            const string _Gr = _Pfac->grouping();
            if (*_Gr.c_str() <= '\0')
                while (_F != _L
                    && _Fac2.is(ctype_base::digit, *_F))
                    _Str += *_F++;
            else
                {const _E _Ks = _Pfac->thousands_sep();
                string _Grin((size_t)1, '\0');
                size_t _I = 0;
                for (; _F != _L; ++_F)
                    if (_Fac2.is(ctype_base::digit, *_F))
                        {_Str += *_F;
                        if (_Grin[_I] != CHAR_MAX)
                            ++_Grin[_I]; }
                    else if (_Grin[_I] == '\0' || *_F != _Ks)
                        break;
                    else
                        _Grin.append((size_t)1, '\0'), ++_I;
                if (_I == 0)
                    ;
                else if ('\0' < _Grin[_I])
                    ++_I;
                else
                    _Bad = true;
                for (const char *_Pg = _Gr.c_str();
                    !_Bad && 0 < _I; --_I)
                    if (*_Pg == CHAR_MAX)
                        break;
                    else if (0 < --_I && *_Pg != _Grin[_I]
                        || 0 == _I && *_Pg < _Grin[_I])
                        _Bad = true;
                    else if ('\0' < _Pg[1])
                        ++_Pg;
                if (_Bad)
                    break; }
            if (_F != _L && *_F == _Pfac->decimal_point())
                {while (++_F != _L
                    && _Fac2.is(ctype_base::digit, *_F))
                    if (_Nfd < _Fd)
                        _Str += *_F, ++_Nfd; }
            if (_Str.size() == 0)
                _Bad = true;
            else
                for (; _Nfd < _Fd; ++_Nfd)
                    _Str += _WIDEN(_E, '0'); }
            break;
        default:
            {if (_N == 3)
                break;
            while (_F != _L && _Fac2.is(ctype_base::space, *_F))
                ++_F; }}
        if (!_Bad && 0 < _Sg.size())
            {string_type::const_iterator _S;
            for (_S = _Sg.begin(); _F != _L
                && ++_S != _Sg.end() && *_F == *_S; ++_F)
                ;
            if (_S != _Sg.end())
                _Bad = true; }
        if (_Bad)
            _Str.erase();
        else if (_Neg)
            _Str.insert((size_t)0, (size_t)1, _WIDEN(_E, '-'));
        return (_Str); }
    };

template<class _E, class _II>
    locale::id money_get<_E, _II>::id;

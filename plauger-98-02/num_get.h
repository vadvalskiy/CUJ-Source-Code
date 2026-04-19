        // TEMPLATE CLASS num_get
template<class _E,
    class _II = istreambuf_iterator<_E, char_traits<_E> > >
    class num_get : public locale::facet {
public:
    typedef numpunct<_E> _Mypunct;
    typedef basic_string<_E, char_traits<_E>, allocator<_E> >
        _Mystr;
    static locale::id id;
public:
    explicit num_get(size_t _R = 0);
    typedef _E char_type;
    typedef _II iter_type;
    _II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
        bool& _V) const
        {return (do_get(_F, _L, _X, _St, _V)); }
    _II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
        unsigned short& _V) const
        {return (do_get(_F, _L, _X, _St, _V)); }
    _II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
        unsigned int& _V) const
        {return (do_get(_F, _L, _X, _St, _V)); }
    _II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
        long& _V) const
        {return (do_get(_F, _L, _X, _St, _V)); }
    _II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
        unsigned long& _V) const
        {return (do_get(_F, _L, _X, _St, _V)); }
    _II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
        float& _V) const
        {return (do_get(_F, _L, _X, _St, _V)); }
    _II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
        double& _V) const
        {return (do_get(_F, _L, _X, _St, _V)); }
    _II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
        long double& _V) const
        {return (do_get(_F, _L, _X, _St, _V)); }
    _II get(_II _F, _II _L, ios_base& _X, ios_base::iostate& _St,
        void *& _V) const
        {return (do_get(_F, _L, _X, _St, _V)); }
protected:
    virtual ~num_get()
        {}
    virtual _II do_get(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, bool& _V) const
        {int _Ans = -1;
        if (_X.flags() & ios_base::boolalpha)
            {const _Mypunct& _Fac =
                use_facet<_Mypunct>(_X.getloc());
            _Mystr _Str((typename _Mystr::size_type)1,
                (char_type)0);
            _Str += _Fac.falsename();
            _Str += (char_type)0;
            _Str += _Fac.truename();
            _Ans = _Getloctxt(_F, _L, (size_t)2, _Str.c_str()); }
        else
            {char _Ac[_MAX_INT_DIG], *_Ep;
            errno = 0;
            const unsigned long _Ulo = strtoul(_Ac, &_Ep,
                _Getifld(_Ac, _F, _L, _X.flags(), _X.getloc()));
            if (_Ep != _Ac && errno == 0 && _Ulo <= 1)
                _Ans = _Ulo; }
        if (_F == _L)
            _St |= ios_base::eofbit;
        if (_Ans < 0)
            _St |= ios_base::failbit;
        else
            _V = _Ans != 0;
        return (_F); }
    virtual _II do_get(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, unsigned short& _V) const
        {char _Ac[_MAX_INT_DIG], *_Ep;
        errno = 0;
        int _Base =
            _Getifld(_Ac, _F, _L, _X.flags(), _X.getloc());
        char *_S = _Ac[0] == '-' ? _Ac + 1 : _Ac;
        const unsigned long _Ans = strtoul(_S, &_Ep, _Base);
        if (_F == _L)
            _St |= ios_base::eofbit;
        if (_Ep == _S || errno != 0 || USHRT_MAX < _Ans)
            _St |= ios_base::failbit;
        else
            _V = _Ac[0] == '-' ? -_Ans : _Ans;
        return (_F); }
    virtual _II do_get(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, unsigned int& _V) const
        {char _Ac[_MAX_INT_DIG], *_Ep;
        errno = 0;
        int _Base =
            _Getifld(_Ac, _F, _L, _X.flags(), _X.getloc());
        char *_S = _Ac[0] == '-' ? _Ac + 1 : _Ac;
        const unsigned long _Ans = strtoul(_S, &_Ep, _Base);
        if (_F == _L)
            _St |= ios_base::eofbit;
        if (_Ep == _S || errno != 0 || UINT_MAX < _Ans)
            _St |= ios_base::failbit;
        else
            _V = _Ac[0] == '-' ? -_Ans : _Ans;
        return (_F); }
    virtual _II do_get(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, long& _V) const
        {char _Ac[_MAX_INT_DIG], *_Ep;
        errno = 0;
        const long _Ans = strtol(_Ac, &_Ep,
            _Getifld(_Ac, _F, _L, _X.flags(), _X.getloc()));
        if (_F == _L)
            _St |= ios_base::eofbit;
        if (_Ep == _Ac || errno != 0)
            _St |= ios_base::failbit;
        else
            _V = _Ans;
        return (_F); }
    virtual _II do_get(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, unsigned long& _V) const
        {char _Ac[_MAX_INT_DIG], *_Ep;
        errno = 0;
        const unsigned long _Ans = strtoul(_Ac, &_Ep,
            _Getifld(_Ac, _F, _L, _X.flags(), _X.getloc()));
        if (_F == _L)
            _St |= ios_base::eofbit;
        if (_Ep == _Ac || errno != 0)
            _St |= ios_base::failbit;
        else
            _V = _Ans;
        return (_F); }
    virtual _II do_get(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, float& _V) const
        {char _Ac[_MAX_EXP_DIG + _MAX_SIG_DIG + 16], *_Ep;
        errno = 0;
        const float _Ans = _Stof(_Ac, &_Ep,
            _Getffld(_Ac, _F, _L, _X.getloc()));
        if (_F == _L)
            _St |= ios_base::eofbit;
        if (_Ep == _Ac || errno != 0)
            _St |= ios_base::failbit;
        else
            _V = _Ans;
        return (_F); }
    virtual _II do_get(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, double& _V) const
        {char _Ac[_MAX_EXP_DIG + _MAX_SIG_DIG + 16], *_Ep;
        errno = 0;
        const double _Ans = _Stod(_Ac, &_Ep,
            _Getffld(_Ac, _F, _L, _X.getloc()));
        if (_F == _L)
            _St |= ios_base::eofbit;
        if (_Ep == _Ac || errno != 0)
            _St |= ios_base::failbit;
        else
            _V = _Ans;
        return (_F); }
    virtual _II do_get(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, long double& _V) const
        {char _Ac[_MAX_EXP_DIG + _MAX_SIG_DIG + 16], *_Ep;
        errno = 0;
        const long double _Ans = _Stold(_Ac, &_Ep,
            _Getffld(_Ac, _F, _L, _X.getloc()));
        if (_F == _L)
            _St |= ios_base::eofbit;
        if (_Ep == _Ac || errno != 0)
            _St |= ios_base::failbit;
        else
            _V = _Ans;
        return (_F); }
    virtual _II do_get(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, void *& _V) const
        {union _Pvlo {
            void *_Pv;
            unsigned long _Lo[1 +
                (sizeof (void *) - 1) / sizeof (unsigned long)];
            } _U;
        const int _NL = sizeof (_U._Lo) / sizeof (unsigned long);
        for (int _I = 0; ; ++_F)
            {char _Ac[_MAX_INT_DIG], *_Ep;
            errno = 0;
            _U._Lo[_I] = strtoul(_Ac, &_Ep,
                _Getifld(_Ac, _F, _L,
                    ios_base::hex, _X.getloc()));
            if (_F == _L)
                _St |= ios_base::eofbit;
            if (_Ep == _Ac || errno != 0)
                {_St |= ios_base::failbit;
                break; }
            if (_NL <= ++_I)
                break;
            if (_F == _L || *_F != _WIDEN(_E, ':'))
                {_St |= ios_base::failbit;
                break; }}
        if (!(_St & ios_base::failbit))
            _V = _U._Pv;
        return (_F); }
private:
    static int _Getifld(char *_Ac, _II& _F, _II& _L,
        ios_base::fmtflags _Bfl, const locale& _Loc)
        {const _E _E0 = _WIDEN(_E, '0');
        const _Mypunct& _Fac =
            use_facet<_Mypunct>(_Loc);
        const string _Gr = _Fac.grouping();
        const _E _Ks = _Fac.thousands_sep();
        char *_P = _Ac;
        if (_F == _L)
            ;
        else if (*_F == _WIDEN(_E, '+'))
            *_P++ = '+', ++_F;
        else if (*_F == _WIDEN(_E, '-'))
            *_P++ = '-', ++_F;
        _Bfl &= ios_base::basefield;
        int _Base = _Bfl == ios_base::oct ? 8
            : _Bfl == ios_base::hex ? 16
            : _Bfl == ios_base::_Fmtzero ? 0 : 10;
        bool _Sd = false, _Snz = false;
        if (_F != _L && *_F == _E0)
            {_Sd = true, ++_F;
            if (_F != _L && (*_F == _WIDEN(_E, 'x')
                    || *_F == _WIDEN(_E, 'X'))
                && (_Base == 0 || _Base == 16))
                _Base = 16, _Sd = false, ++_F;
            else if (_Base == 0)
                _Base = 8; }
        int _Dlen = _Base == 0 || _Base == 10 ? 10
            : _Base == 8 ? 8 : 16 + 6;
        string _Grin((size_t)1, (char)(_Sd ? '\1' : '\0'));
        size_t _I = 0;
        for (char *const _Pe = &_Ac[_MAX_INT_DIG - 1];
            _F != _L; ++_F)
            if (memchr("0123456789abcdefABCDEF",
                *_P = _NARROW(_E, *_F), _Dlen) != 0)
                {if ((_Snz || *_P != '0') && _P < _Pe)
                    ++_P, _Snz = true;
                _Sd = true;
                if (_Grin[_I] != CHAR_MAX)
                    ++_Grin[_I]; }
            else if (_Grin[_I] == '\0' || _Ks == (_E)0
                || *_F != _Ks)
                break;
            else
                _Grin.append((typename _Mystr::size_type)1,
                    '\0'), ++_I;
        if (_I == 0)
            ;
        else if ('\0' < _Grin[_I])
            ++_I;
        else
            _Sd = false;
        for (const char *_Pg = _Gr.c_str(); _Sd && 0 < _I; --_I)
            if (*_Pg == CHAR_MAX)
                break;
            else if (0 < --_I && *_Pg != _Grin[_I]
                || 0 == _I && *_Pg < _Grin[_I])
                _Sd = false;
            else if ('\0' < _Pg[1])
                ++_Pg;
        if (_Sd && !_Snz)
            *_P++ = '0';
        else if (!_Sd)
            _P = _Ac;
        *_P = '\0';
        return (_Base);
        }
    static int _Getffld(char *_Ac, _II& _F, _II &_L,
        const locale& _Loc)
        {const _E _E0 = _WIDEN(_E, '0');
        const _Mypunct& _Fac =
            use_facet<_Mypunct>(_Loc);
        char *_P = _Ac;
        if (_F == _L)
            ;
        else if (*_F == _WIDEN(_E, '+'))
            *_P++ = '+', ++_F;
        else if (*_F == _WIDEN(_E, '-'))
            *_P++ = '-', ++_F;
        bool _Sd = false;
        for (; _F != _L && *_F == _E0; _Sd = true, ++_F)
            ;
        if (_Sd)
            *_P++ = '0';
        int _Ns = 0;
        int _Pten = 0;
        for (; _F != _L && _CSTD isdigit(*_P = _NARROW(_E, *_F));
            _Sd = true, ++_F)
            if (_Ns < _MAX_SIG_DIG)
                ++_P, ++_Ns;
            else
                ++_Pten;
        if (_F != _L && *_F == _Fac.decimal_point())
            *_P++ = localeconv()->decimal_point[0], ++_F;
        if (_Ns == 0)
            {for (; _F != _L && *_F == _E0; _Sd = true, ++_F)
                --_Pten;
            if (_Pten < 0)
                *_P++ = '0', ++_Pten; }
        for (; _F != _L && _CSTD isdigit(*_P = _NARROW(_E, *_F));
            _Sd = true, ++_F)
            if (_Ns < _MAX_SIG_DIG)
                ++_P, ++_Ns;
        if (_Sd && _F != _L
            && (*_F == _WIDEN(_E, 'e') || *_F == _WIDEN(_E, 'E')))
            {*_P++ = 'e', ++_F;
            _Sd = false, _Ns = 0;
            if (_F == _L)
                ;
            else if (*_F == _WIDEN(_E, '+'))
                *_P++ = '+', ++_F;
            else if (*_F == _WIDEN(_E, '-'))
                *_P++ = '-', ++_F;
            for (; _F != _L && *_F == _E0; _Sd = true, ++_F)
                ;
            if (_Sd)
                *_P++ = '0';
            for (; _F != _L
                && _CSTD isdigit(*_P = _NARROW(_E, *_F));
                _Sd = true, ++_F)
                if (_Ns < _MAX_EXP_DIG)
                    ++_P, ++_Ns; }
        if (!_Sd)
            _P = _Ac;
        *_P = '\0';
        return (_Pten);
        };
    };

template<class _E, class _II>
    locale::id num_get<_E, _II>::id;

        // TEMPLATE CLASS time_get
template<class _E,
    class _II = istreambuf_iterator<_E, char_traits<_E> > >
    class time_get : public time_base {
public:
    typedef _E char_type;
    typedef _II iter_type;
    static locale::id id;
    dateorder date_order() const
        {return (do_date_order()); }
    _II get_time(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, tm *_Tp) const
        {return (do_get_time(_F, _L, _X, _St, _Tp)); }
    _II get_date(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, tm *_Tp) const
        {return (do_get_date(_F, _L, _X, _St, _Tp)); }
    _II get_weekday(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, tm *_Tp) const
        {return (do_get_weekday(_F, _L, _X, _St, _Tp)); }
    _II get_monthname(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, tm *_Tp) const
        {return (do_get_monthname(_F, _L, _X, _St, _Tp)); }
    _II get_year(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, tm *_Tp) const
        {return (do_get_year(_F, _L, _X, _St, _Tp)); }
    explicit time_get(size_t _R = 0);
protected:
    virtual ~time_get();
    virtual dateorder do_date_order() const
        {return (mdy); }
    virtual _II do_get_time(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, tm *_Tp) const
        {const _E _Colon = _WIDEN(_E, ':');
        _St |= _Getint(_F, _L, 0, 23, _Tp->tm_hour);
        if (_St != ios_base::goodbit || *_F != _Colon)
            _St |= ios_base::failbit;
        else
            _St |= _Getint(++_F, _L, 0, 59, _Tp->tm_min);
        if (_St != ios_base::goodbit || *_F != _Colon)
            _St |= ios_base::failbit;
        else
            _St |= _Getint(++_F, _L, 0, 59, _Tp->tm_sec);
        return (_F); }
    virtual _II do_get_date(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, tm *_Tp) const    // Dec 2, 1979
        {_F = get_monthname(_F, _L, _X, _St, _Tp);
        if (_St != ios_base::goodbit || *_F != _WIDEN(_E, ' '))
            _St |= ios_base::failbit;
        else
            _St |= _Getint(++_F, _L, 1, 31, _Tp->tm_mday);
        if (_St != ios_base::goodbit || *_F != _WIDEN(_E, ','))
            _St |= ios_base::failbit;
        else if (++_F == _L || *_F != _WIDEN(_E, ' '))
            _St |= ios_base::failbit;
        else
            _F = get_year(++_F, _L, _X, _St, _Tp);
        if (_F == _L)
            _St |= ios_base::eofbit;
        return (_F); }
    virtual _II do_get_weekday(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, tm *_Tp) const
        {int _N = _Getloctxt(_F, _L, (size_t)0, _Days);
        if (_N < 0)
            _St |= ios_base::failbit;
        else
            _Tp->tm_wday = _N >> 1;
        return (_F); }
    virtual _II do_get_monthname(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, tm *_Tp) const
        {int _N = _Getloctxt(_F, _L, (size_t)0, _Months);
        if (_N < 0)
            _St |= ios_base::failbit;
        else
            _Tp->tm_mon = _N >> 1;
        return (_F); }
    virtual _II do_get_year(_II _F, _II _L, ios_base& _X,
        ios_base::iostate& _St, tm *_Tp) const
        {int _Ans;
        _St |= _Getint(_F, _L, 0, 2035, _Ans);
        if (_St & ios_base::failbit)
            ;
        else if (1900 <= _Ans)
            _Ans -= 1900;
        else if (2035 - 1900 < _Ans)
            _St |= ios_base::failbit;
        if (!(_St & ios_base::failbit))
            _Tp->tm_year = _Ans;
        return (_F); }
private:
    static ios_base::iostate _Getint(_II& _F, _II& _L,
        int _Lo, int _Hi, int& _V)
        {char _Ac[_MAX_INT_DIG], *_Ep;
        char *_P = _Ac;
        if (_F == _L)
            ;
        else if (*_F == _WIDEN(_E, '+'))
            *_P++ = '+', ++_F;
        else if (*_F == _WIDEN(_E, '-'))
            *_P++ = '-', ++_F;
        bool _Sd = false;
        while (_F != _L && *_F == _WIDEN(_E, '0'))
            _Sd = true, ++_F;
        if (_Sd)
            *_P++ = '0';
        for (char *const _Pe = &_Ac[_MAX_INT_DIG - 1]; _F != _L
            && '0' <= (*_P = _NARROW(_E, *_F)) && *_P <= '9';
            _Sd = true, ++_F)
            if (_P < _Pe)
                ++_P;
        if (!_Sd)
            _P = _Ac;
        *_P = '\0';
        errno = 0;
        const long _Ans = strtol(_Ac, &_Ep, 10);
        ios_base::iostate _St = ios_base::goodbit;
        if (_F == _L)
            _St |= ios_base::eofbit;
        if (_Ep == _Ac || errno != 0 || _Ans < _Lo || _Hi < _Ans)
            _St |= ios_base::failbit;
        else
            _V = _Ans;
        return (_St); }
    _E *_Days, *_Months;
    };

template<class _E, class _II>
    locale::id time_get<_E, _II>::id;

        // TEMPLATE CLASS time_get_byname
template<class _E,
    class _II = istreambuf_iterator<_E, char_traits<_E> > >
    class time_get_byname : public time_get<_E, _II> {
public:
    explicit time_get_byname(const char *_S, size_t _R = 0);
protected:
    virtual ~time_get_byname()
        {}
    };

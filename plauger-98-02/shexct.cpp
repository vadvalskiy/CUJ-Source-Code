typedef basic_istream<_E, _Tr> _Myt;
typedef basic_ios<_E, _Tr> _Myios;
typedef istreambuf_iterator<_E, _Tr> _Iter;
typedef num_get<_E, _Iter> _Nget;

_Myt& _Myt::operator>>(short& _X)
    {ios_base::iostate _St = ios_base::goodbit;
    const sentry _Ok(*this);
    if (_Ok)
        {long _Y;
        const _Nget& _Fac =
            use_facet<_Nget>(ios_base::getloc());
        try
            {_Fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
                *this, _St, _Y); }
        catch (...)
            _Myios::setstate(ios_base::badbit, true); }
        if (_St & ios_base::failbit
            || _Y < SHRT_MIN || SHRT_MAX < _Y)
            _St |= ios_base::failbit;
        else
            _X = _Y; }
    _Myios::setstate(_St);
    return (*this); }

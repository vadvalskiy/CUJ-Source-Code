typedef basic_ostream<_E, _Tr> _Myt;
typedef basic_ios<_E, _Tr> _Myios;
typedef ostreambuf_iterator<_E, _Tr> _Iter;
typedef num_put<_E, _Iter> _Nput;

_Myt& operator<<(short _X)
    {ios_base::iostate _St = ios_base::goodbit;
    const sentry _Ok(*this);
    if (_Ok)
        {const _Nput& _Fac =
            use_facet<_Nput>(ios_base::getloc());
        ios_base::fmtflags _Bfl =
            ios_base::flags() & ios_base::basefield;
        long _Y = (_Bfl == oct || _Bfl == hex)
            ? (long)(unsigned short)_X : (long)_X;
        try {
            if (_Fac.put(_Iter(_Myios::rdbuf()), *this,
                _Myios::fill(), _Y).failed())
                _St |= ios_base::badbit; }
        catch (...)
            _Myios::setstate(ios_base::badbit, true); }
    _Myios::setstate(_St);
    return (*this); }

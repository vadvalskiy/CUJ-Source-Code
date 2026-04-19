template<class _E, class _Tr, class _A> inline
    bool locale::operator()(const basic_string<_E, _Tr, _A>& _X,
        const basic_string<_E, _Tr, _A>& _Y) const
    {const std::collate<_E>& _Fac = _USE(*this, std::collate<_E>);
    return (_Fac.compare(_X.c_str(), _X.c_str() + _X.size(),
        _Y.c_str(), _Y.c_str() + _Y.size()) < 0); }


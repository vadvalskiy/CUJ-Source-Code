        // TEMPLATE CLASS collate
template<class _E>
    class collate : public locale::facet {
public:
    typedef _E char_type;
    typedef basic_string<_E, char_traits<_E>,
        allocator<_E> > string_type;
    int compare(const _E *_F1, const _E *_L1,
        const _E *_F2, const _E *_L2) const
        {return (do_compare(_F1, _L1, _F2, _L2)); }
    string_type transform(const _E *_F, const _E *_L) const
        {return (do_transform(_F, _L)); }
    long hash(const _E *_F, const _E *_L) const
        {return (do_hash(_F, _L)); }
    static locale::id id;
    explicit collate(size_t _R = 0);
protected:
    ~collate()
        {}
    virtual int do_compare(const _E *_F1, const _E *_L1,
        const _E *_F2, const _E *_L2) const
        {return (_LStrcoll(_F1, _L1, _F2, _L2, &_Coll)); }
    virtual string_type do_transform(const _E *_F,
        const _E *_L) const
        {size_t _I, _N;
        string_type _Str;
        for (_N = _L - _F; ; )
            {_Str.append(_N, '\0');
            if ((_I = _LStrxfrm(&*_Str.begin(), &*_Str.end(),
                    _F, _L, &_Coll)) <= _Str.size())
                break;
            _N = _Str.size() < _I ? _I - _Str.size() : 1; }
        _Str.resize(_I);
        return (_Str); }
    virtual long do_hash(const _E *_F, const _E *_L) const
        {unsigned long _V = 0;
        for (; _F != _L; ++_F)
            _V = (_V << 8 | _V >> 24) + *_F;
        return ((long)_V); }
private:
    _Locinfo::_Collvec _Coll;
    };

template<class _E>
    locale::id collate<_E>::id;


        // TEMPLATE CLASS collate_byname
template<class _E>
    class collate_byname : public collate<_E> {
public:
    explicit collate_byname(const char *_S, size_t _R = 0);
protected:
    virtual ~collate_byname()
        {}
    };

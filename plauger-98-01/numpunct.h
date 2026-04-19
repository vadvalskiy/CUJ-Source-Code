        // TEMPLATE CLASS numpunct
template<class _E>
    class numpunct : public locale::facet {
public:
    typedef basic_string<_E, char_traits<_E>, allocator<_E> >
        string_type;
    typedef _E char_type;
    static locale::id id;
    _E decimal_point() const
        {return (do_decimal_point()); }
    _E thousands_sep() const
        {return (do_thousands_sep()); }
    string grouping() const
        {return (do_grouping()); }
    string_type falsename() const
        {return (do_falsename()); }
    string_type truename() const
        {return (do_truename()); }
    explicit numpunct(size_t _R = 0);
protected:
    virtual ~numpunct();
    virtual _E do_decimal_point() const;
    virtual _E do_thousands_sep() const;
    virtual string do_grouping() const;
    virtual string_type do_falsename() const;
    virtual string_type do_truename() const;
    };

template<class _E>
    locale::id numpunct<_E>::id;

        // TEMPLATE CLASS numpunct_byname
template<class _E>
    class numpunct_byname : public numpunct<_E> {
public:
    explicit numpunct_byname(const char *_S, size_t _R = 0);
protected:
    virtual ~numpunct_byname()
        {}
    };

template<class E, class OutIt = ostreambuf_iterator<E> >
    class time_put : public locale::facet {
public:
    typedef E char_type;
    typedef OutIt iter_type;
    explicit time_put(size_t refs = 0);
    iter_type put(iter_type next, ios_base& x,
        char_type fill, const tm *pt, char fmt, 
        char mod = 0) const;
    iter_type put(iter_type next, ios_base& x,
        char_type fill, const tm *pt, const E *first, 
        const E *last) const;
    static locale::id id;
protected:
    ~time_put();
    virtual iter_type do_put(iter_type next, ios_base& x,
        char_type fill, const tm *pt, char fmt, 
        char mod = 0) const;
    };

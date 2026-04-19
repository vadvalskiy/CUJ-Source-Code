        // STRUCT messages_base
struct messages_base : public locale::facet {
    typedef int catalog;
    explicit messages_base(size_t _R = 0)
        : locale::facet(_R) {}
    };

        // TEMPLATE CLASS messages
template<class _E>
    class messages : public messages_base {
public:
    typedef _E char_type;
    typedef basic_string<_E, char_traits<_E>,
        allocator<_E> > string_type;
    catalog open(const string& _X, const locale& _L) const
        {return (do_open(_X, _L)); }
    string_type get(catalog _C, int _S, int _M,
        const string_type& _D) const
        {return (do_get(_C, _S, _M, _D)); }
    void close(catalog _C) const
        {do_close(_C); }
    static locale::id id;
    explicit messages(size_t _R = 0);
protected:
    virtual catalog do_open(const string&, const locale&) const
        {return (0); }
    virtual string_type do_get(catalog, int,
        int _M, const string_type& _D) const
        {return (_D); }
    virtual void do_close(catalog) const
        {}
    };

template<class _E>
    locale::id messages<_E>::id;

        // TEMPLATE CLASS messages_byname
template<class _E>
    class messages_byname : public messages<_E> {
public:
    explicit messages_byname(const char *_S, size_t _R = 0);
protected:
    virtual ~messages_byname()
        {}
    };

class locale {
public:
    enum category {collate, ctype, monetary,
        numeric, time, messages, all, none};
            // CLASS id
    class id {
    public:
        id(size_t _X = 0)
            : _Id(_X) {}
        operator size_t()
            {_Lockit _Lk;
            if (_Id == 0)
                _Id = ++_Id_cnt;
            return (_Id); }
    private:
        size_t _Id;
        static int _Id_cnt;
        };
    class _Locimp;
            // class facet
    class facet {
        friend class locale;
        friend class _Locimp;
    public:
        static size_t _Getcat()
            {return ((size_t)(-1)); }
        void _Incref()
            {_Lockit _Lk;
            if (_Refs < (size_t)(-1))
                ++_Refs; }
        facet *_Decref()
            {_Lockit _Lk;
            if (0 < _Refs && _Refs < (size_t)(-1))
                --_Refs;
            return (_Refs == 0 ? this : 0); }
    protected:
        virtual ~facet()
            {}
        explicit facet(size_t _R = 0)
            : _Refs(_R) {}
    private:
        facet(const facet&);    // undefined
        const facet& operator=(const facet&);    // undefined
        size_t _Refs;

        };
            // CLASS _Locimp
    class _Locimp : public facet {
    protected:
        ~_Locimp();
    private:
        friend class locale;
        _Locimp(bool _Xp = false);
        _Locimp(const _Locimp&);
        void _Addfac(facet *, size_t);
        static _Locimp * _Makeloc(const _Locinfo&,
            category, _Locimp *, const locale *);
        facet **_Fv;
        size_t _Nfv;
        category _Cat;
        bool _Xpar;
        string _Name;
        static _Locimp *_Clocptr, *_Global;
        };
    template<class _E, class _Tr, class _A>
        bool operator()(const basic_string<_E, _Tr, _A>&,
            const basic_string<_E, _Tr, _A>&) const;
    template<class _F>
        locale(const locale& _X, _F *_Fac);
    template<class _F>
        locale combine(
            const locale& _X,);
    locale() throw()
        : _Ptr(_Init())
        {_Locimp::_Global->_Incref(); }
    locale(_Uninitialized)
        {}
    locale(const locale& _X) throw()
        : _Ptr(_X._Ptr)
        {_Ptr->_Incref(); }
    locale(const locale&, const locale&, category);
    explicit locale(const char *, category = all);
    locale(const locale&, const char *, category);
    ~locale() throw()
        {if (_Ptr != 0)
            delete _Ptr->_Decref(); }
    locale& operator=(const locale& _X) throw()
        {if (_Ptr != _X._Ptr)
            {delete _Ptr->_Decref();
            _Ptr = _X._Ptr;
            _Ptr->_Incref(); }
        return (*this); }
    string name() const
        {return (_Ptr->_Name); }
    const facet *_Getfacet(size_t _Id) const;
    bool operator==(const locale&) const;
    bool operator!=(const locale& _X) const
        {return (!(*this == _X)); }
    static const locale& classic();
    static locale global(const locale&);
    static locale empty();
private:
    locale(_Locimp *_P)
        : _Ptr(_P) {}
    static _Locimp *_Init();
    _Locimp *_Ptr;
    };



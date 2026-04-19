namespace std {
    class locale {
    public:
    // types:
      class facet;
      class id;
      typedef int category;
      static const category   // values are for exposition only
        none     = 0,
        collate  = 0x010, ctype    = 0x020,
        monetary = 0x040, numeric  = 0x080,
        time     = 0x100, messages = 0x200,
        all = collate | ctype | monetary
            | numeric | time  | messages;
    // construct/copy/destroy:
      locale() throw()
      locale(const locale& other) throw()
      explicit locale(const char* std_name);
      locale(const locale& other,
        const char* std_name, category);
      template <class Facet>
        locale(const locale& other, Facet* f);
      template <class Facet>
        locale(const locale& other, const locale& one);
      locale(const locale& other,
        const locale& one, category);
     ~locale() throw();  // non-virtual
      const locale& operator=(const locale& other) throw();
    // locale operations:
      basic_string<char> name() const;
      bool operator==(const locale& other) const;
      bool operator!=(const locale& other) const;
      template <class charT, class Traits, class Allocator>
        bool operator()
            (const basic_string<charT, Traits, Allocator>& s1,
            const basic_string<charT, Traits, Allocator>& s2) const;
    // global locale objects:
      static locale global(const locale&);
      static const locale& classic();
    };
  }

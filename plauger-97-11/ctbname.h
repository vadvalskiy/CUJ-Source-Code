        // TEMPLATE CLASS ctype_byname
template<class _E>
    class ctype_byname : public ctype<_E> {
public:
    explicit ctype_byname(const char *_S, size_t _R = 0)
        : ctype<_E>(_Locinfo(_S), _R) {}
protected:
    virtual ~ctype_byname()
        {}
    };



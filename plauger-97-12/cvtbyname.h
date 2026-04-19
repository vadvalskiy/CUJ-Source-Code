        // TEMPLATE CLASS codecvt_byname
template<class _E, class _To, class _St>
    class codecvt_byname : public codecvt<_E, _To, _St> {
public:
    explicit codecvt_byname(const char *_S, size_t _R = 0)
        : codecvt<_E, _To, _St>(_Locinfo(_S), _R) {}
_PROTECTED:
    virtual ~codecvt_byname()
        {}
    };



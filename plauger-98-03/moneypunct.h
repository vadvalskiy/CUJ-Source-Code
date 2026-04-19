                // TEMPLATE CLASS moneypunct
template<class _E, bool _Intl = false>
        class moneypunct : public _Mpunct<_E> {
public:
        static const bool intl;
        static locale::id id;
        explicit moneypunct(size_t _R = 0)
                : _Mpunct<_E>(_R, _Intl) {}
        };

template<class _E, bool _Intl>
        const bool moneypunct<_E, _Intl>::intl = _Intl;
template<class _E, bool _Intl>
        locale::id moneypunct<_E, _Intl>::id;

                // TEMPLATE CLASS moneypunct_byname
template<class _E, bool _Intl = false>
        class moneypunct_byname : public moneypunct<_E, _Intl> {
public:
        explicit moneypunct_byname(const char *_S, size_t _R = 0);
protected:
        virtual ~moneypunct_byname();
        };


--------------------- end of Listing 3 ---------------



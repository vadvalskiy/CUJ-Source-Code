using namespace std;
typedef codecvt<wchar_t, char, mbstate_t> Mybase;

        // CLASS Simple_codecvt
class Simple_codecvt : public Mybase {
public:
    typedef wchar_t _E;
    typedef char _To;
    typedef mbstate_t _St;

    explicit Simple_codecvt(size_t _R = 0)
        : Mybase(_R) {}

protected:
    virtual result do_in(_St& _State,
        const _To *_F1, const _To *_L1, const _To *& _Mid1,
        _E *_F2, _E *_L2, _E *& _Mid2) const
        {return (noconv); }

    virtual result do_out(_St& _State,
        const _E *_F1, const _E *_L1, const _E *& _Mid1,
        _To *_F2, _To *_L2, _To *& _Mid2) const
        {return (noconv); }

    virtual result do_unshift(_St& _State,
        _To *_F2, _To *_L2, _To *& _Mid2) const
        {return (noconv); }

    virtual int do_length(_St& _State, const _To *_F1,
        const _To *_L1, size_t _N2) const _THROW0()
        {return (_N2 < (size_t)(_L1 - _F1)
            ? _N2 : _L1 - _F1); }

    virtual bool do_always_noconv() const _THROW0()
        {return (true); }

    virtual int do_max_length() const _THROW0()
        {return (2); }

    virtual int do_encoding() const _THROW0()
        {return (2); }
    };

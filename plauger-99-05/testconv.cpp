using namespace std;

typedef codecvt<wchar_t, char, mbstate_t> Mybase;

        // CLASS Mycodecvt
class Mycodecvt : public Mybase {
public:
    typedef wchar_t _E;
    typedef char _To;
    typedef mbstate_t _St;

    explicit Mycodecvt(size_t _R = 0)
        : Mybase(_R) {}

protected:
    virtual result do_in(_St& _State,
        const _To *_F1, const _To *_L1, const _To *& _Mid1,
        _E *_F2, _E *_L2, _E *& _Mid2) const
        {_Mid1 = _F1, _Mid2 = _F2;
        result _Ans = ok;
        if (_Mid1 == _L1 || _Mid2 == _L2)
            ;
        else if ((*_Mid1 & 0x80) == 0x00)
            *_Mid2++ = *_Mid1++ & 0xff;
        else if ((*_Mid1 & 0xe0) == 0xc0)
            if (_Mid1 + 1 == _L1)
                _Ans = partial; // need 2 bytes
            else if ((_Mid1[1] & 0xc0) != 0x80)
                _Ans = error;   // bad byte 2
            else    // deliver 2-byte code
                {*_Mid2 = (*_Mid1++ & 0x1f) << 6;
                *_Mid2++ |= *_Mid1++ & 0x3f; }
        else if ((*_Mid1 & 0xf0) == 0xe0)
            if (_Mid1 + 1 == _L1 || _Mid1 + 2 == _L1)
                _Ans = partial; // need 3 bytes
            else if ((_Mid1[1] & 0xc0) != 0x80
                || (_Mid1[2] & 0xc0) != 0x80)
                _Ans = error;   // bad byte 2 or 3
            else    // deliver 3-byte code
                {*_Mid2 = (*_Mid1++ & 0x0f) << 12;
                *_Mid2 |= (*_Mid1++ & 0x3f) << 6;
                *_Mid2++ |= *_Mid1++ & 0x3f; }
        else
            _Ans = error;   // bad byte 1
        return (_Ans); }

    virtual result do_out(_St& _State,
        const _E *_F1, const _E *_L1, const _E *& _Mid1,
        _To *_F2, _To *_L2, _To *& _Mid2) const
        {_Mid1 = _F1, _Mid2 = _F2;
        if (_Mid1 == _L1 || _Mid2 == _L2)
            return (ok);
        else if ((*_Mid1 & 0xff80) == 0x0000)
            {*_Mid2++ = *_Mid1++;   // put 1 byte
            return (ok); }
        else if ((*_Mid1 & 0xf800) == 0x0000)
            if (_Mid2 + 1 == _L2)
                return (partial);
            else    // put 2 bytes
                {*_Mid2++ = 0xc0 | (*_Mid1 >> 6);
                *_Mid2++ = 0x80 | (*_Mid1++ & 0x3f);
                return (ok); }
        else    // put 3 bytes
            if (_Mid2 + 1 == _L2 || _Mid2 + 2 == _L2)
                return (partial);
            else
                {*_Mid2++ = 0xe0 | (*_Mid1 >> 12);
                *_Mid2++ = 0x80 | (*_Mid1 >> 6 & 0x3f);
                *_Mid2++ = 0x80 | (*_Mid1++ & 0x3f);
                return (ok); }}

    virtual result do_unshift(_St& _State,
        _To *_F2, _To *_L2, _To *& _Mid2) const
        {return (ok); }

    virtual int do_length(_St& _State, const _To *_F1,
        const _To *_L1, size_t _N2) const _THROW0()
        {int _Ans = 0;
        for (; _F1 != _L1; )
            if ((*_F1 & 0x80) == 0x00)
                ++_F1, ++_Ans;
            else if ((*_F1 & 0xe0) == 0xc0
                && _F1 + 1 != _L1
                && (_F1[1] & 0xc0) == 0x80)
                _F1 += 2, _Ans += 2;
            else if ((*_F1 & 0xf0) == 0xe0
                && _F1 + 1 != _L1
                && _F1 + 2 != _L1
                && (_F1[1] & 0xc0) == 0x80
                && (_F1[2] & 0xc0) == 0x80)
                _F1 += 3, _Ans += 3;
            else
                break;  // erroneous code
        return (_Ans); }

    virtual bool do_always_noconv() const _THROW0()
        {return (false); }

    virtual int do_max_length() const _THROW0()
        {return (3); }

    virtual int do_encoding() const _THROW0()
        {return (0); }
    };

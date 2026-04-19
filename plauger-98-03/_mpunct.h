                // TEMPLATE CLASS _Mpunct
template<class _E>
        class _Mpunct : public money_base {
public:
        typedef _E char_type;
        typedef basic_string<_E, char_traits<_E>, allocator<_E> >
                string_type;
        _E decimal_point() const
                {return (do_decimal_point()); }
        _E thousands_sep() const
                {return (do_thousands_sep()); }
        string grouping() const
                {return (do_grouping()); }
        string_type curr_symbol() const
                {return (do_curr_symbol()); }
        string_type positive_sign() const
                {return (do_positive_sign()); }
        string_type negative_sign() const
                {return (do_negative_sign()); }
        int frac_digits() const
                {return (do_frac_digits()); }
        pattern pos_format() const
                {return (do_pos_format()); }
        pattern neg_format() const
                {return (do_neg_format()); }
        explicit _Mpunct(size_t _R, bool _Intl)
                : money_base(_R), _Ifl(_Intl) {_Init(); }
protected:
        virtual ~_Mpunct()
                {delete[] _Mgr;
                delete[] _Mcs;
                delete[] _Mps;
                delete[] _Mns; }
        virtual _E do_decimal_point() const
                {return (_Mdp); }
        virtual _E do_thousands_sep() const
                {return (_Mks); }
        virtual string do_grouping() const
                {return (string(_Mgr)); }
        virtual string_type do_curr_symbol() const
                {return (string_type(_Mcs)); }
        virtual string_type do_positive_sign() const
                {return (string_type(_Mps)); }
        virtual string_type do_negative_sign() const
                {return (string_type(_Mns)); }
        virtual int do_frac_digits() const
                {return (_Mfd); }
        virtual pattern do_pos_format() const
                {return (_Mpf); }
        virtual pattern do_neg_format() const
                {return (_Mnf); }
private:
        void _Init()
                {const lconv *_P = localeconv();        // SIMPLIFIED
                _Mdp = _WIDEN(_E, _P->mon_decimal_point[0]);
                _Mks = _WIDEN(_E, _P->mon_thousands_sep[0]);
                _Mgr = _MAKLOCSTR(char, _P->mon_grouping);
                _Mcs = _MAKLOCSTR(_E, _Ifl ? _P->int_curr_symbol
                        : _P->currency_symbol);
                _Mps = _MAKLOCSTR(_E, 4 < (unsigned int)_P->p_sign_posn
                        ? "" : _P->positive_sign);
                _Mns = _MAKLOCSTR(_E, 4 < (unsigned int)_P->n_sign_posn
                        ? "-" : _P->negative_sign);
                _Mfd = _Ifl ? _P->int_frac_digits
                        : _P->frac_digits;
                if (_Mfd < 0 || CHAR_MAX <= _Mfd)
                        _Mfd = 0;
                _Makpat(_Mpf, _P->p_sep_by_space,
                        _P->p_cs_precedes, _P->p_sign_posn);
                _Makpat(_Mnf, _P->n_sep_by_space,
                        _P->n_cs_precedes, _P->n_sign_posn); }
        void _Makpat(pattern& _Pat, char _Sep, char _Pre, char _Pos)
                {const char *_S = _Ifl || (_Sep & ~1) != 0
                        || (_Pre & ~1) != 0 || 4 < (unsigned int)_Pos
                        ? "$+vx" : "+v$x" "+v$x" "v$+x" "v+$x" "v$+x"
                                "+$vx" "+$vx" "$v+x" "+$vx" "$+vx"
                                "+v $" "+v $" "v $+" "v+ $" "v $+"
                                "+$ v" "+$ v" "$ v+" "+$ v" "$ +v" + (_Pos
                                + (_Pre == 1 ? 20 : 0) + (_Sep == 1 ? 40 : 0));
                memcpy(_Pat.field, _S, 4); }
        char *_Mgr;
        _E _Mdp, _Mks, *_Mcs, *_Mps, *_Mns;
        int _Mfd;
        pattern _Mpf, _Mnf;
        bool _Ifl;
        };

#include <iomanip>
#include <iostream>
#include <locale>
using namespace std;

        // MONETARY TYPES
typedef long double MoneyVal;

class Money {
public:
    Money(MoneyVal v)
        : value(v) {}
    operator MoneyVal() const
        {return (value); }
private:
    MoneyVal value;
    };

        // Money INSERTER
template<class _E, class _Tr> inline
    basic_ostream<_E, _Tr>& operator<<(
        basic_ostream<_E, _Tr>& _O, Money _Y)
    {typedef ostreambuf_iterator<_E, _Tr> _Iter;
    typedef money_put<_E, _Iter> _Mput;

    ios_base::iostate _St = ios_base::goodbit;
    const typename basic_ostream<_E, _Tr>::sentry _Ok(_O);
    if (_Ok)
        {try
            {const _Mput& _Fac =
                _USEFAC(_O.getloc(), _Mput);
            if (_Fac.put(_Iter(_O.rdbuf()),
                (_O.flags() & ios_base::showpos) != 0,
                _O, _O.fill(), _Y).failed())
                _St |= ios_base::badbit; }
        catch (...)
            {_O.setstate(ios_base::badbit, true); }}
    _O.setstate(_St);
    return (_O); }

        // moneypunct FOR USA LOCALE
money_base::pattern mon_fmt = {
    money_base::symbol, money_base::space,
    money_base::sign, money_base::value};

class Mymoneypunct
    : public moneypunct<char, false> {
protected:
    virtual char do_decimal_point() const
        {return ('.'); }
    virtual char do_thousands_sep() const
        {return (','); }
    virtual string do_grouping() const
        {return (string("\3")); }
    virtual string do_curr_symbol() const
        {return (string("$")); }
    virtual string do_positive_sign() const
        {return (string("")); }
    virtual string do_negative_sign() const
        {return (string("-")); }
    virtual int do_frac_digits() const
        {return (2); }
    virtual pattern do_pos_format() const
        {return (mon_fmt); }
    virtual pattern do_neg_format() const
        {return (mon_fmt); }
    };

int main()
    {locale loc = _ADDFAC(locale::classic(), new Mymoneypunct);
    cout.imbue(loc);

    cout << showbase << setw(20) << internal << setfill('*')
        << Money(123456789.0) << endl;
    return (0); }

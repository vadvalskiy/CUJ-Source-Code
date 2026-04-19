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

        // Money EXTRACTOR
template<class _E, class _Tr> inline
    basic_istream<_E, _Tr>& operator>>(
        basic_istream<_E, _Tr>& _I, Money& _X)
    {typedef istreambuf_iterator<_E, _Tr> _Iter;
    typedef money_get<_E, _Iter> _Mput;

    ios_base::iostate _St = ios_base::goodbit;
    const typename basic_istream<_E, _Tr>::sentry _Ok(_I);
    MoneyVal _V;
    if (_Ok)
        {try
            {const _Mput& _Fac =
                _USEFAC(_I.getloc(), _Mput);
            _Fac.get(_Iter(_I.rdbuf()), _Iter(0),
                (_I.flags() & ios_base::showpos) != 0,
                _I, _St, _V); }
        catch (...)
            {_I.setstate(ios_base::badbit, true); }}
    if ((_St & ios_base::failbit) == 0)
        _X = Money(_V);
    _I.setstate(_St);
    return (_I); }

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
    {Money x(0);
    locale loc = _ADDFAC(locale::classic(), new Mymoneypunct);
    cin.imbue(loc);
    cout.imbue(loc);

    while (cin >> x)
        cout << showbase << setw(20) << internal << setfill('*')
            << x << endl;
    return (0); }

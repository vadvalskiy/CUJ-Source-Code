#include <iostream>
#include <locale>
#include <string.h>
#include <time.h>
using namespace std;

        // FORMATTED TIME TYPES

class Time_fmt {
public:
    Time_fmt(time_t t = time(0), const char *fmt = "%c")
        : value(*localtime(&t)), format(fmt) {}
    Time_fmt(tm v, const char *fmt = "%c")
        : value(v), format(fmt) {}
    const tm *valptr() const
        {return (&value); }
    void setvalptr(const tm& val)
        {value = val; }
    const char *fmt_first() const
        {return (format); }
    const char *fmt_last() const
        {return (format + strlen(format)); }
private:
    tm value;
    const char *format;
    };

class Time_dayname : public Time_fmt {
public:
    Time_dayname(Time_fmt x)
        : Time_fmt(*x.valptr(), "%A") {}
    };

        // Time INSERTER
template<class _E, class _Tr> inline
    basic_ostream<_E, _Tr>& operator<<(
        basic_ostream<_E, _Tr>& _O, Time_fmt _Y)
    {typedef ostreambuf_iterator<_E, _Tr> _Iter;
    typedef time_put<_E, _Iter> _Tput;

    ios_base::iostate _St = ios_base::goodbit;
    const typename basic_ostream<_E, _Tr>::sentry _Ok(_O);
    if (_Ok)
        {try
            {const _Tput& _Fac =
                _USEFAC(_O.getloc(), _Tput);
            if (_Fac.put(_Iter(_O.rdbuf()),
                _O, _O.fill(), _Y.valptr(),
                _Y.fmt_first(), _Y.fmt_last()).failed())
                _St |= ios_base::badbit; }
        catch (...)
            {_O.setstate(ios_base::badbit, true); }}
    _O.setstate(_St);
    return (_O); }

        // Time EXTRACTOR
template<class _E, class _Tr> inline
    basic_istream<_E, _Tr>& operator>>(
        basic_istream<_E, _Tr>& _I, Time_fmt& _X)
    {typedef istreambuf_iterator<_E, _Tr> _Iter;
    typedef time_get<_E, _Iter> _Mput;

    ios_base::iostate _St = ios_base::goodbit;
    const typename basic_istream<_E, _Tr>::sentry _Ok(_I);
    tm _V = {0};
    if (_Ok)
        {try
            {const _Tput& _Fac =
                _USEFAC(_I.getloc(), _Tput);
            _Fac.get_date(_Iter(_I.rdbuf()), _Iter(0),
            _I, _St, &_V); }
        catch (...)
            {_I.setstate(ios_base::badbit, true); }}
    if ((_St & ios_base::failbit) == 0)
        _X.setvalptr(_V);
    _I.setstate(_St);
    return (_I); }

int main()
    {Time_fmt date;
    while (cin >> date)
        cout << date << endl;
    return (0); }

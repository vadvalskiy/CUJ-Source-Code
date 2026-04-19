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

int main()
    {Time_fmt today;
    cout << today
        << " which is on " << (Time_dayname)today
        << endl;
    return (0); }

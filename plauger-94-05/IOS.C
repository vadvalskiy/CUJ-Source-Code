
---------------- Listing 3: The file ios.c ----------------

// ios -- ios basic members
#include <iostream>

int ios::_Index = 0;

ios::failure::~failure()
    {    // destruct a failure
    }

ios::~ios()
    {    // destruct an ios -- DO (ALMOST) NOTHING
    if (this != (ios *)&cin && this != (ios *)&cout
        && this != (ios *)&cerr && this != (ios *)&clog)
        _Tidy();
    }

void ios::clear(iostate ns)
    {    // clear all but selected state bits
    _State = ns & _Statmask;
    if (_Sb == 0)
        _State |= badbit;
    if (_State & _Except)
        failure("ios::failure", "ios::clear",
            _State & badbit ? "badbit set"
            : _State & failbit ? "failbit set"
            : "eofbit set").raise();
    }

void ios::init(streambuf *sb)
    {    // initialize a new ios
    _Sb = sb;
    _Tiestr = 0;
    _Except = goodbit;
    _Fmtfl = skipws | dec;
    _Prec = 6;
    _Wide = 0;
    _Fillch = ' ';
    _Arr = 0;
    clear(goodbit);
    }

void ios::_Tidy()
    {    // discard storage for an ios
    _Iosarray *q1, *q2;
    if (_Arr != 0 && 0 <= _Arr->_Index)
        {    // discard if not for standard stream
        for (q1 = _Arr; q1 != 0; q1 = q2)
            q2 = q1->_Next, delete q1;
        }
        _Arr = 0;
    }



--------------- Listing 5: The function ios;:copyfmt(ios&) --------------

// ioscopyfmt -- ios::copyfmt(const ios&)
#include <ios>

ios& ios::copyfmt(const ios& rhs)
    {    // copy format info from another ios
    if (this != &rhs)
        {    // copy all but _Sb and _State
        _Tidy();
        _Tiestr = rhs._Tiestr;
        _Fmtfl = rhs._Fmtfl;
        _Prec = rhs._Prec;
        _Wide = rhs._Wide;
        _Fillch = rhs._Fillch;
        _Iosarray *p = rhs._Arr;
        for (_Arr = 0; p != 0; p = p->_Next)
            if (p->_Lo != 0 || p->_Vp != 0)
                {    // copy over nonzero array values
                iword(p->_Index) = p->_Lo;
                pword(p->_Index) = p->_Vp;
                }
        exceptions(rhs._Except);    // cause any throw at end
        }
    return (*this);
    }



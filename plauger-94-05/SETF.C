
--------------- Listing 10: The function ios::setf(fmtflags) -----------

// iossetf1 -- ios::setf(fmtflags)
#include <ios>

ios::fmtflags ios::setf(fmtflags nf)
    {    // set format bits
    ios::fmtflags of = _Fmtfl;
    _Fmtfl |= nf & _Fmtmask;
    return (of);
    }



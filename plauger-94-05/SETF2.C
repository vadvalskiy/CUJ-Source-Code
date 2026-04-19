
--------- Listing 11: The function ios::setf(fmtflags, fmtflags) -----------

// iossetf2 -- ios::setf(fmtflags, fmtflags)
#include <ios>

ios::fmtflags ios::setf(fmtflags nf, fmtflags mask)
    {    // set format bits under mask
    ios::fmtflags of = _Fmtfl;
    _Fmtfl = (_Fmtfl & ~mask) | (nf & mask & _Fmtmask);
    return (of);
    }



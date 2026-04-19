
----------- Listing 6: The function ios::rdbuf(streambuf *) -----------

// iosrdbuf -- ios::rdbuf(streambuf *)
#include <ios>

streambuf *ios::rdbuf(streambuf *nb)
    {    // set new streambuf
    streambuf *ob = _Sb;
    _Sb = nb;
    clear(goodbit);
    return (ob);
    }



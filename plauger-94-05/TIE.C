
------------- Listing 9: The function ios::tie(ostream *) --------------

// iostie -- ios::tie(ostream *)
#include <ios>

ostream *ios::tie(ostream *nt)
    {    // set new tie
    ostream *ot = _Tiestr;
    _Tiestr = nt;
    return (ot);
    }



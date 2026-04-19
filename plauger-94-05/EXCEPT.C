
------------ Listing 4: The function ios::exceptions(iostate) -------------

// iosexceptions -- ios::exceptions(iostate)
#include <ios>

void ios::exceptions(iostate ne)
    {    // set selected exception bits
    _Except = ne & _Statmask;
    clear(_State);
    }



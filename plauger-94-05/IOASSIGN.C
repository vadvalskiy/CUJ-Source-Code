
--------------- Listing 7: The ios assignment operator ------------

// iosassign -- ios::operator=(const ios&)
#include <ios>

ios& ios::operator=(const ios& rhs)
    {    // assign to an ios
    if (this != &rhs)
        {    // safe to copy
        _Sb = rhs._Sb;
        _State = rhs._State;
        copyfmt(rhs);    // cause any throw at end
        }
    return (*this);
    }



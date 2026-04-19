
----------------- Listing 8: The ios copy constructor --------------

// ioscopy -- ios::ios(const ios&)
#include <ios>

ios::ios(const ios& rhs)
    {    // construct an ios from copy
    init(0);
    *this = rhs;
    }



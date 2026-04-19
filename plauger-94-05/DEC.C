
--------------------- Listing 14: The function dec(ios&) ----------------

// dec -- dec(ios&)
#include <ios>

ios& dec(ios& strios)
    {    // set decimal input/output mode
    strios.setf(ios::dec, ios::basefield);
    return (strios);
    }



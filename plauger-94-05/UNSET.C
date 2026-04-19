
---------------- Listing 12: The function ios::unset(fmtflags) ----------

// iosunsetf -- ios::unsetf(fmtflags)
#include <ios>

void ios::unsetf(fmtflags mask)
    {    // reset format bits under mask
    _Fmtfl &= ~mask;
    }



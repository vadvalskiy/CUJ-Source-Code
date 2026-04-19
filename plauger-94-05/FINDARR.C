
-------------- Listing 13: The function ios::_Findarr(int) ----------

// iosarray -- ios::_Findarr(int)
#include <ios>

ios::_Iosarray& ios::_Findarr(int idx)
    {    // locate or make a variable array element
    _Iosarray *p;
    if (idx < 0)
        failure("ios::failure", "ios::iword or pword",
            "index < 0").raise();
    for (p = _Arr; p != 0; p = p->_Next)
        if (p->_Index == idx)
            return (*p);
    _Arr = new _Iosarray(idx, _Arr);
    return (*_Arr);
    }



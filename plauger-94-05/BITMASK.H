
---------------- Listing 2: The macro _BITMASK ---------------------

// bitmask macros
#if _HAS_ENUM_OVERLOADING
 #define _BITMASK(E, T)    \
E& operator&=(E& _X, E _Y) \
    {_X = (E)(_X & _Y); return (_X); } \
E& operator|=(E& _X, E _Y) \
    {_X = (E)(_X | _Y); return (_X); } \
E& operator^=(E& _X, E _Y) \
    {_X = (E)(_X ^ _Y); return (_X); } \
E& operator&(E _X, E _Y) \
    {return ((E)(_X & _Y)); } \
E& operator|(E _X, E _Y) \
    {return ((E)(_X | _Y)); } \
E& operator^(E _X, E _Y) \
    {return ((E)(_X ^ _Y)); } \
E& operator~(E _X) \
    {return ((E)~_X); } \
typedef E T
#else
#define _BITMASK(E, T)    typedef int T
#endif



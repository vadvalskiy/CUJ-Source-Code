Listing 2 -- The function operator new(size_t)

// operator new(size_t) REPLACEABLE function
#include <stdlib.h>
#include <new>

void *operator new(size_t size)
        {       // try to allocate size bytes
        void *p;
        while ((p = malloc(size)) == 0 && _New_hand != 0)
                (*_New_hand)();
        return (p);
        }

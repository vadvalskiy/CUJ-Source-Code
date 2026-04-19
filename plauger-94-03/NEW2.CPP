Listing 4 -- The function operator new(size_t, void *)

// operator new(size_t, void *)
#include <new>

void *operator new(size_t, void *p)
        {       // allocate in place
        return (p);
        }

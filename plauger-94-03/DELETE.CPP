Listing 3 -- The function operator delete(void *)

// operator delete(void *) REPLACEABLE function
#include <stdlib.h>
#include <new>

void operator delete(void *p)
        {       // free an allocated object
        free(p);
        }

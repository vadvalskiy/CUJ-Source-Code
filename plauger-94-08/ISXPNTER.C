-------------------------- Listing 9: pointer to void extractor  ---------

// isxpointer -- istream::operator>>(void *&)
#include <errno.h>
#include <stdlib.h>
#include <istream>

istream& istream::operator>>(void *& pv)
	{	// extract a void *
	_TRY_IO_BEGIN
	if (!ipfx())
		setstate(failbit);
	else
		{	// gather characters and convert
		char ac[_MAX_INT_DIG], *ep;
		const int NL = 1 +
			(sizeof (void *) - 1) / sizeof (unsigned long);
		union {
			void *pv;
			unsigned long lo[NL];
			} u;
		for (int i = 0; ; )
			{	// gather pieces of pointer
			errno = 0;
			const unsigned long x =
				strtoul(ac, &ep, _Getifld(ac));
			if (ep == ac || errno != 0)
				setstate(failbit);
			else
				u.lo[i] = x;
			if (NL <= ++i)
				break;
			const int ch = rdbuf()->sbumpc();
			if (ch != ':')
				{	// report failure to match ':'
				if (ch != EOF)
					rdbuf()->sputbackc(ch);
				setstate(failbit);
				break;
				}
			}
		if (good())
			pv = u.pv;
		}
	isfx();
	_CATCH_IO_END
	return (*this);
	}

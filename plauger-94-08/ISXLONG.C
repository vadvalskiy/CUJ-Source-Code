-------------------------- Listing 6: long integer extractor  ---------

// isxlong -- istream::operator>>(long&)
#include <errno.h>
#include <stdlib.h>
#include <istream>

istream& istream::operator>>(long& lo)
	{	// extract a long
	_TRY_IO_BEGIN
	if (!ipfx())
		setstate(failbit);
	else
		{	// gather characters and convert
		char ac[_MAX_INT_DIG];
		char *ep;
		errno = 0;
		const long x = strtol(ac, &ep, _Getifld(ac));
		if (ep == ac || errno != 0)
			setstate(failbit);
		else
			lo = x;
		}
	isfx();
	_CATCH_IO_END
	return (*this);
	}

-------------------------- Listing 10: double extractor ---------

// isxdouble -- istream::operator>>(double&)
#include <errno.h>
#include <stdlib.h>
#include <istream>

istream& istream::operator>>(double& d)
	{	// extract a double
	_TRY_IO_BEGIN
	if (!ipfx())
		setstate(failbit);
	else
		{	// gather characters and convert
		char ac[_MAX_EXP_DIG+_MAX_SIG_DIG+16];
		char *ep;
		errno = 0;
		const double x = _Stod(ac, &ep, _Getffld(ac));
		if (ep == ac || errno != 0)
			setstate(failbit);
		else
			d = x;
		}
	isfx();
	_CATCH_IO_END
	return (*this);
	}

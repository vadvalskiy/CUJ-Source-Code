-------------------------- Listing x: simple _Stod function ---------

// xstod -- _Stod LIMITED SUBSTITUTE
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <istream>

double _Stod(const char *s, char **ep, long pten)
	{	// convert text to double and scale
	double x = strtod(s, ep);
	if (x != 0 && pten != 0)
		{	// scale the result
		while (pten < 0)
			x /= 10, ++ pten;	// MAY MISBEHAVE
		while (0 < pten)
			x *= 10, --pten;	// MAY MISBEHAVE
		if (x == 0 || x == HUGE_VAL || x == -HUGE_VAL)
			errno = ERANGE;	// MAY MISBEHAVE
		}
	return (x);
	}

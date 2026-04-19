-------------------------- Listing 8: int extractor  ---------

// isxint -- istream::operator>>(int&)
#include <limits.h>
#include <istream>

istream& istream::operator>>(int& i)
	{	// extract an int
	long lo;
	*this >> lo;
	if (!good() || lo < INT_MIN || INT_MAX < lo)
		setstate(failbit);
	else
		i = lo;
	return (*this);
	}

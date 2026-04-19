-------------------------- Listing 2:  char extractor ---------

// isxchar -- istream::operator>>(char&)
#include <istream>

istream& istream::operator>>(char& c)
	{	// extract an arbitrary character
	int ch;
	_TRY_IO_BEGIN
	if (!ipfx() || (ch = rdbuf()->sbumpc()) == EOF)
		setstate(failbit);
	else
		c = ch;
	isfx();
	_CATCH_IO_END
	return (*this);
	}

// isputback -- istream::putback(char)
#include <istream>

istream& istream::putback(char c)
	{	// put back a char
	_Chcount = 0;
	_TRY_IO_BEGIN
	if (ipfx(1) && rdbuf()->sputbackc(c) == EOF)
		setstate(badbit);
	isfx();
	_CATCH_IO_END
	return (*this);
	}


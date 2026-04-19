// isunget -- istream::unget()
#include <istream>

istream& istream::unget()
	{	// put back last char
	_Chcount = 0;
	_TRY_IO_BEGIN
	if (ipfx(1) && rdbuf()->sungetc() == EOF)
		setstate(badbit);
	isfx();
	_CATCH_IO_END
	return (*this);
	}


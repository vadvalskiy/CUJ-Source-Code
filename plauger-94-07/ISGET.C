// isget -- istream::get()
#include <istream>

int istream::get()
	{	// get a character
	int ch;
	_TRY_IO_BEGIN
	if (!ipfx(1) || (ch = rdbuf()->sbumpc()) == EOF)
		setstate(failbit), _Chcount = 0, ch = EOF;
	else
		_Chcount = 1;
	isfx();
	_CATCH_IO_END
	return (ch);
	}


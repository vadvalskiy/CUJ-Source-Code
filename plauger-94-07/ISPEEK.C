// ispeek -- istream::peek()
#include <istream>

int istream::peek()
	{	// peek at next char
	_Chcount = 0;
	int ch;
	_TRY_IO_BEGIN
	ch = ipfx(1) ? rdbuf()->sgetc() : EOF;
	isfx();
	_CATCH_IO_END
	return (ch);
	}


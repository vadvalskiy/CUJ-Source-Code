// isignore -- istream::ignore(int, int)
#include <limits.h>
#include <istream>

istream& istream::ignore(int n, int delim)
	{	// discard through delimiter or count
	_Chcount = 0;
	_TRY_IO_BEGIN
	if (ipfx(1) && 0 < n)
		{	// extract and ignore arbitrary characters
		int ch;
		for (; ; )
			if (n != INT_MAX && --n <= 0)
				break;
			else if ((ch = rdbuf()->sbumpc()) == EOF)
				{	// record eof and quit
				setstate(eofbit);
				break;
				}
			else
				{	// count it and test for delim
				++_Chcount;
				if (ch == delim)
					break;
				}
		}
	isfx();
	_CATCH_IO_END
	return (*this);
	}


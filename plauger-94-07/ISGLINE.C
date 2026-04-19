// isgline -- istream::getline(char *, int, char)
#include <istream>

istream& istream::getline(char *s, int n, char delim)
	{	// get up through delimiter or count
	_Bool copied = 0;
	_Chcount = 0;
	_TRY_IO_BEGIN
	if (ipfx(1) && 0 < n)
		{	// extract arbitrary characters
		int ch;
		for (; ; )
			if (--n <= 0)
				{	// record count failure and quit
				setstate(failbit);
				break;
				}
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
				*s++ = ch, copied = 1;
				}
		}
	if (!copied)
		setstate(failbit);
	*s = '\0';
	isfx();
	_CATCH_IO_END
	return (*this);
	}


// isgstring -- istream::get(char *, int, char)
#include <istream>

istream& istream::get(char *s, int n, char delim)
	{	// get up to delimiter or count
	_Chcount = 0;
	_TRY_IO_BEGIN
	if (ipfx(1) && 0 < n)
		{	// extract arbitrary characters
		int ch;
		for (; 0 < --n; *s++ = ch, ++_Chcount)
			if ((ch = rdbuf()->sbumpc()) == EOF)
				{	// record eof and quit
				setstate(eofbit);
				break;
				}
			else if (ch == delim)
				{	// put back delimiter and quit
				rdbuf()->sputbackc(ch);
				break;
				}
		}
	if (_Chcount == 0)
		setstate(failbit);
	*s = '\0';
	isfx();
	_CATCH_IO_END
	return (*this);
	}


-------------------------- Listing 4: String extractor  ---------

// isxstring -- istream::operator>>(char *)
#include <ctype.h>
#include <limits.h>
#include <istream>

istream& istream::operator>>(char *sa)
	{	// extract an NTBS
	char *s = sa;
	_TRY_IO_BEGIN
	if (ipfx())
		{	// extract arbitrary characters
		int ch;
		int n = 0 < width() ? width() : INT_MAX;
		while (0 < --n && (ch = rdbuf()->sbumpc()) != EOF)
			if (isspace(ch))
				{	// put back white space and quit
				rdbuf()->sputbackc(ch);
				break;
				}
			else
				*s++ = ch;
		}
	if (s == sa)
		setstate(failbit);
	*s = '\0';
	width(0);
	isfx();
	_CATCH_IO_END
	return (*this);
	}

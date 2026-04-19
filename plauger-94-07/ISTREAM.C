// istream -- istream basic members
#include <ctype.h>
#include <istream>
#include <ostream>

istream::~istream()
	{	// destruct an istream -- DO NOTHING
	}

_Bool istream::ipfx(int noskip)
	{	// setup for input
	if (good())
		{	// no errors, flush and skip
		if (tie() != 0)
			tie()->flush();
		if (!noskip && flags() & skipws)
			{	// skip white space
			int ch;
			while (isspace(ch = rdbuf()->sbumpc()))
				;
			if (ch != EOF)
				rdbuf()->sputbackc(ch);
			}
		if (good())
			return (1);
		}
	setstate(failbit);
	return (0);
	}


// isgstream -- istream::get(streambuf&, char)
#include <istream>

istream& istream::get(streambuf&sb, char delim)
	{	// get into streambuf until delimiter
	_Chcount = 0;
	_TRY_IO_BEGIN
	if (ipfx(1))
		{	// copy characters until failure
		int ch;
		for (; (ch = rdbuf()->sbumpc()) != EOF; ++_Chcount)
			_TRY_BEGIN
				if (ch == delim || sb.sputc(ch) == EOF)
					break;
			_CATCH_ALL
				break;
			_CATCH_END
		if (ch != EOF)
			rdbuf()->sputbackc(ch);
		}
	if (_Chcount == 0)
		setstate(failbit);
	isfx();
	_CATCH_IO_END
	return (*this);
	}


-------------------------- Listing 5: streambuf extractor  ---------

// isxstream -- istream::operator>>(streambuf&)
#include <istream>

istream& istream::operator>>(streambuf& sb)
	{	// extract into streambuf
	_Bool copied = 0;
	_TRY_IO_BEGIN
	if (ipfx())
		{	// copy characters until failure
		char buf[512];
		int n;
		for (; 0 < (n = rdbuf()->sgetn(buf, sizeof (buf)));
			copied = 1)
			_TRY_BEGIN
				if (sb.sputn(buf, n) != n)
					break;
			_CATCH_ALL
				break;
			_CATCH_END
		}
	if (!copied)
		setstate(failbit);
	isfx();
	_CATCH_IO_END
	return (*this);
	}

---------------- Listing 6: The File streambu.c ---------------------------
// streambuf -- streambuf basic members
#include <string.h>
#include <streambuf>

streambuf::~streambuf()
	{	// destruct a streambuf
	}

int streambuf::overflow(int)
	{	// dummy overflow, always fail
	return (EOF);
	}

int streambuf::pbackfail(int)
	{	// dummy pbackfail, always fail
	return (EOF);
	}

int streambuf::underflow()
	{	// dummy underflow, always fail
	return (EOF);
	}

int streambuf::uflow()
	{	// consume and return a character
	return (gptr() != 0 && gptr() < egptr()
		? *_Gn()++
		: underflow() == EOF ? EOF : *_Gn()++);
	}

int streambuf::xsgetn(char *s, int n)
	{	// get up to n characters
	int ch;
	int m;
	int ns = 0;
	while (0 < n)
		if (gptr() != 0 && 0 < (m = egptr() - gptr()))
			{	// move as many as possible
			if (n < m)
				m = n;
			memcpy(s, gptr(), m);
			s += m, ns += m, n -= m, gbump(m);
			}
		else if ((ch = uflow()) == EOF)
			break;
		else
			*s++ = ch, ++ns, --n;
	return (ns);
	}

int streambuf::xsputn(const char *s, int n)
	{	// put n characters
	int m;
	int ns = 0;
	while (0 < n)
		if (pptr() != 0 && 0 < (m = epptr() - pptr()))
			{	// move as many as possible
			if (n < m)
				m = n;
			memcpy(pptr(), s, m);
			s += m, ns += m, n -= m, pbump(m);
			}
		else if (overflow(*(const unsigned char *)s) != EOF)
			++s, ++ns, --n;
	return (ns);
	}

streampos streambuf::seekoff(streamoff, ios::seekdir,
	ios::openmode)
	{	// dummy seekoff, always fail
	return (streampos(_BADOFF));
	}

streampos streambuf::seekpos(streampos, ios::openmode)
	{	// dummy seekpos, always fail
	return (streampos(_BADOFF));
	}

streambuf *streambuf::setbuf(char *, int)
	{	// dummy setbuf, do nothing
	return (this);
	}

int streambuf::sync()
	{	// dummy sync, always succeed
	return (0);
	}

void streambuf::_Init(char **gb, char **gn, char **ge,
	char **pb, char **pn, char **pe)
	{	// initialize a streambuf with indirect pointers
	_IGbeg = gb;
	_IGnext = gn;
	_IGend = ge;
	_IPbeg = pb;
	_IPnext = pn;
	_IPend = pe;
	}

void streambuf::_Init()
	{	// initialize a streambuf with default pointers
	_IGbeg = &_Gbeg;
	_IGnext = &_Gnext;
	_IGend = &_Gend;
	_IPbeg = &_Pbeg;
	_IPnext = &_Pnext;
	_IPend = &_Pend;
	setp(0, 0);
	setg(0, 0, 0);
	}


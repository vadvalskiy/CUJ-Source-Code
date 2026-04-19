--------------- Listing 7: member function _Getifld(char *) ---------

// isgetifl -- istream::_Getifld(char *)
#include <string.h>
#include <istream>

int istream::_Getifld(char ac[_MAX_INT_DIG])
	{	// extract an integer field
	char *p, seen;
	int base, ch, dlen;
	char *const pe = &ac[_MAX_INT_DIG-1];
	const ios::fmtflags bfl = flags() & basefield;
	static const char digits[] = "0123456789abcdefABCDEF";
	p = ac, ch = rdbuf()->sbumpc();
	if (ch == '+' || ch == '-')
		*p++ = ch, ch = rdbuf()->sbumpc();
	seen = 0;
	base = bfl == oct ? 8 : bfl == hex ? 16
		: bfl == _Fmtzero ? 0 : 10;
	if (ch == '0')
		{	// match possible prefix and strip it
		seen = 1;
		ch = rdbuf()->sbumpc();
		if ((ch == 'x' || ch == 'X')
			&& (base == 0 || base == 16))
			base = 16, ch = rdbuf()->sbumpc(), seen = 0;
		else if (base == 0)
			base = 8;
		}
	dlen = base == 0 || base == 10 ? 10 : base == 8 ? 8 : 16+6;
	for (; ch == '0'; seen = 1)
		ch = rdbuf()->sbumpc();
	if (seen)
		*p++ = '0';
	for (; ch != EOF && memchr(digits, ch, dlen);
		ch = rdbuf()->sbumpc(), seen = 1)
		if (p < pe)
			*p++ = ch;
	if (ch != EOF)
		rdbuf()->sputbackc(ch);
	if (!seen)
		p = ac;
	*p = '\0';
	return (base);
	}

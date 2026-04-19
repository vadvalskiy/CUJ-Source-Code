---------------- Listing 11: member function _Getffld(char *) ---------

// isgetffl -- istream::_Getffld(char *)
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <istream>
#include "xmath.h"

int istream::_Getffld(char ac[MAX_EXP_DIG+MAX_SIG_DIG+16])
	{	// extract a floating field
	char *p, seen;
	int ch, nsig;
	int pten;
	p = ac, ch = rdbuf()->sbumpc();
	pten = 0;
	if (ch == '+' || ch == '-')
		*p++ = ch, ch = rdbuf()->sbumpc();
	for (seen = 0; ch == '0'; ch = rdbuf()->sbumpc(), seen = 1)
		;	// strip leading zeros
	if (seen)
		*p++ = '0';	// put one back
	for (nsig = 0; isdigit(ch); ch = rdbuf()->sbumpc(), seen = 1)
		if (nsig < MAX_SIG_DIG)
			*p++ = ch, ++nsig;
		else
			++pten;
	if (ch == localeconv()->decimal_point[0])
		*p++ = ch, ch = rdbuf()->sbumpc();
	if (nsig == 0)
		{	// strip zeros after point
		for (; ch == '0'; ch = rdbuf()->sbumpc(), seen = 1)
			--pten;
		if (pten < 0)
			*p++ = '0', ++pten;	// put one back
		}
	for (; isdigit(ch); ch = rdbuf()->sbumpc(), seen = 1)
		if (nsig < MAX_SIG_DIG)
			*p++ = ch, ++nsig;
	if (seen && (ch == 'e' || ch == 'E'))
		{	// parse exponent
		*p++ = ch, ch = rdbuf()->sbumpc();
		if (ch == '+' || ch == '-')
			*p++ = ch, ch = rdbuf()->sbumpc();
		for (seen = 0; ch == '0'; ch = rdbuf()->sbumpc(), seen = 1)
			;	// strip leading exponent zeros
		if (seen)
			*p++ = '0';	// put one back
		for (nsig = 0; isdigit(ch); ch = rdbuf()->sbumpc(), seen = 1)
			if (nsig < MAX_EXP_DIG)
				*p++ = ch, ++nsig;
		}
	if (ch != EOF)
		rdbuf()->sputbackc(ch);
	if (!seen)
		p = ac;
	*p = '\0';
	return (pten);
	}

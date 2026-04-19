-------------------------- Listing 3:  The manipulator ws ---------

// ws -- ws(istream&)
#include <istream>

istream& ws(istream& is)
	{	// eat white space
	ios::fmtflags flagsav = is.flags();
	is.unsetf(ios::skipws);
	_TRY_IO_BEGIN
	is.ipfx();
	is.isfx();
	_CATCH_IO_END
	is.flags(flagsav);
	return (is);
	}

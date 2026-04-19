-------------- Listing 2: The streampos constructor  -------------------

// spos -- streampos constructor
#include <streambuf>

static const _Fpost fpzero = {0};

streampos::streampos(streamoff off, const _Fpost *fp)
	: _Pos(off), _Fp(fp != 0 ? *fp : fpzero)
	{	// construct a streampos
	}



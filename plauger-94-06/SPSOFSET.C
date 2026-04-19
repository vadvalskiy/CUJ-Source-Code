--------------- Listing 3: The function streampos::offset ---------------

// sposoffset -- streampos::offset()
#include <streambuf>

streamoff streampos::offset() const
	{	// get offset
	return (_Fp._Off == _BADOFF ? _BADOFF : _Pos + _Fp._Off);
	}



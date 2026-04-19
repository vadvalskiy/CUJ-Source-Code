---------------- Listing 4: The function streampos::operator- -----------

// sposminus -- streampos::operator-(const streampos&)
#include <streambuf>

streamoff streampos::operator-(const streampos& rop) const
	{	// subtract one streampos from another
	return (_Fp._Off == _BADOFF || rop._Fp._Off == _BADOFF
		? _BADOFF : _Pos + _Fp._Off - rop._Pos - rop._Fp._Off);
	}



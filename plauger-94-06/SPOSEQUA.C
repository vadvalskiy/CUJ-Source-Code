-------------- Listing 5: The function streampos::operator== ------------

// sposequa -- streampos::operator==(const streampos&)
#include <streambuf>

_Bool streampos::operator==(const streampos& rop) const
	{	// compare for equality
	if (_Fp._Off == _BADOFF || rop._Fp._Off == _BADOFF)
		return (_Fp._Off == _BADOFF && rop._Fp._Off == _BADOFF
			? 1 : 0);
	else
		return (_Pos + _Fp._Off == rop._Pos + rop._Fp._Off
			&& _Fp._Wstate._Wchar == rop._Fp._Wstate._Wchar
			&& _Fp._Wstate._State == rop._Fp._Wstate._State);
	}



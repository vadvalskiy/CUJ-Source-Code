[Caption: Listing 5 -- Class <f>gslice<d>]

class gslice {
public:
	gslice()
		: _Start(0) {}
	gslice(size_t _S, const _Sizarray& _L,
		const _Sizarray& _D)
		: _Start(_S), _Len(_L), _Stride(_D) {}
	size_t start() const
		{return (_Start); }
	_Sizarray size() const
		{return (_Len); }
	_Sizarray stride() const
		{return (_Stride); }
	size_t _Nslice() const
		{return (_Len.size()); }
	size_t _Off(_Sizarray& _Idx) const
		{size_t _I, _K = _Start;
		for (_I = 0; _I < _Idx.size(); ++_I)
			_K += _Idx[_I] * _Stride[_I];
		while (0 < _I--)
			if (++_Idx[_I] < _Len[_I])
				break;
			else
				_Idx[_I] = 0;
		return (_K); }
	size_t _Totlen() const
		{if (_Len.size() == 0)
			return (0);
		size_t _L = _Len[0];
		for (size_t _I = 0; ++_I < _Len.size(); )
			_L *= _Len[_I];
		return (_L); }
private:
	size_t _Start;
	_Sizarray _Len;
	_Sizarray _Stride;
	};

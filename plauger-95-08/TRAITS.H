------------- Listing 1: The struct string_char_traits<char> ---------

template<class _E>
	struct string_char_traits;
struct string_char_traits<char> {
	typedef char _E;
	typedef _E char_type;
	static void assign(_E& _X, const _E& _Y)
		{_X = _Y; }
	static bool eq(const _E& _X, const _E& _Y)
		{return (_X == _Y); }
	static bool ne(const _E& _X, const _E& _Y)
		{return (!eq(_X, _Y)); }
	static bool lt(const _E& _X, const _E& _Y)
		{return (_X < _Y); }
	static _E eos()
		{return ('\0'); }
	static basic_istream<_E, ios_traits<_E> >&
		char_in(basic_istream<_E, ios_traits<_E> >& _I, _E& _X)
		{_I.get(_X);
		return (_I); }
	static basic_ostream<_E, ios_traits<_E> >&
		char_out(basic_ostream<_E, ios_traits<_E> >& _O, _E _X)
		{_O.put(_X);
		return (_O); }
	static bool is_del(_E _X)
		{return (isspace((int)_X)); }
	static int compare(const _E *_U, const _E *_V, size_t _N)
		{return (memcmp(_U, _V, _N)); }
	static size_t length(const _E *_U)
		{return (strlen(_U)); }
	static _E *copy(_E *_U, const _E *_V, size_t _N)
		{return ((_E *)memcpy(_U, _V, _N)); }
	};


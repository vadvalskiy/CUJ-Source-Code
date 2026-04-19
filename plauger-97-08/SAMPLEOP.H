[Caption: Listing 2 -- Sample <f>valarray<d> operators]

		// operator* AND FRIENDS
template<class Ty> inline
	valarray<Ty>& operator*=(valarray<Ty>& L, const Ty& R)
	{VALGOP2(*= R); }
template<class Ty> inline
	valarray<Ty>& operator*=(valarray<Ty>& L,
		const valarray<Ty>& R)
	{VALGOP2(*= R[I]); }
template<class Ty> inline
	valarray<Ty> operator*(const valarray<Ty>& L,
		const Ty& R)
	{VALOP(Ty, L.size(), L[I] * R); }
template<class Ty> inline
	valarray<Ty> operator*(const Ty& L,
		const valarray<Ty>& R)
	{VALOP(Ty, R.size(), L * R[I]); }
template<class Ty> inline
	valarray<Ty> operator*(const valarray<Ty>& L,
		const valarray<Ty>& R)
	{VALOP(Ty, L.size(), L[I] * R[I]); }
// etc.

		// SAMPLE MATH FUNCTION OVERLOAD
template<class _Ty> inline
	valarray<_Ty> acos(const valarray<_Ty>& _X)
	{_VALOP(_Ty, _X.size(), _CSTD acos(_X[_I])); }
// etc.

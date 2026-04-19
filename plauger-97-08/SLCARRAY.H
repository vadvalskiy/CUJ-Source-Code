[Caption: Listing 4 -- Template class <f>slice_array<d>]


		// MACROS
#define SLOP(RHS) \
	size_t N = Start; \
	for (size_t I = 0; I < Len; ++I, N += Stride) \
		Ptr[N] RHS;
#define SLOP2(RHS) \
	size_t N = L.start(); \
	for (size_t I = 0; I < L.size(); \
		++I, N += L.stride()) \
		L.Data(N) RHS;

		// TEMPLATE CLASS slice_array
template<class Ty>
	class slice_array : public slice {
public:
	typedef Ty value_type;
	void operator=(const valarray<Ty>& R) const
		{SLOP(= R[I]); }
	void operator=(const Ty& R)
		{SLOP(= R); }
	Ty& Data(size_t I) const
		{return (Ptr[I]); }
private:
	friend class valarray<Ty>;
	slice_array(const slice& Sl, Ty *Pd)
		: slice(Sl), Ptr(Pd) {}
	Ty *Ptr;
	};

		// slice_array MEMBER TEMPLATE OPERATORS
template<class Ty> inline
	void operator*=(const slice_array<Ty>& L,
		const valarray<Ty>& R)
	{SLOP2(*= R[I]); }
// etc.

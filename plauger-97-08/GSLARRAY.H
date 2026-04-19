[Caption: Listing 6 -- Template class <f>gslice_array<d>]



		// MACROS
#define GSLOP(RHS) \
	Sizarray Idx((size_t)0, Nslice()); \
	size_t N = Totlen(); \
	for (size_t I = 0; I < N; ++I) \
		Ptr[Off(Idx)] RHS;
#define GSLOP2(RHS) \
	Sizarray Idx((size_t)0, L.Nslice()); \
	size_t N = L.Totlen(); \
	for (size_t I = 0; I < N; ++I) \
		L.Data(L.Off(Idx)) RHS;

		// TEMPLATE CLASS gslice_array
template<class Ty>
	class gslice_array : public gslice {
public:
	typedef Ty value_type;
	void operator=(const valarray<Ty>& R) const
		{GSLOP(= R[I]); }
	void operator=(const Ty& R)
		{GSLOP(= R); }
	Ty& Data(size_t I) const
		{return (Ptr[I]); }
private:
	friend class valarray<Ty>;
	gslice_array(const gslice& Gs, Ty *Pd)
		: gslice(Gs), Ptr(Pd) {}
	Ty *Ptr;
	};

		// gslice_array MEMBER TEMPLATE OPERATORS
template<class Ty> inline
	void operator*=(const gslice_array<Ty>& L,
		const valarray<Ty>& R)
	{GSLOP2(*= R[I]); }
// etc.

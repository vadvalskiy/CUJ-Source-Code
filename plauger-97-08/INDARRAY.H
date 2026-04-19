[Caption: Listing 8 -- Template class <f>indirect_array<d>]


		// MACROS
#define IOP(RHS) \
	size_t L = Totlen(); \
	for (size_t I = 0; I < L; ++I) \
		Ptr[Indir(I)] RHS;
#define IOP2(RHS) \
	size_t N = L.Totlen(); \
	for (size_t I = 0; I < N; ++I) \
		L.Data(L.Indir(I)) RHS;

		// TEMPLATE CLASS indirect_array
template<class Ty>
	class indirect_array {
public:
	typedef Ty value_type;
	void operator=(const valarray<Ty>& R) const
		{IOP(= R[I]); }
	void operator=(const Ty& R)
		{IOP(= R); }
	Ty& Data(size_t I) const
		{return (Ptr[I]); }
	size_t Indir(size_t I) const
		{return (Iarr[I]); }
	size_t Totlen() const
		{return (Iarr.size()); }
private:
	friend class valarray<Ty>;
	indirect_array(const Sizarray& Ia, Ty *Pd)
		: Iarr(Ia), Ptr(Pd) {}
	Sizarray Iarr;
	Ty *Ptr;
	};

		// indirect_array MEMBER TEMPLATE OPERATORS
template<class Ty> inline
	void operator*=(const indirect_array<Ty>& L,
		const valarray<Ty>& R)
	{IOP2(*= R[I]); }
// etc.

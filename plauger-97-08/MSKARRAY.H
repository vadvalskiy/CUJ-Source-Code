[Caption: Listing 7 -- Template class <f>mask_array<d>]


		// MACROS
#define MOP(RHS) \
	size_t N = 0; \
	size_t M = Totlen(); \
	for (size_t I = 0; I < M; ++N) \
		if (Mask(N)) \
			Ptr[N] RHS, ++I;
#define MOP2(RHS) \
	size_t N = 0; \
	size_t M = L.Totlen(); \
	for (size_t I = 0; I < M; ++N) \
		if (L.Mask(N)) \
			L.Data(N) RHS, ++I;

		// TEMPLATE CLASS mask_array
template<class Ty>
	class mask_array {
public:
	typedef Ty value_type;
	void operator=(const valarray<Ty>& R)
		{MOP(= R[I]); }
	void operator=(const Ty& R)
		{MOP(= R); }
	Ty& Data(size_t I) const
		{return (Ptr[I]); }
	bool Mask(size_t I) const
		{return (Marr[I]); }
	size_t Totlen() const
		{size_t N = 0;
		for (size_t I = 0; I < Marr.size(); ++I)
			if (Marr[I])
				++N;
		return (N); }
private:
	friend class valarray<Ty>;
	mask_array(const Boolarray& Ma, Ty *Pd)
		: Marr(Ma), Ptr(Pd) {}
	Boolarray Marr;
	Ty *Ptr;
	};

		// mask_array MEMBER TEMPLATE OPERATORS
template<class Ty> inline
	void operator*=(const mask_array<Ty>& L,
		const valarray<Ty>& R)
	{MOP2(*= R[I]); }
// etc.

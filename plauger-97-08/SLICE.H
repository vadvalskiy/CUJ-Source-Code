[Caption: Listing 3 -- Class <f>slice<d>]


		// CLASS slice
class slice {
public:
	slice()
		: Start(0), Len(0), Stride(0) {}
	slice(size_t S, size_t L, size_t D)
		: Start(S), Len(L), Stride(D) {}
	size_t start() const
		{return (Start); }
	size_t size() const
		{return (Len); }
	size_t stride() const
		{return (Stride); }
protected:
	size_t Start, Len, Stride;
	};

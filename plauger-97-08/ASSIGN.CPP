[Caption: Listing 9 -- Assignment and Subscripting]


		// slice_array TEMPLATE FUNCTIONS
template<class Ty> inline
	valarray<Ty>& valarray<Ty>::operator=(
		const slice_array<Ty>& Sl)
	{Grow(Sl.size(), &Sl.Data(Sl.start()),
		Sl.stride(), true);
	return (*this); }
template<class Ty> inline
	valarray<Ty> valarray<Ty>::operator[](slice Sl) const
	{return (valarray<Ty>(slice_array<Ty>(Sl, Ptr))); }
template<class Ty> inline
	slice_array<Ty> valarray<Ty>::operator[](slice Sl)
	{return (slice_array<Ty>(Sl, Ptr)); }

		// gslice_array TEMPLATE FUNCTIONS
template<class Ty> inline
	valarray<Ty>& valarray<Ty>::operator=(
		const gslice_array<Ty>& Gs)
	{Grow(Gs.Totlen(), 0, 0, true);
	Sizarray Idx((size_t)0, Gs.Nslice());
	VALGOP(= Gs.Data(Gs.Off(Idx))); }
template<class Ty> inline
	valarray<Ty> valarray<Ty>::operator[](
		const gslice& Gs) const
	{return (valarray<Ty>(gslice_array<Ty>(Gs, Ptr))); }
template<class Ty> inline
	gslice_array<Ty> valarray<Ty>::operator[](
		const gslice& Gs)
	{return (gslice_array<Ty>(Gs, Ptr)); }

		// mask_array TEMPLATE FUNCTIONS
template<class Ty> inline
	valarray<Ty>& valarray<Ty>::operator=(
		const mask_array<Ty>& Ma)
	{Grow(Ma.Totlen(), 0, 0, true);
	size_t N = 0;
	for (size_t I = 0; I < size(); ++N)
		if (Ma.Mask(N))
			Ptr[I++] = Ma.Data(N);
	return (*this); }
template<class Ty> inline
	valarray<Ty> valarray<Ty>::operator[](
		const Boolarray& Ba) const
	{return (valarray<Ty>(mask_array<Ty>(Ba, Ptr))); }
template<class Ty> inline
	mask_array<Ty> valarray<Ty>::operator[](
		const Boolarray& Ba)
	{return (mask_array<Ty>(Ba, Ptr)); }

		// indirect_array TEMPLATE FUNCTIONS
template<class Ty> inline
	valarray<Ty>& valarray<Ty>::operator=(
		const indirect_array<Ty>& Ia)
	{Grow(Ia.Totlen(), 0, 0, true);
	VALGOP(= Ia.Data(Ia.Indir(I))); }
template<class Ty> inline
	valarray<Ty> valarray<Ty>::operator[](
		const Sizarray& Ia) const
	{return (valarray<Ty>(indirect_array<Ty>(Ia, Ptr))); }
template<class Ty> inline
	indirect_array<Ty> valarray<Ty>::operator[](
		const Sizarray& Ia)
	{return (indirect_array<Ty>(Ia, Ptr)); }

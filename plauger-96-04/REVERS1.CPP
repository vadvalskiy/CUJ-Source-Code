--------------- Listing 2: Template Function <f>reverse<d> -------------

template<class BidIt> inline
	void reverse(BidIt first, BidIt last)
	{_Reverse(first, last, first); }
template<class BidIt> inline
	void _Reverse(BidIt first, BidIt last,
		bidirectional_iterator)
	{for (; first != last && first != --last; ++first)
		iter_swap(first, last); }
template<class RanIt> inline
	void reverse(RanIt first, RanIt last,
		random_access_iterator)
	{for (; first < last; ++first)
		iter_swap(first, --last); }

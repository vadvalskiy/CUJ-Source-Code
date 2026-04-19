------- Listing 4: Improved Template Function <f>reverse<d> -------------

template<class BidIt> inline
	void reverse(BidIt first, BidIt last)
	{_Reverse(first, last, iterator_category(first)); }
template<class BidIt> inline
	void _Reverse(BidIt first, BidIt last,
		bidirectional_iterator_tag)
	{for (; first != last && first != --last; ++first)
		iter_swap(first, last); }
template<class RanIt> inline
	void _Reverse(RanIt first, RanIt last,
		random_access_iterator_tag)
	{for (; first < last; ++first)
		iter_swap(first, --last); }

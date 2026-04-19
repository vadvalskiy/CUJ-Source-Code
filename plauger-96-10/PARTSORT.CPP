-------------- Listing 4: Partial Sorting Template Functions ------------

		// TEMPLATE FUNCTION partial_sort
template<class RanIt> inline
	void partial_sort(RanIt first, RanIt m, RanIt last)
	{_Partial_sort(first, m, last, _Val_type(first)); }
template<class RanIt, class T> inline
	void _Partial_sort(RanIt first, RanIt m, RanIt last, T *)
	{make_heap(first, m);
	for (RanIt i = m; i < last; ++i)
		if (*i < *first)
			_Pop_heap(first, m, i, T(*i), _Dist_type(first));
	sort_heap(first, m); }

		// TEMPLATE FUNCTION partial_sort_copy
template<class InIt, class RanIt> inline
	RanIt partial_sort_copy(InIt first1, InIt last1,
		RanIt first2, RanIt last2)
	{return (_Partial_sort_copy(first1, last1, first2, last2,
		_Dist_type(first2), _Val_type(first1))); }
template<class InIt, class RanIt, class Diff, class T> inline
	RanIt _Partial_sort_copy(InIt first1, InIt last1,
		RanIt first2, RanIt last2,
		Diff *, T *)
	{RanIt x = first2;
	if (x != last2)
		{for (; first1 != last1 && x != last2; ++first1, ++x)
			*x = *first1;
		make_heap(first2, x);
		for (; first1 != last1; ++first1)
			if (*first1 < *first2)
				_Adjust_heap(first2, Diff(0), Diff(x - first2),
					T(*first1));
		sort_heap(first2, x); }
	return (x); }

		// TEMPLATE FUNCTION nth_element
template<class RanIt> inline
	void nth_element(RanIt first, RanIt nth, RanIt last)
	{_Nth_element(first, nth, last, _Val_type(first)); }
template<class RanIt, class T> inline
	void _Nth_element(RanIt first, RanIt nth, RanIt last, T *)
	{for (; _SORT_MAX < last - first; )
		{RanIt m = _Unguarded_partition(first, last,
			_Median(T(*first), T(*(first + (last - first) / 2)),
				T(*(last - 1))));
		if (m <= nth)
			first = m;
		else
			last = m; }
	_Insertion_sort(first, last); }

------------- end of Listing 4 ----------------------------

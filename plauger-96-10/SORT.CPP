r-------------- Listing 2: Template Function <f>sort<d> ------------

        // TEMPLATE FUNCTION sort
template<class RanIt> inline
    void sort(RanIt first, RanIt last)
    {_Sort_0(first, last, _Val_type(first)); }
template<class RanIt, class T> inline
    void _Sort_0(RanIt first, RanIt last, T *)
    {if (last - first <= _SORT_MAX)
        _Insertion_sort(first, last);
    else
        {_Sort(first, last, (T *)0);
        _Insertion_sort(first, first + _SORT_MAX);
        for (first += _SORT_MAX; first != last; ++first)
            _Unguarded_insert(first, T(*first)); }}
template<class RanIt, class T> inline
    void _Sort(RanIt first, RanIt last, T *)
    {for (; _SORT_MAX < last - first; )
        {RanIt m = _Unguarded_partition(first, last,
            _Median(T(*first), T(*(first + (last - first) / 2)),
                T(*(last - 1))));
        if (last - m <= m - first)
            _Sort(m, last, _Val_type(first)), last = m;
        else
            _Sort(first, m, _Val_type(first)), first = m; }}
template<class RanIt, class T> inline
    RanIt _Unguarded_partition(RanIt first, RanIt last, T priv)
    {for (; ; ++first)
        {for (; *first < priv; ++first)
            ;
        for (; priv < *--last; )
            ;
        if (last <= first)
            return (first);
        iter_swap(first, last); }}
template<class RanIt> inline
    void _Insertion_sort(RanIt first, RanIt last)
    {_Insertion_sort_1(first, last, _Val_type(first)); }
template<class BidIt, class T> inline
    void _Insertion_sort_1(BidIt first, BidIt last, T *)
    {if (first != last)
        for (BidIt m = first; ++m != last; )
            {T val = *m;
            if (!(val < *first))
                _Unguarded_insert(m, val);
            else
                {copy_backward(first, m, m + 1);
                *first = val; }}}
template<class BidIt, class T> inline
    void _Unguarded_insert(BidIt last, T val)
    {for (BidIt m = last; val < *--m; last = m)
        *last = *m;
    *last = val; }

------------- end of Listing 2 ----------------------------

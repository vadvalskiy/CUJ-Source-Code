-------------- Listing 5: Merging Template Functions ------------

        // TEMPLATE FUNCTION merge
template<class InIt1, class InIt2, class OutIt> inline
    OutIt merge(InIt1 first1, InIt1 last1,
        InIt2 first2, InIt2 last2, OutIt x)
    {for (; first1 != last1 && first2 != last2; ++x)
        if (*first2 < *first1)
            *x = *first2++;
        else
            *x = *first1++;
    x = copy(first1, last1, x);
    return (copy(first2, last2, x)); } 

        // TEMPLATE FUNCTION inplace_merge
template<class BidIt> inline
    void inplace_merge(BidIt first, BidIt mid, BidIt last)
    {if (first != last)
        _Inplace_merge(first, mid, last,
            _Dist_type(first), _Val_type(first)); }
template<class BidIt, class Diff, class T> inline
    void _Inplace_merge(BidIt first, BidIt mid, BidIt last,
        Diff *, T *)
    {Diff d1 = 0;
    _Distance(first, mid, d1);
    Diff d2 = 0;
    _Distance(mid, last, d2);
    _Temp_iterator<T> xb(d1 < d2 ? d1 : d2);
    _Buffered_merge(first, mid, last, d1, d2, xb); }
template<class BidIt, class Diff, class T> inline
    void _Buffered_merge(BidIt first, BidIt mid, BidIt last,
        Diff d1, Diff d2, _Temp_iterator<T>& xb)
    {if (d1 == 0 || d2 == 0)
        ;
    else if (d1 + d2 == 2)
        {if (*mid < *first)
            iter_swap(first, mid); }
    else if (d1 <= d2 && d1 <= xb.Maxlen())
        {copy(first, mid, xb.Init());
        merge(xb.First(), xb.Last(), mid, last, first); }
    else if (d2 <= xb.Maxlen())
        {copy(mid, last, xb.Init());
        _Merge_backward(first, mid, xb.First(), xb.Last(),
            last); }
    else
        {BidIt firstn, lastn;
        Diff d1n = 0, d2n = 0;
        if (d2 < d1)
            {d1n = d1 / 2;
            firstn = first;
            advance(firstn, d1n);
            lastn = lower_bound(mid, last, T(*firstn));
            _Distance(mid, lastn, d2n); }
        else
            {d2n = d2 / 2;
            lastn = mid;
            advance(lastn, d2n);
            firstn = upper_bound(first, mid, T(*lastn));
            _Distance(first, firstn, d1n); }
        BidIt midn = _Buffered_rotate(firstn, mid, lastn,
            d1 - d1n, d2n, xb);
        _Buffered_merge(first, firstn, midn, d1n, d2n, xb);
        _Buffered_merge(midn, lastn, last,
            d1 - d1n, d2 - d2n, xb); }}
template<class BidIt1, class BidIt2, class BidIt3> inline
    BidIt3 _Merge_backward(BidIt1 first1, BidIt1 last1,
        BidIt2 first2, BidIt2 last2, BidIt3 x)
    {for (; ; )
        if (first1 == last1)
            return (copy_backward(first2, last2, x));
        else if (first2 == last2)
            return (copy_backward(first1, last1, x));
        else if (*--last2 < *--last1)
            *--x = *last1, ++last2;
        else
            *--x = *last2, ++last1; }
template<class BidIt, class Diff, class T> inline
    BidIt _Buffered_rotate(BidIt first, BidIt mid, BidIt last,
        Diff d1, Diff d2, _Temp_iterator<T>& xb)
    {if (d1 <= d2 && d1 <= xb.Maxlen())
        {copy(first, mid, xb.Init());
        copy(mid, last, first);
        return (copy_backward(xb.First(), xb.Last(), last)); }
    else if (d2 <= xb.Maxlen())
        {copy(mid, last, xb.Init());
        copy_backward(first, mid, last);
        return (copy(xb.First(), xb.Last(), first)); }
    else
        {rotate(first, mid, last);
        advance(first, d2);
        return (first); }}

------------- end of Listing 5 ----------------------------





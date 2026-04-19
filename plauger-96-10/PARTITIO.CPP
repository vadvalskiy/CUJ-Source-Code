-------------- Listing 1: Partitioning Template Functions ------------

        // TEMPLATE FUNCTION partition
template<class BidIt, class Pred> inline
    BidIt partition(BidIt first, BidIt last, Pred pr)
    {for (; ; ++first)
        {for (; first != last && pr(*first); ++first)
            ;
        if (first == last)
            break;
        for (; first != --last && !pr(*last); )
            ;
        if (first == last)
            break;
        iter_swap(first, last); }
    return (first); }

        // TEMPLATE FUNCTION stable_partition
template<class FwdIt, class Pred> inline
    FwdIt stable_partition(FwdIt first, FwdIt last, Pred pr)
    {return (first == last ? first :
        _Stable_partition(first, last, pr,
            _Dist_type(first), _Val_type(first))); }
template<class FwdIt, class Pred, class Diff, class T> inline
    FwdIt _Stable_partition(FwdIt first, FwdIt last, Pred pr,
        Diff *, T *)
    {Diff n = 0;
    _Distance(first, last, n);
    _Temp_iterator<T> xb(n);
    return (_Stable_partition(first, last, pr, n, xb)); }
template<class FwdIt, class Pred, class Diff, class T> inline
    FwdIt _Stable_partition(FwdIt first, FwdIt last, Pred pr,
        Diff n, _Temp_iterator<T>& xb)
    {if (n == 1)
        return (pr(*first) ? last : first);
    else if (n <= xb.Maxlen())
        {FwdIt x = first;
        for (xb.Init(); first != last; ++first)
            if (pr(*first))
                *x++ = *first;
            else
                *xb++ = *first;
        copy(xb.First(), xb.Last(), x);
        return (x); }
    else
        {FwdIt m = first;
        advance(m, n / 2);
        FwdIt lastp = _Stable_partition(first, m, pr, n / 2, xb);
        FwdIt rp = _Stable_partition(m, last, pr, n - n / 2, xb);
        Diff d1 = 0;
        _Distance(lastp, m, d1);
        Diff d2 = 0;
        _Distance(m, rp, d2);
        return (_Buffered_rotate(lastp, m, rp, d1, d2, xb)); }}

------------- end of Listing 1 ----------------------------

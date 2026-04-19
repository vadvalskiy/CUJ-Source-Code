-------------- Listing 1: Binary Search Template Functions ------------

        // TEMPLATE FUNCTION lower_bound
template<class FwdIt, class T> inline
    FwdIt lower_bound(FwdIt first, FwdIt last, const T& val)
    {return (_Lower_bound(first, last, val,
        _Dist_type(first))); }
template<class FwdIt, class T, class Diff> inline
    FwdIt _Lower_bound(FwdIt first, FwdIt last, const T& val,
        Diff *)
    {Diff n = 0;
    _Distance(first, last, n);
    for (; 0 < n; )
        {Diff n2 = n / 2;
        FwdIt m = first;
        advance(m, n2);
        if (*m < val)
            first = ++m, n -= n2 + 1;
        else
            n = n2; }
    return (first); } 

        // TEMPLATE FUNCTION upper_bound
template<class FwdIt, class T> inline
    FwdIt upper_bound(FwdIt first, FwdIt last, const T& val)
    {return (_Upper_bound(first, last, val,
        _Dist_type(first))); }
template<class FwdIt, class T, class Diff> inline
    FwdIt _Upper_bound(FwdIt first, FwdIt last,
        const T& val, Diff *)
    {Diff n = 0;
    _Distance(first, last, n);
    for (; 0 < n; )
        {Diff n2 = n / 2;
        FwdIt m = first;
        advance(m, n2);
        if (!(val < *m))
            first = ++m, n -= n2 + 1;
        else
            n = n2; }
    return (first); } 

        // TEMPLATE FUNCTION equal_range
template<class FwdIt, class T> inline
    pair<FwdIt, FwdIt> equal_range(FwdIt first, FwdIt last,
        const T& val)
    {return (_Equal_range(first, last, val,
        _Dist_type(first))); }
template<class FwdIt, class T, class Diff> inline
    pair<FwdIt, FwdIt> _Equal_range(FwdIt first, FwdIt last,
        const T& val, Diff *)
    {Diff n = 0;
    _Distance(first, last, n);
    for (; 0 < n; )
        {Diff n2 = n / 2;
        FwdIt m = first;
        advance(m, n2);
        if (*m < val)
            first = +mm, n -= n2 + 1;
        else if (val < *m)
            n = n2;
        else
            {FwdIt first2 = lower_bound(first, m, val);
            advance(first, n);
            FwdIt last2 = upper_bound(++m, first, val);
            return (pair<FwdIt, FwdIt>(first2, last2)); }} 
    return (pair<FwdIt, FwdIt>(first, first)); } 

        // TEMPLATE FUNCTION binary_search
template<class FwdIt, class T> inline
    bool binary_search(FwdIt first, FwdIt last, const T& val)
    {FwdIt i = lower_bound(first, last, val);
    return (i != last && !(val < *i)); }

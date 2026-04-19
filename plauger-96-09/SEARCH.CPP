-------------- Listing 4: Searching Template Functions ------------

// TEMPLATE FUNCTION find
template<class InIt, class T> inline
    InIt find(InIt first, InIt last, const T& val)
    {for (; first != last; ++first)
        if (*first == val)
            break;
    return (first); }

// TEMPLATE FUNCTION adjacent_find
template<class FwdIt> inline
    FwdIt adjacent_find(FwdIt first, FwdIt last)
    {for (FwdIt firstb; (firstb = first) != last
        && ++first != last; )
        if (*firstb == *first)
            return (firstb);
    return (last); }

// TEMPLATE FUNCTION count
template<class InIt, class T> inline
/// iterator_traits<InIt>::distance_type
///        count(InIt first, InIt last, const T& val)
///    {iterator_traits<InIt>::distance_type n = 0;
    size_t count(InIt first, InIt last, const T& val) ///
    {size_t n = 0;    ///
    for (; first != last; ++first)
        if (*first == val)
            ++n;
    return (n); }

// TEMPLATE FUNCTION search
template<class FwdIt1, class FwdIt2> inline
    FwdIt1 search(FwdIt1 first1, FwdIt1 last1,
        FwdIt2 first2, FwdIt2 last2)
    {return (_Search(first1, last1, first2, last2,
        _Dist_type(first1), _Dist_type(first2))); }
template<class FwdIt1, class FwdIt2,
    class Diff1, class Diff2> inline
    FwdIt1 _Search(FwdIt1 first1, FwdIt1 last1,
        FwdIt2 first2, FwdIt2 last2, Diff1 *, Diff2 *)
    {Diff1 d1 = 0;
    _Distance(first1, last1, d1);
    Diff2 d2 = 0;
    _Distance(first2, last2, d2);
    for (; d2 <= d1; ++first1, --d1)
        {FwdIt1 x1 = first1;
        for (FwdIt2 x2 = first2; ; ++x1, ++x2)
            if (x2 == last2)
                return (first1);
            else if (!(*x1 == *x2))
                break; }
    return (last1); }

// TEMPLATE FUNCTION search_n
template<class FwdIt1, class Diff2, class T> inline
    FwdIt1 search_n(FwdIt1 first1, FwdIt1 last1, Diff2 n,
        const T& val)
    {return (_Search_n(first1, last1, n,
        val, _Dist_type(first1))); }
template<class FwdIt1, class Diff2, class T, class Diff1> inline
    FwdIt1 _Search_n(FwdIt1 first1, FwdIt1 last1,
        Diff2 n, const T& val, Diff1 *)
    {Diff1 d1 = 0;
    _Distance(first1, last1, d1);
    for (; n <= d1; ++first1, --d1)
        {FwdIt1 x1 = first1;
        for (Diff2 d2 = n; ; ++x1, --d2)
            if (d2 == 0)
                return (first1);
            else if (!(*x1 == val))
                break; }
    return (last1); }

// TEMPLATE FUNCTION find_end
template<class FwdIt1, class FwdIt2> inline
    FwdIt1 find_end(FwdIt1 first1, FwdIt1 last1,
        FwdIt2 first2, FwdIt2 last2)
    {return (_Find_end(first1, last1, first2, last2,
        _Dist_type(first1), _Dist_type(first2))); }
template<class FwdIt1, class FwdIt2,
    class Diff1, class Diff2> inline
    FwdIt1 _Find_end(FwdIt1 first1, FwdIt1 last1,
        FwdIt2 first2, FwdIt2 last2, Diff1 *, Diff2 *)
    {Diff1 d1 = 0;
    _Distance(first1, last1, d1);
    Diff2 d2 = 0;
    _Distance(first2, last2, d2);
    FwdIt1 ans = last1;
    if (0 < d2)
        for (; d2 <= d1; ++first1, --d1)
            {FwdIt1 x1 = first1;
            for (FwdIt2 x2 = first2; ; ++x1)
                if (!(*x1 == *x2))
                    break;
                else if (++x2 == last2)
                    {ans = first1;
                    break; }}
    return (ans); }

// TEMPLATE FUNCTION find_first_of
template<class FwdIt1, class FwdIt2> inline
    FwdIt1 find_first_of(FwdIt1 first1, FwdIt1 last1,
        FwdIt2 first2, FwdIt2 last2)
    {for (; first1 != last1; ++first1)
        for (FwdIt2 x2 = first2; x2 != last2; ++x2)
            if (*first1 == *x2)
                return (first1);
    return (first1); }

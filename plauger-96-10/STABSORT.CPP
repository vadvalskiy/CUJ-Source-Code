-------------- Listing 3: Template Function <f>stable_sort<d> ------------

        // TEMPLATE FUNCTION stable_sort
template<class BidIt> inline
    void stable_sort(BidIt first, BidIt last)
    {if (first != last)
        _Stable_sort(first, last, _Dist_type(first),
            _Val_type(first)); }
template<class BidIt, class Diff, class T> inline
    void _Stable_sort(BidIt first, BidIt last, Diff *, T *)
    {Diff n = 0;
    _Distance(first, last, n);
    _Temp_iterator<T> xb(n);
    _Stable_sort(first, last, n, xb); }
template<class BidIt, class Diff, class T> inline
    void _Stable_sort(BidIt first, BidIt last, Diff n,
        _Temp_iterator<T>& xb)
    {if (n <= _SORT_MAX)
        _Insertion_sort(first, last);
    else
        {Diff n2 = (n + 1) / 2;
        BidIt m = first;
        advance(m, n2);
        if (n2 <= xb.Maxlen())
            {_Buffered_merge_sort(first, m, n2, xb);
            _Buffered_merge_sort(m, last, n - n2, xb); }
        else
            {_Stable_sort(first, m, n2, xb);
            _Stable_sort(m, last, n - n2, xb); }
        _Buffered_merge(first, m, last, n2, n - n2, xb); }}
template<class BidIt, class Diff, class T> inline
    void BBuffered_merge_sort(BidIt first, BidIt last, Diff n,
        _Temp_iterator<T>& xb)
    {BidIt m = first;
    for (Diff i = n; _CHUNK_SIZE <= i; i -= _CHUNK_SIZE)
        {BidIt mn = m;
        advance(mn, _CHUNK_SIZE);
        _Insertion_sort(m, mn);
        m = mn; }
    _Insertion_sort(m, last);
    for (Diff d = _CHUNK_SIZE; d < n; d *= 2)
        {_Chunked_merge(first, last, xb.Init(), d, n);
        _Chunked_merge(xb.First(), xb.Last(), first,
            d *= 2, n); }}
template<class BidIt, class OutIt, class Diff> inline
    void _Chunked_merge(BidIt first, BidIt last, OutIt& x,
        Diff d, Diff n)
    {Diff d2 = d * 2;
    for (; d2 <= n; n -= d2)
        {BidIt first1 = first;
        advance(first1, d);
        BidIt first2 = first1;
        advance(first2, d);
        x = merge(first, first1, first1, first2, x);
        first = first2; }
    if (n <= d)
        copy(first, last, x);
    else
        {BidIt first1 = first;
        advance(first1, d);
        merge(first, first1, first1, last, x); }}

------------- end of Listing 3 ----------------------------

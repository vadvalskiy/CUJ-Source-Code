-------------- Listing 4: Permutation Template Functions ------------

        // TEMPLATE FUNCTION next_permutation
template<class BidIt> inline
    bool next_permutation(BidIt first, BidIt last)
    {BidIt i = last;
    if (first == last || first == --i)
        return (false);
    for (; ; )
        {BidIt ip = i;
        if (*--i < *ip)
            {BidIt j = last;
            for (; !(*i < *--j); )
                ;
            iter_swap(i, j);
            reverse(ip, last);
            return (true); }
        if (i == first)
            {reverse(first, last);
            return (false); }}}

        // TEMPLATE FUNCTION prev_permutation
template<class BidIt> inline
    bool prev_permutation(BidIt first, BidIt last)
    {BidIt i = last;
    if (first == last || first == --i)
        return (false);
    for (; ; )
        {BidIt ip = i;
        if (!(*--i < *ip))
            {BidIt j = last;
            for (; *i < *--j; )
                ;
            iter_swap(i, j);
            reverse(ip, last);
            return (true); }
        if (i == first)
            {reverse(first, last);
            return (false); }}}

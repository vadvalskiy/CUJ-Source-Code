-------------- Listing 7: Rearranging Template Functions ------------

// TEMPLATE FUNCTION reverse
template<class BidIt> inline
    void reverse(BidIt first, BidIt last)
    {_Reverse(first, last, _Iter_cat(first)); }
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

// TEMPLATE FUNCTION reverse_copy
template<class BidIt, class OutIt> inline
    OutIt reverse_copy(BidIt first, BidIt last, OutIt x)
    {for (; first != last; ++x)
        *x = *--last;
    return (x); }

// TEMPLATE FUNCTION rotate
template<class FwdIt> inline
    void rotate(FwdIt first, FwdIt mid, FwdIt last)
    {if (first != mid && mid != last)
        _Rotate(first, mid, last, _Iter_cat(first)); }
template<class FwdIt> inline
    void _Rotate(FwdIt first, FwdIt mid, FwdIt last,
        forward_iterator_tag)
    {for (FwdIt x = mid; ; )
        {iter_swap(first, x);
        if (++first == mid)
            if (++x == last)
                break;
            else
                mid = x;
        else if (++x == last)
            x = mid; }}
template<class BidIt> inline
    void _Rotate(BidIt first, BidIt mid, BidIt last,
        bidirectional_iterator_tag)
    {reverse(first, mid);
    reverse(mid, last);
    reverse(first, last); }
template<class RanIt> inline
    void _Rotate(RanIt first, RanIt mid, RanIt last,
            random_access_iterator_tag)
    {_Rotate(first, mid, last, _Dist_type(first),
        _Val_type(first)); }
template<class RanIt, class Diff, class T> inline
    void _Rotate(RanIt first, RanIt mid, RanIt last, Diff *, T *)
    {Diff d = mid - first;
    Diff n = last - first;
    for (Diff i = d; i != 0; )
        {Diff j = n % i;
        n = i, i = j; }
    if (n < last - first)
        for (; 0 < n; --n)
            {RanIt x = first + n;
            RanIt y = x;
            T val = *x;
            RanIt z = y + d == last ? first : y + d;
            while (z != x)
                {*y = *z;
                y = z;
                z = d < last - z ? z + d
                    : first + (d - (last - z)); }
            *y = val; }}

// TEMPLATE FUNCTION rotate_copy
template<class FwdIt, class OutIt> inline
    OutIt rotate_copy(FwdIt first, FwdIt mid, FwdIt last, OutIt x)
    {x = copy(mid, last, x);
    return (copy(first, mid, x)); }

// TEMPLATE FUNCTION random_shuffle
template<class RanIt> inline
    void random_shuffle(RanIt first, RanIt last)
    {if (first != last)
        _Random_shuffle(first, last, _Dist_type(first)); }
template<class RanIt, class Diff> inline
    void _Random_shuffle(RanIt first, RanIt last, Diff *)
    {const int _RBITS = 15;
    const int _RMAX = (1U << _RBITS) - 1;
    RanIt x = first;
    for (Diff d = 1; ++x != last; ++d)
        {unsigned long ranm = _RMAX;
        unsigned long rann = rand() & _RMAX;
        for (; ranm < d && ranm != ~0UL;
            ranm = ranm << _RBITS | _RMAX)
            rann = rann << _RBITS | _RMAX;
        iter_swap(x, first + Diff(rann % d)); }}
template<class RanIt, class Ranf> inline
    void random_shuffle(RanIt first, RanIt last, Ranf& ranf)
    {if (first != last)
        _Random_shuffle(first, last, ranf, _Dist_type(first)); }
template<class RanIt, class Ranf, class Diff> inline
    void _Random_shuffle(RanIt first, RanIt last,
        Ranf& ranf, Diff *)
    {RanIt x = first;
    for (Diff d = 1; ++x != last; ++d)
        iter_swap(x, first + Diff(ranf(d))); }

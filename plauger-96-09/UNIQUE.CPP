-------------- Listing 6: Unique Template Functions ------------

        // TEMPLATE FUNCTION unique_copy
template<class InIt, class OutIt> inline
    OutIt unique_copy(InIt first, InIt last, OutIt x)
    {return (first == last ? x :
        _Unique_copy(first, last, x,
            _Iter_cat(first))); }
template<class InIt, class OutIt> inline
    OutIt _Unique_copy(InIt first, InIt last, OutIt x,
        input_iterator_tag)
    {return (_Unique_copy(first, last, x, _Val_type(first))); }
template<class InIt, class OutIt, class T> inline
    OutIt _Unique_copy(InIt first, InIt last, OutIt x, T *)
    {T val = *first;
    for (*x++ = val; ++first != last; )
        if (!(val == *first))
            val = *first, *x++ = val;
    return (x); }
template<class FwdIt, class OutIt> inline
    OutIt _Unique_copy(FwdIt first, FwdIt last, OutIt x,
        forward_iterator_tag)
    {FwdIt firstb = first;
    for (*x++ = *firstb; ++first != last; )
        if (!(*firstb == *first))
            firstb = first, *x++ = *firstb;
    return (x); }
template<class BidIt, class OutIt> inline    ///
    OutIt _Unique_copy(BidIt first, BidIt last, OutIt x,    ///
        bidirectional_iterator_tag)    ///
    {return (_Unique_copy(first, last, x,    ///
        forward_iterator_tag())); }    ///
template<class RanIt, class OutIt> inline    ///
    OutIt _Unique_copy(RanIt first, RanIt last, OutIt x,    ///
        random_access_iterator_tag)    ///
    {return (_Unique_copy(first, last, x,    ///
        forward_iterator_tag())); }    ///

// TEMPLATE FUNCTION unique
template<class FwdIt> inline
    FwdIt unique(FwdIt first, FwdIt last)
    {first = adjacent_find(first, last);
    return (unique_copy(first, last, first)); }

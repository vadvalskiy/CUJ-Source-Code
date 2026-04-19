-------------- Listing 2: Template Function <f>max_element<d> ------------

// TEMPLATE FUNCTION max_element
template<class FwdIt> inline
    FwdIt max_element(FwdIt first, FwdIt last)
    {FwdIt x = first;
    if (first != last)
        for (; ++first != last; )
            if (*x < *first)
                x = first;
    return (x); }

// TEMPLATE FUNCTION max_element WITH PRED
template<class FwdIt, class Pred> inline
    FwdIt max_element(FwdIt first, FwdIt last, Pred pr)
    {FwdIt x = first;
    if (first != last)
        for (; ++first != last; )
            if (pr(*x, *first))
                x = first;
    return (x); }

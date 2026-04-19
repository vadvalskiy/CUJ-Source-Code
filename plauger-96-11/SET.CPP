-------------- Listing 2: Set Template Functions ------------

        // TEMPLATE FUNCTION includes
template<class InIt1, class InIt2> inline
    bool includes(InIt1 first1, InIt1 last1,
        InIt2 first2, InIt2 last2)
    {for (; first1 != last1 && first2 != last2; )
        if (*first2 < *first1)
            return (false);
        else if (*first1 < *first2)
            ++first1;
        else
            ++first2;
    return (first2 == last2); }

        // TEMPLATE FUNCTION set_union
template<class InIt1, class InIt2, class OutIt> inline
    OutIt set_union(InIt1 first1, InIt1 last1,
        InIt2 first2, InIt2 last2, OutIt x)
    {for (; first1 != last1 && first2 != last2; )
        if (*first1 < *first2)
            *x++ = *first1++;
        else if (*first2 < *first1)
            *x++ = *first2++;
        else
            *x++ = *first1++, ++first2;
    x = copy(first1, last1, x);
    return (copy(first2, last2, x)); }

        // TEMPLATE FUNCTION set_intersection
template<class InIt1, class InIt2, class OutIt> inline
    OutIt set_intersection(InIt1 first1, InIt1 last1,
        InIt2 first2, InIt2 last2, OutIt x)
    {for (; first1 != last1 && first2 != last2; )
        if (*first1 < *first2)
            ++first1;
        else if (*first2 < *first1)
            ++first2;
        else
            *x++ = *first1++, ++first2;
    return (x); }

        // TEMPLATE FUNCTION set_difference
template<class InIt1, class InIt2, class OutIt> inline
    OutIt set_difference(InIt1 first1, InIt1 last1,
        InIt2 first2, InIt2 last2, OutIt x)
    {for (; first1 != last1 && first2 != last2; )
        if (*first1 < *first2)
            *x++ = *first1++;
        else if (*first2 < *first1)
            ++first2;
        else
            ++first1, ++first2;
    return (copy(first1, last1, x)); }

        // TEMPLATE FUNCTION set_symmetric_difference
template<class InIt1, class InIt2, class OutIt> inline
    OutIt set_symmetric_difference(InIt1 first1, InIt1 last1,
        InIt2 first2, InIt2 last2, OutIt x)
    {for (; first1 != last1 && first2 != last2; )
        if (*first1 < *first2)
            *x++ = *first1++;
        else if (*first2 < *first1)
            *x++ = *first2++;
        else
            ++first1, ++first2;
    x = copy(first1, last1, x);
    return (copy(first2, last2, x)); }

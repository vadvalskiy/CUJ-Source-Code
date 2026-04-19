-------------- Listing 3: Comparison Template Functions ------------

// TEMPLATE FUNCTION lexicographical_compare
template<class InIt1, class InIt2> inline
    bool lexicographical_compare(InIt1 first1, InIt1 last1,
        InIt2 first2, InIt2 last2)
    {for (; first1 != last1 && first2 != last2;
        ++first1, ++first2)
        if (*first1 < *first2)
            return (true);
        else if (*first2 < *first1)
            return (false);
    return (first1 == last1 && first2 != last2); }

// TEMPLATE FUNCTION mismatch
template<class InIt1, class InIt2> inline
    pair<InIt1, InIt2> mismatch(InIt1 first, InIt1 last, InIt2 x)
    {for (; first != last && *first == *x; ++first, ++x)
        ;
    return (pair<InIt1, InIt2>(first, x)); }

// TEMPLATE FUNCTION equal
template<class InIt1, class InIt2> inline
    bool equal(InIt1 first, InIt1 last, InIt2 x)
    {return (mismatch(first, last, x).first == last); }

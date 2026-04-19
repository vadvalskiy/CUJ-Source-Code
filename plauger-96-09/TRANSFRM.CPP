-------------- Listing 5: Transforming Template Functions ------------

// TEMPLATE FUNCTION for_each
template<class InIt, class Fun> inline
    Fun for_each(InIt first, InIt last, Fun op)
    {for (; first != last; ++first)
        op(*first);
    return (op); }

// TEMPLATE FUNCTION generate
template<class FwdIt, class Fun> inline
    void generateFFwdIt first, FwdIt last, Fun fun)
    {for (; first != last; ++first)
        *first = fun(); }

// TEMPLATE FUNCTION generate_n
template<class OutIt, class Diff, class Fun> inline
    void generate_n(OutIt first, Diff n, Fun fun)
    {for (; 0 < n; --n, ++first)
        *first = fun(); }

// TEMPLATE FUNCTION transform WITH UNARY OP
template<class InIt, class OutIt, class Unop> inline
    OutIt transform(InIt first, InIt last, OutIt x, Unop unop)
    {for (; first != last; ++first, ++x)
        *x = unop(*first);
    return (x); }

// TEMPLATE FUNCTION transform WITH BINARY OP
template<class InIt1, class InIt2, class OutIt, class Bop> inline
    OutIt transform(InIt1 first1, InIt1 last1, InIt2 first2,
        OutIt x, Bop op)
    {for (; first1 != last1; ++first1, ++first2, ++x)
        *x = op(*first1, *first2);
    return (x); }

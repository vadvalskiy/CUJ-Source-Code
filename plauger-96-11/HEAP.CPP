-------------- Listing 3: Heap Template Functions ------------

        // TEMPLATE FUNCTION push_heap
template<class RanIt> inline
    void push_heap(RanIt first, RanIt last)
    {_Push_heap_0(first, last, _Dist_type(first),
        _Val_type(first)); }
template<class RanIt, class Diff, class T> inline
    void _Push_heap_0(RanIt first, RanIt last, Diff *, T *)
    {_Push_heap(first, Diff(last - first - 1), Diff(0),
        T(*(last - 1))); }
template<class RanIt, class Diff, class T> inline
    void _Push_heap(RanIt first, Diff hole, Diff j, T val)
    {for (Diff i = (hole - 1) / 2;
        j < hole && *(first + i) < val; i = (hole - 1) / 2)
        *(first + hole) = *(first + i), hole = i;
    *(first + hole) = val; }

        // TEMPLATE FUNCTION pop_heap
template<class RanIt> inline
    void pop_heap(RanIt first, RanIt last)
    {_Pop_heap_0(first, last, _Val_type(first)); }
template<class RanIt, class T> inline
    void _Pop_heap_0(RanIt first, RanIt last, T *)
    {_Pop_heap(first, last - 1, last - 1, T(*(last - 1)),
        _Dist_type(first)); }
template<class RanIt, class Diff, class T> inline
    void _Pop_heap(RanIt first, RanIt last, RanIt x,
        T val, Diff *)
    {*x = *first;
    _Adjust_heap(first, Diff(0), Diff(last - first), val); }
template<class RanIt, class Diff, class T> inline
    void _Adjust_heap(RanIt first, Diff hole, Diff n, T val)
    {Diff j = hole;
    Diff k = 2 * hole + 2;
    for (; k < n; k = 2 * k + 2)
        {if (*(first + k) < *(first + (k - 1)))
            --k;
        *(first + hole) = *(first + k), hole = k; }
    if (k == n)
        *(first + hole) = *(first + (k - 1)), hole = k - 1;
    _Push_heap(first, hole, j, val); }

        // TEMPLATE FUNCTION make_heap
template<class RanIt> inline
    void make_heap(RanIt first, RanIt last)
    {if (2 <= last - first)
        _Make_heap(first, last, _Dist_type(first),
            _Val_type(first)); }
template<class RanIt, class Diff, class T> inline
    void _Make_heap(RanIt first, RanIt last, Diff *, T *)
    {Diff n = last - first;
    for (Diff hole = n / 2; 0 < hole; )
        {--hole;
        _Adjust_heap(first, hole, n, T(*(first + hole))); }}

        // TEMPLATE FUNCTION sort_heap
template<class RanIt> inline
    void sort_heap(RanIt first, RanIt last)
    {for (; 1 < last - first; --last)
        pop_heap(first, last); }

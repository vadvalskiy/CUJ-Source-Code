-------------- Listing 1: Template Function <f>max<d> ------------

// TEMPLATE FUNCTION max
template<class T> inline
   const T& max(const T& x, const T& y)
   {return (x < y ? y : x); }

// TEMPLATE FUNCTION max WITH PRED
template<class T, class Pred> inline
   const T& max(const T& x, const T& y, Pred pr)
   {return (pr(x, y) ? y : x); }

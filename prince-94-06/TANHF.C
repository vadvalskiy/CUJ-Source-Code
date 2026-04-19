/* tanhf function */
#include "xmath.h"

float (tanhf) (float x) {
    double xx = x, x2, evens;
    float minthreshold = -M_LN2 / 2;
    /* Exp(x) = (evens+odds)/(evens - odds) ; tanh(x) =
     * (exp(2x)-1)/(exp(2x+1) */
    if (x <= (float) (M_LN2 / 2) && x >= minthreshold) {
	/* Derived from rational e approx */
	xx *= 60.09114349 + (x2 = xx * xx);
	evens = 120.18228722 + x2 * 12.01517514;
	return (xx + xx) * evens / (evens * evens + xx * xx);
    }
    xx += xx;
    if (x != x) {
	errno = EDOM;
	return x;
    }
    if (_Expf(&xx) < FLT_MANT_DIG)
	/* Promote final calc to double */
	return (xx - 1) / (xx + 1);
    return 1; /* large x */
}

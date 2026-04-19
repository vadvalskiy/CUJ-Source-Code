/* coshf function */
#include "xmath.h"

float (coshf) (float x) {	/* compute coshf(x) */
  /* Coshf(x) = coshf (fabsf(x)) */
  double xx;
  int exp;
  xx = x;
  if (x != x) {
	errno = EDOM;
	return x;
  }
  if (FLT_MAX_EXP + 1 < (exp = _Expf(&xx)))
	errno = ERANGE;		/* x large */
  else {
	xx = .5 / xx + .5 * xx;
	if (exp < -FLT_MAX_EXP) errno = ERANGE;
  }
  return xx;
}

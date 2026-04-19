/* sinhf function */
#include "xmath.h"

float (sinhf) (float x) {	/* compute sinhf(x) */
  int exp;
  double xx;
  float minthreshold = -1;
  if (x <= 1 && x >= minthreshold) {
	float x2 = x * x;
	return x + (.16666737f + x2 *
		    (.00832983f + x2 * .00020400f)) * (x * x2);
  }
  xx = x;
  if (x != x) {
	errno = EDOM;
	return x;
  }
  if (FLT_MAX_EXP + 1 < (exp = _Expf(&xx)))
	errno = ERANGE;		/* x large */
  else {
	xx = .5 * xx - .5 / xx;
	if (exp < -FLT_MAX_EXP) errno = ERANGE;
  }
  return xx;
}

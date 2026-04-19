/* expf function */
#include "xmath.h"

float (expf) (float x) {	
/* compute expf(x) */
  /* Test for special codes */
  double xx;
  int exp;
  if (x != x) {
	errno = EDOM;
	return x;
  }
  /* should take care of big numbers here */
  xx = x;
  if (FLT_MAX_EXP < (exp = _Expf(&xx))
 	 || exp < FLT_MIN_EXP - FLT_MANT_DIG)
	errno = ERANGE;
  return xx;
}

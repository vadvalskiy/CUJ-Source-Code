/* pow function */
#include "xmath.h"

float (powf) (float x, float y) {	/* compute x^y */
  int exp = y;
  double z;
  if (exp == y) {
	/* Multiply out to allow x<=0 or y==0 */
	int neg;
	double yi = x;
	if (neg = (exp < 0)) exp = -exp;
	z = 1.;			/* powf(0,0) = 1 */
	if (exp & 1) z = yi;
	for (; exp > 1; z *= yi) do
			yi *= yi;
		while (!((exp >>= 1) & 1));
	return neg ? 1 / z : z;
  }
  z = _Logf(x) * y;
  if (FLT_MAX_EXP < (exp = _Expf(&z)) ||
      exp < FLT_MIN_EXP - FLT_MANT_DIG)
	errno = ERANGE;
  return z;
}

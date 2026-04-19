/* logf function */
#include "xmath.h"

double _Logf(double x)
{				/* compute ln(x) */
  int xexp;
  _Dvar xx;
  double r, r2;
  static const double rthalf = M_SQRT1_2;
  xx._D = x;
  /* Convert to double eliminates underflow */

  /* Test for special codes */
  if (x != x) {
	errno = EDOM;
	return x;
  }

  /* Start working before done looking for exceptions (will throw away
   * if x was not finite positive ) */
/* Pick out exponent field, such that value is normalized
between sqrt(.5) and sqrt(2) */
  xx._W[_D0] -= xexp = (xx._W[_D0] & _DMASK) -
	((xx._W[_D0] & _DFRAC) < (((long *) &rthalf)[_D0] & _DFRAC) ?
	 (1 + _DBIAS) << _DOFF : _DBIAS << _DOFF);
  /* Assume Finite and positive */
  r = (xx._D - 1) / (xx._D + 1);

  if (x <= 0) {
	if (x == 0) {
		errno = ERANGE;
		return -DBL_MAX;/* normally becomes -Inf */
	}
	errno = EDOM;
	return(float) DBL_MAX *0;	/* NaN */
  }
  xexp >>= _DOFF;

  if (x > FLT_MAX) {		/* Inf */
	errno = ERANGE;
	return x;
  }
  r2 = r * r;
  /* Leave result in double to avoid losing significance ; 32 bits
   * required according to IEEE extended single precision */
  /* Chebyshev economized fit log(x) = 2*(x-1)/(x+1)+.... */
  return r + r + xexp * M_LN2 +
	(.66666816 + r2 * (.399748 + r2 * .29925)) * (r * r2);
}

float (logf) (float x) {
  return(float) _Logf(x);
}

float (log10f) (float x) {
  return(float) (M_LOG10E * _Logf(x));
}

/* sqrtf function */
#include "xmath.h"
#include <limits.h>

float (sqrtf) (float x) {	/* compute sqrt(x) */
  int xexp, big;
  _Dvar xd;
  double y, xxx, yy;
  union {
	float f;
	long l;
  } xx;
  const static float c[] = {.415, .59, .83};

  xd._D = x;
  if (x != x || x > FLT_MAX) return x; /* Nan arg */
  xexp = (xd._W[_D0] >> _DOFF) - _DBIAS;
  if (x <= 0) {
	if (x == 0) return x;	/* +- 0 */
	errno = EDOM;
	return(float) DBL_MAX *0; /* NaN result */
  }

  /* Frexp(x) */
  xd._W[_D0] = (xd._W[_D0] & _DFRAC) | (_DBIAS << _DOFF);
  big = xexp & 1;		/* odd exponent adjustment */
  xx.f = c[big + 1] * (float) xd._D + c[big];
  /* Xx.f=ldexpf(xx.f,(exp-(exp<0))/2) */
  xx.l += (xexp >> 1) << _FOFF;
#if -INT_MAX == INT_MIN
#error "adjust right shift to simulate 2's complement"
#endif
  /* First iteration occasionally required for IEEE rounding */
  yy = xx.f;
  y = (x + yy * yy) * .5; /* sqrt(x)*yy approx to 4 sig digs */
  xxx = yy * yy * x;
  /* Heron's formula 2 more times */
  return((y * y + xxx) * (y * y + xxx) * .25 + y * y * xxx) /
      (yy * y * (y * y + xxx));
}

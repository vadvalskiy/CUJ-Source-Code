/* Atan2 function,float precision */
#include "xmath.h"

float (atan2f) (float x, float y) {
  int invert;
  float x2, x4, xi;
  double xd;
  union {
	float f;
	long i;
  } xx, yy;
  /* Reduce to 1st or last octant; atan2f(0,0) = NaN */
  xi = x / y;
#ifdef INLINE_FABS		/* need inline code for efficiency */
  if (invert = fabsf(y) < fabsf(x))
#else				/* cheap non-portable fabsf() */
  xx.f = x;
  yy.f = y;
  if (invert = (yy.i & ~_DSIGN) < (xx.i & ~_DSIGN))
  #endif
	xi = y / x;
  x2 = xi * xi;
  x4 = x2 * x2;
/* Coefficients determined by Chebyshev fit */
  xi += ((x4 * (-0.01600503f + x2 * .00283406f) +
	-0.07495445f + x2 * .04258761f) * (x4 * x4)
         + (-0.14202571f + x2 * .10636754f) * x4
         + -0.33333067f + x2 * .19992484f) * (xi * x2);
  if (invert) {			/* octants 2,3,6,7 */
	/* Certain compilers don't parallelize constant loads unless
	 * they come before the comparison */
	xd = M_PI_2;
	return(x < 0 ? -xd : xd) - xi;
  }
#ifdef INLINE_FABS
  if (y >= 0)
  #else
  if (yy.i >= 0)
  #endif
	return xi;		/* octants 1,8 */
  x4 = xi + (float) M_PI;	/* octant 4 or 5 */
  if (x < 0) x4 = xi - (float) M_PI;	/* octant 5 */
  return x4;
}

float (atanf) (float x) {
  return atan2f(x, 1.f);
}

float (asinf) (float x) {
/* Sqrt instruction included in most modern architectures */
  if (x < -1 || x > 1) errno = EDOM;
  return atan2f(x, sqrt(1 - (double) x * x));
}

float (acosf) (float x) {
  if (x < -1 || x > 1) errno = EDOM;
  return atan2f(sqrt(1 - (double) x * x), x);
}

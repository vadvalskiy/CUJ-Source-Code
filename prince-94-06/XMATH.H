#include "math.h"
#include <errno.h>
#include <float.h>
typedef union { /* VAX compatibility discarded for simplicity */
	double _D;
	 unsigned long _W[2]; 
	} _Dvar;
/* this section belongs in yvals.h according to Plauger */
#define _D0 0	/* big-endian order */
#define _DOFF 20 /* IEEE double format, using union of longs */
#define _DSIGN 0x80000000	/* not given in article: sign bit mask */
#define _DBIAS 1022	/* not given in article: exponent field of 0.0 */
#define _FOFF (FLT_MANT_DIG - 1)
/* end of section from yvals.h */
#define _DFRAC ((1<<_DOFF)-1)
#define _DMASK ( ~_DFRAC) /* wrong in article */
#define _DMAX ((1<<(31-_DOFF))-1)	/* 15 for short */
#define _DNAN (0x80000000|_DMAX<<_DOFF|1<<(_DOFF-1))	/* 8000 */
#define _D1	(1-_D0)			/* word order VAX */
#define FINITE -1
#define INF	1
#define NAN	2
#define NBITS (32+_DOFF)
#define DSIGN(x) (((unsigned long *)&(x))[_D0]&_DSIGN)
#define HUGE_EXP	(int)(_DMAX * 900L / 100) /* correct bug in Plauger */
#define HUGE_RAD	3.14e30
#define SAFE_EXP	(_DMAX>>1)
		/* declarations */
double _Atan();
double _Atant();
int _Dint();
int _Dnorm();
int _Dscale();
double _Dtento();
int _Dtest();
#define _Dtest(x) ((x)>DBL_MAX||(x)<-DBL_MAX?INF:(x)!=(x)?NAN:(x)!=0?FINITE:0)
int _Dunscale();
int _Exp();
int _Ldunscale();
double _Poly();
double _Asin();
double _Log();
double _Sin();
extern _Dconst _Hugeval;
		/* macro overrides */
#define acos(x)	_Asin(x, 1)
#define cos(x)	_Sin(x, 1)
#define sin(x)	_Sin(x, 0)
double _Logf(double);
int _Expf(double *);

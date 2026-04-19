/* Copyright (c) 1985 Regents of the University of California.                 
  Use and reproduction of this software are granted in accordance              
with                                                                           
  the terms and conditions specified in the Berkeley Software                  
License                                                                        
  Agreement (in particular, this entails acknowledgement of the                
  programs' source, and inclusion of this notice) with the                     
additional                                                                     
  understanding that all recipients should regard themselves as                
  participants in an ongoing research project and hence should                 
feel                                                                           
  obligated to report their experiences (good or bad) with these               
  elementary function codes, using "sendbug 4bsd-bugs@BERKELEY",               
to the                                                                         
  authors.                                                                     
 */                                                                            
#ifndef lint                                                                   
static char sccsid[] = "@(#)atan2l.c     (T Prince) 6/3/95";                   
#endif                   /* not lint */                                        
/* ATAN2(Y,X) RETURN ARG (X+iY)                                                
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)                
 * CODED IN C BY K.C. NG, 1/8/85;                                              
 * REVISED BY K.C. NG on 2/7/85, 2/13/85, 3/7/85, 3/30/85,                     
6/29/85.                                                                       
 * long double by T C Prince 6/95                                              
 *                                                                             
 * Method :                                                                    
 1. Reduce y to positive by atan2(y,x)=-atan2(-y,x).                           
 2. Reduce x to positive by (if x and y are unexceptional):                    
                ARG (x+iy) = arctan(y/x)           ... if x > 0,               
                ARG (x+iy) = pi - arctan[y/(-x)]   ... if x < 0,               
 3.  the argument                                                              
        is further reduced to one of the following intervals and               
the                                                                            
        arctangent of y/x is evaluated by the corresponding                    
formula:                                                                       
                                                                               
        [0,1/3]          atan(y/x) = t -                                       
t^3*(a1+t^2*(a2+...a10+t^2*a11)                                                
        [1/3,11/16]      atan(y/x) = atan(1/2) + atan(                         
(y-x/2)/(x+y/2) )                                                              
        [11/16,19/16]   atan(y/x) = atan( 1 ) + atan( (y-x)/(x+y)              
)                                                                              
        [19/16,3]        atan(y/x) = atan(3/2) +                               
atan((y-1.5x)/(x+1.5y))                                                        
        [3,INF]          atan(y/x) = atan(INF) + atan( -x/y )                  
                                                                               
  The decimal values may be used, provided that the compiler will              
  convert from decimal to binary accurately enough.                            
 */                                                                            
#define ath .463647609000806116214256231461214402028537L                       
#define at1 .982793723247329067985710611014666014496877L                       
#define athfhi  (double)ath                                                    
#include <float.h>                                                             
#define FUDGE (1+LDBL_EPSILON/DBL_EPSILON*.125)                                
#define athflo  (ath - athfhi)*FUDGE                                           
#define at1fhi  (double)at1                                                    
#define at1flo  (at1-at1fhi)*FUDGE                                             
#define PI  3.141592653589793238462643383279502884197169L                      
#include "math.h"                                                              
#include <assert.h>                                                            
#include "fp.h"                                                                
                                                                               
long double atan2l(long double y, long double x)                               
{                                                                              
    long double t, z, signy, hi, lo;                                           
    double_t a11;                                                              
    int signx;                                                                 
    /* Copy down the sign of y and x */                                        
    signy = 1.;                                                                
    if (y < 0) {                                                               
     y = -y;                                                                   
     signy = -1.;                                                              
    }                                                                          
    if (signx = x < 0)                                                         
     x = -x;                                                                   
    if ((a11 = t = y / x) < 3) {                                               
     /* In case T is in [0,1/3] */                                             
     hi = 0;                                                                   
     lo = 0;                                                                   
     if (a11 > 1 / 3.) {                                                       
         if (a11 < 11 / 16.) {     /* T is in [1/3,11/16] */                   
          t = (y + y - x) / (x + x + y);                                       
          hi = athfhi;                                                         
          lo = athflo;                                                         
         } else {                                                              
          if (a11 < 19 / 16.) {                                                
              /* T is in [11/16,19/16] */                                      
              t = (y - x) / (x + y);                                           
              hi = (double) PI *.25;                                           
              lo = (PI * .25 - (double) PI * .25) * FUDGE;                     
          } else {  /* T is in [19/16,3] */                                    
              t = y - x;                                                       
              t = (t + t - x) / ((x + x) + (y + y + y));                       
              hi = at1fhi;                                                     
              lo = at1flo;                                                     
          }                                                                    
         }                                                                     
     }                                                                         
    } else {             /* T >= 3 */                                          
/* 0/0 produces NaN (agrees with IEEE, not UNIX tradition) */                  
     t = -x / y;                                                               
     hi = (double) PI *.5;                                                     
     lo = (PI * .5 - (double) PI * .5) * FUDGE;                                
    }                                                                          
#ifdef DEBUG                                                                   
    assert(t <= 1. / 3 || t != t);                                             
#endif                                                                         
    a11 = z = t * t;                                                           
    z = (t + (lo - t * z *                                                     
(.333333333333333333333333333333326238L +                                      
                   z * (-.199999999999999999999999999989692064L +              
                      z * (.142857142857142857142857136902464695L              
+                                                                              
                     z * (-.111111111111111111111109286933220956L              
+                                                                              
                      z * (.090909090909090909090566375305311242L              
+                                                                              
                     z * (-.076923076923076923033848105066780741L              
+                                                                              
                      z * (.066666666666666662832160589417621446L              
+                                                                              
                     z * (-.058823529411764454382902973039123863L              
+                                                                              
                      z * (.052631578947355920010163119267195941L              
+                                                                              
                     z * (-.047619047618567045788940099947698386L              
+                                                                              
                      z * (.043478260855068916374201546117917056L              
+                                                                              
                     z * (-.039999999653506693442185507209875834L              
+                                                                              
                      z * (.037037030436227061574079324145862133L              
+                                                                              
                     z * (-.034482658185047909429270585023057681L              
+                                                                              
                      z * (.032256845866214999368038205000384542L              
+                                                                              
                     z * (-.030291305255230381718828679590094691L              
+                                                                              
                      z * (.028482910936322424263248147209081714L              
+                                                                              
                     z * (-.026511385701218695500640341310485698L              
+                                                                              
                     a11 * (.023381127183313153463575187882151062              
+                                                                              
                     a11 *                                                     
(-.017211039939973303258669077432249085 +                                      
                     a11 * .007572335682370299569957516923702074               
                     )))))))))))))))))))))) + hi;                              
    return (signx ? PI - z : z) * signy;                                       
}                                                                              
                                                                               
long double (atanl) (long double x) {                                          
    return atan2l(x, 1.);                                                      
}                                                                              

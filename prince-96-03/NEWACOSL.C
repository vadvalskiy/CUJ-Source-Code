/* _Asinl function analogous to Plauger's Standard C Library */                
#include "xmath.h"                                                             
                                                                               
#define pi 3.141592653589793238462643383279502884L                             
#define piby2 (pi*.5)                                                          
long double _Asinl(long double x, int idx)                                     
{                   /* compute asin(x) or acos(x) */                           
    long double y;                                                             
    if (x < 0.0)                                                               
     y = -x, idx |= 2;                                                         
    else                                                                       
     y = x;                                                                    
    if (y <= 1) {                                                              
     long double g;                                                            
     double_t gd,gd2;                                                          
     if (y < .5) {                                                             
         g = y * y;                                                            
     } else {       /* find 2*asin(sqrt((1-x)/2)) */                           
         idx |= 4;                                                             
         g = (1 - y) * .5;    /* (1-y)/2 for non-IEEE arithmetic               
! */                                                                           
         y = sqrtl(g);                                                         
         y += y;                                                               
     }                                                                         
     gd = g;                                                                   
     gd2=gd*gd;                                                                
     y += y * g *(.1666666666666666666666666666668570L+                        
          g*(.0749999999999999999999999998022538L+                             
          g*(.0446428571428571428571429389689650L+                             
          g*(.0303819444444444444444264290584560L+                             
          g*(.0223721590909090909115355071830985L+                             
          g*(.0173527644230769228535123004333133L+                             
          g*(.0139648437500000145854270593316417L+                             
          g*(.0115518008961389967887953252084218L+                             
          g*(.0097616095292205461299100045739528L+                             
          g*(.0083903358088407273116333804238820L+                             
          g*(.0073125258917933144096769770989196L+                             
          g*(.0064472099662350030602735825097722L+                             
          g*(.0057400430469470012178027741126342L+                             
          g*(.0051532407052283891602048523937712L+                             
          g*(.0046608773900891796043186670427659L+                             
          g*(.0042344112499930659223984769035612L+                             
          g*(.0039288463047417532461405959282864L+                             
          g*(.0032755791882552983966431652555523L+                             
          gd*(.0047900023410405404395737695213394+                             
          gd*(-.003197356230217091344329534872855+                             
          gd*.0242342929090178315944641858529953+                              
          gd2*(-.056162800637735353622248996665855+                            
          gd*.1298088328028267499694875794652396)+                             
         gd2*gd2*(-.207462246327501442374286462096518+                         
          gd*.2514026839145941338097478636203912+                              
          gd2*(-.190663053387901667982904335750738+                            
          gd*.0776811916171552807854906559050842                               
                   ))))))))))))))))))))));                                     
     switch (idx) {      /* flip and fold */                                   
     default:       /* shouldn't happen */                                     
     case 0:        /* asin, [0, 1/2) */                                       
     case 5:        /* acos, (1/2, 1] */                                       
         return (y);                                                           
     case 1:        /* acos, [0, 1/2) */                                       
     case 4:        /* asin, (1/2, 1] */                                       
         return piby2 - y;                                                     
     case 2:        /* asin, [-1/2, 0) */                                      
         return (-y);                                                          
     case 3:        /* acos, [-1/2, 0) */                                      
         return piby2 + y;                                                     
     case 6:        /* asin, [-1, -1/2) */                                     
         return y - piby2;                                                     
     case 7:        /* acos, [-1, -1/2) */                                     
         return pi - y;                                                        
     }                                                                         
    }                                                                          
    /* 1.0 < |x|, undefined */                                                 
    errno = EDOM;                                                              
    return x != x ? x : (LDBL_MAX * 2) * 0;                                    
}                                                                              
/* asin function */                                                            
                                                                               
long double (asinl) (long double x) {   /* compute asin(x) */                  
    return (_Asinl(x, 0));                                                     
}                                                                              
                                                                               
long double (acosl) (long double x) {   /* compute acos(x) */                  
    return (_Asinl(x, 1));                                                     
}                                                                              

#ifndef __PMKMATH_H
  #define __PMKMATH_H

  #ifndef __STRING_H
    #include<string.h>
  #endif
  #ifndef __CTYPE_H
    #include<ctype.h>
  #endif

  // Combine String with Char
  void   far linksc(char   far*des,char far src);
  // Translate Radix

  char   far*radix(char   far*s,unsigned char far sn,unsigned char far dn);
  long   far radix(char   far*s,unsigned char far sn);

  double far middle(double far a,double far b);
  double far   baby(double far a,double far b);

#endif
#ifndef __PMKTIME_H
 #define __PMKTIME_H
//Don't move '#endif' to the end of this file.
#endif

#ifndef __TIME_H
 #include<time.h>
#endif

#ifndef _SECOND_ //Get how many blank loop CPU can did in 1 second time
 double cpusecond(void)
 {long time1,time2;unsigned count;
  time1=time(NULL);
  for(count=0x0000;count<0xffffU;count++);
  time2=time(NULL);
  return (0xffffU/difftime(time1,time2));
 }
#endif
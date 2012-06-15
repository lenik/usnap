#ifndef __PMKDEFINES_H
	#define __PMKDEFINES_H

	#ifndef BYTE
	  #define BYTE unsigned char
	#endif

	#define swap(a,b,c) {c=a;a=b;b=c;}
	#define mid(a,b,c)  {c=(a+b)/2;}

	#define getm(a,b) \
	  for(temp=0;temp<4;temp++)\
	    if((b[temp] = farmalloc(getsize(a)))==NULL)\
	      {printf("Not enough memory.\n");exit(1);}\
	  get(a,b);

	#define putm(a,b) \
	  put(a,b);\
	  for(temp=0;temp<4;temp++)\
	    farfree(b[temp]);

	#ifndef __FORPMKDRAWMARGUMENTS__
	  #define __FORPMKDRAWMARGUMENTS__
	  #ifndef ef__
	    #define ef__
	  #endif
	  #ifndef sanff__
	    #define sanff__
	  #endif
	  #ifndef gotff__
	    #define gotff__
	  #endif
	  #ifndef smaff__
	    #define smaff__
	  #endif
	  #ifndef triff__
	    #define triff__
	  #endif
	  #ifndef bolff__
	    #define bolff__
	  #endif
	  #ifndef eurff__
	    #define eurff__
	  #endif
	  #ifndef comff__
	    #define comff__
	  #endif
	  #ifndef scrff__
	    #define scrff__
	  #endif
	  #ifndef simff__
	    #define simff__
	  #endif
	  #ifndef tscff__
	    #define tscff__
	  #endif
	#endif

	#ifndef PMKVER
	  #define PMKVER "Program Maker 1.00\n"
	#endif

	#ifndef pmkver
	  #define pmkver PMKVER
	#endif

	#ifndef PmkVer__)
	  #define __PmkVer__ pmkver
	#endif

	#ifndef __pmkver__
	  #define __pmkver__ __PmkVer__
	#endif

	//LevelUp
	#ifndef LEVELUP)
	  #define LEVELUP //LevelUp
	#endif

	#ifndef levelup
	  #define levelup LEVELUP
	#endif

	#ifndef LevelUp
	  #define LevelUp levelup
	#endif

#endif
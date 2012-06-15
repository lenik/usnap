#ifndef __PMKCLEARSCREENEXPERT_H
	#define __PMKCLEARSCREENEXPERT_H

	#if !defined(__GRAPHICS_H)
	  #include<graphics.h>
	#endif

	#if !defined(__STDLIB_H)
	  #include<stdlib.h>
	#endif

	#if !defined(__TIME_H)
	  #include<time.h>
	#endif

	#if !defined(__BIOS_H)
	  #include<bios.h>
	#endif

	#ifndef pset
	  #define pset   0
	#endif

	#ifndef linex
	  #define linex  1
	#endif

	#ifndef liney
	  #define liney  2
	#endif

	#ifndef cirmid
	  #define cirmid 3
	#endif

	#ifndef cirmov
	  #define cirmov 4
	#endif

	extern int far mx,my;

	void far colorcls(unsigned long count,unsigned char type,unsigned char lwidth);
#endif

//
// RASTERITION GRAPHICS LIBRARY
//
// BASIC LINEAR ALGORITHM

#ifndef RGL_LA_BASIC
#define RGL_LA_BASIC

#ifndef __lp
	#define __lp

	#define __lp2(x, y)	y * dwPitch + x
	#define _lp2(x, y)	(y) * dwPitch + (x)
	#define lp2(x, y)	(_lp2(x, y))

	#define __lp3(x, y, z)	z * dwPlainPitch + y * dwPitch + x
	#define _lp3(x, y, z)	(z) * dwPlainPitch + (y) * dwPitch + (x)
	#define lp3(x, y, z)	(_lp3(x, y, z))
#endif // __lp

#endif // RGL_LA_BASIC
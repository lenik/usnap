
#ifndef __STDTYPES_H
#define __STDTYPES_H

/* 标准类型 */
#if defined(WIN32) || defined(_WINDOWS)
#define STDCALL		_stdcall
#elif defined(__cplusplus) || defined(__PASCAL__)
#define STDCALL		_pascal
#elif defined(__TURBOC__) || defined(__CDECL__)
#define STDCALL		_cdecl
#else
#define STDCALL		/**/
#endif

#define REAL		double

#if !(defined(WIN32) || defined(_WINDOWS))
typedef unsigned long	DWORD;
typedef int		INT, *PINT, *LPINT;
typedef int		BOOL;
#define TRUE	1
#define FALSE	0
typedef char 		TCHAR, *PSTR;
typedef PSTR		LPSTR, LPTSTR, LPCTSTR;
#endif

/* 标准图像数据结构 */
#if !(defined(WIN32) || defined(_WINDOWS))
typedef struct _POINT {
	INT	x;
	INT	y;
} POINT, *PPOINT, *LPPOINT;
#endif

/* 数组分配 */
#ifdef __cplusplus
#define NEWA(type, n)	new type[n]
#define DELETEA(var)	delete[] var
#define DEFAULT(val)	= val
#else
#define NEWA(type, n)	(type *)malloc(sizeof(type) * (n))
#define DELETEA(var)	free(var)
#define DEFAULT(val)	/**/
#endif

#endif

// FastImg.cpp : Defines the entry point for the DLL application.
//

typedef DWORD (_stdcall *BITBLTPROC)(DWORD, DWORD);
typedef DWORD (_stdcall *BITBLTALPHAPROC)(DWORD, DWORD, DWORD);
typedef BOOL  (_stdcall *BITBLTEXTENDPROC)(LPDWORD, LPDWORD, LONG, LONG, DWORD);

#define BITBLT_SIMPLE			0x000001	// 通用二元回调
#define BITBLT_BIDIRECTION		0x000002	// 双向修改二元回调(通过传递两个指针)
#define BITBLT_ALPHA			0x000003	// 常量三元回调
#define BITBLT_ALPHA_H			0x000004	// 水平过渡三元回调
#define BITBLT_ALPHA_V			0x000005	// 垂直过渡三元回调
#define BITBLT_EXTEND			0x0000FF	// 阵列传递回调

#define BITBLT_ONLYDEST			0x000100	// 源区域是常量		alpha1
#define BITBLT_ONLYSRC			0x000200	// 目标区域是常量	alpha2

#define BITBLT_TESTBITMAP		0x010000	// 仅测试位图功能
#define BITBLT_TESTCALLBACK		0x020000	// 仅测试回调功能

#define FI_DESTKEY			0x00		// 通过目标键
#define FI_SRCKEY			0x01		// 通过源键

#define FI_GETADDRESS			0
#define FI_GETVAL			1
#define FI_SETVAL			2

#define FI_VAR_RUNNING			0
#define FI_VAR_ALPHA1			1
#define FI_VAR_ALPHA2			2
#define FI_VAR_X			3
#define FI_VAR_Y			4
#define FI_VAR_WIDTH			5
#define FI_VAR_HEIGHT			6
#define FI_VAR_P			7
#define FI_VAR_ALPHAT			10
#define FI_VAR_ALPHAC			11
#define FI_VAR_BITSDEST			12
#define FI_VAR_BITSSRC			13
#define FI_VAR_SIZEDEST			14
#define FI_VAR_SIZESRC			15

#define FI_MAXDELAY			4096		// 最大锁定延时. 用于恢复锁定出错

#define FI_MAXWIDTH			2048
#define FI_MAXHEIGHT			2048

// 位处理宏
	#define	_I(X, Y)	((height - (Y) - 1) * width + (X))

	#define	_A(A, B)	FI_BitBlt_Call_Add(A, B)
	#define	_S(A, B)	FI_BitBlt_Call_Sub(A, B)
	#define	_M(A, B)	FI_BitBlt_Call_Mul_(A, B)
	#define	_D(A, B)	FI_BitBlt_Call_Div_(A, B)

	#define _K(C)		(((C) >> 24) & 0xFF)
	#define _R(C)		(((C) >> 16) & 0xFF)
	#define _G(C)		(((C) >>  8) & 0xFF)
	#define _B(C)		( (C)        & 0xFF)
	#define _RGB(R, G, B)	(((R) << 16) | ((G) << 8) | (B))
	#define _DRGB(P, T, C)	\
				T P##R = _R(C);	\
				T P##G = _G(C);	\
				T P##B = _B(C);

	#define _MAX(A, B)	((A) > (B) ? (A) : (B))
	#define _MIN(A, B)	((A) < (B) ? (A) : (B))
	#define _NOMORE(N, S)	((N) > (S) ? (S) : (N))
	#define _NOLESS(N, S)	((N) < (S) ? (S) : (N))
	#define _NOLESS0B(N)	((N) > 0xFF ? 0 : (N))

// 外部变量声明

	extern BOOL		bRunning;

	extern HDC		hcDest,		hcSrc;
	extern HBITMAP		hoDest,		hoSrc;
	extern HBITMAP		hbmDest,	hbmSrc;
	extern BITMAPINFO	bmiDest,	bmiSrc;

	extern DWORD		*bitsDest,	*bitsSrc;
	extern LONG		sizeDest,	sizeSrc;

	extern LONG		x, y;
	extern LONG		width, height;
	extern LONG		p;

	extern DWORD		alpha1, alpha2;
	extern DWORD		miniDelay;

	extern BYTE		alphaTable[257];
	extern BYTE		alphaColor[257][256];

BOOL	_stdcall FI_BitBlt_Fn(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, LONG fntype, LPARAM lParam, DWORD dwParam);
BOOL	_stdcall FI_BitBlt_Simple_Fn(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, BITBLTPROC bitblt_callback);
BOOL	_stdcall FI_BitBlt_Simple_Add(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy);
BOOL	_stdcall FI_BitBlt_Simple_Sub(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy);
BOOL	_stdcall FI_BitBlt_Simple_Mul(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, DWORD factor);
BOOL	_stdcall FI_BitBlt_Simple_Div(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, DWORD factor);
BOOL	_stdcall FI_BitBlt_Merge(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD key);
BOOL	_stdcall FI_BitBlt_Alpha_Fn(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, BITBLTALPHAPROC bitblt_alpha_callback);
BOOL	_stdcall FI_BitBlt_Alpha_Simple(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD alpha);
BOOL	_stdcall FI_BitBlt_Alpha_Merge(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD alpha, DWORD key);
BOOL	_stdcall FI_BitBlt_LinearAlpha_H(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD alphaTop, DWORD alphaBottom);
BOOL	_stdcall FI_BitBlt_LinearAlpha_V(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD alphaLeft, DWORD alphaRight);
BOOL	_stdcall FI_BitBlt_LinearAlpha_Ex(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, DWORD alphaAngleFromCenter);
BOOL	_stdcall FI_BitBlt_Extend_Fn(HDC hDestDC, LONG destx, LONG desty, LONG width, LONG height, HDC hSrcDC, LONG srcx, LONG srcy, BITBLTEXTENDPROC bitblt_extend_callback, DWORD dwParam);

BOOL	_stdcall FI_Init_Alpha(DWORD amode);
DWORD	_stdcall FI_BitBlt_Vars(DWORD op, LONG index, DWORD dwParam = 0);
BYTE	_stdcall FI_BitBlt_GetAlpha(DWORD alpha, DWORD color);

DWORD	_stdcall FI_BitBlt_Call_Copy(DWORD cDest, DWORD cSrc);
DWORD	_stdcall FI_BitBlt_Call_Order(DWORD cDest, DWORD cSrc);

DWORD	_stdcall FI_BitBlt_Call_Add(DWORD cDest, DWORD cSrc);
DWORD	_stdcall FI_BitBlt_Call_Sub(DWORD cDest, DWORD cSrc);
DWORD	_stdcall FI_BitBlt_Call_Mul(DWORD cDest, DWORD cSrc);
DWORD	_stdcall FI_BitBlt_Call_Div(DWORD cDest, DWORD cSrc);
DWORD	_stdcall FI_BitBlt_Call_Mul_(DWORD cDest, double factor);
DWORD	_stdcall FI_BitBlt_Call_Div_(DWORD cDest, double factor);
DWORD	_stdcall FI_BitBlt_Call_Light(DWORD cDest, DWORD cSrc);
DWORD	_stdcall FI_BitBlt_Call_Dark(DWORD cDest, DWORD cSrc);

DWORD	_stdcall FI_BitBlt_Call_Merge(DWORD cDest, DWORD cSrc, DWORD key);
DWORD	_stdcall FI_BitBlt_Call_Alpha(DWORD cDest, DWORD cSrc, DWORD alpha);
DWORD	_stdcall FI_BitBlt_Call_Alpha_Merge(DWORD cDest, DWORD cSrc, DWORD alpha);

BOOL	_stdcall FI_BitBlt_E_Call_Blur(LPDWORD destBits, LPDWORD srcBits, LONG width, LONG height, DWORD blurOption);
BOOL	_stdcall FI_BitBlt_E_Call_Scan(LPDWORD bitsDest, LPDWORD bitsSrc, LONG width, LONG height, DWORD scanOption);


#define BYTE	unsigned char
#define WORD	unsigned short
#define DWORD	unsigned long

#define PNEAR	void near *
#define PFAR	void far *

typedef struct _INT64 {
	DWORD		low;
	signed long	high;
} INT64;

typedef union _FOURCC {
	char	c[4];
	DWORD	val;
	operator DWORD() { return val; }
} FOURCC;

#define __zero(x)	memset(&x, 0, sizeof(x))

union D4 {
	DWORD dw;
	struct w {
		WORD l;
		WORD h;
	};
	struct b {
		BYTE b0;
		BYTE b1;
		BYTE b2;
		BYTE b3;
	};
};

#define _CF	(_FLAGS & 0x0001)
#define _PF	(_FLAGS & 0x0004)
#define _AF	(_FLAGS & 0x0010)
#define _ZF	(_FLAGS & 0x0040)
#define _SF	(_FLAGS & 0x0080)
#define _TF	(_FLAGS & 0x0100)
#define _IF	(_FLAGS & 0x0200)
#define _DF	(_FLAGS & 0x0400)

#define __CF	(_F & 0x0001)
#define __PF	(_F & 0x0004)
#define __AF	(_F & 0x0010)
#define __ZF	(_F & 0x0040)
#define __SF	(_F & 0x0080)
#define __TF	(_F & 0x0100)
#define __IF	(_F & 0x0200)
#define __DF	(_F & 0x0400)

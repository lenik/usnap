

#ifndef __CAMPOTEXT_H

#define __CAMPOTEXT_H

#include "campoFunc.h"


// defines campo commands

#define CCTEXT_POSITION			'P'
#define CCTEXT_DIRECTION		'D'
#define CCTEXT_ALIGN			'A'
#define CCTEXT_FONT				'F'
#define CCTEXT_EFFECTS			'X'
#define CCTEXT_COLOR			'C'
#define CCTEXT_TEXT				'T'

struct ctFont {
	CString	fontName;
	int		fontSize;
	BOOL	fontBold;
	BOOL	fontItalic;
	BOOL	fontUnderline;
public:
	ctFont() : fontName("Arial"),
		fontSize(100),
		fontBold(FALSE),
		fontItalic(FALSE),
		fontUnderline(FALSE) {}
};

enum ctDirection {
	horizontal,
	vertical
};

struct ctAlign {
	enum ctAlignH {
		left,
		right,
		center
	} h;

	enum ctAlignV {
		top,
		bottom,
		baseline
	} v;
public:
	ctAlign() : h(left), v(top) {}
public:
	UINT getWinAlign();
};


class ctElement {
	CFont			*o_font;
	COLORREF		o_color;
	UINT			o_align;
public:
	CStringArray	text;
	ctFont			font;			// struct
	cColor			color;			// struct
	CPoint			position;		// struct
	ctAlign			align;			// struct
	ctDirection		dir;			// enum
protected:
	CRgn			*setEmptyRgn(CRgn *);
	CRgn			*rgnEntire;
public:
	ctElement();
public:
	BOOL initDC(CDC *pDC);
	BOOL initDC(HDC hDC);
	BOOL restoreDC(CDC *pDC);
	BOOL restoreDC(HDC hDC);

	CRgn *getExtent(CDC *pDC);
	CRgn *getExtent(HDC hDC);

	void draw(CDC *pDC);
	BOOL draw(HDC hDC);
};

class cText {
public:
	cPtrList	textList;

public:
	void draw(CDC *pDC);
	BOOL draw(HDC hDC);

	ctElement *getPointOn(CDC *pDC, POINT point);
	ctElement *getPointOn(HDC hDC, POINT point);
	//BOOL getElementsInRect(CDC *pDC, LPCRECT rect, CTENUMELEMENTSPROC eleProc = NULL, BOOL includeCrossBorder = TRUE);
	//BOOL getElementsInRect(HDC hDC...);

public:
	BOOL Load(CArchive &ar);
	BOOL Save(CArchive &ar);

public:
	cText();
	cText(CArchive &ar);
	~cText();
};

#endif	// __CAMPOTEXT_H


#include "stdafx.h"

#include "wmfDecode.h"

CNostrArray aFname;

static BOOL wmfStatus = FALSE;

static void wmfInit() {
	aFname.Add(new NoStr(0x0201,	1,	new CString("META_SETBKCOLOR")));
	aFname.Add(new NoStr(0x0102,	1,	new CString("SETBKMODE")));
	aFname.Add(new NoStr(0x0103,	1,	new CString("SETMAPMODE")));
	aFname.Add(new NoStr(0x0104,	1,	new CString("SETROP2")));
	aFname.Add(new NoStr(0x0105,	1,	new CString("SETRELABS")));
	aFname.Add(new NoStr(0x0106,	1,	new CString("SETPOLYFILLMODE")));
	aFname.Add(new NoStr(0x0107,	1,	new CString("SETSTRETCHBLTMODE")));
	aFname.Add(new NoStr(0x0108,	1,	new CString("SETTEXTCHAREXTRA")));
	aFname.Add(new NoStr(0x0209,	1,	new CString("SETTEXTCOLOR")));
	aFname.Add(new NoStr(0x020A,	1,	new CString("SETTEXTJUSTIFICATION")));
	aFname.Add(new NoStr(0x020B,	1,	new CString("SETWINDOWORG")));
	aFname.Add(new NoStr(0x020C,	1,	new CString("SETWINDOWEXT")));
	aFname.Add(new NoStr(0x020D,	1,	new CString("SETVIEWPORTORG")));
	aFname.Add(new NoStr(0x020E,	1,	new CString("SETVIEWPORTEXT")));
	aFname.Add(new NoStr(0x020F,	1,	new CString("OFFSETWINDOWORG")));
	aFname.Add(new NoStr(0x0410,	1,	new CString("SCALEWINDOWEXT")));
	aFname.Add(new NoStr(0x0211,	1,	new CString("OFFSETVIEWPORTORG")));
	aFname.Add(new NoStr(0x0412,	1,	new CString("SCALEVIEWPORTEXT")));
	aFname.Add(new NoStr(0x0213,	1,	new CString("LINETO")));
	aFname.Add(new NoStr(0x0214,	1,	new CString("MOVETO")));
	aFname.Add(new NoStr(0x0415,	1,	new CString("EXCLUDECLIPRECT")));
	aFname.Add(new NoStr(0x0416,	1,	new CString("INTERSECTCLIPRECT")));
	aFname.Add(new NoStr(0x0817,	1,	new CString("ARC")));
	aFname.Add(new NoStr(0x0418,	1,	new CString("ELLIPSE")));
	aFname.Add(new NoStr(0x0419,	1,	new CString("FLOODFILL")));
	aFname.Add(new NoStr(0x081A,	1,	new CString("PIE")));
	aFname.Add(new NoStr(0x041B,	1,	new CString("RECTANGLE")));
	aFname.Add(new NoStr(0x061C,	1,	new CString("ROUNDRECT")));
	aFname.Add(new NoStr(0x061D,	1,	new CString("PATBLT")));
	aFname.Add(new NoStr(0x001E,	1,	new CString("SAVEDC")));
	aFname.Add(new NoStr(0x041F,	1,	new CString("SETPIXEL")));
	aFname.Add(new NoStr(0x0220,	1,	new CString("OFFSETCLIPRGN")));
	aFname.Add(new NoStr(0x0521,	1,	new CString("TEXTOUT")));
	aFname.Add(new NoStr(0x0922,	1,	new CString("BITBLT")));
	aFname.Add(new NoStr(0x0B23,	1,	new CString("STRETCHBLT")));
	aFname.Add(new NoStr(0x0324,	1,	new CString("POLYGON")));
	aFname.Add(new NoStr(0x0325,	1,	new CString("POLYLINE")));
	aFname.Add(new NoStr(0x0626,	1,	new CString("ESCAPE")));
	aFname.Add(new NoStr(0x0127,	1,	new CString("RESTOREDC")));
	aFname.Add(new NoStr(0x0228,	1,	new CString("FILLREGION")));
	aFname.Add(new NoStr(0x0429,	1,	new CString("FRAMEREGION")));
	aFname.Add(new NoStr(0x012A,	1,	new CString("INVERTREGION")));
	aFname.Add(new NoStr(0x012B,	1,	new CString("PAINTREGION")));
	aFname.Add(new NoStr(0x012C,	1,	new CString("SELECTCLIPREGION")));
	aFname.Add(new NoStr(0x012D,	1,	new CString("SELECTOBJECT")));
	aFname.Add(new NoStr(0x012E,	1,	new CString("SETTEXTALIGN")));
	aFname.Add(new NoStr(0x0830,	1,	new CString("CHORD")));
	aFname.Add(new NoStr(0x0231,	1,	new CString("SETMAPPERFLAGS")));
	aFname.Add(new NoStr(0x0A32,	1,	new CString("EXTTEXTOUT")));
	aFname.Add(new NoStr(0x0D33,	1,	new CString("SETDIBTODEV")));
	aFname.Add(new NoStr(0x0234,	1,	new CString("SELECTPALETTE")));
	aFname.Add(new NoStr(0x0035,	1,	new CString("REALIZEPALETTE")));
	aFname.Add(new NoStr(0x0436,	1,	new CString("ANIMATEPALETTE")));
	aFname.Add(new NoStr(0x0037,	1,	new CString("SETPALENTRIES")));
	aFname.Add(new NoStr(0x0538,	1,	new CString("POLYPOLYGON")));
	aFname.Add(new NoStr(0x0139,	1,	new CString("RESIZEPALETTE")));
	aFname.Add(new NoStr(0x0940,	1,	new CString("DIBBITBLT")));
	aFname.Add(new NoStr(0x0B41,	1,	new CString("DIBSTRETCHBLT")));
	aFname.Add(new NoStr(0x0142,	1,	new CString("DIBCREATEPATTERNBRUSH")));
	aFname.Add(new NoStr(0x0F43,	1,	new CString("STRETCHDIB")));
	aFname.Add(new NoStr(0x0548,	1,	new CString("EXTFLOODFILL")));
	aFname.Add(new NoStr(0x01F0,	1,	new CString("DELETEOBJECT")));
	aFname.Add(new NoStr(0x00F7,	1,	new CString("CREATEPALETTE")));
	aFname.Add(new NoStr(0x01F9,	1,	new CString("CREATEPATTERNBRUSH")));
	aFname.Add(new NoStr(0x02FA,	1,	new CString("CREATEPENINDIRECT")));
	aFname.Add(new NoStr(0x02FB,	1,	new CString("CREATEFONTINDIRECT")));
	aFname.Add(new NoStr(0x02FC,	1,	new CString("CREATEBRUSHINDIRECT")));
	aFname.Add(new NoStr(0x06FF,	1,	new CString("CREATEREGION")));
	wmfStatus = TRUE;
}

void wmfUninit() {
	aFname.RemoveAll();
	wmfStatus = FALSE;
}

CString wmfNameSearch(WORD fn) {
	if (!wmfStatus) wmfInit();

	CString retstr("!No Such Item!");
	int size = aFname.GetSize();

	for (int i = 0; i < size; i++) {
		if (aFname[i]->no == fn) {
			retstr = aFname[i]->str;
			break;
		}
	}
	CString nfn;
	nfn.Format("%04xh  ", fn);
	return nfn + retstr;
}

void wmfDecode(CDC *pDC, WORD fn, WORD *param, DWORD noparam) {
	static int y = 20;
	CString t;
	CPoint cp = pDC->GetCurrentPosition();

	t.Format("%d", noparam);
	pDC->TextOut(cp.x, cp.y, wmfNameSearch(fn) + "  " + t);
}


#include "stdafx.h"

#include "campoText.h"

UINT ctAlign::getWinAlign() {
	UINT r = 0;
	switch (h) {
	case left:		r |= TA_LEFT; break;
	case right:		r |= TA_RIGHT; break;
	case center:	r |= TA_CENTER; break;
	}
	switch (v) {
	case top:		r |= TA_TOP; break;
	case bottom:	r |= TA_BOTTOM; break;
	case baseline:	r |= TA_BASELINE; break;
	}
	return r;
}

ctElement::ctElement() {
	dir			= horizontal;
	position.x	= position.y = 0;
	align.h		= ctAlign::center;
	align.v		= ctAlign::top;
	o_font		= NULL;
	o_color		= (COLORREF)0;
	o_align		= 0;
	rgnEntire	= new CRgn;
	setEmptyRgn(rgnEntire);
}

CRgn *ctElement::setEmptyRgn(CRgn *rgn) {
	CRgn r;

	r.CreateRectRgn(0, 0, 1, 1);
		if (rgn->m_hObject)
			rgn->DeleteObject();
		rgn->CreateRectRgn(0, 0, 1, 1);
		rgn->CombineRgn(rgn, &r, RGN_AND);
	r.DeleteObject();
	return rgn;
}

BOOL ctElement::initDC(CDC *pDC) {
	CFont *cfont = new CFont;
	CPoint posFirstLine;

	if (!cfont->CreatePointFont(font.fontSize, font.fontName, pDC)) {
		delete cfont;
		return FALSE;
	}

	o_font = pDC->SelectObject(cfont);

	//program calc position byself, so needn't system's align support
	//juse align at topleft corner
	//o_align = pDC->SetTextAlign(align.getWinAlign());
	o_align = pDC->SetTextAlign(TA_LEFT | TA_TOP);

	o_color = pDC->SetTextColor(color.getWinColor());
	// direction is current unused
	return TRUE;
}

BOOL ctElement::initDC(HDC hDC) {
	CDC *pDC = new CDC;
	if (pDC->Attach(hDC)) {
		BOOL b = initDC(pDC);
		pDC->Detach();
		return b;
	}
	return FALSE;
}

BOOL ctElement::restoreDC(CDC *pDC) {
	CFont *last = pDC->SelectObject(o_font);
	delete last;

	pDC->SetTextAlign(o_align);
	pDC->SetTextColor(o_color);
	return TRUE;
}

BOOL ctElement::restoreDC(HDC hDC) {
	CDC *pDC = new CDC;
	BOOL b;
	if (pDC->Attach(hDC)) {
		b = restoreDC(pDC);
		pDC->Detach();
		return b;
	}
	return FALSE;
}

CRgn *ctElement::getExtent(CDC *pDC) {
	TEXTMETRIC	tm;
	int			baseLine = 0;
	POINT		posStart;				// identify start position of each line
	CSize		txtSize;				// text size returned by GetTextExtent
	CRect		txtRect;				// size with offset
	CRgn		*rgnRect = new CRgn;	// another "txtRect"

	int			i, nLines;

	nLines = text.GetSize();

	// !!! make two CRgn empty !!!
	setEmptyRgn(rgnRect);
	setEmptyRgn(rgnEntire);

	if (initDC(pDC)) {
		if (pDC->GetTextMetrics(&tm)) baseLine = tm.tmDescent;
		for (i = 0; i < nLines; i++) {
			txtSize = pDC->GetTextExtent(text.GetAt(i));
			switch (align.h) {
			case ctAlign::right:
				posStart.x = -txtSize.cx;
				break;
			case ctAlign::center:
				posStart.x = -txtSize.cx / 2;
				break;
			case ctAlign::left:
			default:
				posStart.x = 0;
			}
			if (i == 0) {
				switch (align.v) {
				case ctAlign::bottom:
					posStart.y = -txtSize.cy;
					break;
				case ctAlign::baseline:
					posStart.y = -baseLine;
					break;
				case ctAlign::top:
				default:
					posStart.y = 0;
				}
			} else // if i != 0
					posStart.y += txtSize.cy;

			if (dir == vertical) {
				txtRect.SetRect(0, 0, txtSize.cy, txtSize.cx);
				txtRect.OffsetRect(posStart.y, posStart.x);
			} else {
				txtRect.SetRect(0, 0, txtSize.cx, txtSize.cy);
				txtRect.OffsetRect(posStart.x, posStart.y);
			}
			rgnRect->SetRectRgn(txtRect);
			rgnEntire->CombineRgn(rgnEntire, rgnRect, RGN_OR);
		} // for i
		rgnEntire->OffsetRgn(position.x, position.y);
		delete rgnRect;
		restoreDC(pDC);
		return rgnEntire;
	} // if initDC
	return NULL;
}

CRgn *ctElement::getExtent(HDC hDC) {
	CDC *pDC = new CDC;
	CRgn *rgn;
	pDC->Attach(hDC);
	rgn = getExtent(pDC);
	pDC->Detach();
	return rgn;
}


void ctElement::draw(CDC *pDC) {
	int i, nLines;
	CPoint start;
	CSize txtSize;
	CRect txtRect;
	int baseLine = 0;
	TEXTMETRIC tm;

	nLines = text.GetSize();
	if (initDC(pDC)) {
		if (pDC->GetTextMetrics(&tm)) baseLine = tm.tmDescent;
		for (i = 0; i < nLines; i++) {
			txtSize = pDC->GetTextExtent(text.GetAt(i));
			switch (align.h) {
			case ctAlign::right:
				start.x = -txtSize.cx;
				break;
			case ctAlign::center:
				start.x = -txtSize.cx / 2;
				break;
			case ctAlign::left:
			default:
				start.x = 0;
			}
			if (i == 0) {
				switch (align.v) {
				case ctAlign::bottom:
					start.y = -txtSize.cy;
					break;
				case ctAlign::baseline:
					start.y = -baseLine;
					break;
				case ctAlign::top:
				default:
					start.y = 0;
				}
			} else // if i != 0
					start.y += txtSize.cy;

			if (dir == vertical) {
				int t = start.x;
				start.x = start.y;
				start.y = t;
			}

			// here put vertical drawing specifics
			pDC->TextOut(start.x + position.x, start.y + position.y, text.GetAt(i));
		} // for i
		restoreDC(pDC);
	} // if initDC
}

BOOL ctElement::draw(HDC hDC) {
	CDC *pDC = new CDC;
	if (pDC->Attach(hDC)) {
		draw(pDC);
		pDC->Detach();
		return TRUE;
	}
	return FALSE;
}

cText::cText() {
}

cText::cText(CArchive &ar) {
	cText();
	Load(ar);
}

cText::~cText() {
	textList.RemoveAll();
}

void cText::draw(CDC *pDC) {
	ctElement *item;
	POSITION pos;

	for (pos = textList.GetHeadPosition(); pos != NULL; textList.GetNext(pos)) {
		item = (ctElement *)textList.GetAt(pos);
		item->draw(pDC);
	}
}

BOOL cText::draw(HDC hDC) {
	CDC *pDC = new CDC;
	if (pDC->Attach(hDC)) {
		draw(pDC);
		pDC->Detach();
		return TRUE;
	}
	return FALSE;
}

//ctElement *cteVar;

ctElement *cText::getPointOn(CDC *pDC, POINT point) {
	ctElement *item;
	POSITION pos;

	for (pos = textList.GetHeadPosition(); pos != NULL; textList.GetNext(pos)) {
		item = (ctElement *)textList.GetAt(pos);
		if (item->getExtent(pDC)->PtInRegion(point)) {
			return item;
		}
	}
	return NULL;
}

ctElement *cText::getPointOn(HDC hDC, POINT point) {
	CDC *pDC = new CDC;
	ctElement *element;
	if (pDC->Attach(hDC)) {
		element = getPointOn(pDC, point);
		pDC->Detach();
		return element;
	}
	return NULL;
}

//cText::getElementsInRect(CDC *pDC, LPCRECT rect, BOOL includeCross) {
//	CRgn *rgnSpecify;

//	ctElement::setEmptyRgn(rgnSpecify);
//	rgnSpecify->SetRectRgn(rect);


BOOL cText::Load(CArchive &ar) {
	CString str;

	TRY {
		ar << str;
		if (cGetResourceType(str) != crText)
			return FALSE;
	} CATCH (CFileException, c) {
		if (c->m_cause != CFileException::endOfFile)
			return FALSE;
	} END_CATCH

	return TRUE;
}

BOOL cText::Save(CArchive &ar) {
	CString str;
	ctElement *item;
	POSITION pos;

	TRY {
		ar << cMakeCommandString(
			CCGENERAL_COMMANDCHAR,
			CCGENERAL_TYPE,
			CCGENERAL_STRINGCODE,
			CCTYPE_TEXT);
		ar << cMakeCommandString(
			CCGENERAL_COMMANDCHAR,
			CCGENERAL_VERSION,
			CCGENERAL_STRINGCODE,
			"1.00a");

		pos = textList.GetHeadPosition();
		item = (ctElement *)textList.GetHead();
		while (pos != NULL) {
			int i;
			// append element to file
			// implementation:: put it to a serialize function
			ar << cMakeCommandString(CCGENERAL_COMMANDCHAR, CCTEXT_POSITION)
				<< item->position.x
				<< item->position.y;
			ar << cMakeCommandString(CCGENERAL_COMMANDCHAR, CCTEXT_DIRECTION)
				<< item->dir;
			ar << cMakeCommandString(CCGENERAL_COMMANDCHAR, CCTEXT_ALIGN)
				<< item->align.h
				<< item->align.v;
			ar << cMakeCommandString(CCGENERAL_COMMANDCHAR, CCTEXT_COLOR)
				<< item->color.colorType
				<< item->color.color;
			ar << cMakeCommandString(CCGENERAL_COMMANDCHAR, CCTEXT_FONT)
				<< item->font.fontName
				<< item->font.fontSize
				<< item->font.fontBold
				<< item->font.fontItalic
				<< item->font.fontUnderline;
			ar << cMakeCommandString(CCGENERAL_COMMANDCHAR, CCTEXT_TEXT)
				<< item->text.GetSize();
			for (i = 0; i < item->text.GetSize(); i++)
				ar << item->text.GetAt(i);

			item = (ctElement *)textList.GetNext(pos);
		} // while !NULL
	} CATCH (CFileException, c) {
		return FALSE;
	} END_CATCH

	return TRUE;
}

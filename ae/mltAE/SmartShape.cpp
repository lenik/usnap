
#include "stdafx.h"
#include "SmartShape.h"

BOOL shape::setnpts(int npts) {
	if (npts < 0) return FALSE;
	if (npts == 0) {
		SAFE_DELETE_ARRAY(pts);
		m_npts = 0;
		m_nalloc = 0;
		return TRUE;
	}

	int nptsalloc = m_nalloc;
	if (npts > m_nalloc) {
		nptsalloc = npts | 7;
		if (pts) {
			pts = (point *)realloc(pts, sizeof(point) * nptsalloc);
		} else {
			pts = new point[nptsalloc];
		}
	}
	if (!pts) return FALSE;
	m_npts = npts;
	m_nalloc = nptsalloc;
	return TRUE;
}

BOOL SmartShapes_GDI::paint() {
	if (bPainted) return TRUE;
	if (m_nShapes <= 0) return TRUE;

	for (int ns = 0; ns < m_nShapes; ns++) {
		shape *ps = get_shapes() + ns;
		ASSERT(ps);

		int ipt;
		BOOL bSucc = TRUE;
		switch (ps->code) {
		case shape::none:
			break;
		case shape::pixel:
			for (ipt = 0; ipt < ps->m_npts; ipt++) {
				shape::point *pt = ps->pts + ipt;
				m_pEngine->fg_color = pt->color;
				bSucc = bSucc &&
					m_pEngine->Pixel(pt->x, pt->y);
			}
			break;
		case shape::seg:
			for (ipt = 0; ipt < ps->m_npts - 1; ipt += 2) {
				shape::point *pt = ps->pts + ipt;
				m_pEngine->fg_color = pt->color;
				bSucc = bSucc &&
					m_pEngine->Line(pt[0].x, pt[0].y, pt[1].x, pt[1].y);
			}
			break;
		case shape::line:
			if (ps->m_npts < 2) break;
			for (ipt = 0; ipt < ps->m_npts - 1; ipt++) {
				shape::point *pt = ps->pts + ipt;
				m_pEngine->fg_color = pt->color;
				bSucc = bSucc &&
					m_pEngine->Line(pt[0].x, pt[0].y, pt[1].x, pt[1].y);
			}
			break;
		case shape::star:
			if (ps->m_npts < 2) break;
			{
				shape::point *pt0 = ps->pts + 0;
				for (ipt = 1; ipt < ps->m_npts; ipt++) {
					shape::point *pt = ps->pts + ipt;
					m_pEngine->fg_color = pt->color;
					bSucc = bSucc &&
						m_pEngine->Line(pt0->x, pt0->y, pt->x, pt->y);
				}
			}
			break;
		case shape::tri:
			if (ps->m_npts < 3) break;
			for (ipt = 0; ipt < ps->m_npts - 2; ipt += 3) {
				shape::point *pt = ps->pts + ipt;
				m_pEngine->fg_color = pt->color;
				if (pt->flags.fill_group) {
					m_pEngine->fill_color = pt->color;
					m_pEngine->fill_style = 1;
				} else {
					m_pEngine->fill_style = 0;
				}
				bSucc = bSucc &&
					m_pEngine->Triangle(pt[0].x, pt[0].y, pt[1].x, pt[1].y, pt[2].x, pt[2].y);
			}
			break;
		case shape::trifan:
			if (ps->m_npts < 3) break;
			{
				shape::point *pt0 = ps->pts + 0;
				if (pt0->flags.fill_group) {
					m_pEngine->fill_color = pt0->color;
					m_pEngine->fill_style = 1;
				} else {
					m_pEngine->fill_style = 0;
				}
				for (ipt = 1; ipt < ps->m_npts - 1; ipt++) {
					shape::point *pt = ps->pts + ipt;
					m_pEngine->fg_color = pt->color;
					m_pEngine->fill_color = pt->color;
					bSucc = bSucc &&
						m_pEngine->Triangle(pt0->x, pt0->y, pt[0].x, pt[0].y, pt[1].x, pt[1].y);
				}
			}
			break;
		case shape::rect:
			if (ps->m_npts < 4) break;
			for (ipt = 0; ipt < ps->m_npts - 3; ipt = 4) {
				shape::point *pt = ps->pts + ipt;
				m_pEngine->fg_color = pt->color;
				if (pt->flags.fill_group) {
					m_pEngine->fill_color = pt->color;
					m_pEngine->fill_style = 1;
				} else {
					m_pEngine->fill_style = 0;
				}
				bSucc = bSucc &&
					m_pEngine->Rectangle(pt[0].x, pt[0].y, pt[1].x, pt[1].y,
					pt[2].x, pt[2].y, pt[3].x, pt[3].y);
			}
			break;
		case shape::ellipse:
			if (ps->m_npts < 4) break;
			for (ipt = 0; ipt < ps->m_npts - 3; ip t= 4) {
				shape::point *pt = ps->pts + ipt;
				m_pEngine->fg_color = pt->color;
				if (pt->flags.fill_group) {
					m_pEngine->fill_color = pt->color;
					m_pEngine->fill_style = 1;
				} else {
					m_pEngine->fill_style = 0;
				}
				bSucc = bSucc &&
					m_pEngine->Ellipse(pt[0].x, pt[0].y, pt[1].x, pt[1].y,
					pt[2].x, pt[2].y, pt[3].x, pt[3].y);
			}
			break;
		case shape::poly:
			if (ps->m_npts < 2) break;
			{
				m_pEngine->fg_color = ps->pts->color;
				if (ps->pts->flags.fill_group) {
					m_pEngine->fill_color = ps->pts->color;
					m_pEngine->fill_style = 1;
				} else {
					m_pEngine->fill_style = 0;
				}
				// bSucc = bSucc && m_pEngine->Poly(m_npts, pts)
				// not implemented yet.
				bSucc = FALSE;
			}
			break;
		case shape::bezier:
			if (ps->m_npts < 2) break;
			{
				m_pEngine->fg_color = ps->pts->color;
				if (ps->pts->flags.fill_group) {
					m_pEngine->fill_color = ps->pts->color;
					m_pEngine->fill_style = 1;
				} else {
					m_pEngine->fill_style = 0;
				}
				bSucc = bSucc &&
					m_pEngine->Bezier(ps->m_npts, ps->pts);
			}
			break;
		case shape::bezier2:
			// not implemented yet.
			bSucc = FALSE;
			break;
		case shape::nurb:
			// not implemented yet.
			bSucc = FALSE;
			break;
		default:
			ASSERT(FALSE);
		}
	return TRUE;
}

BOOL SmartShapes_GDI::clear() {
	return TRUE;
}


// SmartShapesCreator
BOOL SmartShapesCreator::Pixel(int x, int y) {

	return TRUE;
}
BOOL SmartShapesCreator::Line(int x0, int y0, int x1, int y1) {
	return TRUE;
}
BOOL SmartShapesCreator::Triangle(int x0, int y0, int x1, int y1, int x2, int y2) {
	return TRUE;
}
BOOL SmartShapesCreator::Rectangle(int x0, int y0, int x1, int y1) {
	return TRUE;
}
BOOL SmartShapesCreator::Bezier(int npts, int *pts) {
	return TRUE;
}
BOOL SmartShapesCreator::Ellipse(int x0, int y0, int x1, int y1) {
	return TRUE;
}

SmartShapesCreator::SmartShapesCreator(ISmartShapes *pBindShapes) {
	m_pshapes = pBindShapes;
};


// GraphEngine_RasterGDI
BOOL GraphEngine_RasterGDI::Pixel(int x, int y) {
	SetPixel(m_hDC, x, y, fg_color);
	return TRUE;
}
BOOL GraphEngine_RasterGDI::Line(int x0, int y0, int x1, int y1) {
	return MoveToEx(m_hDC, x0, y0, NULL) &&
		LineTo(m_hDC, x1, y1);
}
BOOL GraphEngine_RasterGDI::Triangle(int x0, int y0, int x1, int y1, int x2, int y2) {
	return MoveToEx(m_hDC, x0, y0, NULL) &&
		LineTo(m_hDC, x1, y1) &&
		LineTo(m_hDC, x2, y2) &&
		LineTo(m_hDC, x0, y0);
}
BOOL GraphEngine_RasterGDI::Rectangle(int x0, int y0, int x1, int y1) {
	return MoveToEx(m_hDC, x0, y0, NULL) &&
		LineTo(m_hDC, x1, y0) &&
		LineTo(m_hDC, x1, y1) &&
		LineTo(m_hDC, x0, y1) &&
		LineTo(m_hDC, x0, y0);
}
BOOL GraphEngine_RasterGDI::Bezier(int npts, int *pts) {
	POINT *_pts = new POINT[npts];
	if (!_pts) return FALSE;

	for (int i = 0; i < npts; i++) {
		_pts[i].x = *pts++;
		_pts[i].y = *pts++;
	}

	BOOL b_Bezier = ::PolyBezier(m_hDC, _pts, npts);

	delete[] _pts;
	return b_Bezier;
}
BOOL GraphEngine_RasterGDI::Ellipse(int x0, int y0, int x1, int y1) {
	int xmid = (x0 + x1) / 2;
	int ymid = (y0 + y1) / 2;
	return Arc(m_hDC, x0, y0, x1, y1,	x1, ymid, xmid, y0) &&
		Arc(m_hDC, x0, y0, x1, y1,	xmid, y0, x0, ymid) &&
		Arc(m_hDC, x0, y0, x1, y1,	x0, ymid, xmid, y1) &&
		Arc(m_hDC, x0, y0, x1, y1,	xmid, y1, x1, ymid);
}

BOOL GraphEngine_RasterGDI::UpdateTool() {
	if (m_hBrush) DeleteObject(m_hBrush);
	if (m_hPen) DeleteObject(m_hPen);
	LOGBRUSH brush;
	brush.lbColor = this->fill_color;
	brush.lbHatch = this->fill_graph;
	brush.lbStyle = this->fill_style;
	m_hBrush = ::CreateBrushIndirect(&brush);
	m_hPen = ::CreatePen(PS_SOLID, 1, this->fg_color);
	if (m_hBrush && m_hPen) {
		return TRUE;
	}
	if (m_hBrush) DeleteObject(m_hBrush);
	if (m_hPen) DeleteObject(m_hPen);
	return FALSE;
}

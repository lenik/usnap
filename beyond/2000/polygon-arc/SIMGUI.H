
#ifndef __SIMGUI_H
#define __SIMGUI_H

#include "graType.h"

#ifdef __MSDOS__
#include "graphics.h"
#endif

const double PI = 3.14159265358979;

class debugGraphics {

	int	dwWidth, dwHeight;
	int     dwDepth;

	typedef void (*DRAWPIXELFUNC)(const int, const int, const int);
	typedef void (*DRAWLINEFUNC)(const int, const int, const int, const int, const int);
	typedef void (*DRAWARCFUNC)(const int, const int, const double, const double, const int, const int, const int);

	DRAWPIXELFUNC	m_fPixel;
	DRAWLINEFUNC	m_fLine;
	DRAWARCFUNC	m_fArc;

public:

	void		init();
	void    	pixel(const int x, const int y, const int color) const;
	void		pixel(const CPoint& p, const int color) const { pixel(p.x, p.y, color); }
	void		line(const int x1, const int y1, const int x2, const int y2, const int color) const;
	void		line(const CPoint& p1, const CPoint& p2, const int color) const { line(p1.x, p1.y, p2.x, p2.y, color); }
	void		rect(const int x1, const int y1, const int x2, const int y2, const int color) const;
	void		rect(const CPoint& p1, const CPoint& p2, const int color) const { rect(p1.x, p1.y, p2.x, p2.y, color); }
	static void		circle(const int x, const int y, const int r, const int color) const;
	static void		circle(const CPoint& p, const int r, const int color) const { circle(p.x, p.y, r, color); }

	// for _DEBUG use
	static void	p_pixel(const int x, const int y, const int color) const;
	static void	p_circle5(const int x, const int y, const int color) const;
	static void	p_rect5(const int x, const int y, const int color) const;
	static void     l_line(const int x1, const int y1, const int x2, const int y2, const int color) const;
	static void     l_box5(const int x1, const int y1, const int x2, const int y2, const int color) const;
	static void	a_arc(const int x, const int y, const double sa, const double ea, const int xr, const int yr, const int color) const;
public:
	debugGraphics() {
		m_fPixel = (DRAWPIXELFUNC)p_pixel;
		m_fLine = (DRAWLINEFUNC)l_line;
		m_fArc = (DRAWARCFUNC)a_arc;
	}
};

#define debugPixel(x,y,c)		debugGraphics::p_circle5(x, y, c)
#define debugCircle(x,y,r,c)		debugGraphics::circle(x, y, r, c)
#define debugLine(x1,y1,x2,y2,c)	debugGraphics::l_line(x1, y1, x2, y2, c)
#define debugArc(x,y,r,s,e,c)		debugGraphics::a_arc(x, y, s, e, r, r, c)
#endif	// __SIMGUI_H

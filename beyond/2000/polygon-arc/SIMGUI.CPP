
#include "simGui.h"

#include <math.h>

void	debugGraphics::pixel(const int x, const int y, const int color) const {
	m_fPixel(x, y, color);
}
void	debugGraphics::line(const int x1, const int y1, const int x2, const int y2, const int color) const {
	m_fLine(x1, y1, x2, y2, color);
}
void 	debugGraphics::rect(const int x1, const int y1, const int x2, const int y2, const int color) const {
	debugGraphics g;
	g.line(x1, y1, x2, y1, color);
	g.line(x2, y1, x2, y2, color);
	g.line(x2, y2, x1, y2, color);
	g.line(x1, y2, x1, y1, color);
}
void	debugGraphics::circle(const int x, const int y, const int r, const int color) const {
	debugGraphics g;
	g.m_fArc(x, y, 0.0, PI * 2, r, r, color);
}

// static member functions

void	debugGraphics::p_pixel(const int x, const int y, const int color) const { putpixel(x, y, color); }
void	debugGraphics::p_circle5(const int x, const int y, const int color) const {
	debugGraphics g;
	g.circle(x, y, 5, color);
}
void	debugGraphics::p_rect5(const int x, const int y, const int color) const {
	debugGraphics g;
	g.rect(x - 2, y - 2, x + 2, y + 2, color);
}

#ifdef _DEBUG
#include <stdlib.h>
#include <complex.h>
#endif

void 	debugGraphics::l_line(const int x1, const int y1, const int x2, const int y2, const int color) const {
	int c = getcolor();
	setcolor(color);
	::line(x1, y1, x2, y2);
#ifdef _DEBUG
	const double trimlen = 10.0;
	const double rotangle = 0.45;
	double w = x1 - x2, h = y1 - y2;
	double L = sqrt(w * w + h * h);
	if (L < 0.1) return;
	else {
		double tx = x2 + (x1 - x2) * trimlen / L;
		double ty = y2 + (y1 - y2) * trimlen / L;
		double a, a1, a2;
		complex z = complex(w, h);
		a = arg(z); a1 = a - rotangle, a2 = a + rotangle;
		w = tx - x2; h = ty - y2;
		L = sqrt(w * w + h * h);
		::line(x2, y2, x2 + L * cos(a1), y2 + L * sin(a1));
		::line(x2, y2, x2 + L * cos(a2), y2 + L * sin(a2));
	}
#endif
	setcolor(c);
}

void 	debugGraphics::l_box5(const int x1, const int y1, const int x2, const int y2, const int color) const {
	int c = getcolor();
	setcolor(color);
	bar(x1 - 2, y1 - 2, x2 + 2, y2 + 2);
	setcolor(c);
}

void	debugGraphics::a_arc(const int x, const int y, const double sa, const double ea, const int xr, const int yr, const int color) const {
	int c = getcolor();
	setcolor(color);
	ellipse(x, y, sa * 180 / PI, ea * 180 / PI, xr, yr);
	setcolor(c);
}

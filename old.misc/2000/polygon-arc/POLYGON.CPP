
#include <iostream.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>
#include <stdio.h>
#include "polygon.h"
#include "simGui.h"

typedef struct __tag_doublev {
	int 	x;
	int	y;
} doublev;

static int	int_cmp_asc_f(const void *s1, const void *s2) {
	doublev *v1 = (doublev *)s1;
	doublev *v2 = (doublev *)s2;
	return v1->y > v2->y ? 1 : v1->y == v2->y ? 0 : -1;
}

static int	int_cmp_desc_f(const void *s1, const void *s2) {
	return -int_cmp_asc_f(s1, s2);
}

void	CPolygon::offset(const int x, const int y) {
	int proc = 0;
	for (; proc < this->getItemsInContainer(); proc++) {
		((CPoint&)(*this)[proc]).offset(x, y);
	}
}

class CPolygonEx : public CPolygon {
public:
	virtual void add(Object& toAdd);
};

	const int	IN_THE_CIRCLE	= 0;
	const int	GO_CIRCLE_IN 	= 100;
	const int	GO_CIRCLE_OUT 	= 101;

	const double	AREA_ERROR	= 3;

	const int	COLOR_DEBUG	= RED;
	const int	COLOR_SOLVE	= LIGHTGREEN;

void	CPolygon::intersect(const CPoint& c_o, const float c_r) const {
	// 1. build polygon'
	//	polygon' has points that in or cut the circle specified.

	CPolygonEx	p_;

	int		proc = 0, last = getItemsInContainer() - 1;
	int		nCount = last - proc + 1;

#ifdef _DEBUG
	draw(COLOR_DEBUG);
	debugCircle(c_o.x, c_o.y, c_r, COLOR_DEBUG);
#endif

	for (proc++; proc <= nCount; proc++) {
		CPoint	&pntProc	= (CPoint&)this->objectAt(proc % nCount),
			&pntProc_p	= (CPoint&)this->objectAt((proc + nCount - 1) % nCount);
			//&pntProc_n	= (CPoint&)this->objectAt((proc + 1) % nCount);

		double	k2, k1, k0;
		double	test;
		double	r1, r2;
		CPoint	cpp, cp;

		// calc status of line cut circle
		k2 = pow(pntProc.x - pntProc_p.x, 2) + pow(pntProc.y - pntProc_p.y, 2);
		k1 = (pntProc_p.x - c_o.x) * (pntProc.x - pntProc_p.x);
		k1 += (pntProc_p.y - c_o.y) * (pntProc.y - pntProc_p.y);
		k1 *= 2;
		k0 = pow(pntProc_p.x - c_o.x, 2) + pow(pntProc_p.y - c_o.y, 2) - c_r * c_r;
		test = k1 * k1 - 4 * k2 * k0;
		if (test >= 0) {
			r1 = (-k1 - sqrt(test)) / k2 / 2;
			r2 = (-k1 + sqrt(test)) / k2 / 2;
			cpp.x = pntProc_p.x + (pntProc.x - pntProc_p.x) * r1;
			cpp.y = pntProc_p.y + (pntProc.y - pntProc_p.y) * r1;
			cp.x = pntProc_p.x + (pntProc.x - pntProc_p.x) * r2;
			cp.y = pntProc_p.y + (pntProc.y - pntProc_p.y) * r2;
			pntProc_p.r1 = pntProc.r1 = cpp.r1 = cp.r1 = (proc + nCount - 1) % nCount;
			pntProc_p.r2 = pntProc.r2 = cpp.r2 = cp.r2 = proc % nCount;
		}
#ifdef _DEBUG
		if (test >= 0) {
			debugPixel(cpp.x, cpp.y, 7 + COLOR_DEBUG);
			if (r2 != r1) {
				debugPixel(cpp.x, cpp.y, COLOR_DEBUG);
				debugPixel(cp.x, cp.y, COLOR_DEBUG);
			}
		}
#endif
		if (test < 0) {
			// line is away from the circle
			// so ignore it
		} else if (test == 0) {
			#if INCLUDE_TAN
			#endif
			;	// here program throw tan edge
		} else {
			// delta > 0, extended-line is in or cut the circle
			// decides on CPn-1 and CPn (2 cut points of extended-line)
			if (r1 < 0) {
				// CPn-1 is left-away from line
				if (r2 <= 0) {
					// CPn is left-away from line, so line is out of the circle
				} else if (r2 <= 1) {
					// CPn is in line, 1-CUT
					// CPn --> go out of circle, cut is a P-out
					pntProc_p.tag = IN_THE_CIRCLE;
					cp.tag = GO_CIRCLE_OUT;
					p_.add((Object&)*new CPoint(pntProc_p));
					p_.add((Object&)*new CPoint(cp));
				} else {
					// CPn is right-away from line, so line is in the circle
					pntProc_p.tag = IN_THE_CIRCLE;
					p_.add((Object&)*new CPoint(pntProc_p));
				}
			} else if (r1 < 1) {
				// CPn-1 is in line, 1-CUT
				cpp.tag = GO_CIRCLE_IN;
				p_.add((Object&)*new CPoint(cpp));
				if (r2 <= 1) {
					// CPn is in line, 1-CUT again
					// CPn-1 --> go into circle, CPn --> go out of circle
					cp.tag = GO_CIRCLE_OUT;
					p_.add((Object&)*new CPoint(cp));
				} else {
					// CPn is right-away from line, no cut again
				}
			} else {
				// CPn-1 is right-away from line, so line is out of the circle
				// 	for that r2 is always >= r1, CPn is always right-hand of CPn-1
			}
		} // test 'test'
	} // for

	int	        count_p_ = p_.getItemsInContainer();
	if (count_p_ > 0) {
		// get overlapped region
		// split to two parts, one is discrete lines, one is discrete arcs

		// discrete lines:
		int 	p_last = count_p_ - 1;
		int 	last_proc = -1;
		for (proc = 0; proc <= p_last; proc++) {
			CPoint 	&pntProc = (CPoint&)p_[proc];
			if (last_proc >= 0) {
				debugLine(p_[last_proc].x, p_[last_proc].y,
					  pntProc.x, pntProc.y, COLOR_SOLVE);
			}
			last_proc = proc;
			if (pntProc.tag == GO_CIRCLE_OUT) {
				last_proc = -1;
				continue;
			}
		}

		// discrete arcs:
		CPolygon	p_l, p_r, p_int;
		doublev		*sort_t;
		for (proc = 0; proc <= p_last; proc++) {
			if (p_[proc].tag == IN_THE_CIRCLE) continue;
			if (p_[proc].x - c_o.x < 0) {
				p_l.add((Object&)p_[proc]);
			} else {
				p_r.add((Object&)p_[proc]);
			}
		}
		// asc-sort p_l by y-axis
		int	p_count, p_base;
		p_count = p_l.getItemsInContainer();
		p_base = 0;
		sort_t = new doublev[p_count];
		for (proc = 0; proc < p_count; proc++) {
			sort_t[proc].x = proc;
			sort_t[proc].y = p_l[proc + p_base].y;
		}
		qsort(sort_t, p_count, sizeof(doublev), int_cmp_asc_f);
		// process sorttable and append sorted points to p_int
		for (proc = 0; proc < p_count; proc++) {
			for (int occured = 0; occured < p_count; proc++)
				if (sort_t[occured].x == proc) break;
			p_int.add((Object&)p_l[occured]);
		}
		delete[] sort_t;

		p_count = p_r.getItemsInContainer();
		p_base = 0;
		sort_t = new doublev[p_count];
		for (proc = 0; proc < p_count; proc++) {
			sort_t[proc].x = proc;
			sort_t[proc].y = p_r[proc + p_base].y;
		}
		qsort(sort_t, p_count, sizeof(doublev), int_cmp_desc_f);
		// process sorttable and append sorted points to p_int
		for (proc = 0; proc < p_count; proc++) {
			for (int occured = 0; occured < p_count; proc++)
				if (sort_t[occured].x == proc) break;
			p_int.add((Object&)p_r[occured]);
		}
		delete[] sort_t;

		// now p_int contains all points in intersecion-arc
		// so link them
		int     shouldClosed = 0;
		int	skipping = 1;
		int	skipLastIndex = 0;
		int	proc_last = 0;
		p_count = p_int.getItemsInContainer();
		p_base = 0;
		for (proc = 0; proc < p_count; proc++) {
			CPoint &pntProc = (CPoint&)p_int[proc];
			CPoint &pntProc_p = (CPoint&)p_int[proc_last];
			if (pntProc.tag != GO_CIRCLE_OUT) {
				if (skipping) {
					// skipping leading GO_CIRCLE_IN or IN_THE_CIRCLE
					shouldClosed = 1;
					skipLastIndex = proc;
				} else {
					// pull out the arc in trims.
					double sa, se;
					complex z = complex(pntProc.x, pntProc.y);
					complex z_p = complex(pntProc_p.x, pntProc_p.y);
					complex o = complex(c_o.x, c_o.y);
					z -= o;
					z_p -= o;
					sa = arg(z_p);
					se = arg(z);
					debugArc(c_o.x, c_o.y, sa, se, c_r, COLOR_SOLVE);
				}
			} else {
				// for 1st found, disable skipping.
				skipping = 0;
			}
			proc_last = proc;
		}
		if (shouldClosed) {
			CPoint &pntProc = (CPoint&)p_int[proc_last];
			CPoint &pntProc_p = (CPoint&)p_int[skipLastIndex];
			double sa, se;
			complex z_p = complex(pntProc_p.x, pntProc_p.y);
			complex z = complex(pntProc.x, pntProc.y);
			complex o = complex(c_o.x, c_o.y);
			z_p -= o;
			z -= o;
			sa = -arg(z_p);
			se = -arg(z);
			debugArc(c_o.x, c_o.y, c_r, se, sa, COLOR_SOLVE);
		}
	} else {
		// test if Ocircle is in 'this' polygon
		double 	regularArea = 0;
		double 	outArea = 0;

		for (proc = 0; proc <= last; proc++) {
			CPoint	&pntProc	= (CPoint&)this->objectAt(proc),
				&pntProc_p	= (CPoint&)this->objectAt((proc + nCount - 1) % nCount),
				&pntProc_n	= (CPoint&)this->objectAt((proc + 1) % nCount);
			double	a, b, c, s, t_area;
			// add triangle area to regularArea
			// s = rounding length
			a = sqrt(pow(pntProc.x - pntProc_p.x, 2) + pow(pntProc.y - pntProc_p.y, 2));
			b = sqrt(pow(pntProc.x - pntProc_n.x, 2) + pow(pntProc.y - pntProc_n.y, 2));
			c = sqrt(pow(pntProc_n.x - pntProc_p.x, 2) + pow(pntProc_n.y - pntProc_p.y, 2));

			s = (a + b + c) / 2;
			t_area = sqrt(s * (s - a) * (s - b) * (s - c));
			regularArea += fabs(t_area);
			a = sqrt(pow(c_o.x - pntProc_p.x, 2) + pow(c_o.y - pntProc_p.y, 2));
			b = sqrt(pow(c_o.x - pntProc_n.x, 2) + pow(c_o.y - pntProc_n.y, 2));
			t_area = sqrt(s * (s - a) * (s - b) * (s - c));
			outArea += fabs(t_area);
		}
		if (fabs(outArea - regularArea) > AREA_ERROR) {
			// c_o is out of polygon, so no overlaps
		} else {
			// circle is in the polygon, the overlap is the circle itself.
			// N@
			debugCircle(c_o.x, c_o.y, c_r, COLOR_SOLVE);
		}
	} // if empty(p_)
}

void 	CPolygon::intersect(const CPolygon&) const {
}

void	CPolygon::draw(const int color) const {
	debugGraphics g;
#ifdef _DEBUG
	char buf[256];
#endif
	int c = this->getItemsInContainer();
	for (int i = 1; i <= c; i++) {
		CPoint &p1 = (CPoint&)(*this)[i - 1],
		       &p2 = (CPoint&)(*this)[i % c];
		g.line(p1, p2, color);
#ifdef _DEBUG
		outtextxy(p1.x + (p2.x - p1.x) / 2, p1.y + (p2.y - p1.y) / 2, ltoa(i, buf, 10));
#endif
	}
}

void 	CPolygonEx::add(Object& toAdd) {
#ifdef _DEBUG
	char buf[256];
	CPoint &p = (CPoint&)toAdd;
	setcolor(LIGHTGRAY);
	switch (p.tag) {
	case IN_THE_CIRCLE:
		sprintf(buf, "IN_THE_CIRCLE(%2.2f,%2.2f)", p.r1, p.r2);
		break;
	case GO_CIRCLE_IN:
		sprintf(buf, "GO_CIRCLE_IN(%2.2f,%2.2f)", p.r1, p.r2);
		break;
	case GO_CIRCLE_OUT:
		sprintf(buf, "GO_CIRCLE_OUT(%2.2f,%2.2f)", p.r1, p.r2);
		break;
	}
	outtextxy(p.x + 4, p.y + 4, buf);
	setcolor(YELLOW);
	outtextxy(p.x - 16, p.y - 8, ltoa(getItemsInContainer(), buf, 10));
	debugPixel(p.x, p.y, LIGHTBLUE);
#endif
	CPolygon::add(toAdd);
}

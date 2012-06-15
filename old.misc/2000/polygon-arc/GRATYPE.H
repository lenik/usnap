
#ifndef __GRATYPE_H
#define __GRATYPE_H

#include <Object.h>

class CPoint : Object {
public:
	virtual classType	isA() const { return 0; }
	virtual char *		nameOf() const { return "CPoint"; }
	virtual int 		isEqual(const Object&) const;
	virtual hashValueType	hashValue() const { return 0; }
	virtual void 		printOn(ostream&) const;
public:
	CPoint() : x(0), y(0) {}
	CPoint(float _x, float _y) : x(_x), y(_y) {}
	CPoint(const CPoint& o_o) : x(o_o.x), y(o_o.y), tag(o_o.tag), r1(o_o.r1), r2(o_o.r2) {}
public:
	virtual void		offset(const int x, const int y);
public:
	float	x;
	float	y;
	long	tag;
	float	r1, r2;
};
typedef CPoint POINT, *LPPOINT;

#endif // __GRATYPE_H

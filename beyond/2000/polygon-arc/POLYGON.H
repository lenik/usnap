
#ifndef __POLYGON_H
#define __POLYGON_H

#define interface	struct

#include <Array.h>
#define DEFAULT_UPPER	32

#include "graType.h"

class CPolygon : public Array {
public:
	virtual classType	isA() const { return 0; }
	virtual char *		nameOf() const { return "CPolygon"; }
	virtual hashValueType	hashValue() const { return 0; }

	virtual CPoint&		operator [] (int atIndex) const { return (CPoint&)this->objectAt(atIndex); }

public:
	virtual void		offset(const int x, const int y);

public:
	virtual void		intersect(const CPolygon&) const;
	virtual void		intersect(const CPoint&, const float) const;

public:
	virtual void		draw(const int) const;

public:
	CPolygon() : Array(DEFAULT_UPPER) {}
};

#endif // __POLYGON_H


#include "graType.h"

int	CPoint::isEqual(const Object& o) const {
	CPoint &p = (CPoint&)o;
	return p.x == x && p.y == y && p.tag == tag;
}

void	CPoint::printOn(ostream& os) const {
	os 	<< "x = " << x << endl
		<< "y = " << y << endl
		<< "tag:" << tag << endl;
}

void 	CPoint::offset(const int _x, const int _y) {
	x += _x;
	y += _y;
}

#include "TGDefs.h"

TPoint::TPoint() {
  x = y = 0;
}
TPoint::TPoint(int _x, int _y) {
  x = _x;
  y = _y;
}
TPoint::TPoint(const TPoint& _Point) {
  x = _Point.x;
  y = _Point.y;
}

TPoint TPoint::operator = (TPoint _Assign) {
  x = _Assign.x;
  y = _Assign.y;
  return *this;
}

TPoint TPoint::operator += (TPoint adder) {
  x += adder.x;
  y += adder.y;
  return *this;
}
TPoint TPoint::operator -= (TPoint subber) {
  x -= subber.x;
  y -= subber.y;
  return *this;
}

TPoint operator + (TPoint one, TPoint two) {
  return TPoint (two.x + one.x, two.y + one.y);
}
TPoint operator - (TPoint one, TPoint two) {
  return TPoint (two.x - one.x, two.y - one.y);
}

int operator == (TPoint one, TPoint two) {
  return one.x == two.x && one.y == two.y;
}
int operator != (TPoint one, TPoint two) {
  return one.x != two.x || one.y != two.y;
}

TPoint3D::TPoint3D() {
  x = y = z = 0;
}
TPoint3D::TPoint3D(int _x, int _y, int _z) {
  x = _x;
  y = _y;
  z = _z;
}
TPoint3D::TPoint3D(const TPoint3D& _Point3D) {
  x = _Point3D.x;
  y = _Point3D.y;
  z = _Point3D.z;
}

TPoint3D TPoint3D::operator = (TPoint3D _Assign) {
  x = _Assign.x;
  y = _Assign.y;
  y = _Assign.z;
  return *this;
}

TPoint3D TPoint3D::operator += (TPoint3D adder) {
  x += adder.x;
  y += adder.y;
  z += adder.z;
  return *this;
}
TPoint3D TPoint3D::operator -= (TPoint3D subber) {
  x -= subber.x;
  y -= subber.y;
  z -= subber.z;
  return *this;
}

TPoint3D operator + (TPoint3D one, TPoint3D two) {
  return TPoint3D (two.x + one.x, two.y + one.y, two.z + one.z);
}
TPoint3D operator - (TPoint3D one, TPoint3D two) {
  return TPoint3D (two.x - one.x, two.y - one.y, two.z - one.z);
}

int operator == (TPoint3D one, TPoint3D two) {
  return one.x == two.x && one.y == two.y && one.z == two.z;
}
int operator != (TPoint3D one, TPoint3D two) {
  return one.x != two.x || one.y != two.y || one.z != two.z;
}

TRect::TRect() {
  Init();
}
TRect::TRect(int ax, int ay, int bx, int by) {
  TRect();
  a.x = ax;
  a.y = ay;
  b.x = bx;
  b.y = by;
}
TRect::TRect(TPoint _TLeft, TPoint _BottomRight) {
  TRect();
  a = _TLeft;
  b = _BottomRight;
}
TRect::TRect(const TRect& _Rect) {
  TRect();
  a = _Rect.a;
  b = _Rect.b;
}
void TRect::Init() {
  Left = &a.x; Top = &a.y; Right = &b.x; Bottom = &b.y;
}

Byte TRect::operator == (TRect _Rect) {
  return a == _Rect.a && b == _Rect.b;
}
Byte TRect::operator != (TRect _Rect) {
  return a != _Rect.a || b != _Rect.b;
}

Byte TRect::IsEmpty() {
  return a.x > b.x||a.y > b.y;
}
Byte TRect::Contains(TPoint _Point) {
  return a.x<=_Point.x&&a.y<=_Point.y&&b.x>=_Point.x&&b.y>=_Point.y;
}

void TRect::Move(int _MoveX, int _MoveY) {
  TPoint _MovePoint(_MoveX, _MoveY);
  a += _MovePoint;
  b += _MovePoint;
}
void TRect::Move(TPoint _MovePoint) {
  a += _MovePoint;
  b += _MovePoint;
}
void TRect::Grow(int _GrowX, int _GrowY) {
  TPoint _GrowPoint(_GrowX, _GrowY);
  a -= _GrowPoint;
  b += _GrowPoint;
}
void TRect::Intersect(TRect _Rect) {
  a.x = (a.x > _Rect.a.x) ? a.x : _Rect.a.x;
  a.y = (a.y > _Rect.a.y) ? a.y : _Rect.a.y;
  b.x = (b.x < _Rect.b.x) ? b.x : _Rect.b.x;
  b.y = (b.y < _Rect.b.y) ? b.y : _Rect.b.y;
}
void TRect::Union(TRect _Rect) {
  a.x = (a.x < _Rect.a.x) ? a.x : _Rect.a.x;
  a.y = (a.y < _Rect.a.y) ? a.y : _Rect.a.y;
  b.x = (b.x > _Rect.b.x) ? b.x : _Rect.b.x;
  b.y = (b.y > _Rect.b.y) ? b.y : _Rect.b.y;
}

TWindowRegion::TWindowRegion() {
  Parent = NULL;
  Image = NULL;
}
TWindowRegion::TWindowRegion(int _Left, int _Top, int _Right, int _Bottom) {
  Actual.Left	= Alter.Left	= _Left;
  Actual.Top	= Alter.Top	= _Top;
  Actual.Right	= Alter.Right	= _Right;
  Actual.Bottom	= Alter.Bottom	= _Bottom;
}
TWindowRegion::TWindowRegion(TPoint _TopLeft, TPoint _BottomRight) {
  TWindowRegion(_TopLeft.x, _TopLeft.y, _BottomRight.x, _BottomRight.y);
}
TWindowRegion::TWindowRegion(const TWindowRegion& _Region) {
  Actual.Left	= _Region.Actual.Left;
  Actual.Top	= _Region.Actual.Top;
  Actual.Right	= _Region.Actual.Right;
  Actual.Bottom	= _Region.Actual.Bottom;
  Alter.Left	= _Region.Alter.Left;
  Alter.Top	= _Region.Alter.Top;
  Alter.Right	= _Region.Alter.Right;
  Alter.Bottom	= _Region.Alter.Bottom;
  Parent	= _Region.Parent;
  Image		= _Region.Image;
}
TWindowRegion::~TWindowRegion() {
}
void TWindowRegion::Move(int _MoveX, int _MoveY) {
  Actual.Left += _MoveX;
  Actual.Right += _MoveX;
  Actual.Top += _MoveY;
  Actual.Bottom += _MoveY;
}

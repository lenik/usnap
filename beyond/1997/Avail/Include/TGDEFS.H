#ifndef __TGDEFS_H

#define __TGDEFS_H

#include "TType.h"
#include "TString.h"

struct TPoint{
  int x, y;

  TPoint();
  TPoint(int _x, int _y);
  TPoint(const TPoint &_Point);

  TPoint operator = (TPoint _Assign);

  TPoint operator += (TPoint adder);
  TPoint operator -= (TPoint subber);
  friend TPoint operator + (TPoint one, TPoint two);
  friend TPoint operator - (TPoint one, TPoint two);
  friend int operator == (TPoint one, TPoint two);
  friend int operator != (TPoint one, TPoint two);
};

struct TPoint3D{
  int x, y, z;

  TPoint3D();
  TPoint3D(int _x, int _y, int _z);
  TPoint3D(const TPoint3D &_Point3D);

  TPoint3D operator = (TPoint3D _Assign);

  TPoint3D operator += (TPoint3D adder);
  TPoint3D operator -= (TPoint3D subber);
  friend TPoint3D operator + (TPoint3D one, TPoint3D two);
  friend TPoint3D operator - (TPoint3D one, TPoint3D two);
  friend int operator == (TPoint3D one, TPoint3D two);
  friend int operator != (TPoint3D one, TPoint3D two);
};

struct TRect{
  TPoint a, b;
  int *Left, *Top, *Right, *Bottom;

  TRect();
  TRect(int ax, int ay, int bx, int by);
  TRect(TPoint _TLeft, TPoint _BottomRight);
  TRect(const TRect &_Rect);
  void Init();

  Byte operator == (TRect _Rect);
  Byte operator != (TRect _Rect);

  Byte IsEmpty();
  Byte Contains(TPoint _Point);

  void Move(int _MoveX, int _MoveY);
  void Move(TPoint _MovePoint);
  void Grow(int _GrowX, int _GrowY);
  void Intersect(TRect _Rect);
  void Union(TRect _Rect);
};

struct TWindowRegion{
  TWindowRegion *Parent;
  struct __twr__Region{
    Word Left, Top, Right, Bottom;
  }Actual, Alter;
  TStringClass *Image;
  // Alter was initialized same as Actual.
  TWindowRegion();
  TWindowRegion(int _Left, int _Top, int _Right, int _Bottom);
  TWindowRegion(TPoint _TopLeft, TPoint _BottomRight);
  TWindowRegion(const TWindowRegion& _Region);
  ~TWindowRegion();
  // Operates on Actual Region.
  void Move(int _MoveX, int _MoveY);
};

struct TColor{
  struct __tc__simcolor{
    Byte Fore, Back;
  }Normal, Contrast, Ground;
};

#endif  //  __TGDEFS_H

// TOP GRAPHICS ALGORITHM CLASS
// DANSEI 1998.11.27

#ifndef __TGALGOR_H

  #define __TGALGOR_H

  #include "TGDefs.h"

  class TSpace2D {
  public:
    TPoint BasePoint;
    TPoint TransPoint;
  public:
    TSpace2D (TPoint _Base, TPoint _Trans);
  public:
    TPoint Move (int _x, int _y);
    TPoint Scale (float _ratiox, float _ratioy);
    TPoint Rotate (float _angle);
    TPoint Slip (float _MA, float _MB, float _MC, float _MD);
  };

  class TSpace3D {
  public:
    TPoint3D BasePoint;
    TPoint3D TransPoint;
  public:
    TSpace3D (TPoint3D _Base, TPoint3D _Trans);
  public:
    TPoint3D Move (int _x, int _y, int _z);
    TPoint3D Scale (float _ratiox, float _ratioy, float _ratioz);
    TPoint3D Rotate (float _anglex, float _angley, float _anglez);
  };

#endif	// __TGALGOR_H
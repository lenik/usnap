// TOP GRAPHICS ALGORITHM CLASS
// DANSEI 1998.11.27

#include <math.h>

#include "TGAlgor.h"

TSpace2D::TSpace2D (TPoint _Base, TPoint _Trans) {
  BasePoint = _Base;
  TransPoint = _Trans;
}

TPoint TSpace2D::Move (int _x, int _y) {
  return TPoint (TransPoint.x + _x, TransPoint.y + _y);
}

TPoint TSpace2D::Scale (float _ratiox, float _ratioy) {
  return TPoint (
    BasePoint.x + (TransPoint.x - BasePoint.x) * _ratiox,
    BasePoint.y + (TransPoint.y - BasePoint.y) * _ratioy
  );
}

TPoint TSpace2D::Rotate (float _angle) {
  TPoint _RetPoint = TransPoint - BasePoint;
  _RetPoint.x = _RetPoint.x * cos (_angle) + _RetPoint.y * sin (_angle);
  _RetPoint.y = -_RetPoint.x * sin (_angle) + _RetPoint.y * cos (_angle);
  return _RetPoint + BasePoint;
}

TPoint TSpace2D::Slip (float _MA, float _MB, float _MC, float _MD) {
  TPoint _RetPoint = TransPoint - BasePoint;
  TPoint _OriPoint = _RetPoint;
  /* Multipling Point with Matrix:
     | a b | * [X Y] = [aX + cY   bX + dY]
     | c d |
  */
  _RetPoint.x = _MA * _OriPoint.x + _MC * _OriPoint.y;
  _RetPoint.y = _MB * _OriPoint.x + _MD * _OriPoint.y;
  return _RetPoint + BasePoint;
}

TSpace3D::TSpace3D (TPoint3D _Base, TPoint3D _Trans) {
  BasePoint = _Base;
  TransPoint = _Trans;
}

TPoint3D TSpace3D::Move (int _x, int _y, int _z) {
  return TPoint3D (TransPoint.x + _x, TransPoint.y + _y, TransPoint.z + _z);
}

TPoint3D TSpace3D::Scale (float _ratiox, float _ratioy, float _ratioz) {
  return TPoint3D (
    BasePoint3D.x + (TransPoint3D.x - BasePoint3D.x) * _ratiox,
    BasePoint3D.y + (TransPoint3D.y - BasePoint3D.y) * _ratioy,
    BasePoint3D.z + (TransPoint3D.z - BasePoint3D.z) * _ratioz
  );
}

TPoint3D TSpace3D::Rotate (float _anglex, float _angley, float _anglez) {
  TPoint3D _RetPoint3D = TransPoint3D - BasePoint3D;
  TPoint3D _OriPoint3D = _RetPoint3D;

  _RetPoint3D.x = _OriPoint3D.x * cos (_angley) - _OriPoint3D.z * sin (_angley);
  _RetPoint3D.z = _OriPoint3D.x * sin (_angley) + _OriPoint3D.z * sin (_angley);
  _RetPoint3D.y = _RetPoint3D.z * sin (_anglex) + _OriPoint3D.y * cos (_anglex);
  _RetPoint3D.z = _RetPoint3D.z * cos (_anglex) - _OriPoint3D.y * sin (_anglex);
  _OriPoint3D.x = _RetPoint3D.x;
  _RetPoint3D.x = _RetPoint3D.y * sin (_anglez) + _OriPoint3D.x * cos (_anglez);
  _RetPoint3D.y = _RetPoint3D.y * cos (_anglez) - _OriPoint3D.x * sin (_anglez);

  return _RetPoint3D + BasePoint3D;
}

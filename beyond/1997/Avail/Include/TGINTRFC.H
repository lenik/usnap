#ifndef __TGINTRFC_H

#define __TGINTRFC_H

#include "TGDefs.h"

class TGraphInterface{
public:
  TopWindowRegion Window;
  TopPoint CurPos;
  TopColor ScreenColor;
  TopColor WindowColor;
  TStringChain Palette;	// 256 Units
public:
  TopRect Fake;
  enum {Direct=0, And, Or, Xor, Add, Sub}DrawMode;
public:
  struct __tgi__Dither{
    Byte Strength;
    Word Influence;
  }Dither;
public:
  class __tgi__Modify{
  public:
    Byte WindowLink; /* =1: Window modified after functions called. */

    TopPoint Center;
    TopRect InRect;
    Byte Fusion; /* =1: NoMissing */

    // Shift functions. Each function returns lines actually shifted.
    // Using:	Fake	InRect
    Byte Shift(int _ShiftX, int _ShiftY);
    Byte ShiftCycle(int _ShiftX, int _ShiftY);
    Byte shl(), shr(), shu(), shd();
    Byte rol(), ror(), rou(), rod();
    // Scale functions. Each function returns the rect after call.
    // Using:	Fake	Fusion	InRect
    TopRect Scale(float _RatioX, float _RatioY);
    TopRect Scale(TRect _FormRect);
    // Rotate functions.
    // Using:	Fake	Fusion	Center	InRect
    void Rotate(float Angle);
    // Flip functions.
    // Using:	Fake	InRect
    void Flip(int _FlipLeft, int _FlipTop, int _FlipRight, int _FlipBottom);
  }Modify;
public:
  class __tgi__Draw{
  public:
    TopColor DrawColor;
    Byte LineMask;
    enum InternalLinkMask{SolidLine=0xFF, DottedLine=0x55, CenterLine=0xFA, DashedLine=0xFC};
    Byte Fill, FillColor;
    TStringChain FillMask, FillPattern;
  public:
    void Init(Byte Mode);
  public:
    void SetFillStyle(TopRect _PatternRect, Byte **_FillMask, Byte **_FillPattern);
  public:
    Byte GetPoint(int _X, int _Y);
    Byte GetPoint(TopPoint _Point);
    void SetPoint(int _X, int _Y);
    void SetPoint(TopPoint _Point);
  public:
    void Line(int _X1, int _Y1, int _X2, int _Y2);
    void Line(TopPoint _Point1, TopPoint _Point2);
    void Rect(int _Left, int _Top, int _Right, int _Bottom);
    void Rect(TopPoint _LeftTop, TopPoint _RightBottom);
    void Rect(TopRect _Rect);
    void Bar(int _Left, int _Top, int _Right, int _Bottom);
    void Bar(TopPoint _LeftTop, TopPoint _RightBottom);
    void Bar(TopRect _Rect);
  public:
    void Poly(TopPoint *_EndPoints, Word _EndPointNum);
  public:
    void Circle(int _CenterX, int _CenterY, Word _Radius);
    void Circle(TopPoint _Center, Word _Radius);
    void Ellipse(int _CenterX, int _CenterY, Word _Radius, float _RatioX, float _RatioY);
    void Ellipse(TopPoint _Center, Word _Radius, float _RatioX, float _RatioY);
    void Ellipse(int _Left, int _Top, int _Right, int _Bottom);
    void Ellipse(TopRect _EllipseRect);

    void CirArc(int _CenterX, int _CenterY, Word _Radius, float _Start, float _End);
    void CirArc(TopPoint _Center, Word _Radius, float _Start, float _End);
    void EllArc(int _CenterX, int _CenterY, Word _Radius, float _Start, float _End, float _RatioX, float _RatioY);
    void EllArc(TopPoint _Center, Word _Radius, float _Start, float _End, float _RatioX, float _RatioY);
    void EllArc(int _Left, int _Top, int _Right, int _Bottom, float _Start, float _End);
    void EllArc(TopRect _EllipseRect, float _Start, float _End);
  public:
    void TextOut(TStringChain _Text);	// Each char in TStringChain take 2 BYTES, the First is Char and the other is Attribute.
    void TextOutXY(int _X, int _Y, TStringChain, _Text);
  public:
    void FloodFill(int _X, int _Y, Byte _Fill);
    void FloodFill(TopPoint _FillPoint, Byte _Fill);
  }Draw;
public:
  class __tgi__ArtDraw{
    ;
  }ArtDraw;
};

#endif
Attribute VB_Name = "modMSIMG32"

Public Const AC_SRC_OVER = &H0

Public Const AC_SRC_NO_PREMULT_ALPHA = &H1
Public Const AC_SRC_NO_ALPHA = &H2
Public Const AC_DST_NO_PREMULT_ALPHA = &H10
Public Const AC_DST_NO_ALPHA = &H20

Public Type BLENDFUNCTION
    BlendOp As Byte             'Specifies the source blend operation. Currently, the only source and destination blend operation that has been defined is AC_SRC_OVER. For details, see the following Remarks section.
    BlendFlags As Byte          'Must be zero.
    SourceConstantAlpha As Byte 'Specifies an alpha transparency value to be used on the entire source bitmap. The SourceConstantAlpha value is combined with any per-pixel alpha values in the source bitmap. If you set SourceConstantAlpha to 0, it is assumed that your image is transparent. Set the SourceConstantAlpha value to 255 (opaque) when you only want to use per-pixel alpha values.
    AlphaFormat As Byte
End Type

Declare Function AlphaBlend Lib "MSIMG32" ( _
    ByVal hdcDst As Long, ByVal nXOriginDst As Integer, ByVal nYOriginDst As Integer, ByVal nWidthDst As Integer, ByVal hHeightDst As Integer, _
    ByVal hdcSrc As Long, ByVal nXOriginSrc As Integer, ByVal nYOriginSrc As Integer, ByVal nWidthSrc As Integer, ByVal nHeightSrc As Integer, _
    bfBlendFunction As BLENDFUNCTION) As Long

Declare Function TransparentBlt Lib "MSIMG32" ( _
    ByVal hdcDst As Long, ByVal nXOriginDst As Integer, ByVal nYOriginDst As Integer, ByVal nWidthDst As Integer, ByVal hHeightDst As Integer, _
    ByVal hdcSrc As Long, ByVal nXOriginSrc As Integer, ByVal nYOriginSrc As Integer, ByVal nWidthSrc As Integer, ByVal nHeightSrc As Integer, _
    ByVal crTransparent As Long) As Long

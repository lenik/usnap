Attribute VB_Name = "modEasyImage"
Option Explicit

Type IPOINT
        X As Double
        Y As Double
End Type

Type IRECT
        Left As Double
        Top As Double
        width As Double
        height As Double
End Type

Public Function ComposeRGB(ByVal r As Long, ByVal g As Long, ByVal b As Long, Optional ByVal res As Long = 0) As Long
        If r < 0 Or r > 255 Then r = 0
        If g < 0 Or g > 255 Then g = 0
        If b < 0 Or b > 255 Then b = 0
        If res < 0 Or res > 255 Then res = 0

        ComposeRGB = r * &H10000 + g * &H100 + b
        ComposeRGB = res * &H1000000 + ComposeRGB
End Function
Public Function ComposeRGB2(rgbq As RGBQUAD) As Long
        ComposeRGB2 = ComposeRGB(rgbq.rgbRed, rgbq.rgbGreen, rgbq.rgbBlue, rgbq.rgbReserved)
End Function
Public Function DisposeRGB(ByVal rgb As Long) As RGBQUAD
        DisposeRGB.rgbRed = (rgb And &HFF0000) / &H10000
        DisposeRGB.rgbGreen = (rgb And &HFF00&) / &H100&
        DisposeRGB.rgbBlue = rgb And &HFF&
        DisposeRGB.rgbReserved = (rgb And &HFF000000) / &H1000000
End Function

Public Function MidRGB(ByVal rgb1 As Long, ByVal rgb2 As Long, Optional ByVal Bias As Double = 0.5) As Long
        Dim rq1 As RGBQUAD, rq2 As RGBQUAD, rq3 As RGBQUAD
        rq1 = DisposeRGB(rgb1)
        rq2 = DisposeRGB(rgb2)
        rq3.rgbRed = rq1.rgbRed + (rq2.rgbRed - rq1.rgbRed) * Bias
        rq3.rgbGreen = rq1.rgbGreen + (rq2.rgbGreen - rq1.rgbGreen) * Bias
        rq3.rgbBlue = rq1.rgbBlue + (rq2.rgbBlue - rq1.rgbBlue) * Bias
        rq3.rgbReserved = rq1.rgbReserved + (rq2.rgbReserved - rq1.rgbReserved) * Bias
        MidRGB = ComposeRGB(rq3.rgbRed, rq3.rgbGreen, rq3.rgbBlue, rq3.rgbReserved)
End Function

' 保存场景中相应块至备份场景, 然后在场景中画hdcObject
' hdcScene      目标场景
' hdcSceneBak   备份场景
' destRect      目标大小. 如果不伸缩, destRect的宽和高无效
' hdcObject     绘画实体
' srcRect       原实体绘画区域
' hdcObjectMask 屏蔽实体 非0时对绘画区域中进行屏蔽, 且屏蔽区域同srcRect
' bStretch      使用伸缩. 将 srcRect的长和宽 变换至 destRect的长和宽
Public Function ExchangeBlock( _
        ByVal hdcScene As Long, _
        ByVal hdcSceneBak As Long, _
        destRect As IRECT, _
        ByVal hdcObject As Long, _
        srcRect As IRECT, _
        Optional hdcObjectMask As Long = 0, _
        Optional ByVal bStretch As Boolean = False) As Boolean

        Dim r As Boolean
        Dim rasop As Long

        ' 备份
        If Not bStretch Then
                destRect.width = srcRect.width
                destRect.height = srcRect.height
        End If
        r = BitBlt( _
                hdcSceneBak, destRect.Left, destRect.Top, destRect.width, destRect.height, _
                hdcScene, destRect.Left, destRect.Top, _
                SRCCOPY)

        ' 若指定屏蔽, 首先做屏蔽
        If hdcObjectMask <> 0 Then
                If bStretch Then
                        r = StretchBlt( _
                                hdcScene, destRect.Left, destRect.Top, destRect.width, destRect.height, _
                                hdcObjectMask, srcRect.Left, srcRect.Top, srcRect.width, srcRect.height, _
                                SRCPAINT)
                Else
                        r = BitBlt( _
                                hdcScene, destRect.Left, destRect.Top, destRect.width, destRect.height, _
                                hdcObjectMask, srcRect.Left, srcRect.Top, _
                                SRCPAINT)
                End If
        End If

        ' 画hdcObject. 如果有屏蔽则使用AND, 否则使用COPY
        rasop = IIf(hdcObjectMask <> 0, SRCAND, SRCCOPY)
        If bStretch Then
                r = StretchBlt( _
                        hdcScene, destRect.Left, destRect.Top, destRect.width, destRect.height, _
                        hdcObject, srcRect.Left, srcRect.Top, srcRect.width, srcRect.height, _
                        rasop)
        Else
                r = BitBlt( _
                        hdcScene, destRect.Left, destRect.Top, destRect.width, destRect.height, _
                        hdcObject, srcRect.Left, srcRect.Top, _
                        rasop)
        End If

        ExchangeBlock = r
End Function

' 恢复备份场景中的块至目标场景
' hdcScene      目标场景
' hdcSceneBak   备份场景
' destRect      上次保存的目标区域
' hdcObject     未使用
' srcRect       上次使用的原区域, 结合bStretch方便恢复伸缩块
' bStretch      上次使用的伸缩参数
Public Function RestoreBlock( _
        ByVal hdcScene As Long, _
        ByVal hdcSceneBak As Long, _
        destRect As IRECT, _
        ByVal hdcObject As Long, _
        srcRect As IRECT, _
        Optional ByVal bStretch As Boolean = False) As Boolean

        Dim r As Boolean
        If Not bStretch Then
                destRect.width = srcRect.width
                destRect.height = srcRect.height
        End If

        r = BitBlt( _
            hdcScene, destRect.Left, destRect.Top, destRect.width, destRect.height, _
            hdcSceneBak, destRect.Left, destRect.Top, _
            SRCCOPY)
End Function

Public Function ExchangeBlock_Pic(picScene As PictureBox, picSceneBak As PictureBox, destRect As IRECT, picObject As PictureBox, Optional picObjectMask As PictureBox = Nothing, Optional ByVal bStretch As Boolean = False) As Boolean
        Dim srcRect As IRECT
        Dim hdcMask As Long

        srcRect.Left = 0
        srcRect.Top = 0
        srcRect.width = picObject.width
        srcRect.height = picObject.height

        If Not picObjectMask Is Nothing Then
                hdcMask = picObjectMask.hdc
        Else
                hdcMask = 0
        End If

        ExchangeBlock_Pic = ExchangeBlock( _
                picScene.hdc, picSceneBak.hdc, destRect, _
                picObject.hdc, srcRect, _
                hdcMask, _
                bStretch)
End Function

Public Function RestoreBlock_pic(picScene As PictureBox, picSceneBak As PictureBox, destRect As IRECT, picObject As PictureBox, Optional ByVal bStretch As Boolean = False) As Boolean
    Dim srcRect As IRECT
    Dim r As Boolean

    srcRect.Left = 0
    srcRect.Top = 0
    srcRect.width = picObject.width
    srcRect.height = picObject.height

    r = RestoreBlock(picScene.hdc, picSceneBak.hdc, destRect, picObject.hdc, srcRect, bStretch)
End Function

Public Function GradientBox_Corner(ByVal hdc As Long, ByVal X1 As Double, ByVal Y1 As Double, ByVal X2 As Double, ByVal Y2 As Double, ByVal c1 As Long, ByVal c2 As Long) As Boolean
        Dim V(0 To 3) As TRIVERTEX
        Dim gTri(0 To 1) As GRADIENT_TRIANGLE
        Dim w As Double, h As Double, l As Double
        Dim rgb As RGBQUAD

        w = X2 - X1
        h = Y2 - Y1
        l = Sqr(w * w + h * h)

        V(0).X = X1
        V(0).Y = Y1
        V(0).Red = toWord(DisposeRGB(c1).rgbRed * &H100&)
        V(0).Green = toWord(DisposeRGB(c1).rgbGreen * &H100&)
        V(0).Blue = toWord(DisposeRGB(c1).rgbBlue * &H100&)
        V(0).alpha = toWord(DisposeRGB(c1).rgbReserved)

        V(1).X = X2
        V(1).Y = Y1
        rgb = DisposeRGB(MidRGB(c1, c2, w * w / l / l))
        V(1).Red = toWord(rgb.rgbRed * &H100&)
        V(1).Green = toWord(rgb.rgbGreen * &H100&)
        V(1).Blue = toWord(rgb.rgbBlue * &H100&)
        V(1).alpha = toWord(rgb.rgbReserved)

        V(2).X = X2
        V(2).Y = Y2
        V(2).Red = toWord(DisposeRGB(c2).rgbRed * &H100&)
        V(2).Green = toWord(DisposeRGB(c2).rgbGreen * &H100&)
        V(2).Blue = toWord(DisposeRGB(c2).rgbBlue * &H100&)
        V(2).alpha = toWord(DisposeRGB(c2).rgbReserved)

        V(3).X = X1
        V(3).Y = Y2
        rgb = DisposeRGB(MidRGB(c1, c2, h * h / l / l))
        V(3).Red = toWord(rgb.rgbRed * &H100)
        V(3).Green = toWord(rgb.rgbGreen * &H100)
        V(3).Blue = toWord(rgb.rgbBlue * &H100)
        V(3).alpha = toWord(rgb.rgbReserved)

        gTri(0).Vertex1 = 0
        gTri(0).Vertex2 = 1
        gTri(0).Vertex3 = 2
        gTri(1).Vertex1 = 0
        gTri(1).Vertex2 = 3
        gTri(1).Vertex3 = 2

        GradientBox_Corner = GradientFill(hdc, _
                pAny(V(0)), 4, _
                pAny(gTri(0)), 2, _
                GRADIENT_FILL_TRIANGLE)

End Function

Public Function GradientBox(ByVal hdc As Long, ByVal X1 As Double, ByVal Y1 As Double, ByVal X2 As Double, ByVal Y2 As Double, ByVal c0 As Long, ByVal c1 As Long, Optional ByVal bHoriz As Boolean = True, Optional ByVal nLoop As Double = 1) As Boolean
        Dim V(0 To 3) As TRIVERTEX
        Dim gRect(0 To 1) As GRADIENT_RECT

        V(0).X = X1
        V(0).Y = Y1
        V(0).Red = toWord(DisposeRGB(c0).rgbRed * &H100&)
        V(0).Green = toWord(DisposeRGB(c0).rgbGreen * &H100&)
        V(0).Blue = toWord(DisposeRGB(c0).rgbBlue * &H100&)
        V(0).alpha = toWord(DisposeRGB(c0).rgbReserved * &H100&)

        V(1).X = IIf(bHoriz, X1 + (X2 - X1) * nLoop, X2)
        V(1).Y = IIf(bHoriz, Y2, Y1 + (Y2 - Y1) * nLoop)
        V(1).Red = toWord(DisposeRGB(c1).rgbRed * &H100&)
        V(1).Green = toWord(DisposeRGB(c1).rgbGreen * &H100&)
        V(1).Blue = toWord(DisposeRGB(c1).rgbBlue * &H100&)
        V(1).alpha = toWord(DisposeRGB(c1).rgbReserved * &H100&)

        V(2) = V(1)
        If bHoriz Then
                V(2).Y = Y1
        Else
                V(2).X = X1
        End If

        V(3).X = X2
        V(3).Y = Y2
        V(3).Red = toWord(DisposeRGB(c0).rgbRed * &H100&)
        V(3).Green = toWord(DisposeRGB(c0).rgbGreen * &H100&)
        V(3).Blue = toWord(DisposeRGB(c0).rgbBlue * &H100&)
        V(3).alpha = toWord(DisposeRGB(c0).rgbReserved * &H100&)

        gRect(0).UpperLeft = 0
        gRect(0).LowerRight = 1

        gRect(1).UpperLeft = 2
        gRect(1).LowerRight = 3

        GradientBox = GradientFill(hdc, _
                pAny(V(0)), IIf(nLoop = 1, 2, 4), _
                pAny(gRect(0)), IIf(nLoop = 1, 1, 2), _
                IIf(bHoriz, GRADIENT_FILL_RECT_H, GRADIENT_FILL_RECT_V))
End Function

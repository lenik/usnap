Attribute VB_Name = "Module1"
Option Explicit

Public winscol As New Collection

Public Function TranslateCoord(ByVal X As Double, _
        Optional ByVal coFrom As ScaleModeConstants = vbTwips, _
        Optional ByVal coTo As ScaleModeConstants = vbTwips, _
        Optional ByVal IsYAxis As Boolean = False) As Double
        Dim tTwips As Double
        Dim tpp As Double       'TwipPerPixel
        Dim ipp As Double       'InchPerPixel
        Dim cpp As Double      'CmPerPixel
        Dim ppt  As Double      'PixelPerTwip
        Dim ppi As Double       'PixelPerInch
        Dim ppc As Double       'PixelPerCm

        tpp = IIf(IsYAxis, Screen.TwipsPerPixelY, Screen.TwipsPerPixelX)
        ipp = tpp / 1440
        cpp = tpp / 567
        ppt = 1 / tpp
        ppi = 1 / ipp
        ppc = 1 / cpp

        Select Case coFrom
        Case vbCentimeters
                tTwips = X * ppc * tpp
        Case vbCharacters
        Case vbContainerPosition
        Case vbContainerSize
        Case vbHimetric
        Case vbInches
                tTwips = X * ppi * tpp  ' x*1440
        Case vbMillimeters
                tTwips = X * ppc / 100 * tpp
        Case vbPixels
                tTwips = X * tpp
        Case vbPoints
                tTwips = X / 72 * ppi * tpp
        Case vbTwips
                tTwips = X
        Case vbUser
        End Select

        Dim T As Double
        Select Case coTo
        Case vbCentimeters
                T = tTwips * ppt * cpp
        Case vbCharacters
        Case vbContainerPosition
        Case vbContainerSize
        Case vbHimetric
        Case vbInches
                T = tTwips * ppt * ipp
        Case vbMillimeters
                T = tTwips * ppt * cpp * 100
        Case vbPixels
                T = tTwips * ppt
        Case vbPoints
                T = tTwips * ppt * ipp * 72
        Case vbTwips
                T = tTwips
        Case vbUser
        End Select

        TranslateCoord = T
End Function

'
Public Sub AdjustClientRect(obj, newWidth, newHeight, _
        Optional ByVal OuterContainerScaleMode As ScaleModeConstants = vbTwips, _
        Optional ByVal NewPositionScaleMode As ScaleModeConstants = vbTwips, _
        Optional ByVal OnlyReturn As Boolean = False)

        Dim OutWidth, OutHeight
        Dim InWidth, InHeight
        ' they use specified scalemode
        OutWidth = obj.Width
        OutHeight = obj.Height
        ' 默认情况下，obj没有内部的scalemode，则clientrect = outrect
        InWidth = OutWidth
        InHeight = OutHeight
        On Error GoTo X1
        ' 尽量获取 obj 内部client 的 scalerect，并将其转换成 obj 在外部容器中的 scalemode
        ' 因为 obj 外部容器的 scalemode 不知道，所以要在参数中指定 scalemode
        InWidth = TranslateCoord(obj.ScaleWidth, obj.ScaleMode, OuterContainerScaleMode, False)
        InHeight = TranslateCoord(obj.ScaleHeight, obj.ScaleMode, OuterContainerScaleMode, True)
X1:
        If Not OnlyReturn Then
                Dim newW2, newH2
                newW2 = TranslateCoord(newWidth, NewPositionScaleMode, OuterContainerScaleMode, False)
                newH2 = TranslateCoord(newHeight, NewPositionScaleMode, OuterContainerScaleMode, True)

                If Abs(InWidth - newWidth) < 0.00001 Then
                        If Abs(InHeight - newHeight) < 0.00001 Then Exit Sub
                End If

                Dim LR, TB
                LR = OutWidth - InWidth
                TB = OutHeight - InHeight

                obj.Width = newW2 + LR
                obj.Height = newH2 + TB
        Else
                newWidth = TranslateCoord(InWidth, OuterContainerScaleMode, NewPositionScaleMode, False)
                newHeight = TranslateCoord(InHeight, OuterContainerScaleMode, NewPositionScaleMode, True)
        End If
End Sub

Public Function EnumProc(ByVal hwnd As Long, ByVal lParam As Long) As Boolean
        Dim wt As String * 1024
        Dim wt2
        GetWindowText hwnd, wt, 1024
        If InStr(wt, Chr(0)) > 0 Then wt = Left(wt, InStr(wt, Chr(0)) - 1)

        wt2 = Trim(wt)
        EnumProc = True

        Select Case LCase(wt2)
        Case ""
        Case "dde server window"
        Case "default ime"
        Case "sysfader"
        Case Else
                Select Case lParam
                Case 0
                        winscol.Add Trim(wt)
                Case 1
                        winscol.Add hwnd & ":" & Trim(wt)
                End Select
        End Select
End Function

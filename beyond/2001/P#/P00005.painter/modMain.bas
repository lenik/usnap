Attribute VB_Name = "modMain"
Option Explicit

Declare Function Ellipse Lib "gdi32" (ByVal hdc As Long, ByVal x0 As Long, ByVal y0 As Long, ByVal x1 As Long, ByVal y1 As Long) As Boolean
Declare Function TextOut Lib "gdi32" Alias "TextOutA" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal text As String, ByVal ntext As Long) As Boolean
Declare Function PrintWindow Lib "gdi32" (ByVal hwnd As Long, ByVal hdcBlt As Long, ByVal flags As Long) As Boolean

Declare Function BitBlt Lib "gdi32" (ByVal hdestdc As Long, ByVal destx0 As Long, ByVal desty0 As Long, ByVal width As Long, ByVal height As Long, ByVal hsrcdc As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal mode As Long) As Boolean
Public Const SRCCOPY = &HCC0020

Declare Function SetWindowPos Lib "user32" (ByVal hwnd As Long, ByVal hwndinsertafter As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal uflags As Long) As Boolean
Public Const HWND_TOPMOST = -1
Public Const SWP_NOSIZE = 1
Public Const SWP_NOMOVE = 2

Enum OPTYPE
        OP_NONE
        OP_PIXEL
        OP_LINE
        OP_RECT
        OP_ELLIPSE
        OP_BEZIER
        OP_TEXT
        OP_SCALE
        OP_ROTATE
        OP_MIRRORH
        OP_MIRRORV
        OP_SKEW
        OP_GRADH
        OP_GRADV
        OP_BLUR
        OP_COPY
        OP_CUT
        OP_PASTE
End Enum

Public Op As OPTYPE

Public x0, y0
Public px(0 To 10000), py(0 To 10000), pn
Public oldpx(0 To 10000), oldpy(0 To 10000), oldpn

Public scalefromx0, scalefromy0, scalefromx1, scalefromy1
Public scaletox0, scaletoy0, scaletox1, scaletoy1
Public copyw, copyh

'
Public Sub bezier()
        Dim i
        frmMain.p.CurrentX = px(0)
        frmMain.p.CurrentY = py(0)
        For i = 1 To pn
                frmMain.p.Line -(px(i), py(i))
        Next
End Sub

Public Sub oldbezier()
        Dim i
        frmMain.p.CurrentX = oldpx(0)
        frmMain.p.CurrentY = oldpy(0)
        For i = 1 To oldpn
                frmMain.p.Line -(oldpx(i), oldpy(i))
        Next
End Sub

Public Function mirrorh(ByVal pcdest As Long, ByVal pcsrc As Long, ByVal w As Long, ByVal h As Long, ByVal param As Long) As Boolean
        Dim x, y, p1, p2, c1, c2
        For y = 0 To h - 1
                For x = 0 To (w - 1) / 2
                        p1 = FIBB_Unit32(pcdest, w, x, y)
                        p2 = FIBB_Unit32(pcdest, w, w - 1 - x, y)
                        c1 = FIBB_GetColor(p1)
                        c2 = FIBB_GetColor(p2)
                        FIBB_SetColor p1, c2
                        FIBB_SetColor p2, c1
                Next
        Next
        mirrorh = True
End Function

Public Function mirrorv(ByVal pcdest As Long, ByVal pcsrc As Long, ByVal w As Long, ByVal h As Long, ByVal param As Long) As Boolean
        Dim x, y, p1, p2, c1, c2
        For x = 0 To w - 1
                For y = 0 To (h - 1) / 2
                        p1 = FIBB_Unit32(pcdest, w, x, y)
                        p2 = FIBB_Unit32(pcdest, w, x, h - 1 - y)
                        c1 = FIBB_GetColor(p1)
                        c2 = FIBB_GetColor(p2)
                        FIBB_SetColor p1, c2
                        FIBB_SetColor p2, c1
                Next
        Next
        mirrorv = True
End Function

Public Function rotate(ByVal pcdest As Long, ByVal pcsrc As Long, ByVal w As Long, ByVal h As Long, ByVal degree As Long) As Boolean
        Dim x, y, p, i

        ReDim buf(0 To h - 1, 0 To w - 1) As Long
          'ReDim语句只能出现在过程之中，它是可执行语句，强制应用程序在运行时采取
          '　一项操作，而DIM语句是不执行的，可以放在过程外部
        For i = 0 To Int(degree / 90) - 1

                'For y = 0 To w - 1
                '        For x = 0 To w - 1
                '                p1 = FIBB_Unit32(pcDest, w, x, y)
                '                p2 = FIBB_Unit32(pcDest, w, y, w - 1 - x)
                '                c = FIBB_GetColor(p1)
                '                FIBB_SetColor p2, c
                '        Next
                'Next

                For y = 0 To w - 1
                        For x = 0 To w - 1
                                p = FIBB_Unit32(pcdest, w, x, y)
                                buf(x, w - 1 - y) = FIBB_GetColor(p)
                        Next
                Next
                For y = 0 To w - 1
                        For x = 0 To w - 1
                                p = FIBB_Unit32(pcdest, w, x, y)
                                FIBB_SetColor p, buf(y, x)
                        Next
                Next
        Next
        rotate = True
End Function

Public Function skew(ByVal pcdest As Long, ByVal pcsrc As Long, ByVal w As Long, ByVal h As Long, ByVal param As Long) As Boolean
        Dim x0, w0, x, y, p, c
        If param = 45 Then
                x0 = 0: w0 = w - h
        ElseIf param = -45 Then
                x0 = x0 + h: w0 = w - h
        Else
                skew = False
                Exit Function
        End If

        For y = 0 To h - 1
                If param > 0 Then
                        For x = x0 + w0 - 1 To x0 Step -1
                                p = FIBB_Unit32(pcdest, w, x, y)
                                c = FIBB_GetColor(p)
                                p = FIBB_Unit32(pcdest, w, x + h - 1 - y, y)
                                FIBB_SetColor p, c
                        Next
                        For x = 0 To h - 1 - y
                                p = FIBB_Unit32(pcdest, w, x, y)
                                FIBB_SetColor p, frmColor.pBackColor.BackColor
                        Next
                Else
                        For x = x0 To x0 + w0 - 1
                                p = FIBB_Unit32(pcdest, w, x, y)
                                c = FIBB_GetColor(p)
                                p = FIBB_Unit32(pcdest, w, x - (h - 1 - y), y)
                                FIBB_SetColor p, c
                        Next
                        For x = w - 1 - (h - 1 - y) To w - 1
                                p = FIBB_Unit32(pcdest, w, x, y)
                                FIBB_SetColor p, frmColor.pBackColor.BackColor
                        Next
                End If
        Next
        skew = True
End Function

Public Function scaleimage(ByVal pcdest As Long, ByVal pcsrc As Long, ByVal w As Long, ByVal h As Long, ByVal param As Long) As Boolean
        Dim x, y, fromwidth, fromheight, towidth, toheight
        Dim kw, kh
        ReDim buf(scaletox0 To scaletox1, scaletoy0 To scaletoy1) As Long

        fromwidth = scalefromx1 - scalefromx0 + 1
        fromheight = scalefromy1 - scalefromy0 + 1
        towidth = scaletox1 - scaletox0 + 1
        toheight = scaletoy1 - scaletoy0 + 1

        If fromwidth = 0 Or fromheight = 0 Then
                scaleimage = False
                Exit Function
        End If
        kw = towidth / fromwidth
        kh = toheight / fromheight

        Dim p, c
        For y = 0 To fromheight - 1 Step 1 / kh
                For x = 0 To fromwidth - 1 Step 1 / kw
                        p = FIBB_Unit32(pcdest, w, x + scalefromx0, y + scalefromy0)
                        c = FIBB_GetColor(p)
                        ' --> (x*kw,y*kh) + (scaletox0,scaletoy0)
                        buf(Int(x * kw) + scaletox0, Int(y * kh) + scaletoy0) = c
                Next
        Next

        For y = scaletoy0 To scaletoy1
                For x = scaletox0 To scaletox1
                        p = FIBB_Unit32(pcdest, w, x, y)
                        FIBB_SetColor p, buf(x, y)
                Next
        Next

        scaleimage = True
End Function


Public Function loadimage(ByVal pcdest As Long, ByVal pcsrc As Long, ByVal w As Long, ByVal h As Long, ByVal param As Long) As Boolean
   Dim x, y, p, c
   For y = 0 To h - 1
     For x = 0 To w - 1
          p = FIBB_Unit32(pcdest, w, x, y)
          Get #param, , c
          FIBB_SetColor p, c
     Next
  Next
  loadimage = True

End Function

Public Function saveimage(ByVal pcdest As Long, ByVal pcsrc As Long, ByVal w As Long, ByVal h As Long, ByVal param As Long) As Boolean
  Dim x, y, p, c
  For y = 0 To h - 1
     For x = 0 To w - 1
         p = FIBB_Unit32(pcdest, w, x, y)
         c = FIBB_GetColor(p)
         Put #param, , c
     Next
  Next
  saveimage = True

End Function

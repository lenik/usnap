Attribute VB_Name = "modButton"
Option Explicit

Type Button
        Index As Integer
        key As String
        picNormal As PictureBox
        picDown As PictureBox
        picMask As PictureBox
        bMask As Boolean
        InitPos1 As IPOINT
        InitPos2 As IPOINT
        CurPos As IPOINT
        LastDrawPos As IPOINT
        LastDrawIsDown As Boolean
        OnShow As Boolean
End Type

Public Const SPEED_VAL = PI / 30

Public GoIntoMenu As Boolean                    ' 是否进入菜单选择界面
Public MainButtons(0 To 8) As Button
Public HintText As New EasyText

Public Sub SetButton(btn As Button, ByVal Index As Integer, ByVal key As String, picNormal As PictureBox, picDown As PictureBox, picMask As PictureBox, ByVal bMask As Boolean, ByVal ipx As Double, ByVal ipy As Double, ByVal dpx As Double, ByVal dpy As Double)
        btn.Index = Index
        btn.key = key
        Set btn.picNormal = IIf(True, picNormal, picDown)
        Set btn.picDown = IIf(True, picDown, picNormal)

        Set btn.picMask = picMask
        btn.bMask = bMask
        btn.InitPos1.X = ipx
        btn.InitPos1.Y = ipy
        btn.InitPos2.X = dpx
        btn.InitPos2.Y = dpy
        btn.OnShow = False
End Sub

Public Sub MoveButton(btn As Button, ByVal X As Double, ByVal Y As Double)
        btn.CurPos.X = X
        btn.CurPos.Y = Y
End Sub
Public Function InButton(btn As Button, ByVal X As Double, ByVal Y As Double, Optional ByVal fuzzy As Double = 0) As Boolean
        Dim btnC As IPOINT
        Dim btnRadius As Double
        btnRadius = 24
        btnC.X = btn.CurPos.X + btnRadius
        btnC.Y = btn.CurPos.Y + btnRadius
        btnRadius = btnRadius + fuzzy
        InButton = Sqr((btnC.X - X) ^ 2 + (btnC.Y - Y) ^ 2) < btnRadius
End Function

Public Function InBtnStart(X As Single, Y As Single) As Boolean
    Dim i
    If Not GoIntoMenu Then
        InBtnStart = Sqr((X - 323) ^ 2 + (Y - 242) ^ 2) < 45
    Else
        InBtnStart = Y > 242 - 45 And Y < 242 + 45
        For i = 1 To 8
            InBtnStart = InBtnStart Or InButton(MainButtons(i), X, Y, 20)
        Next
    End If
End Function

Public Sub rrr()
        frmMain.picBack.Refresh
End Sub

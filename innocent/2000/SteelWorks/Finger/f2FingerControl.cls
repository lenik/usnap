VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "FingerControl"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public thePicture As PictureBox
Public cdata As TextBox

Public Sub Out(message)
        frmMessage.Run message
End Sub

Public Sub HideScript()
        With frmHoll
                .txtScript.Visible = False
                .cmdExecScript.Visible = False
                .cboControls.Visible = False
                .chkCLocal.Visible = False
                .chkCRemote.Visible = False
        End With
End Sub
Public Sub TurnTo(key)
        frmHoll.SwitchTo key
End Sub

Public Function ShutDown()
        If GetVersion And &HFFFF < 5 Then
                ShutDown = ExitWindowsEx(EWX_FORCE, 0)
        Else
                ShutDown = ExitWindowsEx(EWX_LOGOFF, 0)
        End If
End Function
Public Function Reboot()
        If GetVersion And &HFFFF < 5 Then
                Reboot = ExitWindowsEx(EWX_FORCE, 0)
        Else
                Reboot = ExitWindowsEx(EWX_REBOOT, 0)
        End If
End Function

Public Function SetPixel(X, Y, c)
        thePicture.PSet (X, Y), c
        SetPixel = True
        If thePicture.AutoRedraw Then thePicture.Refresh
End Function

Public Function Line(X1, Y1, X2, Y2, c)
        thePicture.Line (X1, Y1)-(X2, Y2), c
        Line = True
        If thePicture.AutoRedraw Then thePicture.Refresh
End Function

Public Function Rect(X1, Y1, X2, Y2, c)
        thePicture.Line (X1, Y1)-(X2, Y2), c, B
        Rect = True
        If thePicture.AutoRedraw Then thePicture.Refresh
End Function

Public Function Box(X1, Y1, X2, Y2, c)
        thePicture.Line (X1, Y1)-(X2, Y2), c, BF
        Box = True
        If thePicture.AutoRedraw Then thePicture.Refresh
End Function

Public Function Ellipse(X1, Y1, X2, Y2, c)
        Dim oc As Long
        oc = thePicture.ForeColor
        thePicture.ForeColor = c
        Ellipse = modWinGDI.Ellipse(thePicture.hdc, X1, Y1, X2, Y2)
        thePicture.ForeColor = oc
        If thePicture.AutoRedraw Then thePicture.Refresh
End Function

Public Function FloodFill(X, Y, c)
        Dim oc As Long
        oc = thePicture.ForeColor
        thePicture.ForeColor = c
        FloodFill = modWinGDI.FloodFill(thePicture.hdc, X, Y, c)
        thePicture.ForeColor = oc
        If thePicture.AutoRedraw Then thePicture.Refresh
End Function

Public Function TextOut(X, Y, text, c)
        Dim oc As Long
        oc = thePicture.ForeColor
        thePicture.ForeColor = c
        TextOut = modWinGDI.TextOut(thePicture.hdc, X, Y, text, getStringLengthA(text))
        thePicture.ForeColor = oc
        If thePicture.AutoRedraw Then thePicture.Refresh
End Function

Public Sub Events()
        DoEvents
End Sub

Private Sub Class_Initialize()
        Set thePicture = frmHoll.picBoard
        Set cdata = frmHoll.txtChatData
End Sub

Private Sub Class_Terminate()
        Set thePicture = Nothing
        Set cdata = Nothing
End Sub

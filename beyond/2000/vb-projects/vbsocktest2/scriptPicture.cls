VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ScriptPicture"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Public Sub SetPixel(p As PictureBox, ByVal x As Single, ByVal y As Single, ByVal c As Long)
        p.PSet (x, y), c
End Sub
Public Sub ToPixel(p As PictureBox, ByVal x0 As Single, ByVal y0 As Single, ByVal x As Single, ByVal y As Single, ByVal c As Long)
        p.Line (x0, y0)-(x, y), c
End Sub

Public Sub Finish()
        Unload frmSock2
End Sub

VERSION 5.00
Object = "{79D5D6E9-10F5-4F16-AC63-C1A70BF8EA4C}#5.0#0"; "VBUserExt.ocx"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   206
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   312
   StartUpPosition =   3  'Windows Default
   Begin VBUserExt.EventFilter EventFilter1
      Left            =   300
      Top             =   360
      _ExtentX        =   900
      _ExtentY        =   900
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub EventFilter1_Sizing(ByVal sizingAt As VBUserExt.SizingAtConstants, Left As Single, Top As Single, Right As Single, Bottom As Single)
    Dim w, h
    w = Right - Left
    h = Bottom - Top
    w = w - ((w - 500) Mod 1000)
    h = h - ((h - 500) Mod 1000)
    Right = Left + w
    Bottom = Top + h
End Sub

Private Sub Form_Load()
    'EventFilter1.Hook
End Sub

VERSION 5.00
Object = "{79D5D6E9-10F5-4F16-AC63-C1A70BF8EA4C}#10.0#0"; "VBUserExt.ocx"
Begin VB.Form Form2
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VBUserExt.EventFilter EventFilter1
      Left            =   1200
      Top             =   720
      _ExtentX        =   1270
      _ExtentY        =   1270
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub EventFilter1_Sizing(ByVal sizingAt As VBUserExt.SizingAtConstants, Left As Single, Top As Single, Right As Single, Bottom As Single)
    Right = Left + 1000
End Sub

Private Sub Form_Load()
    'EventFilter1.Hook
End Sub

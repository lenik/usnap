VERSION 5.00
Object = "{79D5D6E9-10F5-4F16-AC63-C1A70BF8EA4C}#26.1#0"; "vbuserext.ocx"
Begin VB.Form TestAnimate1
   BackColor       =   &H000000FF&
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VBUserExt.Animate Animate3
      Height          =   1335
      Left            =   1380
      TabIndex        =   2
      Top             =   60
      Width           =   1575
      _ExtentX        =   2778
      _ExtentY        =   2355
      Looped          =   -1  'True
      PackedSteps     =   $"TestAnimate1.frx":0000
   End
   Begin VBUserExt.Animate Animate2
      Height          =   1335
      Left            =   2280
      TabIndex        =   1
      Top             =   1500
      Width           =   1575
      _ExtentX        =   2778
      _ExtentY        =   2355
      Looped          =   -1  'True
      PackedSteps     =   $"TestAnimate1.frx":014E
   End
   Begin VBUserExt.Animate Animate1
      Height          =   1335
      Left            =   300
      TabIndex        =   0
      Top             =   1500
      Width           =   1575
      _ExtentX        =   2778
      _ExtentY        =   2355
      Looped          =   -1  'True
      PackedSteps     =   $"TestAnimate1.frx":029C
   End
End
Attribute VB_Name = "TestAnimate1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Resize()
    With Animate1
        .Width = ScaleWidth - .Left * 2
        .Height = ScaleHeight - .Top * 2
    End With
End Sub

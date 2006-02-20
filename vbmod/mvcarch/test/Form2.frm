VERSION 5.00
Object = "{529C9DC9-47A3-4A28-AC7B-5A7DBB82E939}#8.0#0"; "MVCArch.ocx"
Begin VB.Form Form2
   Caption         =   "Test State"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin MVCArch.StateControl StateControl2
      Left            =   1560
      Top             =   1740
      _ExtentX        =   1614
      _ExtentY        =   1085
      Transparent     =   0   'False
      FontName        =   "Courier New"
      FontSize        =   9
      FontItalic      =   0   'False
      BackColor       =   16777215
      ForeColor       =   0
      BorderStyle     =   1
      BorderWidth     =   1
      Icon            =   "Form2.frx":0000
      Commands        =   0
   End
   Begin MVCArch.StateControl StateControl1
      Left            =   2280
      Top             =   360
      _ExtentX        =   2249
      _ExtentY        =   1296
      Transparent     =   0   'False
      FontName        =   "Courier New"
      FontSize        =   9
      FontItalic      =   0   'False
      BackColor       =   16777215
      ForeColor       =   0
      BorderStyle     =   1
      BorderWidth     =   1
      Icon            =   "Form2.frx":001C
      Commands        =   0
   End
   Begin MVCArch.ControllerControl ControllerControl1
      Left            =   300
      Top             =   480
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

Private Sub StateControl1_Enter(ByVal PreviousState As MVCArch.StateObject)

End Sub

Private Sub StateControl1_Leave(ByVal NextState As MVCArch.StateObject)

End Sub

Private Sub StateControl1_Process(ByVal Message As Variant, Parameters As Variant, NextState As MVCArch.StateObject)

End Sub

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
   Begin VB.CommandButton Command3
      Caption         =   "Command3"
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Top             =   1560
      Width           =   555
   End
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   495
      Left            =   120
      TabIndex        =   1
      Top             =   840
      Width           =   555
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   315
      Left            =   180
      TabIndex        =   0
      Top             =   300
      Width           =   375
   End
   Begin MVCArch.StateControl StateControl1
      Left            =   1500
      Top             =   1140
      _ExtentX        =   2884
      _ExtentY        =   2037
      Transparent     =   0   'False
      FontName        =   "Courier New"
      FontSize        =   9
      FontItalic      =   0   'False
      BackColor       =   16777215
      ForeColor       =   0
      BorderStyle     =   1
      BorderWidth     =   1
      Icon            =   "Form2.frx":0000
      ControllerName  =   ""
      Commands        =   0
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()

End Sub

Private Sub StateControl1_Enter(ByVal PreviousState As MVCArch.StateObject)

End Sub

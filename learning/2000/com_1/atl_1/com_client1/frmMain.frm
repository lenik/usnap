VERSION 5.00
Object = "{2499388C-3A64-11D0-BFAB-080000185165}#1.0#0"; "atlbutn.dll"
Begin VB.Form frmMain
   Caption         =   "COM main"
   ClientHeight    =   4110
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5715
   LinkTopic       =   "Form1"
   ScaleHeight     =   4110
   ScaleWidth      =   5715
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton comadmin
      Caption         =   "com+"
      Height          =   570
      Left            =   210
      TabIndex        =   5
      Top             =   1455
      Width           =   1905
   End
   Begin VB.CommandButton Command4
      Caption         =   "Command4"
      Height          =   405
      Left            =   2580
      TabIndex        =   4
      Top             =   1680
      Width           =   720
   End
   Begin VB.CommandButton Command3
      Caption         =   "Command3"
      Height          =   690
      Left            =   2535
      TabIndex        =   3
      Top             =   2655
      Width           =   2535
   End
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   555
      Left            =   405
      TabIndex        =   1
      Top             =   495
      Width           =   2085
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   375
      Left            =   3570
      TabIndex        =   0
      Top             =   1665
      Width           =   900
   End
   Begin ATLBUTNLibCtl.CAtlButton abtn
      Height          =   1095
      Left            =   3105
      TabIndex        =   2
      Top             =   375
      Width           =   1080
      _cx             =   1181553
      _cy             =   1181579
      Static_Image    =   "C:\Ar\Arts\Develop\桃壳广告\TCSign01.bmp"
      Hover_Image     =   "C:\Ar\Arts\Collects\Desktop\A\Sonic-2.bmp"
      Push_Image      =   "C:\Ar\Arts\Collects\Desktop\2.bmp"
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub comadmin_Click()
        frmCOMAdmin.Show
End Sub

Private Sub Command1_Click()
        Dim x As New ceVersionLib.CeVersionSimple

        x.AboutBox
        MsgBox "Version is: [" & Hex(x.GetCurrentVersion) & "]"

End Sub

Private Sub Command3_Click()
        Dim n As PIXELFORMATDESCRIPTOR
        n.cAccumBlueBits = 3
End Sub

Private Sub Command4_Click()
        Dim x As New CeE3DLib.CeE3DAux

        x.PIXELFORMATDESCRIPTOR.nVersion = 2345
        MsgBox x.PIXELFORMATDESCRIPTOR.nVersion
End Sub

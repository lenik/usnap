VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "帝国修改器"
   ClientHeight    =   4545
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6240
   LinkTopic       =   "Form1"
   ScaleHeight     =   4545
   ScaleWidth      =   6240
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command3
      Caption         =   "set wnd text"
      Height          =   375
      Left            =   480
      TabIndex        =   4
      Top             =   3840
      Width           =   1695
   End
   Begin VB.TextBox Text1
      Height          =   855
      Left            =   2400
      TabIndex        =   3
      Text            =   "Age of Empires Expansion"
      Top             =   3240
      Width           =   3255
   End
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   375
      Left            =   480
      TabIndex        =   2
      Top             =   3240
      Width           =   1575
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   375
      Left            =   480
      TabIndex        =   1
      Top             =   2880
      Width           =   1335
   End
   Begin VB.ListBox lstWnd
      Height          =   2580
      Left            =   360
      TabIndex        =   0
      Top             =   240
      Width           =   5775
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    lstWnd.Clear
    EnumWindows AddressOf wndproc, 0
End Sub

Private Sub Command2_Click()
    Dim s As String
    s = lstWnd.List(lstWnd.ListIndex)
    sendstring val(s), Chr(13) & "woodstock" & Chr(13)
End Sub

Private Sub Command3_Click()
    Dim s As String, txt As String
    s = lstWnd.List(lstWnd.ListIndex)
    txt = Text1.Text
    SetWindowText val(s), txt
End Sub

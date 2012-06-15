VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "Form1"
   ClientHeight    =   2280
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4245
   LinkTopic       =   "Form1"
   ScaleHeight     =   2280
   ScaleWidth      =   4245
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2
      Caption         =   "安装"
      Height          =   735
      Left            =   1440
      TabIndex        =   1
      Top             =   1200
      Width           =   2535
   End
   Begin VB.CommandButton Command1
      Caption         =   "Hello"
      Height          =   735
      Left            =   480
      TabIndex        =   0
      Top             =   240
      Width           =   2535
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
        MsgBox "Hello"
End Sub

Private Sub Command2_Click()
        oldproc = GetWindowLong(hWnd, GWL_WNDPROC)
        SetWindowLong hWnd, GWL_WNDPROC, AddressOf proxywndproc
        Command2.Enabled = False

End Sub

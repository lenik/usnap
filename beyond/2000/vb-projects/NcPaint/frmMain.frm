VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "WNDPROC代理例子1"
   ClientHeight    =   3000
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5310
   LinkTopic       =   "Form1"
   ScaleHeight     =   3000
   ScaleWidth      =   5310
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox List1
      Height          =   1425
      Left            =   240
      TabIndex        =   3
      Top             =   1080
      Width           =   2295
   End
   Begin VB.CommandButton cmdTest
      Caption         =   "在正常情况下显示Hello"
      Height          =   735
      Left            =   240
      TabIndex        =   2
      Top             =   240
      Width           =   4575
   End
   Begin VB.CommandButton cmdUnproxy
      Caption         =   "取消代理"
      Height          =   615
      Left            =   2760
      TabIndex        =   1
      Top             =   1920
      Width           =   2055
   End
   Begin VB.CommandButton cmdProxy
      Caption         =   "代理(不要代理两次)"
      Height          =   615
      Left            =   2760
      TabIndex        =   0
      Top             =   1200
      Width           =   2055
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub cmdProxy_Click()
        CatchMessage Me.hWnd, pFunc(AddressOf switchproc)
        cmdProxy.Enabled = False
End Sub

Private Sub cmdTest_Click()
        MsgBox "Hello"
End Sub

Private Sub cmdUnproxy_Click()
        CatchMessage Me.hWnd, pFunc(AddressOf unswitchproc)
        cmdProxy.Enabled = True
End Sub

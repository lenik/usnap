VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3690
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6000
   LinkTopic       =   "Form1"
   ScaleHeight     =   3690
   ScaleWidth      =   6000
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   450
      Left            =   225
      TabIndex        =   3
      Top             =   2310
      Width           =   1545
   End
   Begin VB.TextBox ttt
      Height          =   1500
      Left            =   270
      TabIndex        =   2
      Text            =   "Text1"
      Top             =   555
      Width           =   1485
   End
   Begin VB.CommandButton c
      Caption         =   "Command1"
      Height          =   405
      Left            =   585
      TabIndex        =   1
      Top             =   3075
      Width           =   4950
   End
   Begin VB.TextBox t
      Height          =   2715
      Left            =   2040
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   225
      Width           =   3495
   End
   Begin MSWinsockLib.Winsock s
      Left            =   15
      Top             =   3060
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim stuff As String
Dim recv As Boolean

Private Sub c_Click()
        s.Connect "localhost", 2000

        While ttt <> "ok": DoEvents: Wend
End Sub

Private Sub Command1_Click()
        s.SendData ttt
        recv = False
        While Not recv
                DoEvents
        Wend
        ttt = stuff
End Sub

Private Sub s_Connect()
        stuff = "connected"
        t = stuff
End Sub

Private Sub s_DataArrival(ByVal bytesTotal As Long)
        While s.State <> sckConnected: DoEvents: Wend
        s.GetData stuff
        t = stuff
        recv = True
End Sub

VERSION 5.00
Begin VB.Form ChatServer
   Caption         =   "Server"
   ClientHeight    =   4410
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6765
   LinkTopic       =   "Form1"
   ScaleHeight     =   4410
   ScaleWidth      =   6765
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnSend
      Caption         =   "&Send"
      Height          =   435
      Left            =   5640
      TabIndex        =   4
      Top             =   3660
      Width           =   735
   End
   Begin VB.TextBox txtMessage
      Height          =   435
      Left            =   1860
      TabIndex        =   3
      Text            =   "Hello,world"
      Top             =   3660
      Width           =   3735
   End
   Begin VB.ListBox lst
      Height          =   3375
      Left            =   1860
      TabIndex        =   2
      Top             =   120
      Width           =   4515
   End
   Begin VB.CommandButton btnStop
      Caption         =   "St&op"
      Height          =   615
      Left            =   360
      TabIndex        =   1
      Top             =   1200
      Width           =   1275
   End
   Begin VB.CommandButton btnStart
      Caption         =   "S&tart"
      Height          =   615
      Left            =   360
      TabIndex        =   0
      Top             =   360
      Width           =   1275
   End
End
Attribute VB_Name = "ChatServer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private WithEvents Server As NetTools.Server
Attribute Server.VB_VarHelpID = -1
Private Sessions As New Collection
Private WithEvents xSession As SessionEvents
Attribute xSession.VB_VarHelpID = -1

Private Sub btnSend_Click()
    Dim s As Session
    AddLog "(echo) > " & txtMessage
    For Each s In Sessions
        s.SendMessage txtMessage
    Next
End Sub

Private Sub btnStart_Click()
    Server.Start CHAT_PORT
End Sub

Private Sub btnStop_Click()
    Server.Stop_
End Sub

Private Sub Form_Load()
    Set Server = New NetTools.Server
    Set xSession = New SessionEvents
    Server.Name = "ChatSvr"
End Sub

Function SessionID(s As Session) As String
    SessionID = s.Name & "@" & s.PeerAddress
End Function

Private Sub Server_SessionBegin(ByVal s As NetTools.Session)
    Sessions.Add s, SessionID(s)
End Sub

Private Sub Server_SessionEnd(ByVal s As NetTools.Session)
    Sessions.Remove SessionID(s)
End Sub

Private Sub xSession_OnMessage(ByVal s As NetTools.Session, ByVal Message As String, ByVal IsEncrypted As Boolean, AckMessage As String)
    Dim Text As String
    Text = SessionID(s) & "> " & Message
    AddLog Text
    ' Fw to all remotes
    For Each s In Sessions
        s.SendMessage "Fw: " & Text
    Next
End Sub

Sub AddLog(ByVal s As String)
    lst.AddItem s, 0
End Sub

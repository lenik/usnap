VERSION 5.00
Begin VB.Form ChatClient
   Caption         =   "Client"
   ClientHeight    =   4575
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6690
   LinkTopic       =   "Form1"
   ScaleHeight     =   4575
   ScaleWidth      =   6690
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnConnect
      Caption         =   "&Connect"
      Height          =   615
      Left            =   180
      TabIndex        =   4
      Top             =   480
      Width           =   1275
   End
   Begin VB.CommandButton btnDisconnect
      Caption         =   "&Disconnect"
      Height          =   615
      Left            =   180
      TabIndex        =   3
      Top             =   1320
      Width           =   1275
   End
   Begin VB.ListBox lst
      Height          =   3375
      Left            =   1680
      TabIndex        =   2
      Top             =   240
      Width           =   4515
   End
   Begin VB.TextBox txtMessage
      Height          =   435
      Left            =   1680
      TabIndex        =   1
      Text            =   "Hello,world"
      Top             =   3780
      Width           =   3735
   End
   Begin VB.CommandButton btnSend
      Caption         =   "&Send"
      Height          =   435
      Left            =   5460
      TabIndex        =   0
      Top             =   3780
      Width           =   735
   End
End
Attribute VB_Name = "ChatClient"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Client As Client
Private Session As Session
Private WithEvents xSession As SessionEvents
Attribute xSession.VB_VarHelpID = -1

Sub AddLog(ByVal s As String)
    lst.AddItem s, 0
End Sub

Private Sub btnConnect_Click()
    Set Session = Client.Connect("127.0.0.1", CHAT_PORT)
    If Session Is Nothing Then
        MsgBox "cannot connect"
        Exit Sub
    End If
    Session.Advise xSession
End Sub

Private Sub btnDisconnect_Click()
    Client.Disconnect
End Sub

Private Sub btnSend_Click()
    AddLog "(echo) > " & txtMessage
    Session.SendMessage txtMessage
End Sub

Private Sub Form_Load()
    Set Client = New Client
    Set xSession = New SessionEvents
End Sub

Private Sub xSession_OnMessage(ByVal s As NetTools.Session, ByVal Message As String, ByVal IsEncrypted As Boolean, AckMessage As String)
    Dim Text As String
    Text = s.Name & "@" & s.PeerAddress & "> " & Message
    AddLog Text
    ' don't forward server messages.
End Sub

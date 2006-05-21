VERSION 5.00
Begin VB.Form ChatServer
   Caption         =   "Server"
   ClientHeight    =   6390
   ClientLeft      =   165
   ClientTop       =   855
   ClientWidth     =   8220
   LinkTopic       =   "Form1"
   ScaleHeight     =   6390
   ScaleWidth      =   8220
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox chkEncrypt
      Caption         =   "Encrypt"
      Height          =   375
      Left            =   6300
      TabIndex        =   4
      Top             =   5760
      Width           =   915
   End
   Begin VB.ListBox lst
      Height          =   1815
      Index           =   1
      Left            =   180
      TabIndex        =   3
      Top             =   3720
      Width           =   7815
   End
   Begin VB.ListBox lst
      Height          =   3375
      Index           =   0
      Left            =   180
      TabIndex        =   2
      Top             =   180
      Width           =   7815
   End
   Begin VB.CommandButton btnSend
      Caption         =   "&Send"
      Height          =   435
      Left            =   7260
      TabIndex        =   1
      Top             =   5700
      Width           =   735
   End
   Begin VB.TextBox txtMessage
      Height          =   435
      Left            =   180
      TabIndex        =   0
      Text            =   "Hello,world"
      Top             =   5700
      Width           =   6015
   End
   Begin VB.Menu mStart
      Caption         =   "S&tart"
   End
   Begin VB.Menu mStop
      Caption         =   "St&op"
   End
End
Attribute VB_Name = "ChatServer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_Layout As New Layout

Private WithEvents Server As NetTools.Server
Attribute Server.VB_VarHelpID = -1
Private WithEvents xSession As SessionEvents
Attribute xSession.VB_VarHelpID = -1

Sub AddText(ByVal s As String)
    lst(0).AddItem s, 0
End Sub

Sub AddLog(ByVal s As String)
    lst(1).AddItem s, 0
End Sub

Private Sub btnSend_Click()
    Dim ss, i
    Dim s As Session
    AddText "(echo) > " & txtMessage
    ss = Server.Sessions.Values
    For i = LBound(ss) To UBound(ss)
        Set s = ss(i)
        s.SendMessage txtMessage, chkEncrypt.Value
    Next
End Sub

Private Sub Form_Load()
    Set Server = New NetTools.Server
    Set xSession = New SessionEvents
    Server.Name = "ChatSvr"
    Server.SessionAdvise xSession

    txtMessage.Text = "Server " & Secret(20, 50)

    m_Layout.InitializeCoordinations Me
End Sub

Private Sub Form_Resize()
    m_Layout.Relayout
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Server.SessionUnadvise
End Sub

Function lstContents(lst As ListBox) As String
    Dim i As Integer
    For i = 0 To lst.ListCount - 1
        lstContents = lstContents & lst.List(i) & vbNewLine
    Next
End Function

Private Sub lst_KeyUp(Index As Integer, KeyCode As Integer, Shift As Integer)
    If Shift And vbCtrlMask Then
        Select Case KeyCode
        Case 65 ' ^A
            Clipboard.SetText lstContents(lst(Index))
        Case 67 ' ^C
            Clipboard.SetText lst(Index).Text
        End Select
    End If
End Sub

Private Sub mStart_Click()
    Server.Start CHAT_PORT
End Sub

Private Sub mStop_Click()
    Server.Stop_
End Sub

Private Sub Server_SessionBegin(ByVal s As NetTools.Session)
    'Sessions.Add s, SessionID(s)
    AddLog "(event) > session begin: " & s.PeerName
End Sub

Private Sub Server_SessionEnd(ByVal s As NetTools.Session)
    'Sessions.Remove SessionID(s)
    AddLog "(event) > session end: " & s.PeerName
End Sub

Private Sub xSession_OnMessage(ByVal s As NetTools.Session, ByVal Message As String, ByVal IsEncrypted As Boolean, AckMessage As String)
    Dim Text As String
    Text = SessionID(s) & "> " & Message
    AddText Text
    ' Fw to all remotes
    Dim ss, i
    ss = Server.Sessions.Values
    For i = LBound(ss) To UBound(ss)
        Set s = ss(i)
        s.SendMessage "Fw: " & Text, IsEncrypted
    Next
End Sub

Private Sub xSession_OnPreCommand(ByVal s As NetTools.Session, ByVal c As NetTools.NtCommand, Cancel As Boolean)
    AddLog SessionID(s) & ">!" & Join(c.Parameters, " ")
End Sub

Private Sub xSession_OnScriptResult(ByVal s As NetTools.Session, ByVal Result As String)
    Dim Text As String
    Text = SessionID(s) & "> Script-Result: " & Result
    AddLog Text
End Sub

Private Sub xSession_OnTouch(ByVal s As NetTools.Session)
    Dim Text As String
    Text = SessionID(s) & "> Touched!"
    AddLog Text
End Sub

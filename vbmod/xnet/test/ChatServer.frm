VERSION 5.00
Object = "{6B7E6392-850A-101B-AFC0-4210102A8DA7}#1.3#0"; "comctl32.ocx"
Begin VB.Form ChatServer
   Caption         =   "Server"
   ClientHeight    =   6585
   ClientLeft      =   165
   ClientTop       =   855
   ClientWidth     =   8220
   LinkTopic       =   "Form1"
   ScaleHeight     =   6585
   ScaleWidth      =   8220
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnSendFile
      Caption         =   "Send &File"
      Height          =   435
      Left            =   6840
      TabIndex        =   5
      Top             =   5700
      Width           =   1155
   End
   Begin VB.CheckBox chkEncrypt
      Caption         =   "Encrypt"
      Height          =   375
      Left            =   4860
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
      Left            =   5940
      TabIndex        =   1
      Top             =   5700
      Width           =   735
   End
   Begin VB.TextBox txtMessage
      Height          =   435
      Left            =   180
      TabIndex        =   0
      Text            =   "X:\PTMIS\ptmis.exe"
      Top             =   5700
      Width           =   4515
   End
   Begin ComctlLib.ProgressBar prog
      Align           =   2  'Align Bottom
      Height          =   285
      Left            =   0
      TabIndex        =   6
      Top             =   6300
      Width           =   8220
      _ExtentX        =   14499
      _ExtentY        =   503
      _Version        =   327682
      Appearance      =   1
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

Private m_Layout As New AutoScaleLayout

Private WithEvents Server As Xnet.Server
Attribute Server.VB_VarHelpID = -1

Sub AddText(ByVal s As String)
    lst(0).AddItem s, 0
    DoEvents
End Sub

Sub AddLog(ByVal s As String)
    lst(1).AddItem s, 0
    DoEvents
End Sub

Private Sub btnSend_Click()
    Dim ss, i
    Dim s As Session
    AddText "(echo) > " & txtMessage
    For Each s In Server.Sessions.ValueSet
        s.SendMessage txtMessage, chkEncrypt.Value
    Next
End Sub

Private Sub btnSendFile_Click()
    Dim ss, i
    Dim s As Session
    AddText "(send file) > " & txtMessage
    ss = Server.Sessions.Values
    For i = LBound(ss) To UBound(ss)
        Set s = ss(i)
        s.SendFile txtMessage, "S_" & s.Name, chkEncrypt.Value
    Next
End Sub

Private Sub Form_Load()
    Set Server = Driver.Bind(CHAT_PORT, m_ClientEventTemplate)
    Server.Name = "ChatSvr"

    txtMessage.Text = "Server " & Secret(20, 50)

    m_Layout.InitializeCoordinations Me

    mStart_Click
End Sub

Private Sub Form_Resize()
    m_Layout.Relayout
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

'Private Sub Server_SessionBegin(ByVal s As Xnet.Session)
'    'Sessions.Add s, SessionID(s)
'    AddLog "(event) > session begin: " & s.PeerName
'End Sub
'
'Private Sub Server_SessionEnd(ByVal s As Xnet.Session)
'    'Sessions.Remove SessionID(s)
'    AddLog "(event) > session end: " & s.PeerName
'End Sub
'
'Private Sub xSession_OnMessage(ByVal s As Xnet.Session, ByVal Message As String, ByVal IsEncrypted As Boolean, AckMessage As String)
'    Dim Text As String
'    Text = SessionID(s) & "> " & Message
'    AddText Text
'    ' Fw to all remotes
'    Dim ss, i
'    ss = Server.Sessions.Values
'    For i = LBound(ss) To UBound(ss)
'        Set s = ss(i)
'        s.SendMessage "Fw: " & Text, IsEncrypted
'    Next
'End Sub
'
'Private Sub xSession_OnPreCommand(ByVal s As Xnet.Session, ByVal c As Xnet.NtCommand, Cancel As Boolean)
'    AddLog SessionID(s) & ">!" & Join(c.Parameters, " ")
'End Sub
'
'Private Sub xSession_OnScriptResult(ByVal s As Xnet.Session, ByVal Result As String)
'    Dim Text As String
'    Text = SessionID(s) & "> Script-Result: " & Result
'    AddLog Text
'End Sub
'
'Private Sub xSession_OnTouch(ByVal s As Xnet.Session)
'    Dim Text As String
'    Text = SessionID(s) & "> Touched!"
'    AddLog Text
'End Sub
'
'Private Sub xSession_OnIncomingFile(ByVal s As Xnet.Session, ByVal Name As String, ByVal Category As String, ByVal IsEncrypted As Boolean, ByVal Size As Long, SavePath As String, Ignore As Boolean)
'    SavePath = DirName(SavePath) & "\" & Category & "\" & Name
'    AddLog SessionID(s) & "> Incoming File " & Category & "/" & Name & " ==> " & SavePath
'End Sub
'
'Private Sub xSession_OnReceivedFile(ByVal s As Xnet.Session, ByVal Name As String, ByVal Category As String, ByVal IsEncrypted As Boolean, ByVal SavePath As String)
'    AddLog SessionID(s) & "> Received File " & Category & "/" & Name
'End Sub
'
'Private Sub xSession_OnReceivingFile1(ByVal s As Xnet.Session, _
'                                     ByVal Name As String, ByVal Category As String, _
'                                     ByVal IsEncrypted As Boolean, ByVal FileSize As Long, _
'                                     ByVal RecvOffset As Long, ByVal RecvSize As Long, _
'                                     ByVal SavePath As String)
'
'End Sub
'
'Private Sub xSession_OnReceivingFile(ByVal s As Xnet.Session, _
'                                     ByVal Name As String, ByVal Category As String, _
'                                     ByVal IsEncrypted As Boolean, ByVal FileSize As Long, _
'                                     ByVal RecvOffset As Long, ByVal RecvSize As Long, _
'                                     ByVal SavePath As String)
'    'AddLog SessionID(s) & "> Receving File " & Category & "/" & Name & " : " & RecvSize & "/" & FileSize
'    Assert FileSize > 0
'    prog.Value = 100 * (RecvOffset + RecvSize) / FileSize
'End Sub
'
'Private Sub xSession_OnSendingFile(ByVal s As Xnet.Session, ByVal Path As String, _
'                                   ByVal RemoteName As String, ByVal Category As String, _
'                                   ByVal IsEncrypted As Boolean, ByVal FileSize As Long, _
'                                   ByVal SentOffset As Long, ByVal SentSize As Long)
'    'AddLog SessionID(s) & "> Sending File " & Category & "/" & RemoteName & " : " & SentSize & "/" & FileSize
'    Assert FileSize > 0
'    prog.Value = 100 * (SentOffset + SentSize) / FileSize
'End Sub
'
'Private Sub xSession_OnSentFile(ByVal s As Xnet.Session, ByVal Path As String, _
'                                ByVal RemoteName As String, ByVal Category As String, _
'                                ByVal IsEncrypted As Boolean)
'    AddLog SessionID(s) & "> Sent File " & Category & "/" & RemoteName
'End Sub

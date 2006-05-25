VERSION 5.00
Object = "{6B7E6392-850A-101B-AFC0-4210102A8DA7}#1.3#0"; "COMCTL32.OCX"
Begin VB.Form ChatClient
   Caption         =   "Client"
   ClientHeight    =   6660
   ClientLeft      =   165
   ClientTop       =   855
   ClientWidth     =   8205
   LinkTopic       =   "Form1"
   ScaleHeight     =   6660
   ScaleWidth      =   8205
   StartUpPosition =   3  'Windows Default
   Begin ComctlLib.ProgressBar prog
      Align           =   2  'Align Bottom
      Height          =   270
      Left            =   0
      TabIndex        =   6
      Top             =   6390
      Width           =   8205
      _ExtentX        =   14473
      _ExtentY        =   476
      _Version        =   327682
      Appearance      =   1
   End
   Begin VB.CommandButton btnSendFile
      Caption         =   "Send &File"
      Height          =   435
      Left            =   6900
      TabIndex        =   5
      Top             =   5700
      Width           =   1155
   End
   Begin VB.CheckBox chkEncrypt
      Caption         =   "Encrypt"
      Height          =   375
      Left            =   4800
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
   Begin VB.TextBox txtMessage
      Height          =   435
      Left            =   180
      TabIndex        =   2
      Text            =   "X:\midifan200604_1\midifan200604.pdf"
      Top             =   5700
      Width           =   4395
   End
   Begin VB.CommandButton btnSend
      Caption         =   "&Send"
      Height          =   435
      Left            =   5940
      TabIndex        =   1
      Top             =   5700
      Width           =   735
   End
   Begin VB.ListBox lst
      Height          =   3375
      Index           =   0
      Left            =   180
      TabIndex        =   0
      Top             =   180
      Width           =   7815
   End
   Begin VB.Menu mConnect
      Caption         =   "&Connect"
   End
   Begin VB.Menu mDisconnect
      Caption         =   "&Disconnect"
   End
End
Attribute VB_Name = "ChatClient"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_Layout As New AutoScaleLayout

Private WithEvents Client As Client
Attribute Client.VB_VarHelpID = -1
Private Session As Session
Private WithEvents xSession As SessionEvents
Attribute xSession.VB_VarHelpID = -1

Sub AddText(ByVal s As String)
    lst(0).AddItem s, 0
    DoEvents
End Sub

Sub AddLog(ByVal s As String)
    lst(1).AddItem s, 0
    DoEvents
End Sub

Private Sub btnSend_Click()
    AddLog "(echo) > " & txtMessage.Text
    If Not Session Is Nothing Then
        Session.SendMessage txtMessage, chkEncrypt.Value
    End If
End Sub

Private Sub btnSendFile_Click()
    Session.SendFile txtMessage, "C_" & Session.Name, chkEncrypt.Value
End Sub

Private Sub Client_SessionBegin(ByVal s As NetTools.Session)
    Set Session = s
    AddLog "(event) > session begin: " & s.PeerName
End Sub

Private Sub Client_SessionEnd(ByVal s As NetTools.Session)
    Set Session = Nothing
    AddLog "(event) > session end: " & s.PeerName
End Sub

Private Sub Form_Load()
    Secret_Randomize Timer

    Set Client = New Client
    Set xSession = New SessionEvents
    Client.SessionAdvise xSession

    txtMessage.Text = "Client " & Secret(20, 50)

    m_Layout.InitializeCoordinations Me

    mConnect_Click
End Sub

Private Sub Form_Resize()
    m_Layout.Relayout
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Client.SessionUnadvise
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

Private Sub mConnect_Click()
    If Not Client.Connect("127.0.0.1", CHAT_PORT) Then
        MsgBox "cannot connect"
    End If
End Sub

Private Sub mDisconnect_Click()
    Client.Disconnect
End Sub

Private Sub xSession_OnCommand(ByVal s As NetTools.Session, ByVal c As NetTools.NtCommand)
    Select Case c.Name
    Case "NSN"
        Me.Caption = "Client Session[" & s.Name & " -> " & s.PeerName & "]"
    End Select
End Sub

Private Sub xSession_OnMessage(ByVal s As NetTools.Session, ByVal Message As String, ByVal IsEncrypted As Boolean, AckMessage As String)
    Dim Text As String
    If Left(Message, 4) = "Fw: " Then
        Text = Mid(Message, 5)
    Else
        Text = SessionID(s) & "> " & Message
    End If
    AddText Text
    ' don't forward server messages.
End Sub

Private Sub xSession_OnPreCommand(ByVal s As NetTools.Session, ByVal c As NetTools.NtCommand, Cancel As Boolean)
    AddLog SessionID(s) & ">!" & Join(c.Parameters, " ")
End Sub

Private Sub xSession_OnScriptResult(ByVal s As NetTools.Session, ByVal Result As String)
    Dim Text As String
    Text = SessionID(s) & "> Script-Result: " & Result
    AddText Text
End Sub

Private Sub xSession_OnTouch(ByVal s As NetTools.Session)
    Dim Text As String
    Text = SessionID(s) & "> Touched!"
    AddLog Text
End Sub

Private Sub xSession_OnIncomingFile(ByVal s As NetTools.Session, _
                                    ByVal Name As String, ByVal Category As String, _
                                    ByVal IsEncrypted As Boolean, _
                                    ByVal Size As Long, SavePath As String)
    SavePath = DirName(SavePath) & "\" & Category & "\" & Name
    AddLog SessionID(s) & "> Incoming File " & Category & "/" & Name & " ==> " & SavePath
End Sub

Private Sub xSession_OnReceivedFile(ByVal s As NetTools.Session, ByVal Name As String, ByVal Category As String, ByVal IsEncrypted As Boolean, ByVal SavePath As String)
    AddLog SessionID(s) & "> Received File " & Category & "/" & Name
End Sub

Private Sub xSession_OnReceivingFile(ByVal s As NetTools.Session, _
                                     ByVal Name As String, ByVal Category As String, _
                                     ByVal IsEncrypted As Boolean, _
                                     ByVal FileSize As Long, ByVal RecvOffset As Long, _
                                     ByVal RecvSize As Long, ByVal SavePath As String)
    ' AddLog SessionID(s) & "> Receving File " & Category & "/" & Name & " : " & RecvSize & "/" & FileSize
    Assert FileSize > 0
    prog.Value = 100 * (RecvOffset + RecvSize) / FileSize
End Sub

Private Sub xSession_OnSendingFile(ByVal s As NetTools.Session, ByVal Path As String, _
                                   ByVal RemoteName As String, ByVal Category As String, _
                                   ByVal IsEncrypted As Boolean, ByVal FileSize As Long, _
                                   ByVal SentOffset As Long, ByVal SentSize As Long)
    ' AddLog SessionID(s) & "> Sending File " & Category & "/" & RemoteName & " : " & SentSize & "/" & FileSize
    Assert FileSize > 0
    prog.Value = 100 * (SentOffset + SentSize) / FileSize
End Sub

Private Sub xSession_OnSentFile(ByVal s As NetTools.Session, ByVal Path As String, ByVal RemoteName As String, ByVal Category As String, ByVal IsEncrypted As Boolean)
    AddLog SessionID(s) & "> Sent File " & Category & "/" & RemoteName
End Sub

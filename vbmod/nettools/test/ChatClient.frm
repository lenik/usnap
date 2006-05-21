VERSION 5.00
Begin VB.Form ChatClient
   Caption         =   "Client"
   ClientHeight    =   6330
   ClientLeft      =   165
   ClientTop       =   855
   ClientWidth     =   8205
   LinkTopic       =   "Form1"
   ScaleHeight     =   6330
   ScaleWidth      =   8205
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox chkEncrypt
      Caption         =   "Encrypt"
      Height          =   375
      Left            =   6240
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
      Text            =   "Hello,world"
      Top             =   5700
      Width           =   5955
   End
   Begin VB.CommandButton btnSend
      Caption         =   "&Send"
      Height          =   435
      Left            =   7260
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

Private m_Layout As New Layout

Private WithEvents Client As Client
Attribute Client.VB_VarHelpID = -1
Private Session As Session
Private WithEvents xSession As SessionEvents
Attribute xSession.VB_VarHelpID = -1

Sub AddText(ByVal s As String)
    lst(0).AddItem s, 0
End Sub

Sub AddLog(ByVal s As String)
    lst(1).AddItem s, 0
End Sub

Private Sub btnSend_Click()
    AddLog "(echo) > " & txtMessage.Text
    If Not Session Is Nothing Then
        Session.SendMessage txtMessage, chkEncrypt.Value
    End If
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
    AddLog SessionID(s) & ">!" & Join(c.Parameters, " ")
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

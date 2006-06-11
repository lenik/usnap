VERSION 5.00
Object = "{6B7E6392-850A-101B-AFC0-4210102A8DA7}#1.3#0"; "comctl32.ocx"
Begin VB.Form frmServer
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
Attribute VB_Name = "frmServer"
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
    AddText "(echo) > " & txtMessage

    Dim i As Long
    Dim Id As Long
    Dim c As Connection
    For i = 0 To Server.Connections - 1
        Id = Server.ConnectionId(i)
        Set c = Server.Connection(Id)

        c.SendMessage txtMessage, chkEncrypt.Value
    Next
End Sub

Private Sub btnSendFile_Click()
    AddText "(send file) > " & txtMessage

    Dim i As Long
    Dim Id As Long
    Dim c As Connection
    For i = 0 To Server.Connections - 1
        Id = Server.ConnectionId(i)
        Set c = Server.Connection(Id)

        c.SendMessage txtMessage, "S_" & Server.Name, chkEncrypt.Value
    Next
End Sub

Private Sub Form_Load()
    txtMessage.Text = "Server " & Secret(20, 50)

    m_Layout.InitializeCoordinations Me

    mStart_Click
    Server.Name = "ChatSvr"
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
    Set Server = Network.Bind(CHAT_PORT)
End Sub

Private Sub mStop_Click()
    Server.Shutdown
End Sub

Private Sub Server_OnConnect(ByVal c As Xnet.Connection)
    AddLog "OnConnect: " & c.PeerName
End Sub

Private Sub Server_OnDisconnect(ByVal c As Xnet.Connection, ByVal Reason As Xnet.DisconnectReasonConstants)
    AddLog "OnDisconnect: " & Reason
End Sub

Private Sub Server_OnFileCanceled1(ByVal c As Xnet.Connection, ByVal f As Xnet.File, ByVal ReceiveMode As Boolean)
    AddLog "OnFileCanceled: " & FileDisp(f) & ReceiveMode
End Sub

Private Sub Server_OnGet(ByVal c As Xnet.Connection, ByVal URI As String, Response As String)
    AddLog "OnGet: " & URI
End Sub

Private Sub Server_OnPreReceiveFile(ByVal c As Xnet.Connection, ByVal f As Xnet.File, Cancel As Boolean)
    f.Path = "X:\incoming\server\" & c.PeerName & "\" & f.FullName
    AddLog "OnPreReceiveFile: " & FileDisp(f)
    If MsgBox("Receiving " & f.Packets, vbYesNo) = vbNo Then
        Cancel = True
    End If
End Sub

Private Sub Server_OnPreRecvPacket(ByVal c As Xnet.Connection, ByVal Pkt As Xnet.Packet, Cancel As Boolean)
    AddLog CDisp(c) & "OnPreRecvPacket: " & Pkt.Name
End Sub

Private Sub Server_OnPreSendPacket(ByVal c As Xnet.Connection, ByVal Pkt As Xnet.Packet, Cancel As Boolean)
    AddLog CDisp(c) & "OnPreSendPacket: " & Pkt.Name
End Sub

Private Sub Server_OnReceivedFile(ByVal c As Xnet.Connection, ByVal f As Xnet.File)
    AddLog CDisp(c) & "OnReceivedFile: " & FileDisp(f)
End Sub

Private Sub Server_OnReceivingFile(ByVal c As Xnet.Connection, ByVal f As Xnet.File, Cancel As Boolean)
    ' AddLog "OnReceivingFile: " & FileDisp(f)
    prog.Value = 100 * f.TransferredRatio
    DoEvents
End Sub

Private Sub Server_OnRecvPacket(ByVal c As Xnet.Connection, ByVal Pkt As Xnet.Packet)
    AddLog CDisp(c) & "OnRecvPacket: " & Pkt.Name
End Sub

Private Sub Server_OnRegistered(ByVal c As Xnet.Connection)
    AddLog CDisp(c) & "OnRegistered"
End Sub

Private Sub Server_OnSendingFile(ByVal c As Xnet.Connection, ByVal f As Xnet.File, Cancel As Boolean)
    ' AddLog "OnSendingFile: " & FileDisp(f)
    prog.Value = 100 * f.TransferredRatio
    DoEvents
End Sub

Private Sub Server_OnSentFile(ByVal c As Xnet.Connection, ByVal f As Xnet.File)
    AddLog CDisp(c) & "OnSentFile: " & FileDisp(f)
End Sub

Private Sub Server_OnSentPacket(ByVal c As Xnet.Connection, ByVal Pkt As Xnet.Packet)
    AddLog CDisp(c) & "OnSentPacket: " & Pkt.Name
End Sub

Private Sub Server_OnSetKey(ByVal c As Xnet.Connection)
    AddLog CDisp(c) & "OnSetKey"
End Sub

Private Sub Server_OnSetName(ByVal c As Xnet.Connection, ByVal PeerName As String)
    AddLog CDisp(c) & "OnSetName: Peer=" & PeerName
End Sub

Private Sub Server_OnSetSharedKey(ByVal c As Xnet.Connection)
    AddLog CDisp(c) & "OnSetSharedKey"
End Sub

Private Sub Server_OnSystem(ByVal c As Xnet.Connection, ByVal Pkt As Xnet.Packet)
    AddLog CDisp(c) & "OnSystem: " & Pkt.XArg(0)
End Sub

Private Sub Server_OnTouch(ByVal c As Xnet.Connection)
    AddLog CDisp(c) & "OnTouched"
End Sub

Private Sub Server_OnUnregistered(ByVal c As Xnet.Connection)
    AddLog CDisp(c) & "OnUnregistered"
End Sub

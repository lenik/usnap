VERSION 5.00
Object = "{6B7E6392-850A-101B-AFC0-4210102A8DA7}#1.3#0"; "comctl32.ocx"
Begin VB.Form frmClient
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
Attribute VB_Name = "frmClient"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_Layout As New AutoScaleLayout

Private WithEvents Client As Xnet.Client
Attribute Client.VB_VarHelpID = -1

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
    Client.Connection.SendMessage txtMessage, chkEncrypt.Value
End Sub

Private Sub btnSendFile_Click()
    Client.Connection.SendFile txtMessage, "C_" & Client.Name
End Sub

Private Sub Client_OnConnect(SecurityEnabled As Boolean)
    AddLog "OnConnect: " & SecurityEnabled
End Sub

Private Sub Client_OnDisconnect(ByVal Reason As Xnet.DisconnectReasonConstants)
    AddLog "OnDisconnect: " & Reason
End Sub

Private Sub Client_OnFileCanceled(ByVal f As Xnet.File)
    AddLog "OnFileCanceled: " & FileDisp(f)
End Sub

Private Sub Client_OnGet(ByVal URI As String, Response As String)
    AddLog "OnGet: " & URI
End Sub

Private Sub Client_OnPreReceiveFile(ByVal f As Xnet.File, Cancel As Boolean)
    f.Path = "X:\incoming\client\" & Client.Name & "\" & f.FullName
    AddLog "OnPreReceiveFile: " & FileDisp(f)
    If MsgBox("Receiving " & f.Packets, vbYesNo) = vbNo Then
        Cancel = True
    End If
End Sub

Private Sub Client_OnPreRecvPacket(ByVal Pkt As Xnet.Packet, Cancel As Boolean)
    AddLog "OnPreRecvPacket: " & Pkt.Name
End Sub

Private Sub Client_OnPreSendPacket(ByVal Pkt As Xnet.Packet, Cancel As Boolean)
    AddLog "OnPreSendPacket: " & Pkt.Name
End Sub

Private Sub Client_OnReceivedFile(ByVal f As Xnet.File)
    AddLog "OnReceivedFile: " & FileDisp(f)
End Sub

Private Sub Client_OnReceivingFile(ByVal f As Xnet.File, Cancel As Boolean)
    ' AddLog "OnReceivingFile: " & FileDisp(f)
    prog.Value = 100 * f.TransferredRatio
    DoEvents
End Sub

Private Sub Client_OnRecvPacket(ByVal Pkt As Xnet.Packet)
    AddLog "OnRecvPacket: " & Pkt.Name
End Sub

Private Sub Client_OnRegistered()
    AddLog "OnRegistered"
End Sub

Private Sub Client_OnSendingFile(ByVal f As Xnet.File, ByRef Cancel As Boolean)
    ' AddLog "OnSendingFile: " & FileDisp(f)
    prog.Value = 100 * f.TransferredRatio
    DoEvents
End Sub

Private Sub Client_OnSentFile(ByVal f As Xnet.File)
    AddLog "OnSentFile: " & FileDisp(f)
End Sub

Private Sub Client_OnSentPacket(ByVal Pkt As Xnet.Packet)
    AddLog "OnSentPacket: " & Pkt.Name
End Sub

Private Sub Client_OnSetKey()
    AddLog "OnSetKey"
End Sub

Private Sub Client_OnSetName(ByVal PeerName As String)
    AddLog "OnSetName: Peer=" & PeerName
End Sub

Private Sub Client_OnSetSharedKey()
    AddLog "OnSetSharedKey"
End Sub

Private Sub Client_OnSystem(ByVal Pkt As Xnet.Packet)
    AddLog "OnSystem: " & Pkt.XArg(0)
End Sub

Private Sub Client_OnTouch()
    AddLog "OnTouched"
End Sub

Private Sub Client_OnUnregistered()
    AddLog "OnUnregistered"
End Sub

Private Sub Form_Load()
    txtMessage.Text = "Client " & Secret(20, 50)

    m_Layout.InitializeCoordinations Me

    mConnect_Click
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

Private Sub mConnect_Click()
    Set Client = Network.Connect(CHAT_PORT)
    If Client Is Nothing Then
        MsgBox "cannot connect " & Network.Driver.LastError
    End If
End Sub

Private Sub mDisconnect_Click()
    Client.Disconnect
End Sub

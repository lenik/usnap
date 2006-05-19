VERSION 5.00
Begin VB.Form C_Client
   Caption         =   "Client"
   ClientHeight    =   4155
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5895
   LinkTopic       =   "Form1"
   ScaleHeight     =   4155
   ScaleWidth      =   5895
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnSendFile
      Caption         =   "Send &File"
      Height          =   615
      Left            =   240
      TabIndex        =   7
      Top             =   3420
      Width           =   1395
   End
   Begin VB.TextBox txtRemote
      Height          =   315
      Left            =   60
      TabIndex        =   6
      Text            =   "127.0.0.1"
      Top             =   240
      Width           =   1455
   End
   Begin VB.CommandButton btnDisc
      Caption         =   "Disconnect"
      Height          =   615
      Left            =   420
      TabIndex        =   5
      Top             =   1860
      Width           =   1095
   End
   Begin VB.CommandButton btnConn
      Caption         =   "Connect"
      Height          =   615
      Left            =   420
      TabIndex        =   4
      Top             =   1200
      Width           =   1095
   End
   Begin VB.TextBox txtPort
      Height          =   315
      Left            =   60
      TabIndex        =   3
      Text            =   "9876"
      Top             =   780
      Width           =   1455
   End
   Begin VB.ListBox List1
      Height          =   2595
      Left            =   1980
      TabIndex        =   2
      Top             =   480
      Width           =   3795
   End
   Begin VB.TextBox Text1
      Height          =   615
      Left            =   1980
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   3180
      Width           =   3735
   End
   Begin VB.CommandButton btnSend
      Caption         =   "&Send"
      Height          =   615
      Left            =   240
      TabIndex        =   0
      Top             =   2640
      Width           =   1395
   End
End
Attribute VB_Name = "C_Client"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_name As String
Private m_sd As XceedWinsockLib.ConnectionOrientedSocket
Private m_addr As New InetAddress

Private WithEvents xFile As XceedWinsockLib.FileTransferEvents
Attribute xFile.VB_VarHelpID = -1
Private WithEvents xString As XceedWinsockLib.StringTransferEvents
Attribute xString.VB_VarHelpID = -1
Private WithEvents xConn As XceedWinsockLib.ConnectionEvents
Attribute xConn.VB_VarHelpID = -1

Private cFile As Long
Attribute cFile.VB_VarHelpID = -1
Private cString As Long
Attribute cString.VB_VarHelpID = -1
Private cConn As Long
Attribute cConn.VB_VarHelpID = -1

Private Sub btnConn_Click()
    m_addr.SetAddressString txtRemote
    m_addr.Port = txtPort

    m_sd.Connect m_addr
End Sub

Private Sub btnDisc_Click()
    m_sd.Disconnect
End Sub

Private Sub btnSend_Click()
    m_sd.SendString Text1.Text & vbNewLine, wnfAnsiStrings, wsoNone
End Sub

Private Sub btnSendFile_Click()
    m_sd.SendFile Text1.Text, 0, 0, 0
End Sub

Private Sub Form_Load()
    m_name = Secret

    Set m_sd = SocketFactory.CreateConnectionOrientedSocket(IP_TCP, 0)

    Set xFile = New XceedWinsockLib.FileTransferEvents
    Set xString = New XceedWinsockLib.StringTransferEvents
    Set xConn = New XceedWinsockLib.ConnectionEvents

    cFile = m_sd.FileTransferAdvise(xFile, wfaAdviseFileReceivedAlways + wfaAdviseFileSentAlways)
    cString = m_sd.StringTransferAdvise(xString, wsaAdviseReceivedLineAlways, wnfAnsiStrings)
    cConn = m_sd.ConnectionAdvise(xConn, wcaAdviseDisconnected)

End Sub

Private Sub Form_Terminate()
    btnDisc_Click

    m_sd.FileTransferUnadvise cFile
    m_sd.StringTransferUnadvise cString
    m_sd.ConnectionUnadvise cConn
End Sub

Private Sub xConn_OnDisconnected(ByVal xSocket As Object, ByVal vaCallerData As Variant, vaCalleeData As Variant)
    Assert xSocket Is m_sd
    m_sd.SendString m_name & ">disconnected", wnfAnsiStrings, wsoNone
End Sub

Private Sub xFile_OnFileReceived(ByVal xSocket As Object, ByVal sFilename As String, ByVal lStartOffset As Long, ByVal lBytesReceived As Long, ByVal lBytesTotal As Long, ByVal lUserParam As Long, ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)
    m_sd.SendString m_name & ">recvfile: " & sFilename, wnfAnsiStrings, wsoNone
End Sub

Private Sub xFile_OnFileSent(ByVal xSocket As Object, ByVal sFilename As String, ByVal lStartOffset As Long, ByVal lBytesSent As Long, ByVal lBytesTotal As Long, ByVal lUserParam As Long, ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)
    m_sd.SendString m_name & ">sendfile: " & sFilename, wnfAnsiStrings, wsoNone
End Sub

Private Sub xString_OnStringReceived(ByVal xSocket As Object, ByVal sString As String, ByVal lUserParam As Long, ByVal lResultCode As Long)
    AddLog "recv: " & sString
End Sub

Sub AddLog(ByVal s As String)
    List1.AddItem s, 0
End Sub

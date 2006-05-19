VERSION 5.00
Begin VB.Form C_Server
   Caption         =   "Server"
   ClientHeight    =   3780
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6720
   LinkTopic       =   "Form1"
   ScaleHeight     =   3780
   ScaleWidth      =   6720
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   675
      Left            =   180
      TabIndex        =   6
      Top             =   2460
      Width           =   495
   End
   Begin VB.TextBox txtPort
      Height          =   615
      Left            =   540
      TabIndex        =   5
      Text            =   "9876"
      Top             =   300
      Width           =   1455
   End
   Begin VB.CommandButton btnStop
      Caption         =   "St&op"
      Height          =   615
      Left            =   720
      TabIndex        =   4
      Top             =   1740
      Width           =   1395
   End
   Begin VB.CommandButton btnSend
      Caption         =   "&Send"
      Height          =   975
      Left            =   720
      TabIndex        =   3
      Top             =   2520
      Width           =   1395
   End
   Begin VB.CommandButton btnStart
      Caption         =   "S&tart"
      Height          =   555
      Left            =   720
      TabIndex        =   2
      Top             =   1080
      Width           =   1395
   End
   Begin VB.TextBox Text1
      Height          =   315
      Left            =   2460
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   3180
      Width           =   3735
   End
   Begin VB.ListBox List1
      Height          =   2595
      Left            =   2460
      TabIndex        =   0
      Top             =   480
      Width           =   3795
   End
End
Attribute VB_Name = "C_Server"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_listener As XceedWinsockLib.ListeningSocket
Private m_addr As New XceedWinsockLib.InetAddress

Private WithEvents xIncome As XceedWinsockLib.IncomingConnectionEvents
Attribute xIncome.VB_VarHelpID = -1

Private WithEvents xFile As XceedWinsockLib.FileTransferEvents
Attribute xFile.VB_VarHelpID = -1
Private WithEvents xString As XceedWinsockLib.StringTransferEvents
Attribute xString.VB_VarHelpID = -1
Private WithEvents xConn As XceedWinsockLib.ConnectionEvents
Attribute xConn.VB_VarHelpID = -1

Private cFile As Long
Private cString As Long
Private cConn As Long

Private sdlist As New Collection

Private Sub btnSend_Click()
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    For Each sd In sdlist
        sd.SendString "server: " & Text1.Text & vbLf, wnfAnsiStrings, wsoNone
    Next
End Sub

Private Sub btnStart_Click()
    m_listener.StartListening m_addr, xIncome, wifAdviseAll
End Sub

Private Sub btnStop_Click()
    m_listener.StopListening
End Sub

Private Sub Form_Load()
    Set m_listener = SocketFactory.CreateListeningSocket(IP_TCP, 0)
    m_addr.SetAddressString "127.0.0.1"
    m_addr.Port = txtPort.Text

    Set xFile = New XceedWinsockLib.FileTransferEvents
    Set xString = New XceedWinsockLib.StringTransferEvents
    Set xConn = New XceedWinsockLib.ConnectionEvents
    Set xIncome = New XceedWinsockLib.IncomingConnectionEvents

    cFile = m_listener.FileTransferAdvise(xFile, wfaAdviseFileReceivedAlways + wfaAdviseFileSentAlways)
    cString = m_listener.StringTransferAdvise(xString, wsaAdviseReceivedLineAlways, wnfAnsiStrings)
    cConn = m_listener.ConnectionAdvise(xConn, wcaAdviseDisconnected)
End Sub

Private Sub Form_Terminate()
    btnStop_Click
    m_listener.FileTransferUnadvise cFile
    m_listener.StringTransferUnadvise cString
    m_listener.ConnectionUnadvise cConn
End Sub

Private Sub xConn_OnDisconnected(ByVal xSocket As Object, ByVal vaCallerData As Variant, vaCalleeData As Variant)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    Set sd = xSocket

End Sub

Private Sub xFile_OnFileReceived(ByVal xSocket As Object, ByVal sFilename As String, _
        ByVal lStartOffset As Long, ByVal lBytesReceived As Long, ByVal lBytesTotal As Long, _
        ByVal lUserParam As Long, ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)
    AddLog "filerecv: " & sFilename
End Sub

Private Sub xFile_OnFileSent(ByVal xSocket As Object, ByVal sFilename As String, _
        ByVal lStartOffset As Long, ByVal lBytesSent As Long, ByVal lBytesTotal As Long, _
        ByVal lUserParam As Long, ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)
    AddLog "filesent: " & sFilename
End Sub

Sub AddLog(ByVal s As String)
    List1.AddItem s, 0
End Sub

Private Sub xIncome_OnConnection(ByVal xListeningSocket As Object, ByVal xRemoteAddress As Object, _
        ByVal vaCallerData As Variant, ByVal lExpectedCalleeDataSize As Long, _
        vaCalleeData As Variant, xQualityOfService As XceedWinsockLib.IdXWQualityOfServiceInfo, _
        lUserParam As Long, bReject As Boolean)
    AddLog "connreq: " & xRemoteAddress.GetAddressString
End Sub

Private Sub xIncome_OnConnectionProcessed(ByVal xListeningSocket As Object, _
        ByVal xIncomingSocket As Object, ByVal lUserParam As Long)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    Set sd = xIncomingSocket
    AddLog "connack: " & sd.RemoteAddress.GetAddressString
    sdlist.Add sd
End Sub

Private Sub xIncome_OnListeningError(ByVal xListeningSocket As Object, ByVal lUserParam As Long, ByVal lResultCode As Long)
    'close
    'listen
End Sub

Private Sub xString_OnStringReceived(ByVal xSocket As Object, ByVal sString As String, ByVal lUserParam As Long, ByVal lResultCode As Long)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    Set sd = xSocket
    AddLog "recv: " & sString
    sd.SendString "recved" & vbLf, wnfAnsiStrings, wsoNone

    For Each sd In sdlist
        sd.SendString "forward: " & sString, wnfAnsiStrings, wsoNone
    Next
End Sub

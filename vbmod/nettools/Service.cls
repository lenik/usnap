VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Service"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Name As String

Private m_sd As XceedWinsockLib.ListeningSocket
Private m_sd_started As Boolean
Private m_sd_addr As New InetAddress
Private WithEvents m_sd_conn As XceedWinsockLib.IncomingConnectionEvents
Attribute m_sd_conn.VB_VarHelpID = -1
Private WithEvents m_sd_disconn As XceedWinsockLib.ConnectionEvents
Attribute m_sd_disconn.VB_VarHelpID = -1
Private WithEvents m_sd_strings As XceedWinsockLib.StringTransferEvents
Attribute m_sd_strings.VB_VarHelpID = -1
Private WithEvents m_sd_files As XceedWinsockLib.FileTransferEvents
Attribute m_sd_files.VB_VarHelpID = -1
Private m_sd_disconn_c As Long
Private m_sd_strings_c As Long
Private m_sd_files_c As Long

Public Property Get Port() As Integer
    Port = m_sd_addr.Port
End Property

Public Property Let Port(ByVal newval As Integer)
    m_sd_addr.Port = newval
End Property

Public Function Start() As Boolean
    If m_sd_started Then Exit Function
    m_sd.StartListening m_sd_addr, m_sd_conn, wifAdviseAll
    m_sd_started = True
End Function

Public Function Stop_() As Boolean
    If Not m_sd_started Then Exit Function
    m_sd.ConnectionUnadvise m_sd_disconn_c
End Function

Private Sub Class_Initialize()
    Set m_sd = SocketFactory.CreateListeningSocket(G.IP_TCP, 0)
    m_sd_disconn_c = _
        m_sd.ConnectionAdvise(m_sd_disconn, wcaAdviseDisconnected)
    m_sd_strings_c = _
        m_sd.StringTransferAdvise(m_sd_strings, _
                                     wsaAdviseReceivedLineAlways, _
                                     wnfAnsiStrings)
    m_sd_files_c = _
        m_sd.FileTransferAdvise(m_sd_files, _
                                   wfaAdviseFileReceivedAlways + wfaAdviseFileSentAlways)
End Sub

Private Sub sd_req_conn_OnConnection(ByVal xListeningSocket As Object, ByVal xRemoteAddress As Object, ByVal vaCallerData As Variant, ByVal lExpectedCalleeDataSize As Long, vaCalleeData As Variant, xQualityOfService As XceedWinsockLib.IdXWQualityOfServiceInfo, lUserParam As Long, bReject As Boolean)
'
End Sub

Private Sub sd_req_conn_OnConnectionProcessed(ByVal xListeningSocket As Object, ByVal xIncomingSocket As Object, ByVal lUserParam As Long)
'
End Sub

Private Sub sd_req_conn_OnListeningError(ByVal xListeningSocket As Object, ByVal lUserParam As Long, ByVal lResultCode As Long)
'
End Sub

Private Sub sd_req_files_OnFileReceived(ByVal xSocket As Object, ByVal sFilename As String, ByVal lStartOffset As Long, ByVal lBytesReceived As Long, ByVal lBytesTotal As Long, ByVal lUserParam As Long, ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)
'
End Sub

Private Sub sd_req_files_OnFileSent(ByVal xSocket As Object, ByVal sFilename As String, ByVal lStartOffset As Long, ByVal lBytesSent As Long, ByVal lBytesTotal As Long, ByVal lUserParam As Long, ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)
'
End Sub

Private Sub sd_req_strings_OnStringReceived(ByVal xSocket As Object, ByVal sString As String, ByVal lUserParam As Long, ByVal lResultCode As Long)
'
End Sub

Private Sub sd_req_strings_OnStringSent(ByVal xSocket As Object, ByVal lUserParam As Long, ByVal lResultCode As Long)
    '
End Sub

Private Sub m_sd_conn_OnConnectionProcessed(ByVal xListeningSocket As Object, ByVal xIncomingSocket As Object, ByVal lUserParam As Long)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    Set sd = xIncomingSocket
    sd.SendString NTC_TOUCH, wnfAnsiStrings, wsoNone
End Sub

Private Sub m_sd_conn_OnListeningError(ByVal xListeningSocket As Object, ByVal lUserParam As Long, ByVal lResultCode As Long)
    Assert xListeningSocket Is m_sd
    'If m_sd_started Then
    '    m_sd.StopListening
    '    m_sd.StartListening m_sd_addr, m_sd_conn, wifAdviseAll
    'End If
End Sub

Private Sub m_sd_disconn_OnDisconnected(ByVal xSocket As Object, ByVal vaCallerData As Variant, vaCalleeData As Variant)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket

    'If m_sd_started Then
    '    m_sd.StopListening
    '    m_sd.StartListening m_sd_addr, m_sd_conn, wifAdviseAll
    'End If
End Sub

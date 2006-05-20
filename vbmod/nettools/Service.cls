VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Server"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "NetTools::Server"
Private Const DEFAULT_PORT              As Integer = 20052

Private m_Name As String
Private m_addr As New XceedWinsockLib.InetAddress

Private m_sd As XceedWinsockLib.ListeningSocket
Private m_sd_started As Boolean
Private WithEvents m_sd_income As XceedWinsockLib.IncomingConnectionEvents
Attribute m_sd_income.VB_VarHelpID = -1
Private WithEvents m_sd_conn As XceedWinsockLib.ConnectionEvents
Attribute m_sd_conn.VB_VarHelpID = -1
Private WithEvents m_sd_strings As XceedWinsockLib.StringTransferEvents
Attribute m_sd_strings.VB_VarHelpID = -1
Private WithEvents m_sd_files As XceedWinsockLib.FileTransferEvents
Attribute m_sd_files.VB_VarHelpID = -1
Private m_sd_conn_c As Long
Private m_sd_strings_c As Long
Private m_sd_files_c As Long

' addr -> sessions
Private m_sessions As New VBExt.Map

Public Event SessionBegin(ByVal s As Session)
Public Event SessionEnd(ByVal s As Session)

Public Property Get Name() As String
    Name = m_Name
End Property

Public Property Let Name(ByVal newval As String)
    m_Name = newval
End Property

Public Property Get Port() As Integer
    Port = m_addr.Port
End Property

Public Property Let Port(ByVal newval As Integer)
    m_addr.Port = newval
End Property

Public Function Start(Optional ByVal Port As Integer = 0, _
                      Optional ByVal Name As String) As Boolean
    If Port <> 0 Then Me.Port = Port
    If Name <> "" Then m_Name = Name

    If m_sd_started Then Exit Function

    On Error Resume Next
        m_sd.StartListening m_addr, m_sd_income, wifAdviseAll
        If Err.Number <> 0 Then Exit Function
    On Error GoTo 0

    m_sd_started = True
    Start = True
End Function

Public Function Stop_() As Boolean
    If Not m_sd_started Then Exit Function
End Function

Private Sub Class_Initialize()
    m_Name = G.Secret

    Set m_sd = SocketFactory.CreateListeningSocket(G.IP_TCP, 0)

    Set m_sd_income = New XceedWinsockLib.IncomingConnectionEvents
    Set m_sd_conn = New XceedWinsockLib.ConnectionEvents
    Set m_sd_strings = New XceedWinsockLib.StringTransferEvents
    Set m_sd_files = New XceedWinsockLib.FileTransferEvents

    m_sd_conn_c = _
        m_sd.ConnectionAdvise(m_sd_conn, wcaAdviseDisconnected)
    m_sd_strings_c = _
        m_sd.StringTransferAdvise(m_sd_strings, _
                                  wsaAdviseReceivedLineAlways, _
                                  wnfAnsiStrings)
    m_sd_files_c = _
        m_sd.FileTransferAdvise(m_sd_files, _
                                wfaAdviseFileReceivedAlways + wfaAdviseFileSentAlways)
End Sub

Private Sub Class_Terminate()
    ' stop whatever
    Stop_

    m_sd.ConnectionUnadvise m_sd_conn_c
    m_sd.StringTransferUnadvise m_sd_strings_c
    m_sd.FileTransferUnadvise m_sd_files_c
End Sub

Private Sub m_sd_files_OnFileReceived(ByVal xSocket As Object, ByVal sFilename As String, _
        ByVal lStartOffset As Long, ByVal lBytesReceived As Long, ByVal lBytesTotal As Long, _
        ByVal lUserParam As Long, ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)

End Sub

Private Sub m_sd_files_OnFileSent(ByVal xSocket As Object, ByVal sFilename As String, _
        ByVal lStartOffset As Long, ByVal lBytesSent As Long, ByVal lBytesTotal As Long, _
        ByVal lUserParam As Long, ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)

End Sub

Private Sub m_sd_income_OnConnectionProcessed(ByVal xListeningSocket As Object, _
        ByVal xIncomingSocket As Object, ByVal lUserParam As Long)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    Dim addr As String
    Dim s As New Session

    Set sd = xIncomingSocket
    addr = sd.RemoteAddress.GetAddressString

    s.Initialize sd

    ' Add to sessions list
    m_sessions(addr) = s

    RaiseEvent SessionBegin(s)
End Sub

Private Sub m_sd_income_OnListeningError(ByVal xListeningSocket As Object, _
        ByVal lUserParam As Long, ByVal lResultCode As Long)
    Assert xListeningSocket Is m_sd
    'If m_sd_started Then
    '    m_sd.StopListening
    '    m_sd.StartListening m_addr, m_sd_income, wifAdviseAll
    'End If
End Sub

Private Sub m_sd_conn_OnDisconnected(ByVal xSocket As Object, ByVal vaCallerData As Variant, _
        vaCalleeData As Variant)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    Dim addr As String
    Dim s As Session

    Set sd = xSocket
    addr = sd.RemoteAddress.GetAddressString

    Assert m_sessions.Contain(addr), "Session Lost", LOCATION

    Set s = m_sessions(addr)

    ' Remove from sessions list
    m_sessions.Remove addr

    RaiseEvent SessionEnd(s)
End Sub

Private Sub m_sd_strings_OnStringReceived(ByVal xSocket As Object, ByVal sString As String, _
        ByVal lUserParam As Long, ByVal lResultCode As Long)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    Dim addr As String
    Dim s As Session

    Set sd = xSocket
    addr = sd.RemoteAddress.GetAddressString

    Assert m_sessions.Contain(addr), "Session Lost", LOCATION
    Set s = m_sessions(addr)

    Dim Cmd As NtCommand
    Set Cmd = ParseCmd(sString)

    s.ProcessCommand Cmd
End Sub

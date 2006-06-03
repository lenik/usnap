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
Private WithEvents m_sd_bytes As XceedWinsockLib.ByteTransferEvents
Attribute m_sd_bytes.VB_VarHelpID = -1
Private m_sd_conn_c As Long
Private m_sd_strings_c As Long
Private m_sd_files_c As Long
Private m_sd_bytes_c As Long

' addr -> sessions
Private m_sessions As New VBExt.Map
Private m_session_events As SessionEvents

Public Event SessionRequest(ByVal RemoteAddress As String, ByRef Reject As Boolean)
Public Event SessionBegin(ByVal s As Session)
Public Event SessionEnd(ByVal s As Session)

Implements NetTools.SystemEventListener

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

Public Sub SessionAdvise(ByVal sEvents As SessionEvents)
    Set m_session_events = sEvents
    Dim k
    Dim s As Session
    For Each k In m_sessions.KeySet
        Set s = m_sessions(k)
        s.Advise m_session_events
    Next
End Sub

Public Sub SessionUnadvise()
    Set m_session_events = Nothing
    Dim k
    Dim s As Session
    For Each k In m_sessions.KeySet
        Set s = m_sessions(k)
        s.Unadvise
    Next
End Sub

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

Public Property Get Sessions() As VBExt.Map
    Set Sessions = m_sessions
End Property

Private Sub Class_Initialize()
    m_Name = Secret

    Set m_sd = SocketFactory.CreateListeningSocket(G.IP_TCP, 0)

    Set m_sd_income = New XceedWinsockLib.IncomingConnectionEvents
    Set m_sd_conn = New XceedWinsockLib.ConnectionEvents
    Set m_sd_strings = New XceedWinsockLib.StringTransferEvents
    Set m_sd_bytes = New XceedWinsockLib.ByteTransferEvents
    Set m_sd_files = New XceedWinsockLib.FileTransferEvents

    m_sd_conn_c = _
        m_sd.ConnectionAdvise(m_sd_conn, wcaAdviseDisconnected)
    'm_sd_strings_c = _
        m_sd.StringTransferAdvise(m_sd_strings, _
                                  wsaAdviseReceivedLineAlways, _
                                  wnfAnsiStrings)
    m_sd_files_c = _
        m_sd.FileTransferAdvise(m_sd_files, _
                                wfaAdviseFileReceivedAlways + wfaAdviseFileSentAlways)
    m_sd_bytes_c = _
        m_sd.ByteTransferAdvise(m_sd_bytes, _
                                wtaAdviseReceivedAlways)
End Sub

Private Sub Class_Terminate()
    ' stop whatever
    Stop_

    m_sd.ConnectionUnadvise m_sd_conn_c
    'm_sd.StringTransferUnadvise m_sd_strings_c
    m_sd.ByteTransferUnadvise m_sd_bytes_c
    m_sd.FileTransferUnadvise m_sd_files_c
End Sub

Private Sub m_sd_bytes_OnBytesReceived(ByVal xSocket As Object, ByVal vaData As Variant, _
                                       ByVal lUserParam As Long, ByVal lResultCode As Long)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    Dim addr As String
    Dim s As Session

    Set sd = xSocket
    addr = sd.RemoteAddress.GetAddressString

    Assert m_sessions.Contain(addr), "Session Lost", LOCATION
    Set s = m_sessions(addr)

    s.ProcessBytes vaData
End Sub

Private Sub m_sd_files_OnFileReceived(ByVal xSocket As Object, ByVal sFilename As String, _
                                      ByVal lStartOffset As Long, ByVal lBytesReceived As Long, _
                                      ByVal lBytesTotal As Long, ByVal lUserParam As Long, _
                                      ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    Dim addr As String
    Dim s As Session

    Set sd = xSocket
    addr = sd.RemoteAddress.GetAddressString

    Assert m_sessions.Contain(addr), "Session Lost", LOCATION
    Set s = m_sessions(addr)

    If bTransferCompleted Then
        s.ProcessFileReceived sFilename
    Else
        s.ProcessFileReceiving sFilename, lStartOffset, lBytesReceived, lBytesTotal
    End If
End Sub

Private Sub m_sd_files_OnFileSent(ByVal xSocket As Object, ByVal sFilename As String, _
                                  ByVal lStartOffset As Long, ByVal lBytesSent As Long, _
                                  ByVal lBytesTotal As Long, ByVal lUserParam As Long, _
                                  ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    Dim addr As String
    Dim s As Session

    Set sd = xSocket
    addr = sd.RemoteAddress.GetAddressString

    Assert m_sessions.Contain(addr), "Session Lost", LOCATION
    Set s = m_sessions(addr)

    If bTransferCompleted Then
        s.ProcessFileSent sFilename
    Else
        s.ProcessFileSending sFilename, lStartOffset, lBytesSent, lBytesTotal
    End If
End Sub

Private Sub m_sd_income_OnConnection(ByVal xListeningSocket As Object, _
                                     ByVal xRemoteAddress As Object, _
                                     ByVal vaCallerData As Variant, _
                                     ByVal lExpectedCalleeDataSize As Long, _
                                     vaCalleeData As Variant, _
                                     xQualityOfService As XceedWinsockLib.IdXWQualityOfServiceInfo, _
                                     lUserParam As Long, _
                                     bReject As Boolean)
    RaiseEvent SessionRequest(xRemoteAddress.GetAddressString, bReject)
End Sub

Private Sub m_sd_income_OnConnectionProcessed(ByVal xListeningSocket As Object, _
                                              ByVal xIncomingSocket As Object, _
                                              ByVal lUserParam As Long)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    Dim addr As String
    Dim s As New Session

    Set sd = xIncomingSocket

    addr = sd.RemoteAddress.GetAddressString

    ' Add to sessions list
    m_sessions(addr) = s

    s.Initialize Me, sd
    s.Advise m_session_events

    ' Now the initial commands are triggered by server.
    s.Name = m_Name
    s.SetKey
    s.SysEvent NTCE_BEGINSESSION, True

    s.Touch
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
    Dim addr
    Dim s As Session

    For Each addr In m_sessions.KeySet
        Set s = m_sessions(addr)
        If s.sd.CurrentState = wssInvalid Then
            ' Remote from sessions list
            m_sessions.Remove addr
            s.Unadvise

            RaiseEvent SessionEnd(s)
        End If
    Next
End Sub

'Private Sub m_sd_strings_OnStringReceived(ByVal xSocket As Object, ByVal sString As String, _
'                                          ByVal lUserParam As Long, ByVal lResultCode As Long)
'    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
'    Dim addr As String
'    Dim s As Session
'
'    Set sd = xSocket
'    addr = sd.RemoteAddress.GetAddressString
'
'    Assert m_sessions.Contain(addr), "Session Lost", LOCATION
'    Set s = m_sessions(addr)
'
'    Dim Cmd As NtCommand
'    Set Cmd = ParseCmd(sString)
'
'    If Cmd Is Nothing Then Exit Sub
'
'    s.ProcessCommand Cmd
'End Sub

Private Sub SystemEventListener_OnSystemEvent(ByVal s As Session, ByVal EventName As String, ByVal Initiative As Boolean, Optional Params As Variant)
    Select Case EventName
    Case NTCE_BEGINSESSION
        RaiseEvent SessionBegin(s)
    End Select
End Sub

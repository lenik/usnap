VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Client"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "NetTools::Client"
Private Const DEFAULT_ADDRESS           As String = "127.0.0.1"
Private Const DEFAULT_PORT              As Integer = 20052

Private m_Name As String

Private m_sd As XceedWinsockLib.ConnectionOrientedSocket
Private m_sd_connected As Boolean
Private m_addr As New XceedWinsockLib.InetAddress
Private WithEvents m_sd_files As XceedWinsockLib.FileTransferEvents
Attribute m_sd_files.VB_VarHelpID = -1
Private WithEvents m_sd_strings As XceedWinsockLib.StringTransferEvents
Attribute m_sd_strings.VB_VarHelpID = -1
Private WithEvents m_sd_conn As XceedWinsockLib.ConnectionEvents
Attribute m_sd_conn.VB_VarHelpID = -1
Private m_sd_files_c As Long
Private m_sd_strings_c As Long
Private m_sd_conn_c As Long

Private m_session As Session
Private m_session_events As SessionEvents

Public Event SessionBegin(ByVal s As Session)
Public Event SessionEnd(ByVal s As Session)

Public Property Get Name() As String
    Name = m_Name
End Property

Public Property Let Name(ByVal newval As String)
    m_Name = newval
End Property

Public Property Get ServerAddress() As String
    ServerAddress = m_addr.GetAddressString
End Property

Public Property Let ServerAddress(ByVal newval As String)
    m_addr.SetAddressString newval
End Property

Public Property Get ServerPort() As Integer
    ServerPort = m_addr.Port
End Property

Public Property Let ServerPort(ByVal newval As Integer)
    m_addr.Port = newval
End Property

Public Sub SessionAdvise(ByVal sEvents As SessionEvents)
    Set m_session_events = sEvents
    If Not m_session Is Nothing Then m_session.Advise m_session_events
End Sub

Public Sub SessionUnadvise()
    Set m_session_events = Nothing
    If Not m_session Is Nothing Then m_session.Unadvise
End Sub

Public Function Connect(Optional ByVal ServerAddress As String, _
                        Optional ByVal ServerPort As Integer = 0, _
                        Optional ByVal ClientName As String) As Boolean
    If ServerAddress <> "" Then Me.ServerAddress = ServerAddress
    If ServerPort <> 0 Then Me.ServerPort = ServerPort
    If ClientName <> "" Then m_Name = ClientName

    If m_sd_connected Then Disconnect
    Assert Not m_sd_connected, "Cannot disconnect", LOCATION

    On Error Resume Next
    m_sd.Connect m_addr
    If Err.Number <> 0 Then Exit Function

    Dim s As New Session
    s.Initialize m_Name, m_sd
    s.Advise m_session_events

    Set m_session = s
    m_sd_connected = True

    RaiseEvent SessionBegin(s)

    ' NETCOMM
    m_sd.SendString NtCmd(NTC_SETNAME, StringToBase64(m_Name), "S"), wnfAnsiStrings, wsoNone

    ' NETCOMM
    m_sd.SendString NtCmd(NTC_SETKEY, s.Key.PublicKey, "S"), wnfAnsiStrings, wsoNone

    ' NETCOMM
    m_sd.SendString NtCmd(NTC_TOUCH, CDbl(Date + Time), "S"), wnfAnsiStrings, wsoNone

    Connect = True
End Function

Public Function Disconnect() As Boolean
    On Error Resume Next
        m_sd.Disconnect
        Disconnect = Err.Number = 0
    On Error GoTo 0
End Function

Private Sub Class_Initialize()
    m_Name = G.Secret

    Set m_sd = SocketFactory.CreateConnectionOrientedSocket(G.IP_TCP, 0)

    Set m_sd_files = New XceedWinsockLib.FileTransferEvents
    Set m_sd_strings = New XceedWinsockLib.StringTransferEvents
    Set m_sd_conn = New XceedWinsockLib.ConnectionEvents

    m_sd_files_c = m_sd.FileTransferAdvise(m_sd_files, wfaAdviseFileReceivedAlways + wfaAdviseFileSentAlways)
    m_sd_strings_c = m_sd.StringTransferAdvise(m_sd_strings, wsaAdviseReceivedLineAlways, wnfAnsiStrings)
    m_sd_conn_c = m_sd.ConnectionAdvise(m_sd_conn, wcaAdviseDisconnected)

    m_addr.SetAddressString DEFAULT_ADDRESS
    m_addr.Port = DEFAULT_PORT
End Sub

Private Sub Class_Terminate()
    m_sd.FileTransferUnadvise m_sd_files_c
    m_sd.StringTransferUnadvise m_sd_strings_c
    m_sd.ConnectionUnadvise m_sd_conn_c
End Sub

Private Sub m_sd_conn_OnDisconnected(ByVal xSocket As Object, _
                                     ByVal vaCallerData As Variant, _
                                     vaCalleeData As Variant)
    Dim s As Session
    Set s = m_session
    Set m_session = Nothing

    m_sd_connected = False

    RaiseEvent SessionEnd(s)
End Sub

Private Sub m_sd_files_OnFileReceived(ByVal xSocket As Object, ByVal sFilename As String, _
                                      ByVal lStartOffset As Long, ByVal lBytesReceived As Long, _
                                      ByVal lBytesTotal As Long, ByVal lUserParam As Long, _
                                      ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)
    Assert xSocket Is m_sd
    Assert Not m_session Is Nothing
    If bTransferCompleted Then
        m_session.ProcessFileReceived sFilename
    Else
        m_session.ProcessFileReceiving sFilename, lStartOffset, lBytesReceived, lBytesTotal
    End If
End Sub

Private Sub m_sd_files_OnFileSent(ByVal xSocket As Object, ByVal sFilename As String, _
                                  ByVal lStartOffset As Long, ByVal lBytesSent As Long, _
                                  ByVal lBytesTotal As Long, ByVal lUserParam As Long, _
                                  ByVal bTransferCompleted As Boolean, ByVal lResultCode As Long)
    Assert xSocket Is m_sd
    Assert Not m_session Is Nothing
    If bTransferCompleted Then
        m_session.ProcessFileSent sFilename
    Else
        m_session.ProcessFileSending sFilename, lStartOffset, lBytesSent, lBytesTotal
    End If
End Sub

Private Sub m_sd_strings_OnStringReceived(ByVal xSocket As Object, ByVal sString As String, _
                                          ByVal lUserParam As Long, ByVal lResultCode As Long)
    Assert xSocket Is m_sd

    Dim Cmd As NtCommand
    Set Cmd = ParseCmd(sString)
    If Cmd Is Nothing Then Exit Sub

    m_session.ProcessCommand Cmd
End Sub

Private Sub m_sd_strings_OnStringSent(ByVal xSocket As Object, ByVal lUserParam As Long, _
                                      ByVal lResultCode As Long)
    'm_Session.ProcessCommand
End Sub

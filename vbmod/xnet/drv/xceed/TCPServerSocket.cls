VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "TCPServerSocket"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "XnetXceed::TCPServerSocket"

Private m_LocalAddress As InetAddress

Private xSocket As XceedWinsockLib.ListeningSocket
Private WithEvents xSConn As XceedWinsockLib.IncomingConnectionEvents
Attribute xSConn.VB_VarHelpID = -1
Private WithEvents xCConn As XceedWinsockLib.ConnectionEvents
Attribute xCConn.VB_VarHelpID = -1
Private WithEvents xByte As XceedWinsockLib.ByteTransferEvents
Attribute xByte.VB_VarHelpID = -1
Private lCConn As Long
Private lByte As Long

Private m_Clients As New MemberClients
Private m_AddressId As New VBExt.Map    ' Address (string) -> Id (long)

Private m_EventSink As IServerEvents

Implements IServerSocket

Private Function IServerSocket_Advise(ByVal EventSink As Xnet.IServerEvents) As Long
    Set m_EventSink = EventSink
End Function

Private Sub IServerSocket_Unadvise(Optional ByVal Cookie As Long = -1&)
    Set m_EventSink = Nothing
End Sub

Private Property Get IServerSocket_LocalAddress() As String
    IServerSocket_LocalAddress = Inaddr2Str(m_LocalAddress)
End Property

Private Sub xStart()
    xSocket.StartListening m_LocalAddress, xSConn, _
        wifAdviseConnection + wifAdviseConnectionProcessed
End Sub

Private Sub xStop()
    xSocket.StopListening
End Sub

Private Sub IServerSocket_Bind(ByVal LocalAddress As String)
    Dim Host As String
    Dim Port As Long
    Host = InaddrHost(LocalAddress)
    Port = InaddrPort(LocalAddress)

    Dim Inaddr As New InetAddress
    Inaddr.HostName = Host
    Inaddr.Port = Port
    Set m_LocalAddress = Inaddr

    xStart
End Sub

Private Sub IServerSocket_Unbind()
    xStop
End Sub

Private Property Get IServerSocket_Clients() As Long
    IServerSocket_Clients = m_Clients.Size
End Property

Private Property Get IServerSocket_ClientId(ByVal Index As Long) As Long
    IServerSocket_ClientId = m_Clients.Id(Index)
End Property

Private Property Set IServerSocket_ClientData(ByVal Id As Long, ByVal RHS As Variant)
    Dim mc As MemberClient
    Set mc = m_Clients.Item(Id)
    Assert Not mc Is Nothing, "Invalid Id", LOCATION

    Set mc.UserData = RHS
End Property

Private Property Let IServerSocket_ClientData(ByVal Id As Long, ByVal RHS As Variant)
    Dim mc As MemberClient
    Set mc = m_Clients.Item(Id)
    Assert Not mc Is Nothing, "Invalid Id", LOCATION

    mc.UserData = RHS
End Property

Private Property Get IServerSocket_ClientData(ByVal Id As Long) As Variant
    Dim mc As MemberClient
    Set mc = m_Clients.Item(Id)
    Assert Not mc Is Nothing, "Invalid Id", LOCATION

    If IsObject(mc.UserData) Then
        Set IServerSocket_ClientData = mc.UserData
    Else
        IServerSocket_ClientData = mc.UserData
    End If
End Property

Private Property Get IServerSocket_RemoteAddress(ByVal Id As Long) As String
    Dim mc As MemberClient
    Set mc = m_Clients.Item(Id)
    Assert Not mc Is Nothing, "Invalid Id", LOCATION

    IServerSocket_RemoteAddress = mc.RemoteAddress.GetAddressString
End Property

Private Sub RemoveClient(ByVal mc As MemberClient)
    m_EventSink.Disconnect mc.Id, drClosed, mc.UserData
    m_Clients.Remove mc.Id
    Set mc.xSocket = Nothing            ' (useful??)
End Sub

Private Sub IServerSocket_Disconnect(ByVal Id As Long)
    Dim mc As MemberClient
    Set mc = m_Clients.Item(Id)
    Assert Not mc Is Nothing, "Invalid Id", LOCATION

    mc.Disconnect
    RemoveClient mc
End Sub

Private Sub IServerSocket_SendBytes(ByVal Id As Long, _
                                    Bytes() As Byte, _
                                    Optional ByVal Offset As Long = 0&, _
                                    Optional ByVal Size As Long = -1&, _
                                    Optional ByVal PartialId As Long = -1&, _
                                    Optional ByVal Async As Boolean = False)
    Dim mc As MemberClient
    Set mc = m_Clients.Item(Id)
    Assert Not mc Is Nothing, "Invalid Id", LOCATION

    mc.SendBytes Bytes, Offset, Size, PartialId, Async
End Sub

Private Property Get IServerSocket_SentBytes(ByVal Id As Long) As Long
    Dim mc As MemberClient
    Set mc = m_Clients.Item(Id)
    Assert Not mc Is Nothing, "Invalid Id", LOCATION

    IServerSocket_SentBytes = mc.SentBytes
End Property

Private Property Get IServerSocket_UnsentBytes(ByVal Id As Long) As Long
    Dim mc As MemberClient
    Set mc = m_Clients.Item(Id)
    Assert Not mc Is Nothing, "Invalid Id", LOCATION

    IServerSocket_UnsentBytes = mc.UnsentBytes
End Property

Private Sub IServerSocket_ForgetSent(ByVal Id As Long)
    Dim mc As MemberClient
    Set mc = m_Clients.Item(Id)
    Assert Not mc Is Nothing, "Invalid Id", LOCATION

    mc.ForgetSent
End Sub

' Server/xCOS Events Impl.
'   Adapter to IServerSocket
' ----------------------------------------------------------------------------
Function FindClient(ByVal xSocket As Object, ByRef Id As Long) As MemberClient
    Dim xClient As XceedWinsockLib.ConnectionOrientedSocket
    Set xClient = xSocket
    Assert Not xClient Is Nothing

    Dim xRemoteAddress As Address
    Set xRemoteAddress = xClient.RemoteAddress

    Dim RemoteAddress As String
    RemoteAddress = Addr2Str(xRemoteAddress)

    Assert m_AddressId.Contain(RemoteAddress)
    Id = m_AddressId.Item(RemoteAddress)

    Set FindClient = m_Clients.Item(Id)
    Assert Not FindClient Is Nothing
End Function

Private Sub xByte_OnBytesReceived(ByVal xSocket As Object, _
                                  ByVal vaData As Variant, _
                                  ByVal lUserParam As Long, _
                                  ByVal lResultCode As Long)
    Dim Id As Long
    Dim mc As MemberClient
    Set mc = FindClient(xSocket, Id)

    ' Event may happen during disconnecting
    If mc Is Nothing Then Exit Sub

    mc.xByte_OnBytesReceived m_EventSink, xSocket, vaData, lUserParam, lResultCode
End Sub

Private Sub xByte_OnBytesSent(ByVal xSocket As Object, _
                              ByVal lBytesSent As Long, _
                              ByVal lUserParam As Long, _
                              ByVal lResultCode As Long)
    Dim Id As Long
    Dim mc As MemberClient
    Set mc = FindClient(xSocket, Id)

    ' Event may happen during disconnecting
    If mc Is Nothing Then Exit Sub

    mc.xByte_OnBytesSent m_EventSink, xSocket, lBytesSent, lUserParam, lResultCode
End Sub

' Incoming Connection Request
Private Sub xSConn_OnConnection(ByVal xListeningSocket As Object, _
                                ByVal xRemoteAddress As Object, _
                                ByVal vaCallerData As Variant, _
                                ByVal lExpectedCalleeDataSize As Long, _
                                vaCalleeData As Variant, _
                                xQualityOfService As XceedWinsockLib.IdXWQualityOfServiceInfo, _
                                lUserParam As Long, _
                                bReject As Boolean)
    Dim RemoteAddress As String
    RemoteAddress = Addr2Str(xRemoteAddress)

    m_EventSink.Request RemoteAddress, bReject
End Sub

Private Sub xSConn_OnConnectionProcessed(ByVal xListeningSocket As Object, _
                                         ByVal xIncomingSocket As Object, _
                                         ByVal lUserParam As Long)
    Dim xRemoteAddress As Address
    Set xRemoteAddress = xIncomingSocket.RemoteAddress

    Dim RemoteAddress As String
    RemoteAddress = Addr2Str(xRemoteAddress)

    Dim mc As New MemberClient
    Set mc.xSocket = xIncomingSocket

    Dim Id As Long
    Id = m_Clients.Add(mc)
    mc.Id = Id

    m_AddressId.Item(RemoteAddress) = Id

    m_EventSink.Connect Id, mc.UserData
End Sub

' Disconnected by remote
Private Sub xCConn_OnDisconnected(ByVal xObject As Object, _
                                  ByVal vaCallerData As Variant, _
                                  vaCalleeData As Variant)
    ' This xObject is in invalid-state.
    ' Dim xClient As XceedWinsockLib.ConnectionOrientedSocket
    ' Set xClient = xObject

    Dim mc As MemberClient
    Dim i As Long
    Dim Id As Long
    For i = 0 To m_Clients.Size - 1
        Id = m_Clients.Id(i)
        Set mc = m_Clients.Item(Id)
        If mc.xSocket.CurrentState = wssInvalid Then
            RemoveClient mc
        End If
    Next
End Sub

Private Sub xSConn_OnListeningError(ByVal xListeningSocket As Object, _
                                    ByVal lUserParam As Long, _
                                    ByVal lResultCode As Long)
    ' Not Implemented.
    Assert xListeningSocket Is xSocket, _
           "Unexpected xListeningSocket when ListeningError", LOCATION

    On Error Resume Next
        xStop
        xStart
    On Error GoTo 0
End Sub

' Class
' ----------------------------------------------------------------------------
Private Sub Class_Initialize()
    Set xSocket = SocketFactory.CreateListeningSocket(G.IP_TCP, 0)
    Set xSConn = New XceedWinsockLib.IncomingConnectionEvents
    Set xCConn = New XceedWinsockLib.ConnectionEvents
    Set xByte = New XceedWinsockLib.ByteTransferEvents
    lCConn = xSocket.ConnectionAdvise(xCConn, _
        wcaAdviseDisconnected)
    lByte = xSocket.ByteTransferAdvise(xByte, _
        wtaAdviseReceivedAlways + wtaAdviseSent)
End Sub

Private Sub Class_Terminate()
    xSocket.ConnectionUnadvise lCConn
    xSocket.ByteTransferUnadvise lByte
End Sub

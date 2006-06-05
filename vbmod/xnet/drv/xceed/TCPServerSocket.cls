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

Private m_LocalAddress As InetAddress

Private xSocket As XceedWinsockLib.ListeningSocket
Private WithEvents xSConn As XceedWinsockLib.IncomingConnectionEvents
Attribute xSConn.VB_VarHelpID = -1
Private WithEvents xCConn As XceedWinsockLib.ConnectionEvents
Attribute xCConn.VB_VarHelpID = -1
Private WithEvents xByte As XceedWinsockLib.ByteTransferEvents
Attribute xByte.VB_VarHelpID = -1

Private m_EventSink As IServerEvents

Private m_Clients As New TCPClientSockets

' Address => IClientEvent
Private m_ClientEventSinkTemplate As New VBExt.Map

Implements IServerSocket

Private Sub Class_Initialize()
    Set xSocket = SocketFactory.CreateListeningSocket(G.IP_TCP, 0)
    Set xSConn = New XceedWinsockLib.IncomingConnectionEvents
    Set xCConn = New XceedWinsockLib.ConnectionEvents
    Set xByte = New XceedWinsockLib.ByteTransferEvents
End Sub

Private Function IServerSocket_Advise(ByVal EventSink As Xnet.IServerEvents) As Long
    Set m_EventSink = EventSink
End Function

Private Sub IServerSocket_Bind(ByVal LocalAddress As String)
    m_LocalAddress = Str2Inaddr(LocalAddress)

    xSocket.StartListening m_LocalAddress, xSConn, _
        wifAdviseConnection + wifAdviseConnectionProcessed
End Sub

Private Property Get IServerSocket_Client(ByVal Handle As Long) As Xnet.IClientSocket
    Set IServerSocket_Client = m_Clients.Slot(Handle)
End Property

Private Property Get IServerSocket_ClientHandle(ByVal Index As Long) As Long
    IServerSocket_ClientHandle = m_Clients.Index2Slot(Index)
End Property

Private Property Get IServerSocket_Clients() As Long
    IServerSocket_Clients = m_Clients.Size
End Property

Private Property Get IServerSocket_LocalAddress() As String
    IServerSocket_LocalAddress = Inaddr2Str(m_LocalAddress)
End Property

Private Sub IServerSocket_Unadvise(Optional ByVal Cookie As Long = -1&)
    Set m_EventSink = Nothing
End Sub

Private Sub IServerSocket_Unbind()
    xSocket.StopListening
End Sub

Private Sub xCConn_OnDisconnected(ByVal xSocket As Object, ByVal vaCallerData As Variant, vaCalleeData As Variant)
    Dim sd As XceedWinsockLib.ConnectionOrientedSocket
    ' Ignore this socket.
    ' Set sd = xSocket

    Dim c As TCPClientSocket
    For Each c In m_Clients
        'm_EventSink.Disconnect c.Index
    Next
End Sub

Private Sub xSConn_OnConnection(ByVal xListeningSocket As Object, _
                                ByVal xRemoteAddress As Object, _
                                ByVal vaCallerData As Variant, _
                                ByVal lExpectedCalleeDataSize As Long, _
                                vaCalleeData As Variant, _
                                xQualityOfService As XceedWinsockLib.IdXWQualityOfServiceInfo, _
                                lUserParam As Long, _
                                bReject As Boolean)
    If Not m_EventSink Is Nothing Then
        Dim UsingWhatEventSink As IClientEvents
        Dim RemoteAddress As String

        RemoteAddress = Addr2Str(xRemoteAddress)
        m_EventSink.Request RemoteAddress, bReject, UsingWhatEventSink
        If bReject Then Exit Sub

        m_ClientEventSinkTemplate(RemoteAddress) = UsingWhatEventSink
    End If
End Sub

Private Sub xSConn_OnConnectionProcessed(ByVal xListeningSocket As Object, _
                                         ByVal xIncomingSocket As Object, _
                                         ByVal lUserParam As Long)
    Dim xRemoteAddress As Address
    Set xRemoteAddress = xIncomingSocket

    Dim RemoteAddress As String
    RemoteAddress = Addr2Str(xRemoteAddress)

    Dim ClientEventSink As IClientEvents
    If m_ClientEventSinkTemplate.Contain(RemoteAddress) Then
        Set ClientEventSink = m_ClientEventSinkTemplate(RemoteAddress)
    End If

    Dim sd As New TCPClientSocket
    Dim isd As IClientSocket
    Set isd = sd

    Set sd.Socket = xIncomingSocket
    If Not ClientEventSink Is Nothing Then
        isd.Advise ClientEventSink
    End If

    Dim Handle As Long
    Handle = m_Clients.Add(sd)
    If Not m_EventSink Is Nothing Then
        m_EventSink.Connect Handle
    End If
End Sub

Private Sub xSConn_OnListeningError(ByVal xListeningSocket As Object, ByVal lUserParam As Long, ByVal lResultCode As Long)
    If Not m_EventSink Is Nothing Then
        ' TODO
        ' ??
    End If
End Sub

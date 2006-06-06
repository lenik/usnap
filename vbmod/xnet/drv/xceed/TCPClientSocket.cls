VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "TCPClientSocket"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "XnetXceed::TCPClientSocket"

Private xSocket As XceedWinsockLib.ConnectionOrientedSocket
Private WithEvents xConn As XceedWinsockLib.ConnectionEvents
Attribute xConn.VB_VarHelpID = -1
Private WithEvents xByte As XceedWinsockLib.ByteTransferEvents
Attribute xByte.VB_VarHelpID = -1

Private m_EventSink As IClientEvents

Implements IClientSocket

Property Get Socket() As ConnectionOrientedSocket
    Set Socket = xSocket
End Property

Property Set Socket(ByVal newval As ConnectionOrientedSocket)
    Set xSocket = newval
End Property

Property Get RemoteAddress() As XceedWinsockLib.Address
    Set RemoteAddress = xSocket.RemoteAddress
End Property

Property Get LocalAddress() As XceedWinsockLib.Address
    Set LocalAddress = xSocket.LocalAddress
End Property

Private Function IClientSocket_Advise(ByVal EventSink As Xnet.IClientEvents) As Long
    Set m_EventSink = EventSink
End Function

Private Sub IClientSocket_Connect(ByVal RemoteAddress As String, _
                                  Optional ByVal LocalAddress As String)
    Dim inaddr As New InetAddress
    If LocalAddress <> "" Then
        Set xSocket.LocalAddress = Str2Inaddr(LocalAddress)
    End If

    Set inaddr = Str2Inaddr(RemoteAddress)
    xSocket.Connect inaddr
End Sub

Private Sub IClientSocket_Disconnect()
    xSocket.Disconnect
End Sub

Private Property Get IClientSocket_LocalAddress() As String
    IClientSocket_LocalAddress = Addr2Str(LocalAddress)
End Property

Private Property Get IClientSocket_RemoteAddress() As String
    IClientSocket_RemoteAddress = Addr2Str(RemoteAddress)
End Property

Private Sub IClientSocket_SendBytes(Bytes() As Byte, Optional ByVal Offset As Long = 0&, Optional ByVal Size As Long = -1&, Optional ByVal Async As Boolean = False)
    ' TODO  Bytes[..]
    xSocket.SendBytes Bytes, wsoNone
End Sub

Private Property Get IClientSocket_ServerHost() As String
    Dim in4 As InetAddress
    Set in4 = RemoteAddress
    IClientSocket_ServerHost = in4.HostName
End Property

Private Property Get IClientSocket_ServerPort() As Long
    Dim in4 As InetAddress
    Set in4 = RemoteAddress
    IClientSocket_ServerHost = in4.Port
End Property

Private Sub IClientSocket_Unadvise(Optional ByVal Cookie As Long = -1&)
    Set m_EventSink = Nothing
End Sub
VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "TCPDriver"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "XnetXceed::TCPDriver"

Private m_LastError As String

Implements ISocketDriver

Private Property Get ISocketDriver_LastError() As String
    ISocketDriver_LastError = m_LastError
End Property

Private Function ISocketDriver_Bind(ByVal LocalAddress As String, ByVal EventSink As Xnet.IServerEvents) As Xnet.IServerSocket
    Assert Not EventSink Is Nothing, "Event sink is nothing", LOCATION

    Dim sd As New TCPServerSocket
    Dim isd As IServerSocket
    Set isd = sd
    isd.Advise EventSink

    On Error GoTo x
    isd.Bind LocalAddress
    On Error GoTo 0

    Set ISocketDriver_Bind = isd
    Exit Function

x:
    m_LastError = Err.Description
End Function

Private Function ISocketDriver_Connect(ByVal RemoteString As String, _
                                       ByVal EventSink As Xnet.IClientEvents, _
                                       Optional ByVal LocalAddress As String) As Xnet.IClientSocket
    Assert Not EventSink Is Nothing, "Event sink is nothing", LOCATION

    Dim sd As New TCPClientSocket
    Dim isd As IClientSocket
    Set isd = sd
    isd.Advise EventSink

    On Error GoTo x
    isd.Connect RemoteString, LocalAddress
    On Error GoTo 0

    Set ISocketDriver_Connect = isd
    Exit Function

x:
    m_LastError = Err.Description
End Function

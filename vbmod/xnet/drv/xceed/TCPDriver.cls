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

Implements ISocketDriver

Private Function ISocketDriver_Bind(ByVal LocalAddress As String, ByVal EventSink As Xnet.IServerEvents) As Xnet.IServerSocket
    Dim sd As New TCPServerSocket
    Dim isd As IServerSocket
    Set isd = sd
    isd.Advise EventSink
    isd.Bind LocalAddress
    Set ISocketDriver_Bind = isd
End Function

Private Function ISocketDriver_Connect(ByVal RemoteString As String, _
                                       ByVal EventSink As Xnet.IClientEvents, _
                                       Optional ByVal LocalAddress As String) As Xnet.IClientSocket
    Dim sd As New TCPClientSocket
    Dim isd As IClientSocket
    Set isd = sd
    isd.Advise EventSink
    isd.Connect RemoteString, LocalAddress
    Set ISocketDriver_Connect = isd
End Function

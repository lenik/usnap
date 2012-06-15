VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Driver"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Implements ISocketDriver

Private Function ISocketDriver_Bind(ByVal Address As String, ByVal EventSink As Xnet.IServerEvents) As Xnet.IServerSocket
    Dim sd As New ServerSocket
    Dim isd As IServerSocket
    Set isd = sd
    isd.Advise EventSink
    isd.Bind Address
    Set ISocketDriver_Bind = isd
End Function

Private Function ISocketDriver_Connect(ByVal Address As String, ByVal EventSink As Xnet.IClientEvents) As Xnet.IClientSocket
    Dim sd As New ClientSocket
    Dim isd As IClientSocket
    Set isd = sd
    isd.Advise EventSink
    isd.Connect Address
    Set ISocketDriver_Connect = isd
End Function

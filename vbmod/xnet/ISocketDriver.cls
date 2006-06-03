VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ISocketDriver"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Function Bind(ByVal Port As Long, _
                     ByVal EventSink As IServerEvents) As IServerSocket
End Function

Public Function Connect(ByVal RemoteHost As String, ByVal RemotePort As Long, _
                        ByVal EventSink As IClientEvents) As iclientSocket
End Function

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

' @TAG-CLASS

Public Property Get LastError() As String
End Property

Public Function Bind(ByVal LocalAddress As String, _
                     ByVal EventSink As IServerEvents) As IServerSocket
End Function

Public Function Connect(ByVal RemoteAddress As String, _
                        ByVal EventSink As IClientEvents, _
                        Optional ByVal LocalAddress As String) As IClientSocket
End Function

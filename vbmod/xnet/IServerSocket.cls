VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "IServerSocket"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

' @TAG-CLASS

Public Property Get LocalAddress() As String

End Property

Public Function Advise(ByVal EventSink As IServerEvents) As Long

End Function

Public Sub Unadvise(Optional ByVal Cookie As Long = -1)

End Sub

Public Sub Bind(ByVal LocalAddress As String)

End Sub

Public Sub Unbind()

End Sub

Public Property Get Clients() As Long

End Property

Public Property Get ClientHandle(ByVal Index As Long) As Long

End Property

Public Property Get Client(ByVal Handle As Long) As IClientSocket

End Property

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

Public Function Advise(ByVal EventSink As IServerEvents) As Long

End Function

Public Sub Unadvise(Optional ByVal Cookie As Long = -1)

End Sub

Public Sub Bind(ByVal Port As Long)

End Sub

Public Sub Unbind()

End Sub

Public Property Get Clients() As Long

End Property

Public Property Get ClientIP(ByVal Index As Long) As String

End Property

Public Property Get ClientPort(ByVal Index As Long) As Long

End Property

Public Property Get Client(ByVal Index As Long) As iclientSocket

End Property

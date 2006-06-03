VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "IClientSocket"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
Option Base 0

Public Function Advise(ByVal EventSink As IClientEvents) As Long

End Function

Public Sub Unadvise(Optional ByVal Cookie As Long = -1)

End Sub

Public Sub Connect(ByVal RemoteIP As String, ByVal RemotePort As Long)

End Sub

Public Sub Disconnect()

End Sub

Public Sub SendBytes(ByRef Bytes() As Byte, Optional ByVal Async As Boolean = False)

End Sub

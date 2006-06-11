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

Public Function Advise(ByVal EventSink As IServerEvents) As Long
End Function

Public Sub Unadvise(Optional ByVal Cookie As Long = -1)
End Sub

Public Property Get LocalAddress() As String
End Property

Public Sub Bind(ByVal LocalAddress As String)
End Sub

Public Sub Unbind()
End Sub

Public Property Get Clients() As Long
End Property

Public Property Get ClientId(ByVal Index As Long) As Long
End Property

Public Property Get ClientData(ByVal Id As Long) As Variant
End Property

Public Property Let ClientData(ByVal Id As Long, ByVal newval As Variant)
End Property

Public Property Set ClientData(ByVal Id As Long, ByVal newval As Variant)
End Property

Public Property Get RemoteAddress(ByVal Id As Long) As String
End Property

Public Sub Disconnect(ByVal Id As Long)
End Sub

Public Sub SendBytes(ByVal Id As Long, _
                     ByRef Bytes() As Byte, _
                     Optional ByVal Offset As Long = 0, _
                     Optional ByVal Size As Long = -1, _
                     Optional ByVal PartialId As Long = -1, _
                     Optional ByVal Async As Boolean = False)
End Sub

Public Property Get SentBytes(ByVal Id As Long) As Long
End Property

Public Property Get UnsentBytes(ByVal Id As Long) As Long
End Property

Public Sub ForgetSent(ByVal Id As Long)
End Sub

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

' @TAG-CLASS

Public Function Advise(ByVal EventSink As IClientEvents) As Long
End Function

Public Sub Unadvise(Optional ByVal Cookie As Long = -1)
End Sub

Public Property Get LocalAddress() As String
End Property

Public Property Get RemoteAddress() As String
End Property

Public Sub Connect(ByVal RemoteAddress As String, _
                   Optional ByVal LocalAddress As String)
End Sub

Public Sub Disconnect()
End Sub

Public Sub SendBytes(ByRef Bytes() As Byte, _
                     Optional ByVal Offset As Long = 0, _
                     Optional ByVal Size As Long = -1, _
                     Optional ByVal PartialId As Long = -1, _
                     Optional ByVal Async As Boolean = False)
End Sub

Public Property Get SentBytes() As Long
End Property

Public Property Get UnsentBytes() As Long
End Property

Public Sub ForgetSent()
End Sub

VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Channel"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

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

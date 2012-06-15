VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "IServerEvents"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

' @TAG-CLASS

Public Enum DisconnectReasonConstants
    drClosed
    drErrored
End Enum

Public Sub Request(ByVal RemoteAddress As String, _
                   ByRef Reject As Boolean)
End Sub

Public Sub Connect(ByVal Id As Long, ByRef Data As Variant)
End Sub

Public Sub Disconnect(ByVal Id As Long, _
                      ByVal Reason As DisconnectReasonConstants, _
                      ByRef Data As Variant)
End Sub

Public Sub RecvBytes(ByVal Id As Long, _
                     ByRef Bytes() As Byte, _
                     ByRef UnrecvBytes As Long)
End Sub

Public Sub SentBytes(ByVal Id As Long, _
                     ByVal Size As Long, _
                     ByVal PartialId As Long, _
                     ByVal PartialOffset As Long, _
                     ByVal PartialRemain As Long)
End Sub

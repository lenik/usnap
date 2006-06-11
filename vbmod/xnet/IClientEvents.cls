VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "IClientEvents"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
Option Base 0

' @TAG-CLASS

Public Sub Connect()
End Sub

Public Sub Disconnect(ByVal Reason As DisconnectReasonConstants)
End Sub

Public Sub RecvBytes(ByRef Bytes() As Byte, _
                     ByRef UnrecvBytes As Long)
End Sub

Public Sub SentBytes(ByVal Size As Long, _
                     ByVal PartialId As Long, _
                     ByVal PartialOffset As Long, _
                     ByVal PartialRemain As Long)
End Sub

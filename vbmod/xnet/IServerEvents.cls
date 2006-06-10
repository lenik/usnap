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
                   ByRef Reject As Boolean, ByRef EventSink As IClientEvents)

End Sub

Public Sub Connect(ByVal Handle As Long)

End Sub

Public Sub Disconnect(ByVal Handle As Long, _
                      ByVal Reason As DisconnectReasonConstants)

End Sub

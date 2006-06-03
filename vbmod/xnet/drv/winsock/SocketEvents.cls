VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "SocketEvents"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Sub OnClose()

End Sub

Public Sub OnConnect()

End Sub

Public Sub OnConnectionRequest(ByVal requestID As Long)

End Sub

Public Sub OnDataArrival(ByVal bytesTotal As Long)

End Sub

Public Sub OnError(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)

End Sub

Public Sub OnSendComplete()

End Sub

Public Sub OnSendProgress(ByVal bytesSent As Long, ByVal bytesRemaining As Long)

End Sub

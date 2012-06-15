VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Socket"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_ctrl As Winsock
Private m_ctrl_index As Integer
Private m_servmode As Boolean

Public Enum SocketFlagsConstants
    sfAutoRebind = &H1&
    sfAutoReconnect = &H2&
    sfAutoErrorHandler = &H4&
    sfSkipIncoming = &H100&
    sfSkipOutgoing = &H200&
End Enum

Private m_flags As SocketFlagsConstants

' Layer: Socket commons
    Event Stopped()
' Layer: Winsock -> Socket
    Event Closing()
    Event Closed()
    Event Connected()
    Event ConnectionRequest(ByVal requestID As Long)
    Event DataArrival(ByVal BytesTotal As Long)
    Event Error(ByVal Number As Integer, Description As String, _
                ByVal Scode As Long, ByVal Source As String, _
                ByVal HelpFile As String, ByVal HelpContext As Long, _
                CancelDisplay As Boolean)
    Event SendComplete()
    Event SendProgress(ByVal BytesSent As Long, ByVal bytesRemaining As Long)

' Socket API

Public Tag As String

Public Function Send(Data As Variant, ByVal Size As Long, _
                     Optional ByVal Blocked As Boolean) As Long
    ' m_ctrl.SendData pData
    ' Send m_ctrl.SocketHandle
End Function

Public Function Recv(Data As Variant, ByVal Size As Long, _
                     Optional ByVal Blocked As Boolean) As Long
    '
End Function

Public Function Peek(Data As Variant, ByVal Size As Long, _
                     Optional ByVal Blocked As Boolean) As Long
    '
End Function

Public Sub Close_(Optional ByVal Blocked As Boolean, Optional ByVal Wait_ms As Long = -1)
    If Wait_ms < 0 Then Wait_ms = &H7FFFFFFF
    ' if pending data...
    m_ctrl.Close
End Sub

Sub Rebind()

End Sub

Sub Reconnect()

End Sub

' Class

Private Sub Class_Initialize()
    m_ctrl_index = Ctrls.Allocate
    Set m_ctrl = Ctrls(m_ctrl_index)
End Sub

Private Sub Class_Terminate()
    Set m_ctrl = Nothing
    Ctrls.Free m_ctrl_index
End Sub


' Layer: Socket commons

Private Sub OnStopped()
    RaiseEvent Stopped
End Sub

' Layer: Winsock -> Socket

Friend Sub OnClose()
    RaiseEvent Closing
    OnStopped
End Sub

Friend Sub OnConnect()
    RaiseEvent Connected
End Sub

Friend Sub OnConnectionRequest(ByVal requestID As Long)
    RaiseEvent ConnectionRequest(requestID)
End Sub

Friend Sub OnDataArrival(ByVal BytesTotal As Long)
    RaiseEvent DataArrival(BytesTotal)
End Sub

Friend Sub OnError(ByVal Number As Integer, Description As String, _
                   ByVal Scode As Long, ByVal Source As String, _
                   ByVal HelpFile As String, ByVal HelpContext As Long, _
                   CancelDisplay As Boolean)
    If m_servmode And sfAutoRebind Then
        Rebind
    ElseIf Not m_servmode And sfAutoReconnect Then
        Reconnect
    Else
        RaiseEvent Error(Number, Description, Scode, Source, HelpFile, HelpContext, CancelDisplay)
    End If
    OnStopped
End Sub

Friend Sub OnSendComplete()
    RaiseEvent SendComplete
End Sub

Friend Sub OnSendProgress(ByVal BytesSent As Long, ByVal bytesRemaining As Long)
    RaiseEvent SendProgress(BytesSent, bytesRemaining)
End Sub

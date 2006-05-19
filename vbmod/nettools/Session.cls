VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Session"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public RemoteHost As String
Public RemotePort As Integer

Private m_Name As String
Private m_PeerName As String

Private m_Key As KeyExchange
Private m_PeerKey As KeyExchange

Private m_Connected As Boolean

Property Get Key() As KeyExchange
    If m_Key Is Nothing Then
        Set m_Key = New KeyExchange
    End If
    Set Key = m_Key
End Property

Property Get PeerKey() As KeyExchange
    If m_PeerKey Is Nothing Then
        Set m_PeerKey = New KeyExchange
    End If
    Set PeerKey = m_PeerKey
End Property

Public Sub Connect()
    If m_Connected Then Exit Sub
    ' connect and exchange keys

End Sub

Public Sub SendMessage(ByVal message As String)
    Connect
End Sub

Public Sub SendFile()
    Connect
End Sub

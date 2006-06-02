VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Connection"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private WithEvents m_Socket As Socket

Private m_Name As String
Private m_Key As KeyExchange

Public Event OnPreRecvCommand(ByVal c As Command, ByRef Cancel As Boolean)
Public Event OnRecvCommand(ByVal c As Command)

Public Event OnPreSendCommand(ByVal c As Command, ByRef Cancel As Boolean)
Public Event OnSentCommand(ByVal c As Command)

Public Property Get Socket() As Socket
    Set Socket = m_Socket
End Property

Public Sub Connect(ByVal RemoteHost As String, _
                   Optional ByVal RemotePort As Long = DEFAULT_PORT)
    m_Socket.Connect RemoteHost, RemotePort
End Sub

Public Sub Accept(ByVal requestID As Long)
    m_Socket.Accept requestID
End Sub

Public Sub SetName(ByVal NewName As String)
    m_Name = NewName
End Sub

Public Sub SetKey(ByVal k As KeyExchange)
    Set m_Key = k
End Sub

Private Sub Class_Initialize()
    Set m_Socket = New Socket
End Sub

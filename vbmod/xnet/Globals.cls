VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Globals"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_RegisteredDrivers As New VBExt.Map

Public Property Get XnetDrivers(ByVal Name As String) As ISocketDriver
    If m_RegisteredDrivers.Contain(Name) Then
        Set XnetDrivers = m_RegisteredDrivers(Name)
    End If
End Property

Public Sub XnetRegisterDriver(ByVal Name As String, ByVal Driver As ISocketDriver)
    m_RegisteredDrivers(Name) = Driver
End Sub

Public Sub XnetUnregisterDriver(ByVal Name As String)
    If m_RegisteredDrivers.Contain(Name) Then
        m_RegisteredDrivers.Remove Name
    End If
End Sub

Public Function XnetConnect(ByVal ServerHost As String, _
                            Optional ByVal ServerPort As Integer = DEFAULT_PORT) As Client
    Set XnetConnect = GlobalsSingleton.XnetConnect(ServerHost, ServerPort)
End Function

Public Property Get XnetCommands() As CommandsClient

End Property

Public Function InaddrHost(ByVal Address As String) As String
    If IsNumeric(Address) Then
        InaddrHost = "127.0.0.1"
    ElseIf InStr(Address, ":") Then
        InaddrHost = Left(Address, InStr(Address, ":") - 1)
        If InaddrHost = "" Then InaddrHost = "127.0.0.1"
    Else
        InaddrHost = Address
    End If
End Function

Public Function InaddrPort(ByVal Address As String) As Long
    If IsNumeric(Address) Then
        InaddrPort = Val(Address)
    ElseIf InStr(Address, ":") Then
        InaddrPort = Val(Mid(Address, InStr(Address, ":") + 1))
    Else
        InaddrPort = 0
    End If
End Function

Public Function InaddrIP(ByVal Address As String) As String
    ' InaddrIP = resolve(InaddrHost)
End Function

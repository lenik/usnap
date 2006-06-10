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

Public Property Get XnetDriverNames() As Collection
    Set XnetDriverNames = m_RegisteredDrivers.KeySet
End Property

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

Public Function InaddrHost(ByVal Address As String) As String
    InaddrHost = GlobalsSingleton.InaddrHost(Address)
End Function

Public Function InaddrPort(ByVal Address As String) As Long
    InaddrPort = GlobalsSingleton.InaddrPort(Address)
End Function

Public Function InaddrIP(ByVal Address As String) As String
    InaddrIP = GlobalsSingleton.InaddrIP(Address)
End Function

Private Sub Class_Initialize()
    LicenseManager_WSL.License LICENSE_XC_WINSOCK
End Sub

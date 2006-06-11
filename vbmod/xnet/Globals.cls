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

' Xnet Functions
' ----------------------------------------------------------------------------
Public Property Get XnetDriverNames() As Collection
    Set XnetDriverNames = m_RegisteredDrivers.KeySet
End Property

Public Property Get XnetDriver(ByVal Name As String) As ISocketDriver
    If m_RegisteredDrivers.Contain(Name) Then
        Set XnetDriver = m_RegisteredDrivers(Name)
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

Public Property Get XnetCreate(Optional ByVal Driver As Variant) As Network
    ' DriverName or DriverClass
    If VarType(Driver) = vbString Then
        If m_RegisteredDrivers.Contain(Driver) Then
            Set Driver = XnetDriver(Driver)
        Else
            Set Driver = CreateObject(Driver)
        End If
    End If

    ' Anything other than string
    If Not IsObject(Driver) Then
        Set Driver = Nothing
    End If

    ' Get the first driver (default)
    If Driver Is Nothing Then
        Dim k
        For Each k In m_RegisteredDrivers.KeySet
            Set Driver = m_RegisteredDrivers.Item(k)
            Exit For
        Next
    End If

    If Not Driver Is Nothing Then
        Set XnetCreate = New Network
        Set XnetCreate.Driver = Driver
    End If
End Property

' Tools
' ----------------------------------------------------------------------------
Public Function InaddrHost(ByVal Address As String) As String
    InaddrHost = GlobalsSingleton.InaddrHost(Address)
End Function

Public Function InaddrPort(ByVal Address As String) As Long
    InaddrPort = GlobalsSingleton.InaddrPort(Address)
End Function

Public Function InaddrIP(ByVal Address As String) As String
    InaddrIP = GlobalsSingleton.InaddrIP(Address)
End Function

Property Get NextUniqueId() As Long
    g_NextUniqueId = g_NextUniqueId + 1
    NextUniqueId = g_NextUniqueId
End Property

Private Sub Class_Initialize()
    LicenseManager_WSL.License LICENSE_XC_WINSOCK

    Randomize Timer
    g_NextUniqueId = Int(Rnd * 1000000000)
End Sub

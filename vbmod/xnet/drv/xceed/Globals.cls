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

Private Const LOCATION                  As String = "XnetXceed::Globals"

Public IP_TCP As XceedWinsockLib.Protocol
Public IP_UDP As XceedWinsockLib.Protocol

Public Property Get SocketFactory() As SocketFactory
    Set SocketFactory = GlobalsSingleton.SocketFactory
End Property

Public Property Get Protocols() As XceedWinsockLib.Protocols
    Set Protocols = GlobalsSingleton.Protocols
End Property

Public Property Get AddressManager() As XceedWinsockLib.AddressManager
    Set AddressManager = GlobalsSingleton.AddressManager
End Property

Private Sub Class_Initialize()
    On Error Resume Next

    LicenseManager_WSL.License "WSL12-KW6C3-3X1GE-BWLA"

    Set IP_TCP = Protocols.GetProtocol(wafUnspecified, wstUnspecified, wptIP_TCP)
    Assert Not IP_TCP Is Nothing, "IP/TCP isn't supported", LOCATION

    Set IP_UDP = Protocols.GetProtocol(wafUnspecified, wstUnspecified, wptIP_UDP)
    Assert Not IP_UDP Is Nothing, "IP/UDP isn't supported", LOCATION
End Sub

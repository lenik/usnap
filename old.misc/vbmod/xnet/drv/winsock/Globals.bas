Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Public Protocols As New Protocols
Public AddressManager As New AddressManager
Public SocketFactory As New SocketFactory

Public LicenseManager_WSL As New XceedWinsockLib.LicenseManager

Public G As New Globals

Public Sub Main()

End Sub

Public Function Str2Addr(ByVal Address As String) As Address
'    Dim Inaddr As New InetAddress
'    Inaddr.HostName = InaddrHost(Address)
'    Inaddr.Port = inaddrport(Address)
    Set Str2Addr = AddressManager.GetAddressFromString(Address, wafInet)
End Function

Public Function Addr2Str(ByVal Address As Address) As String
'    Dim Inaddr As InetAddress
'    Set Inaddr = Address
'    Xceed2Addr = Inaddr.HostName & ":" & Inaddr.Port
    Addr2Str = Address.GetAddressString
End Function

Public Function Str2Inaddr(ByVal Address As String) As InetAddress
    Set Str2Inaddr = Str2Addr(Address)
End Function

Public Function Inaddr2Str(ByVal Address As Address) As String
    Inaddr2Str = Addr2Str(Address)
End Function

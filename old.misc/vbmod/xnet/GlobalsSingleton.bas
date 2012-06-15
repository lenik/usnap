Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Public G As New Globals

Public LicenseManager_WSL As New XceedWinsockLib.LicenseManager
Public AddressManager As New XceedWinsockLib.AddressManager

Public g_NextUniqueId As Long

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
    Dim Addrs As Addresses
    Dim Addr As Address
    Set Addrs = AddressManager.GetAddressesFromHostName(Address, wnsDNS)
    If Addrs.Count > 0 Then
        Set Addr = Addrs.Item(1)
        InaddrIP = Addr.GetAddressString
    End If
End Function

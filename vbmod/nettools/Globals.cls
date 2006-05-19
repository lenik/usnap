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

Private Const LOCATION                  As String = "NetTools::Globals"

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

Public Property Get Secret(Optional ByVal MinLen As String = 4, Optional ByVal MaxLen As String = 30) As String
    Dim Consonnants As String
    Dim Vowels As String
    Dim I As Integer
    Dim Name As String

    If MaxLen < 1 Then Exit Property

    Consonnants = "bcdglmnprstvwyz"
    Vowels = "aeiou"

    Do
        For I = 1 To Rnd * 2 + 1
            Name = Name & Mid(Consonnants, Rnd * Len(Consonnants) + 1, 1) & Mid(Vowels, Rnd * (Len(Vowels) - 1) + 1, 1)
        Next I
    Loop Until Len(Name) > 2

    If Len(Name) = 3 And Int(Rnd * 3) = 0 Then Name = Name & Name
    If Len(Name) = 3 And Int(Rnd * 3) = 0 Then Name = Mid(Name, 3, 1) & Mid(Name, 2, 1) & Name
    Name = UCase(Left(Name, 1)) + Trim(Mid(Name, 2))
    If Len(Name) > 4 And Int(Rnd * 3) = 0 Then Name = Left(Name, Len(Name) - 1)
    I = Int(Rnd * 3)
    If Len(Name) > 4 And Int(Rnd * 15) = 0 Then Name = Left(Name, 1 + I) & "-" & Mid(Name, 3 + I)
    If Len(Name) < 7 And Int(Rnd * 15) = 0 Then Name = Name & Mid(" Jr. Sr.ssonson boy girlman manndude2000 2.0oo   #1 ", Int(Rnd * 13) * 4 + 1, 4)
    If Len(Name) < 7 And Int(Rnd * 15) = 0 Then Name = Trim(Mid("Dr. Mr. Ms. Joe ", Int(Rnd * 4) * 4 + 1, 4)) & " " & Name

    Secret = Trim(Name)

    If Len(Secret) = MinLen - 1 Then
        ' if concat with another secret may get a space, so re-generate it
        Secret = Secret(MinLen, MaxLen)
    ElseIf Len(Secret) < MinLen Then
        Secret = Secret & " " & Secret(MinLen - Len(Secret) - 1, MaxLen - Len(Secret) - 1)
    End If

    If Len(Secret) >= MaxLen Then
        Secret = Left(Secret, MaxLen)
        If Right(Secret, 1) = " " Then
            Secret = Left(Secret, Len(Secret) - 1) & "."
        End If
    End If
End Property

Private Sub Class_Initialize()
    On Error Resume Next

    LicenseManager_WSL.License "WSL12-KW6C3-3X1GE-BWLA"

    Set IP_TCP = Protocols.GetProtocol(wafUnspecified, wstUnspecified, wptIP_TCP)
    Assert Not IP_TCP Is Nothing, "IP/TCP isn't supported", LOCATION

    Set IP_UDP = Protocols.GetProtocol(wafUnspecified, wstUnspecified, wptIP_UDP)
    Assert Not IP_UDP Is Nothing, "IP/UDP isn't supported", LOCATION
End Sub

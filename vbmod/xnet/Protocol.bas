Attribute VB_Name = "Protocol"
Option Explicit

' Register(): long
Public Const NC_REGISTER                As String = "REG"

' Unregister(long)
Public Const NC_UNREGISTER              As String = "URG"

' SetName(string): string
Public Const NC_SETNAME                 As String = "STN"

' SetKey(string): string
Public Const NC_SETKEY                  As String = "STK"

' SetSessionKey(string): string
Public Const NC_SETSESSIONKEY           As String = "SSK"

' System(char[4], string): string
Public Const NC_SYSTEM                  As String = "SYS"

' Touch(float): float
Public Const NC_TOUCH                   As String = "TCH"

' Message(string)
Public Const NC_MESSAGE                 As String = "MSG"

' FileInfo(long id, long size, long pkt_size, char[20], string, fullname)
Public Const NC_FILEINFO                As String = "PFI"

' FilePacket(long id, long pkt_index, long pkt_size, char[20], string*): control
'   control:
'       A Acknowledged
'       C Canceled the entire file
'       R Request for re-sending
Public Const NC_FILEPACKET              As String = "PFK"

' Invite([in_addr redirect-to])
Public Const NC_INVITE                  As String = "INV"

Public Function MakePacket(ByVal CmdName As String, _
                           ParamArray Parameters()) As Packet
    Dim Pkt As New Packet
    Pkt.Name = CmdName
    Pkt.Parameters = Parameters
    Set MakePacket = Pkt
End Function

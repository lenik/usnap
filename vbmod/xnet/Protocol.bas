Attribute VB_Name = "Protocol"
Option Explicit
Option Base 0

' Register(): long
Public Const NC_REGISTER                As String = "REG"

' Unregister(long)
Public Const NC_UNREGISTER              As String = "URG"

' SetName(string): string
Public Const NC_SETNAME                 As String = "STN"

' SetKey(string): string
Public Const NC_SETKEY                  As String = "STK"

' SetSessionKey(string): string
Public Const NC_SETSHAREDKEY           As String = "SSK"

' System(char[4], string): string
Public Const NC_SYSTEM                  As String = "SYS"

' Touch(float): float
Public Const NC_TOUCH                   As String = "TCH"

' Message(string)
Public Const NC_MESSAGE                 As String = "MSG"

' Script(string lang, string script)
Public Const NC_SCRIPT                  As String = "PRG"

' PutFile(long id, long size, long pkt_size, char[20], string fullname)
'  Return(long id, char control)
' control:
'       A Acknowledged
'       C Cancel the file.
Public Const NC_PUTFILE                 As String = "PUT"

' PutFileC(long id, char control)
' control:
'       C Cancel the file
Public Const NC_PUTFILE_C               As String = "PUTC"

' FilePacket(long id, long pkt_index, long pkt_size, char[20], string*)
'     Return(long id, char control)
' control:
'       A Acknowledged
'       C Cancel the entire file
'       R Request for re-sending
Public Const NC_FILEPACKET              As String = "PFK"

' Invite([in_addr redirect-to])
Public Const NC_INVITE                  As String = "INV"

' TODO: Profile
Public Function MakePacket(ByVal CmdName As String, _
                           ByVal Encrypted As Boolean, _
                           ByVal Key As SymCrypto, _
                           ByVal Sequence As Long, _
                           ParamArray Args()) As Packet
    If Encrypted Then Assert Not Key Is Nothing

    Dim Pkt As New Packet
    Set Pkt.Key = Key
    Pkt.Encrypted = Encrypted
    Pkt.Name = CmdName
    Pkt.Sequence = Sequence

    Dim i As Integer
    Assert LBound(Args) = 0
    For i = 0 To UBound(Args)
        Pkt.XArg(i) = Args(i)
    Next

    Set MakePacket = Pkt
End Function

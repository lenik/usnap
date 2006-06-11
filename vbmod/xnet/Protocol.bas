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

' Script(string lang, string script)
Public Const NC_SCRIPT                  As String = "PRG"

' PutFile(long id, long size, long pkt_size, char[20], string fullname)
Public Const NC_PUTFILE                 As String = "PUT"

' Cancel(long id)
Public Const NC_CANCEL                  As String = "CAN"

' FilePacket(long id, long pkt_index, long pkt_size, char[20], string*): control
'   control:
'       A Acknowledged
'       C Canceled the entire file
'       R Request for re-sending
Public Const NC_FILEPACKET              As String = "PFK"

' Invite([in_addr redirect-to])
Public Const NC_INVITE                  As String = "INV"

' TODO: Profile
Public Function MakePacket(ByVal CmdName As String, _
                           Optional ByVal Encrypted As Boolean = False, _
                           Optional ByVal Sequence As Long, _
                           Optional ByVal Param0, _
                           Optional ByVal Param1, _
                           Optional ByVal Param2, _
                           Optional ByVal Param3, _
                           Optional ByVal Param4, _
                           Optional ByVal Param5, _
                           Optional ByVal Param6, _
                           Optional ByVal Param7, _
                           Optional ByVal Param8, _
                           Optional ByVal Param9) As Packet
    Dim nparams As Integer
    If IsMissing(Param0) Then
        nparams = 0
    ElseIf IsMissing(Param1) Then
        nparams = 1
    ElseIf IsMissing(Param2) Then
        nparams = 2
    ElseIf IsMissing(Param3) Then
        nparams = 3
    ElseIf IsMissing(Param4) Then
        nparams = 4
    ElseIf IsMissing(Param5) Then
        nparams = 5
    ElseIf IsMissing(Param6) Then
        nparams = 6
    ElseIf IsMissing(Param7) Then
        nparams = 7
    ElseIf IsMissing(Param8) Then
        nparams = 8
    ElseIf IsMissing(Param9) Then
        nparams = 9
    Else
        nparams = 10
    End If

    ReDim Params(-1 To nparams - 1)
    If nparams > 0 Then
      Params(0) = Param0
      If nparams > 1 Then
        Params(1) = Param1
        If nparams > 2 Then
          Params(2) = Param2
          If nparams > 3 Then
            Params(3) = Param3
            If nparams > 4 Then
              Params(4) = Param4
              If nparams > 5 Then
                Params(5) = Param5
                If nparams > 6 Then
                  Params(6) = Param6
                  If nparams > 7 Then
                    Params(7) = Param7
                    If nparams > 8 Then
                      Params(8) = Param8
                      If nparams > 9 Then
                        Params(9) = Param9
                      End If '9
                    End If '8
                  End If '7
                End If '6
              End If '5
            End If '4
          End If '3
        End If '2
      End If '1
    End If '0

    Dim Pkt As New Packet
    Pkt.Name = CmdName
    Pkt.Encrypted = Encrypted
    Pkt.Sequence = Sequence
    'Pkt.Args = Params
    Set MakePacket = Pkt
End Function

Public Function ParsePacket(ByRef Bytes() As Byte, Optional ByVal MaxParams As Integer = 1, _
                            Optional Sep As String = " ", _
                            Optional ByVal RawMode As Boolean = True) As Packet
    Dim Pkt As New Packet
    'Pkt.Decode Bytes, MaxParams, Sep, RawMode
    Set ParsePacket = Pkt
End Function

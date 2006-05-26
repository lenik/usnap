Attribute VB_Name = "NtCommands"
Option Explicit

' SetName(sender-name, 'S'): recver-name/'R'
Public Const NTC_SETNAME                As String = "NSN"

' SetKey(sender-key, 'S'): recver-key/'R'
Public Const NTC_SETKEY                 As String = "NSK"

' Touch(sender-time, 'S'): recver-time/'R'
Public Const NTC_TOUCH                  As String = "NTC"

' Message(message, 'S'): ack-message/'R'
Public Const NTC_MESSAGE                As String = "NMS"

' EncryptedMessage(encrypted-message, 'S'): ack-encrypted-message/R
Public Const NTC_ENCRYPTEDMESSAGE       As String = "NEM"

' PutFile(tr-id, size, [name], [cat], [hash], [cancel-pattern], _
'         <size bytes>...>): ack/_R
' NPF .... ; \n
' xxxx...xxx
Public Const NTC_PUTFILE                As String = "NPF"
Public Const NTC_PUTFILE_CANCELPATTERN  As String = "<CaNCeLPaTTeRN " + "9E515880-3C22-48c7-B300-78E34A048875>"

' PutFileR(code), code ::=
'   A   Acknowledge
'   R   Resend
'   RR  Resend-Rejected
'   CS  Cancel-Sending
'   CR  Cancel-Receiving
Public Const NTC_PUTFILE_R              As String = "NPFR"

' Get(tr-id, uri)
Public Const NTC_GET                    As String = "NGT"

' Response(tr-id, size)
' NRS ... nnn; \n
' xxxx...xxx
Public Const NTC_RESPONSE               As String = "NRS"

' Scripting(lang, script, 'S', sign): result/_R
Public Const NTC_SCRIPT                 As String = "NSC"
Public Const NTC_SCRIPT_R               As String = "NSCR"

Public Property Get NtCmd(ByVal Cmd As String, ParamArray params_()) As String
    Dim params
    params = ParamArrayToArray(params_)

    NtCmd = Cmd & " " & Join(params, " ") & ";" & vbNewLine
End Property

Public Function ParseCmd(ByVal CmdLine As String) As NtCommand
    Dim c As String
    Do
        c = Right(CmdLine, 1)
        If c = vbLf Or c = vbCr Or c = ";" Or c = " " Then
            CmdLine = Left(CmdLine, Len(CmdLine) - 1)
        Else
            Exit Do
        End If
    Loop
    ' Skip, return nothing
    If CmdLine = "" Then Exit Function

    Set ParseCmd = New NtCommand
    ParseCmd.Init CmdLine
End Function

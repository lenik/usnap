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

' VolInfo(vol-guid): vol-infoo/_R
' VolInfoR(vol-guid vol-cat vol-name vol-segs)
Public Const NTC_VOLINFO                As String = "NVI"
Public Const NTC_VOLINFO_R              As String = "NVIR"

' PutVol(vol-guid, vol-index, vol-data)
Public Const NTC_PUTVOL                 As String = "NPV"

' ReqVol(vol-guid, vol-index): vol-data/PUTVOL
Public Const NTC_REQVOL                 As String = "NRV"

' AcptVol(vol-guid, vol-index)
Public Const NTC_ACPTVOL                As String = "NAV"

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

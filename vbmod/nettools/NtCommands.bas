Attribute VB_Name = "NtCommands"
Option Explicit

' NewSession(sender-name): recver-name/echo
Public Const NTC_NEWSESSION             As String = "NNS"

' Touch(local-time)
Public Const NTC_TOUCH                  As String = "NTC"

' SetKey(sender-key): recver-key/echo
Public Const NTC_SETKEY                 As String = "NSK"

' Message(message)
Public Const NTC_MESSAGE                As String = "NMS"

' EncryptedMessage(encrypted-message)
Public Const NTC_ENCRYPTEDMESSAGE       As String = "NEM"

' VolInfo(vol-guid): vol-info-xml/_R
Public Const NTC_VOLINFO                As String = "NVI"
Public Const NTC_VOLINFO_R              As String = "NVIR"

' PutVol(vol-guid, vol-index, vol-data)
Public Const NTC_PUTVOL                 As String = "NPV"

' ReqVol(vol-guid, vol-index): vol-data/PUTVOL
Public Const NTC_REQVOL                 As String = "NRV"

' AcptVol(vol-guid, vol-index)
Public Const NTC_ACPTVOL                As String = "NAV"

' Scripting(lang, script, sign): result/_R
Public Const NTC_SCRIPT                 As String = "NSC"
Public Const NTC_SCRIPT_R               As String = "NSCR"

Public Property Get NtCmd(ByVal Cmd As String, ParamArray Params()) As String
    NtCmd = Cmd & Join(Params, " ") & ";"
End Property

Public Function ParseCmd(ByVal CmdLine As String) As NtCommand
    Set ParseCmd = New NtCommand
    ParseCmd.Init CmdLine
End Function

VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Session"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public RemoteHost As String
Public RemotePort As Integer

Private m_Name As String
Private m_PeerName As String

Private m_Key As New KeyExchange
Private m_PeerKey As New KeyExchange

Private m_sd As XceedWinsockLib.ConnectionOrientedSocket

Private m_base64 As New BinaryLib.Base64

Property Get Key() As KeyExchange
    Set Key = m_Key
End Property

Property Get PeerKey() As KeyExchange
    Set PeerKey = m_PeerKey
End Property

Public Sub SendMessage(ByVal Message As String, Optional ByVal Encrypted As Boolean = False)
    If Encrypted Then
        Message = PeerKey.EncryptMessage(Message)
        m_sd.SendString NtCmd(NTC_ENCRYPTEDMESSAGE, Message), wnfAnsiStrings, wsoNone
    Else
        m_base64.SetStringB Message
        Message = m_base64.GetBase64
        m_sd.SendString NtCmd(NTC_MESSAGE, Message), wnfAnsiStrings, wsoNone
    End If
End Sub

Public Sub SendFile()
    '
End Sub

Friend Sub ProcessCommand(ByVal cmd As NtCommand)
    Select Case UCase(cmd.Name)
    Case NTC_NEWSESSION
    Case NTC_SETKEY
    Case NTC_TOUCH
    Case NTC_MESSAGE
    Case NTC_ENCRYPTEDMESSAGE
    Case NTC_PUTVOL
    Case NTC_REQVOL
    Case NTC_ACPTVOL
    Case NTC_SCRIPT
    Case NTC_SCRIPT_R
    Case NTC_VOLINFO
    Case NTC_VOLINFO_R
    End Select
End Sub

Private Sub Class_Initialize()
    Key.GenerateKeys
End Sub

Attribute VB_Name = "modLMMsg"

Type LPBYTE
    address As Long
End Type

Declare Function NetMessageNameAdd Lib "NetApi32.dll" (ByVal servername As String, ByVal msgname As String) As Long
Declare Function NetMessageNameEnum Lib "NetApi32.dll" (ByVal servername As String, ByVal level As Long, bufptr As LPBYTE, ByVal prefmaxlen As Long, entriesread As Long, totalentries As Long, resume_handle As Long) As Long
Declare Function NetMessageNameGetInfo Lib "NetApi32.dll" (ByVal servername As String, ByVal msgname As String, ByVal level As Long, bufptr As LPBYTE) As Long
Declare Function NetMessageNameDel Lib "NetApi32.dll" (ByVal servername As String, ByVal msgname As String) As Long
Declare Function NetMessageBufferSend Lib "NetApi32.dll" Alias "NetMessageBufferSendA" (ByVal servername As String, ByVal msgname As String, ByVal fromname As String, buf As Byte, ByVal buflen As Long) As Long

'
'  Data Structures
'

Type MSG_INFO_0
    msgi0_name As String
End Type
Type PMSG_INFO_0
    address As Long
End Type
Type LPMSG_INFO_0
    address As Long
End Type

Type MSG_INFO_1
    msgi1_name As String
    msgi1_forward_flag As Long
    msgi1_forward As String
End Type
Type PMSG_INFO_1
    address As Long
End Type
Type LPMSG_INFO_1
    address As Long
End Type

'
' Special Values and Constants
'

'
' Values for msgi1_forward_flag.
'

Public Const MSGNAME_NOT_FORWARDED As Integer = 0        ' Name not forwarded
Public Const MSGNAME_FORWARDED_TO As Integer = &H4      ' Name forward to remote station
Public Const MSGNAME_FORWARDED_FROM As Integer = &H10    ' Name forwarded from remote station

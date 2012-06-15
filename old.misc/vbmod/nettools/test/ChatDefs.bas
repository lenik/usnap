Attribute VB_Name = "ChatDefs"
Option Explicit

Public Const CHAT_PORT As Integer = 9876

Public Function SessionID(s As Session) As String
    If Left(s.PeerAddress, 10) = "127.0.0.1:" Then
        SessionID = s.PeerName & "@" & Mid(s.PeerAddress, 10)
    Else
        SessionID = s.PeerName & "@" & s.PeerAddress
    End If
End Function

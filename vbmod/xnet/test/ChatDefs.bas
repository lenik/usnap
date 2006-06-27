Attribute VB_Name = "ChatDefs"
Option Explicit

Public Const C_LOCAL As Integer = 776
Public Const C_REMOTE As String = "Localhost:776"
'Public Const C_REMOTE As String = "Loop:776"

Public Network As Xnet.Network

Public Sub Main()
    XnetRegisterDriver "Xceed Network Driver for Xnet", New XnetXceed.TCPDriver
    XnetRegisterDriver "Test Driver #2", New XnetXceed.TCPDriver

    frmStart.Show
End Sub

Public Function FileDisp(ByVal f As File) As String
    FileDisp = "<" & f.Guid & ", " & f.Path & "> "
End Function

Public Function CDisp(ByVal c As Connection) As String
    CDisp = c.QPeer & "->"
End Function

Public Function PktDisp(ByVal Pkt As Packet) As String
    PktDisp = BytesToString(Pkt.Encode)
End Function

Public Function IgnorePkt(ByVal Pkt As Packet) As Boolean
    Select Case Pkt.Name
    Case "PFK"
        IgnorePkt = True
    End Select
End Function

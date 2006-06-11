Attribute VB_Name = "ChatDefs"
Option Explicit

Public Const CHAT_PORT As Integer = 9876

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

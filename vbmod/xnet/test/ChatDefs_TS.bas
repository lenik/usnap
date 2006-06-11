Attribute VB_Name = "ChatDefs_TS"
Option Explicit

Public Const CHAT_PORT As Integer = 9876

Public Network As Xnet.Network

Public Sub Main()
    XnetRegisterDriver "Xceed Network Driver for Xnet", New XnetXceed.TCPDriver
    XnetRegisterDriver "Test Driver #2", New XnetXceed.TCPDriver

    frmStart.Show
End Sub

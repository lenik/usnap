Attribute VB_Name = "Module1"
Option Explicit

Public Function getdata(sock As Winsock, Optional ByVal clearsock As Boolean = False) As String
        Dim buf As String * 1024
        If clearsock Then
                sock.getdata buf, , 10
        Else
                sock.PeekData buf, , 10
        End If
        getdata = Trim(buf)
End Function

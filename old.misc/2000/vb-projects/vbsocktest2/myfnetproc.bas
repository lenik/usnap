Attribute VB_Name = "myfnetproc"
Option Explicit

Public Sub ADD_switch(ByVal switchON As Boolean)
        If switchON Then
                With CurrentFN.cb
                        .procDataArrival = getFuncPointer(AddressOf ADD_socket_DataArrival)
                        .procSendComplete = getFuncPointer(AddressOf ADD_socket_SendComplete)
                        .procSendProgress = getFuncPointer(AddressOf ADD_socket_SendProgress)
                End With
        Else
                FN_init_socket
        End If
End Sub
Public Sub ADD_socket_Connect(ByVal dwParam As Long)
        sock.SendData "1+1=?"
End Sub
Public Sub ADD_socket_DataArrival(ByVal dwParam As Long)
        Dim Datas As String * 1024
        sock.GetData Datas, , 1024
        Select Case Left(Datas, 3)
        Case "1+1"
                Form1.Label2 = "who call me??? ask me " & Trim(Datas)
                sock.SendData "RESULT IS 2"
        Case "I K"
                sock.Close
                sock.Listen
        Case "SO "
                sock.Close
                sock.Listen
        Case "RES"
                Form1.Label1 = Trim(Datas)
                sock.SendData "I KNOW"
        Case "YOU"
                sock.SendData "SO DO YOU"
        End Select
End Sub

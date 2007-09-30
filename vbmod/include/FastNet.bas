Attribute VB_Name = "modFastNet"
Option Explicit

Public tti1 As String * 100, tti2 As String * 100, tti3 As String * 100

' FastNet Kernel
        ' 网络资源枚举
        Declare Function NetEnum Lib "FastNet.dll" Alias "WNet_enum" (ByVal addrContainer As Long, ByVal addrEnumProc As Long) As Long
        ' 解释返回代码
        Declare Function NetStatus Lib "FastNet.dll" Alias "WNet_status" (ByVal Status As Long) As String

' Vars
        Public Const FN_DEFAULT_SERVER_PORT = 1600
        Public Const FN_DEFAULT_CLIENT_PORT = 1601

        Public Const FN_SERVER = 0
        Public Const FN_CLIENT = 1

        Public Const FN_WAITINGLINE_MAX = 128

        Type FN_SOCKET_COMMAND
                OnConnect As String
                OnDone As String
        End Type

        Type FN_SESSION_BUFFER
                SessionType As String
                LaterProcess As Boolean
                KeepSession As Boolean
                TextIn As String
                TextOut As String
        End Type

        Type FN_SESSION_CALLBACKS
                procSessionProcess As Long
        End Type

        Type FN_SOCKET_CALLBACKS
                procClose As Long
                procConnect As Long
                procConnectionRequest As Long
                procDataArrival As Long
                procError As Long
                procSendComplete As Long
                procSendProgress As Long
        End Type

        Type FN_ERROR_PACKAGE
                number As Integer
                Description As String
                Scode As Long
                Source As String
                HelpFile As String
                HelpContext As Long
                CancelDisplay As Boolean
        End Type

        Type FN_SEND_STATUS
                bytesSent As Long
                bytesRemaining As Long
        End Type

        Type FN_TIMEOUT
                timerServer As Long
                timerClient As Long
                timeoutServer As Long
                timeoutClient As Long
                procTimer As Long
                procTimeout As Long
        End Type

        Type FN_LOOP
                ServerPort As Long
                ClientPort As Long

                ServerSession As Boolean
                ClientSession As Boolean
                ServerLocked As Boolean
                ClientLocked As Boolean

                Command As FN_SOCKET_COMMAND
                SessionBuffer As FN_SESSION_BUFFER
                SessionCall As FN_SESSION_CALLBACKS

                ServerCall As FN_SOCKET_CALLBACKS
                ClientCall As FN_SOCKET_CALLBACKS
                ServerSend As FN_SEND_STATUS
                ClientSend As FN_SEND_STATUS
                ServerError As FN_ERROR_PACKAGE
                ClientError As FN_ERROR_PACKAGE

                Timeout As FN_TIMEOUT
        End Type

        Public SockServer As Winsock, SockClient As Winsock
        Public CurrentFN As FN_LOOP
        Public script As ScriptControl
        Public FN_WaitingLine As Long

' 异步解决方案
        Type FN_IOPACKAGE
                RemoteName As String
                Session As FN_SESSION_BUFFER
                Command As FN_SOCKET_COMMAND
        End Type

        Public Sub FN_TurnOnSession(ByVal sessionID As Long)
                Select Case sessionID
                Case FN_SERVER
                        'While CurrentFN.ServerLocked: FN_DoEvents: Wend
                        CurrentFN.ServerSession = True
                Case FN_CLIENT
                        'While CurrentFN.ClientLocked: FN_DoEvents: Wend
                        CurrentFN.ClientSession = True
                End Select
        End Sub

        Public Sub FN_WaitForSession(ByVal sessionID As Long)
                Select Case sessionID
                Case FN_SERVER
                        While CurrentFN.ServerSession: FN_DoEvents: Wend
                Case FN_CLIENT
                        While CurrentFN.ClientSession: FN_DoEvents: Wend
                End Select
        End Sub

        Public Sub FN_DoEvents()
                Static rox As String
                Select Case rox
                Case "/": rox = "-"
                Case "-": rox = "\"
                Case "\": rox = "|"
                Case "|": rox = "/"
                Case Else
                        rox = "-"
                End Select
                frmNetStatus.lblRox = rox
                DoEvents
        End Sub

' 默认回调函数
        Public Sub FN_TimeoutTimer()
                Static lastTimer As Single
                Dim cTimer As Single, DeltaTimer As Single
                cTimer = Timer
                DeltaTimer = cTimer - lastTimer
                With CurrentFN
                        If .ServerSession Then
                                .Timeout.timerServer = .Timeout.timerServer + DeltaTimer
                                If .Timeout.timerServer > .Timeout.timeoutServer Then
                                        callProcedure1 .Timeout.procTimeout, FN_SERVER
                                        .Timeout.timerServer = 0
                                End If
                        ElseIf .ClientSession Then
                                .Timeout.timerClient = .Timeout.timerClient + DeltaTimer
                                If .Timeout.timerClient > .Timeout.timeoutClient Then
                                        callProcedure1 .Timeout.procTimeout, FN_CLIENT
                                        .Timeout.timerClient = 0
                                End If
                        End If
                End With
                lastTimer = cTimer
        End Sub
        Public Sub FN_DefaultTimeout(ByVal TimerID As Long)
                frmMessage.Run "等待超时", 3
                Select Case TimerID
                Case FN_SERVER
                        If SockServer.State <> sckListening Then
                                SockServer.Close
                                SockServer.Listen
                        End If
                        CurrentFN.ServerSession = False
                        CurrentFN.ServerLocked = False
                Case FN_CLIENT
                        If SockClient.State <> sckClosed Then
                                SockClient.Close
                        End If
                        CurrentFN.ClientSession = False
                        CurrentFN.ClientLocked = False
                End Select
        End Sub
        Public Sub FN_ResetSession()
                With CurrentFN
                        .Command.OnConnect = ""
                        .Command.OnDone = ""
                        .SessionBuffer.LaterProcess = False
                End With
        End Sub
        Public Sub FN_Default_Session(ByVal ActAsServer As Boolean)
                On Error GoTo err
                With CurrentFN.SessionBuffer
                        If ActAsServer Then
                                Select Case .SessionType
                                Case "STAT"
                                        ' 被请求问好
                                Case "INFO"
                                        ' 被请求获取信息
                                Case "TEXT"
                                        ' 被请求存放信息
                                        Dim TextType As String
                                        TextType = Left(.TextOut, 4)
                                        Select Case TextType
                                        Case "MAIN"
                                        Case "SCRP"
                                                script.ExecuteStatement Mid(.TextOut, 5)
                                        End Select
                                Case "LINF"
                                        ' 被请求获取大量信息
                                Case "LTXT"
                                        ' 被请求存放大量信息
                                End Select
                        Else
                                Select Case .SessionType
                                Case "STAT"
                                        ' 已问好
                                Case "INFO"
                                        ' 已获取信息
                                Case "TEXT"
                                        ' 已存放信息
                                Case "LINF"
                                        ' 已获取大量信息
                                Case "LTXT"
                                        ' 已存放大量信息
                                End Select
                        End If
                End With
                Exit Sub
err:
        End Sub

        ' 关闭服务器 [非事件, 客户请求], 服务器响应
        Public Sub FN_S_Close(ByVal dwParam As Long)
                SockServer.Close
                SockServer.Listen
                CurrentFN.ServerSession = False
                ' 是否迟后执行
                If CurrentFN.SessionBuffer.LaterProcess Then callProcedure1 CurrentFN.SessionCall.procSessionProcess, True
                ' 是否保持会话
                If Not CurrentFN.SessionBuffer.KeepSession Then FN_ResetSession
        End Sub
        ' 服务器已关闭, 客户响应
        Public Sub FN_C_Close(ByVal dwParam As Long)
                SockClient.Close
                CurrentFN.ClientSession = False
        End Sub
        ' 服务器建立连接, 客户响应
        Public Sub FN_S_Connect(ByVal dwParam As Long): SockServer.Close: SockServer.Listen: End Sub
        Public Sub FN_C_Connect(ByVal dwParam As Long)
                CurrentFN.Timeout.timerClient = 0
                SockClient.SendData lt_s.departPart(CurrentFN.Command.OnConnect, 1)
        End Sub
        ' 客户请求连接, 服务器响应
        Public Sub FN_S_ConnectionRequest(ByVal dwParam As Long)
                CurrentFN.Timeout.timerServer = 0
                FN_WaitingLine = FN_WaitingLine + 1

                FN_TurnOnSession FN_SERVER
                SockServer.Close
                SockServer.Accept dwParam
                FN_WaitForSession FN_SERVER     ' 等待客户请求的连接结束

                ' 是否迟后处理
                If CurrentFN.SessionBuffer.LaterProcess Then
                        callProcedure1 CurrentFN.SessionCall.procSessionProcess, True
                End If
                FN_WaitingLine = FN_WaitingLine - 1
        End Sub
        Public Sub FN_C_ConnectionRequest(ByVal dwParam As Long): SockClient.Close: SockClient.Accept dwParam: End Sub
        ' 有数据到达, 客户或服务器响应
        Public Sub FN_S_DataArrival(ByVal dwParam As Long): CurrentFN.Timeout.timerServer = 0: FN_DataArrival dwParam, True: End Sub
        Public Sub FN_C_DataArrival(ByVal dwParam As Long): CurrentFN.Timeout.timerClient = 0: FN_DataArrival dwParam, False: End Sub
        Public Sub FN_DataArrival(ByVal dwParam As Long, ByVal toServer As Boolean)
                Dim sock As Winsock

                Dim Bytes As String * 1024
                Dim Bytes_Command As String
                Dim Bytes_Parameter As String
                Dim Bytes_Data As String

                Set sock = IIf(toServer, SockServer, SockClient)
                sock.GetData Bytes, , 1024

                Bytes_Command = Trim(Mid(Bytes, 1, 4))
                Bytes_Parameter = Trim(Mid(Bytes, 6, 4))
                Bytes_Data = RTrim(Mid(Bytes, 11))

                If Not toServer Then
                        If CurrentFN.Command.OnConnect <> "" Then
                                sock.SendData lt_s.departPart(CurrentFN.Command.OnConnect, 1)
                                Exit Sub
                        End If
                End If

                Select Case Bytes_Command
                Case "OPTN"
                        Select Case Bytes_Parameter
                        Case "IMMD"
                                CurrentFN.SessionBuffer.LaterProcess = False
                                sock.SendData "OPTN ACCP IMMD"
                        Case "LATE"
                                CurrentFN.SessionBuffer.LaterProcess = True
                                sock.SendData "OPTN ACCP LATE"
                        Case "KEEP"
                                CurrentFN.SessionBuffer.KeepSession = True
                                sock.SendData "OPTN ACCP KEEP"
                        Case "NOKP"
                                CurrentFN.SessionBuffer.KeepSession = False
                                sock.SendData "OPTN ACCP NOKP"
                        Case "ACCP"
                                sock.SendData "DONE OPTN"
                        Case Else
                                sock.SendData "UNKN OPTN " & Bytes_Parameter
                        End Select
                Case "SESS"
                        CurrentFN.SessionBuffer.SessionType = Bytes_Parameter
                        Select Case Bytes_Parameter
                        Case "STAT"
                                sock.SendData "DONE STAT"
                        Case "INFO"
                                sock.SendData "DATA INFO " & CurrentFN.SessionBuffer.TextIn
                        Case "TEXT"
                                sock.SendData "WHAT TEXT"
                        Case "LINF"
                                sock.SendData "DATA LINF " & CurrentFN.SessionBuffer.TextIn
                        Case "LTXT"
                                sock.SendData "WHAT LTXT"
                        Case Else
                                sock.SendData "UNKN SESS " & Bytes_Parameter
                        End Select
                Case "WHAT"
                        Select Case Bytes_Parameter
                        Case "SESS"
                                sock.SendData "SESS " & CurrentFN.SessionBuffer.SessionType
                        Case "TEXT"
                                sock.SendData "DATA TEXT " & CurrentFN.SessionBuffer.TextIn
                        Case "LTXT"
                                sock.SendData "DATA LTXT " & CurrentFN.SessionBuffer.TextIn
                        Case Else
                                sock.SendData "UNKN WHAT " & Bytes_Parameter
                        End Select
                Case "DATA"
                        FN_DataInput Bytes_Data, toServer
                        If CurrentFN.SessionBuffer.TextIn <> "" Then
                                sock.SendData CurrentFN.SessionBuffer.TextIn
                        Else
                                Select Case Bytes_Parameter
                                Case "INFO"
                                        sock.SendData "DONE INFO"
                                Case "TEXT"
                                        sock.SendData "DONE TEXT"
                                Case "LINF"
                                        sock.SendData "DONE LINF"
                                Case "LTXT"
                                        sock.SendData "DONE LTXT"
                                Case Else
                                        sock.SendData "UNKN DATA " & Bytes_Parameter
                                End Select
                        End If
                Case "DONE"
                        If toServer Then
                                callProcedure1 CurrentFN.ServerCall.procClose, 0
                        Else
                                If CurrentFN.Command.OnDone <> "" Then
                                        sock.SendData lt_s.departPart(CurrentFN.Command.OnDone, 1)
                                Else
                                        sock.SendData "DONE " & Bytes_Parameter & " TO YOU"
                                End If
                        End If
                Case "UNKN"
                        If toServer Then
                                With CurrentFN.ServerError
                                        .Source = "FastNet"
                                        .number = -1
                                        Select Case Bytes_Parameter
                                        Case "PREF"
                                                .Description = "不知道这个行前缀: " & Mid(Bytes_Parameter, 7)
                                        Case "OPTN"
                                                .Description = "不知道这个选项 OPTN = " & Mid(Bytes_Parameter, 7)
                                        Case "SESS"
                                                .Description = "不知道这个会话类型 SESS = " & Mid(Bytes_Parameter, 7)
                                        Case "WHAT"
                                                .Description = "不知道这个服务提示 WHAT = " & Mid(Bytes_Parameter, 7)
                                        Case "DATA"
                                                .Description = "不知道这个数据类型 DATA = " & Mid(Bytes_Parameter, 7)
                                        Case "DONE"
                                                .Description = "不知道这个结束类型 DONE = " & Mid(Bytes_Parameter, 7)
                                        Case Else
                                                .Description = "天哪, 怎么会有这种错误类型: " & Bytes_Parameter
                                        End Select
                                End With
                                callProcedure1 CurrentFN.ServerCall.procError, 0
                        Else
                                sock.SendData Bytes
                        End If
                Case Else
                        sock.SendData "UNKN PREF " & Bytes_Command
                End Select
        End Sub
        Public Sub FN_DataInput(ByVal Bytes As String, ByVal RunningOnServer As Boolean)
                CurrentFN.SessionBuffer.TextOut = Bytes
                If Not CurrentFN.SessionBuffer.LaterProcess Then
                        ' 立即执行
                        callProcedure1 CurrentFN.SessionCall.procSessionProcess, RunningOnServer
                Else
                        ' 迟后执行. 把执行推迟到Close之后
                        CurrentFN.SessionBuffer.TextIn = ""
                End If
        End Sub
        ' 发生错误, 服务器或客户响应
        Public Sub FN_S_Error(ByVal dwParam As Long)
                callProcedure1 CurrentFN.ServerCall.procClose, 0
                MsgBox CurrentFN.ServerError.Description & "(" & CurrentFN.ServerError.number & ")"
        End Sub
        Public Sub FN_C_Error(ByVal dwParam As Long)
                callProcedure1 CurrentFN.ClientCall.procClose, 0
                MsgBox CurrentFN.ClientError.Description & "(" & CurrentFN.ClientError.number & ")"
        End Sub
        Public Sub FN_S_SendComplete(ByVal dwParam As Long): End Sub
        Public Sub FN_C_SendComplete(ByVal dwParam As Long): End Sub
        Public Sub FN_S_SendProgress(ByVal dwParam As Long): End Sub
        Public Sub FN_C_SendProgress(ByVal dwParam As Long): End Sub


Public Sub FN_Initialize(ServerSock As Winsock, ClientSock As Winsock, ByVal ServerPort As Long, ByVal ClientPort As Long, Optional ByVal SessionCall As Long = 0)
        Set SockServer = ServerSock
        Set SockClient = ClientSock
        SockServer.LocalPort = ServerPort
        SockClient.LocalPort = ClientPort
        CurrentFN.ServerPort = ServerPort
        CurrentFN.ClientPort = ClientPort
        With CurrentFN
                .Command.OnConnect = "SESS STAT"
                .Command.OnDone = ""

                .SessionBuffer.KeepSession = False
                .SessionBuffer.LaterProcess = False
                .SessionBuffer.TextIn = ""
                .SessionBuffer.TextOut = ""
                .SessionCall.procSessionProcess = _
                        IIf(SessionCall = 0, _
                                pFunc(AddressOf FN_Default_Session), _
                                SessionCall)

                .ServerCall.procClose = pFunc(AddressOf FN_S_Close)
                .ServerCall.procConnect = pFunc(AddressOf FN_S_Connect)
                .ServerCall.procConnectionRequest = pFunc(AddressOf FN_S_ConnectionRequest)
                .ServerCall.procDataArrival = pFunc(AddressOf FN_S_DataArrival)
                .ServerCall.procError = pFunc(AddressOf FN_S_Error)
                .ServerCall.procSendComplete = pFunc(AddressOf FN_S_SendComplete)
                .ServerCall.procSendProgress = pFunc(AddressOf FN_S_SendProgress)

                .ClientCall.procClose = pFunc(AddressOf FN_C_Close)
                .ClientCall.procConnect = pFunc(AddressOf FN_C_Connect)
                .ClientCall.procConnectionRequest = pFunc(AddressOf FN_C_ConnectionRequest)
                .ClientCall.procDataArrival = pFunc(AddressOf FN_C_DataArrival)
                .ClientCall.procError = pFunc(AddressOf FN_C_Error)
                .ClientCall.procSendComplete = pFunc(AddressOf FN_C_SendComplete)
                .ClientCall.procSendProgress = pFunc(AddressOf FN_C_SendProgress)

                .Timeout.timerServer = 0
                .Timeout.timerClient = 0
                .Timeout.timeoutServer = 20
                .Timeout.timeoutClient = 20
                .Timeout.procTimer = pFunc(AddressOf FN_TimeoutTimer)
                .Timeout.procTimeout = pFunc(AddressOf FN_DefaultTimeout)
        End With
        SockServer.Listen
        FN_WaitingLine = 0
End Sub

' fix ---
Public Sub FN_change_socket()
        SockClient.Close
        SockClient.Listen
        SockServer.Close
        'SockServer.Connect IIf(frmSock2.txtremote = "tc-info", "df", "tc-info"), CurrentFN.ClientPort
End Sub

' 网络函数包装
        Public Function FN_PackIO_Thread(ByVal pIOPack As Long)
                Dim IOPack As FN_IOPACKAGE
'                On Error GoTo cleanup
        End Function

        Public Function FN_PackIO(IOPack As FN_IOPACKAGE) As Boolean
                Dim hThread As Long
                Dim idThread As Long

                FN_PackIO = True
                FN_WaitingLine = FN_WaitingLine + 1

                On Error GoTo err
                If FN_WaitingLine > FN_WAITINGLINE_MAX Then Error 6

                FN_WaitForSession FN_CLIENT
                FN_TurnOnSession FN_CLIENT

                'CurrentFN.ClientLocked = True
                CurrentFN.SessionBuffer = IOPack.Session
                CurrentFN.Command.OnConnect = IOPack.Command.OnConnect
                SockClient.Connect IOPack.RemoteName, CurrentFN.ServerPort
                FN_WaitForSession FN_CLIENT
                IOPack.Session = CurrentFN.SessionBuffer
cleanup:
                'CurrentFN.ClientLocked = False

                FN_WaitingLine = FN_WaitingLine - 1
                Exit Function
err:
                FN_PackIO = False
        End Function

        Public Function FN_TextIO(ByVal RemoteName As String, ByVal TextIn As String, Optional ByVal delayProcess As Boolean = False) As String
                Dim IOPack As FN_IOPACKAGE
                IOPack.RemoteName = RemoteName
                IOPack.Session.SessionType = "TEXT"
                IOPack.Session.TextIn = TextIn
                IOPack.Command.OnConnect = IIf(delayProcess, "#OPTN LATE", "#OPTN IMMD") & "#SESS TEXT"
                If FN_PackIO(IOPack) Then
                        FN_TextIO = IOPack.Session.TextOut
                End If
        End Function

        Public Function FN_ScriptIO(ByVal RemoteName As String, ByVal ScriptIn As String) As Boolean
                Dim IOPack As FN_IOPACKAGE
                FN_ScriptIO = True

                On Error GoTo err
                IOPack.RemoteName = RemoteName
                IOPack.Session.SessionType = "TEXT"
                IOPack.Session.TextIn = "SCRP " & ScriptIn
                IOPack.Command.OnConnect = "#OPTN LATE#SESS TEXT"
                If FN_PackIO(IOPack) Then
                        ' 以后再考虑脚本输出
                        ' script.ExecuteStatement IOPack.Session.TextOut
                End If
                Exit Function
err:
                FN_ScriptIO = False
        End Function

Attribute VB_Name = "modFingerNet"
Option Explicit

Type FINGER_SERVER
        Monitor As String
        Group As String
        Channel As String
        TestTime As Long
        HostName As String
        HostIP As String
End Type

Type FINGER_CLIENT
        Alias As String
        HostName As String
        HostIP As String
        Comment As String
        CurrentSpeed As Single
        CurrentAccuracy As Single
        Status As String
        InChannel As String
End Type

Public fingerServer As FINGER_SERVER
Public fingerClient As FINGER_CLIENT

Public fingerRunServer As Boolean
Public hasBeenCreated As Boolean

Public dispatchLaterString As String

Public Property Get dispatchLater() As String: dispatchLater = dispatchLaterString: End Property
Public Property Let dispatchLater(ByVal newDispatch As String)
        If Not hasBeenCreated Then
                'MsgBox "必须建立频道服务器之后才可以建立迟后分发流"
        Else
                dispatchLaterString = newDispatch
                frmManager.timerDispatch.Enabled = True
        End If
End Property

Public Function cAddr(ByVal Name As String, ByVal host As String) As String: cAddr = lt_s.encodePart(lt_s.encodePart(Name) & lt_s.encodePart(host)): End Function
Public Function cAddrName(ByVal cAddr As String) As String: cAddrName = lt_s.decodePart(lt_s.decodePart(cAddr, 1), 1): End Function
Public Function cAddrHost(ByVal cAddr As String) As String: cAddrHost = lt_s.decodePart(lt_s.decodePart(cAddr, 1), 2): End Function
Public Function dispAddr(ByVal cAddr As String) As String: dispAddr = cAddrName(cAddr) & "@" & cAddrHost(cAddr): End Function
Public Function storeAddr(ByVal cAddr As String) As String
        storeAddr = dispAddr(cAddr)
        storeAddr = storeAddr & String(64 - Len(storeAddr), " ")
        storeAddr = storeAddr & cAddr
End Function
Public Function storeCAddr(ByVal storeAddr As String) As String: storeCAddr = Mid(storeAddr, 65): End Function
Public Function storeDispAddr(ByVal storeAddr As String) As String: storeDispAddr = RTrim(Left(storeAddr, 64)): End Function

' 网络数据包处理
        Public Function encodeFingerServer(s As FINGER_SERVER) As String
                encodeFingerServer = _
                        lt_s.encodePart("SERVER") & _
                        lt_s.encodePart(s.Monitor) & _
                        lt_s.encodePart(s.Group) & _
                        lt_s.encodePart(s.Channel) & _
                        lt_s.encodePart(s.TestTime) & _
                        lt_s.encodePart(s.HostName) & _
                        lt_s.encodePart(s.HostIP)
        End Function
        Public Function decodeFingerServer(s As String) As FINGER_SERVER
                If lt_s.decodePart(s, 1) = "SERVER" Then
                        With decodeFingerServer
                                .Monitor = lt_s.decodePart(s, 2)
                                .Group = lt_s.decodePart(s, 3)
                                .Channel = lt_s.decodePart(s, 4)
                                .TestTime = val(lt_s.decodePart(s, 5))
                                .HostName = lt_s.decodePart(s, 6)
                                .HostIP = lt_s.decodePart(s, 7)
                        End With
                End If
        End Function
        Public Function encodeFingerClient(s As FINGER_CLIENT) As String
                encodeFingerClient = _
                        lt_s.encodePart("CLIENT") & _
                        lt_s.encodePart(s.Alias) & _
                        lt_s.encodePart(s.HostName) & _
                        lt_s.encodePart(s.HostIP) & _
                        lt_s.encodePart(s.Comment) & _
                        lt_s.encodePart(s.CurrentSpeed) & _
                        lt_s.encodePart(s.CurrentAccuracy) & _
                        lt_s.encodePart(s.Status)
        End Function
        Public Function decodeFingerClient(s As String) As FINGER_CLIENT
                If lt_s.decodePart(s, 1) = "CLIENT" Then
                        With decodeFingerClient
                                .Alias = lt_s.decodePart(s, 2)
                                .HostName = lt_s.decodePart(s, 3)
                                .HostIP = lt_s.decodePart(s, 4)
                                .Comment = lt_s.decodePart(s, 5)
                                .CurrentSpeed = val(lt_s.decodePart(s, 6))
                                .CurrentAccuracy = val(lt_s.decodePart(s, 7))
                                .Status = lt_s.decodePart(s, 8)
                        End With
                End If
        End Function

' 网络主会话回调
        Public Sub Finger_Session(ByVal ActAsServer As Boolean)
                On Error GoTo err

                With CurrentFN.SessionBuffer
                        'MsgBox str(ActAsServer) & vbNewLine & _
                                "SES: " & .SessionType & vbNewLine & _
                                "IN: " & .TextIn & vbNewLine & _
                                "OUT: " & .TextOut
                        If .TextOut = "" Then Exit Sub

                        If ActAsServer Then
                                ' 客户发送信息
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
                                        Case "FING"
                                                Select Case lt_s.decodePart(.TextOut, 1)
                                                Case "ARE YOU MANAGER"
                                                        If hasBeenCreated Then
                                                                .TextIn = "DATA TEXT FING #ARE YOU MANAGER#YES" & lt_s.encodePart(cAddr(frmManager.txtChannel, fingerClient.HostName))
                                                        Else
                                                                .TextIn = "DATA TEXT FING #ARE YOU MANAGER#NO"
                                                        End If
                                                Case "WHAT IS YOUR CHANNEL NAME"
                                                        If hasBeenCreated Then
                                                                .TextIn = "DATA TEXT FING #WHAT IS YOUR CHANNEL NAME#OK" & lt_s.encodePart(cAddr(lt_s.encodePart(frmManager.txtChannel), fingerClient.HostName))
                                                        Else
                                                                .TextIn = "DATA TEXT FING #WHAT IS YOUR CHANNEL NAME#ERROR#NOT A CHANNEL"
                                                        End If
                                                Case "JOIN APPLY"
                                                        If hasBeenCreated Then
                                                                If frmManager.Join(lt_s.decodePart(.TextOut, 2)) Then
                                                                        .TextIn = "DATA TEXT FING #JOIN APPLY#OK" & lt_s.encodePart(encodeFingerServer(fingerServer))
                                                                Else
                                                                        .TextIn = "DATA TEXT FING #JOIN APPLY#ERROR#JOINER EXISTED"
                                                                End If
                                                        Else
                                                                .TextIn = "DATA TEXT FING #JOIN APPLY#ERROR#NOT A CHANNEL"
                                                        End If
                                                Case "JOINER CANCELED"
                                                        If Not hasBeenCreated Then
                                                                frmMessage.Run "您已经被" & fingerClient.InChannel & "取消资格, 请重新加入!", 2
                                                                fingerClient.InChannel = ""
                                                                .TextIn = "DATA TEXT FING #JOINER CANCELED#OK"
                                                        Else
                                                                .TextIn = "DATA TEXT FING #JOINER CANCELED#ERROR#NOT A CLIENT"
                                                        End If
                                                Case "CANCEL APPLY"
                                                        If hasBeenCreated Then
                                                                frmManager.CancelJoiner lt_s.decodePart(.TextOut, 2)
                                                                .TextIn = "DATA TEXT FING #CANCEL APPLY#OK"
                                                        Else
                                                                .TextIn = "DATA TEXT FING #CANCEL APPLY#ERROR#NOT A CLIENT"
                                                        End If
                                                Case "GET SERVER INFO"
                                                        If hasBeenCreated Then
                                                                .TextIn = "DATA TEXT FING #GET SERVER INFO#OK" & lt_s.encodePart(encodeFingerServer(fingerServer))
                                                        Else
                                                                .TextIn = "DATA TEXT FING #GET SERVER INFO#ERROR#NOT A SERVER"
                                                        End If
                                                Case "GET CLIENT INFO"
                                                        If Not hasBeenCreated Then
                                                                .TextIn = "DATA TEXT FING #GET CLIENT INFO#OK" & lt_s.encodePart(encodeFingerClient(fingerClient))
                                                        Else
                                                                .TextIn = "DATA TEXT FING #GET CLIENT INFO#ERROR#NOT A CLIENT"
                                                        End If
                                                Case "DISPLAY MESSAGE"
                                                        frmMain.controlMain.Out lt_s.decodePart(Mid(.TextOut, lt_s.decodePart(.TextOut, 2, True)), 1)
                                                        .TextIn = "DATA TEXT FING #DISPLAY MESSAGE#OK"
                                                Case "DISPATCH MESSAGE"
                                                        dispatchLater = dispatchLater & lt_s.encodePart("FING #SERVER MESSAGE" & lt_s.encodePart(lt_s.decodePart(.TextOut, 2)))
                                                        .TextIn = "DATA TEXT FING #DISPATCH MESSAGE#OK#PLEASE WAIT"
                                                Case "DISPATCH SCRIPT"
                                                        dispatchLater = dispatchLater & lt_s.encodePart("SCRP " & lt_s.decodePart(.TextOut, 2))
                                                        .TextIn = "DATA TEXT FING #DISPATCH SCRIPT#OK#PLEASE WAIT"
                                                Case "SERVER MESSAGE"
                                                        If Not hasBeenCreated Then
                                                                frmHoll.ChatIn lt_s.decodePart(.TextOut, 2)
                                                                .TextIn = "DATA TEXT FING #SERVER MESSAGE#OK#RECEIVED BY CLIENT"
                                                        Else
                                                                .TextIn = "DATA TEXT FING #SERVER MESSAGE#ERROR#NOT A CLIENT"
                                                        End If
                                                Case "START"
                                                        If Not hasBeenCreated Then
                                                                tempContent = Mid(.TextOut, lt_s.decodePart(.TextOut, 3, True))
                                                                paperDowned = -1
                                                                .TextIn = "DATA TEXT FING #START#OK"
                                                        Else
                                                                .TextIn = "DATA TEXT FING #START#NOT A CLIENT"
                                                        End If
                                                Case "HANDUP"
                                                        If Not hasBeenCreated Then
                                                                bHandup = True
                                                                .TextIn = "DATA TEXT FING #HANDUP#OK"
                                                        Else
                                                                .TextIn = "DATA TEXT FING #HANDUP#NOT A CLIENT"
                                                        End If
                                                Case "EARLY HANDUP"
                                                        If hasBeenCreated Then
                                                                .TextIn = "DATA TEXT FING #HANDUP"
                                                        Else
                                                                .TextIn = "DATA TEXT FING #EARLY HANDUP#NOT A SERVER"
                                                        End If
                                                Case "PAPER ACCEPTED"
                                                        If Not hasBeenCreated Then
                                                                frmMain.PaperAccepted = True
                                                                .TextIn = "DATA TEXT FING #PAPER ACCEPTED#OK"
                                                        Else
                                                                .TextIn = "DATA TEXT FING #PAPER ACCEPTED#ERROR#NOT A CLIENT"
                                                        End If
                                                Case "QUERY COMPRESULT"
                                                        If Not hasBeenCreated Then
                                                                .TextIn = "DATA TEXT FING #QUERY COMPRESULT#OK" & lt_s.encodePart(encodeCompResult(validResult))
                                                        Else
                                                                .TextIn = "DATA TEXT FING #QUERY COMPRESULT#ERROR#NOT A CLIENT"
                                                        End If
                                                Case Else
                                                        .TextIn = "DATA TEXT FING #ERROR#NO SUCH CMD"
                                                End Select
                                        Case "SCRP"
                                                script.ExecuteStatement Mid(.TextOut, 5)
                                        End Select
                                Case "LINF"
                                        ' 被请求获取大量信息
                                Case "LTXT"
                                        ' 被请求存放大量信息
                                End Select
                        Else
                                ' 服务器回答信息
                                Select Case .SessionType
                                Case "STAT"
                                        ' 已问好
                                Case "INFO"
                                        ' 已获取信息
                                Case "TEXT"
                                        ' 已存放信息
                                        .TextIn = ""
                                        Select Case Left(.TextOut, 4)
                                        Case "FING"
                                                If debugMode Then
                                                        If lt_s.decodePart(.TextOut, 1) = "ERROR" Then MsgBox .TextOut
                                                End If
                                                .TextOut = Mid(.TextOut, val(lt_s.decodePart(.TextOut, 2, True)))
                                        Case "SCRP"
                                        End Select
                                Case "LINF"
                                        ' 已获取大量信息
                                Case "LTXT"
                                        ' 已存放大量信息
                                End Select
                        End If
                End With
                Exit Sub
err:
                MsgBox "Err: " & Error
        End Sub

' 网络资源枚举
        Public Sub Finger_EnumResourceProc(ByVal eleNetResource As Long)
                frmSelectComputer.lstComputers.AddItem lt_s.saveAscizString(returnLong(eleNetResource, NETRESOURCE_lpRemoteName))
                DoEvents
                Sleep 30        ' Delay 30
        End Sub

        Public Sub Finger_EnumComputerProc(ByVal eleNetResource As Long)
                Dim DisplayType As Long
                Dim HostName As String

                DisplayType = returnLong(eleNetResource, NETRESOURCE_dwDisplayType)
                HostName = lt_s.saveAscizString(returnLong(eleNetResource, NETRESOURCE_lpRemoteName))

                If DisplayType = RESOURCEDISPLAYTYPE_SERVER Or DisplayType = RESOURCEDISPLAYTYPE_ROOT Then
                        HostName = Mid(HostName, 3)
                        frmSelectComputer.lstComputers.AddItem HostName
                End If
                DoEvents
                Sleep 30        ' Delay 30
        End Sub

        Public Sub Finger_EnumManagerProc(ByVal eleNetResource As Long)
                Dim DisplayType As Long
                Dim HostName As String
                Dim Respond As String

                DisplayType = returnLong(eleNetResource, NETRESOURCE_dwDisplayType)
                HostName = lt_s.saveAscizString(returnLong(eleNetResource, NETRESOURCE_lpRemoteName))

                If DisplayType = RESOURCEDISPLAYTYPE_SERVER Or DisplayType = RESOURCEDISPLAYTYPE_ROOT Then
                        HostName = Mid(HostName, 3)
                        Respond = FN_TextIO(HostName, "FING #ARE YOU MANAGER")
                        If lt_s.decodePart(Respond, 1) = "YES" Then
                                frmSelectComputer.lstComputers.AddItem storeAddr(lt_s.decodePart(Respond, 2))
                        End If
                End If
                DoEvents
                Sleep 30        ' Delay 30
        End Sub

        Public Sub Finger_DispatchText(remotes As ListBox, ByVal text As String, ByVal displaymessage As String, Optional ByVal delayProcess As Boolean = False)
                Dim I As Integer
                Dim host As String
                Dim cdispmsg As String
                Dim ret1 As String
                Dim ret As String
                frmWaitingBox.TurnOn "准备批量发送", frmManager.picHead
                ret = ""
                With remotes
                        For I = 0 To .ListCount - 1
                                cdispmsg = Replace(displaymessage, "%%%", storeDispAddr(.List(I)))
                                frmWaitingBox.SetInfo cdispmsg
                                DoEvents
                                host = cAddrHost(storeCAddr(.List(I)))
                                If host <> "" Then ' 保存每个有效客户的返回值
                                        ret1 = FN_TextIO(host, text, delayProcess)
                                        ret = ret & lt_s.encodePart(storeDispAddr(.List(I)) & "/" & ret1)
                                End If
                        Next
                End With
                frmWaitingBox.TurnOff
        End Sub

VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Object = "{0E59F1D2-1FBE-11D0-8FF2-00A0D10038BC}#1.0#0"; "msscript.ocx"
Begin VB.Form frmTest
   Caption         =   "桃壳ICQ"
   ClientHeight    =   4770
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   6885
   LinkTopic       =   "Form1"
   ScaleHeight     =   4770
   ScaleWidth      =   6885
   StartUpPosition =   3  '窗口缺省
   Begin VB.Frame frameDebug
      Caption         =   "细节控制"
      Height          =   195
      Left            =   120
      TabIndex        =   0
      Top             =   0
      Width           =   6495
      Begin VB.TextBox txtArrival
         Appearance      =   0  'Flat
         Height          =   2175
         Left            =   120
         MultiLine       =   -1  'True
         ScrollBars      =   3  'Both
         TabIndex        =   22
         ToolTipText     =   "到达信息"
         Top             =   960
         Width           =   6135
      End
      Begin VB.Timer Timer1
         Interval        =   1
         Left            =   240
         Top             =   1200
      End
      Begin VB.TextBox txtreq
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   5160
         TabIndex        =   21
         TabStop         =   0   'False
         Text            =   "RequestID"
         ToolTipText     =   "连接请求代码"
         Top             =   720
         Width           =   1095
      End
      Begin VB.TextBox txtBytesTotal
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   120
         TabIndex        =   20
         TabStop         =   0   'False
         Text            =   "txtBytesTotal"
         Top             =   240
         Width           =   1335
      End
      Begin VB.TextBox txtStatus
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   1440
         TabIndex        =   19
         TabStop         =   0   'False
         Text            =   "status"
         Top             =   240
         Width           =   4815
      End
      Begin VB.TextBox txtNumber
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   120
         TabIndex        =   18
         TabStop         =   0   'False
         Text            =   "txtNumber"
         Top             =   480
         Width           =   855
      End
      Begin VB.TextBox txtDescription
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   960
         TabIndex        =   17
         TabStop         =   0   'False
         Text            =   "txtDescription"
         Top             =   480
         Width           =   2655
      End
      Begin VB.TextBox txtsCode
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   3600
         TabIndex        =   16
         TabStop         =   0   'False
         Text            =   "txtsCode"
         Top             =   480
         Width           =   735
      End
      Begin VB.TextBox txtSource
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   4320
         TabIndex        =   15
         TabStop         =   0   'False
         Text            =   "txtSource"
         Top             =   480
         Width           =   1335
      End
      Begin VB.TextBox txtCancelDisplay
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   5640
         TabIndex        =   14
         TabStop         =   0   'False
         Text            =   "txtCancelDisplay"
         Top             =   480
         Width           =   615
      End
      Begin VB.TextBox txtPort
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   1800
         TabIndex        =   13
         Text            =   "1000"
         ToolTipText     =   "远程端口"
         Top             =   720
         Width           =   615
      End
      Begin VB.TextBox txtLocal
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   2400
         TabIndex        =   12
         Text            =   "0"
         ToolTipText     =   "本地端口(0自动分配)"
         Top             =   720
         Width           =   615
      End
      Begin VB.TextBox txtRemote
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   120
         TabIndex        =   11
         Text            =   "localhost"
         ToolTipText     =   "远程主机"
         Top             =   720
         Width           =   1695
      End
      Begin VB.TextBox txtSend
         Appearance      =   0  'Flat
         Height          =   975
         Left            =   120
         MultiLine       =   -1  'True
         ScrollBars      =   3  'Both
         TabIndex        =   10
         ToolTipText     =   "发送文本, 按住CTRL键点击鼠标输入控制字符。"
         Top             =   3120
         Width           =   4695
      End
      Begin VB.CommandButton cmdAccept
         Caption         =   "&A 接受连接"
         Height          =   255
         Left            =   6240
         TabIndex        =   9
         TabStop         =   0   'False
         Top             =   960
         Width           =   1095
      End
      Begin VB.CommandButton cmdDoScript
         Caption         =   "&L 本地控制"
         Height          =   255
         Left            =   6240
         TabIndex        =   8
         TabStop         =   0   'False
         Top             =   1200
         Width           =   1095
      End
      Begin VB.CommandButton cmdRemoteDebug
         Caption         =   "&R 远程控制"
         Height          =   255
         Left            =   6240
         TabIndex        =   7
         TabStop         =   0   'False
         Top             =   1440
         Width           =   1095
      End
      Begin VB.CommandButton cmdShowPort
         Caption         =   "&S 显示端口"
         Height          =   255
         Left            =   6240
         TabIndex        =   6
         TabStop         =   0   'False
         Top             =   1680
         Width           =   1095
      End
      Begin VB.CommandButton cmdListen
         Caption         =   "Listen Ctrl-L"
         Height          =   255
         Left            =   4800
         TabIndex        =   5
         TabStop         =   0   'False
         Top             =   3120
         Width           =   1455
      End
      Begin VB.CommandButton cmdConnect
         Caption         =   "Connect Ctrl-K"
         Height          =   255
         Left            =   4800
         TabIndex        =   4
         TabStop         =   0   'False
         Top             =   3360
         Width           =   1455
      End
      Begin VB.CommandButton cmdClose
         Caption         =   "Close Ctrl-O"
         Height          =   255
         Left            =   4800
         TabIndex        =   3
         TabStop         =   0   'False
         Top             =   3600
         Width           =   1455
      End
      Begin VB.CommandButton cmdSend
         Caption         =   "Send Ctrl-S"
         Height          =   255
         Left            =   4800
         TabIndex        =   2
         TabStop         =   0   'False
         Top             =   3840
         Width           =   1455
      End
      Begin VB.CommandButton cmdBind
         Caption         =   "&B 绑定端口"
         Height          =   255
         Left            =   6240
         TabIndex        =   1
         TabStop         =   0   'False
         Top             =   1920
         Width           =   1095
      End
      Begin MSWinsockLib.Winsock sock
         Left            =   720
         Top             =   1200
         _ExtentX        =   741
         _ExtentY        =   741
         _Version        =   393216
         Protocol        =   1
         RemoteHost      =   "tc-info"
         RemotePort      =   80
      End
      Begin MSScriptControlCtl.ScriptControl script
         Left            =   1680
         Top             =   1080
         _ExtentX        =   1005
         _ExtentY        =   1005
         AllowUI         =   -1  'True
      End
      Begin MSWinsockLib.Winsock sockClient
         Left            =   1200
         Tag             =   "基本上不用"
         Top             =   1200
         _ExtentX        =   741
         _ExtentY        =   741
         _Version        =   393216
         RemoteHost      =   "tc-info"
      End
   End
   Begin VB.Menu mCmd
      Caption         =   "Soc&kCmd"
      Begin VB.Menu mnuConnect
         Caption         =   "Connect"
         Shortcut        =   ^K
      End
      Begin VB.Menu mClose
         Caption         =   "Close"
         Shortcut        =   ^O
      End
      Begin VB.Menu mListen
         Caption         =   "Listen"
         Shortcut        =   ^L
      End
      Begin VB.Menu mSend
         Caption         =   "Send"
         Shortcut        =   ^S
      End
      Begin VB.Menu ms
         Caption         =   "-"
      End
      Begin VB.Menu mBind
         Caption         =   "&Bind"
         Shortcut        =   ^B
      End
   End
   Begin VB.Menu mEnv
      Caption         =   "&Env"
      Begin VB.Menu mmClear
         Caption         =   "清除到达数据"
         Shortcut        =   ^R
      End
      Begin VB.Menu mmAutoS
         Caption         =   "自动发送并清除"
         Checked         =   -1  'True
         Shortcut        =   ^A
      End
      Begin VB.Menu mmAutoNewline
         Caption         =   "自动添加换行"
         Checked         =   -1  'True
         Shortcut        =   ^N
      End
      Begin VB.Menu mmConnectString
         Caption         =   "连接触发字串"
         Shortcut        =   ^E
      End
      Begin VB.Menu ms2
         Caption         =   "-"
      End
      Begin VB.Menu mmClearError
         Caption         =   "清除错误"
         Shortcut        =   ^X
      End
   End
   Begin VB.Menu mControl
      Caption         =   "&Control"
      Begin VB.Menu mmAlwaysListen
         Caption         =   "时刻保持接听"
         Shortcut        =   {F5}
      End
      Begin VB.Menu mmManualAccept
         Caption         =   "人工接受连接"
         Shortcut        =   {F6}
      End
      Begin VB.Menu mmPromptClose
         Caption         =   "授权关闭连接"
         Shortcut        =   {F7}
      End
      Begin VB.Menu mmRemoteDebug
         Caption         =   "启用远程脚本调试功能"
         Checked         =   -1  'True
         Shortcut        =   {F8}
      End
      Begin VB.Menu ms4
         Caption         =   "-"
      End
      Begin VB.Menu mmPeek
         Caption         =   "保留远程数据"
         Shortcut        =   {F11}
      End
   End
   Begin VB.Menu mProtocol
      Caption         =   "&Protocol"
      Begin VB.Menu mmTCP
         Caption         =   "&TCP"
         Checked         =   -1  'True
         Shortcut        =   {F3}
      End
      Begin VB.Menu mmUDP
         Caption         =   "&UDP"
         Shortcut        =   {F4}
      End
   End
   Begin VB.Menu mHelp
      Caption         =   "&Help"
      Begin VB.Menu mmAbout
         Caption         =   "&A关于"
      End
      Begin VB.Menu ms5
         Caption         =   "-"
      End
      Begin VB.Menu mmSetTitle
         Caption         =   "主题名字设置"
         Shortcut        =   ^T
      End
   End
   Begin VB.Menu mText
      Caption         =   "&Text"
      Visible         =   0   'False
      Begin VB.Menu mmInsertAscii
         Caption         =   "&Insert ascii"
      End
      Begin VB.Menu mmCopyAll
         Caption         =   "&Copy all"
      End
   End
End
Attribute VB_Name = "frmTest"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim buf As String * 16385
Dim strConnectString As String

Public Sub sockreset()
        If sock.State <> sckClosed Then
                sock.Close
        End If
        sock.RemoteHost = txtRemote
        sock.RemotePort = txtPort
        sock.LocalPort = txtLocal
        sock.Protocol = IIf(mmTCP.Checked, sckTCPProtocol, sckUDPProtocol)
End Sub

Private Sub cmdAccept_Click()
        'sockClient.LocalPort = sock.LocalPort
        'sockClient.RemotePort = sock.RemotePort
        'sockClient.Bind
        sock.Accept Val(txtreq)
End Sub

Private Sub cmdBind_Click()
        mBind_Click
End Sub

Private Sub cmdClose_Click()
        ' how =
        '           0   receive
        '           1   send
        '           2   both
        'sock_shutdown sock.SocketHandle, 2
        '           call 'sock_shutdown', then sock_Close event will be trigged.
        '           but sock.Close won't.
        sock.Close
End Sub

Private Sub cmdListen_Click()
        On Error Resume Next
        If Me.Tag = "client" Then Me.Tag = "server"
        sockreset
        sock.Listen
End Sub

Private Sub cmdConnect_Click()
        On Error Resume Next
        If Me.Tag = "server" Then Me.Tag = "client"
        sockreset
        sock.Connect
End Sub

Private Sub cmdSend_Click()
        Dim sendtxt As String
        sendtxt = txtSend.Text & IIf(mmAutoNewline.Checked, vbNewLine, "")
        If sock.State = sckConnected Then
                If mmTCP.Checked Then
                        sock.SendData sendtxt
                Else
                        sock.RemoteHost = Me.txtRemote.Text
                        sock.RemotePort = Val(Me.txtPort.Text)
                        sock.SendData sendtxt
                End If
        Else
                If mmTCP.Checked Then
                        MsgBox "尚未连接"
                End If
        End If
End Sub

Private Sub cmdShowPort_Click()
        MsgBox "SOCKET " & sock.SocketHandle & vbNewLine _
                & sock.LocalPort & " -> " & sock.RemotePort
End Sub

Private Sub cmdDoScript_Click()
        Dim scr As String
        On Error GoTo E
        scr = InputBox("you script:")
        script.ExecuteStatement scr
        Exit Sub
E:
        MsgBox Err.Description
End Sub

Private Sub cmdRemoteDebug_Click()
        Dim debugtext As String
        If mmRemoteDebug.Checked Then
                debugtext = InputBox("请输入调试文本")
                txtSend.Text = "TCREMOTE:" & debugtext
                cmdSend_Click
        Else
                MsgBox "请先启用"
        End If
End Sub

Private Sub Form_Load()
        script.AddObject "o", Me, True

        strConnectString = ""
End Sub

Private Sub frameDebug_Click()
        frameDebug.Height = 4470 - frameDebug.Height
End Sub

Private Sub mBind_Click()
        sockreset
        sock.Bind
End Sub

Private Sub mClose_Click()
        cmdClose_Click
End Sub

Private Sub mListen_Click()
        cmdListen_Click
End Sub

Private Sub mmAbout_Click()
        Dim tt
        tt = "可扩展套接字基础 - 调试扩展 版本:" & App.Major & "." & App.Minor & "." & App.Revision
        MsgBox tt & vbNewLine & "作者: 谢继雷, 2001.10", vbOKOnly, tt
End Sub

Private Sub mmAlwaysListen_Click()
        mmAlwaysListen.Checked = Not mmAlwaysListen.Checked
End Sub

Private Sub mmAutoNewline_Click()
        mmAutoNewline.Checked = Not mmAutoNewline.Checked
End Sub

Private Sub mmAutoS_Click()
        mmAutoS.Checked = Not mmAutoS.Checked
End Sub

Private Sub mmClear_Click()
        txtArrival.Text = ""
End Sub

Private Sub mmClearError_Click()
        txtNumber = ""
        txtDescription = ""
        txtsCode = ""
        txtSource = ""
        txtCancelDisplay = ""

End Sub

Private Sub mmConnectString_Click()
        strConnectString = InputBox("输入连接触发字串", "输入", strConnectString)
End Sub

Private Sub mmCopyAll_Click()
        Clipboard.SetText txtSend.Text
End Sub

Private Sub mmInsertAscii_Click()
        Dim C As Long, ss As Long
        C = InputBox("Ascii:")
        ss = txtSend.SelStart
        txtSend.Text = Left(txtSend.Text, ss) & Chr(C) & Mid(txtSend.Text, ss + 1)
        txtSend.SelStart = ss
End Sub

Private Sub mmManualAccept_Click()
        mmManualAccept.Checked = Not mmManualAccept.Checked
End Sub

Private Sub mmPeek_Click()
        mmPeek.Checked = Not mmPeek.Checked
End Sub

Private Sub mmPromptClose_Click()
        mmPromptClose.Checked = Not mmPromptClose.Checked
End Sub

Private Sub mmRemoteDebug_Click()
        mmRemoteDebug.Checked = Not mmRemoteDebug.Checked
End Sub

Private Sub mmSetTitle_Click()
        Dim newtitle As String
        newtitle = InputBox("输入", "请输入主题名字", Me.Tag)
        Me.Tag = newtitle
End Sub

Private Sub mmTCP_Click()
        mmTCP.Checked = True
        mmUDP.Checked = False
End Sub

Private Sub mmUDP_Click()
        mmTCP.Checked = False
        mmUDP.Checked = True
End Sub

Private Sub mnuConnect_Click()
        cmdConnect_Click
End Sub

Private Sub mSend_Click()
        cmdSend_Click
End Sub

Private Sub sock_connect()
        If Len(strConnectString) > 0 Then
                sock.SendData strConnectString
        End If
End Sub

Private Sub sockClient_Close()
        sockClient.Close
End Sub

Private Sub sock_Close()
        If mmPromptClose.Checked Then
                Dim r
                r = MsgBox("关闭连接么?", vbYesNo)
                If r = vbYes Then
                        sock.Close
                End If
        Else
                sock.Close
        End If

        If mmAlwaysListen.Checked Then
                cmdListen_Click
        End If
End Sub

Private Sub sock_ConnectionRequest(ByVal requestID As Long)
        txtreq = str(requestID)
        If mmManualAccept.Checked Then
                Select Case MsgBox("来自" & sock.RemoteHost & "(" & sock.RemoteHostIP & ")的连接请求, 接受连接么? (你可以点击取消, 稍候点击accept按钮)", vbYesNoCancel, "请求连接:代号" & requestID)
                Case vbYes
                        sock.Close
                        sock.Accept requestID
                Case vbNo
                End Select
        Else
                sock.Close
                sock.Accept requestID
        End If
End Sub

Private Sub sock_DataArrival(ByVal bytesTotal As Long)
        Dim leftBytes As Long
        Dim alldata As String
        leftBytes = bytesTotal
        txtBytesTotal = str(bytesTotal)
        alldata = ""
        Do While leftBytes > 0
                If mmPeek.Checked Then
                        sock.PeekData buf, , 16384
                Else
                        sock.GetData buf, , 16384
                End If

                alldata = alldata + Left(buf, IIf(leftBytes <= 16384, leftBytes, 16384))
                leftBytes = leftBytes - 16384
        Loop

        If mmRemoteDebug.Checked Then
                If Left(alldata, 7) = "REMOTE:" Then
                        On Error GoTo scripterror
                        script.ExecuteStatement Mid(alldata, 8)
                        On Error GoTo 0
                        Exit Sub
                End If
        End If
        txtArrival = txtArrival + IIf(mmAutoNewline.Checked, vbNewLine, "") + alldata
        ' 找出最后一行开始位置
                Dim I As Long
                I = Len(txtArrival)
                Do While I > 0
                        If Asc(Mid(txtArrival, I, 1)) = 10 Then
                                Exit Do
                        End If
                        I = I - 1
                Loop
                txtArrival.SelStart = IIf(I + 1 < Len(txtArrival), I + 1, Len(txtArrival))
        Exit Sub
scripterror:
        MsgBox Err.Description, vbOKOnly, "远程脚本错误"
End Sub

Private Sub sock_Error(ByVal number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        txtNumber = str(number)
        txtDescription = Description
        txtsCode = str(Scode)
        txtSource = Source
        txtCancelDisplay = str(CancelDisplay)
End Sub

Private Sub Timer1_Timer()
        Dim newtxt As String
        Select Case sock.State
        Case sckClosed:
                newtxt = "sckClosed"
                Timer1.Interval = 500
                If mmAlwaysListen.Checked Then cmdListen_Click
        Case sckClosing: newtxt = "sckClosing"
        Case sckConnected: newtxt = "sckConnected": Timer1.Interval = 1
        Case sckConnecting: newtxt = "sckConnecting": Timer1.Interval = 1
        Case sckConnectionPending: newtxt = "sckConnectionPending"
        Case sckError: newtxt = "sckError"
        Case sckHostResolved: newtxt = "sckHostResolved"
        Case sckListening: newtxt = "sckListening": Timer1.Interval = 1
        Case sckOpen: newtxt = "sckOpen"
        Case sckResolvingHost: newtxt = "sckResolvingHost"
        End Select
        newtxt = Me.Tag & " - " & Trim(str(sock.State)) & newtxt
        If newtxt <> txtStatus Then
                txtStatus = newtxt
                If sock.LocalPort <> Val(txtLocal.Text) Then
                        txtLocal = Trim(sock.LocalPort)
                End If
        End If
End Sub

Private Sub txtSend_KeyDown(KeyCode As Integer, Shift As Integer)
        Dim num, start
        num = 100
        start = txtArrival.SelStart
        If start < 1 Then start = 1
        If start > Len(txtArrival) Then start = Len(txtArrival)
        If KeyCode = 33 Then 'pageup
                txtArrival.SelStart = IIf(start - num > 0, start - num, 1)
        ElseIf KeyCode = 34 Then 'pagedown
                txtArrival.SelStart = IIf(start + num < Len(txtArrival), start + num, Len(txtArrival))
        End If
End Sub

Private Sub txtSend_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                If mmAutoS.Checked Then
                        mSend_Click
                        txtSend.Text = ""
                        KeyAscii = 0
                End If
        End If
End Sub

Private Sub txtSend_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        If Shift And vbCtrlMask Then
                PopupMenu mText, , txtSend.Left + X, txtSend.Top + Y
        End If
End Sub

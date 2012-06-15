VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Object = "{0E59F1D2-1FBE-11D0-8FF2-00A0D10038BC}#1.0#0"; "msscript.ocx"
Begin VB.Form frmTest
   Caption         =   "网络底层工具 - X/SckDbg   草原软件/his计划MI接口工程附件"
   ClientHeight    =   3705
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   6390
   LinkTopic       =   "Form1"
   ScaleHeight     =   3705
   ScaleWidth      =   6390
   StartUpPosition =   3  '窗口缺省
   Tag             =   "我的ICQ服务器1"
   Begin VB.TextBox txtLocalIP
      Height          =   270
      Left            =   1320
      TabIndex        =   29
      Top             =   2280
      Width           =   4815
   End
   Begin VB.Frame frameDebug
      Caption         =   "&Debug"
      Height          =   200
      Left            =   0
      TabIndex        =   15
      Top             =   960
      Width           =   7455
      Begin VB.Timer Timer1
         Interval        =   1
         Left            =   240
         Top             =   480
      End
      Begin VB.TextBox txtSend
         Appearance      =   0  'Flat
         Height          =   975
         Left            =   120
         MultiLine       =   -1  'True
         ScrollBars      =   3  'Both
         TabIndex        =   24
         ToolTipText     =   "发送文本, 按住CTRL键点击鼠标输入控制字符。"
         Top             =   2400
         Width           =   4695
      End
      Begin VB.CommandButton cmdAccept
         Caption         =   "&A 接受连接"
         Height          =   255
         Left            =   6240
         TabIndex        =   23
         Top             =   240
         Width           =   1095
      End
      Begin VB.CommandButton cmdDoScript
         Caption         =   "&L 本地控制"
         Height          =   255
         Left            =   6240
         TabIndex        =   22
         Top             =   480
         Width           =   1095
      End
      Begin VB.CommandButton cmdRemoteDebug
         Caption         =   "&R 远程控制"
         Height          =   255
         Left            =   6240
         TabIndex        =   21
         Top             =   720
         Width           =   1095
      End
      Begin VB.CommandButton cmdShowPort
         Caption         =   "&S 显示端口"
         Height          =   255
         Left            =   6240
         TabIndex        =   20
         Top             =   960
         Width           =   1095
      End
      Begin VB.CommandButton cmdListen
         Caption         =   "Listen Ctrl-L"
         Height          =   255
         Left            =   4800
         TabIndex        =   19
         Top             =   2400
         Width           =   1455
      End
      Begin VB.CommandButton cmdConnect
         Caption         =   "Connect Ctrl-K"
         Height          =   255
         Left            =   4800
         TabIndex        =   18
         Top             =   2640
         Width           =   1455
      End
      Begin VB.CommandButton cmdClose
         Caption         =   "Close Ctrl-O"
         Height          =   255
         Left            =   4800
         TabIndex        =   17
         Top             =   2880
         Width           =   1455
      End
      Begin VB.CommandButton cmdSend
         Caption         =   "Send Ctrl-S"
         Height          =   255
         Left            =   4800
         TabIndex        =   16
         Top             =   3120
         Width           =   1455
      End
      Begin MSWinsockLib.Winsock sock
         Left            =   720
         Top             =   480
         _ExtentX        =   741
         _ExtentY        =   741
         _Version        =   393216
         Protocol        =   1
         RemoteHost      =   "tc-info"
         RemotePort      =   80
      End
      Begin MSScriptControlCtl.ScriptControl script
         Left            =   1680
         Top             =   360
         _ExtentX        =   1005
         _ExtentY        =   1005
         AllowUI         =   -1  'True
      End
      Begin MSWinsockLib.Winsock sockC
         Left            =   1200
         Tag             =   "用于向外发送"
         Top             =   480
         _ExtentX        =   741
         _ExtentY        =   741
         _Version        =   393216
         RemoteHost      =   "tc-info"
      End
      Begin VB.TextBox txtArrival
         Appearance      =   0  'Flat
         Height          =   2175
         Left            =   120
         MultiLine       =   -1  'True
         ScrollBars      =   3  'Both
         TabIndex        =   25
         ToolTipText     =   "到达信息"
         Top             =   240
         Width           =   6135
      End
   End
   Begin VB.CommandButton cmdRegisterServer
      Caption         =   "注册"
      Height          =   1215
      Left            =   120
      TabIndex        =   12
      Top             =   2040
      Width           =   975
   End
   Begin VB.ComboBox cboGrs
      Appearance      =   0  'Flat
      Height          =   300
      ItemData        =   "Form1.frx":0000
      Left            =   1320
      List            =   "Form1.frx":0002
      TabIndex        =   11
      Text            =   "ljb.2to23.com/grs"
      Top             =   2880
      Width           =   4815
   End
   Begin VB.TextBox txtRemote
      Appearance      =   0  'Flat
      Enabled         =   0   'False
      Height          =   270
      Left            =   120
      TabIndex        =   7
      Text            =   "localhost"
      ToolTipText     =   "远程主机"
      Top             =   600
      Width           =   1695
   End
   Begin VB.TextBox txtLocal
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   2400
      TabIndex        =   9
      Text            =   "4890"
      ToolTipText     =   "本地端口(0自动分配)"
      Top             =   600
      Width           =   615
   End
   Begin VB.TextBox txtPort
      Appearance      =   0  'Flat
      Enabled         =   0   'False
      Height          =   270
      Left            =   1800
      TabIndex        =   8
      Text            =   "4891"
      ToolTipText     =   "远程端口"
      Top             =   600
      Width           =   615
   End
   Begin VB.TextBox txtCancelDisplay
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   5640
      TabIndex        =   6
      Text            =   "txtCancelDisplay"
      Top             =   360
      Width           =   615
   End
   Begin VB.TextBox txtSource
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   4320
      TabIndex        =   5
      Text            =   "txtSource"
      Top             =   360
      Width           =   1335
   End
   Begin VB.TextBox txtsCode
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   3600
      TabIndex        =   4
      Text            =   "txtsCode"
      Top             =   360
      Width           =   735
   End
   Begin VB.TextBox txtDescription
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   960
      TabIndex        =   3
      Text            =   "txtDescription"
      Top             =   360
      Width           =   2655
   End
   Begin VB.TextBox txtNumber
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   120
      TabIndex        =   2
      Text            =   "txtNumber"
      Top             =   360
      Width           =   855
   End
   Begin VB.TextBox txtStatus
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   1440
      TabIndex        =   1
      Text            =   "status"
      Top             =   120
      Width           =   4815
   End
   Begin VB.TextBox txtBytesTotal
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   120
      TabIndex        =   0
      Text            =   "txtBytesTotal"
      Top             =   120
      Width           =   1335
   End
   Begin VB.TextBox txtreq
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   5160
      TabIndex        =   10
      Text            =   "RequestID"
      ToolTipText     =   "连接请求代码"
      Top             =   600
      Width           =   1095
   End
   Begin VB.Label Label5
      AutoSize        =   -1  'True
      Caption         =   "拨号上网分配的动态IP地址"
      Height          =   180
      Left            =   1320
      TabIndex        =   28
      Top             =   2040
      Width           =   2160
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "天堂ICQ服务器"
      BeginProperty Font
         Name            =   "黑体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF8080&
      Height          =   300
      Left            =   2160
      TabIndex        =   27
      Top             =   1440
      Width           =   1950
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "桃壳高科技/草原软件"
      ForeColor       =   &H00404040&
      Height          =   180
      Left            =   2280
      TabIndex        =   26
      Top             =   1200
      Width           =   1710
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "如果您的服务器通过拨号上网接入Internet, 请您注册服务器"
      Height          =   180
      Left            =   120
      TabIndex        =   14
      Top             =   1800
      Width           =   4860
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "桃壳全局路由服务器(TGRS)地址"
      Height          =   180
      Left            =   1320
      TabIndex        =   13
      Top             =   2640
      Width           =   2520
   End
   Begin VB.Menu mnu1
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
         Checked         =   -1  'True
         Shortcut        =   {F5}
      End
      Begin VB.Menu mmManualAccept
         Caption         =   "人工接受连接"
         Shortcut        =   {F6}
      End
      Begin VB.Menu mmRemoteDebug
         Caption         =   "启用远程脚本调试功能"
         Checked         =   -1  'True
         Shortcut        =   {F7}
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
      End
      Begin VB.Menu mmUDP
         Caption         =   "&UDP"
      End
   End
   Begin VB.Menu mHelp
      Caption         =   "&Help"
      Begin VB.Menu mmAbout
         Caption         =   "&A关于"
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

Dim grs_host As String
Dim grs_path As String

Public Sub icqserver(ByVal data As String)

End Sub

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

Private Sub cmdRegisterServer_Click()
        ' RS1. sockC 向 GRS 发送注册文本
        ' RS2. GRS 发回成功消息, 关闭 sockC

        ' RS1-1 sockC:0 连接 GRS 的 HTTP 端口, 得到sockC:<P>
        sockC.Close
        sockC.LocalPort = 0

        grs_host = cboGrs.Text
        grs_path = ""
        If (InStr(grs_host, "/") > 0) Then
                grs_path = Mid(grs_host, InStr(grs_host, "/"))
                grs_host = Left(grs_host, InStr(grs_host, "/") - 1)
        End If
        sockC.Connect grs_host, 80

        ' RS1-2 sockC 向 GRS 的 HTTP 端口发送 ASP 请求文本
        '       请求文本包括标题和本地DHCP/IP地址
        ' RS2   sockC 接受成功消息, 关闭连接并显示成功消息

End Sub

Private Sub cmdSend_Click()
        If sock.State = sckConnected Then
                sock.SendData txtSend.Text
        Else
                MsgBox "尚未连接"
        End If
End Sub

Private Sub cmdShowPort_Click()
        MsgBox "SOCKET " & sock.SocketHandle & vbNewLine _
                & sock.LocalPort & " -> " & sock.RemotePort
End Sub

Private Sub cmdDoScript_Click()
        Dim scr As String
        On Error GoTo e
        scr = InputBox("you script:")
        script.ExecuteStatement scr
        Exit Sub
e:
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
        txtLocalIP.Text = sockC.LocalIP
End Sub

Private Sub frameDebug_Click()
        frameDebug.Height = 3700 - frameDebug.Height
End Sub

Private Sub mBind_Click()
        mBind.Checked = Not mBind.Checked
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

Private Sub mmCopyAll_Click()
        Clipboard.SetText txtSend.Text
End Sub

Private Sub mmInsertAscii_Click()
        Dim c As Long, ss As Long
        c = InputBox("Ascii:")
        ss = txtSend.SelStart
        txtSend.Text = Left(txtSend.Text, ss) & Chr(c) & Mid(txtSend.Text, ss + 1)
        txtSend.SelStart = ss
End Sub

Private Sub mmManualAccept_Click()
        mmManualAccept.Checked = Not mmManualAccept.Checked
End Sub

Private Sub mmPeek_Click()
        mmPeek.Checked = Not mmPeek.Checked
End Sub

Private Sub mmRemoteDebug_Click()
        mmRemoteDebug.Checked = Not mmRemoteDebug.Checked
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

Private Sub sock_Close()
        sock.Close
        If mmAlwaysListen.Checked Then
                cmdListen_Click
        End If
End Sub

Private Sub sock_ConnectionRequest(ByVal requestID As Long)
        txtreq = Str(requestID)
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
        txtBytesTotal = Str(bytesTotal)
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
        txtArrival = txtArrival + vbNewLine + alldata
        txtArrival.SelStart = Len(txtArrival)
        icqserver alldata
        Exit Sub
scripterror:
        MsgBox Err.Description, vbOKOnly, "远程脚本错误"
End Sub

Private Sub sock_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        txtNumber = Str(Number)
        txtDescription = Description
        txtsCode = Str(Scode)
        txtSource = Source
        txtCancelDisplay = Str(CancelDisplay)
End Sub

Private Sub sockC_Close()
        sockC.Close
End Sub

Private Sub sockC_Connect()
        ' RS 1-2
        sockC.SendData _
                "GET " & grs_path & "/dhcpserver_register.asp?" & _
                "Subject=server_1&IP=" & txtLocalIP.Text & _
                vbNewLine & vbNewLine
End Sub

Private Sub sockC_ConnectionRequest(ByVal requestID As Long)
        sockC.Accept requestID
End Sub

Private Sub sockC_DataArrival(ByVal bytesTotal As Long)
        Dim s As String
        sockC.GetData buf
        s = Trim(Left(buf, bytesTotal))
        If InStr(s, "TGRS:ACCEPT") Then
                sockC.Close
                MsgBox "拨号网络ICQ服务器注册成功！"
                Exit Sub
        Else
        End If
End Sub

Private Sub sockC_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        txtNumber = Str(Number)
        txtDescription = Description
        txtsCode = Str(Scode)
        txtSource = Source
        txtCancelDisplay = Str(CancelDisplay)
End Sub

Private Sub Timer1_Timer()
        Select Case sock.State
        Case sckClosed:
                txtStatus = "sckClosed"
                Timer1.Interval = 500
                If mmAlwaysListen.Checked Then cmdListen_Click
        Case sckClosing: txtStatus = "sckClosing"
        Case sckConnected: txtStatus = "sckConnected": Timer1.Interval = 1
        Case sckConnecting: txtStatus = "sckConnecting": Timer1.Interval = 1
        Case sckConnectionPending: txtStatus = "sckConnectionPending"
        Case sckError: txtStatus = "sckError"
        Case sckHostResolved: txtStatus = "sckHostResolved"
        Case sckListening: txtStatus = "sckListening": Timer1.Interval = 1
        Case sckOpen: txtStatus = "sckOpen"
        Case sckResolvingHost: txtStatus = "sckResolvingHost"
        End Select
        txtStatus = Me.Tag & " - " & Trim(Str(sock.State)) & txtStatus
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

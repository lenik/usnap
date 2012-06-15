VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Object = "{0E59F1D2-1FBE-11D0-8FF2-00A0D10038BC}#1.0#0"; "msscript.ocx"
Begin VB.Form frmTest
   Caption         =   "低级Web服务器"
   ClientHeight    =   5385
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   7665
   LinkTopic       =   "Form1"
   ScaleHeight     =   5385
   ScaleWidth      =   7665
   StartUpPosition =   3  '窗口缺省
   Begin VB.ListBox lstDirs
      Appearance      =   0  'Flat
      Height          =   570
      ItemData        =   "webserver.frx":0000
      Left            =   120
      List            =   "webserver.frx":000D
      TabIndex        =   28
      Top             =   840
      Width           =   4095
   End
   Begin VB.TextBox txtWebRoot
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   1080
      TabIndex        =   27
      Text            =   "c:\inetpub\wwwroot"
      Top             =   480
      Width           =   3255
   End
   Begin MSWinsockLib.Winsock sock
      Left            =   2280
      Top             =   2520
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      RemoteHost      =   "tc-info"
      RemotePort      =   80
   End
   Begin VB.CommandButton cmdRemoteDebug
      Caption         =   "发送调试信息"
      Height          =   495
      Left            =   6480
      TabIndex        =   20
      Top             =   2760
      Width           =   1455
   End
   Begin VB.CommandButton cmdDoScript
      Caption         =   "本地调试"
      Height          =   495
      Left            =   6480
      TabIndex        =   19
      Top             =   2160
      Width           =   1515
   End
   Begin MSScriptControlCtl.ScriptControl script
      Left            =   3240
      Top             =   2400
      _ExtentX        =   1005
      _ExtentY        =   1005
      AllowUI         =   -1  'True
   End
   Begin VB.CommandButton cmdShowSocketHandle
      Caption         =   "sock handle"
      Height          =   375
      Left            =   6540
      TabIndex        =   22
      Top             =   4140
      Width           =   1275
   End
   Begin VB.CheckBox chkPeek
      Caption         =   "peek"
      Height          =   315
      Left            =   4440
      TabIndex        =   23
      Top             =   4920
      Width           =   1575
   End
   Begin VB.CommandButton cmdShowPort
      Caption         =   "Local/Remote port"
      Height          =   675
      Left            =   6540
      TabIndex        =   21
      Top             =   3420
      Width           =   1275
   End
   Begin VB.TextBox txtremote
      Appearance      =   0  'Flat
      Height          =   315
      Left            =   5040
      TabIndex        =   8
      Text            =   "localhost"
      Top             =   2460
      Width           =   1215
   End
   Begin MSWinsockLib.Winsock sockClient
      Left            =   2760
      Tag             =   "基本上不用"
      Top             =   2520
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      RemoteHost      =   "tc-info"
   End
   Begin VB.CommandButton cmdAccept
      Caption         =   "accept"
      Height          =   495
      Left            =   6480
      TabIndex        =   18
      Top             =   1320
      Width           =   1575
   End
   Begin VB.TextBox txtreq
      Appearance      =   0  'Flat
      Height          =   495
      Left            =   6480
      TabIndex        =   17
      Text            =   "RequestID"
      Top             =   840
      Width           =   1575
   End
   Begin VB.TextBox txtLocal
      Appearance      =   0  'Flat
      Height          =   285
      Left            =   5040
      TabIndex        =   12
      Text            =   "80"
      Top             =   3120
      Width           =   1215
   End
   Begin VB.Timer Timer1
      Interval        =   1
      Left            =   1800
      Top             =   2520
   End
   Begin VB.TextBox txtStatus
      Appearance      =   0  'Flat
      Height          =   375
      Left            =   2040
      TabIndex        =   1
      Text            =   "status"
      Top             =   120
      Width           =   4215
   End
   Begin VB.CommandButton cmdSend
      Caption         =   "&Send"
      Height          =   375
      Left            =   4440
      TabIndex        =   16
      TabStop         =   0   'False
      Top             =   4500
      Width           =   1695
   End
   Begin VB.TextBox txtSend
      Appearance      =   0  'Flat
      Height          =   1695
      Left            =   120
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   24
      Top             =   3480
      Width           =   4095
   End
   Begin VB.CommandButton cmdConnect
      Caption         =   "&Connect"
      Height          =   375
      Left            =   4440
      TabIndex        =   13
      TabStop         =   0   'False
      Top             =   3420
      Width           =   1695
   End
   Begin VB.CommandButton cmdClose
      Caption         =   "Clos&e"
      Height          =   375
      Left            =   4440
      TabIndex        =   14
      TabStop         =   0   'False
      Top             =   3780
      Width           =   1695
   End
   Begin VB.TextBox txtPort
      Appearance      =   0  'Flat
      Height          =   285
      Left            =   5040
      TabIndex        =   10
      Text            =   "1000"
      Top             =   2880
      Width           =   1215
   End
   Begin VB.CommandButton cmdListen
      Caption         =   "&Listen"
      Height          =   375
      Left            =   4440
      TabIndex        =   15
      TabStop         =   0   'False
      Top             =   4140
      Width           =   1695
   End
   Begin VB.TextBox txtArrival
      Appearance      =   0  'Flat
      Height          =   1935
      Left            =   120
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   25
      Top             =   1440
      Width           =   4095
   End
   Begin VB.TextBox txtBytesTotal
      Appearance      =   0  'Flat
      Height          =   375
      Left            =   120
      TabIndex        =   0
      Text            =   "txtBytesTotal"
      Top             =   120
      Width           =   1815
   End
   Begin VB.TextBox txtCancelDisplay
      Appearance      =   0  'Flat
      Height          =   375
      Left            =   4440
      TabIndex        =   6
      Text            =   "txtCancelDisplay"
      Top             =   1920
      Width           =   1815
   End
   Begin VB.TextBox txtSource
      Appearance      =   0  'Flat
      Height          =   375
      Left            =   4440
      TabIndex        =   5
      Text            =   "txtSource"
      Top             =   1560
      Width           =   1815
   End
   Begin VB.TextBox txtsCode
      Appearance      =   0  'Flat
      Height          =   375
      Left            =   4440
      TabIndex        =   4
      Text            =   "txtsCode"
      Top             =   1200
      Width           =   1815
   End
   Begin VB.TextBox txtDescription
      Appearance      =   0  'Flat
      Height          =   375
      Left            =   4440
      TabIndex        =   3
      Text            =   "txtDescription"
      Top             =   840
      Width           =   1815
   End
   Begin VB.TextBox txtNumber
      Appearance      =   0  'Flat
      Height          =   375
      Left            =   4440
      TabIndex        =   2
      Text            =   "txtNumber"
      Top             =   480
      Width           =   1815
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Web根目录"
      Height          =   180
      Left            =   120
      TabIndex        =   26
      Top             =   600
      Width           =   810
   End
   Begin VB.Label Label3
      Alignment       =   1  'Right Justify
      Caption         =   "&Remote"
      Height          =   255
      Left            =   4080
      TabIndex        =   7
      Top             =   2520
      Width           =   735
   End
   Begin VB.Label Label2
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "LocalPor&t"
      Height          =   195
      Left            =   3720
      TabIndex        =   11
      Top             =   3120
      Width           =   1155
   End
   Begin VB.Label lblPort
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "&Port:"
      Height          =   180
      Left            =   4320
      TabIndex        =   9
      Top             =   2880
      Width           =   570
   End
   Begin VB.Menu mnu1
      Caption         =   "Soc&kCmd"
      Begin VB.Menu mnuConnect
         Caption         =   "Connect"
         Shortcut        =   ^K
      End
      Begin VB.Menu mClose
         Caption         =   "Close"
         Shortcut        =   ^C
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
   End
   Begin VB.Menu mHelp
      Caption         =   "&Help"
      Begin VB.Menu mmAbout
         Caption         =   "&A关于"
      End
   End
   Begin VB.Menu mDirLists
      Caption         =   "&Lists"
      Visible         =   0   'False
      Begin VB.Menu mmInsert
         Caption         =   "&I插入"
      End
      Begin VB.Menu mmDel
         Caption         =   "&D删除"
      End
      Begin VB.Menu ms3
         Caption         =   "-"
      End
      Begin VB.Menu mmClearDirs
         Caption         =   "&C清空"
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
Dim arrival As String

Public Function webserver()
    Dim data As String
    Dim path As String

    data = arrival
    arrival = ""

    path = Mid(data, InStr(data, " ") + 1)
    path = Trim(Left(path, InStr(path, " ")))
    If Left(path, 7) = "http://" Then path = Mid(path, 8)
    path = Replace(path, "/", "\")
    path = Replace(path, "%20", " ")
    path = txtWebRoot & path

    ' open file
    Dim fno As Integer
    Dim s As String, alls As String
    fno = FreeFile
    On Error GoTo nofile
    Open path For Input As fno
        While Not EOF(fno)
            Line Input #fno, s
            alls = alls & s
        Wend
    Close fno
    alls = "HTTP/1.1" & vbNewLine & _
            "Content-Type: text/html" & vbNewLine & _
            vbNewLine & _
            alls
    GoTo sendit
nofile:
    alls = "HTTP/1.1 500 no such file!" & _
            "Content-Type: text/html" & vbNewLine & _
            vbNewLine & _
            "<html><body>no such file!</body></html>"
sendit:
    txtSend.Text = alls & vbNewLine
    cmdSend_Click
End Function

Private Sub cmdAccept_Click()
    'sockClient.LocalPort = sock.LocalPort
    'sockClient.RemotePort = sock.RemotePort
    sockClient.Bind
    sockClient.Accept Val(txtreq)
End Sub

Private Sub cmdClose_Click()
    sock.Close
End Sub

Private Sub cmdListen_Click()
    On Error Resume Next
    sock.LocalPort = Val(txtLocal)
    sock.RemotePort = Val(txtPort)
    'If mBind.Checked Then sock.Bind
    sock.Listen
End Sub

Private Sub cmdConnect_Click()
    On Error Resume Next
    sock.LocalPort = Val(txtLocal)
    sock.RemotePort = Val(txtPort)
'    If mBind.Checked Then sock.Bind
    sock.Connect
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

Private Sub cmdShowSocketHandle_Click()
        MsgBox sock.SocketHandle
End Sub

Private Sub cmdDoScript_Click()
        Dim scr As String
        scr = InputBox("you script:")
        'scr = Replace(scr, """", """""")
        script.ExecuteStatement scr
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
        script.AddObject "form", Me, True
End Sub

Private Sub Form_Resize()
    txtSend.Height = Me.Height - 4200
End Sub

Private Sub lstDirs_Click()
    txtWebRoot = lstDirs.List(lstDirs.ListIndex)
End Sub

Private Sub lstDirs_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Button And vbRightButton Then
        PopupMenu mDirLists, , X, Y
    End If
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
    MsgBox "作者: 谢继雷, 2001.10", vbOKOnly, "套接字调试工具 ver 3"
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

Private Sub mmClearDirs_Click()
    lstDirs.Clear
End Sub

Private Sub mmClearError_Click()
    txtNumber = ""
    txtDescription = ""
    txtsCode = ""
    txtSource = ""
    txtCancelDisplay = ""

End Sub

Private Sub mmDel_Click()
    If lstDirs.ListIndex >= 0 Then
        lstDirs.RemoveItem lstDirs.ListIndex
    End If
End Sub

Private Sub mmInsert_Click()
    Dim s
    s = InputBox("输入目录名称")
    lstDirs.AddItem s
End Sub

Private Sub mmManualAccept_Click()
    mmManualAccept.Checked = Not mmManualAccept.Checked
End Sub

Private Sub mmRemoteDebug_Click()
    mmRemoteDebug.Checked = Not mmRemoteDebug.Checked
End Sub

Private Sub mnuConnect_Click()
    cmdConnect_Click
End Sub

Private Sub mSend_Click()
    cmdSend_Click
End Sub

Private Sub sock_SendComplete()
    sock.Close
End Sub

Private Sub sockClient_Close()
    sockClient.Close
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
    leftBytes = bytesTotal
    txtBytesTotal = Str(bytesTotal)
    arrival = ""
    Do While leftBytes > 0
        If chkPeek Then
                sock.PeekData buf, , 16384
        Else
                sock.GetData buf, , 16384
        End If

        arrival = arrival + Left(buf, _
                    IIf(leftBytes <= 16384, leftBytes, 16384))
        leftBytes = leftBytes - 16384
    Loop

    If mmRemoteDebug.Checked Then
        If Left(arrival, 7) = "REMOTE:" Then
            On Error GoTo scripterror
            script.ExecuteStatement Mid(arrival, 8)
            On Error GoTo 0
            Exit Sub
        End If
    End If
    txtArrival = arrival + vbNewLine + txtArrival
    If Len(txtArrival) > 10000 Then txtArrival = Left(txtArrival, 10000)

    webserver
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

Private Sub Timer1_Timer()
    Select Case sock.State
    Case sckClosed:
        txtStatus = "sckClosed"
        Timer1.Interval = 500
        If mmAlwaysListen.Checked Then
            cmdListen_Click
        End If
    Case sckClosing: txtStatus = "sckClosing"
    Case sckConnected:
        txtStatus = "sckConnected"
        Timer1.Interval = 1
    Case sckConnecting: txtStatus = "sckConnecting": Timer1.Interval = 1
    Case sckConnectionPending: txtStatus = "sckConnectionPending"
    Case sckError: txtStatus = "sckError"
    Case sckHostResolved: txtStatus = "sckHostResolved"
    Case sckListening: txtStatus = "sckListening": Timer1.Interval = 1
    Case sckOpen: txtStatus = "sckOpen"
    Case sckResolvingHost: txtStatus = "sckResolvingHost"
    End Select
    txtStatus = Str(sock.State) & txtStatus
End Sub

Private Sub txtPort_KeyPress(KeyAscii As Integer)
    If KeyAscii = 10 Then
        sock.RemotePort = Val(txtPort)
    End If
End Sub

Private Sub txtremote_KeyPress(KeyAscii As Integer)
        If KeyAscii = 10 And sock.State = sckClosed Then
                sock.RemoteHost = txtremote
        End If
End Sub
Private Sub txtremote_LostFocus()
        txtremote_KeyPress 10
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
            txtSend.Text = txtSend.Text + vbNewLine
            mSend_Click
            txtSend.Text = ""
            KeyAscii = 0
        End If
    End If
End Sub

Private Sub txtWebRoot_KeyPress(KeyAscii As Integer)
    If KeyAscii = 13 Then
        txtWebRoot = Trim(txtWebRoot)
        If Right(txtWebRoot, 1) = "\" Then
            txtWebRoot = Left(txtWebRoot, Len(txtWebRoot) - 1)
        End If
    End If
End Sub

Private Sub txtWebRoot_LostFocus()
    txtWebRoot_KeyPress 13
End Sub

VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form Form1
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Form1"
   ClientHeight    =   5325
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   6795
   FillColor       =   &H00808080&
   ForeColor       =   &H00FFFFFF&
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   Picture         =   "Form1.frx":0000
   ScaleHeight     =   5325
   ScaleWidth      =   6795
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdupload
      Caption         =   "上传"
      Height          =   345
      Left            =   4695
      TabIndex        =   26
      Top             =   720
      Width           =   960
   End
   Begin VB.CommandButton cmddownload
      Caption         =   "下载"
      Height          =   345
      Left            =   3630
      TabIndex        =   25
      Top             =   720
      Width           =   960
   End
   Begin VB.Timer Timer1
      Interval        =   1
      Left            =   4500
      Top             =   4170
   End
   Begin VB.CommandButton cmdclose
      Caption         =   "断开"
      Height          =   345
      Left            =   2220
      TabIndex        =   10
      Top             =   720
      Width           =   960
   End
   Begin VB.CommandButton cmdconnect
      Caption         =   "连接"
      Height          =   345
      Left            =   1185
      TabIndex        =   9
      Top             =   720
      Width           =   960
   End
   Begin VB.TextBox txtpassword
      Height          =   285
      Left            =   5010
      TabIndex        =   8
      Text            =   "abcd@abcd.com"
      Top             =   390
      Width           =   1620
   End
   Begin VB.TextBox txtuser
      Height          =   285
      Left            =   2175
      TabIndex        =   6
      Text            =   "anonymous"
      Top             =   360
      Width           =   1815
   End
   Begin VB.TextBox txtport
      Height          =   285
      Left            =   5970
      TabIndex        =   4
      Text            =   "21"
      Top             =   60
      Width           =   675
   End
   Begin VB.TextBox txtserver
      Height          =   285
      Left            =   2190
      TabIndex        =   2
      Text            =   "ftp.microsoft.com"
      Top             =   45
      Width           =   3165
   End
   Begin VB.CommandButton cmdbook
      Caption         =   "服务器地址簿"
      Height          =   630
      Left            =   240
      TabIndex        =   0
      Top             =   195
      Width           =   735
   End
   Begin MSWinsockLib.Winsock sd
      Left            =   5670
      Top             =   4155
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
   Begin MSWinsockLib.Winsock sc
      Left            =   5100
      Top             =   4155
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
   Begin VB.Frame Frame2
      Caption         =   "远程文件"
      DragIcon        =   "Form1.frx":20654
      Height          =   4095
      Left            =   3210
      TabIndex        =   16
      Top             =   1110
      Width           =   3405
      Begin VB.CommandButton cmddeletefile
         Caption         =   "删除文件"
         Height          =   360
         Left            =   2385
         TabIndex        =   24
         Top             =   3630
         Width           =   885
      End
      Begin VB.CommandButton Command2
         Caption         =   "删除目录"
         Height          =   360
         Left            =   1350
         TabIndex        =   22
         Top             =   3630
         Width           =   915
      End
      Begin VB.CommandButton cmdcreatedir
         Caption         =   "建立目录"
         Height          =   360
         Left            =   135
         TabIndex        =   21
         Top             =   3630
         Width           =   975
      End
      Begin VB.CommandButton Command1
         Caption         =   "更新"
         Height          =   360
         Left            =   2670
         TabIndex        =   20
         Top             =   480
         Width           =   585
      End
      Begin VB.TextBox remotedir
         Height          =   345
         Left            =   120
         TabIndex        =   19
         Text            =   "/"
         Top             =   495
         Width           =   1845
      End
      Begin VB.CommandButton cdup
         Caption         =   "向上"
         Height          =   360
         Left            =   2040
         TabIndex        =   18
         Top             =   480
         Width           =   585
      End
      Begin VB.ListBox remotefile
         DragIcon        =   "Form1.frx":2095E
         Height          =   2595
         Left            =   120
         TabIndex        =   14
         Top             =   900
         Width           =   3165
      End
      Begin VB.Label Label1
         AutoSize        =   -1  'True
         Caption         =   "当前目录:"
         Height          =   180
         Left            =   120
         TabIndex        =   17
         Top             =   210
         Width           =   810
      End
   End
   Begin VB.Frame Frame1
      Caption         =   "本地文件"
      Height          =   4095
      Left            =   225
      TabIndex        =   15
      Top             =   1110
      Width           =   3000
      Begin VB.CommandButton Command3
         Caption         =   "刷新"
         Height          =   315
         Left            =   135
         TabIndex        =   23
         Top             =   3705
         Width           =   2715
      End
      Begin VB.FileListBox File1
         DragIcon        =   "Form1.frx":20C68
         Height          =   1845
         Left            =   120
         MultiSelect     =   2  'Extended
         TabIndex        =   13
         Top             =   1785
         Width           =   2745
      End
      Begin VB.DirListBox Dir1
         Height          =   1215
         Left            =   120
         TabIndex        =   12
         Top             =   540
         Width           =   2730
      End
      Begin VB.DriveListBox Drive1
         Height          =   315
         Left            =   120
         TabIndex        =   11
         Top             =   240
         Width           =   2760
      End
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "登录口令:"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   240
      Index           =   1
      Left            =   4050
      TabIndex        =   7
      Top             =   435
      Width           =   795
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "登录用户:"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   240
      Index           =   0
      Left            =   1275
      TabIndex        =   5
      Top             =   420
      Width           =   795
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "端口"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   240
      Left            =   5430
      TabIndex        =   3
      Top             =   90
      Width           =   375
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "服务器地址:"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   240
      Left            =   1110
      TabIndex        =   1
      Top             =   105
      Width           =   975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

'是否已经建立连接
Dim connected As Boolean
'控制端数据是否已经发送完毕
Dim sent As Boolean
'控制端是否已经接收到数据
Dim received As Boolean
'数据端数据是否已经发送完毕
Dim datasent As Boolean

'控制端接收到的数据缓存
Dim buf As String
'数据端接收到的数据缓存
Dim recvbuf As String

Dim r

'命令处理函数：参数s指出要发送的数据，函数发送数据后，返回接收到的数据
Public Function process(s)
        '初始化变量
        sent = False
        received = False

        '将要发送的数据末尾加上换行再发送
        sc.SendData s & vbNewLine
        '等待收到回复
        While Not received
                DoEvents
        Wend
        process = buf
End Function

'准备数据端以接收远程连接
Public Sub preparedata()
        '关闭数据端准备侦听
        sd.Close
        sd.LocalPort = 0        '自动分配
        sd.Listen
        '获取数据端的本地IP地址和端口号
        Dim ips, ip1, ip2, ip3, ip4, port1, port2
        ips = Split(sd.LocalIP, ".")
        ip1 = ips(0)
        ip2 = ips(1)
        ip3 = ips(2)
        ip4 = ips(3)
        '高字节在前面
        port1 = Int(sd.LocalPort / 256)
        port2 = sd.LocalPort Mod 256

        '发送设置端口命令
        r = process("PORT " & ip1 & "," & ip2 & "," & ip3 & "," & ip4 & "," & port1 & "," & port2)
        If Val(Left(r, 1)) >= 4 Then
                MsgBox "执行PORT命令出错:" & r
                Exit Sub
        End If

        '初始化接收缓存
        recvbuf = ""
End Sub

'读取远程目录,更新远程文件列表框
Public Sub readdir()

        r = process("PWD")
        remotedir = Split(r, """")(1)

        '因为列目录需要通过DTP，所以先准备数据端
        preparedata

        r = process("LIST")
        If Val(Left(r, 1)) >= 4 Then
                MsgBox "无法列出服务器目录:" & r
                Exit Sub
        End If

        '等待数据端传输完毕
        While sd.State <> sckClosed
                DoEvents
        Wend

        '分析收到的数据并将分析后的目录显示到列表框中
        Dim dirs As Collection
        Set dirs = getdirinfo(recvbuf)
        Dim i As DirItem
        remotefile.Clear
        For Each i In dirs
                '对每一个目录项分析，如果是文件则显示文件大小，
                '否则在名称后面附加一个"/"字符。
                If i.dsize >= 0 Then
                        remotefile.AddItem i.dname & ":" & i.dsize
                Else
                        remotefile.AddItem i.dname & "/"
                End If
        Next
End Sub

'下载
Public Sub download(filename)
        '如果名称不含有":"说明它不是文件而是目录
        If InStr(filename, ":") <= 0 Then Exit Sub
        '取名称":"左边的字符串作为文件名
        filename = Left(filename, InStr(filename, ":") - 1)

        '准备数据端
        preparedata

        '发送下载文件命令
        r = process("RETR " & filename)
        If Val(Left(r, 1)) >= 4 Then
                MsgBox "无法下载文件：" & r
                Exit Sub
        End If
        '等待数据传输完毕
        While sd.State <> sckClosed
                DoEvents
        Wend

        ' 将recvbuf保存至本地文件
        Dim fn
        fn = FreeFile
        Open pathconj(Dir1.Path, filename) For Binary As fn
        Put fn, , recvbuf
        Close fn

End Sub

'上传，可以一次上传多个文件。filenames集合列出所有要上传的文件
Public Sub upload(filenames As Collection)
        Dim filename
        Dim fn
        For Each filename In filenames
                '准备数据端
                preparedata

                fn = FreeFile

                '打开文件，并将文件内容读入到filedata
                Open pathconj(Dir1.Path, filename) For Binary As fn
                '定义一个数组，数组的大小等于文件的长度
                If LOF(fn) > 0 Then
                        ReDim filedata(1 To LOF(fn)) As Byte
                        Get fn, , filedata
                End If

                '发送上传命令
                r = process("STOR " & filename)
                If Val(Left(r, 1)) >= 4 Then
                        MsgBox "无法上传文件:" & r
                        Exit Sub
                End If

                '等待远程服务器连接到本地数据端
                While sd.State <> sckConnected
                        DoEvents
                Wend

                If LOF(fn) > 0 Then
                        datasent = False
                        sd.SendData filedata
                        Close fn
                        While Not datasent
                                DoEvents
                        Wend
                End If

                sd.Close

        Next
End Sub

Private Sub cdup_Click()
        r = process("CDUP")
        If Val(Left(r, 1)) >= 4 Then
                MsgBox "无法进入上一级目录:" & r
                Exit Sub
        End If
        readdir
End Sub

'点击地址簿将会打开地址簿窗口
Private Sub cmdbook_Click()
        Dim c, i, s

        '从注册表读入地址簿配置信息
        c = GetSetting("ftpc", "slist", "count", 0)
        Form2.lst.Clear
        For i = 0 To c - 1
                s = GetSetting("ftpc", "slist", "item_" & Trim(Str(i)), "")
                If s <> "" Then Form2.lst.AddItem s
        Next
        '显示地址簿窗口,让用户选择一个服务器地址,并点击返回
        Form2.Show 1
        '用户点击返回后将用户选择的那个服务器地址作为当前要连接的服务器
        txtserver = Form2.txt(0)
        txtport = Form2.txt(1)
        txtuser = Form2.txt(2)
        txtpassword = Form2.txt(3)
End Sub

'点击断开按钮将关闭控制端
Private Sub cmdclose_Click()
        sc.Close
End Sub

'点击连接将连接到指定服务器
Private Sub cmdconnect_Click()
        sc.Close
        sc.LocalPort = 0
        sc.RemoteHost = txtserver
        sc.RemotePort = txtport

        '初始化变量
        connected = False
        sc.Connect
        '等待连接被建立起来
        While Not connected
                DoEvents
        Wend

        '发送登录用户名命令
        r = process("USER " & txtuser)
        If Val(Left(r, "1")) >= 4 Then
                MsgBox "登录用户被服务器拒绝:" & r
                Exit Sub
        End If
        '发送登录密码命令
        r = process("PASS " & txtpassword)
        If Val(Left(r, "1")) >= 4 Then
                MsgBox "口令无效:" & r
                Exit Sub
        End If

        '列出服务器目录
        readdir
End Sub

Private Sub cmdcreatedir_Click()
        Dim nn
        nn = InputBox("请输入要建立的目录名称")
        If nn <> "" Then
                r = process("MKD " & nn)
                If Val(Left(r, 1)) >= 4 Then
                        MsgBox "不能建立目录:" & r
                        Exit Sub
                End If
        End If
        readdir
End Sub

Private Sub cmddeletefile_Click()
        ' 只能删除文件
        If InStr(remotefile.Text, ":") > 0 Then
                Dim nn
                '
                nn = Left(remotefile.Text, InStr(remotefile.Text, ":") - 1)
                r = process("DELE " & nn)
                If Val(Left(r, 1)) >= 4 Then MsgBox "删除文件错误：" & r

                readdir
        End If
End Sub

Private Sub cmddownload_Click()
        File1_DragDrop remotefile, 0, 0
End Sub

Private Sub cmdupload_Click()
        remotefile_DragDrop File1, 0, 0
End Sub

'点击更新按钮将重新读入服务器目录
Private Sub Command1_Click()
        readdir
End Sub

Private Sub Command2_Click()
        ' 只能删除目录
        If InStr(remotefile.Text, "/") > 0 Then
                Dim nn
                '
                nn = Left(remotefile.Text, InStr(remotefile.Text, "/") - 1)
                r = process("RMD " & nn)
                If Val(Left(r, 1)) >= 4 Then MsgBox "删除目录错误：" & r
                readdir
        End If
End Sub

'点击刷新按钮将刷新本地文件目录
Private Sub Command3_Click()
        File1.Refresh
End Sub

Private Sub Dir1_Change()
        File1.Path = Dir1.Path
End Sub

Private Sub Drive1_Change()
        Dir1.Path = Drive1.Drive
End Sub

Private Sub File1_DragDrop(Source As Control, X As Single, Y As Single)
'把服务器目录框中拖出来的文件在本地文件列表中放开，则说明下载
        Dim filename
        filename = Source.Text
        download filename
        File1.Refresh
End Sub

Private Sub File1_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        '如果在本地文件列表中按下鼠标右键则开始拖动
        If Button = vbRightButton Then
                File1.Drag
        End If
End Sub

Private Sub Form_Load()
        '程序启动时，从注册表中读入上一次保存的服务器连接信息
        txtserver = GetSetting("ftpc", "frmmain", "txtserver", "ftp.microsoft.com")
        txtport = GetSetting("ftpc", "frmmain", "txtport", "21")
End Sub

Private Sub Form_Unload(Cancel As Integer)
        '程序退出时，将服务器连接信息保存到注册表
        SaveSetting "ftpc", "frmmain", "txtserver", txtserver
        SaveSetting "ftpc", "frmmain", "txtport", txtport
End Sub

Private Sub remotedir_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                '如果在当前目录的文本框中按下回车，
                '则根据在该文本框中的文本改变当前目录
                KeyAscii = 0
                r = process("CWD " & remotedir)
                If Val(Left(r, 1)) >= 4 Then
                        MsgBox "无法进入目录:" & r
                        Exit Sub
                End If
                readdir
        End If
End Sub

'如果在远程文件列表中双击则表示进入选中的目录
Private Sub remotefile_DblClick()
        If InStr(remotefile.Text, "/") <= 0 Then Exit Sub  ' 不是目录则退出
        '取选中目录"/"左边的字符串
        Dim n
        n = Left(remotefile.Text, InStr(remotefile.Text, "/") - 1)
        '发送改变当前目录命令
        r = process("CWD " & n)
        If Val(Left(r, 1)) >= 4 Then
                MsgBox "无法进入目录:" & r
                Exit Sub
        End If
        readdir
End Sub

'表示拖动在远程文件列表中放开，表示上传文件
Private Sub remotefile_DragDrop(Source As Control, X As Single, Y As Single)
        Dim filenames As New Collection
        Dim i
        '将本地文件列表框中选中的项一个个添加到filenames集合中
        For i = 0 To Source.ListCount - 1
                If Source.Selected(i) Then filenames.Add Source.List(i)
        Next
        '再调用上传函数
        upload filenames
        readdir
End Sub

Private Sub remotefile_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        '在远程文件列表中按下鼠标右键则开始拖动
        If Button And vbRightButton Then remotefile.Drag
End Sub

Private Sub sc_Connect()
        '当控制连接建立起来时，设置 连接已建立 变量为true
        connected = True
End Sub

'控制端收到数据
Private Sub sc_DataArrival(ByVal bytesTotal As Long)
        While sc.State <> sckConnected: DoEvents: Wend
        '获取收到的数据放入buf
        sc.GetData buf
        received = True
End Sub

'当控制端发生错误
Private Sub sc_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        MsgBox Description
        '发生错误时关闭控制端
        sc.Close
End Sub

'当控制端数据发送完毕
Private Sub sc_SendComplete()
        sent = True
End Sub

'当远程数据端已经关闭
Private Sub sd_Close()
        sd.Close
End Sub

'数据端收到连接请求
Private Sub sd_ConnectionRequest(ByVal requestID As Long)
        sd.Close
        sd.Accept requestID
End Sub

'数据端收到数据，将数据保存到recvbuf
Private Sub sd_DataArrival(ByVal bytesTotal As Long)
        Dim data As String
        While sd.State <> sckConnected: DoEvents: Wend
        sd.GetData data
        recvbuf = recvbuf & data
End Sub

'数据端发送错误，弹出一个消息框，并关闭数据连接
Private Sub sd_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        MsgBox Description
        sd.Close
End Sub

Private Sub sd_SendComplete()
        datasent = True
End Sub

Private Sub txtport_Validate(Cancel As Boolean)
    '端口不能为空，且必须是数值
    If txtport = "" Then
        MsgBox "请输入端口"
        Cancel = True
        ElseIf Not IsNumeric(txtport) Then
         MsgBox "请输入数值"
         Cancel = True
    End If

End Sub

Private Sub txtserver_Validate(Cancel As Boolean)
    '服务器地址不能为空
     If txtserver = "" Then
         MsgBox "请输入服务器地址"
        Cancel = True
    End If
End Sub

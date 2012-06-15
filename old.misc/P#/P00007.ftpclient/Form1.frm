VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form Form1
   Caption         =   "FTP服务器"
   ClientHeight    =   5550
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   6990
   ControlBox      =   0   'False
   LinkTopic       =   "Form1"
   ScaleHeight     =   5550
   ScaleWidth      =   6990
   StartUpPosition =   3  'Windows Default
   Begin VB.Timer Timer1
      Enabled         =   0   'False
      Interval        =   1
      Left            =   4080
      Top             =   4200
   End
   Begin MSComDlg.CommonDialog cd
      Left            =   4680
      Top             =   4200
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin MSWinsockLib.Winsock 控制连接
      Left            =   5400
      Top             =   4200
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      LocalPort       =   21
   End
   Begin MSWinsockLib.Winsock 数据连接
      Left            =   6000
      Top             =   4200
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
   Begin VB.ListBox 日志
      Height          =   1035
      ItemData        =   "Form1.frx":0000
      Left            =   240
      List            =   "Form1.frx":0002
      TabIndex        =   14
      Top             =   4080
      Width           =   6495
   End
   Begin VB.CommandButton 浏览映像目录
      Caption         =   "&B浏览"
      Height          =   375
      Left            =   6000
      TabIndex        =   13
      Top             =   3120
      Width           =   735
   End
   Begin VB.CommandButton 删除
      Caption         =   "&R删除"
      Height          =   375
      Left            =   2520
      TabIndex        =   12
      Top             =   840
      Width           =   855
   End
   Begin VB.CommandButton 添加
      Caption         =   "&A添加"
      Height          =   375
      Left            =   1440
      TabIndex        =   11
      Top             =   840
      Width           =   855
   End
   Begin VB.TextBox 映像目录
      Height          =   375
      Left            =   3120
      TabIndex        =   10
      Top             =   3600
      Width           =   3615
   End
   Begin VB.TextBox 虚拟目录名
      Height          =   375
      Left            =   3120
      TabIndex        =   9
      Top             =   2640
      Width           =   3615
   End
   Begin VB.TextBox 服务器中目录
      Height          =   375
      Left            =   3120
      TabIndex        =   6
      Top             =   1680
      Width           =   3615
   End
   Begin VB.ListBox 虚拟目录表
      Height          =   2400
      Left            =   240
      TabIndex        =   4
      Top             =   1320
      Width           =   2415
   End
   Begin VB.CommandButton Command1
      Caption         =   "浏览"
      Height          =   375
      Left            =   6000
      TabIndex        =   2
      Top             =   240
      Width           =   855
   End
   Begin VB.TextBox 主目录
      Height          =   375
      Left            =   1800
      TabIndex        =   1
      Text            =   "C:\"
      Top             =   240
      Width           =   4095
   End
   Begin VB.Shape 数据红绿灯
      FillColor       =   &H00FFFFFF&
      FillStyle       =   0  'Solid
      Height          =   255
      Left            =   270
      Shape           =   2  'Oval
      Top             =   435
      Width           =   255
   End
   Begin VB.Shape 控制红绿灯
      FillColor       =   &H00FFFFFF&
      FillStyle       =   0  'Solid
      Height          =   255
      Left            =   270
      Shape           =   2  'Oval
      Top             =   135
      Width           =   255
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "虚拟目录映像到服务器硬盘中的目录"
      Height          =   180
      Index           =   2
      Left            =   2880
      TabIndex        =   8
      Top             =   3240
      Width           =   2880
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "虚拟目录的名称"
      Height          =   180
      Index           =   1
      Left            =   2880
      TabIndex        =   7
      Top             =   2280
      Width           =   1260
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "虚拟目录位于FTP服务器主目录中的位置"
      Height          =   180
      Index           =   0
      Left            =   2880
      TabIndex        =   5
      Top             =   1320
      Width           =   3150
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "虚拟目录"
      Height          =   180
      Left            =   240
      TabIndex        =   3
      Top             =   960
      Width           =   720
   End
   Begin VB.Label FTP服务器
      AutoSize        =   -1  'True
      Caption         =   "FTP主目录(&R)"
      Height          =   180
      Left            =   720
      TabIndex        =   0
      Top             =   360
      Width           =   1080
   End
   Begin VB.Menu mFtpServer
      Caption         =   "&FTP服务器"
      Begin VB.Menu mStartFtp
         Caption         =   "&S启动"
      End
      Begin VB.Menu mStopFtp
         Caption         =   "&T停止"
         Enabled         =   0   'False
      End
   End
   Begin VB.Menu mUserConfig
      Caption         =   "&U用户配置"
   End
   Begin VB.Menu mHelp
      Caption         =   "&H帮助"
      Begin VB.Menu mHelpAbout
         Caption         =   "&A关于"
      End
   End
   Begin VB.Menu mExit
      Caption         =   "&X退出"
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        Dim s As New Shell32.Shell
        Dim f As Shell32.Folder
        Set f = s.BrowseForFolder(Me.hWnd, "请选择FTP主目录", 0)
        If Not f Is Nothing Then
                主目录 = f.ParseName("nul").Path
                主目录 = Left(主目录, Len(主目录) - 4)
        End If
End Sub

Private Sub Form_Load()
        读取设置
        正在接受连接 = False
        数据发送完毕 = True
End Sub

Private Sub mExit_Click()
        保存设置
        End
End Sub

Private Sub mHelpAbout_Click()
        MsgBox "FTP 服务器"
End Sub

Private Sub mStartFtp_Click()

        If Not 文件系统.FolderExists(主目录) Then
                MsgBox "主目录不存在!"
                主目录.SetFocus
                Exit Sub
        End If

        mStartFtp.Enabled = False
        mStopFtp.Enabled = True
        Timer1.Enabled = True
        加到日志 "服务器被启动"
End Sub

Private Sub mStopFtp_Click()
        mStartFtp.Enabled = True
        mStopFtp.Enabled = False
        Timer1.Enabled = False
        数据连接.Close
        控制连接.Close
        控制红绿灯.FillColor = 颜色_断开
        加到日志 "服务器被关闭"
End Sub

Private Sub mUserConfig_Click()
        用户配置.Show 1
End Sub

Public Sub 保存设置()
        SaveSetting 注册表_名称, "主要参数", "FTP主目录", 主目录.Text
        Dim i
        SaveSetting 注册表_名称, "主要参数", "虚拟目录个数", 虚拟目录表.ListCount
        For i = 0 To 虚拟目录表.ListCount - 1
                SaveSetting 注册表_名称, "主要参数", "虚拟目录#" & Trim(i), _
                         虚拟目录表.List(i)
        Next
End Sub

Public Sub 读取设置()
        主目录 = GetSetting(注册表_名称, "主要参数", "FTP主目录", "")
        Dim i, c
        c = GetSetting(注册表_名称, "主要参数", "虚拟目录个数", 0)
        For i = 0 To c - 1
                Dim s, x As 虚拟目录
                s = GetSetting(注册表_名称, "主要参数", "虚拟目录#" & Trim(i), "")
                虚拟目录表.AddItem s
        Next
End Sub

Private Sub Timer1_Timer()
        On Error Resume Next

        Select Case 控制连接.State
        Case sckError
                控制红绿灯.FillColor = 颜色_错误
                控制连接.Close
        Case sckClosed
                If Not 正在接受连接 Then 控制连接.Listen
                控制红绿灯.FillColor = 颜色_空闲
        Case sckConnected
                控制红绿灯.FillColor = 颜色_忙碌
        End Select

        Select Case 数据连接.State
        Case sckError
                数据红绿灯.FillColor = 颜色_错误
                数据连接.Close
        Case sckConnected
                数据红绿灯.FillColor = 颜色_忙碌
        Case sckClosed
                数据红绿灯.FillColor = 颜色_断开
                数据连接.LocalPort = 0
        End Select
End Sub

Private Sub 控制连接_Close()
        控制连接.Close
End Sub

Private Sub 控制连接_Connect()
        加到日志 "建立连接"
End Sub

Private Sub 控制连接_ConnectionRequest(ByVal requestID As Long)
        正在接受连接 = True
        控制连接.Close
        控制连接.Accept requestID
        正在接受连接 = False
        控制发送 "220 " & "欢迎访问马三林的 FTP 服务器 !!!"
        加到日志 "接受连接"
        当前用户.用户名 = ""
        当前目录 = ""
        用户已登陆 = False
End Sub

Private Sub 控制连接_DataArrival(ByVal bytesTotal As Long)
        While Not 控制连接.State = sckConnected: DoEvents: Wend

        Dim buf As String
        Dim ps, a, fn
        控制红绿灯.FillColor = 颜色_忙碌
        控制连接.GetData buf
        buf = Trim(buf)
        While (Asc(Right(buf, 1)) = 13 Or Asc(Right(buf, 1)) = 10) And Len(buf) > 0
                buf = Left(buf, Len(buf) - 1)
        Wend

        加到日志 buf

        ps = Split(Trim(buf), " ", 2, vbTextCompare)
        If UBound(ps) < 0 Then Exit Sub
        Select Case UCase(ps(0))
        Case "USER"
                If Not 用户配置.用户存在(ps(1)) Then
                        控制发送 "400 用户不存在"
                Else
                        当前用户 = 获取用户配置(ps(1))
                        If 当前用户.允许Email密码 Then
                                控制发送 "331 用户存在,请输入您的Email地址作为密码."
                        Else
                                控制发送 "331 用户存在,请输入密码:"
                        End If
                End If
        Case "PASS"
                If 当前用户.用户名 = "" Then
                        控制发送 "503 请先输入用户名!"
                Else
                        If 当前用户.允许Email密码 Then
                                If Not (InStr(ps(1), "@") > 0) Then
                                        控制发送 "400 Email格式不正确,请重试"
                                Else
                                        用户已登陆 = True
                                        控制发送 "230 Email已经被验证"
                                        当前目录 = "/"
                                        Set 当前目录对象 = 文件系统.GetFolder(主目录.Text)
                                End If
                        Else
                                If ps(1) <> 当前用户.密码 Then
                                        控制发送 "530 密码错误"
                                Else
                                        用户已登陆 = True
                                        控制发送 "230 密码正确"
                                        当前目录 = "/"
                                        Set 当前目录对象 = 文件系统.GetFolder(主目录.Text)
                                End If
                        End If
                End If
        Case "PWD"
                If Not 用户已登陆 Then 控制发送 "530 请先登陆": Exit Sub

                控制发送 "257 """ & 当前目录 & """ 是当前目录"
        Case "CWD"
                If Not 用户已登陆 Then 控制发送 "530 请先登陆": Exit Sub

                If Left(ps(1), 1) <> "/" Then
                ' 相对路径
                        If Not 文件系统.FolderExists(目录连接(当前目录对象.Path, ps(1))) Then
                                控制发送 "550 目录不存在"
                        Else
                                Set 当前目录对象 = 当前目录对象.SubFolders(ps(1))
                                当前目录 = 当前目录 & ps(1) & "/"
                                控制发送 "250 CWD命令正确,当前目录为:" & 当前目录
                        End If
                Else
                ' 绝对路径
                        Dim ppp
                        ppp = 主目录 & Replace(ps(1), "/", "\")
                        If 文件系统.FolderExists(ppp) Then
                                当前目录 = ps(1)
                                If Right(当前目录, 1) <> "/" Then 当前目录 = 当前目录 & "/"
                                Set 当前目录对象 = 文件系统.GetFolder(ppp)
                                控制发送 "250 CWD命令正确,当前目录为:" & 当前目录
                        Else
                                控制发送 "550 目录不存在"
                        End If
                End If
        Case "CDUP"
                If Not 用户已登陆 Then 控制发送 "530 请先登陆": Exit Sub

                a = Split(当前目录, "/")
                If UBound(a) > 1 Then
                        Dim i
                        当前目录 = ""
                        For i = LBound(a) To UBound(a) - 2
                                当前目录 = 当前目录 & a(i) & "/"
                        Next
                        Set 当前目录对象 = 当前目录对象.ParentFolder
                End If
                控制发送 "250 CDUP命令正确,当前目录为:" & 当前目录
        Case "LIST"
                If Not 用户已登陆 Then 控制发送 "530 请先登陆": Exit Sub
                控制发送 "150 LIST命令正确"

                数据发送 获取当前目录内容
                控制发送 "226 数据传输完毕!"
        Case "RETR"
                If Not 用户已登陆 Then 控制发送 "400 请先登陆": Exit Sub
                If Not 当前用户.读权限 Then
                        控制发送 "500 用户没有权限执行本命令"
                        Exit Sub
                End If
                If 文件系统.FileExists(目录连接(当前目录对象.Path, ps(1))) Then
                        控制发送 "150 RETR命令正确,准备发送数据"

                        fn = FreeFile
                        Open 目录连接(当前目录对象.Path, ps(1)) For Binary As #fn
                        ReDim 文件数据(1 To LOF(fn)) As Byte
                        Get #fn, , 文件数据
                        Close #fn

                        数据发送 文件数据
                        控制发送 "226 数据传输完毕"
                Else
                        控制发送 "550 文件不存在"
                End If
        Case "STOR"
                If Not 用户已登陆 Then 控制发送 "530 请先登陆": Exit Sub
                If Not 当前用户.写权限 Then
                        控制发送 "500 用户没有权限执行本命令"
                        Exit Sub
                End If
                On Error GoTo x1
                fn = FreeFile
                Open 目录连接(当前目录对象.Path, ps(1)) For Binary As fn
                控制发送 "150 STOR命令正确,准备接受数据"
                数据连接.Connect
                While 数据连接.State <> sckClosed: DoEvents: Wend
                控制发送 "226 数据传输完毕"
                Put fn, , 接收数据
                Close fn
                Exit Sub
x1:
                Close fn
                控制发送 "500 无法保存文件"
                Exit Sub
        Case "MKD"
                If Not 用户已登陆 Then 控制发送 "530 请先登陆": Exit Sub
                If Not 当前用户.目录操作权限 Then
                        控制发送 "500 用户没有权限执行本命令"
                        Exit Sub
                End If
                If 文件系统.FolderExists(目录连接(当前目录对象.Path, ps(1))) Then
                        控制发送 "550 无法建立目录,目录已存在"
                        Exit Sub
                End If

                If 当前目录对象.SubFolders.Add(ps(1)) Is Nothing Then
                        控制发送 "550 无法建立目录"
                Else
                        控制发送 "257 MKD命令正确"
                End If
        Case "RMD"
                If Not 用户已登陆 Then 控制发送 "530 请先登陆": Exit Sub
                If Not 当前用户.目录操作权限 Then
                        控制发送 "500 用户没有权限执行本命令"
                        Exit Sub
                End If
                If Not 文件系统.FolderExists(目录连接(当前目录对象.Path, ps(1))) Then
                        控制发送 "550 无法删除目录,目录不存在"
                        Exit Sub
                End If
                当前目录对象.SubFolders(ps(1)).Delete
                If 文件系统.FolderExists(目录连接(当前目录对象.Path, ps(1))) Then
                        控制发送 "550 无法删除目录"
                Else
                        控制发送 "250 RMD命令正确"
                End If
        Case "DELE"
                If Not 用户已登陆 Then 控制发送 "530 请先登陆": Exit Sub
                If Not 当前用户.目录操作权限 Then
                        控制发送 "500 用户没有权限执行本命令"
                        Exit Sub
                End If
                If Not 文件系统.FileExists(目录连接(当前目录对象.Path, ps(1))) Then
                        控制发送 "550 无法删除文件,文件不存在"
                        Exit Sub
                End If
                当前目录对象.Files(ps(1)).Delete True
                If 文件系统.FileExists(目录连接(当前目录对象.Path, ps(1))) Then
                        控制发送 "550 无法删除目录"
                Else
                        控制发送 "250 DELE命令正确"
                End If
        Case "HELP"
                控制发送 "214 - USER PASS HELP QUIT PORT STOR RETR"
        Case "PORT"
                If Not 用户已登陆 Then 控制发送 "530 请先登陆": Exit Sub
                Dim ps2
                ps2 = Split(ps(1), ",", , vbTextCompare)
                If UBound(ps2) < 5 Then
                        控制发送 "500 格式错误"
                Else
                        远程地址 = Trim(ps2(0)) & "." & _
                                        Trim(ps2(1)) & "." & _
                                        Trim(ps2(2)) & "." & _
                                        Trim(ps2(3))
                        远程端口 = Val(ps2(4)) * 256 + Val(ps2(5))
                        数据连接.RemoteHost = 远程地址
                        数据连接.RemotePort = 远程端口
                        控制发送 "200 PORT命令执行完毕(" & 远程地址 & ":" & 远程端口 & ")"
                End If
        Case "REIN"
                控制发送 "220 REIN命令正确，服务重新开始"

                当前目录 = "/"
                Set 当前目录对象 = 文件系统.GetFolder(主目录.Text)

        Case "QUIT"
                加到日志 "退出连接"
                控制发送 "210 谢谢您的使用,再见!", , True
                控制连接.Close
        Case Else
                控制发送 "200 "
        End Select
End Sub

Private Sub 控制连接_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        加到日志 Number & ":" & Description
        控制连接.Close
End Sub

Private Sub 控制连接_SendComplete()
        发送完毕 = True
End Sub

Private Sub 浏览映像目录_Click()
        Dim s As New Shell
        Dim f As Folder
        Set f = s.BrowseForFolder(Me.hWnd, "请打开要映像至虚拟目录的目录", 0)
        If Not f Is Nothing Then
                映像目录 = f.ParentFolder.ParseName(f).Path
        End If
End Sub

Private Sub 删除_Click()
        Dim li
        li = 虚拟目录表.ListIndex
        On Error Resume Next
        虚拟目录表.RemoveItem 虚拟目录表.ListIndex
        虚拟目录表.ListIndex = li
End Sub

Private Sub 数据连接_Close()
        数据连接.Close
End Sub

Private Sub 数据连接_Connect()
        If 等待发送数据 <> "" Then
                数据连接.SendData 等待发送数据
        End If
End Sub

Private Sub 数据连接_DataArrival(ByVal bytesTotal As Long)
        While Not 数据连接.State = sckConnected: DoEvents: Wend
        Dim buf As String
        数据连接.GetData buf
        接收数据 = 接收数据 & buf
End Sub

Private Sub 数据连接_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        加到日志 "数据错误:" & Number & ":" & Description
        数据连接.Close
End Sub

Private Sub 数据连接_SendComplete()
        数据发送完毕 = True
End Sub

Private Sub 添加_Click()
        Dim x As 虚拟目录
        x.服务器主目录中位置 = 服务器中目录
        x.名称 = 虚拟目录名
        x.映像目录 = 映像目录
        虚拟目录表.AddItem 编码虚拟目录(x)
End Sub

Private Sub 虚拟目录表_Click()
        Dim x As 虚拟目录
        x = 解码虚拟目录(虚拟目录表.List(虚拟目录表.ListIndex))
        服务器中目录 = x.服务器主目录中位置
        虚拟目录名 = x.名称
        映像目录 = x.映像目录
End Sub

Public Sub 加到日志(s)
        日志.AddItem "[" & Date & " " & Time & "] " & s & _
                        " (远程主机 " & 控制连接.RemoteHostIP & ":" & 控制连接.RemotePort & ")"
End Sub

Public Sub 控制发送(s, Optional 换行 As Boolean = True, Optional 等待 As Boolean = False)
        If 等待 Then 发送完毕 = False
        控制连接.SendData s & IIf(换行, vbNewLine, "")
        If 等待 Then
                While Not 发送完毕
                        DoEvents
                Wend
        End If
End Sub

Public Sub 数据发送(要发送的数据)
        数据发送完毕 = False

        数据连接.Connect

        等待发送数据 = 要发送的数据
        While Not 数据发送完毕
                DoEvents
        Wend
        等待发送数据 = ""

        数据连接.Close
End Sub

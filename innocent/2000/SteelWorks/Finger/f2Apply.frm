VERSION 5.00
Begin VB.Form frmApply
   BorderStyle     =   1  'Fixed Single
   Caption         =   "申请加入测试"
   ClientHeight    =   2730
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5565
   Icon            =   "f2Apply.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   182
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   371
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox txtID
      Height          =   270
      Left            =   1620
      TabIndex        =   10
      Top             =   1020
      Visible         =   0   'False
      Width           =   3555
   End
   Begin VB.TextBox txtComment
      Height          =   315
      Left            =   1620
      TabIndex        =   9
      Top             =   660
      Width           =   3555
   End
   Begin VB.CommandButton cmdCancel
      Caption         =   "取消"
      Height          =   375
      Left            =   4140
      TabIndex        =   7
      Top             =   2040
      Width           =   1095
   End
   Begin VB.CommandButton cmdEnterWaitingRoom
      Caption         =   "进入候听室"
      Height          =   375
      Left            =   1920
      TabIndex        =   6
      Top             =   2040
      Width           =   1515
   End
   Begin VB.CommandButton cmdWaitingStart
      Caption         =   "直接等待开始"
      Height          =   375
      Left            =   300
      TabIndex        =   5
      Top             =   2040
      Width           =   1515
   End
   Begin VB.CommandButton cmdBrowse
      Caption         =   "浏览"
      Height          =   315
      Left            =   4560
      TabIndex        =   4
      Top             =   1500
      Width           =   675
   End
   Begin VB.TextBox txtAlias
      Height          =   315
      Left            =   1620
      MaxLength       =   8
      TabIndex        =   3
      Top             =   180
      Width           =   3555
   End
   Begin VB.TextBox txtChannel
      Height          =   315
      Left            =   1620
      TabIndex        =   1
      Top             =   1500
      Width           =   2835
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "代号"
      Height          =   180
      Left            =   660
      TabIndex        =   11
      Top             =   1080
      Visible         =   0   'False
      Width           =   360
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "附言"
      Height          =   180
      Left            =   660
      TabIndex        =   8
      Top             =   780
      Width           =   360
   End
   Begin VB.Line Line1
      X1              =   8
      X2              =   344
      Y1              =   85
      Y2              =   85
   End
   Begin VB.Label qqqComments
      AutoSize        =   -1  'True
      Caption         =   "你的名字"
      Height          =   180
      Index           =   1
      Left            =   300
      TabIndex        =   2
      Top             =   240
      Width           =   720
   End
   Begin VB.Label qqqComments
      AutoSize        =   -1  'True
      Caption         =   "选择测试频道"
      Height          =   180
      Index           =   0
      Left            =   300
      TabIndex        =   0
      Top             =   1560
      Width           =   1080
   End
End
Attribute VB_Name = "frmApply"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private applied As Boolean

Public Sub addme(ByVal host As String)
        Dim r As String
        Dim serverInfo As String
        frmWaitingBox.TurnOn "正在申请加入, 请稍候..."
                r = FN_TextIO(host, "FING #JOIN APPLY" & lt_s.encodePart(cAddr(fingerClient.Alias, fingerClient.HostName)))
                If lt_s.decodePart(r, 1) = "OK" Then
                        MsgBox "您已被成功加入!"
                        fingerServer = decodeFingerServer(lt_s.decodePart(r, 2))
                        applied = True

                        serverInfo = FN_TextIO(fingerServer.HostName, "FING #GET SERVER INFO")
                        If lt_s.decodePart(serverInfo, 1) = "OK" Then
                                fingerServer = decodeFingerServer(lt_s.decodePart(serverInfo, 2))
                        End If
                Else
                        If lt_s.decodePart(r, 2) = "JOINER EXISTED" Then
                                MsgBox "您已经被加入. "
                                applied = True
                        Else
                                MsgBox "无法加入指定频道!"
                                fingerServer = decodeFingerServer("")
                                applied = False
                        End If
                End If
        frmWaitingBox.TurnOff
End Sub

Private Sub cmdBrowse_Click()
        Dim HostName As String
        txtChannel = frmSelectComputer.Run(False, False, pFunc(AddressOf Finger_EnumManagerProc))
        If txtChannel <> "" Then
                HostName = cAddrHost(storeCAddr(txtChannel))
                If HostName = "" Then
                        MsgBox "频道无效!"
                Else
                        addme HostName
                End If
        End If
End Sub

Public Sub cmdCancel_Click()
        FN_TextIO fingerServer.HostName, "FING #CANCEL APPLY" & lt_s.encodePart(cAddr(fingerClient.Alias, fingerClient.HostName))
        paperDowned = 1
        Me.Hide
End Sub

Private Sub cmdEnterWaitingRoom_Click()
        Me.Hide
        With frmHoll
                .lblChannel = fingerServer.Channel
                .lblPos = "位于:" & fingerServer.HostName & "@" & fingerServer.HostIP
                .lblMonitor = "监考者：" & fingerServer.Monitor
                .lblGroup = "小组名称：" & fingerServer.Group
                .lblTime = "测试时间：" & fingerServer.TestTime

                .txtAlias = fingerClient.Alias
                .Show
        End With
End Sub

Private Sub cmdWaitingStart_Click()
        If applied Then
                '
        Else
                MsgBox "您尚未加入, 请先加入"
        End If
End Sub

Private Sub Form_Load()
        applied = False

        With fingerClient
                .Alias = ""
                .Comment = ""
                .HostName = SockServer.LocalHostName
                .HostIP = SockServer.LocalIP
                .Status = "空闲状态"
        End With

        txtAlias = GetSetting(FingerRoot, "申请者", "别名")
        txtComment = GetSetting(FingerRoot, "申请者", "附言")
        txtID = GetSetting(FingerRoot, "申请者", "代号")

End Sub

Private Sub Form_Unload(Cancel As Integer)
        SaveSetting FingerRoot, "申请者", "别名", txtAlias
        SaveSetting FingerRoot, "申请者", "附言", txtComment
        SaveSetting FingerRoot, "申请者", "代号", txtID
End Sub

Private Sub txtAlias_Change()
        fingerClient.Alias = txtAlias
End Sub

Private Sub txtComment_Change()
        fingerClient.Comment = txtComment
End Sub

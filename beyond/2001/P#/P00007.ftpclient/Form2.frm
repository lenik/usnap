VERSION 5.00
Begin VB.Form 用户配置
   Caption         =   "用户配置"
   ClientHeight    =   4185
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6135
   ControlBox      =   0   'False
   LinkTopic       =   "Form2"
   ScaleHeight     =   4185
   ScaleWidth      =   6135
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2
      Caption         =   "&R删除"
      Height          =   375
      Left            =   1560
      TabIndex        =   12
      Top             =   3720
      Width           =   1335
   End
   Begin VB.CommandButton Command1
      Caption         =   "&A加入"
      Height          =   375
      Left            =   120
      TabIndex        =   11
      Top             =   3720
      Width           =   1215
   End
   Begin VB.CommandButton 返回
      Caption         =   "&X返回"
      Height          =   375
      Left            =   4800
      TabIndex        =   10
      Top             =   3720
      Width           =   975
   End
   Begin VB.CheckBox 目录操作权限
      Caption         =   "允许该用户目录操作权限"
      Height          =   255
      Left            =   2760
      TabIndex        =   9
      Top             =   3240
      Width           =   3015
   End
   Begin VB.CheckBox 读权限
      Caption         =   "允许该用户读权限"
      Height          =   255
      Left            =   2760
      TabIndex        =   8
      Top             =   2520
      Width           =   2175
   End
   Begin VB.CheckBox 写权限
      Caption         =   "允许该用户写权限"
      Height          =   255
      Left            =   2760
      TabIndex        =   7
      Top             =   2880
      Width           =   2175
   End
   Begin VB.CheckBox 使用email密码
      Caption         =   "使用Email地址作为密码"
      Height          =   255
      Left            =   3000
      TabIndex        =   6
      Top             =   1560
      Width           =   2535
   End
   Begin VB.TextBox 密码
      Height          =   375
      IMEMode         =   3  'DISABLE
      Left            =   3000
      PasswordChar    =   "*"
      TabIndex        =   5
      Top             =   1920
      Width           =   2775
   End
   Begin VB.TextBox 用户名
      Height          =   375
      Left            =   3000
      TabIndex        =   3
      Top             =   600
      Width           =   2775
   End
   Begin VB.ListBox 用户列表
      Height          =   2760
      Left            =   120
      TabIndex        =   1
      Top             =   600
      Width           =   2175
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "密码"
      Height          =   180
      Left            =   2640
      TabIndex        =   4
      Top             =   1200
      Width           =   360
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "用户名"
      Height          =   180
      Left            =   2640
      TabIndex        =   2
      Top             =   240
      Width           =   540
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "用户列表"
      Height          =   180
      Left            =   720
      TabIndex        =   0
      Top             =   240
      Width           =   720
   End
End
Attribute VB_Name = "用户配置"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Command1_Click()
        Dim u As 用户
        u.用户名 = 用户名
        u.密码 = 密码
        u.允许Email密码 = 使用email密码.Value <> 0
        u.读权限 = 读权限.Value <> 0
        u.写权限 = 写权限.Value <> 0
        u.目录操作权限 = 目录操作权限 <> 0
        用户列表.AddItem 编码用户(u)
End Sub

Private Sub Command2_Click()
        Dim li
        li = 用户列表.ListIndex
        On Error Resume Next
        用户列表.RemoveItem li
        用户列表.ListIndex = li
End Sub

Private Sub Form_Load()
        读取设置
End Sub

Private Sub 返回_Click()
        保存设置
        Me.Hide
End Sub

Public Sub 保存设置()
        Dim i
        SaveSetting 注册表_名称, "用户配置", "用户数目", 用户列表.ListCount
        For i = 0 To 用户列表.ListCount - 1
                SaveSetting 注册表_名称, "用户配置", "用户#" & Trim(i), _
                        用户列表.List(i)
        Next
End Sub

Public Sub 读取设置()
        Dim c, i
        c = GetSetting(注册表_名称, "用户配置", "用户数目", 0)
        For i = 0 To c - 1
                用户列表.AddItem GetSetting(注册表_名称, "用户配置", "用户#" & Trim(i), "")
        Next
End Sub

Private Sub 用户列表_Click()
        Dim u As 用户
        u = 解码用户(用户列表.List(用户列表.ListIndex))
        用户名 = u.用户名
        密码 = u.密码
        使用email密码.Value = IIf(u.允许Email密码, 1, 0)
        读权限.Value = IIf(u.读权限, 1, 0)
        写权限.Value = IIf(u.写权限, 1, 0)
        目录操作权限.Value = IIf(u.目录操作权限, 1, 0)
End Sub

Public Function 用户存在(x) As Boolean
        Dim i
        For i = 0 To 用户列表.ListCount - 1
                Dim u As 用户
                u = 解码用户(用户列表.List(i))
                If x = u.用户名 Then
                        用户存在 = True
                        Exit Function
                End If
        Next
        用户存在 = False
End Function

Public Function 密码正确(x, p) As Boolean
        Dim i
        For i = 0 To 用户列表.ListCount - 1
                Dim u As 用户
                u = 解码用户(用户列表.List(i))
                If x = u.用户名 Then
                        If p = u.密码 Then
                                密码正确 = True
                                Exit Function
                        End If
                Else
                        密码正确 = False
                        Exit Function
                End If
        Next
        密码正确 = False
End Function

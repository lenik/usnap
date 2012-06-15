VERSION 5.00
Begin VB.Form Form1
   Caption         =   "进程分析工具"
   ClientHeight    =   4290
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6180
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   ScaleHeight     =   4290
   ScaleWidth      =   6180
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdRefresh
      Caption         =   "刷新"
      Height          =   375
      Left            =   4800
      TabIndex        =   2
      Top             =   120
      Width           =   975
   End
   Begin VB.ListBox lstProcesses
      Height          =   2985
      Left            =   240
      TabIndex        =   1
      Top             =   600
      Width           =   5535
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "双击以分析选定进程"
      Height          =   180
      Left            =   1920
      TabIndex        =   3
      Top             =   3960
      Width           =   1620
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "&L 进程列表"
      Height          =   180
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   900
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdRefresh_Click()
        ' 获取系统中正在运行的所有进程并保存到Processes数组中。
        GetProcesses

        Dim i
        ' 在将进程数组表示到进程列表框之前，先清空列表框
        lstProcesses.Clear
        For i = 1 To nProcesses
                ' 每一项用如下格式表示：
                '     进程ID的16进制 : 进程对应的路径文件名
                lstProcesses.AddItem Hex(Processes(i).th32ProcessID) & ":" & Processes(i).szExeFile
        Next
End Sub

Private Sub Form_Load()
        ' 程序开始时列出正在运行的所有进程
        cmdRefresh_Click
End Sub

Private Sub Form_Unload(Cancel As Integer)
        ' 当主窗体关闭时，结束整个程序。
        ' 通过结束整个程序来关闭所有其他窗体。
        End
End Sub

Private Sub lstProcesses_DblClick()
        Dim x, pid
        ' 在进程列表框中双击，首先要得到双击所在项的进程PID
        ' 通过将所在项用":"分割，并取分割后的第一项 (0) 来实现
        x = Split(lstProcesses.Text, ":")(0)
        ' 将进程PID字符串转换成数值。用"&H" 表示 x 是用16进制表示的。
        pid = val("&H" & x)
        ' 建立一个frmviewp类型的窗体
        Dim v As New frmviewp
        ' 调用该窗体的init方法初始化窗体的各字段
        v.init pid
        ' 显示窗体
        v.Show
End Sub

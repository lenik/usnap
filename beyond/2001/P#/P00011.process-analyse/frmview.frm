VERSION 5.00
Begin VB.Form frmviewp
   Caption         =   "进程分析"
   ClientHeight    =   3810
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5610
   LinkTopic       =   "Form2"
   ScaleHeight     =   3810
   ScaleWidth      =   5610
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command6
      Caption         =   "返回"
      Height          =   495
      Left            =   3480
      TabIndex        =   21
      Top             =   3120
      Width           =   1815
   End
   Begin VB.CommandButton Command5
      Caption         =   "进程内存分析"
      Height          =   495
      Left            =   240
      TabIndex        =   20
      Top             =   3120
      Width           =   2055
   End
   Begin VB.CommandButton Command4
      Caption         =   "分析父进程"
      Height          =   375
      Left            =   4080
      TabIndex        =   19
      Top             =   1920
      Width           =   1215
   End
   Begin VB.CommandButton Command3
      Caption         =   "分析所有线程"
      Height          =   375
      Left            =   4080
      TabIndex        =   18
      Top             =   1560
      Width           =   1215
   End
   Begin VB.CommandButton Command2
      Caption         =   "对该模块分析"
      Height          =   375
      Left            =   4080
      TabIndex        =   17
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton Command1
      Caption         =   "对该堆分析"
      Height          =   375
      Left            =   4080
      TabIndex        =   16
      Top             =   840
      Width           =   1215
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   7
      Left            =   1440
      TabIndex        =   15
      Top             =   2760
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   6
      Left            =   1440
      TabIndex        =   14
      Top             =   2400
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   5
      Left            =   1440
      TabIndex        =   13
      Top             =   2040
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   4
      Left            =   1440
      TabIndex        =   12
      Top             =   1680
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   3
      Left            =   1440
      TabIndex        =   11
      Top             =   1320
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   2
      Left            =   1440
      TabIndex        =   10
      Top             =   960
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   1
      Left            =   1440
      TabIndex        =   9
      Top             =   600
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   0
      Left            =   1440
      TabIndex        =   8
      Top             =   240
      Width           =   90
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "标志:"
      Height          =   180
      Index           =   7
      Left            =   240
      TabIndex        =   7
      Top             =   2760
      Width           =   450
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "进程优先权:"
      Height          =   180
      Index           =   6
      Left            =   240
      TabIndex        =   6
      Top             =   2400
      Width           =   990
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "父进程ID:"
      Height          =   180
      Index           =   5
      Left            =   240
      TabIndex        =   5
      Top             =   2040
      Width           =   810
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "包含线程数:"
      Height          =   180
      Index           =   4
      Left            =   240
      TabIndex        =   4
      Top             =   1680
      Width           =   990
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "模块ID:"
      Height          =   180
      Index           =   3
      Left            =   240
      TabIndex        =   3
      Top             =   1320
      Width           =   630
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "默认堆ID:"
      Height          =   180
      Index           =   2
      Left            =   240
      TabIndex        =   2
      Top             =   960
      Width           =   810
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "名称:"
      Height          =   180
      Index           =   1
      Left            =   240
      TabIndex        =   1
      Top             =   600
      Width           =   450
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "进程ID:"
      Height          =   180
      Index           =   0
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   630
   End
End
Attribute VB_Name = "frmviewp"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

Private Sub Command1_Click()
        Dim he As HEAPENTRY32
        he.dwSize = Len(he)
        ' 获取默认堆的信息，并保存到he中
        Heap32First he, val("&H" & PI(0)), val("&H" & PI(2))
        ' 建立一个类型为frmviewh的窗体
        Dim v As New frmviewh
        ' 将堆的信息填入新建的窗体
        v.PI(0) = Hex(he.th32HeapID)
        v.PI(1) = Hex(he.th32ProcessID)
        v.PI(2) = Hex(he.dwAddress)
        v.PI(3) = Hex(he.dwBlockSize)
        v.PI(4) = he.dwLockCount
        v.PI(5) = Hex(he.hHandle)
        v.PI(6) = Hex(he.dwFlags)
        ' 显示窗体
        v.Show
End Sub

Private Sub Command2_Click()
        Dim mid
        Dim m As MODULEENTRY32
        Dim h As Long, b As Boolean

        ' mid为模块ID
        mid = val("&H" & PI(3))

        ' 建立一个快照
        h = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0)
        m.dwSize = Len(m)
        ' 从快照中找出模块ID等于mid的模块的信息
        b = Module32First(h, m)
        Do While m.th32ModuleID <> mid And b
                b = Module32Next(h, m)
        Loop

        ' 如果找到了该模块
        If m.th32ModuleID = mid Then
                ' 则建立一个类型为frmviewm的窗体
                Dim v As New frmviewm
                ' 并将模块的信息填入该窗体
                v.PI(0) = Hex(m.th32ModuleID)
                v.PI(1) = m.szModule
                v.PI(2) = Hex(m.th32ProcessID)
                v.PI(3) = "总共" & m.GlblcntUsage & ",其中本进程使用" & m.ProccntUsage
                v.PI(4) = Hex(m.modBaseAddr)
                v.PI(5) = Hex(m.modBaseSize)
                v.PI(6) = Hex(m.hModule)
                ' 显示窗体
                v.Show
        End If
        ' 关闭快照
        CloseHandle h
End Sub

Private Sub Command3_Click()
        Dim pid
        Dim t As THREADENTRY32
        Dim h As Long, b As Boolean
        Dim v As New frmviewths

        pid = val("&H" & PI(0))
        ' 建立一个快照
        h = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0)
        t.dwSize = Len(t)

        ' 将快照中所有属于进程pid的线程添加到新建窗体的列表框中
        ' 获取快照中第一个线程
        b = Thread32First(h, t)
        Do While b
                ' 如果线程的所属进程等于pid
                If t.th32OwnerProcessID = pid Then
                        v.lstThreads.AddItem Hex(t.th32ThreadID)
                End If
                ' 获取快照中下一个线程
                b = Thread32Next(h, t)
        Loop
        ' 关闭快照
        CloseHandle h
        ' 设置线程列表窗体的pid字段
        v.PI(0) = Hex(pid)
        ' 显示窗体
        v.Show
End Sub

Private Sub Command4_Click()
        Dim pid
        pid = val("&H" & PI(5))
        ' 如果父进程存在
        If pid <> 0 Then
                ' 则建立一个类型为frmviewp的窗体
                Dim v As New frmviewp
                ' 并用父进程ID初始化
                v.init pid
                ' 显示窗体
                v.Show
        End If
End Sub

Private Sub Command5_Click()
        ' 建立一个类型为memory的窗体
        Dim v As New memory
        ' 设置窗体中的PID字段
        v.txtPID = PI(0)
        ' 显示窗体
        v.Show
End Sub

Private Sub Command6_Click()
        ' 关闭本窗体
        Hide
End Sub

Public Sub init(pid)
        Dim pe As PROCESSENTRY32
        ' 使用进程ID为PID的进程信息初始化
        pe = GetProcess(pid)
        With pe
                ' 进程信息填入各个字段
                PI(0) = Hex(.th32ProcessID)
                PI(1) = .szExeFile
                PI(2) = Hex(.th32DefaultHeapID)
                PI(3) = Hex(.th32ModuleID)
                PI(4) = .cntThreads
                PI(5) = Hex(.th32ParentProcessID)
                PI(6) = .pcPriClassBase
                PI(7) = Hex(.dwFlags)
        End With
End Sub

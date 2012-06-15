VERSION 5.00
Begin VB.Form frmviewths
   Caption         =   "进程包含的线程列表"
   ClientHeight    =   3990
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3960
   LinkTopic       =   "Form2"
   ScaleHeight     =   3990
   ScaleWidth      =   3960
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox lstThreads
      Height          =   2595
      Left            =   360
      TabIndex        =   3
      Top             =   960
      Width           =   3135
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "进程ID:"
      Height          =   180
      Index           =   0
      Left            =   360
      TabIndex        =   2
      Top             =   240
      Width           =   630
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "线程列表:"
      Height          =   180
      Index           =   1
      Left            =   360
      TabIndex        =   1
      Top             =   600
      Width           =   810
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   0
      Left            =   1560
      TabIndex        =   0
      Top             =   240
      Width           =   90
   End
End
Attribute VB_Name = "frmviewths"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

' 在列表框上双击以分析线程ID为tid的线程
Private Sub lstThreads_DblClick()
        Dim pid, tid
        Dim t As THREADENTRY32
        Dim h As Long, b As Boolean
        Dim v As New frmviewt

        pid = val("&H" & PI(0))
        ' tid就等于列表框中双击所在项的内容，将它转换成数值
        tid = val("&H" & lstThreads.Text)

        ' 建立一个快照
        h = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0)
        t.dwSize = Len(t)

        ' 找出快照中进程ID为pid，线程ID为tid的那个线程
        ' 获取快照中第一个线程，保存至t
        b = Thread32First(h, t)
        Do While b
                If t.th32OwnerProcessID = pid And t.th32ThreadID = tid Then
                        ' 找到了就退出循环
                        Exit Do
                End If
                ' 获取快照中下一个线程
                b = Thread32Next(h, t)
        Loop
        ' 关闭快照
        CloseHandle h

        ' 将找到的线程信息填入新建的窗体中
        v.PI(0) = Hex(t.th32ThreadID)
        v.PI(1) = Hex(t.th32OwnerProcessID)
        v.PI(2) = t.cntUsage
        v.PI(3) = t.tpBasePri
        v.PI(4) = t.tpDeltaPri
        v.PI(5) = Hex(t.dwFlags)

        ' 显示窗体
        v.Show

End Sub

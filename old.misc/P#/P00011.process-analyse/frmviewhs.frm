VERSION 5.00
Begin VB.Form frmviewhs
   Caption         =   "进程中的所有堆列表"
   ClientHeight    =   3615
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4815
   LinkTopic       =   "Form2"
   ScaleHeight     =   3615
   ScaleWidth      =   4815
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox lstHeaps
      Height          =   2205
      Left            =   240
      TabIndex        =   3
      Top             =   1080
      Width           =   4215
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "堆列表:"
      Height          =   180
      Index           =   1
      Left            =   240
      TabIndex        =   2
      Top             =   600
      Width           =   630
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   0
      Left            =   1440
      TabIndex        =   1
      Top             =   240
      Width           =   90
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
Attribute VB_Name = "frmviewhs"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

' 在堆列表中双击将显示指定堆的信息
Private Sub lstHeaps_DblClick()
        Dim pid, hid, start, ll
        Dim he As HEAPENTRY32
        Dim b As Boolean
        ' 建立一个类型为frmviewh的窗体
        Dim v As New frmviewh

        ' 列表中所有堆所在的进程ID
        pid = val("&H" & PI(0))

        ' 将双击所在项保存到ll
        ll = lstHeaps.Text
        ' 每一项都有如下格式：
        '       堆ID的16进制 ":起始" 堆地址的16进制 "," 堆长度的16进制
        ' 因此 堆ID等于ll用":"分割的第一项
        hid = val("&H" & Split(ll, ":")(0))

        ' 起始和长度等于ll用":"分割的第二项，因为"起始"两个字不算，因该从第二项的第三个字母开始
        start = mid(Split(ll, ":")(1), 3)
        ' 起始是 "起始和长度" 用 "," 分割 的第一项，并将它转换成数值。
        start = val("&H" & Split(start, ",")(0))

        he.dwSize = Len(he)
        ' 再列举一次系统中的堆，找出堆ID等于前面计算出来的堆ID
        b = Heap32First(he, pid, GetProcess(pid).th32DefaultHeapID)
        Do While b
                If he.th32ProcessID = pid Then
                        If he.th32HeapID = hid And he.dwAddress = start Then
                                ' 找到了这一项则退出循环
                                Exit Do
                        End If
                End If
                ' 继续找下一项
                b = Heap32Next(he)
        Loop

        ' 将堆信息填入新建的frmviewh窗口中
        v.PI(0) = Hex(he.th32HeapID)
        v.PI(1) = Hex(he.th32ProcessID)
        v.PI(2) = Hex(he.dwAddress)
        v.PI(3) = Hex(he.dwBlockSize)
        v.PI(4) = he.dwLockCount
        v.PI(5) = Hex(he.hHandle)
        v.PI(6) = Hex(he.dwFlags)

        v.Show

End Sub

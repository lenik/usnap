VERSION 5.00
Begin VB.Form frmviewp
   Caption         =   "���̷���"
   ClientHeight    =   3810
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5610
   LinkTopic       =   "Form2"
   ScaleHeight     =   3810
   ScaleWidth      =   5610
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command6
      Caption         =   "����"
      Height          =   495
      Left            =   3480
      TabIndex        =   21
      Top             =   3120
      Width           =   1815
   End
   Begin VB.CommandButton Command5
      Caption         =   "�����ڴ����"
      Height          =   495
      Left            =   240
      TabIndex        =   20
      Top             =   3120
      Width           =   2055
   End
   Begin VB.CommandButton Command4
      Caption         =   "����������"
      Height          =   375
      Left            =   4080
      TabIndex        =   19
      Top             =   1920
      Width           =   1215
   End
   Begin VB.CommandButton Command3
      Caption         =   "���������߳�"
      Height          =   375
      Left            =   4080
      TabIndex        =   18
      Top             =   1560
      Width           =   1215
   End
   Begin VB.CommandButton Command2
      Caption         =   "�Ը�ģ�����"
      Height          =   375
      Left            =   4080
      TabIndex        =   17
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton Command1
      Caption         =   "�Ըöѷ���"
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
      Caption         =   "��־:"
      Height          =   180
      Index           =   7
      Left            =   240
      TabIndex        =   7
      Top             =   2760
      Width           =   450
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "��������Ȩ:"
      Height          =   180
      Index           =   6
      Left            =   240
      TabIndex        =   6
      Top             =   2400
      Width           =   990
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "������ID:"
      Height          =   180
      Index           =   5
      Left            =   240
      TabIndex        =   5
      Top             =   2040
      Width           =   810
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "�����߳���:"
      Height          =   180
      Index           =   4
      Left            =   240
      TabIndex        =   4
      Top             =   1680
      Width           =   990
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "ģ��ID:"
      Height          =   180
      Index           =   3
      Left            =   240
      TabIndex        =   3
      Top             =   1320
      Width           =   630
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Ĭ�϶�ID:"
      Height          =   180
      Index           =   2
      Left            =   240
      TabIndex        =   2
      Top             =   960
      Width           =   810
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "����:"
      Height          =   180
      Index           =   1
      Left            =   240
      TabIndex        =   1
      Top             =   600
      Width           =   450
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "����ID:"
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
        ' ��ȡĬ�϶ѵ���Ϣ�������浽he��
        Heap32First he, val("&H" & PI(0)), val("&H" & PI(2))
        ' ����һ������Ϊfrmviewh�Ĵ���
        Dim v As New frmviewh
        ' ���ѵ���Ϣ�����½��Ĵ���
        v.PI(0) = Hex(he.th32HeapID)
        v.PI(1) = Hex(he.th32ProcessID)
        v.PI(2) = Hex(he.dwAddress)
        v.PI(3) = Hex(he.dwBlockSize)
        v.PI(4) = he.dwLockCount
        v.PI(5) = Hex(he.hHandle)
        v.PI(6) = Hex(he.dwFlags)
        ' ��ʾ����
        v.Show
End Sub

Private Sub Command2_Click()
        Dim mid
        Dim m As MODULEENTRY32
        Dim h As Long, b As Boolean

        ' midΪģ��ID
        mid = val("&H" & PI(3))

        ' ����һ������
        h = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0)
        m.dwSize = Len(m)
        ' �ӿ������ҳ�ģ��ID����mid��ģ�����Ϣ
        b = Module32First(h, m)
        Do While m.th32ModuleID <> mid And b
                b = Module32Next(h, m)
        Loop

        ' ����ҵ��˸�ģ��
        If m.th32ModuleID = mid Then
                ' ����һ������Ϊfrmviewm�Ĵ���
                Dim v As New frmviewm
                ' ����ģ�����Ϣ����ô���
                v.PI(0) = Hex(m.th32ModuleID)
                v.PI(1) = m.szModule
                v.PI(2) = Hex(m.th32ProcessID)
                v.PI(3) = "�ܹ�" & m.GlblcntUsage & ",���б�����ʹ��" & m.ProccntUsage
                v.PI(4) = Hex(m.modBaseAddr)
                v.PI(5) = Hex(m.modBaseSize)
                v.PI(6) = Hex(m.hModule)
                ' ��ʾ����
                v.Show
        End If
        ' �رտ���
        CloseHandle h
End Sub

Private Sub Command3_Click()
        Dim pid
        Dim t As THREADENTRY32
        Dim h As Long, b As Boolean
        Dim v As New frmviewths

        pid = val("&H" & PI(0))
        ' ����һ������
        h = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0)
        t.dwSize = Len(t)

        ' ���������������ڽ���pid���߳���ӵ��½�������б����
        ' ��ȡ�����е�һ���߳�
        b = Thread32First(h, t)
        Do While b
                ' ����̵߳��������̵���pid
                If t.th32OwnerProcessID = pid Then
                        v.lstThreads.AddItem Hex(t.th32ThreadID)
                End If
                ' ��ȡ��������һ���߳�
                b = Thread32Next(h, t)
        Loop
        ' �رտ���
        CloseHandle h
        ' �����߳��б����pid�ֶ�
        v.PI(0) = Hex(pid)
        ' ��ʾ����
        v.Show
End Sub

Private Sub Command4_Click()
        Dim pid
        pid = val("&H" & PI(5))
        ' ��������̴���
        If pid <> 0 Then
                ' ����һ������Ϊfrmviewp�Ĵ���
                Dim v As New frmviewp
                ' ���ø�����ID��ʼ��
                v.init pid
                ' ��ʾ����
                v.Show
        End If
End Sub

Private Sub Command5_Click()
        ' ����һ������Ϊmemory�Ĵ���
        Dim v As New memory
        ' ���ô����е�PID�ֶ�
        v.txtPID = PI(0)
        ' ��ʾ����
        v.Show
End Sub

Private Sub Command6_Click()
        ' �رձ�����
        Hide
End Sub

Public Sub init(pid)
        Dim pe As PROCESSENTRY32
        ' ʹ�ý���IDΪPID�Ľ�����Ϣ��ʼ��
        pe = GetProcess(pid)
        With pe
                ' ������Ϣ��������ֶ�
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

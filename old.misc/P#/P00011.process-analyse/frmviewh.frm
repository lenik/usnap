VERSION 5.00
Begin VB.Form frmviewh
   Caption         =   "����ʹ�öѷ���"
   ClientHeight    =   3465
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4785
   LinkTopic       =   "Form2"
   ScaleHeight     =   3465
   ScaleWidth      =   4785
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2
      Caption         =   "����"
      Height          =   375
      Left            =   3240
      TabIndex        =   15
      Top             =   2880
      Width           =   1215
   End
   Begin VB.CommandButton Command1
      Caption         =   "����ͬһ���̵����ж�"
      Height          =   375
      Left            =   360
      TabIndex        =   14
      Top             =   2880
      Width           =   2415
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "��ID:"
      Height          =   180
      Index           =   0
      Left            =   360
      TabIndex        =   13
      Top             =   240
      Width           =   450
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "����ID:"
      Height          =   180
      Index           =   1
      Left            =   360
      TabIndex        =   12
      Top             =   600
      Width           =   630
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "����ʼ��ַ:"
      Height          =   180
      Index           =   2
      Left            =   360
      TabIndex        =   11
      Top             =   960
      Width           =   990
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "�Ѵ�С:"
      Height          =   180
      Index           =   3
      Left            =   360
      TabIndex        =   10
      Top             =   1320
      Width           =   630
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "��������:"
      Height          =   180
      Index           =   4
      Left            =   360
      TabIndex        =   9
      Top             =   1680
      Width           =   810
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "�Ѿ��:"
      Height          =   180
      Index           =   5
      Left            =   360
      TabIndex        =   8
      Top             =   2040
      Width           =   630
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "��־:"
      Height          =   180
      Index           =   6
      Left            =   360
      TabIndex        =   7
      Top             =   2400
      Width           =   450
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   0
      Left            =   1560
      TabIndex        =   6
      Top             =   240
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   1
      Left            =   1560
      TabIndex        =   5
      Top             =   600
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   2
      Left            =   1560
      TabIndex        =   4
      Top             =   960
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   3
      Left            =   1560
      TabIndex        =   3
      Top             =   1320
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   4
      Left            =   1560
      TabIndex        =   2
      Top             =   1680
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   5
      Left            =   1560
      TabIndex        =   1
      Top             =   2040
      Width           =   90
   End
   Begin VB.Label PI
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Index           =   6
      Left            =   1560
      TabIndex        =   0
      Top             =   2400
      Width           =   90
   End
End
Attribute VB_Name = "frmviewh"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

Private Sub Command1_Click()
        Dim pid
        Dim he As HEAPENTRY32
        Dim b As Boolean
        ' ����һ������Ϊfrmviewhs�Ĵ���
        Dim v As New frmviewhs

        pid = val("&H" & PI(1))
        he.dwSize = Len(he)
        ' ��ȡ�����е�һ����
        b = Heap32First(he, pid, GetProcess(pid).th32DefaultHeapID)
        Do While b
                ' ֻ��Ӷ����ڽ���Ϊָ��pid�Ķ�
                If he.th32ProcessID = pid Then
                        ' ÿһ�������¸�ʽ��ʾ��
                        '       ��ID��16���� ":��ʼ" �ѵ�ַ��16���� "," �ѳ��ȵ�16����
                        v.lstHeaps.AddItem Hex(he.th32HeapID) & ":��ʼ" & Hex(he.dwAddress) & ",����" & Hex(he.dwBlockSize)
                End If
                ' ������һ���ѡ�����Ѿ������򷵻�false
                b = Heap32Next(he)
        Loop
        v.PI(0) = Hex(pid)
        ' ��ʾ�½��Ĵ���
        v.Show
End Sub

Private Sub Command2_Click()
        ' ����ر�ʱ��������
        Hide
End Sub

VERSION 5.00
Begin VB.Form frmviewhs
   Caption         =   "�����е����ж��б�"
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
      Caption         =   "���б�:"
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
      Caption         =   "����ID:"
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

' �ڶ��б���˫������ʾָ���ѵ���Ϣ
Private Sub lstHeaps_DblClick()
        Dim pid, hid, start, ll
        Dim he As HEAPENTRY32
        Dim b As Boolean
        ' ����һ������Ϊfrmviewh�Ĵ���
        Dim v As New frmviewh

        ' �б������ж����ڵĽ���ID
        pid = val("&H" & PI(0))

        ' ��˫��������浽ll
        ll = lstHeaps.Text
        ' ÿһ������¸�ʽ��
        '       ��ID��16���� ":��ʼ" �ѵ�ַ��16���� "," �ѳ��ȵ�16����
        ' ��� ��ID����ll��":"�ָ�ĵ�һ��
        hid = val("&H" & Split(ll, ":")(0))

        ' ��ʼ�ͳ��ȵ���ll��":"�ָ�ĵڶ����Ϊ"��ʼ"�����ֲ��㣬��ôӵڶ���ĵ�������ĸ��ʼ
        start = mid(Split(ll, ":")(1), 3)
        ' ��ʼ�� "��ʼ�ͳ���" �� "," �ָ� �ĵ�һ�������ת������ֵ��
        start = val("&H" & Split(start, ",")(0))

        he.dwSize = Len(he)
        ' ���о�һ��ϵͳ�еĶѣ��ҳ���ID����ǰ���������Ķ�ID
        b = Heap32First(he, pid, GetProcess(pid).th32DefaultHeapID)
        Do While b
                If he.th32ProcessID = pid Then
                        If he.th32HeapID = hid And he.dwAddress = start Then
                                ' �ҵ�����һ�����˳�ѭ��
                                Exit Do
                        End If
                End If
                ' ��������һ��
                b = Heap32Next(he)
        Loop

        ' ������Ϣ�����½���frmviewh������
        v.PI(0) = Hex(he.th32HeapID)
        v.PI(1) = Hex(he.th32ProcessID)
        v.PI(2) = Hex(he.dwAddress)
        v.PI(3) = Hex(he.dwBlockSize)
        v.PI(4) = he.dwLockCount
        v.PI(5) = Hex(he.hHandle)
        v.PI(6) = Hex(he.dwFlags)

        v.Show

End Sub

VERSION 5.00
Begin VB.Form frmviewths
   Caption         =   "���̰������߳��б�"
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
      Caption         =   "����ID:"
      Height          =   180
      Index           =   0
      Left            =   360
      TabIndex        =   2
      Top             =   240
      Width           =   630
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "�߳��б�:"
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

' ���б����˫���Է����߳�IDΪtid���߳�
Private Sub lstThreads_DblClick()
        Dim pid, tid
        Dim t As THREADENTRY32
        Dim h As Long, b As Boolean
        Dim v As New frmviewt

        pid = val("&H" & PI(0))
        ' tid�͵����б����˫������������ݣ�����ת������ֵ
        tid = val("&H" & lstThreads.Text)

        ' ����һ������
        h = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0)
        t.dwSize = Len(t)

        ' �ҳ������н���IDΪpid���߳�IDΪtid���Ǹ��߳�
        ' ��ȡ�����е�һ���̣߳�������t
        b = Thread32First(h, t)
        Do While b
                If t.th32OwnerProcessID = pid And t.th32ThreadID = tid Then
                        ' �ҵ��˾��˳�ѭ��
                        Exit Do
                End If
                ' ��ȡ��������һ���߳�
                b = Thread32Next(h, t)
        Loop
        ' �رտ���
        CloseHandle h

        ' ���ҵ����߳���Ϣ�����½��Ĵ�����
        v.PI(0) = Hex(t.th32ThreadID)
        v.PI(1) = Hex(t.th32OwnerProcessID)
        v.PI(2) = t.cntUsage
        v.PI(3) = t.tpBasePri
        v.PI(4) = t.tpDeltaPri
        v.PI(5) = Hex(t.dwFlags)

        ' ��ʾ����
        v.Show

End Sub

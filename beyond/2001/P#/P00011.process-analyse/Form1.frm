VERSION 5.00
Begin VB.Form Form1
   Caption         =   "���̷�������"
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
      Caption         =   "ˢ��"
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
      Caption         =   "˫���Է���ѡ������"
      Height          =   180
      Left            =   1920
      TabIndex        =   3
      Top             =   3960
      Width           =   1620
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "&L �����б�"
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
        ' ��ȡϵͳ���������е����н��̲����浽Processes�����С�
        GetProcesses

        Dim i
        ' �ڽ����������ʾ�������б��֮ǰ��������б��
        lstProcesses.Clear
        For i = 1 To nProcesses
                ' ÿһ�������¸�ʽ��ʾ��
                '     ����ID��16���� : ���̶�Ӧ��·���ļ���
                lstProcesses.AddItem Hex(Processes(i).th32ProcessID) & ":" & Processes(i).szExeFile
        Next
End Sub

Private Sub Form_Load()
        ' ����ʼʱ�г��������е����н���
        cmdRefresh_Click
End Sub

Private Sub Form_Unload(Cancel As Integer)
        ' ��������ر�ʱ��������������
        ' ͨ�����������������ر������������塣
        End
End Sub

Private Sub lstProcesses_DblClick()
        Dim x, pid
        ' �ڽ����б����˫��������Ҫ�õ�˫��������Ľ���PID
        ' ͨ������������":"�ָ��ȡ�ָ��ĵ�һ�� (0) ��ʵ��
        x = Split(lstProcesses.Text, ":")(0)
        ' ������PID�ַ���ת������ֵ����"&H" ��ʾ x ����16���Ʊ�ʾ�ġ�
        pid = val("&H" & x)
        ' ����һ��frmviewp���͵Ĵ���
        Dim v As New frmviewp
        ' ���øô����init������ʼ������ĸ��ֶ�
        v.init pid
        ' ��ʾ����
        v.Show
End Sub

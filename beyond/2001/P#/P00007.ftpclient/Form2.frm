VERSION 5.00
Begin VB.Form �û�����
   Caption         =   "�û�����"
   ClientHeight    =   4185
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6135
   ControlBox      =   0   'False
   LinkTopic       =   "Form2"
   ScaleHeight     =   4185
   ScaleWidth      =   6135
   StartUpPosition =   3  '����ȱʡ
   Begin VB.CommandButton Command2
      Caption         =   "&Rɾ��"
      Height          =   375
      Left            =   1560
      TabIndex        =   12
      Top             =   3720
      Width           =   1335
   End
   Begin VB.CommandButton Command1
      Caption         =   "&A����"
      Height          =   375
      Left            =   120
      TabIndex        =   11
      Top             =   3720
      Width           =   1215
   End
   Begin VB.CommandButton ����
      Caption         =   "&X����"
      Height          =   375
      Left            =   4800
      TabIndex        =   10
      Top             =   3720
      Width           =   975
   End
   Begin VB.CheckBox Ŀ¼����Ȩ��
      Caption         =   "������û�Ŀ¼����Ȩ��"
      Height          =   255
      Left            =   2760
      TabIndex        =   9
      Top             =   3240
      Width           =   3015
   End
   Begin VB.CheckBox ��Ȩ��
      Caption         =   "������û���Ȩ��"
      Height          =   255
      Left            =   2760
      TabIndex        =   8
      Top             =   2520
      Width           =   2175
   End
   Begin VB.CheckBox дȨ��
      Caption         =   "������û�дȨ��"
      Height          =   255
      Left            =   2760
      TabIndex        =   7
      Top             =   2880
      Width           =   2175
   End
   Begin VB.CheckBox ʹ��email����
      Caption         =   "ʹ��Email��ַ��Ϊ����"
      Height          =   255
      Left            =   3000
      TabIndex        =   6
      Top             =   1560
      Width           =   2535
   End
   Begin VB.TextBox ����
      Height          =   375
      IMEMode         =   3  'DISABLE
      Left            =   3000
      PasswordChar    =   "*"
      TabIndex        =   5
      Top             =   1920
      Width           =   2775
   End
   Begin VB.TextBox �û���
      Height          =   375
      Left            =   3000
      TabIndex        =   3
      Top             =   600
      Width           =   2775
   End
   Begin VB.ListBox �û��б�
      Height          =   2760
      Left            =   120
      TabIndex        =   1
      Top             =   600
      Width           =   2175
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "����"
      Height          =   180
      Left            =   2640
      TabIndex        =   4
      Top             =   1200
      Width           =   360
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "�û���"
      Height          =   180
      Left            =   2640
      TabIndex        =   2
      Top             =   240
      Width           =   540
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "�û��б�"
      Height          =   180
      Left            =   720
      TabIndex        =   0
      Top             =   240
      Width           =   720
   End
End
Attribute VB_Name = "�û�����"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Command1_Click()
        Dim u As �û�
        u.�û��� = �û���
        u.���� = ����
        u.����Email���� = ʹ��email����.Value <> 0
        u.��Ȩ�� = ��Ȩ��.Value <> 0
        u.дȨ�� = дȨ��.Value <> 0
        u.Ŀ¼����Ȩ�� = Ŀ¼����Ȩ�� <> 0
        �û��б�.AddItem �����û�(u)
End Sub

Private Sub Command2_Click()
        Dim li
        li = �û��б�.ListIndex
        On Error Resume Next
        �û��б�.RemoveItem li
        �û��б�.ListIndex = li
End Sub

Private Sub Form_Load()
        ��ȡ����
End Sub

Private Sub ����_Click()
        ��������
        Me.Hide
End Sub

Public Sub ��������()
        Dim i
        SaveSetting ע���_����, "�û�����", "�û���Ŀ", �û��б�.ListCount
        For i = 0 To �û��б�.ListCount - 1
                SaveSetting ע���_����, "�û�����", "�û�#" & Trim(i), _
                        �û��б�.List(i)
        Next
End Sub

Public Sub ��ȡ����()
        Dim c, i
        c = GetSetting(ע���_����, "�û�����", "�û���Ŀ", 0)
        For i = 0 To c - 1
                �û��б�.AddItem GetSetting(ע���_����, "�û�����", "�û�#" & Trim(i), "")
        Next
End Sub

Private Sub �û��б�_Click()
        Dim u As �û�
        u = �����û�(�û��б�.List(�û��б�.ListIndex))
        �û��� = u.�û���
        ���� = u.����
        ʹ��email����.Value = IIf(u.����Email����, 1, 0)
        ��Ȩ��.Value = IIf(u.��Ȩ��, 1, 0)
        дȨ��.Value = IIf(u.дȨ��, 1, 0)
        Ŀ¼����Ȩ��.Value = IIf(u.Ŀ¼����Ȩ��, 1, 0)
End Sub

Public Function �û�����(x) As Boolean
        Dim i
        For i = 0 To �û��б�.ListCount - 1
                Dim u As �û�
                u = �����û�(�û��б�.List(i))
                If x = u.�û��� Then
                        �û����� = True
                        Exit Function
                End If
        Next
        �û����� = False
End Function

Public Function ������ȷ(x, p) As Boolean
        Dim i
        For i = 0 To �û��б�.ListCount - 1
                Dim u As �û�
                u = �����û�(�û��б�.List(i))
                If x = u.�û��� Then
                        If p = u.���� Then
                                ������ȷ = True
                                Exit Function
                        End If
                Else
                        ������ȷ = False
                        Exit Function
                End If
        Next
        ������ȷ = False
End Function

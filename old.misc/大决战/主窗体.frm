VERSION 5.00
Begin VB.Form ������
   Caption         =   "Form1"
   ClientHeight    =   4785
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6810
   LinkTopic       =   "Form1"
   ScaleHeight     =   319
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   454
   StartUpPosition =   3  '����ȱʡ
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   465
      Left            =   4620
      TabIndex        =   3
      Top             =   3855
      Width           =   1635
   End
   Begin VB.PictureBox ������Ƭ
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   990
      Left            =   105
      Picture         =   "������.frx":0000
      ScaleHeight     =   960
      ScaleWidth      =   960
      TabIndex        =   1
      Top             =   3705
      Visible         =   0   'False
      Width           =   990
   End
   Begin VB.PictureBox ����
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   2400
      Left            =   1065
      ScaleHeight     =   160
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   320
      TabIndex        =   0
      Top             =   1080
      Width           =   4800
   End
   Begin VB.Label Label1
      Caption         =   "Label1"
      Height          =   465
      Left            =   1350
      TabIndex        =   2
      Top             =   3795
      Width           =   1965
   End
End
Attribute VB_Name = "������"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Const �����߽��С As Integer = 5

Public Sub ˢ��()
        ����.Cls
        ����ͼ.���Ƶ�ͼ
        ����.Refresh
        Label1 = ����ͼ.������߽� & "," & ����ͼ.�����ϱ߽�
End Sub

Private Sub ���������߽�(ByVal X As Single, ByVal Y As Single)
        Dim wi As WINDOWINFO
        Dim nX As Single, nY As Single          ' �����λ�� [����]
        Dim oX As Single, oY As Single          ' �����λ�� [����]
        GetWindowInfo Me.hWnd, wi
        oX = wi.rcClient.Left + ����.Left + X
        oY = wi.rcClient.Top + ����.Top + Y
        nX = oX
        nY = oY
        If X < �����߽��С Then
                nX = wi.rcClient.Left + ����.Left + �����߽��С
                If ����ͼ.������߽� > 0 Then
                        ����ͼ.������߽� = ����ͼ.������߽� - 1
                End If
        End If
        If X > ����.Width - �����߽��С Then
                nX = wi.rcClient.Left + ����.Left + ����.Width - �����߽��С
                If ����ͼ.������߽� + ����ͼ.������� < ����ͼ.��� Then
                        ����ͼ.������߽� = ����ͼ.������߽� + 1
                End If
        End If
        If Y < �����߽��С Then
                nY = wi.rcClient.Top + ����.Top + �����߽��С
                If ����ͼ.�����ϱ߽� > 0 Then
                        ����ͼ.�����ϱ߽� = ����ͼ.�����ϱ߽� - 1
                End If
        End If
        If Y > ����.Height - �����߽��С Then
                nY = wi.rcClient.Top + ����.Top + ����.Height - �����߽��С
                If ����ͼ.�����ϱ߽� + ����ͼ.�����߶� < ����ͼ.�߶� Then
                        ����ͼ.�����ϱ߽� = ����ͼ.�����ϱ߽� + 1
                End If
        End If
        If nX <> oX And nY <> oY Then
                SetCursorPos nX, nY
        ElseIf nX <> oX Then
                SetCursorPos nX, oY
        ElseIf nY <> oY Then
                SetCursorPos oX, nY
        Else
                Exit Sub
        End If
        ˢ��
End Sub

Private Sub Command1_Click()
        ˢ��
End Sub

Private Sub ����_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
        ���������߽� X, Y
End Sub

VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form Form1
   Appearance      =   0  'Flat
   BackColor       =   &H80000005&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "�й�����"
   ClientHeight    =   6360
   ClientLeft      =   150
   ClientTop       =   720
   ClientWidth     =   5895
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   424
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   393
   StartUpPosition =   3  'Windows Default
   Begin VB.Timer Timer1
      Interval        =   100
      Left            =   75
      Top             =   795
   End
   Begin MSWinsockLib.Winsock c
      Left            =   75
      Top             =   270
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      RemotePort      =   1230
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   7
      Left            =   2775
      Picture         =   "Form1.frx":0000
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   14
      Top             =   825
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   6
      Left            =   2430
      Picture         =   "Form1.frx":0D28
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   13
      Top             =   825
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   5
      Left            =   2085
      Picture         =   "Form1.frx":1A50
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   12
      Top             =   825
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   4
      Left            =   1740
      Picture         =   "Form1.frx":2778
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   11
      Top             =   825
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   3
      Left            =   1380
      Picture         =   "Form1.frx":34A0
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   10
      Top             =   825
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   2
      Left            =   1035
      Picture         =   "Form1.frx":41C8
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   9
      Top             =   825
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   9
      Left            =   1035
      Picture         =   "Form1.frx":4EF0
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   8
      Top             =   1365
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   8
      Left            =   690
      Picture         =   "Form1.frx":5C18
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   7
      Top             =   1365
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   14
      Left            =   2775
      Picture         =   "Form1.frx":6940
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   6
      Top             =   1365
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   13
      Left            =   2430
      Picture         =   "Form1.frx":7668
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   5
      Top             =   1365
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   12
      Left            =   2085
      Picture         =   "Form1.frx":8390
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   4
      Top             =   1365
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   11
      Left            =   1725
      Picture         =   "Form1.frx":90B8
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   3
      Top             =   1365
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   10
      Left            =   1440
      Picture         =   "Form1.frx":9DE0
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   2
      Top             =   1365
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox qz
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   495
      Index           =   1
      Left            =   690
      Picture         =   "Form1.frx":AB08
      ScaleHeight     =   33
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   33
      TabIndex        =   1
      Top             =   825
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox p
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   6240
      Left            =   60
      Picture         =   "Form1.frx":B830
      ScaleHeight     =   414
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   384
      TabIndex        =   0
      Top             =   60
      Width           =   5790
   End
   Begin VB.Menu mnunew
      Caption         =   "����Ϸ"
   End
   Begin VB.Menu mnucreate
      Caption         =   "���ö˿�"
   End
   Begin VB.Menu mnujoin
      Caption         =   "����������Ϸ"
   End
   Begin VB.Menu mundo
      Caption         =   "����"
   End
   Begin VB.Menu mnuexit
      Caption         =   "�˳�"
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim dx, dy, dqzx, dqzy
Dim dqz As qztype

Dim server As Boolean

'
Private Sub c_Close()
        c.Close
        c.LocalPort = 0
End Sub

Private Sub c_DataArrival(ByVal bytesTotal As Long)
        Dim buf As String
        Dim a, x1, y1, x2, y2

        c.GetData buf

        If buf = "ok" Then              's->c
                mnunew_Click
                ��Ϸģʽ = "����ͻ�"
                ' ����������
                ��ǰѡ�� = "��"
                MsgBox "������Ϸ��ʼ���Է�����"
        ElseIf buf = "cancel" Then      ' s->c
                MsgBox "�Է����Ͻ���������Ϸ"
                c.Close
                server = True
        ElseIf buf = "qpundo" Then
                qpundo
        Else
                a = Split(buf, ",")
                x1 = a(0)
                y1 = a(1)
                x2 = a(2)
                y2 = a(3)
                moveqz x1, y1, x2, y2
        End If

End Sub

Private Sub c_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        c.Close
End Sub

Private Sub Form_Load()
        server = True

        mnunew_Click
End Sub

Private Sub Form_Paint()
        draw
End Sub

Private Sub mnucreate_Click()
        Dim lport
        lport = InputBox("ʹ�ö˿�", , c.LocalPort)
        Timer1.Enabled = False
        c.Close
        c.LocalPort = Val(lport)
        c.Listen
        Timer1.Enabled = True
End Sub

Private Sub mnuexit_Click()
        End
End Sub

Private Sub mnujoin_Click()
        Dim a, rip, rport
        a = InputBox("�����������IP��ַ:�˿ڣ��� 192.168.1.107:1230", , "192.168.1.107:1230")
        ' ���û�а�ȡ��
        If a <> "" Then
                a = Split(a, ":")
                rip = a(0)
                rport = Val(a(1))
                server = False
                c.Close
                c.Connect rip, rport
        End If
End Sub

Private Sub mnunew_Click()
        init
        dqz = ��
        ��ǰѡ�� = "��"
        ��Ϸģʽ = "����"
        ���� = 0
        draw
End Sub


Private Sub qpundo()
        Dim i, j
        For i = 1 To 10
                For j = 1 To 9
                        qp(i, j) = qp2(i, j)
                Next
        Next
        draw
End Sub

Private Sub mundo_Click()
        qpundo
        If ��Ϸģʽ <> "����" Then
                c.SendData "qpundo"
        End If
End Sub

Private Sub p_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        Dim qzx, qzy
        qzx = Int((X - 10) / 41) + 1
        qzy = Int((Y - 5) / 41) + 1
        If qzx < 1 Or qzx > 9 Or qzy < 1 Or qzy > 10 Then Exit Sub

        If qp(qzy, qzx) = �� Then Exit Sub

        If ��Ϸģʽ = "���������" And ��ǰѡ�� = "��" Then Exit Sub
        If ��Ϸģʽ = "����ͻ�" And ��ǰѡ�� = "��" Then Exit Sub

        ' �׷������ƶ��ڷ�������
        If ��ǰѡ�� = "��" And �ڷ�(qp(qzy, qzx)) Then Exit Sub
        ' �ڷ������ƶ��׷�������
        If ��ǰѡ�� = "��" And �׷�(qp(qzy, qzx)) Then Exit Sub

        dx = X
        dy = Y
        dqzx = qzx
        dqzy = qzy
        dqz = qp(qzy, qzx)
End Sub

Private Sub p_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
        Dim qzx, qzy

        If Button = 0 Then Exit Sub
        If dqz = �� Then Exit Sub

        qzx = Int((X - 10) / 41) + 1
        qzy = Int((Y - 5) / 41) + 1
        If qzx < 1 Or qzx > 9 Or qzy < 1 Or qzy > 10 Then Exit Sub

        If Not qz(dqz).Visible Then qz(dqz).Visible = True
        qz(dqz).Top = Y
        qz(dqz).Left = X

End Sub

Private Sub p_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
        Dim qzx, qzy
        If dqz = �� Then Exit Sub
        qz(dqz).Visible = False
        dqz = ��

        qzx = Int((X - 10) / 41) + 1
        qzy = Int((Y - 5) / 41) + 1
        If qzx < 1 Or qzx > 9 Or qzy < 1 Or qzy > 10 Then Exit Sub

        If qzx = dqzx And qzy = dqzy Then Exit Sub

        If Not isvalid(dqzx, dqzy, qzx, qzy) Then
                MsgBox "����������"
        Else
                moveqz dqzx, dqzy, qzx, qzy
        End If

End Sub

Public Sub draw()
        Dim X, Y
        p.Cls
        For Y = 1 To 10
                For X = 1 To 9
                        If qp(Y, X) <> �� Then
                                p.PaintPicture qz(qp(Y, X)), 10 + (X - 1) * 41, 5 + (Y - 1) * 41
                        End If
                Next
        Next
End Sub

Private Sub c_ConnectionRequest(ByVal requestID As Long)
        c.Close
        c.Accept requestID

        If ��Ϸģʽ = "����" Then
                Dim r
                r = MsgBox("Զ������" & c.RemoteHost & "(" & c.RemoteHostIP & ":" & c.RemotePort & ")" & "����ʼ�������,���ܷ�?", vbOKCancel)
                If r = vbOK Then
                        c.SendData "ok"
                        mnunew_Click
                        ��Ϸģʽ = "���������"
                        ' ����������
                        ��ǰѡ�� = "��"
                Else
                        c.SendData "cancel"
                End If
        Else
                ' �Ѿ�������ģʽ���Ȼ�Զ���������������ƶ���Ϣ����
        End If
End Sub

Private Sub Timer1_Timer()
        If c.State = sckError Then c.Close
        If server Then
                If c.State = sckClosed Then c.Listen
        End If
End Sub

Public Sub moveqz(x1, y1, x2, y2)
        Dim i, j
        For i = 1 To 10
                For j = 1 To 9
                        qp2(i, j) = qp1(i, j)
                Next
        Next
        For i = 1 To 10
                For j = 1 To 9
                        qp1(i, j) = qp(i, j)
                Next
        Next

        qp(y2, x2) = qp(y1, x1)
        qp(y1, x1) = ��
        Form1.draw
        If ��Ϸģʽ = "���������" And ��ǰѡ�� = "��" Then
                c.SendData x1 & "," & y1 & "," & x2 & "," & y2
        ElseIf ��Ϸģʽ = "����ͻ�" And ��ǰѡ�� = "��" Then
                c.SendData x1 & "," & y1 & "," & x2 & "," & y2
        End If

        Dim failed As Boolean
        failed = True
        For i = 1 To 10
                For j = 1 To 9
                        If (��ǰѡ�� = "��" And qp(i, j) = �׽�) Or _
                                (��ǰѡ�� = "��" And qp(i, j) = �ڽ�) Then
                                failed = False
                        End If
                Next
        Next
        If failed Then
                MsgBox ��ǰѡ�� & "��ʤ!"
                mnunew_Click
        End If

        If ��ǰѡ�� = "��" Then ��ǰѡ�� = "��" Else ��ǰѡ�� = "��"
End Sub

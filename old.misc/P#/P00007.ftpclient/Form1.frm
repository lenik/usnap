VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form Form1
   Caption         =   "FTP������"
   ClientHeight    =   5550
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   6990
   ControlBox      =   0   'False
   LinkTopic       =   "Form1"
   ScaleHeight     =   5550
   ScaleWidth      =   6990
   StartUpPosition =   3  'Windows Default
   Begin VB.Timer Timer1
      Enabled         =   0   'False
      Interval        =   1
      Left            =   4080
      Top             =   4200
   End
   Begin MSComDlg.CommonDialog cd
      Left            =   4680
      Top             =   4200
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin MSWinsockLib.Winsock ��������
      Left            =   5400
      Top             =   4200
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      LocalPort       =   21
   End
   Begin MSWinsockLib.Winsock ��������
      Left            =   6000
      Top             =   4200
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
   Begin VB.ListBox ��־
      Height          =   1035
      ItemData        =   "Form1.frx":0000
      Left            =   240
      List            =   "Form1.frx":0002
      TabIndex        =   14
      Top             =   4080
      Width           =   6495
   End
   Begin VB.CommandButton ���ӳ��Ŀ¼
      Caption         =   "&B���"
      Height          =   375
      Left            =   6000
      TabIndex        =   13
      Top             =   3120
      Width           =   735
   End
   Begin VB.CommandButton ɾ��
      Caption         =   "&Rɾ��"
      Height          =   375
      Left            =   2520
      TabIndex        =   12
      Top             =   840
      Width           =   855
   End
   Begin VB.CommandButton ���
      Caption         =   "&A���"
      Height          =   375
      Left            =   1440
      TabIndex        =   11
      Top             =   840
      Width           =   855
   End
   Begin VB.TextBox ӳ��Ŀ¼
      Height          =   375
      Left            =   3120
      TabIndex        =   10
      Top             =   3600
      Width           =   3615
   End
   Begin VB.TextBox ����Ŀ¼��
      Height          =   375
      Left            =   3120
      TabIndex        =   9
      Top             =   2640
      Width           =   3615
   End
   Begin VB.TextBox ��������Ŀ¼
      Height          =   375
      Left            =   3120
      TabIndex        =   6
      Top             =   1680
      Width           =   3615
   End
   Begin VB.ListBox ����Ŀ¼��
      Height          =   2400
      Left            =   240
      TabIndex        =   4
      Top             =   1320
      Width           =   2415
   End
   Begin VB.CommandButton Command1
      Caption         =   "���"
      Height          =   375
      Left            =   6000
      TabIndex        =   2
      Top             =   240
      Width           =   855
   End
   Begin VB.TextBox ��Ŀ¼
      Height          =   375
      Left            =   1800
      TabIndex        =   1
      Text            =   "C:\"
      Top             =   240
      Width           =   4095
   End
   Begin VB.Shape ���ݺ��̵�
      FillColor       =   &H00FFFFFF&
      FillStyle       =   0  'Solid
      Height          =   255
      Left            =   270
      Shape           =   2  'Oval
      Top             =   435
      Width           =   255
   End
   Begin VB.Shape ���ƺ��̵�
      FillColor       =   &H00FFFFFF&
      FillStyle       =   0  'Solid
      Height          =   255
      Left            =   270
      Shape           =   2  'Oval
      Top             =   135
      Width           =   255
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "����Ŀ¼ӳ�񵽷�����Ӳ���е�Ŀ¼"
      Height          =   180
      Index           =   2
      Left            =   2880
      TabIndex        =   8
      Top             =   3240
      Width           =   2880
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "����Ŀ¼������"
      Height          =   180
      Index           =   1
      Left            =   2880
      TabIndex        =   7
      Top             =   2280
      Width           =   1260
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "����Ŀ¼λ��FTP��������Ŀ¼�е�λ��"
      Height          =   180
      Index           =   0
      Left            =   2880
      TabIndex        =   5
      Top             =   1320
      Width           =   3150
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "����Ŀ¼"
      Height          =   180
      Left            =   240
      TabIndex        =   3
      Top             =   960
      Width           =   720
   End
   Begin VB.Label FTP������
      AutoSize        =   -1  'True
      Caption         =   "FTP��Ŀ¼(&R)"
      Height          =   180
      Left            =   720
      TabIndex        =   0
      Top             =   360
      Width           =   1080
   End
   Begin VB.Menu mFtpServer
      Caption         =   "&FTP������"
      Begin VB.Menu mStartFtp
         Caption         =   "&S����"
      End
      Begin VB.Menu mStopFtp
         Caption         =   "&Tֹͣ"
         Enabled         =   0   'False
      End
   End
   Begin VB.Menu mUserConfig
      Caption         =   "&U�û�����"
   End
   Begin VB.Menu mHelp
      Caption         =   "&H����"
      Begin VB.Menu mHelpAbout
         Caption         =   "&A����"
      End
   End
   Begin VB.Menu mExit
      Caption         =   "&X�˳�"
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        Dim s As New Shell32.Shell
        Dim f As Shell32.Folder
        Set f = s.BrowseForFolder(Me.hWnd, "��ѡ��FTP��Ŀ¼", 0)
        If Not f Is Nothing Then
                ��Ŀ¼ = f.ParseName("nul").Path
                ��Ŀ¼ = Left(��Ŀ¼, Len(��Ŀ¼) - 4)
        End If
End Sub

Private Sub Form_Load()
        ��ȡ����
        ���ڽ������� = False
        ���ݷ������ = True
End Sub

Private Sub mExit_Click()
        ��������
        End
End Sub

Private Sub mHelpAbout_Click()
        MsgBox "FTP ������"
End Sub

Private Sub mStartFtp_Click()

        If Not �ļ�ϵͳ.FolderExists(��Ŀ¼) Then
                MsgBox "��Ŀ¼������!"
                ��Ŀ¼.SetFocus
                Exit Sub
        End If

        mStartFtp.Enabled = False
        mStopFtp.Enabled = True
        Timer1.Enabled = True
        �ӵ���־ "������������"
End Sub

Private Sub mStopFtp_Click()
        mStartFtp.Enabled = True
        mStopFtp.Enabled = False
        Timer1.Enabled = False
        ��������.Close
        ��������.Close
        ���ƺ��̵�.FillColor = ��ɫ_�Ͽ�
        �ӵ���־ "���������ر�"
End Sub

Private Sub mUserConfig_Click()
        �û�����.Show 1
End Sub

Public Sub ��������()
        SaveSetting ע���_����, "��Ҫ����", "FTP��Ŀ¼", ��Ŀ¼.Text
        Dim i
        SaveSetting ע���_����, "��Ҫ����", "����Ŀ¼����", ����Ŀ¼��.ListCount
        For i = 0 To ����Ŀ¼��.ListCount - 1
                SaveSetting ע���_����, "��Ҫ����", "����Ŀ¼#" & Trim(i), _
                         ����Ŀ¼��.List(i)
        Next
End Sub

Public Sub ��ȡ����()
        ��Ŀ¼ = GetSetting(ע���_����, "��Ҫ����", "FTP��Ŀ¼", "")
        Dim i, c
        c = GetSetting(ע���_����, "��Ҫ����", "����Ŀ¼����", 0)
        For i = 0 To c - 1
                Dim s, x As ����Ŀ¼
                s = GetSetting(ע���_����, "��Ҫ����", "����Ŀ¼#" & Trim(i), "")
                ����Ŀ¼��.AddItem s
        Next
End Sub

Private Sub Timer1_Timer()
        On Error Resume Next

        Select Case ��������.State
        Case sckError
                ���ƺ��̵�.FillColor = ��ɫ_����
                ��������.Close
        Case sckClosed
                If Not ���ڽ������� Then ��������.Listen
                ���ƺ��̵�.FillColor = ��ɫ_����
        Case sckConnected
                ���ƺ��̵�.FillColor = ��ɫ_æµ
        End Select

        Select Case ��������.State
        Case sckError
                ���ݺ��̵�.FillColor = ��ɫ_����
                ��������.Close
        Case sckConnected
                ���ݺ��̵�.FillColor = ��ɫ_æµ
        Case sckClosed
                ���ݺ��̵�.FillColor = ��ɫ_�Ͽ�
                ��������.LocalPort = 0
        End Select
End Sub

Private Sub ��������_Close()
        ��������.Close
End Sub

Private Sub ��������_Connect()
        �ӵ���־ "��������"
End Sub

Private Sub ��������_ConnectionRequest(ByVal requestID As Long)
        ���ڽ������� = True
        ��������.Close
        ��������.Accept requestID
        ���ڽ������� = False
        ���Ʒ��� "220 " & "��ӭ���������ֵ� FTP ������ !!!"
        �ӵ���־ "��������"
        ��ǰ�û�.�û��� = ""
        ��ǰĿ¼ = ""
        �û��ѵ�½ = False
End Sub

Private Sub ��������_DataArrival(ByVal bytesTotal As Long)
        While Not ��������.State = sckConnected: DoEvents: Wend

        Dim buf As String
        Dim ps, a, fn
        ���ƺ��̵�.FillColor = ��ɫ_æµ
        ��������.GetData buf
        buf = Trim(buf)
        While (Asc(Right(buf, 1)) = 13 Or Asc(Right(buf, 1)) = 10) And Len(buf) > 0
                buf = Left(buf, Len(buf) - 1)
        Wend

        �ӵ���־ buf

        ps = Split(Trim(buf), " ", 2, vbTextCompare)
        If UBound(ps) < 0 Then Exit Sub
        Select Case UCase(ps(0))
        Case "USER"
                If Not �û�����.�û�����(ps(1)) Then
                        ���Ʒ��� "400 �û�������"
                Else
                        ��ǰ�û� = ��ȡ�û�����(ps(1))
                        If ��ǰ�û�.����Email���� Then
                                ���Ʒ��� "331 �û�����,����������Email��ַ��Ϊ����."
                        Else
                                ���Ʒ��� "331 �û�����,����������:"
                        End If
                End If
        Case "PASS"
                If ��ǰ�û�.�û��� = "" Then
                        ���Ʒ��� "503 ���������û���!"
                Else
                        If ��ǰ�û�.����Email���� Then
                                If Not (InStr(ps(1), "@") > 0) Then
                                        ���Ʒ��� "400 Email��ʽ����ȷ,������"
                                Else
                                        �û��ѵ�½ = True
                                        ���Ʒ��� "230 Email�Ѿ�����֤"
                                        ��ǰĿ¼ = "/"
                                        Set ��ǰĿ¼���� = �ļ�ϵͳ.GetFolder(��Ŀ¼.Text)
                                End If
                        Else
                                If ps(1) <> ��ǰ�û�.���� Then
                                        ���Ʒ��� "530 �������"
                                Else
                                        �û��ѵ�½ = True
                                        ���Ʒ��� "230 ������ȷ"
                                        ��ǰĿ¼ = "/"
                                        Set ��ǰĿ¼���� = �ļ�ϵͳ.GetFolder(��Ŀ¼.Text)
                                End If
                        End If
                End If
        Case "PWD"
                If Not �û��ѵ�½ Then ���Ʒ��� "530 ���ȵ�½": Exit Sub

                ���Ʒ��� "257 """ & ��ǰĿ¼ & """ �ǵ�ǰĿ¼"
        Case "CWD"
                If Not �û��ѵ�½ Then ���Ʒ��� "530 ���ȵ�½": Exit Sub

                If Left(ps(1), 1) <> "/" Then
                ' ���·��
                        If Not �ļ�ϵͳ.FolderExists(Ŀ¼����(��ǰĿ¼����.Path, ps(1))) Then
                                ���Ʒ��� "550 Ŀ¼������"
                        Else
                                Set ��ǰĿ¼���� = ��ǰĿ¼����.SubFolders(ps(1))
                                ��ǰĿ¼ = ��ǰĿ¼ & ps(1) & "/"
                                ���Ʒ��� "250 CWD������ȷ,��ǰĿ¼Ϊ:" & ��ǰĿ¼
                        End If
                Else
                ' ����·��
                        Dim ppp
                        ppp = ��Ŀ¼ & Replace(ps(1), "/", "\")
                        If �ļ�ϵͳ.FolderExists(ppp) Then
                                ��ǰĿ¼ = ps(1)
                                If Right(��ǰĿ¼, 1) <> "/" Then ��ǰĿ¼ = ��ǰĿ¼ & "/"
                                Set ��ǰĿ¼���� = �ļ�ϵͳ.GetFolder(ppp)
                                ���Ʒ��� "250 CWD������ȷ,��ǰĿ¼Ϊ:" & ��ǰĿ¼
                        Else
                                ���Ʒ��� "550 Ŀ¼������"
                        End If
                End If
        Case "CDUP"
                If Not �û��ѵ�½ Then ���Ʒ��� "530 ���ȵ�½": Exit Sub

                a = Split(��ǰĿ¼, "/")
                If UBound(a) > 1 Then
                        Dim i
                        ��ǰĿ¼ = ""
                        For i = LBound(a) To UBound(a) - 2
                                ��ǰĿ¼ = ��ǰĿ¼ & a(i) & "/"
                        Next
                        Set ��ǰĿ¼���� = ��ǰĿ¼����.ParentFolder
                End If
                ���Ʒ��� "250 CDUP������ȷ,��ǰĿ¼Ϊ:" & ��ǰĿ¼
        Case "LIST"
                If Not �û��ѵ�½ Then ���Ʒ��� "530 ���ȵ�½": Exit Sub
                ���Ʒ��� "150 LIST������ȷ"

                ���ݷ��� ��ȡ��ǰĿ¼����
                ���Ʒ��� "226 ���ݴ������!"
        Case "RETR"
                If Not �û��ѵ�½ Then ���Ʒ��� "400 ���ȵ�½": Exit Sub
                If Not ��ǰ�û�.��Ȩ�� Then
                        ���Ʒ��� "500 �û�û��Ȩ��ִ�б�����"
                        Exit Sub
                End If
                If �ļ�ϵͳ.FileExists(Ŀ¼����(��ǰĿ¼����.Path, ps(1))) Then
                        ���Ʒ��� "150 RETR������ȷ,׼����������"

                        fn = FreeFile
                        Open Ŀ¼����(��ǰĿ¼����.Path, ps(1)) For Binary As #fn
                        ReDim �ļ�����(1 To LOF(fn)) As Byte
                        Get #fn, , �ļ�����
                        Close #fn

                        ���ݷ��� �ļ�����
                        ���Ʒ��� "226 ���ݴ������"
                Else
                        ���Ʒ��� "550 �ļ�������"
                End If
        Case "STOR"
                If Not �û��ѵ�½ Then ���Ʒ��� "530 ���ȵ�½": Exit Sub
                If Not ��ǰ�û�.дȨ�� Then
                        ���Ʒ��� "500 �û�û��Ȩ��ִ�б�����"
                        Exit Sub
                End If
                On Error GoTo x1
                fn = FreeFile
                Open Ŀ¼����(��ǰĿ¼����.Path, ps(1)) For Binary As fn
                ���Ʒ��� "150 STOR������ȷ,׼����������"
                ��������.Connect
                While ��������.State <> sckClosed: DoEvents: Wend
                ���Ʒ��� "226 ���ݴ������"
                Put fn, , ��������
                Close fn
                Exit Sub
x1:
                Close fn
                ���Ʒ��� "500 �޷������ļ�"
                Exit Sub
        Case "MKD"
                If Not �û��ѵ�½ Then ���Ʒ��� "530 ���ȵ�½": Exit Sub
                If Not ��ǰ�û�.Ŀ¼����Ȩ�� Then
                        ���Ʒ��� "500 �û�û��Ȩ��ִ�б�����"
                        Exit Sub
                End If
                If �ļ�ϵͳ.FolderExists(Ŀ¼����(��ǰĿ¼����.Path, ps(1))) Then
                        ���Ʒ��� "550 �޷�����Ŀ¼,Ŀ¼�Ѵ���"
                        Exit Sub
                End If

                If ��ǰĿ¼����.SubFolders.Add(ps(1)) Is Nothing Then
                        ���Ʒ��� "550 �޷�����Ŀ¼"
                Else
                        ���Ʒ��� "257 MKD������ȷ"
                End If
        Case "RMD"
                If Not �û��ѵ�½ Then ���Ʒ��� "530 ���ȵ�½": Exit Sub
                If Not ��ǰ�û�.Ŀ¼����Ȩ�� Then
                        ���Ʒ��� "500 �û�û��Ȩ��ִ�б�����"
                        Exit Sub
                End If
                If Not �ļ�ϵͳ.FolderExists(Ŀ¼����(��ǰĿ¼����.Path, ps(1))) Then
                        ���Ʒ��� "550 �޷�ɾ��Ŀ¼,Ŀ¼������"
                        Exit Sub
                End If
                ��ǰĿ¼����.SubFolders(ps(1)).Delete
                If �ļ�ϵͳ.FolderExists(Ŀ¼����(��ǰĿ¼����.Path, ps(1))) Then
                        ���Ʒ��� "550 �޷�ɾ��Ŀ¼"
                Else
                        ���Ʒ��� "250 RMD������ȷ"
                End If
        Case "DELE"
                If Not �û��ѵ�½ Then ���Ʒ��� "530 ���ȵ�½": Exit Sub
                If Not ��ǰ�û�.Ŀ¼����Ȩ�� Then
                        ���Ʒ��� "500 �û�û��Ȩ��ִ�б�����"
                        Exit Sub
                End If
                If Not �ļ�ϵͳ.FileExists(Ŀ¼����(��ǰĿ¼����.Path, ps(1))) Then
                        ���Ʒ��� "550 �޷�ɾ���ļ�,�ļ�������"
                        Exit Sub
                End If
                ��ǰĿ¼����.Files(ps(1)).Delete True
                If �ļ�ϵͳ.FileExists(Ŀ¼����(��ǰĿ¼����.Path, ps(1))) Then
                        ���Ʒ��� "550 �޷�ɾ��Ŀ¼"
                Else
                        ���Ʒ��� "250 DELE������ȷ"
                End If
        Case "HELP"
                ���Ʒ��� "214 - USER PASS HELP QUIT PORT STOR RETR"
        Case "PORT"
                If Not �û��ѵ�½ Then ���Ʒ��� "530 ���ȵ�½": Exit Sub
                Dim ps2
                ps2 = Split(ps(1), ",", , vbTextCompare)
                If UBound(ps2) < 5 Then
                        ���Ʒ��� "500 ��ʽ����"
                Else
                        Զ�̵�ַ = Trim(ps2(0)) & "." & _
                                        Trim(ps2(1)) & "." & _
                                        Trim(ps2(2)) & "." & _
                                        Trim(ps2(3))
                        Զ�̶˿� = Val(ps2(4)) * 256 + Val(ps2(5))
                        ��������.RemoteHost = Զ�̵�ַ
                        ��������.RemotePort = Զ�̶˿�
                        ���Ʒ��� "200 PORT����ִ�����(" & Զ�̵�ַ & ":" & Զ�̶˿� & ")"
                End If
        Case "REIN"
                ���Ʒ��� "220 REIN������ȷ���������¿�ʼ"

                ��ǰĿ¼ = "/"
                Set ��ǰĿ¼���� = �ļ�ϵͳ.GetFolder(��Ŀ¼.Text)

        Case "QUIT"
                �ӵ���־ "�˳�����"
                ���Ʒ��� "210 лл����ʹ��,�ټ�!", , True
                ��������.Close
        Case Else
                ���Ʒ��� "200 "
        End Select
End Sub

Private Sub ��������_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        �ӵ���־ Number & ":" & Description
        ��������.Close
End Sub

Private Sub ��������_SendComplete()
        ������� = True
End Sub

Private Sub ���ӳ��Ŀ¼_Click()
        Dim s As New Shell
        Dim f As Folder
        Set f = s.BrowseForFolder(Me.hWnd, "���Ҫӳ��������Ŀ¼��Ŀ¼", 0)
        If Not f Is Nothing Then
                ӳ��Ŀ¼ = f.ParentFolder.ParseName(f).Path
        End If
End Sub

Private Sub ɾ��_Click()
        Dim li
        li = ����Ŀ¼��.ListIndex
        On Error Resume Next
        ����Ŀ¼��.RemoveItem ����Ŀ¼��.ListIndex
        ����Ŀ¼��.ListIndex = li
End Sub

Private Sub ��������_Close()
        ��������.Close
End Sub

Private Sub ��������_Connect()
        If �ȴ��������� <> "" Then
                ��������.SendData �ȴ���������
        End If
End Sub

Private Sub ��������_DataArrival(ByVal bytesTotal As Long)
        While Not ��������.State = sckConnected: DoEvents: Wend
        Dim buf As String
        ��������.GetData buf
        �������� = �������� & buf
End Sub

Private Sub ��������_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        �ӵ���־ "���ݴ���:" & Number & ":" & Description
        ��������.Close
End Sub

Private Sub ��������_SendComplete()
        ���ݷ������ = True
End Sub

Private Sub ���_Click()
        Dim x As ����Ŀ¼
        x.��������Ŀ¼��λ�� = ��������Ŀ¼
        x.���� = ����Ŀ¼��
        x.ӳ��Ŀ¼ = ӳ��Ŀ¼
        ����Ŀ¼��.AddItem ��������Ŀ¼(x)
End Sub

Private Sub ����Ŀ¼��_Click()
        Dim x As ����Ŀ¼
        x = ��������Ŀ¼(����Ŀ¼��.List(����Ŀ¼��.ListIndex))
        ��������Ŀ¼ = x.��������Ŀ¼��λ��
        ����Ŀ¼�� = x.����
        ӳ��Ŀ¼ = x.ӳ��Ŀ¼
End Sub

Public Sub �ӵ���־(s)
        ��־.AddItem "[" & Date & " " & Time & "] " & s & _
                        " (Զ������ " & ��������.RemoteHostIP & ":" & ��������.RemotePort & ")"
End Sub

Public Sub ���Ʒ���(s, Optional ���� As Boolean = True, Optional �ȴ� As Boolean = False)
        If �ȴ� Then ������� = False
        ��������.SendData s & IIf(����, vbNewLine, "")
        If �ȴ� Then
                While Not �������
                        DoEvents
                Wend
        End If
End Sub

Public Sub ���ݷ���(Ҫ���͵�����)
        ���ݷ������ = False

        ��������.Connect

        �ȴ��������� = Ҫ���͵�����
        While Not ���ݷ������
                DoEvents
        Wend
        �ȴ��������� = ""

        ��������.Close
End Sub

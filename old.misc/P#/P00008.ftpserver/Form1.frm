VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form Form1
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Form1"
   ClientHeight    =   5325
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   6795
   FillColor       =   &H00808080&
   ForeColor       =   &H00FFFFFF&
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   Picture         =   "Form1.frx":0000
   ScaleHeight     =   5325
   ScaleWidth      =   6795
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdupload
      Caption         =   "�ϴ�"
      Height          =   345
      Left            =   4695
      TabIndex        =   26
      Top             =   720
      Width           =   960
   End
   Begin VB.CommandButton cmddownload
      Caption         =   "����"
      Height          =   345
      Left            =   3630
      TabIndex        =   25
      Top             =   720
      Width           =   960
   End
   Begin VB.Timer Timer1
      Interval        =   1
      Left            =   4500
      Top             =   4170
   End
   Begin VB.CommandButton cmdclose
      Caption         =   "�Ͽ�"
      Height          =   345
      Left            =   2220
      TabIndex        =   10
      Top             =   720
      Width           =   960
   End
   Begin VB.CommandButton cmdconnect
      Caption         =   "����"
      Height          =   345
      Left            =   1185
      TabIndex        =   9
      Top             =   720
      Width           =   960
   End
   Begin VB.TextBox txtpassword
      Height          =   285
      Left            =   5010
      TabIndex        =   8
      Text            =   "abcd@abcd.com"
      Top             =   390
      Width           =   1620
   End
   Begin VB.TextBox txtuser
      Height          =   285
      Left            =   2175
      TabIndex        =   6
      Text            =   "anonymous"
      Top             =   360
      Width           =   1815
   End
   Begin VB.TextBox txtport
      Height          =   285
      Left            =   5970
      TabIndex        =   4
      Text            =   "21"
      Top             =   60
      Width           =   675
   End
   Begin VB.TextBox txtserver
      Height          =   285
      Left            =   2190
      TabIndex        =   2
      Text            =   "ftp.microsoft.com"
      Top             =   45
      Width           =   3165
   End
   Begin VB.CommandButton cmdbook
      Caption         =   "��������ַ��"
      Height          =   630
      Left            =   240
      TabIndex        =   0
      Top             =   195
      Width           =   735
   End
   Begin MSWinsockLib.Winsock sd
      Left            =   5670
      Top             =   4155
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
   Begin MSWinsockLib.Winsock sc
      Left            =   5100
      Top             =   4155
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
   Begin VB.Frame Frame2
      Caption         =   "Զ���ļ�"
      DragIcon        =   "Form1.frx":20654
      Height          =   4095
      Left            =   3210
      TabIndex        =   16
      Top             =   1110
      Width           =   3405
      Begin VB.CommandButton cmddeletefile
         Caption         =   "ɾ���ļ�"
         Height          =   360
         Left            =   2385
         TabIndex        =   24
         Top             =   3630
         Width           =   885
      End
      Begin VB.CommandButton Command2
         Caption         =   "ɾ��Ŀ¼"
         Height          =   360
         Left            =   1350
         TabIndex        =   22
         Top             =   3630
         Width           =   915
      End
      Begin VB.CommandButton cmdcreatedir
         Caption         =   "����Ŀ¼"
         Height          =   360
         Left            =   135
         TabIndex        =   21
         Top             =   3630
         Width           =   975
      End
      Begin VB.CommandButton Command1
         Caption         =   "����"
         Height          =   360
         Left            =   2670
         TabIndex        =   20
         Top             =   480
         Width           =   585
      End
      Begin VB.TextBox remotedir
         Height          =   345
         Left            =   120
         TabIndex        =   19
         Text            =   "/"
         Top             =   495
         Width           =   1845
      End
      Begin VB.CommandButton cdup
         Caption         =   "����"
         Height          =   360
         Left            =   2040
         TabIndex        =   18
         Top             =   480
         Width           =   585
      End
      Begin VB.ListBox remotefile
         DragIcon        =   "Form1.frx":2095E
         Height          =   2595
         Left            =   120
         TabIndex        =   14
         Top             =   900
         Width           =   3165
      End
      Begin VB.Label Label1
         AutoSize        =   -1  'True
         Caption         =   "��ǰĿ¼:"
         Height          =   180
         Left            =   120
         TabIndex        =   17
         Top             =   210
         Width           =   810
      End
   End
   Begin VB.Frame Frame1
      Caption         =   "�����ļ�"
      Height          =   4095
      Left            =   225
      TabIndex        =   15
      Top             =   1110
      Width           =   3000
      Begin VB.CommandButton Command3
         Caption         =   "ˢ��"
         Height          =   315
         Left            =   135
         TabIndex        =   23
         Top             =   3705
         Width           =   2715
      End
      Begin VB.FileListBox File1
         DragIcon        =   "Form1.frx":20C68
         Height          =   1845
         Left            =   120
         MultiSelect     =   2  'Extended
         TabIndex        =   13
         Top             =   1785
         Width           =   2745
      End
      Begin VB.DirListBox Dir1
         Height          =   1215
         Left            =   120
         TabIndex        =   12
         Top             =   540
         Width           =   2730
      End
      Begin VB.DriveListBox Drive1
         Height          =   315
         Left            =   120
         TabIndex        =   11
         Top             =   240
         Width           =   2760
      End
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "��¼����:"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   240
      Index           =   1
      Left            =   4050
      TabIndex        =   7
      Top             =   435
      Width           =   795
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "��¼�û�:"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   240
      Index           =   0
      Left            =   1275
      TabIndex        =   5
      Top             =   420
      Width           =   795
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "�˿�"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   240
      Left            =   5430
      TabIndex        =   3
      Top             =   90
      Width           =   375
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "��������ַ:"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   240
      Left            =   1110
      TabIndex        =   1
      Top             =   105
      Width           =   975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

'�Ƿ��Ѿ���������
Dim connected As Boolean
'���ƶ������Ƿ��Ѿ��������
Dim sent As Boolean
'���ƶ��Ƿ��Ѿ����յ�����
Dim received As Boolean
'���ݶ������Ƿ��Ѿ��������
Dim datasent As Boolean

'���ƶ˽��յ������ݻ���
Dim buf As String
'���ݶ˽��յ������ݻ���
Dim recvbuf As String

Dim r

'�������������sָ��Ҫ���͵����ݣ������������ݺ󣬷��ؽ��յ�������
Public Function process(s)
        '��ʼ������
        sent = False
        received = False

        '��Ҫ���͵�����ĩβ���ϻ����ٷ���
        sc.SendData s & vbNewLine
        '�ȴ��յ��ظ�
        While Not received
                DoEvents
        Wend
        process = buf
End Function

'׼�����ݶ��Խ���Զ������
Public Sub preparedata()
        '�ر����ݶ�׼������
        sd.Close
        sd.LocalPort = 0        '�Զ�����
        sd.Listen
        '��ȡ���ݶ˵ı���IP��ַ�Ͷ˿ں�
        Dim ips, ip1, ip2, ip3, ip4, port1, port2
        ips = Split(sd.LocalIP, ".")
        ip1 = ips(0)
        ip2 = ips(1)
        ip3 = ips(2)
        ip4 = ips(3)
        '���ֽ���ǰ��
        port1 = Int(sd.LocalPort / 256)
        port2 = sd.LocalPort Mod 256

        '�������ö˿�����
        r = process("PORT " & ip1 & "," & ip2 & "," & ip3 & "," & ip4 & "," & port1 & "," & port2)
        If Val(Left(r, 1)) >= 4 Then
                MsgBox "ִ��PORT�������:" & r
                Exit Sub
        End If

        '��ʼ�����ջ���
        recvbuf = ""
End Sub

'��ȡԶ��Ŀ¼,����Զ���ļ��б��
Public Sub readdir()

        r = process("PWD")
        remotedir = Split(r, """")(1)

        '��Ϊ��Ŀ¼��Ҫͨ��DTP��������׼�����ݶ�
        preparedata

        r = process("LIST")
        If Val(Left(r, 1)) >= 4 Then
                MsgBox "�޷��г�������Ŀ¼:" & r
                Exit Sub
        End If

        '�ȴ����ݶ˴������
        While sd.State <> sckClosed
                DoEvents
        Wend

        '�����յ������ݲ����������Ŀ¼��ʾ���б����
        Dim dirs As Collection
        Set dirs = getdirinfo(recvbuf)
        Dim i As DirItem
        remotefile.Clear
        For Each i In dirs
                '��ÿһ��Ŀ¼�������������ļ�����ʾ�ļ���С��
                '���������ƺ��渽��һ��"/"�ַ���
                If i.dsize >= 0 Then
                        remotefile.AddItem i.dname & ":" & i.dsize
                Else
                        remotefile.AddItem i.dname & "/"
                End If
        Next
End Sub

'����
Public Sub download(filename)
        '������Ʋ�����":"˵���������ļ�����Ŀ¼
        If InStr(filename, ":") <= 0 Then Exit Sub
        'ȡ����":"��ߵ��ַ�����Ϊ�ļ���
        filename = Left(filename, InStr(filename, ":") - 1)

        '׼�����ݶ�
        preparedata

        '���������ļ�����
        r = process("RETR " & filename)
        If Val(Left(r, 1)) >= 4 Then
                MsgBox "�޷������ļ���" & r
                Exit Sub
        End If
        '�ȴ����ݴ������
        While sd.State <> sckClosed
                DoEvents
        Wend

        ' ��recvbuf�����������ļ�
        Dim fn
        fn = FreeFile
        Open pathconj(Dir1.Path, filename) For Binary As fn
        Put fn, , recvbuf
        Close fn

End Sub

'�ϴ�������һ���ϴ�����ļ���filenames�����г�����Ҫ�ϴ����ļ�
Public Sub upload(filenames As Collection)
        Dim filename
        Dim fn
        For Each filename In filenames
                '׼�����ݶ�
                preparedata

                fn = FreeFile

                '���ļ��������ļ����ݶ��뵽filedata
                Open pathconj(Dir1.Path, filename) For Binary As fn
                '����һ�����飬����Ĵ�С�����ļ��ĳ���
                If LOF(fn) > 0 Then
                        ReDim filedata(1 To LOF(fn)) As Byte
                        Get fn, , filedata
                End If

                '�����ϴ�����
                r = process("STOR " & filename)
                If Val(Left(r, 1)) >= 4 Then
                        MsgBox "�޷��ϴ��ļ�:" & r
                        Exit Sub
                End If

                '�ȴ�Զ�̷��������ӵ��������ݶ�
                While sd.State <> sckConnected
                        DoEvents
                Wend

                If LOF(fn) > 0 Then
                        datasent = False
                        sd.SendData filedata
                        Close fn
                        While Not datasent
                                DoEvents
                        Wend
                End If

                sd.Close

        Next
End Sub

Private Sub cdup_Click()
        r = process("CDUP")
        If Val(Left(r, 1)) >= 4 Then
                MsgBox "�޷�������һ��Ŀ¼:" & r
                Exit Sub
        End If
        readdir
End Sub

'�����ַ������򿪵�ַ������
Private Sub cmdbook_Click()
        Dim c, i, s

        '��ע�������ַ��������Ϣ
        c = GetSetting("ftpc", "slist", "count", 0)
        Form2.lst.Clear
        For i = 0 To c - 1
                s = GetSetting("ftpc", "slist", "item_" & Trim(Str(i)), "")
                If s <> "" Then Form2.lst.AddItem s
        Next
        '��ʾ��ַ������,���û�ѡ��һ����������ַ,���������
        Form2.Show 1
        '�û�������غ��û�ѡ����Ǹ���������ַ��Ϊ��ǰҪ���ӵķ�����
        txtserver = Form2.txt(0)
        txtport = Form2.txt(1)
        txtuser = Form2.txt(2)
        txtpassword = Form2.txt(3)
End Sub

'����Ͽ���ť���رտ��ƶ�
Private Sub cmdclose_Click()
        sc.Close
End Sub

'������ӽ����ӵ�ָ��������
Private Sub cmdconnect_Click()
        sc.Close
        sc.LocalPort = 0
        sc.RemoteHost = txtserver
        sc.RemotePort = txtport

        '��ʼ������
        connected = False
        sc.Connect
        '�ȴ����ӱ���������
        While Not connected
                DoEvents
        Wend

        '���͵�¼�û�������
        r = process("USER " & txtuser)
        If Val(Left(r, "1")) >= 4 Then
                MsgBox "��¼�û����������ܾ�:" & r
                Exit Sub
        End If
        '���͵�¼��������
        r = process("PASS " & txtpassword)
        If Val(Left(r, "1")) >= 4 Then
                MsgBox "������Ч:" & r
                Exit Sub
        End If

        '�г�������Ŀ¼
        readdir
End Sub

Private Sub cmdcreatedir_Click()
        Dim nn
        nn = InputBox("������Ҫ������Ŀ¼����")
        If nn <> "" Then
                r = process("MKD " & nn)
                If Val(Left(r, 1)) >= 4 Then
                        MsgBox "���ܽ���Ŀ¼:" & r
                        Exit Sub
                End If
        End If
        readdir
End Sub

Private Sub cmddeletefile_Click()
        ' ֻ��ɾ���ļ�
        If InStr(remotefile.Text, ":") > 0 Then
                Dim nn
                '
                nn = Left(remotefile.Text, InStr(remotefile.Text, ":") - 1)
                r = process("DELE " & nn)
                If Val(Left(r, 1)) >= 4 Then MsgBox "ɾ���ļ�����" & r

                readdir
        End If
End Sub

Private Sub cmddownload_Click()
        File1_DragDrop remotefile, 0, 0
End Sub

Private Sub cmdupload_Click()
        remotefile_DragDrop File1, 0, 0
End Sub

'������°�ť�����¶��������Ŀ¼
Private Sub Command1_Click()
        readdir
End Sub

Private Sub Command2_Click()
        ' ֻ��ɾ��Ŀ¼
        If InStr(remotefile.Text, "/") > 0 Then
                Dim nn
                '
                nn = Left(remotefile.Text, InStr(remotefile.Text, "/") - 1)
                r = process("RMD " & nn)
                If Val(Left(r, 1)) >= 4 Then MsgBox "ɾ��Ŀ¼����" & r
                readdir
        End If
End Sub

'���ˢ�°�ť��ˢ�±����ļ�Ŀ¼
Private Sub Command3_Click()
        File1.Refresh
End Sub

Private Sub Dir1_Change()
        File1.Path = Dir1.Path
End Sub

Private Sub Drive1_Change()
        Dir1.Path = Drive1.Drive
End Sub

Private Sub File1_DragDrop(Source As Control, X As Single, Y As Single)
'�ѷ�����Ŀ¼�����ϳ������ļ��ڱ����ļ��б��зſ�����˵������
        Dim filename
        filename = Source.Text
        download filename
        File1.Refresh
End Sub

Private Sub File1_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        '����ڱ����ļ��б��а�������Ҽ���ʼ�϶�
        If Button = vbRightButton Then
                File1.Drag
        End If
End Sub

Private Sub Form_Load()
        '��������ʱ����ע����ж�����һ�α���ķ�����������Ϣ
        txtserver = GetSetting("ftpc", "frmmain", "txtserver", "ftp.microsoft.com")
        txtport = GetSetting("ftpc", "frmmain", "txtport", "21")
End Sub

Private Sub Form_Unload(Cancel As Integer)
        '�����˳�ʱ����������������Ϣ���浽ע���
        SaveSetting "ftpc", "frmmain", "txtserver", txtserver
        SaveSetting "ftpc", "frmmain", "txtport", txtport
End Sub

Private Sub remotedir_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                '����ڵ�ǰĿ¼���ı����а��»س���
                '������ڸ��ı����е��ı��ı䵱ǰĿ¼
                KeyAscii = 0
                r = process("CWD " & remotedir)
                If Val(Left(r, 1)) >= 4 Then
                        MsgBox "�޷�����Ŀ¼:" & r
                        Exit Sub
                End If
                readdir
        End If
End Sub

'�����Զ���ļ��б���˫�����ʾ����ѡ�е�Ŀ¼
Private Sub remotefile_DblClick()
        If InStr(remotefile.Text, "/") <= 0 Then Exit Sub  ' ����Ŀ¼���˳�
        'ȡѡ��Ŀ¼"/"��ߵ��ַ���
        Dim n
        n = Left(remotefile.Text, InStr(remotefile.Text, "/") - 1)
        '���͸ı䵱ǰĿ¼����
        r = process("CWD " & n)
        If Val(Left(r, 1)) >= 4 Then
                MsgBox "�޷�����Ŀ¼:" & r
                Exit Sub
        End If
        readdir
End Sub

'��ʾ�϶���Զ���ļ��б��зſ�����ʾ�ϴ��ļ�
Private Sub remotefile_DragDrop(Source As Control, X As Single, Y As Single)
        Dim filenames As New Collection
        Dim i
        '�������ļ��б����ѡ�е���һ������ӵ�filenames������
        For i = 0 To Source.ListCount - 1
                If Source.Selected(i) Then filenames.Add Source.List(i)
        Next
        '�ٵ����ϴ�����
        upload filenames
        readdir
End Sub

Private Sub remotefile_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        '��Զ���ļ��б��а�������Ҽ���ʼ�϶�
        If Button And vbRightButton Then remotefile.Drag
End Sub

Private Sub sc_Connect()
        '���������ӽ�������ʱ������ �����ѽ��� ����Ϊtrue
        connected = True
End Sub

'���ƶ��յ�����
Private Sub sc_DataArrival(ByVal bytesTotal As Long)
        While sc.State <> sckConnected: DoEvents: Wend
        '��ȡ�յ������ݷ���buf
        sc.GetData buf
        received = True
End Sub

'�����ƶ˷�������
Private Sub sc_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        MsgBox Description
        '��������ʱ�رտ��ƶ�
        sc.Close
End Sub

'�����ƶ����ݷ������
Private Sub sc_SendComplete()
        sent = True
End Sub

'��Զ�����ݶ��Ѿ��ر�
Private Sub sd_Close()
        sd.Close
End Sub

'���ݶ��յ���������
Private Sub sd_ConnectionRequest(ByVal requestID As Long)
        sd.Close
        sd.Accept requestID
End Sub

'���ݶ��յ����ݣ������ݱ��浽recvbuf
Private Sub sd_DataArrival(ByVal bytesTotal As Long)
        Dim data As String
        While sd.State <> sckConnected: DoEvents: Wend
        sd.GetData data
        recvbuf = recvbuf & data
End Sub

'���ݶ˷��ʹ��󣬵���һ����Ϣ�򣬲��ر���������
Private Sub sd_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        MsgBox Description
        sd.Close
End Sub

Private Sub sd_SendComplete()
        datasent = True
End Sub

Private Sub txtport_Validate(Cancel As Boolean)
    '�˿ڲ���Ϊ�գ��ұ�������ֵ
    If txtport = "" Then
        MsgBox "������˿�"
        Cancel = True
        ElseIf Not IsNumeric(txtport) Then
         MsgBox "��������ֵ"
         Cancel = True
    End If

End Sub

Private Sub txtserver_Validate(Cancel As Boolean)
    '��������ַ����Ϊ��
     If txtserver = "" Then
         MsgBox "�������������ַ"
        Cancel = True
    End If
End Sub

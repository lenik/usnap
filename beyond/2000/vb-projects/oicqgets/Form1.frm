VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   6270
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7050
   LinkTopic       =   "Form1"
   ScaleHeight     =   6270
   ScaleWidth      =   7050
   StartUpPosition =   3  '����ȱʡ
   Begin VB.CommandButton cmdStop
      Caption         =   "ֹͣ"
      Height          =   495
      Left            =   3840
      TabIndex        =   16
      Top             =   240
      Width           =   1455
   End
   Begin VB.ListBox lstQues
      Height          =   1320
      Left            =   240
      TabIndex        =   15
      Top             =   4680
      Width           =   6615
   End
   Begin VB.TextBox txtArrival
      Height          =   2535
      Left            =   3840
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   13
      Top             =   1680
      Width           =   3015
   End
   Begin VB.CommandButton cmdGet
      Caption         =   "&G��ȡ"
      Height          =   375
      Left            =   2280
      TabIndex        =   11
      Top             =   3240
      Width           =   1455
   End
   Begin VB.CommandButton cmdClear
      Caption         =   "&C���"
      Height          =   375
      Left            =   2280
      TabIndex        =   10
      Top             =   2520
      Width           =   1455
   End
   Begin VB.CommandButton cmdDel
      Caption         =   "ɾ��"
      Height          =   375
      Left            =   2280
      TabIndex        =   9
      Top             =   1920
      Width           =   1455
   End
   Begin VB.TextBox txt1
      Height          =   375
      Left            =   240
      TabIndex        =   8
      Text            =   "Text2"
      Top             =   3960
      Width           =   1935
   End
   Begin VB.ListBox lstIDs
      Height          =   1860
      ItemData        =   "Form1.frx":0000
      Left            =   240
      List            =   "Form1.frx":0013
      TabIndex        =   7
      Top             =   1920
      Width           =   1935
   End
   Begin VB.TextBox txtRemote
      Height          =   375
      Left            =   1080
      TabIndex        =   3
      Text            =   "service.tencent.com"
      Top             =   840
      Width           =   4335
   End
   Begin VB.TextBox txtLocal
      Height          =   375
      Left            =   1080
      TabIndex        =   1
      Text            =   "1000"
      Top             =   360
      Width           =   1695
   End
   Begin MSWinsockLib.Winsock sock
      Left            =   3120
      Top             =   360
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      RemotePort      =   80
      LocalPort       =   1001
   End
   Begin VB.Label ��ȡ�����б�
      Caption         =   "��ȡ�����б�"
      Height          =   255
      Left            =   2400
      TabIndex        =   14
      Top             =   4320
      Width           =   1095
   End
   Begin VB.Label �������
      AutoSize        =   -1  'True
      Caption         =   "�������"
      Height          =   180
      Left            =   3960
      TabIndex        =   12
      Top             =   1320
      Width           =   720
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      Caption         =   "��������ʾ����"
      Height          =   180
      Left            =   1920
      TabIndex        =   6
      Top             =   1440
      Width           =   1260
   End
   Begin VB.Label lblID
      AutoSize        =   -1  'True
      Caption         =   "Label4"
      Height          =   180
      Left            =   1200
      TabIndex        =   5
      Top             =   1440
      Width           =   540
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "��������"
      Height          =   180
      Left            =   360
      TabIndex        =   4
      Top             =   1440
      Width           =   720
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "&RԶ������"
      Height          =   180
      Left            =   120
      TabIndex        =   2
      Top             =   840
      Width           =   810
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "&L���ض˿�"
      Height          =   180
      Left            =   120
      TabIndex        =   0
      Top             =   480
      Width           =   810
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Public currentoicq As Long
Public thisend As Boolean       ' ����, ��һ������ȴ�
Public breakall As Boolean      ' ����, �ô����ж�
Public noignore As Boolean      ' ���ϸ񲶻�

Public Sub pass(ByVal oicq As Long)

    lblID = oicq
    sock.LocalPort = Val(txtLocal)
    currentoicq = oicq
    txtArrival = ""

    thisend = False
    sock.Connect txtRemote.Text, 80

    While Not thisend
        DoEvents
    Wend
End Sub

Private Sub cmdClear_Click()
    lstIDs.Clear
End Sub

Private Sub cmdDel_Click()
    If lstIDs.ListIndex >= 0 Then
        lstIDs.RemoveItem lstIDs.ListIndex
    End If
End Sub

Private Sub cmdGet_Click()
    Dim i As Long, j As Long
    Dim c As String

    breakall = False

    For i = 0 To lstIDs.ListCount - 1
        If breakall Then Exit For
        c = lstIDs.List(i)
        ' ����icq����
        If InStr(c, "-") < 0 Then
            pass Val(c)
        Else
            For j = Val(c) To Val(Mid(c, InStr(c, "-") + 1))
                pass j
                If breakall Then Exit For
            Next
        End If
    Next
End Sub

Private Sub cmdStop_Click()
    breakall = True
End Sub

Private Sub Form_Load()
    thisend = False
    DoEvents
    sock.LocalPort = Val(txtLocal.Text)
End Sub

Private Sub sock_Close()
    sock.Close
    thisend = True
    breakall = False

    If InStr(txtArrival, "ϵͳæ") Then
        Exit Sub
    End If

    If InStr(txtArrival, "����ʱ��û���������뱣��") Then
        lstQues.AddItem currentoicq & ":û����"
    Else
        lstQues.AddItem currentoicq & ":ʲô���⣿"
    End If
    lstQues.ListIndex = lstQues.ListCount - 1

End Sub

Private Sub sock_Connect()
    ' ��Զ�������ɹ�����, ����HTTP�����ı���ȡ����
    Dim httpreq As String

    'service.tencent.com/cgi-bin/reg/remember
    httpreq = ""
    httpreq = _
            "POST http://service.tencent.com/cgi-bin/reg/remember HTTP/1.1" & vbNewLine & _
            "Accept: */*" & vbNewLine & _
            "Accept -Language: zh -cn" & vbNewLine & _
            "Content-Type: application/x-www-form-urlencoded" & vbNewLine & _
            "Accept -Encoding: gzip , deflate" & vbNewLine & _
            "User-Agent: Mozilla/4.0 (compatible; MSIE 5.5; Windows 98)" & vbNewLine & _
            "Host: ljb:1000" & vbNewLine & _
            "Content-Length: " & 11 + Len(LTrim(Str(currentoicq))) & vbNewLine & _
            "Connection: Keep -Alive" & vbNewLine & _
            "Cookie: YourName=linjian; YourWork=%C6%F3%D2%B5%D4%B1%B9%A4; YourSex=%C5%AE%CA%BF" & vbNewLine & _
            vbNewLine & _
            "uin=" & currentoicq & "&step=1" & vbNewLine

    sock.SendData httpreq
End Sub

Private Sub sock_DataArrival(ByVal bytesTotal As Long)
    Dim buf As String * 60000
    While bytesTotal > 60000
        sock.GetData buf, , 60000
        bytesTotal = bytesTotal - 60000
    Wend
    sock.GetData buf, , 60000
    txtArrival.Text = txtArrival.Text & Left(buf, bytesTotal) & vbNewLine

End Sub

Private Sub sock_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    If Description = "��ַ����ʹ��" Then
        txtLocal = Trim(Val(txtLocal) + 1)
    End If
    MsgBox Description
    sock.Close
End Sub

Private Sub txt1_KeyPress(KeyAscii As Integer)
    If KeyAscii = 13 Then
        lstIDs.AddItem txt1
        txt1 = ""
    End If
End Sub

Private Sub txtLocal_KeyPress(KeyAscii As Integer)
    If KeyAscii = 13 Then
        sock.LocalPort = Val(txtLocal)
    End If
End Sub

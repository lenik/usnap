VERSION 5.00
Begin VB.Form frmManager
   Caption         =   "��س���"
   ClientHeight    =   5085
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   9495
   Icon            =   "f2Manager.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   5085
   ScaleWidth      =   9495
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox picHead
      AutoSize        =   -1  'True
      BorderStyle     =   0  'None
      Height          =   480
      Left            =   120
      Picture         =   "f2Manager.frx":0E42
      ScaleHeight     =   480
      ScaleWidth      =   5280
      TabIndex        =   40
      Top             =   5100
      Visible         =   0   'False
      Width           =   5280
   End
   Begin VB.Frame frameScript
      Caption         =   "&CԶ�̿��Ƽ��߼�����"
      ForeColor       =   &H000000C0&
      Height          =   3855
      Left            =   6900
      TabIndex        =   26
      Top             =   120
      Width           =   2475
      Begin VB.CommandButton cmdExec
         Caption         =   "&Zִ��"
         Height          =   315
         Left            =   180
         TabIndex        =   31
         Top             =   3420
         Width           =   2175
      End
      Begin VB.TextBox txtScript
         Height          =   2055
         Left            =   180
         MultiLine       =   -1  'True
         TabIndex        =   30
         Top             =   1320
         Width           =   2175
      End
      Begin VB.ComboBox cboDefaultScript
         Height          =   300
         ItemData        =   "f2Manager.frx":9286
         Left            =   180
         List            =   "f2Manager.frx":9299
         Style           =   2  'Dropdown List
         TabIndex        =   28
         Top             =   600
         Width           =   2175
      End
      Begin VB.Label Label5
         AutoSize        =   -1  'True
         Caption         =   "&O���ο���"
         Height          =   180
         Left            =   180
         TabIndex        =   29
         Top             =   1020
         Width           =   810
      End
      Begin VB.Label Label4
         AutoSize        =   -1  'True
         Caption         =   "&PԤ�������"
         Height          =   180
         Left            =   180
         TabIndex        =   27
         Top             =   300
         Width           =   990
      End
   End
   Begin VB.Frame Frame5
      Caption         =   "&N����"
      ForeColor       =   &H00800000&
      Height          =   3855
      Left            =   2820
      TabIndex        =   13
      Top             =   120
      Width           =   4035
      Begin VB.CommandButton cmdQueryResult
         Caption         =   "&W��ϸ�ɼ�"
         Height          =   315
         Left            =   2100
         TabIndex        =   23
         Top             =   2700
         Width           =   1635
      End
      Begin VB.CommandButton cmdManualCreate
         Caption         =   "&M�ֹ�����"
         Height          =   315
         Left            =   2100
         TabIndex        =   22
         Top             =   2340
         Width           =   1635
      End
      Begin VB.CommandButton cmdSendMessage
         Caption         =   "&F������Ϣ"
         Height          =   315
         Left            =   2100
         TabIndex        =   24
         Top             =   3060
         Width           =   1635
      End
      Begin VB.CommandButton cmdCancelID
         Caption         =   "&Qǿ��ȡ��"
         Height          =   315
         Left            =   2100
         TabIndex        =   25
         Top             =   3420
         Width           =   1650
      End
      Begin VB.ListBox lstJoinerView
         Height          =   3180
         Left            =   120
         TabIndex        =   15
         Top             =   480
         Width           =   1815
      End
      Begin VB.Line Line2
         BorderColor     =   &H00FFFFFF&
         X1              =   1980
         X2              =   3840
         Y1              =   2280
         Y2              =   2280
      End
      Begin VB.Line Line1
         BorderColor     =   &H00FFFFFF&
         X1              =   1980
         X2              =   1980
         Y1              =   405
         Y2              =   3730
      End
      Begin VB.Label eleInfo
         AutoSize        =   -1  'True
         Caption         =   "״̬"
         ForeColor       =   &H00008000&
         Height          =   180
         Index           =   5
         Left            =   2100
         TabIndex        =   21
         Top             =   1980
         Width           =   360
      End
      Begin VB.Label eleInfo
         AutoSize        =   -1  'True
         Caption         =   "��ǰ��ȷ��"
         ForeColor       =   &H00008000&
         Height          =   180
         Index           =   4
         Left            =   2100
         TabIndex        =   20
         Top             =   1680
         Width           =   900
      End
      Begin VB.Label eleInfo
         AutoSize        =   -1  'True
         Caption         =   "��ǰ�ٶ�"
         ForeColor       =   &H00008000&
         Height          =   180
         Index           =   3
         Left            =   2100
         TabIndex        =   19
         Top             =   1380
         Width           =   720
      End
      Begin VB.Label eleInfo
         AutoSize        =   -1  'True
         Caption         =   "����"
         ForeColor       =   &H00008000&
         Height          =   180
         Index           =   2
         Left            =   2100
         TabIndex        =   18
         Top             =   1080
         Width           =   360
      End
      Begin VB.Label eleInfo
         AutoSize        =   -1  'True
         Caption         =   "IP��ַ"
         ForeColor       =   &H00008000&
         Height          =   180
         Index           =   1
         Left            =   2100
         TabIndex        =   17
         Top             =   780
         Width           =   540
      End
      Begin VB.Label eleInfo
         AutoSize        =   -1  'True
         Caption         =   "����λ��"
         ForeColor       =   &H00008000&
         Height          =   180
         Index           =   0
         Left            =   2100
         TabIndex        =   16
         Top             =   480
         Width           =   720
      End
      Begin VB.Label ��Ϣ
         AutoSize        =   -1  'True
         Caption         =   "��Ϣ"
         ForeColor       =   &H00404000&
         Height          =   180
         Left            =   3360
         TabIndex        =   36
         Top             =   240
         Width           =   360
      End
      Begin VB.Label Label6
         AutoSize        =   -1  'True
         Caption         =   "���β��Բ�����Ա"
         ForeColor       =   &H00800000&
         Height          =   180
         Left            =   120
         TabIndex        =   14
         Top             =   240
         Width           =   1440
      End
   End
   Begin VB.Frame Frame4
      Height          =   975
      Left            =   120
      TabIndex        =   32
      Top             =   4020
      Width           =   9300
      Begin VB.Timer timerDispatch
         Enabled         =   0   'False
         Interval        =   1
         Left            =   4080
         Top             =   240
      End
      Begin VB.CommandButton cmdEnd
         Caption         =   "&X�������"
         Height          =   495
         Left            =   2700
         TabIndex        =   35
         Top             =   300
         Width           =   1215
      End
      Begin VB.CommandButton cmdJoinWindow
         Caption         =   "&M�ı�ģʽ"
         Height          =   495
         Left            =   1440
         TabIndex        =   34
         Top             =   300
         Width           =   1155
      End
      Begin VB.CommandButton cmdStart
         Caption         =   "&S��ʼ����"
         Height          =   495
         Left            =   180
         TabIndex        =   33
         Top             =   300
         Width           =   1155
      End
      Begin VB.Label Label10
         AutoSize        =   -1  'True
         Caption         =   "δע��汾"
         BeginProperty Font
            Name            =   "����"
            Size            =   15
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00808080&
         Height          =   300
         Left            =   5820
         TabIndex        =   39
         Top             =   300
         Width           =   1500
      End
      Begin VB.Label Label7
         AutoSize        =   -1  'True
         Caption         =   "�������������, ��ע��.   л����/��ԭ��� ��Ȩ���� 2001"
         ForeColor       =   &H00404040&
         Height          =   180
         Left            =   4080
         TabIndex        =   38
         Top             =   720
         Width           =   4950
      End
   End
   Begin VB.Frame Frame2
      Caption         =   "&S��������"
      ForeColor       =   &H00800000&
      Height          =   3855
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   2655
      Begin VB.CommandButton cmdDataSetup
         Caption         =   "&D��������"
         Height          =   375
         Left            =   120
         TabIndex        =   10
         Top             =   2460
         Width           =   2355
      End
      Begin VB.CommandButton cmdCancelChannel
         Caption         =   "&Nȡ��Ƶ��"
         Height          =   375
         Left            =   120
         TabIndex        =   12
         Top             =   3300
         Width           =   2355
      End
      Begin VB.CommandButton cmdCreateChannel
         Caption         =   "&C����Ƶ��"
         Height          =   375
         Left            =   120
         TabIndex        =   11
         Top             =   2880
         Width           =   2355
      End
      Begin VB.TextBox txtChannel
         Appearance      =   0  'Flat
         ForeColor       =   &H00404000&
         Height          =   315
         Left            =   240
         MaxLength       =   16
         TabIndex        =   7
         Top             =   1680
         Width           =   2175
      End
      Begin VB.Frame Frame1
         Caption         =   "&M�࿼����Ϣ"
         ForeColor       =   &H00800000&
         Height          =   1035
         Left            =   180
         TabIndex        =   1
         Top             =   240
         Width           =   2355
         Begin VB.TextBox txtMonitor
            Appearance      =   0  'Flat
            ForeColor       =   &H00800000&
            Height          =   315
            Left            =   660
            MaxLength       =   8
            TabIndex        =   3
            Top             =   240
            Width           =   1575
         End
         Begin VB.TextBox txtGroup
            Appearance      =   0  'Flat
            ForeColor       =   &H00800000&
            Height          =   315
            Left            =   660
            MaxLength       =   8
            TabIndex        =   5
            Top             =   600
            Width           =   1575
         End
         Begin VB.Label Label1
            AutoSize        =   -1  'True
            Caption         =   "����"
            ForeColor       =   &H00800000&
            Height          =   180
            Left            =   120
            TabIndex        =   2
            Top             =   360
            Width           =   360
         End
         Begin VB.Label Label2
            AutoSize        =   -1  'True
            Caption         =   "����"
            ForeColor       =   &H00800000&
            Height          =   180
            Left            =   120
            TabIndex        =   4
            Top             =   720
            Width           =   360
         End
      End
      Begin VB.TextBox txtTime
         Appearance      =   0  'Flat
         ForeColor       =   &H00404000&
         Height          =   315
         Left            =   1260
         MaxLength       =   4
         TabIndex        =   9
         Top             =   2100
         Width           =   975
      End
      Begin VB.Label Label9
         AutoSize        =   -1  'True
         Caption         =   "��"
         ForeColor       =   &H00800000&
         Height          =   180
         Left            =   2340
         TabIndex        =   37
         Top             =   2220
         Width           =   180
      End
      Begin VB.Label Label8
         AutoSize        =   -1  'True
         Caption         =   "&NƵ������"
         ForeColor       =   &H00800000&
         Height          =   180
         Left            =   240
         TabIndex        =   6
         Top             =   1440
         Width           =   810
      End
      Begin VB.Label Label3
         AutoSize        =   -1  'True
         Caption         =   "&T����ʱ��"
         ForeColor       =   &H00800000&
         Height          =   180
         Left            =   240
         TabIndex        =   8
         Top             =   2220
         Width           =   810
      End
   End
End
Attribute VB_Name = "frmManager"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Running As Boolean

Public AllContent As String

Public Function JoinerExisted(ByVal joiner As String) As Boolean
        Dim I As Integer
        JoinerExisted = False
        With lstJoinerView
                For I = 0 To .ListCount - 1
                        If .List(I) = storeAddr(joiner) Then
                                JoinerExisted = True
                                Exit For
                        End If
                Next
        End With
End Function

Public Function Join(ByVal joiner As String) As Boolean
        If JoinerExisted(joiner) Then
                Join = False
        Else
                lstJoinerView.AddItem storeAddr(joiner)
                Join = True
        End If
End Function

Public Sub CancelJoiner(ByVal joiner As String)
        Dim I As Integer
        With lstJoinerView
                For I = 0 To .ListCount - 1
                        If joiner = .List(I) Or joiner = storeCAddr(.List(I)) Then
                                .RemoveItem I
                                Exit For
                        End If
                Next
        End With
End Sub

Private Sub cboDefaultScript_Click()
        Select Case cboDefaultScript.text
        Case "����Ļ�ϵ�ѩ��"
                txtScript = "snow.visible=true" & vbNewLine & _
                                "for y=0 to 300" & vbNewLine & _
                                vbTab & "tleft=320+100*sin(y/50)" & vbNewLine & _
                                vbTab & "ttop=y" & vbNewLine & _
                                vbTab & "snow.left=tleft*15" & vbNewLine & _
                                vbTab & "snow.top=ttop*15" & vbNewLine & _
                                vbTab & "c.Events" & vbNewLine & _
                                "next" & vbNewLine & _
                                "snow.visible=false"
        Case "���ѿ�ʼ"
                txtScript = "c.Out ""��Ҫ��ʼ��, ������׼��!"""
        Case "�ػ�"
                txtScript = "c.ShutDown"
        Case "�����������"
                txtScript = "c.Out ""�밴���������"""
        Case "�������"
                Select Case Int(Rnd * 4)
                Case 0: txtScript = "c.Out ""��֪����ԭ���ԭ����ʲô? �ҿ������! """
                Case 1: txtScript = "c.Out ""Ϊʲô��ԭ���û�в���DirectX����? ������Ϊ��ԭ���ӵ���Լ�������ͼ���������������! """
                Case 2: txtScript = "c.Out ""��һ����֪��Pa���԰�, ���ǲ�ԭ����Լ�������! """
                Case Else: txtScript = "c.Out ""��һ�μ�β��ϯ, ��ס���ϲ�ԭ���, ��������������������������!"""
                End Select
        End Select
End Sub

Private Sub cmdCancelChannel_Click()
        If Not hasBeenCreated Then
                MsgBox "Ƶ����δ����, ���Ƚ���"
        Else
                Dim ListText As String
                frmWaitingBox.TurnOn "׼��ȡ���Ѳ�����Ա"
                With lstJoinerView
                        Do While .ListCount > 0
                                ListText = .List(.ListCount - 1)
                                .RemoveItem .ListCount - 1
                                frmWaitingBox.SetInfo "����ȡ��" & storeDispAddr(ListText)
                                FN_TextIO cAddrHost(storeCAddr(ListText)), "FING #JOINER CANCELED"
                        Loop
                End With
                frmWaitingBox.TurnOff
                hasBeenCreated = False
        End If
End Sub

Private Sub cmdCancelID_Click()
        FN_TextIO cAddrHost(storeCAddr(lstJoinerView.text)), "FING #JOINER CANCELED"
        CancelJoiner lstJoinerView.text
End Sub

Private Sub cmdCreateChannel_Click()
        If hasBeenCreated Then
                MsgBox "Ƶ���Ѿ�����, ����ȡ��"
        Else
                fingerRunServer = True
                With fingerServer
                        .Monitor = txtMonitor
                        .Group = txtGroup
                        .Channel = txtChannel
                        .TestTime = val(txtTime)
                        .HostName = SockClient.LocalHostName
                        .HostIP = SockClient.LocalIP
                End With
                fingerClient.Status = "���ڼ��..."
                hasBeenCreated = True
        End If
End Sub

Private Sub cmdDataSetup_Click()
        AllContent = frmDataSetup.Run
End Sub

Private Sub cmdEnd_Click()
        If Running Then
                MsgBox "���ڲ�����, �����ܽ������", vbOKOnly, "δע��汾"
        Else
                frmMain.Show
                Me.Hide
        End If
End Sub

Private Sub cmdExec_Click()
        Finger_DispatchText lstJoinerView, "SCRP " & txtScript, "���ڷ��������%%%...", True
End Sub

Private Sub cmdExecPredefined_Click()

End Sub

Private Sub cmdJoinWindow_Click()
        If Not hasBeenCreated Then
                frmApply.Show
                frmManager.Hide
                hasBeenCreated = False
        Else
                MsgBox "���Ѿ�����Ƶ��, Ҫ�ĳɲ����߱������ȳ���Ƶ��."
        End If
End Sub

Private Sub cmdManualCreate_Click()
        Dim clientname As String, clienthost As String
        Dim I As Integer
        Dim r As String, Ri As String
        r = InputBox("����������ߵ����ƺ���������, �ö��Ÿ���. " & vbNewLine & _
                        "���ͬʱ�����������, ��������֮���÷ֺŸ���. " & vbNewLine & _
                        "��: С��,loca;С��,locb;С��,locx", "�˹�����")
        I = 0
        Do
                Ri = lt_s.decodePart(r, I, False, ";")
                If Ri = "" Then Exit Do
                clientname = Trim(lt_s.decodePart(Ri, 0, False, ","))
                clienthost = Trim(lt_s.decodePart(Ri, 1, False, ","))
                If Len(clientname) < 3 Or clienthost = "" Then
                        MsgBox "����: [" & clientname & "@" & clienthost & "] ��Ч. " & vbNewLine & "�����ǲ���������̫�̻���������������. "
                Else
                        Join cAddr(clientname, clienthost)
                End If
                I = I + 1
        Loop
End Sub

Private Sub cmdQueryResult_Click()
        Dim sd As String
        Dim host As String
        Dim cr As COMPRESULT

        host = cAddrHost(storeCAddr(lstJoinerView.text))
        sd = FN_TextIO(host, "FING #QUERY COMPRESULT")
        cr = decodeCompResult(lt_s.decodePart(sd, 2))

        MsgBox storeDispAddr(lstJoinerView.text) & "�Ĳ��Խ��:" & vbNewLine & _
                "��ȷ: " & cr.Right & vbNewLine & _
                "����: " & cr.wrong & vbNewLine & _
                "����: " & cr.extra & vbNewLine & _
                "ȱ��: " & cr.lost & vbNewLine & _
                "-------------------"
End Sub

Private Sub cmdSendMessage_Click()
        Dim sendmsg As String
        Dim host As String

        host = cAddrHost(storeCAddr(lstJoinerView.text))
        sendmsg = InputBox("������Ҫ���͵���Ϣ(�ű���###��ͷ): ", "������Ϣ", "���")
        If Left(sendmsg, 3) = "###" Then
                FN_ScriptIO host, Mid(sendmsg, 4)
        Else
                FN_TextIO host, "FING #DISPLAY MESSAGE" & lt_s.encodePart(sendmsg)
        End If
End Sub

Private Sub cmdStart_Click()
        Finger_DispatchText lstJoinerView, "FING #START" & lt_s.encodePart(AllContent), "���ڷ��Ͳ������ݸ�%%%..."
End Sub

Private Sub timerDispatch_Timer()
        Dim dispAll As String
        Dim curDispatch As String
        Dim I As Integer
        ' ��ΪdispatchLater������, �������ݸ�һ�к��������ܸı��ڲ�����
        dispAll = dispatchLater
        curDispatch = LTrim(lt_s.departPart(dispAll, 1))
        dispatchLater = dispAll

        FN_WaitForSession FN_SERVER

        If curDispatch = "" Then
                dispatchLater = ""
                timerDispatch.Enabled = False
        Else
                With lstJoinerView
                        If Left(curDispatch, 4) = "SCRP" Then
                                For I = 0 To .ListCount - 1
                                        FN_ScriptIO cAddrHost(storeCAddr(.List(I))), Mid(curDispatch, 5)
                                Next
                                If debugMode Then script.ExecuteStatement Mid(curDispatch, 5)
                        Else
                                For I = 0 To .ListCount - 1
                                        FN_TextIO cAddrHost(storeCAddr(.List(I))), curDispatch
                                Next
                        End If
                End With
        End If
End Sub

Private Sub Form_GotFocus()
        fingerClient.Status = "�ڼ��..."
End Sub

Private Sub Form_Load()
        hasBeenCreated = False
        Running = False
        cboDefaultScript.ListIndex = 0
        txtMonitor = GetSetting(FingerRoot, "����Ա", "����", "")
        txtGroup = GetSetting(FingerRoot, "����Ա", "����", "")
        txtChannel = GetSetting(FingerRoot, "����Ա", "Ƶ������", "")
        txtTime = GetSetting(FingerRoot, "����Ա", "����ʱ��", 600)
        txtScript = GetSetting(FingerRoot, "����Ա", "���ο���", txtScript)
End Sub

Private Sub Form_Resize()
        If width < 9420 Then
                width = 9420
        Else
                frameScript.width = width - frameScript.Left - 200
                cboDefaultScript.width = frameScript.width - 360
                txtScript.width = frameScript.width - 360
                cmdExec.width = frameScript.width - 360
        End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
        If Running Then
                MsgBox "���ڲ�����, �����ܹرձ�����, ���򽫷�������Ԥ��Ĺ���"
                Cancel = 1
        Else
                SaveSetting FingerRoot, "����Ա", "����", txtMonitor
                SaveSetting FingerRoot, "����Ա", "����", txtGroup
                SaveSetting FingerRoot, "����Ա", "Ƶ������", txtChannel
                SaveSetting FingerRoot, "����Ա", "����ʱ��", txtTime
                SaveSetting FingerRoot, "����Ա", "���ο���", txtScript
                frmMain.Show
        End If
End Sub

Private Sub lstJoinerView_Click()
        Dim ListText As String
        Dim joinerInfo As String
        Dim joinerInfoStruct As FINGER_CLIENT

        If lstJoinerView.ListIndex < 0 Then Exit Sub

        ListText = lstJoinerView.text

        joinerInfo = FN_TextIO(cAddrHost(storeCAddr(ListText)), "FING #GET CLIENT INFO")
        If lt_s.decodePart(joinerInfo, 1) = "OK" Then
                joinerInfoStruct = decodeFingerClient(lt_s.decodePart(joinerInfo, 2))

                With joinerInfoStruct
                        eleInfo(0) = "����λ�� " & .HostName
                        eleInfo(1) = "IP��ַ " & .HostIP
                        eleInfo(2) = "���� " & .Comment
                        eleInfo(3) = "��ǰ�ٶ�" & .CurrentSpeed
                        eleInfo(4) = "��ǰ��ȷ��" & .CurrentAccuracy
                        eleInfo(5) = "״̬" & .Status
                End With
        Else
                If MsgBox("��Ч����, ɾ��ô?", vbYesNo) = vbYes Then
                        CancelJoiner ListText
                End If
        End If
End Sub

VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form frmHoll
   AutoRedraw      =   -1  'True
   Caption         =   "��ԭ������"
   ClientHeight    =   5250
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   9255
   Icon            =   "f2Holl.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   350
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   617
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame frmBoard
      BorderStyle     =   0  'None
      Caption         =   "BOARD"
      Height          =   3855
      Left            =   2280
      TabIndex        =   34
      Top             =   720
      Visible         =   0   'False
      Width           =   6735
      Begin VB.CommandButton cmdFont
         Caption         =   "&F��������"
         Height          =   315
         Left            =   5100
         TabIndex        =   24
         Top             =   2160
         Width           =   1395
      End
      Begin MSComDlg.CommonDialog cdColor
         Left            =   6180
         Top             =   900
         _ExtentX        =   847
         _ExtentY        =   847
         _Version        =   393216
         CancelError     =   -1  'True
         Flags           =   1
         FontSize        =   9
      End
      Begin VB.CommandButton cmdCls
         Caption         =   "&C�������"
         Height          =   375
         Left            =   5100
         TabIndex        =   25
         Top             =   2940
         Width           =   1395
      End
      Begin MSComctlLib.ImageCombo cboDrawMenu
         Height          =   330
         Left            =   5040
         TabIndex        =   23
         Top             =   1440
         Width           =   1515
         _ExtentX        =   2672
         _ExtentY        =   582
         _Version        =   393216
         ForeColor       =   -2147483640
         BackColor       =   -2147483643
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
            Name            =   "����"
            Size            =   9.75
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Text            =   "ͼ�����"
         ImageList       =   "ImageDraw"
      End
      Begin VB.CheckBox chkSeeLocal
         Caption         =   "&L���ػ���"
         Height          =   255
         Left            =   5100
         TabIndex        =   22
         Top             =   1020
         Value           =   1  'Checked
         Width           =   1335
      End
      Begin VB.TextBox txtBackColor
         Appearance      =   0  'Flat
         BackColor       =   &H00FFFFFF&
         ForeColor       =   &H00000000&
         Height          =   255
         Left            =   5100
         Locked          =   -1  'True
         TabIndex        =   21
         Text            =   "       �Ҽ���ɫ"
         Top             =   540
         Width           =   1455
      End
      Begin VB.TextBox txtForeColor
         Appearance      =   0  'Flat
         BackColor       =   &H00004000&
         ForeColor       =   &H00FFFFFF&
         Height          =   255
         Left            =   5100
         Locked          =   -1  'True
         TabIndex        =   20
         Text            =   "�����ɫ"
         Top             =   120
         Width           =   1455
      End
      Begin VB.CommandButton cmdRefreshAll
         Caption         =   "&S���ͻ���"
         Height          =   375
         Left            =   5100
         TabIndex        =   26
         Top             =   3360
         Width           =   1395
      End
      Begin VB.PictureBox picBoard
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H00004000&
         BorderStyle     =   0  'None
         FillColor       =   &H00FFFFFF&
         FillStyle       =   0  'Solid
         Height          =   3600
         Left            =   120
         Picture         =   "f2Holl.frx":0E42
         ScaleHeight     =   240
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   320
         TabIndex        =   19
         Top             =   120
         Width           =   4800
         Begin MSComctlLib.ImageList ImageDraw
            Left            =   4140
            Top             =   2940
            _ExtentX        =   1005
            _ExtentY        =   1005
            BackColor       =   -2147483643
            ImageWidth      =   32
            ImageHeight     =   32
            MaskColor       =   12632256
            _Version        =   393216
            BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
               NumListImages   =   7
               BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
                  Picture         =   "f2Holl.frx":2580
                  Key             =   ""
               EndProperty
               BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
                  Picture         =   "f2Holl.frx":29D2
                  Key             =   ""
               EndProperty
               BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628}
                  Picture         =   "f2Holl.frx":2E24
                  Key             =   ""
               EndProperty
               BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628}
                  Picture         =   "f2Holl.frx":3276
                  Key             =   ""
               EndProperty
               BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628}
                  Picture         =   "f2Holl.frx":39C8
                  Key             =   ""
               EndProperty
               BeginProperty ListImage6 {2C247F27-8591-11D1-B16A-00C0F0283628}
                  Picture         =   "f2Holl.frx":3E1A
                  Key             =   ""
               EndProperty
               BeginProperty ListImage7 {2C247F27-8591-11D1-B16A-00C0F0283628}
                  Picture         =   "f2Holl.frx":426C
                  Key             =   ""
               EndProperty
            EndProperty
         End
      End
   End
   Begin MSComctlLib.ImageList Images
      Left            =   1500
      Top             =   4200
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   32
      ImageHeight     =   32
      MaskColor       =   14474460
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
         NumListImages   =   14
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":46BE
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":5312
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":5F66
            Key             =   ""
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":6BBA
            Key             =   ""
         EndProperty
         BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":780E
            Key             =   ""
         EndProperty
         BeginProperty ListImage6 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":8462
            Key             =   ""
         EndProperty
         BeginProperty ListImage7 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":90B6
            Key             =   ""
         EndProperty
         BeginProperty ListImage8 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":9D0A
            Key             =   ""
         EndProperty
         BeginProperty ListImage9 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":A95E
            Key             =   ""
         EndProperty
         BeginProperty ListImage10 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":B5B2
            Key             =   ""
         EndProperty
         BeginProperty ListImage11 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":C206
            Key             =   ""
         EndProperty
         BeginProperty ListImage12 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":CE5A
            Key             =   ""
         EndProperty
         BeginProperty ListImage13 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":DAAE
            Key             =   ""
         EndProperty
         BeginProperty ListImage14 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "f2Holl.frx":E702
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.TreeView treeMenu
      Height          =   4815
      Left            =   60
      TabIndex        =   0
      Top             =   60
      Width           =   2115
      _ExtentX        =   3731
      _ExtentY        =   8493
      _Version        =   393217
      Indentation     =   847
      LineStyle       =   1
      Style           =   7
      HotTracking     =   -1  'True
      ImageList       =   "Images"
      Appearance      =   1
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "����"
         Size            =   9.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
   End
   Begin VB.Frame frmSys
      BorderStyle     =   0  'None
      Caption         =   "SYS"
      Height          =   3855
      Left            =   2400
      TabIndex        =   32
      Top             =   780
      Visible         =   0   'False
      Width           =   6495
      Begin VB.Label Label2
         AutoSize        =   -1  'True
         Caption         =   "(C)��Ȩ���� ��ԭ���"
         ForeColor       =   &H00808080&
         Height          =   180
         Index           =   1
         Left            =   4200
         TabIndex        =   11
         Top             =   3540
         Width           =   1800
      End
      Begin VB.Label Label1
         AutoSize        =   -1  'True
         Caption         =   "δע��汾 ����ע��"
         BeginProperty Font
            Name            =   "����"
            Size            =   24
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00808080&
         Height          =   480
         Left            =   1380
         TabIndex        =   10
         Top             =   2820
         Width           =   4710
      End
      Begin VB.Label cmdCancelApply
         AutoSize        =   -1  'True
         Caption         =   "&Xȡ������"
         BeginProperty Font
            Name            =   "����"
            Size            =   9
            Charset         =   134
            Weight          =   400
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00808000&
         Height          =   180
         Left            =   2340
         TabIndex        =   5
         Top             =   1920
         Width           =   810
      End
      Begin VB.Line Line2
         BorderColor     =   &H00FFFFFF&
         BorderWidth     =   3
         X1              =   3300
         X2              =   3300
         Y1              =   120
         Y2              =   2220
      End
      Begin VB.Label lblPos
         AutoSize        =   -1  'True
         Caption         =   "λ��: "
         BeginProperty Font
            Name            =   "����"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00C00000&
         Height          =   210
         Left            =   120
         TabIndex        =   4
         Top             =   660
         Width           =   630
      End
      Begin VB.Line Line1
         BorderColor     =   &H00FFFFFF&
         BorderWidth     =   3
         X1              =   0
         X2              =   3300
         Y1              =   600
         Y2              =   600
      End
      Begin VB.Label lblChannel
         Caption         =   "Ƶ��"
         BeginProperty Font
            Name            =   "����"
            Size            =   21.75
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00C00000&
         Height          =   435
         Left            =   60
         TabIndex        =   2
         Top             =   120
         Width           =   2325
      End
      Begin VB.Label Label6
         AutoSize        =   -1  'True
         Caption         =   "Ƶ��"
         BeginProperty Font
            Name            =   "����"
            Size            =   15.75
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00404040&
         Height          =   315
         Left            =   2520
         TabIndex        =   3
         Top             =   240
         Width           =   630
      End
      Begin VB.Label lblGroup
         AutoSize        =   -1  'True
         BackColor       =   &H00400000&
         Caption         =   "С�����ƣ�"
         BeginProperty Font
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FFFFFF&
         Height          =   240
         Left            =   3480
         TabIndex        =   7
         Top             =   780
         Width           =   1275
      End
      Begin VB.Label Label5
         AutoSize        =   -1  'True
         BackColor       =   &H00400000&
         Caption         =   "�������ݣ�[����]"
         BeginProperty Font
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FFFFFF&
         Height          =   240
         Left            =   3480
         TabIndex        =   9
         Top             =   1740
         Width           =   2055
      End
      Begin VB.Label lblTime
         AutoSize        =   -1  'True
         BackColor       =   &H00400000&
         Caption         =   "����ʱ�䣺"
         BeginProperty Font
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FFFFFF&
         Height          =   240
         Left            =   3480
         TabIndex        =   8
         Top             =   1260
         Width           =   1275
      End
      Begin VB.Label lblMonitor
         AutoSize        =   -1  'True
         BackColor       =   &H00400000&
         Caption         =   "�࿼�ߣ�"
         BeginProperty Font
            Name            =   "����"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FFFFFF&
         Height          =   240
         Left            =   3480
         TabIndex        =   6
         Top             =   300
         Width           =   1020
      End
   End
   Begin VB.Frame frmCon
      BorderStyle     =   0  'None
      Caption         =   "CON"
      Height          =   4095
      Left            =   2400
      TabIndex        =   37
      Top             =   660
      Visible         =   0   'False
      Width           =   6495
      Begin VB.ComboBox cboControls
         Height          =   300
         ItemData        =   "f2Holl.frx":F356
         Left            =   1680
         List            =   "f2Holl.frx":F363
         Style           =   2  'Dropdown List
         TabIndex        =   16
         Top             =   3240
         Width           =   3015
      End
      Begin VB.CheckBox chkCRemote
         Caption         =   "����Զ��"
         Height          =   180
         Left            =   180
         TabIndex        =   15
         Top             =   3600
         Width           =   1215
      End
      Begin VB.CheckBox chkCLocal
         Caption         =   "���Ʊ���"
         Height          =   180
         Left            =   180
         TabIndex        =   14
         Top             =   3300
         Value           =   1  'Checked
         Width           =   1215
      End
      Begin VB.CommandButton cmdExecScript
         Caption         =   "&Xִ�г���"
         Height          =   375
         Left            =   4800
         TabIndex        =   17
         Top             =   3240
         Width           =   1515
      End
      Begin VB.TextBox txtScript
         Height          =   2715
         Left            =   120
         MultiLine       =   -1  'True
         ScrollBars      =   2  'Vertical
         TabIndex        =   13
         Text            =   "f2Holl.frx":F397
         Top             =   420
         Width           =   6195
      End
      Begin VB.Label Label4
         AutoSize        =   -1  'True
         Caption         =   "&S�����������߷��Ϳ���"
         Height          =   180
         Left            =   120
         TabIndex        =   12
         Top             =   120
         Width           =   1890
      End
   End
   Begin VB.Frame frmChat
      BorderStyle     =   0  'None
      Caption         =   "CHAT"
      Height          =   3975
      Left            =   2400
      TabIndex        =   18
      Top             =   720
      Visible         =   0   'False
      Width           =   6495
      Begin VB.CommandButton cmdClearMsg
         Caption         =   "&R�������"
         Height          =   315
         Left            =   2700
         TabIndex        =   33
         Top             =   3600
         Width           =   1275
      End
      Begin VB.CommandButton cmdChangeAlias
         Caption         =   "&Aʹ�ñ���"
         Height          =   315
         Left            =   120
         TabIndex        =   31
         Top             =   3600
         Width           =   1335
      End
      Begin VB.CommandButton cmdSend
         Caption         =   "&S����"
         Height          =   315
         Left            =   5220
         TabIndex        =   35
         Top             =   3600
         Width           =   1155
      End
      Begin VB.TextBox txtContent
         Appearance      =   0  'Flat
         BackColor       =   &H00C0FFC0&
         Height          =   270
         Left            =   1920
         MaxLength       =   100
         TabIndex        =   30
         Top             =   3240
         Width           =   4455
      End
      Begin VB.TextBox txtAct
         Appearance      =   0  'Flat
         BackColor       =   &H00FFFFC0&
         Height          =   270
         Left            =   1140
         TabIndex        =   29
         TabStop         =   0   'False
         Text            =   "˵:"
         Top             =   3240
         Width           =   735
      End
      Begin VB.TextBox txtChatData
         Appearance      =   0  'Flat
         BackColor       =   &H00FFC0C0&
         ForeColor       =   &H00000000&
         Height          =   3075
         Left            =   120
         MultiLine       =   -1  'True
         TabIndex        =   27
         Top             =   120
         Width           =   6255
      End
      Begin VB.Label txtAlias
         AutoSize        =   -1  'True
         Caption         =   "&CAMPO"
         ForeColor       =   &H00800000&
         Height          =   180
         Left            =   120
         TabIndex        =   28
         Top             =   3300
         Width           =   450
      End
   End
   Begin VB.Frame frmTalk
      BorderStyle     =   0  'None
      Caption         =   "TALK"
      Height          =   3915
      Left            =   2460
      TabIndex        =   36
      Top             =   720
      Visible         =   0   'False
      Width           =   6435
      Begin VB.Label Label3
         AutoSize        =   -1  'True
         Caption         =   "������..."
         BeginProperty Font
            Name            =   "����"
            Size            =   42
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00004000&
         Height          =   840
         Left            =   1320
         TabIndex        =   38
         Top             =   1440
         Width           =   3870
      End
   End
   Begin MSComctlLib.TabStrip tabMenu
      Height          =   4815
      Left            =   2220
      TabIndex        =   1
      Top             =   60
      Width           =   6855
      _ExtentX        =   12091
      _ExtentY        =   8493
      MultiRow        =   -1  'True
      HotTracking     =   -1  'True
      ImageList       =   "Images"
      _Version        =   393216
      BeginProperty Tabs {1EFB6598-857C-11D1-B16A-00C0F0283628}
         NumTabs         =   5
         BeginProperty Tab1 {1EFB659A-857C-11D1-B16A-00C0F0283628}
            Caption         =   "ϵͳ"
            Key             =   "SYS"
            ImageVarType    =   2
            ImageIndex      =   1
         EndProperty
         BeginProperty Tab2 {1EFB659A-857C-11D1-B16A-00C0F0283628}
            Caption         =   "������"
            Key             =   "CHAT"
            ImageVarType    =   2
            ImageIndex      =   2
         EndProperty
         BeginProperty Tab3 {1EFB659A-857C-11D1-B16A-00C0F0283628}
            Caption         =   "�װ�"
            Key             =   "BOARD"
            ImageVarType    =   2
            ImageIndex      =   5
         EndProperty
         BeginProperty Tab4 {1EFB659A-857C-11D1-B16A-00C0F0283628}
            Caption         =   "������"
            Key             =   "TALK"
            ImageVarType    =   2
            ImageIndex      =   8
         EndProperty
         BeginProperty Tab5 {1EFB659A-857C-11D1-B16A-00C0F0283628}
            Caption         =   "����"
            Key             =   "CON"
            ImageVarType    =   2
            ImageIndex      =   6
         EndProperty
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "����"
         Size            =   9.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "л����/��ԭ��� 2001 �й�.�㽭"
      ForeColor       =   &H00008000&
      Height          =   180
      Index           =   0
      Left            =   6360
      TabIndex        =   39
      Top             =   4980
      Width           =   2700
   End
End
Attribute VB_Name = "frmHoll"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private lastX As Single, lastY As Single, bDown As Boolean
Private drawText As String

Public Sub WaitForPaper()
        frmWaitingBox.TurnOn "�ȴ�����..."
        fingerClient.Status = "�ȴ�����..."
        Do While paperDowned = 0
                DoEvents
        Loop
        frmWaitingBox.TurnOff
End Sub

Public Sub ChatIn(ByVal inData As String)
        Dim lastLine As String
        lastLine = lt_s.decodePart(txtChatData, 0, False, Chr(13))
        If lastLine <> inData Then
                txtChatData = inData & vbNewLine & txtChatData
        Else
                txtChatData = lastLine & "+1" & Mid(txtChatData, Len(lastLine) + 2)
        End If
End Sub

Private Sub cboControls_Click()
        Select Case cboControls.text
        Case "�ÿ��ƻ�����ʧ"
                txtScript = "c.HideScript"
        Case "�������Ҳ�����"
                txtScript = "a1 = ""Ϊʲô��ԭ���û�в���DirectX����? ������Ϊ��ԭ���ӵ���Լ�������ͼ���������������! """ & vbNewLine & _
                                "a2 = ""��һ����֪��Pa���԰�, ���ǲ�ԭ����Լ�������! """ & vbNewLine & _
                                "a3 = ""��һ�μ�β��ϯ, ��ס���ϲ�ԭ���, ��������������������������!""" & vbNewLine & _
                                "" & vbNewLine & _
                                "select case int(rnd * 3)" & vbNewLine & _
                                "    case 0: outt = a1" & vbNewLine & _
                                "    case 1: outt = a2" & vbNewLine & _
                                "    case else: outt = a3" & vbNewLine & _
                                "end select" & vbNewLine & _
                                "c.cdata.text = outt & chr(13) & chr(10) & c.cdata.text" & vbNewLine & _
                                "" & vbNewLine & _
                                "c.turnTo ""CHAT""" & vbNewLine
        End Select
End Sub

Private Sub cboDrawMenu_Click()
        If cboDrawMenu.SelectedItem.key = "TEXT" Then
                drawText = InputBox("������Ҫ���������: ")
        End If
End Sub

Public Sub sendDraw(ByVal drawCmd As String)
        Dim allline As String
        Dim host As String

        allline = "drawRes=c." & LTrim(drawCmd)
        If chkSeeLocal Then
                script.ExecuteStatement allline
                picBoard.Refresh
        End If

        host = fingerServer.HostName
        If host <> "" Then
                allline = "FING #DISPATCH SCRIPT" & lt_s.encodePart(allline)
                FN_TextIO host, allline
        End If
End Sub

Private Sub cmdCancelApply_Click()
        Dim host As String
        host = fingerServer.HostName
        If host <> "" Then
                If MsgBox("���ȡ��ô?", vbYesNo) = vbYes Then
                        frmApply.cmdCancel_Click
                        frmMain.Show
                        Me.Hide
                End If
        End If
End Sub

Private Sub cmdClearMsg_Click()
        txtChatData = ""
End Sub

Private Sub cmdCls_Click()
        picBoard.Cls
End Sub

Private Sub cmdExecScript_Click()
        Dim sendstr As String
        Dim host As String
        sendstr = txtScript
        If chkCLocal Then
                script.ExecuteStatement sendstr
        End If
        If chkCRemote Then
                host = fingerServer.HostName
                If host <> "" Then
                        sendstr = "FING #DISPATCH SCRIPT" & lt_s.encodePart(sendstr)
                        FN_TextIO host, sendstr
                End If
        End If
End Sub

Private Sub cmdFont_Click()
        On Error GoTo err
        cdColor.ShowFont
        cmdFont.FontName = cdColor.FontName
        cmdFont.FontSize = cdColor.FontSize
        cmdFont.FontBold = cdColor.FontBold
        cmdFont.FontItalic = cdColor.FontItalic
        cmdFont.FontStrikethru = cdColor.FontStrikethru
        cmdFont.FontUnderline = cdColor.FontUnderline
        picBoard.Font = cmdFont.Font
        Exit Sub
err:
End Sub

Private Sub cmdRefreshAll_Click()
        Dim r As VbMsgBoxResult
        r = MsgBox("��������Ҫ�����������, �п��ܻή����������, Ŀǰ����")
End Sub

Private Sub cmdSend_Click()
        Dim SStr As String
        Dim host As String
        Static lastContent As String

        SStr = txtAlias & txtAct & txtContent
        host = fingerServer.HostName
        If host = "" Then
                MsgBox "�������ȼ���һ��Ƶ��֮����ܷ�����Ϣ!"
        Else
                If SStr = lastContent Then
                        MsgBox "�벻Ҫ�����ظ�������, ���ǲ����µ�. "
                Else
                        FN_TextIO host, "FING #DISPATCH MESSAGE" & lt_s.encodePart(SStr)
                        lastContent = SStr
                End If
        End If
End Sub

Private Sub cmdChangeAlias_Click()
        Dim nA As String
        nA = InputBox("�����������±���:", , txtAlias)
        While Len(nA) < 3
                nA = InputBox("������������3���ַ�, ����������: ", , txtAlias)
        Wend
        txtAlias = nA
End Sub

Private Sub Form_Activate()
        SwitchTo 1
End Sub

Private Sub Form_Load()
        bDown = False
        init_treenodes treeMenu.Nodes, Nothing, _
                "#43,ϵͳ|SYS|1,1|1,1#�ȴ�����|WAIT|1,9#����������|RET|2,12" & _
                "#������|CHAT|1,2|1,3#�װ�|BOARD|1,4|1,5#������|TALK|1,7|1,8#����|CON|1,6|1,6#26,����|HELP|2,12#����|ABOUT|2,12"
        With cboDrawMenu.ComboItems
                .Add , "PIXEL", "��㻭", 1
                .Add , "LINE", "ֱ��", 3
                .Add , "RECT", "����", 4
                .Add , "CIR", "Բ", 7
                .Add , "FILL", "���", 5
                .Add , "TEXT", "����", 6
        End With
        cboControls.ListIndex = 0

        txtScript = GetSetting(FingerRoot, "������", "���Ƴ���", txtScript)
End Sub

Public Sub SwitchTo(ByVal key As String)
        Dim tabsel As Integer

        frmSys.Visible = False
        frmChat.Visible = False
        frmBoard.Visible = False
        frmTalk.Visible = False
        frmCon.Visible = False

        tabsel = 1
        Select Case UCase(key)
        Case "SYS", "SYSTEM", "WAIT", "RET"
                tabsel = 1
                frmSys.Visible = True
                fingerClient.Status = "�ں����Ҳ���"
        Case "CHAT"
                tabsel = 2
                frmChat.Visible = True
                fingerClient.Status = "�ں���������"
        Case "BOARD", "DRAW"
                tabsel = 3
                frmBoard.Visible = True
                fingerClient.Status = "�ں����һ���"
        Case "TALK", "DISCUSS"
                tabsel = 4
                frmTalk.Visible = True
                fingerClient.Status = "�ں���������"
        Case "CON", "CONTROL"
                tabsel = 5
                frmCon.Visible = True
                fingerClient.Status = "�ں����ҿ���"
        Case Else
                fingerClient.Status = "�ں����Ҳ�֪��ʲô"
        End Select
        If tabMenu.SelectedItem.Index <> tabsel Then tabMenu.Tabs(tabsel).Selected = True
End Sub

Private Sub Form_Unload(Cancel As Integer)
        SaveSetting FingerRoot, "������", "���Ƴ���", txtScript
End Sub

Private Sub picBoard_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        Dim useColor As Long
        useColor = IIf(Button And vbLeftButton, txtForeColor.BackColor, txtBackColor.BackColor)
        lastX = X: lastY = Y

        If Not cboDrawMenu.SelectedItem Is Nothing Then
                Select Case cboDrawMenu.SelectedItem.key
                Case "PIXEL": ' ��һ�����ȷ��
                Case "LINE": ' ����Ѿ�ȷ��
                Case "RECT": ' ���Ͻ�ȷ��
                Case "CIR": ' Բ��ȷ��
                Case "FILL": sendDraw "FloodFill(" & X & ", " & Y & ", " & useColor & ")"
                Case "TEXT": sendDraw "TextOut(" & X & ", " & Y & ", """ & lt_s.quoteString(drawText) & """, " & useColor & ")"
                End Select
        End If
        bDown = True
End Sub

Private Sub picBoard_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
        Dim useColor As Long
        Dim ox As Single, oy As Single
        If Not bDown Then Exit Sub
        ox = lastX: oy = lastY
        useColor = IIf(Button And vbLeftButton, txtForeColor.BackColor, txtBackColor.BackColor)


        If Not cboDrawMenu.SelectedItem Is Nothing Then
                Select Case cboDrawMenu.SelectedItem.key
                Case "PIXEL":
                        lastX = X: lastY = Y
                        sendDraw "Line(" & ox & ", " & oy & ", " & X & ", " & Y & ", " & useColor & ")"
                Case "LINE": ' rubberLine...
                Case "RECT": ' rubberRect...
                Case "CIR": ' rubberCir...
                End Select
        End If
End Sub

Private Sub picBoard_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
        Dim useColor As Long
        useColor = IIf(Button And vbLeftButton, txtForeColor.BackColor, txtBackColor.BackColor)

        If Not cboDrawMenu.SelectedItem Is Nothing Then
                Select Case cboDrawMenu.SelectedItem.key
                Case "LINE": sendDraw "Line(" & lastX & ", " & lastY & ", " & X & ", " & Y & ", " & useColor & ")"
                Case "RECT": sendDraw "Rect(" & lastX & ", " & lastY & ", " & X & ", " & Y & ", " & useColor & ")"
                Case "CIR": sendDraw "Ellipse(" & lastX & ", " & lastY & ", " & X & ", " & Y & ", " & useColor & ")"
                End Select
        End If
        bDown = False
End Sub

Private Sub tabMenu_Click()
        Select Case tabMenu.SelectedItem.key
        Case "SYS"
                SwitchTo "SYS"
        Case "CHAT"
                SwitchTo "CHAT"
        Case "BOARD"
                SwitchTo "BOARD"
        Case "TALK"
                SwitchTo "TALK"
        Case "CON"
                SwitchTo "CON"
        End Select
End Sub

Private Sub treeMenu_NodeClick(ByVal Node As MSComctlLib.Node)
        Select Case Node.key
        Case "SYS"
                SwitchTo "SYS"
        Case "WAIT"
                WaitForPaper
        Case "RET"
                cmdCancelApply_Click
        Case "CHAT"
                SwitchTo "CHAT"
        Case "BOARD"
                SwitchTo "BOARD"
        Case "TALK"
                SwitchTo "TALK"
        Case "CON"
                SwitchTo "CON"
        Case "ABOUT"
                frmAbout.Show
        End Select
End Sub

Private Sub txtBackColor_Change()
        On Error GoTo err
        cdColor.ShowColor
        txtForeColor.BackColor = cdColor.color
        Exit Sub
err:
End Sub

Private Sub txtContent_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then cmdSend_Click
End Sub

Private Sub txtForeColor_Change()
        On Error GoTo err
        cdColor.ShowColor
        txtForeColor.BackColor = cdColor.color
        Exit Sub
err:
End Sub

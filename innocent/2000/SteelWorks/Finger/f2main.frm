VERSION 5.00
Object = "{0E59F1D2-1FBE-11D0-8FF2-00A0D10038BC}#1.0#0"; "msscript.ocx"
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form frmMain
   BorderStyle     =   1  'Fixed Single
   Caption         =   "FINGER - 草原软件出品"
   ClientHeight    =   3135
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5085
   Icon            =   "f2main.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   209
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   339
   StartUpPosition =   2  'CenterScreen
   Begin VB.PictureBox picText
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   300
      Left            =   600
      ScaleHeight     =   300
      ScaleWidth      =   1200
      TabIndex        =   22
      Top             =   1260
      Visible         =   0   'False
      Width           =   1200
      Begin VB.Label Label2
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "文字绘制暂存"
         Height          =   180
         Left            =   60
         TabIndex        =   23
         Top             =   60
         Visible         =   0   'False
         Width           =   1080
      End
   End
   Begin VB.Timer tmrNet
      Interval        =   1
      Left            =   2160
      Top             =   1800
   End
   Begin VB.CommandButton cmdInitBtn
      Caption         =   "InitBtn"
      Height          =   315
      Left            =   3000
      TabIndex        =   31
      Top             =   60
      Visible         =   0   'False
      Width           =   1335
   End
   Begin VB.CommandButton cmdInitText
      Caption         =   "InitText"
      Height          =   315
      Left            =   3000
      TabIndex        =   30
      Top             =   420
      Visible         =   0   'False
      Width           =   1335
   End
   Begin VB.CommandButton cmdInitUI
      Caption         =   "InitUI"
      Height          =   315
      Left            =   3000
      TabIndex        =   29
      Top             =   780
      Visible         =   0   'False
      Width           =   1335
   End
   Begin VB.PictureBox picBack3
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   240
      Left            =   480
      Picture         =   "f2main.frx":0E42
      ScaleHeight     =   16
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   80
      TabIndex        =   24
      Top             =   1140
      Visible         =   0   'False
      Width           =   1200
      Begin VB.Label qqqComments
         Appearance      =   0  'Flat
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BackStyle       =   0  'Transparent
         Caption         =   "picBack3"
         ForeColor       =   &H80000008&
         Height          =   180
         Index           =   7
         Left            =   240
         TabIndex        =   26
         Top             =   0
         Visible         =   0   'False
         Width           =   720
      End
   End
   Begin MSScriptControlCtl.ScriptControl script
      Left            =   3780
      Top             =   1680
      _ExtentX        =   1005
      _ExtentY        =   1005
      AllowUI         =   -1  'True
   End
   Begin MSComDlg.CommonDialog cdMain
      Left            =   2940
      Top             =   1740
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      DialogTitle     =   "打开钢指神功数据文件"
      Flags           =   1
      HelpFile        =   "help\finger.chm"
   End
   Begin VB.Timer tmrMain
      Interval        =   500
      Left            =   1440
      Top             =   1800
   End
   Begin MSWinsockLib.Winsock sockS
      Left            =   180
      Top             =   1800
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      LocalPort       =   1600
   End
   Begin VB.PictureBox Picture1
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   1155
      Left            =   2040
      ScaleHeight     =   75
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   47
      TabIndex        =   2
      Top             =   60
      Visible         =   0   'False
      Width           =   735
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   18
         Left            =   5880
         Picture         =   "f2main.frx":E1E86
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   37
         Top             =   720
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   17
         Left            =   5160
         Picture         =   "f2main.frx":E2EBD
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   36
         Top             =   720
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   16
         Left            =   5880
         Picture         =   "f2main.frx":E3F88
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   35
         Top             =   0
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   15
         Left            =   5160
         Picture         =   "f2main.frx":E4CD3
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   34
         Top             =   0
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   0
         Left            =   0
         Picture         =   "f2main.frx":E5B30
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   17
         Top             =   0
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   1
         Left            =   720
         Picture         =   "f2main.frx":E6695
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   16
         Top             =   0
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   2
         Left            =   1440
         Picture         =   "f2main.frx":E757D
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   15
         Top             =   0
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   3
         Left            =   2160
         Picture         =   "f2main.frx":E8452
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   14
         Top             =   0
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   4
         Left            =   2880
         Picture         =   "f2main.frx":E92A3
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   13
         Top             =   0
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   5
         Left            =   3600
         Picture         =   "f2main.frx":EA120
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   12
         Top             =   0
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   6
         Left            =   4320
         Picture         =   "f2main.frx":EAFE5
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   11
         Top             =   0
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   7
         Left            =   720
         Picture         =   "f2main.frx":EBDA8
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   10
         Top             =   720
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   8
         Left            =   1440
         Picture         =   "f2main.frx":ECB21
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   9
         Top             =   720
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   9
         Left            =   2160
         Picture         =   "f2main.frx":ED89B
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   8
         Top             =   720
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   10
         Left            =   2880
         Picture         =   "f2main.frx":EE5B9
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   7
         Top             =   720
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   11
         Left            =   3600
         Picture         =   "f2main.frx":EF302
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   6
         Top             =   720
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   720
         Index           =   12
         Left            =   4320
         Picture         =   "f2main.frx":F005B
         ScaleHeight     =   48
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   48
         TabIndex        =   5
         Top             =   720
         Visible         =   0   'False
         Width           =   720
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   1605
         Index           =   13
         Left            =   720
         Picture         =   "f2main.frx":F0D14
         ScaleHeight     =   107
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   118
         TabIndex        =   4
         Top             =   1440
         Visible         =   0   'False
         Width           =   1770
      End
      Begin VB.PictureBox picBtn
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   1605
         Index           =   14
         Left            =   2520
         Picture         =   "f2main.frx":F26E5
         ScaleHeight     =   107
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   118
         TabIndex        =   3
         Top             =   1440
         Visible         =   0   'False
         Width           =   1770
      End
      Begin VB.Label qqqComments
         AutoSize        =   -1  'True
         Caption         =   "main buttons"
         Height          =   180
         Index           =   4
         Left            =   0
         TabIndex        =   28
         Top             =   720
         Visible         =   0   'False
         Width           =   1080
      End
   End
   Begin VB.PictureBox picBack2
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H00FF0000&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   240
      Left            =   300
      ScaleHeight     =   16
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   80
      TabIndex        =   1
      Top             =   960
      Visible         =   0   'False
      Width           =   1200
      Begin VB.Label qqqComments
         Appearance      =   0  'Flat
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BackStyle       =   0  'Transparent
         Caption         =   "picBack2"
         ForeColor       =   &H80000008&
         Height          =   180
         Index           =   1
         Left            =   240
         TabIndex        =   25
         Top             =   0
         Visible         =   0   'False
         Width           =   720
      End
   End
   Begin VB.PictureBox picBack
      AutoRedraw      =   -1  'True
      BorderStyle     =   0  'None
      BeginProperty Font
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      IMEMode         =   7  'DBCS ALPHABET
      Left            =   60
      Picture         =   "f2main.frx":F40F7
      ScaleHeight     =   43
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   104
      TabIndex        =   0
      Top             =   120
      Width           =   1560
      Begin VB.Label lblTime
         Appearance      =   0  'Flat
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BackStyle       =   0  'Transparent
         Caption         =   "时间"
         BeginProperty Font
            Name            =   "Arial Black"
            Size            =   15
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   -1  'True
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FF8080&
         Height          =   420
         Left            =   780
         TabIndex        =   33
         Top             =   180
         Width           =   600
      End
      Begin VB.Label qqqComments
         Appearance      =   0  'Flat
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BackStyle       =   0  'Transparent
         Caption         =   "picBack"
         ForeColor       =   &H80000008&
         Height          =   180
         Index           =   0
         Left            =   300
         TabIndex        =   27
         Top             =   120
         Visible         =   0   'False
         Width           =   630
      End
   End
   Begin MSWinsockLib.Winsock sockC
      Left            =   600
      Top             =   1800
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      LocalPort       =   1601
   End
   Begin VB.Label qqqComments
      AutoSize        =   -1  'True
      Caption         =   "tmrNet"
      Height          =   180
      Index           =   8
      Left            =   2100
      TabIndex        =   32
      Top             =   2280
      Visible         =   0   'False
      Width           =   540
   End
   Begin VB.Label qqqComments
      AutoSize        =   -1  'True
      Caption         =   "script"
      Height          =   180
      Index           =   6
      Left            =   3780
      TabIndex        =   21
      Top             =   2280
      Visible         =   0   'False
      Width           =   540
   End
   Begin VB.Label qqqComments
      AutoSize        =   -1  'True
      Caption         =   "cdMain"
      Height          =   180
      Index           =   5
      Left            =   2880
      TabIndex        =   20
      Top             =   2280
      Visible         =   0   'False
      Width           =   540
   End
   Begin VB.Label qqqComments
      AutoSize        =   -1  'True
      Caption         =   "tmrMain"
      Height          =   180
      Index           =   3
      Left            =   1260
      TabIndex        =   19
      Top             =   2280
      Visible         =   0   'False
      Width           =   630
   End
   Begin VB.Label qqqComments
      AutoSize        =   -1  'True
      Caption         =   "socket"
      Height          =   180
      Index           =   2
      Left            =   300
      TabIndex        =   18
      Top             =   2280
      Visible         =   0   'False
      Width           =   540
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public bDown As Boolean
Public controlMain As New FingerControl
Public hbmCaret As Long
Public PaperAccepted As Boolean
Public showResulted As Boolean

Private Sub ShowButton(btn As Button, ByVal bDown As Boolean)
        Dim r As IRECT
        If btn.OnShow Then
                If btn.CurPos.X = btn.LastDrawPos.X And btn.CurPos.Y = btn.LastDrawPos.Y _
                    And bDown = btn.LastDrawIsDown Then Exit Sub
                r.Left = btn.LastDrawPos.X
                r.Top = btn.LastDrawPos.Y
                RestoreBlock_pic picBack, picBack2, r, IIf(bDown, btn.picDown, btn.picNormal), False
                HintText.GetChar(0).ClearChar
                HintText.GetChar(1).ClearChar
        End If
        r.Left = btn.CurPos.X
        r.Top = btn.CurPos.Y
        ExchangeBlock_Pic picBack, picBack2, r, IIf(bDown, btn.picDown, btn.picNormal), btn.picMask, False
        btn.LastDrawPos = btn.CurPos
        If bDown Then
                With HintText.GetChar(0)
                        .ClearChar
                        .m_AuxX = btn.CurPos.X - 5
                        .m_AuxY = btn.CurPos.Y - 15
                        .Content = Left(btn.key, 2)
                        .redraw
                End With
                With HintText.GetChar(1)
                        .ClearChar
                        .m_AuxX = btn.CurPos.X + 20
                        .m_AuxY = btn.CurPos.Y + btn.picNormal.height + 10
                        .Content = Mid(btn.key, 4)
                        .redraw
                End With
        End If
        btn.LastDrawIsDown = bDown
        btn.OnShow = True
End Sub
Private Sub HideButton(btn As Button)
        Dim r As IRECT
        If btn.OnShow Then
                r.Left = btn.LastDrawPos.X
                r.Top = btn.LastDrawPos.Y
                RestoreBlock_pic picBack, picBack2, r, IIf(btn.LastDrawIsDown, btn.picDown, btn.picNormal), False
                HintText.GetChar(0).ClearChar
                HintText.GetChar(1).ClearChar
                btn.OnShow = False
        End If
End Sub

Sub cmdInitBtn_Click()
        With HintText
                .SetSize 2
                With .GetChar(0)
                        .Content = ""
                        .BackColor = &HFFFFFFFF
                        .ForeColor = &HFF00FF
                        .Size = 10
                        .Underline = True
                        .SetOwnerText HintText, 0
                End With
                With .GetChar(1)
                        .Content = ""
                        .BackColor = &HFF00FF00
                        .ForeColor = &H80FFFFFF
                        .Size = 9
                        .Underline = False
                        .SetOwnerText HintText, 1
                End With
                Set .drawPic = picText
                .hSceneDC = picBack.hdc
                .hSceneBakDC = picBack3.hdc
        End With
        SetButton MainButtons(1), 1, "练习-热身运动", picBtn(1), picBtn(7), picBtn(0), True, 83, 215, -1, 290
        SetButton MainButtons(2), 2, "测试-牛刀初试", picBtn(2), picBtn(8), picBtn(0), True, 143, 215, -1, 265
        SetButton MainButtons(3), 3, "统考-听从发落", picBtn(3), picBtn(9), picBtn(0), True, 203, 215, -1, 240
        SetButton MainButtons(4), 4, "交卷-一切结束", picBtn(4), picBtn(10), picBtn(0), True, 393, 215, -1, 230
        SetButton MainButtons(5), 5, "监考-远程指挥", picBtn(5), picBtn(11), picBtn(0), True, 453, 215, -1, 255
        SetButton MainButtons(6), 6, "退出-服从分配", picBtn(6), picBtn(12), picBtn(0), True, 513, 215, -1, 280
        SetButton MainButtons(7), 7, "关于-关于程序", picBtn(15), picBtn(16), picBtn(0), True, 210, 165, -1, -1
        SetButton MainButtons(8), 8, "帮助-请求咨询", picBtn(17), picBtn(18), picBtn(0), True, 385, 276, -1, -1
        SetButton MainButtons(0), 0, "开始-", picBtn(13), picBtn(14), Nothing, False, 265, 189, -1, -1
End Sub
Sub cmdInitText_Click()
        Dim t As String
        t = GetSetting(FingerRoot, "启动设置", "字体", "#8,16777152#7,1048576#True#8,16777215#7,8421631#1,1#1,1#True")
        With template_FingerChar
                .BackColor = val(lt_s.decodePart(t, 1))
                .ForeColor = val(lt_s.decodePart(t, 2))
                .HasGradient = CBool(lt_s.decodePart(t, 3))
                .GradientC1 = val(lt_s.decodePart(t, 4))
                .GradientC2 = val(lt_s.decodePart(t, 5))
                .GradientDirection = val(lt_s.decodePart(t, 6))
                .GradientLoop = val(lt_s.decodePart(t, 7))
                .Break = CBool(lt_s.decodePart(t, 8))
        End With
        tempText.X = 40
        tempText.Y = 20
        tempText.hSceneDC = frmMain.picBack.hdc
        tempText.hSceneBakDC = frmMain.picBack3.hdc
        inputText.X = 40
        inputText.Y = 300
        inputText.hSceneDC = frmMain.picBack.hdc
        inputText.hSceneBakDC = frmMain.picBack3.hdc
        inputText.AL_AllocContent "", -1
        inputText.ShowCaret = True
        inputText.Visible = True
        copyEText validText, tempText, False
        validText.Visible = False
        validText.Y = tempText.Y + 18
End Sub
Sub cmdInitUI_Click()
        picBack.Left = 0
        picBack.Top = 0
        picBack.width = 640
        picBack.height = 480

        picBack2.Left = 0
        picBack2.Top = 0
        picBack2.width = picBack.width
        picBack2.height = picBack.height
        picBack3.Left = 0
        picBack3.Top = 0
        picBack3.width = picBack.width
        picBack3.height = picBack.height
        picText.width = picBack2.width
        picText.height = 64

        Me.width = 645 * Screen.TwipsPerPixelX
        Me.height = 500 * Screen.TwipsPerPixelY

        lblTime.Left = 500
        lblTime.Top = 220

        With SpeedBox
                .X = 43: .Y = 180: .w = 90: .h = 100
                .m_ImgType = 0
        End With
        With AccuracyBox
                .X = 143: .Y = 180: .w = 90: .h = 100
                .m_ImgType = 1
        End With

        cmdInitBtn_Click
        cmdInitText_Click
        GoIntoMenu = False

End Sub

Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
        FingerDown KeyCode, Shift
End Sub
Private Sub Form_KeyPress(KeyAscii As Integer)
        FingerPressed KeyAscii
End Sub
Private Sub Form_KeyUp(KeyCode As Integer, Shift As Integer)
        FingerUp KeyCode, Shift
End Sub

Private Sub Form_Unload(Cancel As Integer)
        Dim t As String
        With template_FingerChar
                t = lt_s.encodePart(.BackColor) & lt_s.encodePart(.ForeColor) & lt_s.encodePart(.HasGradient) & _
                        lt_s.encodePart(.GradientC1) & lt_s.encodePart(.GradientC2) & lt_s.encodePart(.GradientDirection) & _
                        lt_s.encodePart(.GradientLoop) & lt_s.encodePart(.Break)
        End With
        SaveSetting FingerRoot, "启动选项", "字体", t

        SaveSetting FingerRoot, "启动选项\流比较", "比较深度", SEARCH_DEPTH
        SaveSetting FingerRoot, "启动选项\流比较", "比较广度", SAME_SIZE
End Sub

Private Sub picBack_KeyDown(KeyCode As Integer, Shift As Integer)
        FingerDown KeyCode, Shift
End Sub
Private Sub picBack_KeyPress(KeyAscii As Integer)
        picBack_GotFocus
        FingerPressed KeyAscii
End Sub
Private Sub picBack_KeyUp(KeyCode As Integer, Shift As Integer)
        FingerUp KeyCode, Shift
End Sub

Private Sub Form_Load()
        FN_Initialize sockS, sockC, _
                        FN_DEFAULT_SERVER_PORT, FN_DEFAULT_CLIENT_PORT, _
                        pFunc(AddressOf Finger_Session)
        Set modFastNet.script = script

        script.AddObject "frmMain", frmMain, True
        script.AddObject "frmManager", frmManager, True
        script.AddObject "frmHoll", frmHoll, True
        script.AddObject "tempText", tempText
        script.AddObject "validText", validText
        script.AddObject "inputText", inputText
        script.AddObject "TheScript", script
        script.AddObject "TheTimer", tmrMain
        script.AddObject "cdMain", cdMain
        script.AddObject "sockS", sockS
        script.AddObject "sockC", sockC
        script.AddObject "c", controlMain
        script.AddObject "snow", frm_Snow
        script.AddObject "scriptScreen", Screen

        cmdInitUI_Click
End Sub

' mainmenu
        Sub F_Practice()
                PrepareText
                Mode = M_Practice
                FLastTimer = 0
        End Sub
        Sub F_Test()
                PrepareText

                Mode = M_Test
                FLastTimer = Timer
        End Sub
        Sub F_Client()
                frmApply.Show
                Do While paperDowned = 0
                        DoEvents
                Loop
                If paperDowned = -1 Then
                        PrepareText False
                        Mode = M_client
                        bHandup = False
                        FLastTimer = Timer
                Else
                        ' canceled
                End If
        End Sub
        Sub F_Handup()
                Select Case Mode
                Case M_client
                        WaitForAcceptPaper
                        MsgBox "祝贺您成功的结束了您的测试!"
                        ShowFingerResult
                Case M_Test
                        ShowFingerResult
                Case M_Practice
                End Select
                Mode = M_Idle
        End Sub

        Sub F_Manager()
                frmManager.Show
                Me.Hide
                Mode = M_Manager
        End Sub
        Sub F_About()
                frmAbout.Show
        End Sub
        Sub F_Help()
                Dim pdir As String
                pdir = winDir
                If Trim(pdir) <> "" Then pdir = pdir & "\"
                WinExec pdir & "hh.exe " & App.Path & "\finger.chm", SW_SHOWNORMAL
        End Sub
        Sub F_End()
                Terminate
                End
        End Sub

        Sub WaitForAcceptPaper()
                PaperAccepted = False
                frmWaitingBox.TurnOn "正在提交试卷, 请等待..."
                While Not PaperAccepted
                        DoEvents
                Wend
                frmWaitingBox.TurnOff
        End Sub

        Sub ShowFingerResult()
                Dim I As Integer
                Dim r As Boolean
                Dim crect As RECTL
                I = 1
                crect.Left = frmMain.Left / Screen.TwipsPerPixelX + 113
                crect.Top = frmMain.Top / Screen.TwipsPerPixelY + 116
                crect.Right = crect.Left + 60
                crect.Bottom = crect.Top + 34
                ClipCursor pAny(crect)
                Do While I < 80
                        r = BitBltBrick(picBack.hdc, 100, 80, 440, 320, I * &H100& + &H1 * I)
                        picBack.Refresh
                        I = I + 1 + I / 10
                Loop
                SpeedBox.dispSpec
                showResulted = True
        End Sub

' buttons
        Private Sub btnStart_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
                Dim I
                btnStart_MouseMoveOut
                For I = 1 To 8
                        If InButton(MainButtons(I), X, Y) Then
                                btnMenu_MouseDown I, Button, Shift, X, Y
                                Exit For
                        End If
                Next
        End Sub
        Private Sub btnStart_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
            Dim I
            Dim speed As Double
            Dim an As Double
            Dim rot_center As IPOINT
            Dim end_angle As Double
            Dim l As Double

            If Not GoIntoMenu Then      ' 如果尚未进入菜单状态, 动画显示菜单
                MainButtons(0).CurPos = MainButtons(0).InitPos1
                ShowButton MainButtons(0), True
                GoIntoMenu = True

                speed = SPEED_VAL
                rot_center.X = MainButtons(0).InitPos1.X + MainButtons(0).picNormal.width / 2
                rot_center.Y = MainButtons(0).InitPos1.Y + MainButtons(0).picNormal.height / 2
                For an = 0 To PI / 3 Step speed
                    ' 动画过程中鼠标已移出区域, 这时通过GoIntoMenu=True强制btnStart_MouseMoveOut擦除残留信息
                    ' 并退出事件响应过程
                    If GoIntoMenu = False Then
                        GoIntoMenu = True
                        btnStart_MouseMoveOut
                        Exit Sub
                    End If
                    For I = 1 To 6
                        With MainButtons(I)
                            ' 确定是否继续旋转以及旋转角
                            end_angle = (.InitPos2.Y - .InitPos1.Y) / (rot_center.X - .InitPos1.X)
                            end_angle = Abs(Atn(end_angle))
                            If an - speed > end_angle Then GoTo IgnoreThis
                            If an > end_angle Then
                                end_angle = end_angle       ' 最大终极角度
                            Else
                                end_angle = an
                            End If

                            ' 计算该角度下旋转坐标
                            ' 首先使用中心点坐标系
                            .CurPos.X = .InitPos1.X + .picMask.width / 2
                            .CurPos.Y = .InitPos1.Y + .picMask.height / 2

                            l = -Sgn(rot_center.X - .InitPos1.X) * Sqr((rot_center.X - .CurPos.X) ^ 2 + (rot_center.Y - .CurPos.Y) ^ 2)
                            .CurPos.X = rot_center.X + l * Cos(end_angle)
                            .CurPos.Y = rot_center.Y - l * Sin(end_angle)

                            ' 转化到左上角坐标系
                            .CurPos.X = .CurPos.X - .picMask.width / 2
                            .CurPos.Y = .CurPos.Y - .picMask.height / 2
                        End With
                        ShowButton MainButtons(I), False
IgnoreThis:
                    Next
                    MainButtons(7).CurPos = MainButtons(7).InitPos1
                    MainButtons(8).CurPos = MainButtons(8).InitPos1
                    ShowButton MainButtons(7), False
                    ShowButton MainButtons(8), False
                    If picBack.AutoRedraw Then picBack.Refresh
                Next
            Else
                ' 进入菜单选择状态, 判断是否进入某个按钮区域
                For I = 1 To 8
                    If InButton(MainButtons(I), X, Y) Then
                        btnMenu_MouseMove I, Button, Shift, X, Y
                    Else
                        btnMenu_MouseMoveOut I
                    End If
                Next
            End If
        End Sub
        Private Sub btnStart_MouseMoveOut()
            Dim I
            If GoIntoMenu Then
                For I = 1 To 8
                    HideButton MainButtons(I)
                Next
                MainButtons(0).CurPos = MainButtons(0).InitPos1
                ShowButton MainButtons(0), False
                If picBack.AutoRedraw Then picBack.Refresh
                GoIntoMenu = False
            End If
        End Sub
        Private Sub btnStart_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
            Dim I
            For I = 1 To 8
                If InButton(MainButtons(I), X, Y) Then
                    btnMenu_MouseUp I, Button, Shift, X, Y
                    Exit For
                End If
            Next
        End Sub

        Private Sub btnMenu_MouseDown(ByVal Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
            Select Case Index
            Case 1: F_Practice
            Case 2: F_Test
            Case 3: F_Client
            Case 4: F_Handup
            Case 5: F_Manager
            Case 6: F_End
            Case 7: F_About
            Case 8: F_Help
            End Select
        End Sub
        Private Sub btnMenu_MouseMove(ByVal Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
                If Not MainButtons(Index).LastDrawIsDown Or Not MainButtons(Index).OnShow Then
                        ShowButton MainButtons(Index), True
                        If picBack.AutoRedraw Then picBack.Refresh
                End If
        End Sub
        Private Sub btnMenu_MouseMoveOut(ByVal Index As Integer)
                If MainButtons(Index).LastDrawIsDown Or Not MainButtons(Index).OnShow Then
                        ShowButton MainButtons(Index), False
                        If picBack.AutoRedraw Then picBack.Refresh
                End If
        End Sub
        Private Sub btnMenu_MouseUp(ByVal Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
        End Sub

' picBack
        Private Sub picBack_GotFocus()
                Dim r As Long

                If RunningMode <> M_Idle Then
                        r = CreateCaret(picBack.hWnd, 0, 3, 18)
                        ShowCaret picBack.hWnd
                        inputText.SetCaret
                End If
        End Sub
        Private Sub picBack_LostFocus()
                If RunningMode <> M_Idle Then
                        HideCaret picBack.hWnd
                        DestroyCaret
                End If
        End Sub

        Private Sub picBack_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
                If showResulted Then
                        Dim I As Integer
                        I = 5
                        Do While I < 260
                                BitBltAlphaSimple picBack.hdc, 100, 80, 440, 320, picBack3.hdc, 100, 80, 256 - IIf(I < 256, I, 256)
                                picBack.Refresh
                                I = I + 1 + I / 5
                        Loop
                        ClipCursor 0
                        tempText.DeleteAll
                        validText.DeleteAll
                        showResulted = False
                Else
                        bDown = True
                        If InBtnStart(X, Y) Then
                                btnStart_MouseDown Button, Shift, X, Y
                        End If
                        inputText.SetRowCol X, Y
                End If
        End Sub

        Private Sub picBack_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
                Static r As IRECT
                Static first As Integer
                If InBtnStart(X, Y) Then
                        btnStart_MouseMove Button, Shift, X, Y
                Else
                        btnStart_MouseMoveOut
                End If
                'lblI = X & "," & Y
                If bDown Then inputText.SetRowCol X, Y
        End Sub

        Private Sub picBack_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
                bDown = False
                If InBtnStart(X, Y) Then btnStart_MouseUp Button, Shift, X, Y
        End Sub

        Private Sub picBack_Paint()
                Static nPaints As Integer
                nPaints = nPaints + 1
                frmMain.Caption = nPaints
        End Sub

' sockets
        Private Sub sockS_Close(): callProcedure1 CurrentFN.ServerCall.procClose, 0: End Sub
        Private Sub sockS_Connect(): callProcedure1 CurrentFN.ServerCall.procConnect, 0: End Sub
        Private Sub sockS_ConnectionRequest(ByVal requestID As Long): callProcedure1 CurrentFN.ServerCall.procConnectionRequest, requestID: End Sub
        Private Sub sockS_DataArrival(ByVal bytesTotal As Long): callProcedure1 CurrentFN.ServerCall.procDataArrival, bytesTotal: End Sub
        Private Sub sockS_Error(ByVal number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
                With CurrentFN.ServerError
                        .number = number
                        .Description = Description
                        .Scode = Scode
                        .Source = Source
                        .HelpFile = HelpFile
                        .HelpContext = HelpContext
                        .CancelDisplay = CancelDisplay
                End With
                callProcedure1 CurrentFN.ServerCall.procError, number
        End Sub
        Private Sub sockS_SendComplete(): callProcedure1 CurrentFN.ServerCall.procSendComplete, 0: End Sub
        Private Sub sockS_SendProgress(ByVal bytesSent As Long, ByVal bytesRemaining As Long)
                CurrentFN.ServerSend.bytesSent = bytesSent
                CurrentFN.ServerSend.bytesRemaining = bytesRemaining
                callProcedure1 CurrentFN.ServerCall.procSendProgress, 0
        End Sub

        Private Sub sockC_Close(): callProcedure1 CurrentFN.ClientCall.procClose, 0: End Sub
        Private Sub sockC_Connect(): callProcedure1 CurrentFN.ClientCall.procConnect, 0: End Sub
        Private Sub sockC_ConnectionRequest(ByVal requestID As Long): callProcedure1 CurrentFN.ClientCall.procConnectionRequest, requestID: End Sub
        Private Sub sockC_DataArrival(ByVal bytesTotal As Long): callProcedure1 CurrentFN.ClientCall.procDataArrival, bytesTotal: End Sub
        Private Sub sockC_Error(ByVal number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
                With CurrentFN.ClientError
                        .number = number
                        .Description = Description
                        .Scode = Scode
                        .Source = Source
                        .HelpFile = HelpFile
                        .HelpContext = HelpContext
                        .CancelDisplay = CancelDisplay
                End With
                callProcedure1 CurrentFN.ClientCall.procError, number
        End Sub
        Private Sub sockC_SendComplete(): callProcedure1 CurrentFN.ClientCall.procSendComplete, 0: End Sub
        Private Sub sockC_SendProgress(ByVal bytesSent As Long, ByVal bytesRemaining As Long)
                CurrentFN.ClientSend.bytesSent = bytesSent
                CurrentFN.ClientSend.bytesRemaining = bytesRemaining
                callProcedure1 CurrentFN.ClientCall.procSendProgress, 0
        End Sub

' misc
        Private Sub tmrMain_Timer()
                Dim totals As Long

                lblTime.Visible = Mode <> M_Idle
                lblTime = deltaTime

                If Mode <> M_Idle And Mode <> M_Manager Then
                        With cResult
                                totals = .Right + .wrong + .extra
                                If totals > 1 Then
                                        fingerClient.CurrentAccuracy = (.Right / totals) * 100
                                Else
                                        fingerClient.CurrentAccuracy = 0
                                End If
                                totals = DeltaTimer
                                If totals > 1 Then
                                        fingerClient.CurrentSpeed = Len(inputContent & inputText.TextNL) / totals * 60
                                Else
                                        fingerClient.CurrentSpeed = 0
                                End If
                        End With
                        SpeedBox.Paint
                        AccuracyBox.Paint
                End If

                If bHandup And Mode = M_client Then
                        frmMessage.Run "交卷..."
                        F_Handup
                End If

                ' 确保至少有一个窗口打开
                        Dim visi As Boolean
                        visi = frmMain.Visible
                        visi = visi Or frmManager.Visible
                        visi = visi Or frmHoll.Visible
                        visi = visi Or frmApply.Visible
                        If Not visi Then frmMain.Visible = True
        End Sub

Private Sub tmrNet_Timer()
        If CurrentFN.Timeout.procTimer <> 0 Then
                callProcedure0 CurrentFN.Timeout.procTimer
        End If
End Sub

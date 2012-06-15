VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmMain
   BorderStyle     =   1  'Fixed Single
   Caption         =   "畅通游戏界 - 翔宇打补丁专家"
   ClientHeight    =   5880
   ClientLeft      =   1905
   ClientTop       =   2490
   ClientWidth     =   6345
   BeginProperty Font
      Name            =   "宋体"
      Size            =   9
      Charset         =   134
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "Main.frx":0000
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   392
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   423
   Begin VB.CommandButton cmdProcessRefresh
      Caption         =   "&R获取"
      Height          =   300
      Left            =   1035
      TabIndex        =   15
      Top             =   45
      Width           =   1035
   End
   Begin MSComctlLib.Slider sldPriority
      Height          =   210
      Left            =   3150
      TabIndex        =   14
      Top             =   90
      Width           =   3000
      _ExtentX        =   5292
      _ExtentY        =   370
      _Version        =   393216
      Max             =   100
      TickFrequency   =   10
   End
   Begin VB.ComboBox cboProcessList
      Height          =   300
      Left            =   135
      Style           =   2  'Dropdown List
      TabIndex        =   13
      Top             =   420
      Width           =   6015
   End
   Begin MSComctlLib.ImageList imgAPatch
      Index           =   0
      Left            =   4860
      Top             =   5400
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   32
      ImageHeight     =   32
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
         NumListImages   =   2
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":030A
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":0626
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.ImageList imgAPatch
      Index           =   1
      Left            =   5190
      Top             =   5400
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
         NumListImages   =   2
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":0942
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":0C5E
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.ListView lvPatch
      Height          =   1005
      Left            =   150
      TabIndex        =   11
      Top             =   4680
      Width           =   6060
      _ExtentX        =   10689
      _ExtentY        =   1773
      View            =   3
      LabelWrap       =   -1  'True
      HideSelection   =   0   'False
      AllowReorder    =   -1  'True
      GridLines       =   -1  'True
      _Version        =   393217
      Icons           =   "imgAPatch(0)"
      SmallIcons      =   "imgAPatch(1)"
      ColHdrIcons     =   "imgAPatch(1)"
      ForeColor       =   -2147483640
      BackColor       =   -2147483643
      Appearance      =   0
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      NumItems        =   7
      BeginProperty ColumnHeader(1) {BDD1F052-858B-11D1-B16A-00C0F0283628}
         Text            =   "补丁名称"
         Object.Width           =   2646
      EndProperty
      BeginProperty ColumnHeader(2) {BDD1F052-858B-11D1-B16A-00C0F0283628}
         SubItemIndex    =   1
         Text            =   "补丁地址"
         Object.Width           =   2117
      EndProperty
      BeginProperty ColumnHeader(3) {BDD1F052-858B-11D1-B16A-00C0F0283628}
         SubItemIndex    =   2
         Text            =   "值"
         Object.Width           =   1058
      EndProperty
      BeginProperty ColumnHeader(4) {BDD1F052-858B-11D1-B16A-00C0F0283628}
         SubItemIndex    =   3
         Text            =   "状态"
         Object.Width           =   1058
      EndProperty
      BeginProperty ColumnHeader(5) {BDD1F052-858B-11D1-B16A-00C0F0283628}
         SubItemIndex    =   4
         Text            =   "类别"
         Object.Width           =   1058
      EndProperty
      BeginProperty ColumnHeader(6) {BDD1F052-858B-11D1-B16A-00C0F0283628}
         SubItemIndex    =   5
         Text            =   "连接进程"
         Object.Width           =   1323
      EndProperty
      BeginProperty ColumnHeader(7) {BDD1F052-858B-11D1-B16A-00C0F0283628}
         SubItemIndex    =   6
         Text            =   "版本"
         Object.Width           =   1323
      EndProperty
   End
   Begin MSComctlLib.Slider Slider1
      Height          =   255
      Left            =   1515
      TabIndex        =   7
      Top             =   4335
      Width           =   4335
      _ExtentX        =   7646
      _ExtentY        =   450
      _Version        =   393216
      Max             =   50
   End
   Begin VB.Timer tmrRefresh
      Enabled         =   0   'False
      Interval        =   10
      Left            =   690
      Top             =   4245
   End
   Begin VB.Frame frmPatch
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1365
      Left            =   2655
      TabIndex        =   2
      Top             =   2805
      Width           =   3555
      Begin MSComctlLib.ImageList imgPatch
         Index           =   0
         Left            =   2415
         Top             =   240
         _ExtentX        =   1005
         _ExtentY        =   1005
         BackColor       =   -2147483643
         ImageWidth      =   32
         ImageHeight     =   32
         MaskColor       =   12632256
         _Version        =   393216
         BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
            NumListImages   =   3
            BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
               Picture         =   "Main.frx":0F7A
               Key             =   ""
            EndProperty
            BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
               Picture         =   "Main.frx":1296
               Key             =   ""
            EndProperty
            BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628}
               Picture         =   "Main.frx":15B2
               Key             =   ""
            EndProperty
         EndProperty
      End
      Begin MSComctlLib.Toolbar tbPatch
         Height          =   765
         Left            =   90
         TabIndex        =   6
         Top             =   180
         Width           =   1770
         _ExtentX        =   3122
         _ExtentY        =   1349
         ButtonWidth     =   1032
         ButtonHeight    =   1349
         Wrappable       =   0   'False
         Style           =   1
         ImageList       =   "imgPatch(0)"
         HotImageList    =   "imgPatch(1)"
         _Version        =   393216
         BeginProperty Buttons {66833FE8-8583-11D1-B16A-00C0F0283628}
            NumButtons      =   3
            BeginProperty Button1 {66833FEA-8583-11D1-B16A-00C0F0283628}
               Caption         =   "写入"
               Key             =   "WriteTo"
               ImageIndex      =   1
            EndProperty
            BeginProperty Button2 {66833FEA-8583-11D1-B16A-00C0F0283628}
               Caption         =   "刷新"
               Key             =   "Refresh"
               ImageIndex      =   2
            EndProperty
            BeginProperty Button3 {66833FEA-8583-11D1-B16A-00C0F0283628}
               Caption         =   "锁定"
               Key             =   "Lock"
               ImageIndex      =   3
               Style           =   1
            EndProperty
         EndProperty
      End
      Begin VB.TextBox txtNewValue
         Appearance      =   0  'Flat
         BackColor       =   &H8000000F&
         BorderStyle     =   0  'None
         Height          =   210
         Left            =   2130
         MaxLength       =   32
         TabIndex        =   5
         Top             =   1020
         Width           =   1320
      End
      Begin MSComctlLib.ImageList imgPatch
         Index           =   1
         Left            =   2670
         Top             =   225
         _ExtentX        =   1005
         _ExtentY        =   1005
         BackColor       =   -2147483643
         ImageWidth      =   32
         ImageHeight     =   32
         MaskColor       =   12632256
         _Version        =   393216
         BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
            NumListImages   =   3
            BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
               Picture         =   "Main.frx":18CE
               Key             =   ""
            EndProperty
            BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
               Picture         =   "Main.frx":1BEA
               Key             =   ""
            EndProperty
            BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628}
               Picture         =   "Main.frx":1F06
               Key             =   ""
            EndProperty
         EndProperty
      End
      Begin VB.Label Label2
         AutoSize        =   -1  'True
         Caption         =   "&N新数值"
         BeginProperty Font
            Name            =   "宋体"
            Size            =   11.25
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FFFFC0&
         Height          =   225
         Left            =   1245
         TabIndex        =   4
         Top             =   990
         Width           =   795
      End
      Begin VB.Label lblOldValue
         Caption         =   "原数值"
         BeginProperty Font
            Name            =   "宋体"
            Size            =   11.25
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00800000&
         Height          =   225
         Left            =   90
         TabIndex        =   3
         Top             =   990
         Width           =   675
      End
   End
   Begin MSComctlLib.ImageList imgtvMenu
      Left            =   1635
      Top             =   3375
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
         NumListImages   =   199
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2222
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2676
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2ACA
            Key             =   ""
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2F1E
            Key             =   ""
         EndProperty
         BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":3372
            Key             =   ""
         EndProperty
         BeginProperty ListImage6 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":37C6
            Key             =   ""
         EndProperty
         BeginProperty ListImage7 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":3C1A
            Key             =   ""
         EndProperty
         BeginProperty ListImage8 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":406E
            Key             =   ""
         EndProperty
         BeginProperty ListImage9 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":44C2
            Key             =   ""
         EndProperty
         BeginProperty ListImage10 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":4916
            Key             =   ""
         EndProperty
         BeginProperty ListImage11 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":4D6A
            Key             =   ""
         EndProperty
         BeginProperty ListImage12 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":51BE
            Key             =   ""
         EndProperty
         BeginProperty ListImage13 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":54DA
            Key             =   ""
         EndProperty
         BeginProperty ListImage14 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":592E
            Key             =   ""
         EndProperty
         BeginProperty ListImage15 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":5C4A
            Key             =   ""
         EndProperty
         BeginProperty ListImage16 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":5F66
            Key             =   ""
         EndProperty
         BeginProperty ListImage17 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":6282
            Key             =   ""
         EndProperty
         BeginProperty ListImage18 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":66D6
            Key             =   ""
         EndProperty
         BeginProperty ListImage19 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":6B2A
            Key             =   ""
         EndProperty
         BeginProperty ListImage20 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":6F7E
            Key             =   ""
         EndProperty
         BeginProperty ListImage21 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":73D2
            Key             =   ""
         EndProperty
         BeginProperty ListImage22 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":7B26
            Key             =   ""
         EndProperty
         BeginProperty ListImage23 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":7E42
            Key             =   ""
         EndProperty
         BeginProperty ListImage24 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":8296
            Key             =   ""
         EndProperty
         BeginProperty ListImage25 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":89EA
            Key             =   ""
         EndProperty
         BeginProperty ListImage26 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":8E3E
            Key             =   ""
         EndProperty
         BeginProperty ListImage27 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":9292
            Key             =   ""
         EndProperty
         BeginProperty ListImage28 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":96E6
            Key             =   ""
         EndProperty
         BeginProperty ListImage29 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":9B3A
            Key             =   ""
         EndProperty
         BeginProperty ListImage30 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":9E56
            Key             =   ""
         EndProperty
         BeginProperty ListImage31 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":A172
            Key             =   ""
         EndProperty
         BeginProperty ListImage32 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":A5C6
            Key             =   ""
         EndProperty
         BeginProperty ListImage33 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":AA1A
            Key             =   ""
         EndProperty
         BeginProperty ListImage34 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":AE6E
            Key             =   ""
         EndProperty
         BeginProperty ListImage35 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":B2CA
            Key             =   ""
         EndProperty
         BeginProperty ListImage36 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":B71E
            Key             =   ""
         EndProperty
         BeginProperty ListImage37 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":BB72
            Key             =   ""
         EndProperty
         BeginProperty ListImage38 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":BFC6
            Key             =   ""
         EndProperty
         BeginProperty ListImage39 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":C41A
            Key             =   ""
         EndProperty
         BeginProperty ListImage40 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":C86E
            Key             =   ""
         EndProperty
         BeginProperty ListImage41 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":CCC2
            Key             =   ""
         EndProperty
         BeginProperty ListImage42 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":D116
            Key             =   ""
         EndProperty
         BeginProperty ListImage43 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":D56A
            Key             =   ""
         EndProperty
         BeginProperty ListImage44 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":D9BE
            Key             =   ""
         EndProperty
         BeginProperty ListImage45 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":DE12
            Key             =   ""
         EndProperty
         BeginProperty ListImage46 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":E266
            Key             =   ""
         EndProperty
         BeginProperty ListImage47 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":E6BA
            Key             =   ""
         EndProperty
         BeginProperty ListImage48 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":EB0E
            Key             =   ""
         EndProperty
         BeginProperty ListImage49 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":EF62
            Key             =   ""
         EndProperty
         BeginProperty ListImage50 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":F3B6
            Key             =   ""
         EndProperty
         BeginProperty ListImage51 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":F80A
            Key             =   ""
         EndProperty
         BeginProperty ListImage52 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":FC5E
            Key             =   ""
         EndProperty
         BeginProperty ListImage53 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":100B2
            Key             =   ""
         EndProperty
         BeginProperty ListImage54 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":10506
            Key             =   ""
         EndProperty
         BeginProperty ListImage55 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1095A
            Key             =   ""
         EndProperty
         BeginProperty ListImage56 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":10DAE
            Key             =   ""
         EndProperty
         BeginProperty ListImage57 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":11202
            Key             =   ""
         EndProperty
         BeginProperty ListImage58 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":11656
            Key             =   ""
         EndProperty
         BeginProperty ListImage59 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":11AAA
            Key             =   ""
         EndProperty
         BeginProperty ListImage60 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":11EFE
            Key             =   ""
         EndProperty
         BeginProperty ListImage61 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":12352
            Key             =   ""
         EndProperty
         BeginProperty ListImage62 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":127A6
            Key             =   ""
         EndProperty
         BeginProperty ListImage63 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":12BFA
            Key             =   ""
         EndProperty
         BeginProperty ListImage64 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1304E
            Key             =   ""
         EndProperty
         BeginProperty ListImage65 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":134A2
            Key             =   ""
         EndProperty
         BeginProperty ListImage66 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":138F6
            Key             =   ""
         EndProperty
         BeginProperty ListImage67 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":13D4A
            Key             =   ""
         EndProperty
         BeginProperty ListImage68 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1419E
            Key             =   ""
         EndProperty
         BeginProperty ListImage69 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":145F2
            Key             =   ""
         EndProperty
         BeginProperty ListImage70 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":14A46
            Key             =   ""
         EndProperty
         BeginProperty ListImage71 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":14E9A
            Key             =   ""
         EndProperty
         BeginProperty ListImage72 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":152EE
            Key             =   ""
         EndProperty
         BeginProperty ListImage73 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":15742
            Key             =   ""
         EndProperty
         BeginProperty ListImage74 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":15B96
            Key             =   ""
         EndProperty
         BeginProperty ListImage75 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":15FEA
            Key             =   ""
         EndProperty
         BeginProperty ListImage76 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1643E
            Key             =   ""
         EndProperty
         BeginProperty ListImage77 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":16892
            Key             =   ""
         EndProperty
         BeginProperty ListImage78 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":16CE6
            Key             =   ""
         EndProperty
         BeginProperty ListImage79 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1713A
            Key             =   ""
         EndProperty
         BeginProperty ListImage80 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1758E
            Key             =   ""
         EndProperty
         BeginProperty ListImage81 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":179E2
            Key             =   ""
         EndProperty
         BeginProperty ListImage82 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":17E36
            Key             =   ""
         EndProperty
         BeginProperty ListImage83 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1858A
            Key             =   ""
         EndProperty
         BeginProperty ListImage84 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":189DE
            Key             =   ""
         EndProperty
         BeginProperty ListImage85 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":18E32
            Key             =   ""
         EndProperty
         BeginProperty ListImage86 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":19286
            Key             =   ""
         EndProperty
         BeginProperty ListImage87 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":196DA
            Key             =   ""
         EndProperty
         BeginProperty ListImage88 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":19B2E
            Key             =   ""
         EndProperty
         BeginProperty ListImage89 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":19F82
            Key             =   ""
         EndProperty
         BeginProperty ListImage90 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1A3D6
            Key             =   ""
         EndProperty
         BeginProperty ListImage91 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1A82A
            Key             =   ""
         EndProperty
         BeginProperty ListImage92 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1AC7E
            Key             =   ""
         EndProperty
         BeginProperty ListImage93 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1B0D2
            Key             =   ""
         EndProperty
         BeginProperty ListImage94 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1B526
            Key             =   ""
         EndProperty
         BeginProperty ListImage95 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1B982
            Key             =   ""
         EndProperty
         BeginProperty ListImage96 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1BDDE
            Key             =   ""
         EndProperty
         BeginProperty ListImage97 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1C232
            Key             =   ""
         EndProperty
         BeginProperty ListImage98 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1C686
            Key             =   ""
         EndProperty
         BeginProperty ListImage99 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1CADA
            Key             =   ""
         EndProperty
         BeginProperty ListImage100 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1CF2E
            Key             =   ""
         EndProperty
         BeginProperty ListImage101 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1D24A
            Key             =   ""
         EndProperty
         BeginProperty ListImage102 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1D69E
            Key             =   ""
         EndProperty
         BeginProperty ListImage103 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1DAF2
            Key             =   ""
         EndProperty
         BeginProperty ListImage104 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1E246
            Key             =   ""
         EndProperty
         BeginProperty ListImage105 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1E6A2
            Key             =   ""
         EndProperty
         BeginProperty ListImage106 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1EDF6
            Key             =   ""
         EndProperty
         BeginProperty ListImage107 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1F24A
            Key             =   ""
         EndProperty
         BeginProperty ListImage108 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1F69E
            Key             =   ""
         EndProperty
         BeginProperty ListImage109 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1FAF2
            Key             =   ""
         EndProperty
         BeginProperty ListImage110 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":1FF46
            Key             =   ""
         EndProperty
         BeginProperty ListImage111 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2039A
            Key             =   ""
         EndProperty
         BeginProperty ListImage112 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":207EE
            Key             =   ""
         EndProperty
         BeginProperty ListImage113 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":20C42
            Key             =   ""
         EndProperty
         BeginProperty ListImage114 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":21096
            Key             =   ""
         EndProperty
         BeginProperty ListImage115 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":214EA
            Key             =   ""
         EndProperty
         BeginProperty ListImage116 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2193E
            Key             =   ""
         EndProperty
         BeginProperty ListImage117 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":21D92
            Key             =   ""
         EndProperty
         BeginProperty ListImage118 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":221E6
            Key             =   ""
         EndProperty
         BeginProperty ListImage119 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2263A
            Key             =   ""
         EndProperty
         BeginProperty ListImage120 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":22A8E
            Key             =   ""
         EndProperty
         BeginProperty ListImage121 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":22EE2
            Key             =   ""
         EndProperty
         BeginProperty ListImage122 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":23336
            Key             =   ""
         EndProperty
         BeginProperty ListImage123 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2378A
            Key             =   ""
         EndProperty
         BeginProperty ListImage124 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":23BDE
            Key             =   ""
         EndProperty
         BeginProperty ListImage125 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":24032
            Key             =   ""
         EndProperty
         BeginProperty ListImage126 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":24486
            Key             =   ""
         EndProperty
         BeginProperty ListImage127 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":248DA
            Key             =   ""
         EndProperty
         BeginProperty ListImage128 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":24D2E
            Key             =   ""
         EndProperty
         BeginProperty ListImage129 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":25182
            Key             =   ""
         EndProperty
         BeginProperty ListImage130 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":255D6
            Key             =   ""
         EndProperty
         BeginProperty ListImage131 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":25A2A
            Key             =   ""
         EndProperty
         BeginProperty ListImage132 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":25E7E
            Key             =   ""
         EndProperty
         BeginProperty ListImage133 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":262D2
            Key             =   ""
         EndProperty
         BeginProperty ListImage134 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":26726
            Key             =   ""
         EndProperty
         BeginProperty ListImage135 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":26B7A
            Key             =   ""
         EndProperty
         BeginProperty ListImage136 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":26FCE
            Key             =   ""
         EndProperty
         BeginProperty ListImage137 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":27422
            Key             =   ""
         EndProperty
         BeginProperty ListImage138 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":27876
            Key             =   ""
         EndProperty
         BeginProperty ListImage139 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":27CCA
            Key             =   ""
         EndProperty
         BeginProperty ListImage140 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2811E
            Key             =   ""
         EndProperty
         BeginProperty ListImage141 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":28572
            Key             =   ""
         EndProperty
         BeginProperty ListImage142 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":289C6
            Key             =   ""
         EndProperty
         BeginProperty ListImage143 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":28E1A
            Key             =   ""
         EndProperty
         BeginProperty ListImage144 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2926E
            Key             =   ""
         EndProperty
         BeginProperty ListImage145 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":296C2
            Key             =   ""
         EndProperty
         BeginProperty ListImage146 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":29B16
            Key             =   ""
         EndProperty
         BeginProperty ListImage147 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":29F6A
            Key             =   ""
         EndProperty
         BeginProperty ListImage148 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2A3BE
            Key             =   ""
         EndProperty
         BeginProperty ListImage149 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2A812
            Key             =   ""
         EndProperty
         BeginProperty ListImage150 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2AC66
            Key             =   ""
         EndProperty
         BeginProperty ListImage151 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2B0BA
            Key             =   ""
         EndProperty
         BeginProperty ListImage152 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2B80E
            Key             =   ""
         EndProperty
         BeginProperty ListImage153 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2BC62
            Key             =   ""
         EndProperty
         BeginProperty ListImage154 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2C0B6
            Key             =   ""
         EndProperty
         BeginProperty ListImage155 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2C50A
            Key             =   ""
         EndProperty
         BeginProperty ListImage156 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2C95E
            Key             =   ""
         EndProperty
         BeginProperty ListImage157 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2CDB2
            Key             =   ""
         EndProperty
         BeginProperty ListImage158 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2D206
            Key             =   ""
         EndProperty
         BeginProperty ListImage159 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2D65A
            Key             =   ""
         EndProperty
         BeginProperty ListImage160 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2DAAE
            Key             =   ""
         EndProperty
         BeginProperty ListImage161 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2DF02
            Key             =   ""
         EndProperty
         BeginProperty ListImage162 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2E356
            Key             =   ""
         EndProperty
         BeginProperty ListImage163 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2E7AA
            Key             =   ""
         EndProperty
         BeginProperty ListImage164 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2EBFE
            Key             =   ""
         EndProperty
         BeginProperty ListImage165 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2F052
            Key             =   ""
         EndProperty
         BeginProperty ListImage166 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2F4A6
            Key             =   ""
         EndProperty
         BeginProperty ListImage167 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2F8FA
            Key             =   ""
         EndProperty
         BeginProperty ListImage168 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":2FD4E
            Key             =   ""
         EndProperty
         BeginProperty ListImage169 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":301A2
            Key             =   ""
         EndProperty
         BeginProperty ListImage170 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":305F6
            Key             =   ""
         EndProperty
         BeginProperty ListImage171 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":30A4A
            Key             =   ""
         EndProperty
         BeginProperty ListImage172 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":30E9E
            Key             =   ""
         EndProperty
         BeginProperty ListImage173 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":312F2
            Key             =   ""
         EndProperty
         BeginProperty ListImage174 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":31746
            Key             =   ""
         EndProperty
         BeginProperty ListImage175 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":31B9A
            Key             =   ""
         EndProperty
         BeginProperty ListImage176 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":31FEE
            Key             =   ""
         EndProperty
         BeginProperty ListImage177 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":32442
            Key             =   ""
         EndProperty
         BeginProperty ListImage178 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":32896
            Key             =   ""
         EndProperty
         BeginProperty ListImage179 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":32CEA
            Key             =   ""
         EndProperty
         BeginProperty ListImage180 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":3313E
            Key             =   ""
         EndProperty
         BeginProperty ListImage181 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":33592
            Key             =   ""
         EndProperty
         BeginProperty ListImage182 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":339E6
            Key             =   ""
         EndProperty
         BeginProperty ListImage183 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":33E3A
            Key             =   ""
         EndProperty
         BeginProperty ListImage184 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":3428E
            Key             =   ""
         EndProperty
         BeginProperty ListImage185 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":346E2
            Key             =   ""
         EndProperty
         BeginProperty ListImage186 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":34B36
            Key             =   ""
         EndProperty
         BeginProperty ListImage187 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":34F8A
            Key             =   ""
         EndProperty
         BeginProperty ListImage188 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":353DE
            Key             =   ""
         EndProperty
         BeginProperty ListImage189 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":35832
            Key             =   ""
         EndProperty
         BeginProperty ListImage190 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":35C86
            Key             =   ""
         EndProperty
         BeginProperty ListImage191 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":360DA
            Key             =   ""
         EndProperty
         BeginProperty ListImage192 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":3652E
            Key             =   ""
         EndProperty
         BeginProperty ListImage193 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":36982
            Key             =   ""
         EndProperty
         BeginProperty ListImage194 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":36DD6
            Key             =   ""
         EndProperty
         BeginProperty ListImage195 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":3722A
            Key             =   ""
         EndProperty
         BeginProperty ListImage196 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":3767E
            Key             =   ""
         EndProperty
         BeginProperty ListImage197 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":37AD2
            Key             =   ""
         EndProperty
         BeginProperty ListImage198 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":37F26
            Key             =   ""
         EndProperty
         BeginProperty ListImage199 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "Main.frx":3837A
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin VB.TextBox txtText
      BorderStyle     =   0  'None
      BeginProperty Font
         Name            =   "宋体"
         Size            =   11.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   2085
      Left            =   2655
      MultiLine       =   -1  'True
      TabIndex        =   1
      Text            =   "Main.frx":387CE
      Top             =   750
      Width           =   3540
   End
   Begin MSComctlLib.TreeView tvMenu
      Height          =   3435
      Left            =   165
      TabIndex        =   0
      Top             =   750
      Width           =   2400
      _ExtentX        =   4233
      _ExtentY        =   6059
      _Version        =   393217
      Indentation     =   564
      Style           =   7
      ImageList       =   "imgtvMenu"
      Appearance      =   0
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "优先级筛选"
      ForeColor       =   &H00C0FFC0&
      Height          =   180
      Left            =   2190
      TabIndex        =   16
      Top             =   90
      Width           =   900
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "进程连接"
      ForeColor       =   &H00C0FFFF&
      Height          =   180
      Left            =   180
      TabIndex        =   12
      Top             =   120
      Width           =   720
   End
   Begin VB.Label lblSFast
      AutoSize        =   -1  'True
      Caption         =   "高"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   11.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   225
      Left            =   5850
      TabIndex        =   10
      Top             =   4335
      Width           =   225
   End
   Begin VB.Label lblSSlow
      AutoSize        =   -1  'True
      Caption         =   "低"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   11.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000040&
      Height          =   255
      Left            =   1155
      TabIndex        =   9
      Top             =   4335
      Width           =   255
   End
   Begin VB.Label lblSmart
      AutoSize        =   -1  'True
      Caption         =   "灵敏度"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   11.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   195
      TabIndex        =   8
      Top             =   4335
      Width           =   735
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Dim PatchLock As Boolean

Sub WriteProcess(ByVal Address As Long, ByVal Value As Long, ByVal VType As String)
    Dim hProcess As Long
    hProcess = OpenProcess(PROCESS_VM_WRITE, False, cboProcessList.ItemData(cboProcessList.ListIndex))
    If hProcess <> 0 Then
        WriteProcessMemory hProcess, Address, Buf, IIf(VType = "B", 1, IIf(VType = "W", 2, 4)), Null
        CloseHandle hProcess
    End If
End Sub

Private Sub cmdProcessRefresh_Click()
    TEnumProcess cboProcessList
End Sub

Private Sub Form_Load()
    Dim Ret As FileError
    Dim RetMB As VbMsgBoxResult
    Dim x As ListItem

    Do
        Ret = ReadDir(XYPatchFile, tvMenu)
        If Ret.Error Then
            RetMB = MsgBox(Ret.Message, vbRetryCancel, "读入数据错:" + Err.Description)
            If RetMB = vbCancel Then End
        End If
    Loop While Ret.Error

    PatchLock = False

    Set x = lvPatch.ListItems.Add(, , "1234", 1, 1)
    x.SubItems(1) = "aaaaaa"
    'x.EnsureVisible
End Sub

Private Sub Slider1_Change()
    Dim vr1 As Integer, vr2 As Integer
    Dim vg1 As Integer, vg2 As Integer
    Dim vb1 As Integer, vb2 As Integer
    Dim sscale As Single
    vr1 = lblSSlow.ForeColor And &HFF: vr2 = lblSFast.ForeColor And &HFF
    vg1 = (lblSSlow.ForeColor And &HFF00) / &H100: vg2 = (lblSFast.ForeColor And &HFF00) / &H100
    vb1 = (lblSSlow.ForeColor And &HFF0000) / &H10000: vb2 = (lblSFast.ForeColor And &HFF0000) / &H10000
    sscale = Slider1.Value / (Slider1.Max - Slider1.Min)
    lblSmart.ForeColor = RGB(vr1 + (vr2 - vr1) * sscale, vg1 + (vg2 - vg1) * sscale, vb1 + (vb2 - vb1) * sscale)
End Sub

Private Sub tbPatch_ButtonClick(ByVal Button As MSComctlLib.Button)
    Select Case Button.Key
        Case "WriteTo"
            MsgBox "程序引起保护错误: cannot attach process", vbCritical
        Case "Refresh"

        Case "Lock"
            PatchLock = Button.Value = tbrPressed
    End Select
End Sub

Private Sub tmrRefresh_Timer()
    Dim i As Integer
    For i = 1 To lvPatch.ListItems.Count
        With lvPatch.ListItems(i)
            WriteProcess .SubItems(1), .SubItems(2), .SubItems(4)
        End With
    Next
End Sub

Private Sub tvMenu_Click()
    Dim dt As TagData
    Dim pt As PatchType
    Dim li As ListItem

    If tvMenu.SelectedItem.Tag = "" Then
        txtText = tvMenu.SelectedItem.Text
    Else
        dt = GetTag(tvMenu.SelectedItem.Tag)
        If dt.DataType = dtText Then
            txtText = dt.Src
        Else
            lvPatch.ListItems.Clear
            pt = EnumPatch(dt.Src, True)
            While pt.Address <> 0
                Set li = lvPatch.ListItems.Add(, , pt.VarName, IIf(pt.Locked = "T", 1, 2), IIf(pt.Locked = "T", 1, 2))
                li.SubItems(1) = Hex(pt.Address)
                li.SubItems(2) = Str(pt.Value)
                li.SubItems(3) = IIf(pt.Locked = "T", "锁定", "手工")
                Select Case pt.VarLength
                    Case "1": li.SubItems(4) = "字节"
                    Case "2": li.SubItems(4) = "字"
                    Case "4": li.SubItems(4) = "双字"
                End Select

                li.SubItems(6) = pt.Version
                pt = EnumPatch(dt.Src)
            Wend
        End If
    End If
End Sub

Private Sub tvMenu_KeyUp(KeyCode As Integer, Shift As Integer)
    tvMenu_Click
End Sub

VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form memory
   Caption         =   "进程内存分析"
   ClientHeight    =   4245
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7110
   LinkTopic       =   "Form2"
   ScaleHeight     =   4245
   ScaleWidth      =   7110
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame Frame1
      Caption         =   "内存动态分析"
      Height          =   3915
      Left            =   4005
      TabIndex        =   80
      Top             =   120
      Width           =   3105
      Begin VB.TextBox aEnd
         Height          =   315
         Left            =   1425
         TabIndex        =   84
         Text            =   "00138000"
         Top             =   630
         Width           =   1545
      End
      Begin VB.TextBox aStart
         Height          =   315
         Left            =   1425
         TabIndex        =   82
         Text            =   "0012D000"
         Top             =   255
         Width           =   1545
      End
      Begin VB.CommandButton savemem
         Caption         =   "存储进程内存"
         Height          =   375
         Left            =   90
         TabIndex        =   85
         Top             =   1110
         Width           =   1455
      End
      Begin VB.CommandButton loadmem
         Caption         =   "恢复进程内存"
         Height          =   375
         Left            =   1650
         TabIndex        =   86
         Top             =   1110
         Width           =   1455
      End
      Begin VB.TextBox analyseval
         Appearance      =   0  'Flat
         Height          =   270
         Left            =   1560
         TabIndex        =   88
         Text            =   "0"
         Top             =   1665
         Width           =   1455
      End
      Begin VB.ListBox lstFound
         Height          =   1035
         Left            =   135
         TabIndex        =   91
         Top             =   2655
         Width           =   2895
      End
      Begin VB.CommandButton cmdadd
         Caption         =   "加入分析点"
         Height          =   375
         Left            =   105
         TabIndex        =   89
         Top             =   1995
         Width           =   1335
      End
      Begin VB.CommandButton cmdreset
         Caption         =   "复位"
         Height          =   375
         Left            =   2175
         TabIndex        =   90
         Top             =   2010
         Width           =   855
      End
      Begin VB.Label founded
         AutoSize        =   -1  'True
         Caption         =   "founded"
         Height          =   195
         Left            =   135
         TabIndex        =   92
         Top             =   2415
         Width           =   585
      End
      Begin VB.Label Label3
         AutoSize        =   -1  'True
         Caption         =   "分析结束地址"
         Height          =   195
         Index           =   1
         Left            =   90
         TabIndex        =   83
         Top             =   675
         Width           =   1080
      End
      Begin VB.Label Label3
         AutoSize        =   -1  'True
         Caption         =   "分析起始地址"
         Height          =   195
         Index           =   0
         Left            =   90
         TabIndex        =   81
         Top             =   330
         Width           =   1080
      End
      Begin VB.Label Label4
         AutoSize        =   -1  'True
         Caption         =   "数值(用16进制)"
         Height          =   180
         Left            =   135
         TabIndex        =   87
         Top             =   1725
         Width           =   1260
      End
   End
   Begin MSComDlg.CommonDialog cd
      Left            =   1890
      Top             =   90
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      CancelError     =   -1  'True
   End
   Begin VB.CommandButton PageDown
      Caption         =   "下页"
      Height          =   375
      Left            =   855
      TabIndex        =   78
      Top             =   3660
      Width           =   630
   End
   Begin VB.CommandButton PageUp
      Caption         =   "上页"
      Height          =   375
      Left            =   165
      TabIndex        =   77
      Top             =   3660
      Width           =   630
   End
   Begin VB.CommandButton Command4
      Caption         =   "将修改结果写到进程内存"
      Height          =   375
      Left            =   1620
      TabIndex        =   79
      Top             =   3660
      Width           =   2280
   End
   Begin VB.CommandButton Command3
      Caption         =   "刷新"
      Height          =   375
      Left            =   2880
      TabIndex        =   4
      Top             =   600
      Width           =   975
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   63
      Left            =   3480
      TabIndex        =   76
      Text            =   "00"
      Top             =   3285
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   62
      Left            =   3120
      TabIndex        =   75
      Text            =   "00"
      Top             =   3285
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   61
      Left            =   2760
      TabIndex        =   74
      Text            =   "00"
      Top             =   3285
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   60
      Left            =   2400
      TabIndex        =   73
      Text            =   "00"
      Top             =   3285
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   59
      Left            =   2040
      TabIndex        =   72
      Text            =   "00"
      Top             =   3285
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   58
      Left            =   1680
      TabIndex        =   71
      Text            =   "00"
      Top             =   3285
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   57
      Left            =   1320
      TabIndex        =   70
      Text            =   "00"
      Top             =   3285
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   56
      Left            =   960
      TabIndex        =   69
      Text            =   "00"
      Top             =   3285
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   55
      Left            =   3480
      TabIndex        =   67
      Text            =   "00"
      Top             =   2970
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   54
      Left            =   3120
      TabIndex        =   66
      Text            =   "00"
      Top             =   2970
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   53
      Left            =   2760
      TabIndex        =   65
      Text            =   "00"
      Top             =   2970
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   52
      Left            =   2400
      TabIndex        =   64
      Text            =   "00"
      Top             =   2970
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   51
      Left            =   2040
      TabIndex        =   63
      Text            =   "00"
      Top             =   2970
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   50
      Left            =   1680
      TabIndex        =   62
      Text            =   "00"
      Top             =   2970
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   49
      Left            =   1320
      TabIndex        =   61
      Text            =   "00"
      Top             =   2970
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   48
      Left            =   960
      TabIndex        =   60
      Text            =   "00"
      Top             =   2970
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   47
      Left            =   3480
      TabIndex        =   58
      Text            =   "00"
      Top             =   2670
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   46
      Left            =   3120
      TabIndex        =   57
      Text            =   "00"
      Top             =   2670
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   45
      Left            =   2760
      TabIndex        =   56
      Text            =   "00"
      Top             =   2670
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   44
      Left            =   2400
      TabIndex        =   55
      Text            =   "00"
      Top             =   2670
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   43
      Left            =   2040
      TabIndex        =   54
      Text            =   "00"
      Top             =   2670
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   42
      Left            =   1680
      TabIndex        =   53
      Text            =   "00"
      Top             =   2670
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   41
      Left            =   1320
      TabIndex        =   52
      Text            =   "00"
      Top             =   2670
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   40
      Left            =   960
      TabIndex        =   51
      Text            =   "00"
      Top             =   2670
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   39
      Left            =   3480
      TabIndex        =   49
      Text            =   "00"
      Top             =   2355
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   38
      Left            =   3120
      TabIndex        =   48
      Text            =   "00"
      Top             =   2355
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   37
      Left            =   2760
      TabIndex        =   47
      Text            =   "00"
      Top             =   2355
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   36
      Left            =   2400
      TabIndex        =   46
      Text            =   "00"
      Top             =   2355
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   35
      Left            =   2040
      TabIndex        =   45
      Text            =   "00"
      Top             =   2355
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   34
      Left            =   1680
      TabIndex        =   44
      Text            =   "00"
      Top             =   2355
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   33
      Left            =   1320
      TabIndex        =   43
      Text            =   "00"
      Top             =   2355
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   32
      Left            =   960
      TabIndex        =   42
      Text            =   "00"
      Top             =   2355
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   31
      Left            =   3480
      TabIndex        =   40
      Text            =   "00"
      Top             =   2040
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   30
      Left            =   3120
      TabIndex        =   39
      Text            =   "00"
      Top             =   2040
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   29
      Left            =   2760
      TabIndex        =   38
      Text            =   "00"
      Top             =   2040
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   28
      Left            =   2400
      TabIndex        =   37
      Text            =   "00"
      Top             =   2040
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   27
      Left            =   2040
      TabIndex        =   36
      Text            =   "00"
      Top             =   2040
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   26
      Left            =   1680
      TabIndex        =   35
      Text            =   "00"
      Top             =   2040
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   25
      Left            =   1320
      TabIndex        =   34
      Text            =   "00"
      Top             =   2040
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   24
      Left            =   960
      TabIndex        =   33
      Text            =   "00"
      Top             =   2040
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   23
      Left            =   3480
      TabIndex        =   31
      Text            =   "00"
      Top             =   1725
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   22
      Left            =   3120
      TabIndex        =   30
      Text            =   "00"
      Top             =   1725
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   21
      Left            =   2760
      TabIndex        =   29
      Text            =   "00"
      Top             =   1725
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   20
      Left            =   2400
      TabIndex        =   28
      Text            =   "00"
      Top             =   1725
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   19
      Left            =   2040
      TabIndex        =   27
      Text            =   "00"
      Top             =   1725
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   18
      Left            =   1680
      TabIndex        =   26
      Text            =   "00"
      Top             =   1725
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   17
      Left            =   1320
      TabIndex        =   25
      Text            =   "00"
      Top             =   1725
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   16
      Left            =   960
      TabIndex        =   24
      Text            =   "00"
      Top             =   1725
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   15
      Left            =   3480
      TabIndex        =   22
      Text            =   "00"
      Top             =   1410
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   14
      Left            =   3120
      TabIndex        =   21
      Text            =   "00"
      Top             =   1410
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   13
      Left            =   2760
      TabIndex        =   20
      Text            =   "00"
      Top             =   1410
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   12
      Left            =   2400
      TabIndex        =   19
      Text            =   "00"
      Top             =   1410
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   11
      Left            =   2040
      TabIndex        =   18
      Text            =   "00"
      Top             =   1410
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   10
      Left            =   1680
      TabIndex        =   17
      Text            =   "00"
      Top             =   1410
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   9
      Left            =   1320
      TabIndex        =   16
      Text            =   "00"
      Top             =   1410
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   8
      Left            =   960
      TabIndex        =   15
      Text            =   "00"
      Top             =   1410
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   7
      Left            =   3480
      TabIndex        =   13
      Text            =   "00"
      Top             =   1080
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   6
      Left            =   3120
      TabIndex        =   12
      Text            =   "00"
      Top             =   1080
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   5
      Left            =   2760
      TabIndex        =   11
      Text            =   "00"
      Top             =   1080
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   4
      Left            =   2400
      TabIndex        =   10
      Text            =   "00"
      Top             =   1080
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   3
      Left            =   2040
      TabIndex        =   9
      Text            =   "00"
      Top             =   1080
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   2
      Left            =   1680
      TabIndex        =   8
      Text            =   "00"
      Top             =   1080
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   230
      Index           =   1
      Left            =   1320
      TabIndex        =   7
      Text            =   "00"
      Top             =   1080
      Width           =   350
   End
   Begin VB.TextBox box
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      Height          =   225
      Index           =   0
      Left            =   960
      TabIndex        =   6
      Text            =   "00"
      Top             =   1080
      Width           =   350
   End
   Begin VB.TextBox txtAddr
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   930
      TabIndex        =   3
      Text            =   "0"
      Top             =   720
      Width           =   1725
   End
   Begin VB.Label add
      AutoSize        =   -1  'True
      Caption         =   "00000000"
      Height          =   180
      Index           =   7
      Left            =   120
      TabIndex        =   68
      Top             =   3285
      Width           =   720
   End
   Begin VB.Label add
      AutoSize        =   -1  'True
      Caption         =   "00000000"
      Height          =   180
      Index           =   6
      Left            =   120
      TabIndex        =   59
      Top             =   2970
      Width           =   720
   End
   Begin VB.Label add
      AutoSize        =   -1  'True
      Caption         =   "00000000"
      Height          =   180
      Index           =   5
      Left            =   120
      TabIndex        =   50
      Top             =   2670
      Width           =   720
   End
   Begin VB.Label add
      AutoSize        =   -1  'True
      Caption         =   "00000000"
      Height          =   180
      Index           =   4
      Left            =   120
      TabIndex        =   41
      Top             =   2355
      Width           =   720
   End
   Begin VB.Label add
      AutoSize        =   -1  'True
      Caption         =   "00000000"
      Height          =   180
      Index           =   3
      Left            =   120
      TabIndex        =   32
      Top             =   2040
      Width           =   720
   End
   Begin VB.Label add
      AutoSize        =   -1  'True
      Caption         =   "00000000"
      Height          =   180
      Index           =   2
      Left            =   120
      TabIndex        =   23
      Top             =   1725
      Width           =   720
   End
   Begin VB.Label add
      AutoSize        =   -1  'True
      Caption         =   "00000000"
      Height          =   180
      Index           =   1
      Left            =   120
      TabIndex        =   14
      Top             =   1410
      Width           =   720
   End
   Begin VB.Label add
      AutoSize        =   -1  'True
      Caption         =   "00000000"
      Height          =   180
      Index           =   0
      Left            =   120
      TabIndex        =   5
      Top             =   1080
      Width           =   720
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "地址:"
      Height          =   195
      Index           =   0
      Left            =   120
      TabIndex        =   2
      Top             =   720
      Width           =   405
   End
   Begin VB.Label txtPID
      AutoSize        =   -1  'True
      Caption         =   "."
      Height          =   180
      Left            =   1320
      TabIndex        =   1
      Top             =   330
      Width           =   90
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "进程ID:"
      Height          =   180
      Index           =   1
      Left            =   135
      TabIndex        =   0
      Top             =   345
      Width           =   630
   End
End
Attribute VB_Name = "memory"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

' 添加分析
Private Sub cmdadd_Click()
        Dim pid
        Dim h As Long

        ' 打开进程PID，获取进程句柄h。用于AddAnalyse函数
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_READ, 0, pid)
        If h = 0 Then
                MsgBox "不能打开进程，这可能是系统进程。"
                Exit Sub
        End If
        analyseval = analyseval Mod 256
        AddAnalyse h, val(analyseval)

        ' hsize是分析缓存的大小。因为每个字节单元对应于一个地址，
        ' 因此 hsize 是实际单元数目的4倍
        founded = "已找到" & hsize / 4 & "单元"

        lstFound.Clear
        ' 如果找到的单元数少于 5 个，则将它们列出来
        If hsize / 4 < 5 And hsize / 4 > 0 Then
                Dim i, r
                r = GetAnalyse(h)
                For i = 0 To hsize / 4 - 1
                        ' 每一项的格式： 单元地址 = 单元内容
                        lstFound.AddItem r(i, 0) & "=" & r(i, 1)
                Next
        End If

        ' 关闭进程句柄
        CloseHandle h
End Sub

Private Sub cmdreset_Click()
        Dim pid
        Dim h As Long
        Dim cbread As Long
        Dim pstart As Long, pend As Long

        ' 打开进程PID。返回的进程句柄用于 ResetAnalyse函数
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_READ, 0, pid)
        If h = 0 Then
                MsgBox "不能打开进程，这可能是系统进程。"
                Exit Sub
        End If

        ' 要分析的地址范围的数值形式
        pstart = val("&H" & aStart)
        pend = val("&H" & aEnd)

        ' 调用分析复位函数，用于初始化分析环境
        ResetAnalyse h, pstart, pend - pstart + 1

        ' 关闭进程句柄
        CloseHandle h

        founded = "已找到" & hsize / 4 & "单元"
End Sub

Private Sub loadmem_Click()
        Dim pid, h
        Dim cwrite As Long, fn
        ReDim b(0 To 0) As Byte
        Dim pstart As Long, pend As Long

' 首先打开文件并读入文件内容至数组 b

        ' 如果点击取消则转到 x 退出。
        On Error GoTo x
        ' 显示打开文件对话框
        cd.ShowOpen
        ' 分配文件句柄
        fn = FreeFile
        ' 以二进制方式打开文件
        Open cd.FileName For Binary As #fn
        ' 读入起始地址和结束地址
        Get #fn, , pstart
        Get #fn, , pend
        ' 分配数组 b 的空间
        ReDim b(pstart To pend) As Byte
        ' 读入内存数据
        Get #fn, , b
        ' 关闭文件
        Close #fn

' 然后将数组 b 复制到进程内存
        ' 打开进程
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_WRITE, 0, pid)
        If h = 0 Then
                MsgBox "不能打开进程，这可能是系统进程。"
                Exit Sub
        End If

        ' 将数组 b 的内容分成多个小段写入进程内存
        Dim i As Long
        For i = pstart To pend - 1000 Step 1000
                WriteProcessMemory h, i, b(i), 1000, cwrite
        Next
        ' 将剩余不足1000的小段写入进程内存
        WriteProcessMemory h, i, b(i), pend - i + 1, cwrite
        'writeprocessmemory h,pstart+i
        CloseHandle h

        ' 将内存文件中的起始地址和结束地址更新到文本框中
        aStart = Hex(pstart)
        aEnd = Hex(pend)
x:
End Sub

' 点击刷新按钮只要简单的调用刷新函数即可
Private Sub Command3_Click()
        RefreshMemory
End Sub

' 保存修改结果至内存
Private Sub Command4_Click()
        Dim pid
        Dim i, p, h
        Dim bs(0 To 63) As Byte, cbwritten As Long

        ' 将 64 格文本框的内容转化至数组
        For i = 0 To 63
                If box(i) <> "" Then
                        bs(i) = val("&H" & box(i))
                Else
                        ' 如果某一格没有内容则说明结束，此时退出循环后，
                        ' 变量 i 将存放已经转化的单元数目。
                        Exit For
                End If
        Next

        ' 打开进程
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_WRITE, 0, pid)
        ' 在地址文本框中的值(p)作为保存的起始地址
        p = val("&H" & txtAddr)

        ' 将bs数组的64个字节单元写入进程中。
        WriteProcessMemory h, p, bs(0), i, cbwritten
        If cbwritten < i Then
                MsgBox "更新内存时发生错误。"
        End If

        ' 关闭进程句柄
        CloseHandle h
End Sub

' 在已找到单元列表框中双击, 将把双击所在项的地址复制到地址文本框中
Private Sub lstFound_Click()
        ' 取双击所在项文本按 "=" 分割后的第一项(0)的数值的16进制表示
        txtAddr = Hex(val(Split(lstFound.Text, "=")(0)))
        RefreshMemory
End Sub

Private Sub PageDown_Click()
        ' 取地址文本框的16进制内容的数值 加上 128，然后再转换回16进制
        txtAddr = Hex(val("&H" & Trim(txtAddr)) + 128)
        RefreshMemory
End Sub

Private Sub PageUp_Click()
        ' 取地址文本框的16进制内容的数值 减去 128，然后再转换回16进制
        txtAddr = Hex(val("&H" & Trim(txtAddr)) - 128)
        RefreshMemory
End Sub

Private Sub savemem_Click()
        Dim pid, h
        Dim cread As Long, fn
        Dim pstart As Long, pend As Long

' 保存进程内存，首先将进程内存的数据读入到数组 b 中
        ' 将分析起始地址和分析结束地址转换成数值，放入pstart和pend变量中
        pstart = val("&H" & aStart)
        pend = val("&H" & aEnd)
        ' 分配数组 b 空间
        ReDim b(pstart To pend) As Byte

        ' 打开进程
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_READ, 0, pid)
        If h = 0 Then
                MsgBox "不能打开进程，这可能是系统进程。"
                Exit Sub
        End If

        ' 从进程中分小段读入数组 b
        Dim i
        For i = pstart To pend - 1000 Step 1000
                ReadProcessMemory h, i, b(i), 1000, cread
        Next
        ' 读入最后不足1000的小段
        ReadProcessMemory h, i, b(i), pend - i + 1, cread

        ' 关闭进程句柄
        CloseHandle h

' 然后将数组 b 的内容保存至文件
        ' 当选择取消后转到 x
        On Error GoTo x
        ' 显示保存文件对话框
        cd.ShowSave
        ' 分配文件句柄
        fn = FreeFile
        ' 以二进制打开文件
        Open cd.FileName For Binary As #fn
        ' 写入起始地址
        Put #fn, , pstart
        ' 写入结束地址
        Put #fn, , pend
        ' 写入内存数据
        Put #fn, , b
        ' 关闭文件
        Close #fn

x:
End Sub

' 可以在地址文本框中直接按回车刷新内存
Private Sub txtAddr_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Or KeyAscii = 10 Then RefreshMemory
End Sub

' 当地址文本框失去焦点时刷新内存
Private Sub txtAddr_LostFocus()
        RefreshMemory
End Sub

' 刷新内存函数
Public Sub RefreshMemory()
        Dim pid
        Dim i, p, h
        Dim bs(0 To 63) As Byte, cbread As Long

        ' 打开进程
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_READ, 0, pid)
        If h = 0 Then
                MsgBox "不能打开进程，这可能是系统进程。"
                Exit Sub
        End If

        ' 将地址文本框的内容转换成数值
        p = val("&H" & txtAddr)
        ' 从进程内存的制定地址处开始读入64字节数据. cbread返回读入的有效字节数
        ReadProcessMemory h, p, bs(0), 64, cbread
        ' 关闭句柄
        CloseHandle h

        ' 将读入的有效字节显示在格子中
        For i = 0 To cbread - 1
                ' 格子显示的为16进制
                box(i) = Hex(bs(i))
                ' 如果长度不足2个字母，在左边加上一个"0"
                If Len(box(i)) = 1 Then box(i) = "0" & box(i)
        Next
        ' 将剩余的个子清空
        For i = cbread To 63
                box(i) = ""
        Next

        ' 更新格子左边的 8 个地址文本
        For i = 0 To 7
                ' 从上到下的每个地址文本显示为起始地址 + 8*i，
                ' 因为每行共有8个格子。
                add(i) = Hex(p + i * 8)

                ' 将地址文本补齐到8个字母。
                If Len(add(i)) < 8 Then
                        ' 不足 8 个的左边添 "0"
                        add(i) = String(8 - Len(add(i)), "0") + add(i)
                End If
        Next
End Sub

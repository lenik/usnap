VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form memory
   Caption         =   "�����ڴ����"
   ClientHeight    =   4245
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7110
   LinkTopic       =   "Form2"
   ScaleHeight     =   4245
   ScaleWidth      =   7110
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame Frame1
      Caption         =   "�ڴ涯̬����"
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
         Caption         =   "�洢�����ڴ�"
         Height          =   375
         Left            =   90
         TabIndex        =   85
         Top             =   1110
         Width           =   1455
      End
      Begin VB.CommandButton loadmem
         Caption         =   "�ָ������ڴ�"
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
         Caption         =   "���������"
         Height          =   375
         Left            =   105
         TabIndex        =   89
         Top             =   1995
         Width           =   1335
      End
      Begin VB.CommandButton cmdreset
         Caption         =   "��λ"
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
         Caption         =   "����������ַ"
         Height          =   195
         Index           =   1
         Left            =   90
         TabIndex        =   83
         Top             =   675
         Width           =   1080
      End
      Begin VB.Label Label3
         AutoSize        =   -1  'True
         Caption         =   "������ʼ��ַ"
         Height          =   195
         Index           =   0
         Left            =   90
         TabIndex        =   81
         Top             =   330
         Width           =   1080
      End
      Begin VB.Label Label4
         AutoSize        =   -1  'True
         Caption         =   "��ֵ(��16����)"
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
      Caption         =   "��ҳ"
      Height          =   375
      Left            =   855
      TabIndex        =   78
      Top             =   3660
      Width           =   630
   End
   Begin VB.CommandButton PageUp
      Caption         =   "��ҳ"
      Height          =   375
      Left            =   165
      TabIndex        =   77
      Top             =   3660
      Width           =   630
   End
   Begin VB.CommandButton Command4
      Caption         =   "���޸Ľ��д�������ڴ�"
      Height          =   375
      Left            =   1620
      TabIndex        =   79
      Top             =   3660
      Width           =   2280
   End
   Begin VB.CommandButton Command3
      Caption         =   "ˢ��"
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
      Caption         =   "��ַ:"
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
      Caption         =   "����ID:"
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

' ��ӷ���
Private Sub cmdadd_Click()
        Dim pid
        Dim h As Long

        ' �򿪽���PID����ȡ���̾��h������AddAnalyse����
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_READ, 0, pid)
        If h = 0 Then
                MsgBox "���ܴ򿪽��̣��������ϵͳ���̡�"
                Exit Sub
        End If
        analyseval = analyseval Mod 256
        AddAnalyse h, val(analyseval)

        ' hsize�Ƿ�������Ĵ�С����Ϊÿ���ֽڵ�Ԫ��Ӧ��һ����ַ��
        ' ��� hsize ��ʵ�ʵ�Ԫ��Ŀ��4��
        founded = "���ҵ�" & hsize / 4 & "��Ԫ"

        lstFound.Clear
        ' ����ҵ��ĵ�Ԫ������ 5 �����������г���
        If hsize / 4 < 5 And hsize / 4 > 0 Then
                Dim i, r
                r = GetAnalyse(h)
                For i = 0 To hsize / 4 - 1
                        ' ÿһ��ĸ�ʽ�� ��Ԫ��ַ = ��Ԫ����
                        lstFound.AddItem r(i, 0) & "=" & r(i, 1)
                Next
        End If

        ' �رս��̾��
        CloseHandle h
End Sub

Private Sub cmdreset_Click()
        Dim pid
        Dim h As Long
        Dim cbread As Long
        Dim pstart As Long, pend As Long

        ' �򿪽���PID�����صĽ��̾������ ResetAnalyse����
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_READ, 0, pid)
        If h = 0 Then
                MsgBox "���ܴ򿪽��̣��������ϵͳ���̡�"
                Exit Sub
        End If

        ' Ҫ�����ĵ�ַ��Χ����ֵ��ʽ
        pstart = val("&H" & aStart)
        pend = val("&H" & aEnd)

        ' ���÷�����λ���������ڳ�ʼ����������
        ResetAnalyse h, pstart, pend - pstart + 1

        ' �رս��̾��
        CloseHandle h

        founded = "���ҵ�" & hsize / 4 & "��Ԫ"
End Sub

Private Sub loadmem_Click()
        Dim pid, h
        Dim cwrite As Long, fn
        ReDim b(0 To 0) As Byte
        Dim pstart As Long, pend As Long

' ���ȴ��ļ��������ļ����������� b

        ' ������ȡ����ת�� x �˳���
        On Error GoTo x
        ' ��ʾ���ļ��Ի���
        cd.ShowOpen
        ' �����ļ����
        fn = FreeFile
        ' �Զ����Ʒ�ʽ���ļ�
        Open cd.FileName For Binary As #fn
        ' ������ʼ��ַ�ͽ�����ַ
        Get #fn, , pstart
        Get #fn, , pend
        ' �������� b �Ŀռ�
        ReDim b(pstart To pend) As Byte
        ' �����ڴ�����
        Get #fn, , b
        ' �ر��ļ�
        Close #fn

' Ȼ������ b ���Ƶ������ڴ�
        ' �򿪽���
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_WRITE, 0, pid)
        If h = 0 Then
                MsgBox "���ܴ򿪽��̣��������ϵͳ���̡�"
                Exit Sub
        End If

        ' ������ b �����ݷֳɶ��С��д������ڴ�
        Dim i As Long
        For i = pstart To pend - 1000 Step 1000
                WriteProcessMemory h, i, b(i), 1000, cwrite
        Next
        ' ��ʣ�಻��1000��С��д������ڴ�
        WriteProcessMemory h, i, b(i), pend - i + 1, cwrite
        'writeprocessmemory h,pstart+i
        CloseHandle h

        ' ���ڴ��ļ��е���ʼ��ַ�ͽ�����ַ���µ��ı�����
        aStart = Hex(pstart)
        aEnd = Hex(pend)
x:
End Sub

' ���ˢ�°�ťֻҪ�򵥵ĵ���ˢ�º�������
Private Sub Command3_Click()
        RefreshMemory
End Sub

' �����޸Ľ�����ڴ�
Private Sub Command4_Click()
        Dim pid
        Dim i, p, h
        Dim bs(0 To 63) As Byte, cbwritten As Long

        ' �� 64 ���ı��������ת��������
        For i = 0 To 63
                If box(i) <> "" Then
                        bs(i) = val("&H" & box(i))
                Else
                        ' ���ĳһ��û��������˵����������ʱ�˳�ѭ����
                        ' ���� i ������Ѿ�ת���ĵ�Ԫ��Ŀ��
                        Exit For
                End If
        Next

        ' �򿪽���
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_WRITE, 0, pid)
        ' �ڵ�ַ�ı����е�ֵ(p)��Ϊ�������ʼ��ַ
        p = val("&H" & txtAddr)

        ' ��bs�����64���ֽڵ�Ԫд������С�
        WriteProcessMemory h, p, bs(0), i, cbwritten
        If cbwritten < i Then
                MsgBox "�����ڴ�ʱ��������"
        End If

        ' �رս��̾��
        CloseHandle h
End Sub

' �����ҵ���Ԫ�б����˫��, ����˫��������ĵ�ַ���Ƶ���ַ�ı�����
Private Sub lstFound_Click()
        ' ȡ˫���������ı��� "=" �ָ��ĵ�һ��(0)����ֵ��16���Ʊ�ʾ
        txtAddr = Hex(val(Split(lstFound.Text, "=")(0)))
        RefreshMemory
End Sub

Private Sub PageDown_Click()
        ' ȡ��ַ�ı����16�������ݵ���ֵ ���� 128��Ȼ����ת����16����
        txtAddr = Hex(val("&H" & Trim(txtAddr)) + 128)
        RefreshMemory
End Sub

Private Sub PageUp_Click()
        ' ȡ��ַ�ı����16�������ݵ���ֵ ��ȥ 128��Ȼ����ת����16����
        txtAddr = Hex(val("&H" & Trim(txtAddr)) - 128)
        RefreshMemory
End Sub

Private Sub savemem_Click()
        Dim pid, h
        Dim cread As Long, fn
        Dim pstart As Long, pend As Long

' ��������ڴ棬���Ƚ������ڴ�����ݶ��뵽���� b ��
        ' ��������ʼ��ַ�ͷ���������ַת������ֵ������pstart��pend������
        pstart = val("&H" & aStart)
        pend = val("&H" & aEnd)
        ' �������� b �ռ�
        ReDim b(pstart To pend) As Byte

        ' �򿪽���
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_READ, 0, pid)
        If h = 0 Then
                MsgBox "���ܴ򿪽��̣��������ϵͳ���̡�"
                Exit Sub
        End If

        ' �ӽ����з�С�ζ������� b
        Dim i
        For i = pstart To pend - 1000 Step 1000
                ReadProcessMemory h, i, b(i), 1000, cread
        Next
        ' ���������1000��С��
        ReadProcessMemory h, i, b(i), pend - i + 1, cread

        ' �رս��̾��
        CloseHandle h

' Ȼ������ b �����ݱ������ļ�
        ' ��ѡ��ȡ����ת�� x
        On Error GoTo x
        ' ��ʾ�����ļ��Ի���
        cd.ShowSave
        ' �����ļ����
        fn = FreeFile
        ' �Զ����ƴ��ļ�
        Open cd.FileName For Binary As #fn
        ' д����ʼ��ַ
        Put #fn, , pstart
        ' д�������ַ
        Put #fn, , pend
        ' д���ڴ�����
        Put #fn, , b
        ' �ر��ļ�
        Close #fn

x:
End Sub

' �����ڵ�ַ�ı�����ֱ�Ӱ��س�ˢ���ڴ�
Private Sub txtAddr_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Or KeyAscii = 10 Then RefreshMemory
End Sub

' ����ַ�ı���ʧȥ����ʱˢ���ڴ�
Private Sub txtAddr_LostFocus()
        RefreshMemory
End Sub

' ˢ���ڴ溯��
Public Sub RefreshMemory()
        Dim pid
        Dim i, p, h
        Dim bs(0 To 63) As Byte, cbread As Long

        ' �򿪽���
        pid = val("&H" & txtPID)
        h = OpenProcess(PROCESS_VM_OPERATION Or PROCESS_VM_READ, 0, pid)
        If h = 0 Then
                MsgBox "���ܴ򿪽��̣��������ϵͳ���̡�"
                Exit Sub
        End If

        ' ����ַ�ı��������ת������ֵ
        p = val("&H" & txtAddr)
        ' �ӽ����ڴ���ƶ���ַ����ʼ����64�ֽ�����. cbread���ض������Ч�ֽ���
        ReadProcessMemory h, p, bs(0), 64, cbread
        ' �رվ��
        CloseHandle h

        ' ���������Ч�ֽ���ʾ�ڸ�����
        For i = 0 To cbread - 1
                ' ������ʾ��Ϊ16����
                box(i) = Hex(bs(i))
                ' ������Ȳ���2����ĸ������߼���һ��"0"
                If Len(box(i)) = 1 Then box(i) = "0" & box(i)
        Next
        ' ��ʣ��ĸ������
        For i = cbread To 63
                box(i) = ""
        Next

        ' ���¸�����ߵ� 8 ����ַ�ı�
        For i = 0 To 7
                ' ���ϵ��µ�ÿ����ַ�ı���ʾΪ��ʼ��ַ + 8*i��
                ' ��Ϊÿ�й���8�����ӡ�
                add(i) = Hex(p + i * 8)

                ' ����ַ�ı����뵽8����ĸ��
                If Len(add(i)) < 8 Then
                        ' ���� 8 ��������� "0"
                        add(i) = String(8 - Len(add(i)), "0") + add(i)
                End If
        Next
End Sub

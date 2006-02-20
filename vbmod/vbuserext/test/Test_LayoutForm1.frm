VERSION 5.00
Begin VB.Form Test_LayoutForm1
   Caption         =   "Test Layout"
   ClientHeight    =   4770
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   9195
   LinkTopic       =   "Form1"
   ScaleHeight     =   4770
   ScaleWidth      =   9195
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text2
      Height          =   1095
      Left            =   5820
      TabIndex        =   3
      Text            =   "Text2"
      Top             =   3600
      Width           =   1875
   End
   Begin VB.TextBox Text1
      Height          =   375
      Left            =   2100
      TabIndex        =   2
      Text            =   "Text1"
      Top             =   420
      Width           =   2775
   End
   Begin VB.FileListBox File1
      Height          =   1455
      Left            =   1560
      TabIndex        =   6
      Top             =   2700
      Width           =   1395
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   23
      Left            =   4260
      TabIndex        =   33
      Top             =   5580
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   22
      Left            =   4080
      TabIndex        =   32
      Top             =   5340
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   21
      Left            =   3900
      TabIndex        =   31
      Top             =   5100
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   20
      Left            =   3720
      TabIndex        =   30
      Top             =   4860
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   19
      Left            =   3540
      TabIndex        =   28
      Top             =   4620
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   18
      Left            =   3360
      TabIndex        =   27
      Top             =   4380
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   17
      Left            =   3180
      TabIndex        =   26
      Top             =   4140
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   16
      Left            =   3000
      TabIndex        =   25
      Top             =   3900
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   15
      Left            =   2760
      TabIndex        =   24
      Top             =   3660
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   14
      Left            =   2580
      TabIndex        =   23
      Top             =   3420
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   13
      Left            =   2400
      TabIndex        =   22
      Top             =   3180
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   12
      Left            =   2220
      TabIndex        =   21
      Top             =   2940
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   11
      Left            =   2040
      TabIndex        =   19
      Top             =   2700
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   10
      Left            =   1860
      TabIndex        =   18
      Top             =   2460
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   9
      Left            =   1680
      TabIndex        =   17
      Top             =   2220
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   8
      Left            =   1500
      TabIndex        =   16
      Top             =   1980
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   7
      Left            =   1320
      TabIndex        =   15
      Top             =   1740
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   6
      Left            =   1140
      TabIndex        =   14
      Top             =   1500
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   5
      Left            =   960
      TabIndex        =   13
      Top             =   1260
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   4
      Left            =   780
      TabIndex        =   12
      Top             =   1020
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   3
      Left            =   600
      TabIndex        =   10
      Top             =   780
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   2
      Left            =   420
      TabIndex        =   9
      Top             =   540
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   1
      Left            =   240
      TabIndex        =   8
      Top             =   300
      Width           =   3255
   End
   Begin VB.HScrollBar HScroll1
      Height          =   195
      Index           =   0
      Left            =   60
      TabIndex        =   7
      Top             =   60
      Width           =   3255
   End
   Begin VB.DirListBox Dir1
      Height          =   1215
      Left            =   6480
      TabIndex        =   5
      Top             =   1560
      Width           =   1935
   End
   Begin VB.Timer Timer1
      Left            =   360
      Top             =   3720
   End
   Begin VB.ListBox List1
      Height          =   450
      Left            =   5640
      TabIndex        =   4
      Top             =   840
      Width           =   1455
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   675
      Left            =   420
      TabIndex        =   0
      Top             =   2220
      Width           =   795
   End
   Begin VB.Image Image1
      Height          =   1035
      Left            =   5220
      Top             =   1500
      Width           =   1095
   End
   Begin VB.Label Label3
      Alignment       =   1  'Right Justify
      Caption         =   "Label1"
      Height          =   375
      Left            =   6120
      TabIndex        =   20
      Top             =   3060
      Width           =   1035
   End
   Begin VB.Label Label4
      Alignment       =   1  'Right Justify
      Caption         =   "Label1"
      Height          =   375
      Left            =   4440
      TabIndex        =   29
      Top             =   5280
      Width           =   1035
   End
   Begin VB.Label Label2
      Alignment       =   1  'Right Justify
      Caption         =   "Label1"
      Height          =   375
      Left            =   1500
      TabIndex        =   11
      Top             =   1440
      Width           =   1035
   End
   Begin VB.Shape Shape1
      Height          =   495
      Left            =   7320
      Top             =   3060
      Width           =   1215
   End
   Begin VB.Label Label1
      Alignment       =   1  'Right Justify
      Caption         =   "Label1"
      Height          =   375
      Left            =   780
      TabIndex        =   1
      Top             =   480
      Width           =   1035
   End
End
Attribute VB_Name = "Test_LayoutForm1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_Layout As New AutoScaleLayout

Private Sub Form_Load()
    m_Layout.InitializeCoordinations Me
End Sub

Private Sub Form_Resize()
    m_Layout.Relayout
End Sub

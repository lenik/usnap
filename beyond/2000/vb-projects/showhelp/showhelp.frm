VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6420
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   6420
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.TextBox Text2
      Height          =   375
      Left            =   420
      TabIndex        =   4
      Text            =   "S:\app\games\Game2001\SteelWorks\Finger\help\finger.chm"
      Top             =   2760
      Width           =   5475
   End
   Begin VB.ComboBox Combo1
      Height          =   300
      ItemData        =   "showhelp.frx":0000
      Left            =   1500
      List            =   "showhelp.frx":000D
      TabIndex        =   3
      Text            =   "Combo1"
      Top             =   60
      Width           =   2835
   End
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   315
      Left            =   2040
      TabIndex        =   2
      Top             =   1140
      Width           =   1335
   End
   Begin VB.TextBox Text1
      Height          =   555
      Left            =   1740
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   480
      Width           =   2835
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   795
      Left            =   780
      TabIndex        =   0
      Top             =   1800
      Width           =   2895
   End
   Begin MSComDlg.CommonDialog cd1
      Left            =   300
      Top             =   360
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      HelpCommand     =   3
      HelpContext     =   1
      HelpFile        =   "C:\winnt\help\regedt32.hlp"
      HelpKey         =   "qwe"
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Combo1_Click()
        If Combo1.ListIndex >= 0 Then
                cd1.HelpCommand = Combo1.ItemData(Combo1.ListIndex)
        End If
End Sub

Private Sub Command1_Click()
        cd1.ShowHelp
End Sub

Private Sub Command2_Click()
        cd1.HelpCommand = Val(Text1)
End Sub

Private Sub Form_Load()
        Combo1.ListIndex = 2
End Sub

Private Sub Text2_Change()
        cd1.HelpFile = Text2
End Sub

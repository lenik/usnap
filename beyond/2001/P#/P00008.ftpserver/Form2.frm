VERSION 5.00
Begin VB.Form Form2
   BorderStyle     =   1  'Fixed Single
   Caption         =   "服务器地址簿"
   ClientHeight    =   4035
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5670
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   Picture         =   "Form2.frx":0000
   ScaleHeight     =   4035
   ScaleWidth      =   5670
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox txt
      Height          =   330
      Index           =   4
      Left            =   2625
      TabIndex        =   2
      Top             =   630
      Width           =   2790
   End
   Begin VB.CommandButton cmdadd
      Caption         =   "添加"
      Height          =   465
      Left            =   2475
      TabIndex        =   11
      Top             =   3345
      Width           =   855
   End
   Begin VB.CommandButton cmddel
      Caption         =   "删除"
      Height          =   465
      Left            =   3532
      TabIndex        =   12
      Top             =   3345
      Width           =   855
   End
   Begin VB.CommandButton cmdback
      Caption         =   "返回"
      Height          =   465
      Left            =   4605
      TabIndex        =   13
      Top             =   3345
      Width           =   855
   End
   Begin VB.TextBox txt
      Height          =   330
      IMEMode         =   3  'DISABLE
      Index           =   3
      Left            =   2685
      PasswordChar    =   "*"
      TabIndex        =   10
      Top             =   2865
      Width           =   2790
   End
   Begin VB.TextBox txt
      Height          =   330
      Index           =   2
      Left            =   2640
      TabIndex        =   8
      Top             =   2340
      Width           =   2790
   End
   Begin VB.TextBox txt
      Height          =   330
      Index           =   1
      Left            =   2655
      TabIndex        =   6
      Top             =   1785
      Width           =   2790
   End
   Begin VB.TextBox txt
      Height          =   330
      Index           =   0
      Left            =   2655
      TabIndex        =   4
      Top             =   1260
      Width           =   2790
   End
   Begin VB.ListBox lst
      Height          =   3180
      Left            =   210
      TabIndex        =   0
      Top             =   405
      Width           =   2130
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "名称"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   195
      Index           =   4
      Left            =   2430
      TabIndex        =   1
      Top             =   405
      Width           =   375
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "登录口令:"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   195
      Index           =   3
      Left            =   2475
      TabIndex        =   9
      Top             =   2685
      Width           =   795
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "登录用户:"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   195
      Index           =   2
      Left            =   2445
      TabIndex        =   7
      Top             =   2130
      Width           =   795
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "端口:"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   195
      Index           =   1
      Left            =   2445
      TabIndex        =   5
      Top             =   1605
      Width           =   435
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "服务器地址:"
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   195
      Index           =   0
      Left            =   2445
      TabIndex        =   3
      Top             =   1035
      Width           =   975
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Public Function f1(s)
    f1 = s & "|"
End Function

Private Sub cmdadd_Click()
    s = f1(txt(4) & Space(40)) & f1(txt(0)) & f1(txt(1)) & f1(txt(2)) & f1(txt(3))
    lst.AddItem s
    txt(0) = ""
    txt(1) = ""
    txt(2) = ""
    txt(3) = ""
    txt(4) = ""

End Sub

Private Sub cmdback_Click()
    SaveSetting "ftpc", "slist", "count", lst.ListCount

    For i = 0 To lst.ListCount - 1
        SaveSetting "ftpc", "slist", "item_" & Trim(Str(i)), lst.List(i)
    Next

    Hide
End Sub

Private Sub cmddel_Click()
    lst.RemoveItem lst.ListIndex
End Sub

Private Sub lst_Click()
    s = lst.List(lst.ListIndex)
    a = Split(s, "|")
    txt(4) = Trim(a(0))
    txt(0) = a(1)
    txt(1) = a(2)
    txt(2) = a(3)
    txt(3) = a(4)
End Sub

Private Sub txt_KeyPress(Index As Integer, KeyAscii As Integer)
    If KeyAscii > Asc("9") And Index = 1 Then
        KeyAscii = 0
    End If
End Sub

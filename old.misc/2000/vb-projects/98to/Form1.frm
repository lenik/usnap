VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   4695
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5265
   LinkTopic       =   "Form1"
   ScaleHeight     =   4695
   ScaleWidth      =   5265
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdUpdate
      Caption         =   "更新"
      Height          =   705
      Left            =   1200
      TabIndex        =   9
      Top             =   2355
      Width           =   1845
   End
   Begin VB.TextBox arrival
      Height          =   1290
      Left            =   1230
      MultiLine       =   -1  'True
      TabIndex        =   8
      Top             =   3270
      Width           =   3795
   End
   Begin MSWinsockLib.Winsock s
      Left            =   360
      Top             =   4065
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   327681
   End
   Begin VB.TextBox Text3
      Height          =   315
      Left            =   2640
      TabIndex        =   7
      Text            =   "http://jljljjl.topcities.com/tip1.htm"
      Top             =   1260
      Width           =   2325
   End
   Begin VB.TextBox Text2
      Height          =   315
      Left            =   2655
      TabIndex        =   6
      Text            =   "http://218.0.211.150"
      Top             =   1725
      Width           =   2325
   End
   Begin VB.OptionButton Option2
      Caption         =   "指定站点"
      Height          =   345
      Left            =   1320
      TabIndex        =   5
      Top             =   1680
      Width           =   1170
   End
   Begin VB.TextBox Text1
      Height          =   345
      IMEMode         =   3  'DISABLE
      Left            =   1365
      PasswordChar    =   "*"
      TabIndex        =   4
      Text            =   "nothing"
      Top             =   705
      Width           =   2295
   End
   Begin VB.TextBox txtlogin
      Height          =   345
      Left            =   1380
      TabIndex        =   2
      Text            =   "99c"
      Top             =   195
      Width           =   2295
   End
   Begin VB.OptionButton Option1
      Caption         =   "临时站点"
      Height          =   345
      Left            =   1320
      TabIndex        =   0
      Top             =   1230
      Width           =   1140
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "登陆密码"
      Height          =   195
      Left            =   270
      TabIndex        =   3
      Top             =   810
      Width           =   720
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "登陆名称"
      Height          =   195
      Left            =   255
      TabIndex        =   1
      Top             =   270
      Width           =   720
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub wait(delta)
        Dim t1
        t1 = Timer
        While Timer - t1 < delta
                DoEvents
        Wend

End Sub

Private Sub cmdUpdate_Click()
        s.Connect "98.to", 80
        wait 1000
        s.SendData "GET /loginx.asp?login=99c&password=nothing"
        wait 1000
        s.SendData "GET /login"
End Sub

Private Sub s_DataArrival(ByVal bytesTotal As Long)
        Dim data
        s.GetData data
        arrival = data & vbNewLine & arrival
End Sub

Private Sub s_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)

End Sub

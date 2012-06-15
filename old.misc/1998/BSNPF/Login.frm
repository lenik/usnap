VERSION 5.00
Begin VB.Form frmLogin
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Çë×¢²á"
   ClientHeight    =   1545
   ClientLeft      =   2175
   ClientTop       =   3240
   ClientWidth     =   3750
   Icon            =   "Login.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   912.837
   ScaleMode       =   0  'User
   ScaleWidth      =   3521.047
   ShowInTaskbar   =   0   'False
   Begin VB.TextBox txtUserName
      ForeColor       =   &H00FF0000&
      Height          =   345
      Left            =   1290
      TabIndex        =   1
      Top             =   135
      Width           =   2325
   End
   Begin VB.CommandButton cmdOK
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   390
      Left            =   495
      TabIndex        =   4
      Top             =   1020
      Width           =   1140
   End
   Begin VB.CommandButton cmdCancel
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   390
      Left            =   2100
      TabIndex        =   5
      Top             =   1020
      Width           =   1140
   End
   Begin VB.TextBox txtPassword
      ForeColor       =   &H00FF0000&
      Height          =   345
      IMEMode         =   3  'DISABLE
      Left            =   1290
      PasswordChar    =   "*"
      TabIndex        =   3
      Top             =   525
      Width           =   2325
   End
   Begin VB.Label lblLabels
      Caption         =   "&L ×¢²áÃû:"
      BeginProperty Font
         Name            =   "ËÎÌå"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800000&
      Height          =   270
      Index           =   0
      Left            =   105
      TabIndex        =   0
      Top             =   150
      Width           =   1080
   End
   Begin VB.Label lblLabels
      Caption         =   "&P ¿ÚÁî:"
      BeginProperty Font
         Name            =   "ËÎÌå"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800000&
      Height          =   270
      Index           =   1
      Left            =   105
      TabIndex        =   2
      Top             =   540
      Width           =   1080
   End
End
Attribute VB_Name = "frmLogin"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public LoginSucceeded As Boolean

Private Sub cmdCancel_Click()
    'set the global var to false
    'to denote a failed login

    CurUser.Name = "Noname"
    CurUser.Password = ""
    CurUser.UserOp = False
    CurUser.ClassOp = False
    CurUser.ManageSelf = False
    CurUser.ViewLog = False

    LoginSucceeded = True
    Me.Hide
End Sub

Private Sub cmdOK_Click()
    Dim UserR As UserRecord

    If Trim(txtUserName.Text) = "" Then
      cmdCancel_Click
      Exit Sub
    End If

    na = FreeFile
    Open DataDir + UserFile For Random As na Len = Len(UserRecord)
    While Not EOF(nf)
      GetR na, UserR
      If UserR.Name = txtUserName.Text Then
        If Trim(UserR.Password) = txtPassword Then
          CurUser.Name = UserR.Name
          CurUser.Password = UserR.Password
          CurUser.UserOp = UserR.UserOp
          CurUser.ClassOp = UserR.ClassOp
          CurUser.ManageSelf = UserR.ManageSelf
          CurUser.ViewLog = UserR.ViewLog

          LoginSucceeded = True
          Me.Hide
          Exit Sub
        Else
          MsgBox "¿ÚÁîÎÞÐ§, ÇëÖØÊÔ»òÄäÃû×¢²á", , "×¢²áÊ§°Ü"
          txtPassword.SetFocus
          SendKeys "{Home}+{End}"
        End If
      End If
    Wend
    Close #na
    LoginSucceeded = True
End Sub

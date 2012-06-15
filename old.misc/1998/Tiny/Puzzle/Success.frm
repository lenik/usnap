VERSION 5.00
Begin VB.Form frmSuccess
   BackColor       =   &H0080FFFF&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "恭喜您成功!"
   ClientHeight    =   3690
   ClientLeft      =   1740
   ClientTop       =   2370
   ClientWidth     =   4170
   Icon            =   "Success.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3690
   ScaleWidth      =   4170
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton cmdOK
      Caption         =   "&Okey!"
      Default         =   -1  'True
      Height          =   375
      Left            =   2880
      TabIndex        =   2
      Top             =   3120
      Width           =   855
   End
   Begin VB.PictureBox Picture1
      AutoSize        =   -1  'True
      BorderStyle     =   0  'None
      Height          =   2400
      Left            =   840
      Picture         =   "Success.frx":030A
      ScaleHeight     =   2400
      ScaleWidth      =   2400
      TabIndex        =   1
      Top             =   600
      Width           =   2400
   End
   Begin VB.Label Label1
      BackStyle       =   0  'Transparent
      Caption         =   "恭喜您! 您已胜利通过本关! "
      BeginProperty Font
         Name            =   "楷体_GB2312"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H008080FF&
      Height          =   435
      Left            =   480
      TabIndex        =   0
      Top             =   180
      Width           =   3315
   End
End
Attribute VB_Name = "frmSuccess"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub cmdOK_Click()
  Me.Hide
End Sub

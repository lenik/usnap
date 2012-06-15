VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text1
      Height          =   1275
      Left            =   360
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   1
      Text            =   "Form1.frx":0000
      Top             =   240
      Width           =   3855
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   1095
      Left            =   2220
      TabIndex        =   0
      Top             =   1800
      Width           =   1995
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    Dim buf As New InputBuffer
    Dim b() As Byte
    b = StrConv(Text1.Text, vbFromUnicode)
    buf.AddBytes b

    Dim st As Statement
    Set st = buf.GetStatement
    'b = st.Encode

    Dim s As String
    s = StrConv(st.Encode, vbUnicode)
    MsgBox s
End Sub

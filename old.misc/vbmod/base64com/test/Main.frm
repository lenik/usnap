VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5970
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7740
   LinkTopic       =   "Form1"
   ScaleHeight     =   5970
   ScaleWidth      =   7740
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton encf
      Caption         =   "Encode From File"
      Height          =   435
      Left            =   3600
      TabIndex        =   5
      Top             =   2700
      Width           =   1695
   End
   Begin VB.CommandButton decf
      Caption         =   "Decode To File"
      Height          =   435
      Left            =   5400
      TabIndex        =   4
      Top             =   2700
      Width           =   1455
   End
   Begin VB.TextBox dst
      Height          =   2175
      Left            =   660
      MultiLine       =   -1  'True
      TabIndex        =   3
      Top             =   3360
      Width           =   6195
   End
   Begin VB.CommandButton dec
      Caption         =   "Decode"
      Height          =   435
      Left            =   2100
      TabIndex        =   2
      Top             =   2700
      Width           =   1215
   End
   Begin VB.CommandButton enc
      Caption         =   "Encode"
      Height          =   435
      Left            =   720
      TabIndex        =   1
      Top             =   2700
      Width           =   1275
   End
   Begin VB.TextBox src
      Height          =   2175
      Left            =   720
      MultiLine       =   -1  'True
      TabIndex        =   0
      Text            =   "Main.frx":0000
      Top             =   240
      Width           =   6135
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Base64 As New BinariesLib.Base64

Private Sub dec_Click()
    src.Text = Base64.DecodeString(dst.Text)
    dst.Text = ""
End Sub

Private Sub decf_Click()
    ' Read dst
    Base64.DecodeFile dst.Text, src.Text
End Sub

Private Sub enc_Click()
    dst.Text = Base64.EncodeString(src.Text)
    src.Text = ""
End Sub

Private Sub encf_Click()
    ' Write dst
    dst.Text = Base64.EncodeFile(src.Text)
End Sub

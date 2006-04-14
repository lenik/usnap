VERSION 5.00
Begin VB.Form Base64Pic
   Caption         =   "Test base64 picture"
   ClientHeight    =   4680
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8340
   LinkTopic       =   "Form1"
   ScaleHeight     =   4680
   ScaleWidth      =   8340
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnOpenBase64
      Caption         =   "Open &Base64"
      Height          =   675
      Left            =   6420
      TabIndex        =   4
      Top             =   540
      Width           =   1575
   End
   Begin VB.CommandButton btnOpenFile
      Caption         =   "Open &File"
      Height          =   315
      Left            =   6420
      TabIndex        =   3
      Top             =   120
      Width           =   1575
   End
   Begin VB.PictureBox pic
      AutoSize        =   -1  'True
      Height          =   3015
      Left            =   300
      ScaleHeight     =   2955
      ScaleWidth      =   3435
      TabIndex        =   2
      Top             =   1320
      Width           =   3495
   End
   Begin VB.TextBox edtBase64
      Height          =   675
      Left            =   300
      MultiLine       =   -1  'True
      TabIndex        =   1
      Top             =   540
      Width           =   6015
   End
   Begin VB.TextBox edtPath
      Height          =   315
      Left            =   300
      TabIndex        =   0
      Text            =   "X:\lia.gif"
      Top             =   120
      Width           =   6015
   End
End
Attribute VB_Name = "Base64Pic"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub btnOpenBase64_Click()
    Dim pic As StdPicture
    Set pic = BinaryToPicture(edtBase64.Text)
    If Not pic Is Nothing Then
        Set Me.pic.Picture = pic
    Else
        MsgBox "Can't create picture from binary"
        Exit Sub
    End If
End Sub

Private Sub btnOpenFile_Click()
    Dim base64 As String
    base64 = ReadBinaryFile(edtPath)
    If base64 = "" Then
        MsgBox "Can't open binary file: " & edtPath
        Exit Sub
    End If

    edtBase64 = base64
    btnOpenBase64_Click
End Sub

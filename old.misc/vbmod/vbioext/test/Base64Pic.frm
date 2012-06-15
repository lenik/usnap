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
   Begin VB.CheckBox chkAutoBase64
      Caption         =   "&Auto base64"
      Height          =   315
      Left            =   300
      TabIndex        =   5
      Top             =   120
      Width           =   1335
   End
   Begin VB.ComboBox edtPath
      Height          =   315
      ItemData        =   "Base64Pic.frx":0000
      Left            =   1740
      List            =   "Base64Pic.frx":0010
      TabIndex        =   4
      Text            =   "x:\lia.gif"
      Top             =   120
      Width           =   4575
   End
   Begin VB.CommandButton btnOpenBase64
      Caption         =   "Open &Base64"
      Height          =   675
      Left            =   6420
      TabIndex        =   3
      Top             =   540
      Width           =   1575
   End
   Begin VB.CommandButton btnOpenFile
      Caption         =   "Open &File"
      Height          =   315
      Left            =   6420
      TabIndex        =   2
      Top             =   120
      Width           =   1575
   End
   Begin VB.PictureBox pic
      AutoSize        =   -1  'True
      Height          =   3015
      Left            =   300
      ScaleHeight     =   2955
      ScaleWidth      =   3435
      TabIndex        =   1
      Top             =   1320
      Width           =   3495
   End
   Begin VB.TextBox edtBase64
      Height          =   675
      Left            =   300
      MultiLine       =   -1  'True
      TabIndex        =   0
      Top             =   540
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
    OpenBase64 edtBase64.Text
End Sub

Private Sub btnOpenFile_Click()
    Dim fp As New FunctionProfile
    Set fp = New FunctionProfile
    Dim base64 As String
    base64 = ReadBinaryFile(edtPath)
    If base64 = "" Then
        MsgBox "Can't open binary file: " & edtPath
        Exit Sub
    End If

    If chkAutoBase64 Then
        edtBase64 = base64
        btnOpenBase64_Click
    Else
        OpenBase64 base64
    End If
End Sub

Sub OpenBase64(ByVal base64 As String)
    Dim pic As StdPicture
    Set pic = BinaryToPicture(base64)
    If Not pic Is Nothing Then
        Set Me.pic.Picture = pic
    Else
        MsgBox "Can't create picture from binary"
        Exit Sub
    End If
End Sub

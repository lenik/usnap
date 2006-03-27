VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5595
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7575
   LinkTopic       =   "Form1"
   ScaleHeight     =   5595
   ScaleWidth      =   7575
   StartUpPosition =   3  'Windows Default
   Begin VB.ComboBox bmode
      Height          =   315
      ItemData        =   "Form1.frx":0000
      Left            =   180
      List            =   "Form1.frx":000A
      Style           =   2  'Dropdown List
      TabIndex        =   8
      Top             =   3000
      Width           =   1575
   End
   Begin VB.CheckBox chkLazy
      Caption         =   "&Lazy"
      Height          =   435
      Left            =   180
      TabIndex        =   7
      Top             =   1020
      Width           =   1155
   End
   Begin VB.TextBox dst
      Height          =   2295
      Left            =   1980
      MultiLine       =   -1  'True
      TabIndex        =   6
      Top             =   3000
      Width           =   4575
   End
   Begin VB.CommandButton cmdDecode
      Caption         =   "&Decode"
      Height          =   375
      Left            =   5280
      TabIndex        =   5
      Top             =   2520
      Width           =   1275
   End
   Begin VB.CommandButton cmdEncode
      Caption         =   "&Encode"
      Height          =   375
      Left            =   3780
      TabIndex        =   4
      Top             =   2520
      Width           =   1215
   End
   Begin VB.ComboBox cboType
      Height          =   315
      ItemData        =   "Form1.frx":001B
      Left            =   1980
      List            =   "Form1.frx":0031
      Style           =   2  'Dropdown List
      TabIndex        =   3
      Top             =   2520
      Width           =   1695
   End
   Begin VB.TextBox src
      Height          =   1995
      Left            =   1920
      MultiLine       =   -1  'True
      TabIndex        =   1
      Text            =   "Form1.frx":0069
      Top             =   360
      Width           =   4635
   End
   Begin VB.Label Label2
      Caption         =   "&Type"
      Height          =   315
      Left            =   240
      TabIndex        =   2
      Top             =   2580
      Width           =   1515
   End
   Begin VB.Label Label1
      Caption         =   "&String"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   420
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdDecode_Click()
    Dim b64 As New Base64

    Select Case bmode.Text
    Case "Base64"
        b64.SetBase64 dst.Text
    Case "Hex"
        b64.SetHex dst.Text
    End Select

    Select Case cboType.Text
    Case "Raw"
        src.Text = b64.GetStringB
    Case Else
        src.Text = b64.GetString(cboType.Text)
    End Select
End Sub

Private Sub cmdEncode_Click()
    Dim b64 As New Base64

    Select Case cboType.Text
    Case "Raw"
        b64.SetStringB src.Text
    Case Else
        b64.SetString src.Text, cboType.Text
    End Select

    Select Case bmode.Text
    Case "Base64"
        dst.Text = b64.GetBase64
    Case "Hex"
        dst.Text = b64.GetHex(" ")
    End Select
End Sub

Private Sub Form_Load()
    cboType.ListIndex = 1
    bmode.ListIndex = 0
End Sub

Private Sub src_Change()
    If chkLazy Then cmdEncode_Click
End Sub

VERSION 5.00
Begin VB.Form frmJsb
   Caption         =   "frmJsb"
   ClientHeight    =   4125
   ClientLeft      =   60
   ClientTop       =   630
   ClientWidth     =   5565
   LinkTopic       =   "Form1"
   ScaleHeight     =   4125
   ScaleWidth      =   5565
   Begin VB.CommandButton cmdExit
      Caption         =   "E&xit"
      Height          =   375
      Left            =   3000
      TabIndex        =   2
      Top             =   3600
      Width           =   1935
   End
   Begin VB.CommandButton cmdSave
      Caption         =   "&Save"
      Height          =   375
      Left            =   480
      TabIndex        =   1
      Top             =   3600
      Width           =   2055
   End
   Begin VB.TextBox txtText
      Height          =   3375
      Left            =   240
      MousePointer    =   3  'I-Beam
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   0
      Text            =   "frmJsb.frx":0000
      Top             =   120
      Width           =   5055
   End
   Begin VB.Label Label1
      Caption         =   "Label1"
      Height          =   255
      Left            =   600
      TabIndex        =   3
      Top             =   1440
      Width           =   1215
   End
   Begin VB.Menu mnuFile
      Caption         =   "&F文件"
      Begin VB.Menu mnuFileLoad
         Caption         =   "Load"
         Shortcut        =   ^O
      End
      Begin VB.Menu mnuFileSave
         Caption         =   "Save"
         Shortcut        =   ^S
      End
      Begin VB.Menu mnuFileExit
         Caption         =   "E&xit"
         Shortcut        =   ^X
      End
   End
   Begin VB.Menu mnuHelp
      Caption         =   "&H帮助"
      Begin VB.Menu mnuHelpAbout
         Caption         =   "About"
      End
   End
End
Attribute VB_Name = "frmJsb"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim bChanged As Boolean

Sub LoadFile()
    nf = FreeFile
    Open "X:\hh" For Output As nf
        Input #nf, txtText.Text
    Close nf
    FileChanged False
End Sub

Sub SaveFile()
    nf = FreeFile
    Open "X:\hh" For Output As nf
        Write #nf, txtText.Text
    Close nf
    FileChanged False
End Sub

Private Sub cmdExit_Click()
    If bChanged Then
        r = MsgBox("文件已经修改, 尚未存盘, 现在存盘么?", vbYesNoCancel, "文件未存盘")
        Select Case r
        Case vbYes
            SaveFile
        Case vbCancel
            Exit Sub
        End Select
    End If
    End
End Sub

Private Sub Form_Load()
    FileChanged False
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
    cmdExit_Click
End Sub

Private Sub mnuFileExit_Click()
    cmdExit_Click
End Sub

Private Sub mnuFileLoad_Click()
    If bChanged Then
        r = MsgBox("文件已经修改, 尚未存盘, 现在存盘么?", vbYesNoCancel, "文件未存盘")
        Select Case r
        Case vbYes
            SaveFile
        Case vbCancel
            Exit Sub
        End Select
    End If
    LoadFile
End Sub

Private Sub mnuHelpAbout_Click()
    frmAbout.Show
End Sub

Private Sub txtText_Change()
    FileChanged True
End Sub

Private Sub FileChanged(b As Boolean)
    bChanged = b
    cmdSave.Enabled = b
    mnuFileSave.Enabled = b
End Sub

VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmAddFile
   Caption         =   "添加新程序"
   ClientHeight    =   2670
   ClientLeft      =   1815
   ClientTop       =   2235
   ClientWidth     =   4455
   Icon            =   "AddFile.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   2670
   ScaleWidth      =   4455
   Begin VB.CommandButton cmdAbort
      Cancel          =   -1  'True
      Caption         =   "&Abort!"
      Height          =   315
      Left            =   3300
      TabIndex        =   12
      Top             =   2220
      Width           =   855
   End
   Begin VB.CommandButton cmdOkey
      Caption         =   "&Okey!"
      Height          =   315
      Left            =   2040
      TabIndex        =   11
      Top             =   2220
      Width           =   855
   End
   Begin VB.CommandButton cmdBrowseIcon
      Caption         =   "..."
      Height          =   315
      Left            =   3480
      TabIndex        =   10
      Top             =   1260
      Width           =   375
   End
   Begin VB.CommandButton cmdBrowseFile
      Caption         =   "..."
      Height          =   315
      Left            =   3480
      MaskColor       =   &H000000FF&
      TabIndex        =   9
      Top             =   420
      UseMaskColor    =   -1  'True
      Width           =   375
   End
   Begin VB.ComboBox cboClass
      ForeColor       =   &H00FF0000&
      Height          =   315
      ItemData        =   "AddFile.frx":08CA
      Left            =   1380
      List            =   "AddFile.frx":08CC
      TabIndex        =   8
      Text            =   "Combo1"
      Top             =   1680
      Width           =   2055
   End
   Begin MSComDlg.CommonDialog cdFile
      Left            =   3900
      Top             =   360
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      DefaultExt      =   "txt"
      DialogTitle     =   "请选择可执行文件"
      Filter          =   "Executable files: *.exe;*.com|*.exe;*.com|DOS images|*.com"
      FilterIndex     =   1
   End
   Begin VB.TextBox txtIconFile
      Appearance      =   0  'Flat
      ForeColor       =   &H00FF0000&
      Height          =   285
      Left            =   1380
      TabIndex        =   6
      Top             =   1260
      Width           =   2055
   End
   Begin VB.TextBox txtAlias
      Appearance      =   0  'Flat
      ForeColor       =   &H00FF0000&
      Height          =   285
      Left            =   1380
      TabIndex        =   4
      Top             =   840
      Width           =   2055
   End
   Begin VB.TextBox txtProgramName
      Appearance      =   0  'Flat
      ForeColor       =   &H00FF0000&
      Height          =   285
      Left            =   1380
      TabIndex        =   2
      Top             =   420
      Width           =   2055
   End
   Begin MSComDlg.CommonDialog cdIconFile
      Left            =   3900
      Top             =   1200
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      DefaultExt      =   "txt"
      DialogTitle     =   "请选择图标"
      Filter          =   "All available|*.ico;*.jpg;*.bmp;*.wmf"
      FilterIndex     =   1
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "类别: "
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800000&
      Height          =   180
      Index           =   3
      Left            =   480
      TabIndex        =   7
      Top             =   1740
      Width           =   540
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "图标: "
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800000&
      Height          =   180
      Index           =   2
      Left            =   480
      TabIndex        =   5
      Top             =   1320
      Width           =   540
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "别名: "
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800000&
      Height          =   180
      Index           =   1
      Left            =   480
      TabIndex        =   3
      Top             =   900
      Width           =   540
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "文件名: "
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800000&
      Height          =   180
      Index           =   0
      Left            =   480
      TabIndex        =   1
      Top             =   480
      Width           =   720
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "添加新程序: "
      BeginProperty Font
         Name            =   "宋体"
         Size            =   11.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   225
      Left            =   180
      TabIndex        =   0
      Top             =   120
      Width           =   1365
   End
End
Attribute VB_Name = "frmAddFile"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Sub IBackup()
    txtAlias.Tag = txtAlias.Text
    txtProgramName.Tag = txtProgramName.Text
    txtIconFile.Tag = txtIconFile.Text
End Sub

Sub IRestore()
    txtAlias.Text = txtAlias.Tag
    txtProgramName.Text = txtProgramName.Tag
    txtIconFile.Text = txtIconFile.Tag
End Sub

Sub InitClassCombo()
    cboClass.Clear
    For I = 0 To MaxClass - 1
        cboClass.AddItem frmMain.PClass(I).Caption
    Next
    cboClass.ListIndex = CurClass
End Sub

Private Sub cmdAbort_Click()
    IRestore
    Me.Hide
End Sub

Private Sub cmdBrowseFile_Click()
    cdFile.FileName = txtProgramName.Text
    cdFile.ShowOpen
    If cdFile.CancelError = True Then
      Exit Sub
    Else
      txtProgramName.Text = cdFile.FileName
      txtAlias.Text = cdFile.FileTitle
    End If
End Sub

Private Sub cmdBrowseIcon_Click()
    cdIconFile.FileName = txtIconFile.Text
    cdIconFile.ShowOpen
    If cdIconFile.CancelError = True Then
      Exit Sub
    Else
      txtIconFile.Text = cdIconFile.FileName
    End If
End Sub

Private Sub cmdOkey_Click()
    Me.Hide
End Sub

Private Sub txtProgramName_Change()
    txtAlias.Text = txtProgramName.Text
    l = Len(txtProgramName.Text)
    If l < 2 Then Exit Sub
    For p = l - 1 To 1 Step -1
      If Mid(txtProgramName.Text, p, 1) = "\" Then
        txtAlias.Text = Mid(txtProgramName, p + 1)
        Exit For
      End If
    Next
    If LCase(Right(Trim(txtProgramName.Text), 4)) = ".exe" Then
      txtIconFile.Text = FSystemDir + SI_EXECUTABLE
    End If
End Sub

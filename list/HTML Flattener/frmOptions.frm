VERSION 5.00
Begin VB.Form frmOptions
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Options"
   ClientHeight    =   7650
   ClientLeft      =   45
   ClientTop       =   390
   ClientWidth     =   6600
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   7650
   ScaleWidth      =   6600
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.Frame Frame2
      Caption         =   "Change the output filenames"
      Height          =   2535
      Left            =   300
      TabIndex        =   6
      Top             =   1680
      Width           =   5895
      Begin VB.PictureBox Picture2
         BorderStyle     =   0  'None
         Height          =   2175
         Left            =   360
         ScaleHeight     =   2175
         ScaleWidth      =   5475
         TabIndex        =   7
         Top             =   300
         Width           =   5475
         Begin VB.TextBox txtNameDst
            Enabled         =   0   'False
            Height          =   315
            Left            =   660
            TabIndex        =   13
            Text            =   "$1.txt"
            Top             =   1740
            Width           =   4530
         End
         Begin VB.TextBox txtNameSrc
            Enabled         =   0   'False
            Height          =   315
            Left            =   660
            TabIndex        =   11
            Text            =   "^(.*)\.htm$"
            Top             =   1020
            Width           =   4530
         End
         Begin VB.OptionButton optNameRegex
            Caption         =   "Replace by Regular-e&xpression: "
            Height          =   300
            Left            =   0
            TabIndex        =   9
            Top             =   360
            Width           =   5175
         End
         Begin VB.OptionButton optNameDefault
            Caption         =   "<Original filenames>.txt"
            Height          =   300
            Left            =   0
            MaskColor       =   &H80000012&
            TabIndex        =   8
            Top             =   0
            Value           =   -1  'True
            Width           =   5175
         End
         Begin VB.Label lblNameDst
            Caption         =   "Target filename pattern: "
            Enabled         =   0   'False
            Height          =   285
            Left            =   300
            TabIndex        =   12
            Top             =   1440
            Width           =   4290
         End
         Begin VB.Label lblNameSrc
            Caption         =   "Source filename pattern: "
            Enabled         =   0   'False
            Height          =   285
            Left            =   300
            TabIndex        =   10
            Top             =   720
            Width           =   4290
         End
      End
   End
   Begin VB.Frame Frame1
      Caption         =   "Output directory: "
      Height          =   1395
      Left            =   300
      TabIndex        =   0
      Top             =   240
      Width           =   5895
      Begin VB.PictureBox Picture1
         BorderStyle     =   0  'None
         Height          =   1095
         Left            =   360
         ScaleHeight     =   1095
         ScaleWidth      =   5475
         TabIndex        =   1
         Top             =   240
         Width           =   5475
         Begin VB.TextBox txtOutDir
            Enabled         =   0   'False
            Height          =   285
            Left            =   300
            TabIndex        =   4
            Top             =   660
            Width           =   3630
         End
         Begin VB.OptionButton optOutSame
            Caption         =   "The &same directory as input"
            Height          =   300
            Left            =   0
            TabIndex        =   2
            Top             =   0
            Value           =   -1  'True
            Width           =   5175
         End
         Begin VB.OptionButton optOutSpec
            Caption         =   "Specify the output directory: "
            Height          =   300
            Left            =   0
            TabIndex        =   3
            Top             =   360
            Width           =   5175
         End
         Begin VB.CommandButton cmdOutBrowse
            Caption         =   "&Browse"
            Enabled         =   0   'False
            Height          =   315
            Left            =   4020
            TabIndex        =   5
            Top             =   660
            Width           =   1155
         End
      End
   End
   Begin VB.CheckBox chkIncludeTitle
      Caption         =   "Include HTML &Title in text files"
      Height          =   300
      Left            =   360
      TabIndex        =   15
      Top             =   4635
      Value           =   1  'Checked
      Width           =   5715
   End
   Begin VB.CheckBox chkBackup
      Caption         =   "Backup existing files (.ba&k)"
      Height          =   300
      Left            =   360
      TabIndex        =   14
      Top             =   4305
      Width           =   5715
   End
   Begin VB.CommandButton cmdCancel
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   375
      Left            =   4980
      TabIndex        =   24
      Top             =   6960
      Width           =   1155
   End
   Begin VB.CommandButton cmdOK
      Caption         =   "&OK"
      Default         =   -1  'True
      Height          =   375
      Left            =   3660
      TabIndex        =   23
      Top             =   6960
      Width           =   1155
   End
   Begin VB.TextBox txtTitleFormat
      Height          =   795
      Left            =   1020
      MultiLine       =   -1  'True
      TabIndex        =   22
      Text            =   "frmOptions.frx":0000
      Top             =   6000
      Width           =   5115
   End
   Begin VB.OptionButton optAlignRight
      Caption         =   "&Right"
      Height          =   315
      Left            =   3420
      TabIndex        =   20
      Top             =   5325
      Width           =   855
   End
   Begin VB.OptionButton optAlignCenter
      Caption         =   "&Center"
      Height          =   315
      Left            =   2220
      TabIndex        =   19
      Top             =   5325
      Width           =   855
   End
   Begin VB.TextBox txtScreenWidth
      Height          =   315
      Left            =   3060
      TabIndex        =   17
      Text            =   "80"
      Top             =   4980
      Width           =   930
   End
   Begin VB.OptionButton optAlignLeft
      Caption         =   "&Left"
      Height          =   315
      Left            =   1020
      TabIndex        =   18
      Top             =   5325
      Value           =   -1  'True
      Width           =   855
   End
   Begin VB.Label lblTitleFormat
      Caption         =   "Title &format"
      Height          =   285
      Left            =   660
      TabIndex        =   21
      Top             =   5700
      Width           =   930
   End
   Begin VB.Label lblScreenWidth
      Caption         =   "Screen &width (characters): "
      Height          =   285
      Left            =   660
      TabIndex        =   16
      Top             =   4995
      Width           =   2310
   End
End
Attribute VB_Name = "frmOptions"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit


Private Sub chkIncludeTitle_Click()
    Dim en As Boolean
    en = chkIncludeTitle.Value = vbChecked
    lblScreenWidth.Enabled = en
    txtScreenWidth.Enabled = en
    optAlignLeft.Enabled = en
    optAlignCenter.Enabled = en
    optAlignRight.Enabled = en
    lblTitleFormat.Enabled = en
    txtTitleFormat.Enabled = en
End Sub

Private Sub cmdCancel_Click()
    Me.Hide
End Sub

Private Sub cmdOK_Click()
    Unload Me
End Sub

Private Sub Form_Load()
    chkIncludeTitle.Enabled = IIf(IsRegistered, vbChecked, vbUnchecked)
End Sub

Private Sub optNameDefault_Click()
    lblNameSrc.Enabled = False
    txtNameSrc.Enabled = False
    lblNameDst.Enabled = False
    txtNameDst.Enabled = False
End Sub

Private Sub optNameRegex_Click()
    lblNameSrc.Enabled = True
    txtNameSrc.Enabled = True
    lblNameDst.Enabled = True
    txtNameDst.Enabled = True
End Sub

Private Sub optOutSame_Click()
    txtOutDir.Enabled = False
    cmdOutBrowse.Enabled = False
End Sub

Private Sub optOutSpec_Click()
    txtOutDir.Enabled = True
    cmdOutBrowse.Enabled = True
End Sub



Public Sub SetOptions(opts As Options)
    LoadOptions opts

    Me.Show 1

    SaveOptions opts
End Sub


Public Sub LoadOptions(opts As Options)
    If opts.OutSameDir Then
        optOutSame.Value = True
    Else
        optOutSame.Value = False
        txtOutDir.Text = opts.OutDir
    End If

    If opts.NameDefault Then
        optNameDefault.Value = True
    Else
        optNameDefault.Value = False
        txtNameSrc.Text = opts.NameSrc
        txtNameDst.Text = opts.NameDst
    End If

    chkBackup.Value = IIf(opts.Backup, vbChecked, vbUnchecked)

    chkIncludeTitle.Value = IIf(opts.IncludeTitle, vbChecked, vbUnchecked)

    If opts.IncludeTitle Then
        txtScreenWidth = Trim(Str(opts.ScreenWidth))
        Select Case opts.TitleAlignment
        Case vbLeftJustify
            optAlignLeft.Value = True
        Case vbCenter
            optAlignCenter.Value = True
        Case vbRightJustify
            optAlignRight.Value = True
        End Select
        txtTitleFormat = opts.TitleFormat
    End If
End Sub


Public Sub SaveOptions(opts As Options)
    If optOutSame Then
        opts.OutSameDir = True
    Else
        opts.OutSameDir = False
        opts.OutDir = txtOutDir.Text
    End If

    If optNameDefault Then
        opts.NameDefault = True
    Else
        opts.NameDefault = False
        opts.NameSrc = txtNameSrc
        opts.NameDst = txtNameDst
    End If

    opts.Backup = chkBackup.Value = vbChecked

    opts.IncludeTitle = chkIncludeTitle.Value = vbChecked

    If opts.IncludeTitle Then
        opts.ScreenWidth = Val(txtScreenWidth)
        If optAlignLeft Then opts.TitleAlignment = vbLeftJustify
        If optAlignCenter Then opts.TitleAlignment = vbCenter
        If optAlignRight Then opts.TitleAlignment = vbRightJustify
        opts.TitleFormat = txtTitleFormat
        'opts.Variables("TITLE") = txtTitleFormat
    End If
End Sub

Private Sub txtOutDir_Validate(Cancel As Boolean)
    On Error GoTo x
    With frmHTMLFlattener
        .FindFiles.Path = txtOutDir
        If .FindFiles.Path <> txtOutDir Then
            txtOutDir = .FindFiles.Path
        End If
    End With
    On Error GoTo 0
    Exit Sub
x:
    If Err.Number = 76 Then
        MsgBox "The specified directory isn't existed. ", vbInformation
        Cancel = True
        txtOutDir = ""
    End If
End Sub

Private Sub txtScreenWidth_Validate(Cancel As Boolean)
    If Not IsNumeric(txtScreenWidth) Then
        MsgBox "Screen width must be number", vbInformation
        Cancel = True
    End If

    Dim v As Integer
    v = Int(Abs(Val(txtScreenWidth)))
    If Str(v) <> txtScreenWidth Then
        txtScreenWidth = v
    End If
End Sub

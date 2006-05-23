VERSION 5.00
Object = "{6B7E6392-850A-101B-AFC0-4210102A8DA7}#1.3#0"; "COMCTL32.OCX"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5595
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6825
   LinkTopic       =   "Form1"
   ScaleHeight     =   5595
   ScaleWidth      =   6825
   StartUpPosition =   3  'Windows Default
   Begin ComctlLib.ProgressBar prog
      Align           =   2  'Align Bottom
      Height          =   375
      Left            =   0
      TabIndex        =   13
      Top             =   5220
      Width           =   6825
      _ExtentX        =   12039
      _ExtentY        =   661
      _Version        =   327682
      Appearance      =   1
   End
   Begin VB.TextBox txtPassword
      Height          =   435
      Left            =   2280
      TabIndex        =   12
      Top             =   3480
      Width           =   4335
   End
   Begin VB.CommandButton btnUnzip
      Caption         =   "Unzip"
      Height          =   735
      Left            =   3720
      TabIndex        =   10
      Top             =   4140
      Width           =   1455
   End
   Begin VB.TextBox txtUnzip
      Height          =   435
      Left            =   2280
      TabIndex        =   9
      Text            =   "C:\windows\msagent"
      Top             =   2880
      Width           =   4335
   End
   Begin VB.CommandButton btnZip
      Caption         =   "Zip"
      Height          =   735
      Left            =   1620
      TabIndex        =   7
      Top             =   4140
      Width           =   1455
   End
   Begin VB.TextBox txtZipName
      Height          =   435
      Left            =   2280
      TabIndex        =   6
      Top             =   2100
      Width           =   4335
   End
   Begin VB.TextBox txtZipDir
      Height          =   435
      Left            =   2280
      TabIndex        =   4
      Text            =   "C:\windows\temp\myzip\dir1"
      Top             =   1560
      Width           =   4335
   End
   Begin VB.CheckBox chkRecursive
      Caption         =   "&Recursive"
      Height          =   435
      Left            =   420
      TabIndex        =   2
      Top             =   840
      Width           =   2415
   End
   Begin VB.TextBox txtSrcDir
      Height          =   435
      Left            =   2280
      TabIndex        =   1
      Text            =   "C:\windows\msagent"
      Top             =   360
      Width           =   4335
   End
   Begin VB.Label Label5
      Caption         =   "&Password:"
      Height          =   375
      Left            =   420
      TabIndex        =   11
      Top             =   3480
      Width           =   1755
   End
   Begin VB.Label Label4
      Caption         =   "&Unzipped to directory: "
      Height          =   375
      Left            =   420
      TabIndex        =   8
      Top             =   2880
      Width           =   1755
   End
   Begin VB.Label Label3
      Caption         =   "Zipped name: "
      Height          =   375
      Left            =   420
      TabIndex        =   5
      Top             =   2100
      Width           =   1755
   End
   Begin VB.Label Label2
      Caption         =   "&Zipped directory: "
      Height          =   375
      Left            =   420
      TabIndex        =   3
      Top             =   1620
      Width           =   1755
   End
   Begin VB.Label Label1
      Caption         =   "Source directory: "
      Height          =   315
      Left            =   420
      TabIndex        =   0
      Top             =   420
      Width           =   1695
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private WithEvents m_Packer As Packer

Sub InitPacker()
    If txtZipName = "" Then
        txtZipName = BaseName(txtSrcDir)
    End If
    m_Packer.ZipFolder = txtSrcDir
    m_Packer.Recursive = chkRecursive.Value
    m_Packer.PackedPath = txtZipDir
    m_Packer.PackedName = txtZipName
    m_Packer.UnzipFolder = txtUnzip
    m_Packer.Secret = txtPassword
End Sub

Private Sub btnUnzip_Click()
    InitPacker
    m_Packer.Unpack
End Sub

Private Sub btnZip_Click()
    InitPacker
    m_Packer.Pack
End Sub

Private Sub Form_Load()
    Set m_Packer = New Packer
End Sub

Private Sub m_Packer_Progress(ByVal Percent As Single, Cancel As Boolean)
    prog.Value = Percent
End Sub

VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5130
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6825
   LinkTopic       =   "Form1"
   ScaleHeight     =   5130
   ScaleWidth      =   6825
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnUnzip
      Caption         =   "Unzip"
      Height          =   735
      Left            =   3480
      TabIndex        =   10
      Top             =   4080
      Width           =   1455
   End
   Begin VB.TextBox txtUnzip
      Height          =   435
      Left            =   2280
      TabIndex        =   9
      Text            =   "C:\windows\msagent"
      Top             =   3060
      Width           =   4335
   End
   Begin VB.CommandButton btnZip
      Caption         =   "Zip"
      Height          =   735
      Left            =   1380
      TabIndex        =   7
      Top             =   4080
      Width           =   1455
   End
   Begin VB.TextBox txtZipName
      Height          =   435
      Left            =   2280
      TabIndex        =   6
      Top             =   2280
      Width           =   4335
   End
   Begin VB.TextBox txtZipDir
      Height          =   435
      Left            =   2280
      TabIndex        =   4
      Text            =   "C:\windows\temp\myzip\dir1"
      Top             =   1740
      Width           =   4335
   End
   Begin VB.CheckBox chkRecursive
      Caption         =   "&Recursive"
      Height          =   435
      Left            =   420
      TabIndex        =   2
      Top             =   1020
      Width           =   2415
   End
   Begin VB.TextBox txtSrcDir
      Height          =   435
      Left            =   2280
      TabIndex        =   1
      Text            =   "C:\windows\msagent"
      Top             =   540
      Width           =   4335
   End
   Begin VB.Label Label4
      Caption         =   "&Unzipped to directory: "
      Height          =   375
      Left            =   420
      TabIndex        =   8
      Top             =   3060
      Width           =   1755
   End
   Begin VB.Label Label3
      Caption         =   "Zipped name: "
      Height          =   375
      Left            =   420
      TabIndex        =   5
      Top             =   2280
      Width           =   1755
   End
   Begin VB.Label Label2
      Caption         =   "&Zipped directory: "
      Height          =   375
      Left            =   420
      TabIndex        =   3
      Top             =   1800
      Width           =   1755
   End
   Begin VB.Label Label1
      Caption         =   "Source directory: "
      Height          =   315
      Left            =   420
      TabIndex        =   0
      Top             =   600
      Width           =   1695
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Label2_Click()

End Sub

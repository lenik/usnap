VERSION 5.00
Begin VB.Form Test_LayoutForm2
   Caption         =   "Form2"
   ClientHeight    =   4995
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7440
   LinkTopic       =   "Form2"
   ScaleHeight     =   333
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   496
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3
      Caption         =   "Command3"
      Height          =   495
      Left            =   120
      TabIndex        =   5
      Top             =   840
      Width           =   675
   End
   Begin VB.PictureBox Picture2
      Height          =   4035
      Left            =   960
      ScaleHeight     =   265
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   373
      TabIndex        =   0
      Top             =   420
      Width           =   5655
      Begin VB.ListBox List1
         Height          =   840
         Left            =   3540
         TabIndex        =   4
         Top             =   540
         Width           =   1275
      End
      Begin VB.PictureBox Picture1
         Height          =   1935
         Left            =   2160
         ScaleHeight     =   125
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   201
         TabIndex        =   2
         Top             =   1680
         Width           =   3075
         Begin VB.CommandButton Command1
            Caption         =   "Command1"
            Height          =   735
            Left            =   1140
            TabIndex        =   3
            Top             =   720
            Width           =   1095
         End
      End
      Begin VB.CommandButton Command2
         Caption         =   "Command2"
         Height          =   735
         Left            =   480
         TabIndex        =   1
         Top             =   780
         Width           =   1215
      End
   End
End
Attribute VB_Name = "Test_LayoutForm2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private m_Layout As New AutoScaleLayout

Private Sub Form_Load()
    m_Layout.InitializeCoordinations Me
End Sub

Private Sub Form_Resize()
    m_Layout.Relayout
End Sub

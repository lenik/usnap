VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   7590
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7875
   LinkTopic       =   "Form1"
   ScaleHeight     =   7590
   ScaleWidth      =   7875
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox p
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   750
      Index           =   0
      Left            =   150
      ScaleHeight     =   720
      ScaleWidth      =   690
      TabIndex        =   2
      Top             =   120
      Width           =   720
   End
   Begin VB.FileListBox File1
      Height          =   1455
      Left            =   5535
      TabIndex        =   1
      Top             =   5970
      Width           =   1890
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   585
      Left            =   615
      TabIndex        =   0
      Top             =   6855
      Width           =   1845
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        File1.Path = "H:\ÕÕÆ¬\2\07152002_133518"
        File1.Pattern = "*.jpg"

        Dim i
        For i = 1 To File1.ListCount - 1
                Load p(i)
                p(i).Left = p(i - 1).Left + p(i - 1).Width + 100
                p(i).Top = p(i - 1).Top
                If p(i).Left + p(i).Width >= Me.Width Then
                        p(i).Left = 0
                        p(i).Top = p(i - 1).Top + p(i - 1).Height + 100
                End If
                Set p(i).Picture = LoadPicture(File1.Path & "\" & File1.List(i))
                p(i).Visible = True
                DoEvents
        Next
End Sub

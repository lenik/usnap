VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   7335
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8760
   LinkTopic       =   "Form1"
   ScaleHeight     =   489
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   584
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   840
      Left            =   3375
      TabIndex        =   2
      Top             =   1290
      Width           =   3360
   End
   Begin VB.TextBox t
      BeginProperty Font
         Name            =   "Small Fonts"
         Size            =   6
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3885
      Left            =   270
      MultiLine       =   -1  'True
      TabIndex        =   1
      Top             =   3000
      Width           =   8205
   End
   Begin VB.PictureBox p
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   1530
      Left            =   210
      Picture         =   "Form1.frx":0000
      ScaleHeight     =   100
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   100
      TabIndex        =   0
      Top             =   135
      Width           =   1530
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        Dim x, y, c, l
        t = ""
        For y = 0 To p.ScaleHeight - 1
                l = ""
                For x = 0 To p.ScaleWidth - 1
                        c = p.Point(x, y)
                        Select Case c
                        Case &HFFFFFF 'white
                                l = l & "0"
                        Case &H8AFF& 'orange
                                l = l & "1"
                        Case &HDE5660 'blue
                                l = l & "2"
                        Case 0 'black
                                l = l & "3"
                        Case Else
                                l = l & "?"
                        End Select
                Next
                t = t & l & vbNewLine
        Next
End Sub

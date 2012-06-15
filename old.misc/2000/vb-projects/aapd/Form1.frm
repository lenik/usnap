VERSION 5.00
Begin VB.Form frmsel
   Appearance      =   0  'Flat
   BackColor       =   &H00C0FFC0&
   Caption         =   "Selector"
   ClientHeight    =   1680
   ClientLeft      =   165
   ClientTop       =   450
   ClientWidth     =   3225
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1680
   ScaleWidth      =   3225
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox List1
      Appearance      =   0  'Flat
      BackColor       =   &H00C0FFC0&
      Height          =   1395
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   2955
   End
   Begin VB.Timer T
      Interval        =   1000
      Left            =   285
      Top             =   7485
   End
End
Attribute VB_Name = "frmsel"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public canceled As Boolean

Private Sub Form_Resize()
        Static IGNORE As Boolean

        If Me.WindowState = 0 Then
                List1.Width = ScaleWidth
                List1.Height = ScaleHeight
                DoEvents

                IGNORE = True
                AdjustClientRect Me, _
                        List1.Width, List1.Height, _
                        Me.ScaleMode, Me.ScaleMode
                DoEvents
                IGNORE = False
        End If
End Sub

Public Function dosel()
        Dim I
        canceled = False
        Me.Show
        List1.Clear
        For Each I In winscol
                List1.AddItem I
        Next
        While Me.Visible
                DoEvents
                Sleep 10
        Wend
        dosel = List1.Text
End Function

Private Sub Form_Unload(Cancel As Integer)
        canceled = True
End Sub

Private Sub List1_DblClick()
        canceled = False
        Me.Hide
End Sub

Private Sub List1_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                KeyAscii = 0
                List1_DblClick
        End If
End Sub

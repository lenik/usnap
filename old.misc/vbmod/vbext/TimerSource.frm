VERSION 5.00
Begin VB.Form TimerSource
   Caption         =   "TimerSource"
   ClientHeight    =   1005
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   1725
   LinkTopic       =   "Form1"
   ScaleHeight     =   1005
   ScaleWidth      =   1725
   StartUpPosition =   3  'Windows Default
   Begin VB.Timer MakeUserActive
      Interval        =   500
      Left            =   840
      Top             =   300
   End
   Begin VB.Timer MemoryDetector
      Interval        =   60000
      Left            =   240
      Top             =   300
   End
End
Attribute VB_Name = "TimerSource"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub MakeUserActive_Timer()
    DoEvents
End Sub

Private Sub MemoryDetector_Timer()
    ' Test if memory low.
End Sub

VERSION 5.00
Begin VB.Form frmThread
   Caption         =   "Form1"
   ClientHeight    =   3930
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5595
   LinkTopic       =   "Form1"
   ScaleHeight     =   3930
   ScaleWidth      =   5595
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   615
      Left            =   300
      TabIndex        =   0
      Top             =   2160
      Width           =   1695
   End
   Begin VB.Label lblExit
      Caption         =   "Label1"
      Height          =   1020
      Left            =   300
      TabIndex        =   3
      Top             =   2880
      Width           =   5160
      WordWrap        =   -1  'True
   End
   Begin VB.Label lblWait
      AutoSize        =   -1  'True
      Caption         =   "Label1"
      Height          =   180
      Left            =   2280
      TabIndex        =   2
      Top             =   2100
      Width           =   540
   End
   Begin VB.Label lblCount
      Caption         =   "Label1"
      Height          =   495
      Left            =   960
      TabIndex        =   1
      Top             =   720
      Width           =   1995
   End
   Begin VB.Shape sLight
      BackStyle       =   1  'Opaque
      Height          =   555
      Left            =   3480
      Shape           =   2  'Oval
      Top             =   360
      Width           =   615
   End
End
Attribute VB_Name = "frmThread"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Sub a()
End Sub


Private Sub Command1_Click()
        Dim th As Long
        Dim h As Long
        Dim X As Long
        Dim r As Long
        h = CreateThread(0, 0, AddressOf WaitAndInc, 0, 0, th)
        Command1.Caption = "Create: " & h
        Do
                lblWait = "WAITING"
                DoEvents
                GetExitCodeThread h, X
        Loop While X = &H103&
        lblWait = "OK!"

        lblExit = lblExit & " " & X
        CloseHandle h

End Sub

VERSION 5.00
Begin VB.Form frmCeE3DAux1
   Caption         =   "CampoEngine.CeE3DAux.1"
   ClientHeight    =   3870
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5940
   LinkTopic       =   "Form1"
   ScaleHeight     =   3870
   ScaleWidth      =   5940
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   495
      Left            =   4710
      TabIndex        =   3
      Top             =   1005
      Width           =   1080
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   435
      Left            =   5325
      TabIndex        =   2
      Top             =   135
      Width           =   525
   End
   Begin VB.CommandButton initDC
      Caption         =   "initDC"
      Height          =   465
      Left            =   285
      TabIndex        =   1
      Top             =   3135
      Width           =   1140
   End
   Begin VB.PictureBox p
      Appearance      =   0  'Flat
      BackColor       =   &H00FFFFFF&
      ForeColor       =   &H80000008&
      Height          =   2580
      Left            =   1065
      ScaleHeight     =   2550
      ScaleWidth      =   3540
      TabIndex        =   0
      Top             =   75
      Width           =   3570
   End
End
Attribute VB_Name = "frmCeE3DAux1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public e3 As New CeE3DAux
Public e3b As New CeE3DBase

Private Sub Command1_Click()
        frmMain.Show
End Sub

Private Sub initDC_Click()
        Dim px As PIXELFORMATDESCRIPTOR
        Dim res As Long
        'e3.GetPixelFormat p.hDC, 0
        e3.initDC p.hDC

                e3.DrawBegin p.hDC
                        e3.DrawSolidTeapot 10
                        e3.SwapBuffers
                e3.DrawEnd p.hDC
                e3b.Flush
        e3.Endup
End Sub

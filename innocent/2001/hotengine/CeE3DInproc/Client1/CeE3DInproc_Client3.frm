VERSION 5.00
Begin VB.Form frmCeE3DInproc_Client3
   Caption         =   "CeE3DInproc_Client3"
   ClientHeight    =   3645
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   5520
   Icon            =   "CeE3DInproc_Client3.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   243
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   368
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox p
      AutoRedraw      =   -1  'True
      Height          =   2370
      Left            =   600
      ScaleHeight     =   154
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   278
      TabIndex        =   0
      Top             =   225
      Width           =   4230
   End
   Begin VB.Menu mnuDraw
      Caption         =   "&Draw"
      Begin VB.Menu mnuTeapot
         Caption         =   "&Teapot"
         Shortcut        =   ^T
      End
   End
End
Attribute VB_Name = "frmCeE3DInproc_Client3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()
        ceAux.InitDC p.hdc

End Sub

Private Sub Form_Resize()
        p_Resize
End Sub

Private Sub mnuTeapot_Click()
        ceAux.DrawBegin p.hdc

        ceRender.SetDepthFunc DEPTHFUNC_LEQUAL
        ceRender.ShadeSmooth

        ceEnv.StartLighting
        ceEnv.EnableLight 0
        'ceEnv.SetLightPositionf 0, 0, 0, 10, 0

        ceBase.ClearColor 0, 0, 1, 1
        ceAux.ClearAll
        ceBase.Clear CEE3D_DEPTH_BUFFER_BIT

        ceBase.Color3f 1, 1, 1
        ceAux.DrawSolidTorus 0.1, 0.7
        'ceAux.DrawWireTeapot 0.7

        ceBase.Flush
        ceAux.SwapBuffers

        ceAux.DrawEnd p.hdc
        p.Refresh
End Sub

Private Sub p_Resize()
        Dim hdc As Long
        Dim r As Boolean
        hdc = p.hdc
        r = ceAux.DrawBegin(hdc)
                ceBase.Viewport 0, 0, p.Width, p.Height
        r = ceAux.DrawEnd(hdc)
End Sub

VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "Visual BSD"
   ClientHeight    =   3645
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   6180
   LinkTopic       =   "Form1"
   ScaleHeight     =   3645
   ScaleWidth      =   6180
   StartUpPosition =   3  '����ȱʡ
   Begin VB.Menu mnuFile
      Caption         =   "&F�ļ�"
      Begin VB.Menu mnuFOpenStatic
         Caption         =   "&O�򿪾�̬ͼ���ļ�"
         Shortcut        =   ^O
      End
      Begin VB.Menu mnuOpenDynamics
         Caption         =   "&D�򿪶�̬ͼ���ļ�"
         Enabled         =   0   'False
         Shortcut        =   ^D
      End
      Begin VB.Menu mnuFSave
         Caption         =   "&S����"
         Shortcut        =   ^S
      End
      Begin VB.Menu mnuFS1
         Caption         =   "-"
      End
      Begin VB.Menu mnuFExportBSD
         Caption         =   "&E����BSD..."
         Shortcut        =   ^E
      End
      Begin VB.Menu mnuFS2
         Caption         =   "-"
      End
      Begin VB.Menu mnuFExit
         Caption         =   "&X�˳�"
         Shortcut        =   ^X
      End
      Begin VB.Menu mnuFS3
         Caption         =   "-"
      End
      Begin VB.Menu mnuFRecent
         Caption         =   "&0"
         Index           =   0
      End
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub mnuFExit_Click()
        End
End Sub

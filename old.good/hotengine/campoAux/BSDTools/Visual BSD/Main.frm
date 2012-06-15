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
   StartUpPosition =   3  '窗口缺省
   Begin VB.Menu mnuFile
      Caption         =   "&F文件"
      Begin VB.Menu mnuFOpenStatic
         Caption         =   "&O打开静态图像文件"
         Shortcut        =   ^O
      End
      Begin VB.Menu mnuOpenDynamics
         Caption         =   "&D打开动态图像文件"
         Enabled         =   0   'False
         Shortcut        =   ^D
      End
      Begin VB.Menu mnuFSave
         Caption         =   "&S保存"
         Shortcut        =   ^S
      End
      Begin VB.Menu mnuFS1
         Caption         =   "-"
      End
      Begin VB.Menu mnuFExportBSD
         Caption         =   "&E导出BSD..."
         Shortcut        =   ^E
      End
      Begin VB.Menu mnuFS2
         Caption         =   "-"
      End
      Begin VB.Menu mnuFExit
         Caption         =   "&X退出"
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

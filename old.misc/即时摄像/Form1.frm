VERSION 5.00
Object = "{84926CA3-2941-101C-816F-0E6013114B7F}#1.0#0"; "ImgScan.ocx"
Begin VB.Form Form1
   Caption         =   "‘∂æ∞…„œÒœµÕ≥"
   ClientHeight    =   6405
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8280
   LinkTopic       =   "Form1"
   ScaleHeight     =   6405
   ScaleWidth      =   8280
   StartUpPosition =   3  'Windows Default
   Begin ScanLibCtl.ImgScan is1
      Left            =   1650
      Top             =   3900
      _Version        =   65536
      _ExtentX        =   952
      _ExtentY        =   1058
      _StockProps     =   0
      PageType        =   6
      CompressionType =   6
      CompressionInfo =   4096
      ShowSetupBeforeScan=   0   'False
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   1290
      Left            =   3045
      TabIndex        =   0
      Top             =   3675
      Width           =   2505
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        is1.StartScan
End Sub

Private Sub is1_PageDone(ByVal PageNumber As Long)
        msgbox "page done"
End Sub

Private Sub is1_ScanDone()
        msgbox "scan done"
End Sub

Private Sub is1_ScanStarted()
        msgbox "scan started"
End Sub

Private Sub is1_ScanUIDone()
        msgbox "scan ui done"
End Sub

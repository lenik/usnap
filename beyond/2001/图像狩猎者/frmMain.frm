VERSION 5.00
Object = "{6D940288-9F11-11CE-83FD-02608C3EC08A}#2.2#0"; "ksti1.dll"
Object = "{84926CA3-2941-101C-816F-0E6013114B7F}#1.0#0"; "ksti2.dll"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5640
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7155
   LinkTopic       =   "Form1"
   ScaleHeight     =   5640
   ScaleWidth      =   7155
   StartUpPosition =   3  'Windows Default
   Begin ScanLibCtl.ImgScan ImgScan1
      Left            =   1350
      Top             =   3630
      _Version        =   65536
      _ExtentX        =   847
      _ExtentY        =   873
      _StockProps     =   0
      DestImageControl=   "ImgEdit"
   End
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   975
      Left            =   2040
      TabIndex        =   2
      Top             =   4560
      Width           =   1395
   End
   Begin ImgeditLibCtl.ImgEdit ImgEdit1
      Height          =   3015
      Left            =   2130
      TabIndex        =   1
      Top             =   540
      Width           =   3735
      _Version        =   131074
      _ExtentX        =   6588
      _ExtentY        =   5318
      _StockProps     =   96
      BorderStyle     =   1
      Image           =   "C:\Documents and Settings\zauj.d\My Documents\ÕÕÆ¬·Ö±æÂÊ·ÖÎö\ÍÑÅÄ1024x768 HQ.tif"
      ImageControl    =   "ImgEdit"
      UndoBufferSize  =   38289920
      OcrZoneVisibility=   -3600
      AnnotationOcrType=   25649
      ForceFileLinking1x=   -1  'True
      MagnifierZoom   =   25649
      sReserved1      =   -3600
      sReserved2      =   -3600
      lReserved1      =   19696304
      lReserved2      =   19696304
      bReserved1      =   -1  'True
      bReserved2      =   -1  'True
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   855
      Left            =   3960
      TabIndex        =   0
      Top             =   4020
      Width           =   2175
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        ImgScan1.ShowSelectScanner
End Sub

Private Sub Command2_Click()
        ImgScan1.StartScan
End Sub

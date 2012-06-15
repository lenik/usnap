VERSION 5.00
Object = "{6D940288-9F11-11CE-83FD-02608C3EC08A}#2.2#0"; "ImgEdit.ocx"
Object = "{84926CA3-2941-101C-816F-0E6013114B7F}#1.0#0"; "ImgScan.ocx"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin ScanLibCtl.ImgScan ImgScan1
      Left            =   1920
      Top             =   2160
      _Version        =   65536
      _ExtentX        =   873
      _ExtentY        =   873
      _StockProps     =   0
   End
   Begin ImgeditLibCtl.ImgEdit ImgEdit1
      Height          =   795
      Left            =   1620
      TabIndex        =   0
      Top             =   1200
      Width           =   1515
      _Version        =   131074
      _ExtentX        =   2672
      _ExtentY        =   1402
      _StockProps     =   96
      BorderStyle     =   1
      ImageControl    =   "ImgEdit"
      UndoBufferSize  =   69378560
      OcrZoneVisibility=   -3524
      AnnotationOcrType=   25649
      ForceFileLinking1x=   -1  'True
      MagnifierZoom   =   25649
      sReserved1      =   -3524
      sReserved2      =   -3524
      lReserved1      =   1241720
      lReserved2      =   1241720
      bReserved1      =   -1  'True
      bReserved2      =   -1  'True
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

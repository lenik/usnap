VERSION 5.00
Object = "{009541A3-3B81-101C-92F3-040224009C02}#2.1#0"; "ImgAdmin.ocx"
Object = "{6D940288-9F11-11CE-83FD-02608C3EC08A}#2.2#0"; "ImgEdit.ocx"
Object = "{84926CA3-2941-101C-816F-0E6013114B7F}#1.0#0"; "ImgScan.ocx"
Object = "{E1A6B8A3-3603-101C-AC6E-040224009C02}#1.0#0"; "ImgThumb.ocx"
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5055
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5610
   LinkTopic       =   "Form1"
   ScaleHeight     =   5055
   ScaleWidth      =   5610
   StartUpPosition =   3  'Windows Default
   Begin ScanLibCtl.ImgScan ImgScan2
      Left            =   645
      Top             =   2550
      _Version        =   65536
      _ExtentX        =   820
      _ExtentY        =   820
      _StockProps     =   0
      PageType        =   6
      CompressionType =   6
      CompressionInfo =   4096
   End
   Begin ThumbnailLibCtl.ImgThumbnail ImgThumbnail1
      Height          =   1110
      Left            =   3165
      TabIndex        =   2
      Top             =   3660
      Width           =   1410
      _Version        =   65536
      _ExtentX        =   2487
      _ExtentY        =   1958
      _StockProps     =   97
      BackColor       =   12632256
      BorderStyle     =   1
      ThumbHeight     =   120
   End
   Begin ScanLibCtl.ImgScan ImgScan1
      Left            =   1530
      Top             =   3810
      _Version        =   65536
      _ExtentX        =   1032
      _ExtentY        =   847
      _StockProps     =   0
      PageType        =   6
      CompressionType =   6
      CompressionInfo =   4096
   End
   Begin ImgeditLibCtl.ImgAnnTool ImgAnnTool1
      Height          =   495
      Left            =   285
      TabIndex        =   1
      Top             =   4095
      Width           =   540
      _Version        =   131074
      _ExtentX        =   952
      _ExtentY        =   873
      _StockProps     =   64
      AnnotationType  =   6
      DestImageControl=   $"Form1.frx":0000
   End
   Begin ImgeditLibCtl.ImgEdit ImgEdit1
      Height          =   2850
      Left            =   2055
      TabIndex        =   0
      Top             =   810
      Width           =   3255
      _Version        =   131074
      _ExtentX        =   5741
      _ExtentY        =   5027
      _StockProps     =   96
      BorderStyle     =   1
      ImageControl    =   "ImgEdit"
      UndoBufferSize  =   22797568
      OcrZoneVisibility=   -3380
      AnnotationOcrType=   25649
      ForceFileLinking1x=   -1  'True
      MagnifierZoom   =   25649
      sReserved1      =   -3380
      sReserved2      =   -3380
      lReserved1      =   1241864
      lReserved2      =   1241864
      bReserved1      =   -1  'True
      bReserved2      =   -1  'True
   End
   Begin AdminLibCtl.ImgAdmin ImgAdmin1
      Left            =   360
      Top             =   1020
      _Version        =   131073
      _ExtentX        =   2355
      _ExtentY        =   2090
      _StockProps     =   0
      PrintStartPage  =   0
      PrintEndPage    =   0
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form frmNetStatus
   BackColor       =   &H00FFFFFF&
   Caption         =   "ÍøÂç×´Ì¬"
   ClientHeight    =   1815
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3435
   Icon            =   "f2NetStatus.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1815
   ScaleWidth      =   3435
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin MSComctlLib.ProgressBar NIN
      Height          =   1080
      Left            =   120
      TabIndex        =   1
      Top             =   180
      Width           =   570
      _ExtentX        =   1005
      _ExtentY        =   1905
      _Version        =   393216
      Appearance      =   0
      Orientation     =   1
      Scrolling       =   1
   End
   Begin VB.Label qqq
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      Caption         =   "ÊäÈë"
      ForeColor       =   &H80000008&
      Height          =   180
      Left            =   240
      TabIndex        =   2
      Top             =   1440
      Width           =   360
   End
   Begin VB.Label lblRox
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      Caption         =   "*"
      ForeColor       =   &H80000008&
      Height          =   180
      Left            =   2760
      TabIndex        =   0
      Top             =   120
      Width           =   90
   End
End
Attribute VB_Name = "frmNetStatus"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

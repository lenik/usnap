VERSION 5.00
Begin VB.Form frmMessage
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "草原软件"
   ClientHeight    =   960
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   4305
   Icon            =   "f2Message.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   64
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   287
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  '窗口缺省
   Begin VB.Timer maxDelay
      Interval        =   1000
      Left            =   180
      Top             =   360
   End
   Begin VB.CommandButton cmdOK
      Caption         =   "&OK"
      Default         =   -1  'True
      Height          =   315
      Left            =   1500
      TabIndex        =   1
      Top             =   480
      Width           =   1215
   End
   Begin VB.Label lblDelay
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "0"
      ForeColor       =   &H80000008&
      Height          =   210
      Left            =   60
      TabIndex        =   2
      Top             =   60
      Width           =   120
   End
   Begin VB.Label lblInfo
      AutoSize        =   -1  'True
      Caption         =   "Hello!"
      Height          =   180
      Left            =   1860
      TabIndex        =   0
      Top             =   180
      Width           =   540
   End
End
Attribute VB_Name = "frmMessage"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public nHMarginL As Single, nHMarginR As Single, nVMargin As Single
Public done As Boolean

Public currentDelay As Long

Public Sub Run(ByVal info As String, Optional ByVal maxDelayTime As Long = 10)
        lblInfo = info
        Relocation
        done = False
        Me.Show

        currentDelay = maxDelayTime

        While Not done And currentDelay > 0
                DoEvents
        Wend

        Me.Hide
End Sub

Public Sub SetInfo(ByVal info As String)
        lblInfo = info
        Relocation
End Sub

Sub Relocation()
        Dim SizeNeededW As Single, SizeNeededH As Single

        SizeNeededW = lblInfo.width + nHMarginL + nHMarginR
        SizeNeededH = lblInfo.height + nVMargin * 2

        If SizeNeededW < 150 Then SizeNeededW = 150
        If SizeNeededH < 130 Then SizeNeededH = 130

        Me.width = SizeNeededW * Screen.TwipsPerPixelX
        'Me.height = SizeNeededH * Screen.TwipsPerPixelY

        lblInfo.Left = (SizeNeededW - lblInfo.width) / 2
        cmdOK.Left = (SizeNeededW - cmdOK.width) / 2
End Sub

Private Sub cmdOK_Click()
        done = True
End Sub

Private Sub Form_Load()
        nHMarginL = 32
        nHMarginR = 48
        nVMargin = 32
End Sub

Private Sub maxDelay_Timer()
        currentDelay = currentDelay - 1
        lblDelay = currentDelay
End Sub

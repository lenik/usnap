VERSION 5.00
Begin VB.Form frmWaitingBox
   BackColor       =   &H00E0E0E0&
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "草原软件"
   ClientHeight    =   2115
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   4800
   Icon            =   "f2WatingBox.frx":0000
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   141
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   320
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  '所有者中心
   Begin VB.Timer tmrSwitch
      Enabled         =   0   'False
      Interval        =   150
      Left            =   180
      Top             =   1500
   End
   Begin VB.PictureBox picClip
      Appearance      =   0  'Flat
      BackColor       =   &H0000FF00&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Left            =   960
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   1
      Top             =   660
      Width           =   480
      Begin VB.PictureBox picSeq
         Appearance      =   0  'Flat
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   480
         Left            =   0
         Picture         =   "f2WatingBox.frx":0E42
         ScaleHeight     =   480
         ScaleWidth      =   3840
         TabIndex        =   2
         Top             =   0
         Width           =   3840
      End
   End
   Begin VB.Label lblInfo
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "-"
      Height          =   180
      Left            =   1740
      TabIndex        =   3
      Top             =   780
      Width           =   90
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "[picClip]"
      Height          =   180
      Left            =   780
      TabIndex        =   0
      Top             =   420
      Visible         =   0   'False
      Width           =   810
   End
End
Attribute VB_Name = "frmWaitingBox"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim curFrame As Integer

Public nHMarginL As Single, nHMarginR As Single, nVMargin As Single
Public nIconSpace As Single

Private oPicture As StdPicture
Public Sub TurnOn(ByVal info As String, Optional showpic As PictureBox = Nothing)
        lblInfo = info
        Set oPicture = picSeq.Picture
        If Not showpic Is Nothing Then picSeq.Picture = showpic.Picture

        Relocation
        Me.Show
        tmrSwitch.Enabled = True
End Sub

Public Sub TurnOff()
        tmrSwitch.Enabled = False
        Set picSeq.Picture = oPicture
        Set oPicture = Nothing
        Me.Hide
End Sub

Public Sub SetInfo(ByVal info As String, Optional showpic As PictureBox = Nothing)
        lblInfo = info
        If Not showpic Is Nothing Then Set picSeq.Picture = showpic.Picture
        Relocation
End Sub

Sub Relocation()
        Dim SizeNeededW As Single, SizeNeededH As Single

        SizeNeededW = picClip.width + nIconSpace + lblInfo.width + nHMarginL + nHMarginR
        SizeNeededH = picClip.height
        If SizeNeededH < lblInfo.height Then SizeNeededH = lblInfo.height
        SizeNeededH = SizeNeededH + nVMargin * 2

        picClip.Left = nHMarginL
        lblInfo.Left = picClip.Left + picClip.width + nIconSpace

        If picClip.height > lblInfo.height Then
                picClip.Top = nVMargin
                lblInfo.Top = picClip.Top + picClip.height / 2 - lblInfo.height / 2
        Else
                lblInfo.Top = nVMargin
                picClip.Top = lblInfo.Top + lblInfo.height / 2 - picClip.height / 2
        End If

        Me.width = SizeNeededW * 15
        Me.height = (SizeNeededH + 17) * 15
End Sub

Private Sub tmrSwitch_Timer()
        picSeq.Left = -picClip.width * curFrame
        curFrame = curFrame + 1
        If curFrame >= Int(picSeq.width / picClip.width) Then curFrame = 0
        DoEvents
End Sub

Private Sub Form_Load()
        curFrame = 0
        nHMarginL = 32
        nHMarginR = 48
        nVMargin = 32
        nIconSpace = 16
End Sub

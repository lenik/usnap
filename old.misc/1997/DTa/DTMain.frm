VERSION 5.00
Begin VB.Form DTMain
   BackColor       =   &H80000005&
   Caption         =   "¾ö²ß±í¥¢"
   ClientHeight    =   3315
   ClientLeft      =   2310
   ClientTop       =   2220
   ClientWidth     =   6660
   Icon            =   "DTMain.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   3315
   ScaleWidth      =   6660
   Begin VB.PictureBox DTTitle
      AutoSize        =   -1  'True
      BorderStyle     =   0  'None
      Height          =   480
      Left            =   1920
      Picture         =   "DTMain.frx":030A
      ScaleHeight     =   480
      ScaleWidth      =   4800
      TabIndex        =   6
      Top             =   0
      Width           =   4800
   End
   Begin VB.PictureBox mnuDTDTI
      AutoSize        =   -1  'True
      Height          =   1980
      Left            =   960
      Picture         =   "DTMain.frx":7B4E
      ScaleHeight     =   1920
      ScaleWidth      =   1440
      TabIndex        =   5
      Top             =   480
      Visible         =   0   'False
      Width           =   1500
   End
   Begin VB.PictureBox mnuDTDT
      AutoSize        =   -1  'True
      BackColor       =   &H8000000E&
      BorderStyle     =   0  'None
      Height          =   480
      Left            =   960
      Picture         =   "DTMain.frx":93D0
      ScaleHeight     =   480
      ScaleWidth      =   480
      TabIndex        =   4
      Top             =   0
      Width           =   480
   End
   Begin VB.PictureBox mnuDTLibI
      AutoSize        =   -1  'True
      Height          =   1020
      Left            =   480
      Picture         =   "DTMain.frx":96DA
      ScaleHeight     =   960
      ScaleWidth      =   1440
      TabIndex        =   3
      Top             =   480
      Visible         =   0   'False
      Width           =   1500
   End
   Begin VB.PictureBox mnuDTSystemI
      AutoSize        =   -1  'True
      Height          =   1500
      Left            =   0
      Picture         =   "DTMain.frx":A35C
      ScaleHeight     =   96
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   96
      TabIndex        =   2
      Top             =   480
      Visible         =   0   'False
      Width           =   1500
   End
   Begin VB.PictureBox mnuDTLib
      AutoSize        =   -1  'True
      BackColor       =   &H8000000E&
      BorderStyle     =   0  'None
      Height          =   480
      Left            =   480
      Picture         =   "DTMain.frx":B5DE
      ScaleHeight     =   480
      ScaleWidth      =   480
      TabIndex        =   1
      Top             =   0
      Width           =   480
   End
   Begin VB.PictureBox mnuDTSystem
      AutoSize        =   -1  'True
      BackColor       =   &H8000000E&
      BorderStyle     =   0  'None
      Height          =   480
      Left            =   0
      Picture         =   "DTMain.frx":B8E8
      ScaleHeight     =   480
      ScaleWidth      =   480
      TabIndex        =   0
      Top             =   0
      Width           =   480
   End
   Begin VB.PictureBox aviTopCroak
      BackColor       =   &H80000012&
      BorderStyle     =   0  'None
      Height          =   2175
      Left            =   1560
      ScaleHeight     =   145
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   249
      TabIndex        =   7
      Top             =   840
      Width           =   3735
   End
End
Attribute VB_Name = "DTMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Dim mnuDTSystemE As Boolean, mnuDTLibE As Boolean, mnuDTDTE As Boolean


Private Sub Form_Load()
Dim Buf As String * 512
Dim ReturnVal As Long, ReturnStr As String * 128

DTDir = "D:\Develop\Basic\CVB5\DTa\Images"

    ReturnVal = mciSendString("open " + DTDir + "\TopCroak.avi type avivideo alias TC", ReturnStr, 128, 0)
    ReturnVal = mciGetErrorString(ReturnVal, Buf, 512)

    ReturnVal = mciSendString("window TC handle " + Str(aviTopCroak.hWnd) + " ", ReturnStr, 128, 0)
    ReturnVal = mciGetErrorString(ReturnVal, Buf, 512)

    ReturnVal = mciSendString("cue TC to 0", ReturnStr, 128, 0)
    ReturnVal = mciGetErrorString(ReturnVal, Buf, 512)

    ReturnVal = mciSendString("seek TC to start", ReturnStr, 128, 0)
    ReturnVal = mciGetErrorString(ReturnVal, Buf, 512)

    ReturnVal = mciSendString("play TC", ReturnStr, 128, 0)
    ReturnVal = mciGetErrorString(ReturnVal, Buf, 512)

End Sub


Private Sub mnuDTSystem_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If mnuDTSystemE = False Then
        If mnuDTLibE Then mnuDTLib_MouseDown 1, 0, 0, 0: mnuDTLib_MouseUp 1, 0, 0, 0
        If mnuDTDTE Then mnuDTDT_MouseDown 1, 0, 0, 0: mnuDTDT_MouseUp 1, 0, 0, 0
        mnuDTSystem.BorderStyle = 1 - mnuDTSystem.BorderStyle
    Else
        mnuDTSystemI.Visible = Not mnuDTSystemI.Visible
    End If
End Sub
Private Sub mnuDTSystem_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If mnuDTSystemE = False Then
        mnuDTSystemI.Visible = Not mnuDTSystemI.Visible
    Else
        mnuDTSystem.BorderStyle = 1 - mnuDTSystem.BorderStyle
    End If
    mnuDTSystemE = Not mnuDTSystemE
End Sub
Private Sub mnuDTSystemI_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If X >= 0 And X <= 95 Then
        mnuDTSystem_MouseDown 1, 0, 0, 0: mnuDTSystem_MouseUp 1, 0, 0, 0
        If Y >= 0 And Y <= 31 Then DTEnd
        If Y >= 32 And Y <= 63 Then DTHelp.Show
        If Y >= 64 And Y <= 95 Then DTAbout.Show
    End If
End Sub



Private Sub mnuDTLib_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If mnuDTLibE = False Then
        If mnuDTSystemE Then mnuDTSystem_MouseDown 1, 0, 0, 0: mnuDTSystem_MouseUp 1, 0, 0, 0
        If mnuDTDTE Then mnuDTDT_MouseDown 1, 0, 0, 0: mnuDTDT_MouseUp 1, 0, 0, 0
        mnuDTLib.BorderStyle = 1 - mnuDTLib.BorderStyle
    Else
        mnuDTLibI.Visible = Not mnuDTLibI.Visible
    End If
End Sub
Private Sub mnuDTLib_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If mnuDTLibE = False Then
        mnuDTLibI.Visible = Not mnuDTLibI.Visible
    Else
        mnuDTLib.BorderStyle = 1 - mnuDTLib.BorderStyle
    End If
    mnuDTLibE = Not mnuDTLibE
End Sub
Private Sub mnuDTLibI_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If X >= 0 And X <= 95 Then
        mnuDTLib_MouseDown 1, 0, 0, 0: mnuDTLib_MouseUp 1, 0, 0, 0

        If Y >= 0 And Y <= 31 Then End
        If Y >= 32 And Y <= 63 Then DTHelp.Show
        If Y >= 64 And Y <= 95 Then DTAbout.Show
    End If
End Sub



Private Sub mnuDTDT_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If mnuDTDTE = False Then
        If mnuDTLibE Then mnuDTLib_MouseDown 1, 0, 0, 0: mnuDTLib_MouseUp 1, 0, 0, 0
        If mnuDTSystemE Then mnuDTSystem_MouseDown 1, 0, 0, 0: mnuDTSystem_MouseUp 1, 0, 0, 0
        mnuDTDT.BorderStyle = 1 - mnuDTDT.BorderStyle
    Else
        mnuDTDTI.Visible = Not mnuDTDTI.Visible
    End If
End Sub
Private Sub mnuDTDT_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If mnuDTDTE = False Then
        mnuDTDTI.Visible = Not mnuDTDTI.Visible
    Else
        mnuDTDT.BorderStyle = 1 - mnuDTDT.BorderStyle
    End If
    mnuDTDTE = Not mnuDTDTE
End Sub
Private Sub mnuDTDTI_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If X >= 0 And X <= 95 Then
        mnuDTDT_MouseDown 1, 0, 0, 0: mnuDTDT_MouseUp 1, 0, 0, 0
        If Y >= 0 And Y <= 31 Then End
        If Y >= 32 And Y <= 63 Then DTHelp.Show
        If Y >= 64 And Y <= 95 Then DTAbout.Show
    End If
End Sub

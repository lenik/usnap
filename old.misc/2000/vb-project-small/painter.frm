VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmPat
   Caption         =   "画笔"
   ClientHeight    =   3675
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5280
   LinkTopic       =   "Form1"
   ScaleHeight     =   3675
   ScaleWidth      =   5280
   StartUpPosition =   3  'Windows Default
   Begin MSComDlg.CommonDialog cdColorPal
      Left            =   4080
      Top             =   600
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin MSComctlLib.ImageList imgIcons
      Left            =   4560
      Top             =   600
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628}
         NumListImages   =   4
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "painter.frx":0000
            Key             =   "New"
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "painter.frx":015C
            Key             =   "Pixel"
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "painter.frx":0478
            Key             =   "ColorPal"
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628}
            Picture         =   "painter.frx":0794
            Key             =   "Exit"
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.Toolbar tbTools
      Align           =   1  'Align Top
      Height          =   555
      Left            =   0
      TabIndex        =   1
      Top             =   0
      Width           =   5280
      _ExtentX        =   9313
      _ExtentY        =   979
      ButtonWidth     =   1138
      ButtonHeight    =   926
      Appearance      =   1
      Style           =   1
      ImageList       =   "imgIcons"
      _Version        =   393216
      BeginProperty Buttons {66833FE8-8583-11D1-B16A-00C0F0283628}
         NumButtons      =   7
         BeginProperty Button1 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Caption         =   "新文件"
            Key             =   "New"
            ImageIndex      =   1
         EndProperty
         BeginProperty Button2 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Style           =   3
         EndProperty
         BeginProperty Button3 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Caption         =   "画点"
            Key             =   "Pixel"
            ImageIndex      =   2
            Style           =   1
         EndProperty
         BeginProperty Button4 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Caption         =   "前景色"
            Key             =   "FPal"
            ImageIndex      =   3
         EndProperty
         BeginProperty Button5 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Caption         =   "背景色"
            Key             =   "BPal"
            ImageIndex      =   3
         EndProperty
         BeginProperty Button6 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Style           =   3
         EndProperty
         BeginProperty Button7 {66833FEA-8583-11D1-B16A-00C0F0283628}
            Caption         =   "退出"
            Key             =   "Exit"
            ImageIndex      =   4
         EndProperty
      EndProperty
      BorderStyle     =   1
      Begin VB.PictureBox picBack
         Appearance      =   0  'Flat
         BackColor       =   &H80000005&
         ForeColor       =   &H80000008&
         Height          =   375
         Left            =   4200
         ScaleHeight     =   345
         ScaleWidth      =   465
         TabIndex        =   3
         Top             =   120
         Width           =   495
      End
      Begin VB.PictureBox picFore
         Appearance      =   0  'Flat
         BackColor       =   &H00FFFFFF&
         ForeColor       =   &H80000008&
         Height          =   375
         Left            =   3600
         ScaleHeight     =   345
         ScaleWidth      =   465
         TabIndex        =   2
         Top             =   120
         Width           =   495
      End
   End
   Begin VB.PictureBox picPat
      Align           =   2  'Align Bottom
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   2895
      Left            =   0
      ScaleHeight     =   2865
      ScaleWidth      =   5250
      TabIndex        =   0
      Top             =   780
      Width           =   5280
   End
End
Attribute VB_Name = "frmpat"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim InDrawModeL As Boolean, InDrawModeR As Boolean, FirstButton As Integer

Private Sub Form_Resize()
    picPat.Height = Me.Height - tbTools.Height - 400
End Sub

Private Sub picPat_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If tbTools.Buttons(3).Value Then
        If Button And vbLeftButton Then
            InDrawModeL = True
            If Not InDrawModeR Then FirstButton = 1
            picFore.BorderStyle = 0
            picPat.PSet (X, Y), picFore.BackColor
        End If
        If Button And vbRightButton Then
            InDrawModeR = True
            If Not InDrawModeL Then FirstButton = 2
            picBack.BorderStyle = 0
            picPat.PSet (X, Y), picBack.BackColor
        End If
    End If
End Sub

Private Sub picPat_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If InDrawModeL And InDrawModeR Then
        picPat.Line -(X, Y), picFore.BackColor Or picBack.BackColor
    End If
    If FirstButton = 1 Then
        If InDrawModeR Then
            picPat.Line -(X, Y), picBack.BackColor
        End If
        If InDrawModeL Then
            picPat.Line -(X, Y), picFore.BackColor
        End If
    ElseIf FirstButton = 2 Then
        If InDrawModeL Then
            picPat.Line -(X, Y), picFore.BackColor
        End If
        If InDrawModeR Then
            picPat.Line -(X, Y), picBack.BackColor
        End If
    End If
End Sub

Private Sub picPat_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Button And vbLeftButton Then
        InDrawModeL = False
        picFore.BorderStyle = 1
        If InDrawModeR Then FirstButton = 2
    End If
    If Button And vbRightButton Then
        InDrawModeR = False
        picBack.BorderStyle = 1
        If InDrawModeL Then FirstButton = 1
    End If
End Sub

Private Sub tbTools_ButtonClick(ByVal Button As MSComctlLib.Button)
    Select Case Button.Key
    Case "New"
        picPat.Cls
    Case "Pixel"

    Case "FPal"
        cdColorPal.ShowColor
        If Not cdColorPal.CancelError Then
            picFore.BackColor = cdColorPal.Color
        End If
    Case "BPal"
        cdColorPal.ShowColor
        If Not cdColorPal.CancelError Then
            picBack.BackColor = cdColorPal.Color
        End If

    Case "Exit"
        End
    End Select
End Sub

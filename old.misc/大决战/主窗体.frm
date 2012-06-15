VERSION 5.00
Begin VB.Form 主窗体
   Caption         =   "Form1"
   ClientHeight    =   4785
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6810
   LinkTopic       =   "Form1"
   ScaleHeight     =   319
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   454
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   465
      Left            =   4620
      TabIndex        =   3
      Top             =   3855
      Width           =   1635
   End
   Begin VB.PictureBox 格子切片
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   990
      Left            =   105
      Picture         =   "主窗体.frx":0000
      ScaleHeight     =   960
      ScaleWidth      =   960
      TabIndex        =   1
      Top             =   3705
      Visible         =   0   'False
      Width           =   990
   End
   Begin VB.PictureBox 场景
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   2400
      Left            =   1065
      ScaleHeight     =   160
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   320
      TabIndex        =   0
      Top             =   1080
      Width           =   4800
   End
   Begin VB.Label Label1
      Caption         =   "Label1"
      Height          =   465
      Left            =   1350
      TabIndex        =   2
      Top             =   3795
      Width           =   1965
   End
End
Attribute VB_Name = "主窗体"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Const 锁定边界大小 As Integer = 5

Public Sub 刷新()
        场景.Cls
        主地图.绘制地图
        场景.Refresh
        Label1 = 主地图.视区左边界 & "," & 主地图.视区上边界
End Sub

Private Sub 锁定场景边界(ByVal X As Single, ByVal Y As Single)
        Dim wi As WINDOWINFO
        Dim nX As Single, nY As Single          ' 新鼠标位置 [像素]
        Dim oX As Single, oY As Single          ' 旧鼠标位置 [像素]
        GetWindowInfo Me.hWnd, wi
        oX = wi.rcClient.Left + 场景.Left + X
        oY = wi.rcClient.Top + 场景.Top + Y
        nX = oX
        nY = oY
        If X < 锁定边界大小 Then
                nX = wi.rcClient.Left + 场景.Left + 锁定边界大小
                If 主地图.视区左边界 > 0 Then
                        主地图.视区左边界 = 主地图.视区左边界 - 1
                End If
        End If
        If X > 场景.Width - 锁定边界大小 Then
                nX = wi.rcClient.Left + 场景.Left + 场景.Width - 锁定边界大小
                If 主地图.视区左边界 + 主地图.视区宽度 < 主地图.宽度 Then
                        主地图.视区左边界 = 主地图.视区左边界 + 1
                End If
        End If
        If Y < 锁定边界大小 Then
                nY = wi.rcClient.Top + 场景.Top + 锁定边界大小
                If 主地图.视区上边界 > 0 Then
                        主地图.视区上边界 = 主地图.视区上边界 - 1
                End If
        End If
        If Y > 场景.Height - 锁定边界大小 Then
                nY = wi.rcClient.Top + 场景.Top + 场景.Height - 锁定边界大小
                If 主地图.视区上边界 + 主地图.视区高度 < 主地图.高度 Then
                        主地图.视区上边界 = 主地图.视区上边界 + 1
                End If
        End If
        If nX <> oX And nY <> oY Then
                SetCursorPos nX, nY
        ElseIf nX <> oX Then
                SetCursorPos nX, oY
        ElseIf nY <> oY Then
                SetCursorPos oX, nY
        Else
                Exit Sub
        End If
        刷新
End Sub

Private Sub Command1_Click()
        刷新
End Sub

Private Sub 场景_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
        锁定场景边界 X, Y
End Sub

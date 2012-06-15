VERSION 5.00
Begin VB.Form frmSet
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "设置"
   ClientHeight    =   960
   ClientLeft      =   150
   ClientTop       =   390
   ClientWidth     =   3765
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   960
   ScaleWidth      =   3765
   ShowInTaskbar   =   0   'False
   Begin VB.TextBox tProjectName
      Appearance      =   0  'Flat
      Height          =   285
      Left            =   120
      TabIndex        =   0
      Text            =   "-"
      Top             =   0
      Width           =   3555
   End
   Begin VB.ComboBox lstInt
      Height          =   315
      ItemData        =   "frmSet.frx":0000
      Left            =   120
      List            =   "frmSet.frx":001F
      Style           =   2  'Dropdown List
      TabIndex        =   1
      Top             =   300
      Width           =   1425
   End
   Begin VB.CommandButton cCalc
      Caption         =   "C"
      Height          =   300
      Left            =   3375
      TabIndex        =   7
      Top             =   615
      Width           =   300
   End
   Begin VB.CommandButton cCurrent
      Caption         =   "C"
      Height          =   330
      Left            =   3375
      TabIndex        =   4
      Top             =   285
      Width           =   300
   End
   Begin VB.TextBox tAfter
      Appearance      =   0  'Flat
      Height          =   315
      Left            =   1890
      TabIndex        =   6
      Text            =   "-"
      Top             =   600
      Width           =   1485
   End
   Begin VB.CommandButton cAfter
      Caption         =   "+"
      Height          =   315
      Left            =   1545
      TabIndex        =   5
      Top             =   600
      Width           =   345
   End
   Begin VB.TextBox tToTime
      Appearance      =   0  'Flat
      Height          =   330
      Left            =   1890
      TabIndex        =   3
      Text            =   "-"
      Top             =   285
      Width           =   1485
   End
   Begin VB.CommandButton cToTime
      Caption         =   "-->"
      Height          =   315
      Left            =   1545
      TabIndex        =   2
      Top             =   285
      Width           =   345
   End
   Begin VB.Menu mPredefinedPeriod
      Caption         =   "预定义期限"
      Begin VB.Menu m60s
         Caption         =   "60秒"
      End
      Begin VB.Menu m5m
         Caption         =   "5分钟"
      End
      Begin VB.Menu m10m
         Caption         =   "10分钟"
      End
      Begin VB.Menu m30m
         Caption         =   "30分钟"
      End
      Begin VB.Menu m1h
         Caption         =   "1小时"
      End
      Begin VB.Menu m1h2
         Caption         =   "1.5小时"
      End
      Begin VB.Menu m2h
         Caption         =   "2小时"
      End
      Begin VB.Menu m3h
         Caption         =   "3小时"
      End
      Begin VB.Menu m5h
         Caption         =   "5小时"
      End
      Begin VB.Menu m1d
         Caption         =   "1天"
      End
      Begin VB.Menu m2d
         Caption         =   "2天"
      End
      Begin VB.Menu m3d
         Caption         =   "3天"
      End
      Begin VB.Menu m1w
         Caption         =   "1周"
      End
      Begin VB.Menu m2w
         Caption         =   "2周"
      End
      Begin VB.Menu m30d
         Caption         =   "1月"
      End
      Begin VB.Menu m1y
         Caption         =   "1年"
      End
   End
   Begin VB.Menu mPredefinedTime
      Caption         =   "预定义截止时间"
      Begin VB.Menu mTo8h
         Caption         =   "8:00 AM"
      End
      Begin VB.Menu mTo9h
         Caption         =   "9:00 AM"
      End
      Begin VB.Menu mTo12h
         Caption         =   "12:00 AM"
      End
      Begin VB.Menu mTo18h
         Caption         =   "18:00 PM"
      End
      Begin VB.Menu mTo20h
         Caption         =   "20:00 PM"
      End
      Begin VB.Menu mTo21h
         Caption         =   "21:00 PM"
      End
      Begin VB.Menu mTo22h
         Caption         =   "22:00 PM"
      End
      Begin VB.Menu mTo24h
         Caption         =   "0:00 PM"
      End
      Begin VB.Menu mToSaturday
         Caption         =   "星期六"
      End
      Begin VB.Menu mToSunday
         Caption         =   "星期日"
      End
      Begin VB.Menu mToMonthEnd
         Caption         =   "到月底"
      End
      Begin VB.Menu mToYearEnd
         Caption         =   "到年底"
      End
   End
End
Attribute VB_Name = "frmSet"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Const iss = "yyyy,1;m,1;d,1;h,3;h,1;n,15;h,1;n,1;s,1"

Private Sub cAfter_Click()
        Dim ds, di, dv
        ds = Split(tAfter, " ")
        di = "s"
        If UBound(ds) - LBound(ds) > 0 Then
                di = ds(1)
        End If
        dv = ds(0)

        On Error Resume Next
        tToTime = DateAdd(di, dv, Date + Time)
        cToTime_Click
End Sub

Private Sub cCalc_Click()
        tAfter = DateDiff("s", Time, CDate(tToTime.Text))
End Sub

Private Sub cCurrent_Click()
        tToTime = Time
End Sub

Private Sub cToTime_Click()
        On Error Resume Next
        frmMain.To_Time = CDate(tToTime.Text)
End Sub

Private Sub Form_Activate()
        tProjectName = frmMain.lastappname
End Sub

Private Sub Form_DblClick()
        tProjectName = Trim(tProjectName)
        If tProjectName = "" Then tProjectName = "Noname project # " & Date + Time
        frmMain.lastappname = tProjectName
        frmMain.l.ToolTipText = tProjectName
        Me.Hide
End Sub

Private Sub Form_Load()
        lstInt.ListIndex = 8
End Sub

Private Sub lstInt_Click()
        Dim i, s
        i = lstInt.ListIndex
        s = Split(iss, ";")(i)
        frmMain.cIntFormat = Split(s, ",")(0)
        frmMain.cIntK = Split(s, ",")(1)
End Sub

Private Sub lstInt_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then tToTime.SetFocus
End Sub

Private Sub m10m_Click()
        tAfter = "10 n"
End Sub

Private Sub m1d_Click()
        tAfter = "1 d"
End Sub

Private Sub m1h_Click()
        tAfter = "1 h"
End Sub

Private Sub m1h2_Click()
        tAfter = "90 n"
End Sub

Private Sub m1w_Click()
        tAfter = "1 ww"
End Sub

Private Sub m1y_Click()
        tAfter = "1 yyyy"
End Sub

Private Sub m2d_Click()
        tAfter = "2 d"
End Sub

Private Sub m2h_Click()
        tAfter = "2 h"
End Sub

Private Sub m2w_Click()
        tAfter = "2 ww"
End Sub

Private Sub m30d_Click()
        tAfter = "1 m"
End Sub

Private Sub m30m_Click()
        tAfter = "30 n"
End Sub

Private Sub m3d_Click()
        tAfter = "3 d"
End Sub

Private Sub m3h_Click()
        tAfter = "3 h"
End Sub

Private Sub m5h_Click()
        tAfter = "5 h"
End Sub

Private Sub m5m_Click()
        tAfter = "5 n"
End Sub

Private Sub m60s_Click()
        tAfter = "60 s"
End Sub

Private Sub mTo12h_Click()
        tToTime = DateAdd("h", 12, Date)
End Sub

Private Sub mTo18h_Click()
        tToTime = DateAdd("h", 18, Date)
End Sub

Private Sub mTo20h_Click()
        tToTime = DateAdd("h", 20, Date)
End Sub

Private Sub mTo21h_Click()
        tToTime = DateAdd("h", 21, Date)
End Sub

Private Sub mTo22h_Click()
        tToTime = DateAdd("h", 22, Date)
End Sub

Private Sub mTo24h_Click()
        tToTime = DateAdd("h", 24, Date)
End Sub

Private Sub mTo8h_Click()
        tToTime = DateAdd("h", 8, Date)
End Sub

Private Sub mTo9h_Click()
        tToTime = DateAdd("h", 9, Date)
End Sub

Private Sub mToMonthEnd_Click()
        tToTime = DateAdd("d", -1, _
                DateSerial(Year(Date), Month(Date) + 1, 1))
End Sub

Private Sub mToSaturday_Click()
        Dim days
        days = vbSaturday - Weekday(Date, vbSunday)
        tToTime = DateAdd("d", days, Date)
End Sub

Private Sub mToSunday_Click()
        Dim days
        days = vbSunday + 7 - Weekday(Date, vbSunday)
        days = (days - 1) Mod 7 + 1
        tToTime = DateAdd("d", days, Date)
End Sub

Private Sub mToYearEnd_Click()
        tToTime = DateAdd("d", -1, _
                DateSerial(Year(Date) + 1, 1, 1))
End Sub

Private Sub tAfter_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                cAfter_Click
                tProjectName.SetFocus
        End If
End Sub

Private Sub tAfter_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
        If Button And vbLeftButton Then
                PopupMenu mPredefinedPeriod
        End If
End Sub

Private Sub tProjectName_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then lstInt.SetFocus
End Sub

Private Sub tToTime_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                cCalc_Click
                cToTime_Click
                tAfter.SetFocus
        End If
End Sub

Private Sub tToTime_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
        If Button And vbLeftButton Then
                PopupMenu mPredefinedTime
        End If
End Sub

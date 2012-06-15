VERSION 5.00
Begin VB.Form frmSet
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Settings"
   ClientHeight    =   930
   ClientLeft      =   150
   ClientTop       =   105
   ClientWidth     =   3570
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   930
   ScaleWidth      =   3570
   ShowInTaskbar   =   0   'False
   Begin VB.CheckBox cAfter
      Caption         =   "R"
      Height          =   315
      Left            =   1440
      Style           =   1  'Graphical
      TabIndex        =   6
      ToolTipText     =   "到指定时限以及是否重复"
      Top             =   600
      Width           =   345
   End
   Begin VB.TextBox tInt
      Appearance      =   0  'Flat
      Height          =   315
      Left            =   15
      TabIndex        =   2
      Text            =   "-"
      ToolTipText     =   "详细显示单位"
      Top             =   600
      Width           =   1425
   End
   Begin VB.TextBox tProjectName
      Appearance      =   0  'Flat
      Height          =   285
      Left            =   15
      TabIndex        =   0
      Text            =   "-"
      ToolTipText     =   "工程名称"
      Top             =   0
      Width           =   3555
   End
   Begin VB.ComboBox lstInt
      Height          =   315
      ItemData        =   "frmSet.frx":0000
      Left            =   15
      List            =   "frmSet.frx":001F
      Style           =   2  'Dropdown List
      TabIndex        =   1
      ToolTipText     =   "显示单位"
      Top             =   300
      Width           =   1425
   End
   Begin VB.CommandButton cCalc
      Caption         =   "C"
      Height          =   300
      Left            =   3270
      TabIndex        =   8
      ToolTipText     =   "计算离目标时间剩余时间"
      Top             =   615
      Width           =   300
   End
   Begin VB.CommandButton cCurrent
      Caption         =   "C"
      Height          =   330
      Left            =   3270
      TabIndex        =   5
      ToolTipText     =   "取当前时间"
      Top             =   285
      Width           =   300
   End
   Begin VB.TextBox tAfter
      Appearance      =   0  'Flat
      Height          =   315
      Left            =   1785
      TabIndex        =   7
      Text            =   "-"
      ToolTipText     =   "目标时限"
      Top             =   600
      Width           =   1485
   End
   Begin VB.TextBox tToTime
      Appearance      =   0  'Flat
      Height          =   330
      Left            =   1785
      TabIndex        =   4
      Text            =   "-"
      ToolTipText     =   "目标时间"
      Top             =   285
      Width           =   1485
   End
   Begin VB.CommandButton cToTime
      Caption         =   "->"
      Height          =   315
      Left            =   1440
      TabIndex        =   3
      ToolTipText     =   "到指定时间"
      Top             =   285
      Width           =   345
   End
   Begin VB.Menu mPredefinedPeriod
      Caption         =   "Predefined period"
      Visible         =   0   'False
      Begin VB.Menu m60s
         Caption         =   "60s"
      End
      Begin VB.Menu m5m
         Caption         =   "5'"
      End
      Begin VB.Menu m10m
         Caption         =   "10'"
      End
      Begin VB.Menu m30m
         Caption         =   "30'"
      End
      Begin VB.Menu m1h
         Caption         =   "1 hour"
      End
      Begin VB.Menu m1h2
         Caption         =   "1.5 hours"
      End
      Begin VB.Menu m2h
         Caption         =   "2 hours"
      End
      Begin VB.Menu m3h
         Caption         =   "3 hours"
      End
      Begin VB.Menu m5h
         Caption         =   "5 hours"
      End
      Begin VB.Menu m1d
         Caption         =   "1 day"
      End
      Begin VB.Menu m2d
         Caption         =   "2 days"
      End
      Begin VB.Menu m3d
         Caption         =   "3 days"
      End
      Begin VB.Menu m1w
         Caption         =   "1 week"
      End
      Begin VB.Menu m2w
         Caption         =   "2 weeks"
      End
      Begin VB.Menu m30d
         Caption         =   "1 month"
      End
      Begin VB.Menu m1y
         Caption         =   "1 year"
      End
   End
   Begin VB.Menu mPredefinedTime
      Caption         =   "Predefined time"
      Visible         =   0   'False
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
         Caption         =   "Saturday"
      End
      Begin VB.Menu mToSunday
         Caption         =   "Sunday"
      End
      Begin VB.Menu mToMonthEnd
         Caption         =   "The End of Month"
      End
      Begin VB.Menu mToYearEnd
         Caption         =   "The End of Year"
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

Public Sub SetInt()
        Dim ss
        Dim tf As String, tk As Double
        ss = Split(tInt, ",")
        tf = ss(0)
        If (UBound(ss) > 0) Then tk = ss(1) Else tk = 1
        frmMain.cIntFormat = tf
        frmMain.cIntK = tk
End Sub

Public Sub cAfter_Click()
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

Public Sub cCalc_Click()
        tAfter = DateDiff("s", Date + Time, CDate(tToTime.Text))
        cAfter_Click
End Sub

Public Sub cCurrent_Click()
        tToTime = Date + Time
        cToTime_Click
End Sub

Public Sub cToTime_Click()
        On Error Resume Next
        frmMain.To_Time = CDate(tToTime.Text)
        frmMain.bMsged = False
End Sub

Public Sub Form_Activate()
        tProjectName = frmMain.lastappname
End Sub

Public Sub Form_DblClick()
        tProjectName = Trim(tProjectName)
        If tProjectName = "" Then tProjectName = "Noname project # " & Date + Time
        frmMain.lastappname = tProjectName
        frmMain.l.ToolTipText = tProjectName
        SetInt
        Me.Hide
End Sub

Public Sub Form_Load()
        lstInt.ListIndex = 8
End Sub

Private Sub Form_Unload(Cancel As Integer)
        Cancel = True
        Me.Hide
End Sub

Public Sub lstInt_Click()
        tInt = Split(iss, ";")(lstInt.ListIndex)
        SetInt
End Sub

Public Sub lstInt_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                KeyAscii = 0
                tInt.SetFocus
        End If
End Sub

Public Sub m10m_Click()
        tAfter = "10 n"
End Sub

Public Sub m1d_Click()
        tAfter = "1 d"
End Sub

Public Sub m1h_Click()
        tAfter = "1 h"
End Sub

Public Sub m1h2_Click()
        tAfter = "90 n"
End Sub

Public Sub m1w_Click()
        tAfter = "1 ww"
End Sub

Public Sub m1y_Click()
        tAfter = "1 yyyy"
End Sub

Public Sub m2d_Click()
        tAfter = "2 d"
End Sub

Public Sub m2h_Click()
        tAfter = "2 h"
End Sub

Public Sub m2w_Click()
        tAfter = "2 ww"
End Sub

Public Sub m30d_Click()
        tAfter = "1 m"
End Sub

Public Sub m30m_Click()
        tAfter = "30 n"
End Sub

Public Sub m3d_Click()
        tAfter = "3 d"
End Sub

Public Sub m3h_Click()
        tAfter = "3 h"
End Sub

Public Sub m5h_Click()
        tAfter = "5 h"
End Sub

Public Sub m5m_Click()
        tAfter = "5 n"
End Sub

Public Sub m60s_Click()
        tAfter = "60 s"
End Sub

Public Sub mTo12h_Click()
        tToTime = DateAdd("h", 12, Date)
End Sub

Public Sub mTo18h_Click()
        tToTime = DateAdd("h", 18, Date)
End Sub

Public Sub mTo20h_Click()
        tToTime = DateAdd("h", 20, Date)
End Sub

Public Sub mTo21h_Click()
        tToTime = DateAdd("h", 21, Date)
End Sub

Public Sub mTo22h_Click()
        tToTime = DateAdd("h", 22, Date)
End Sub

Public Sub mTo24h_Click()
        tToTime = DateAdd("h", 24, Date)
End Sub

Public Sub mTo8h_Click()
        tToTime = DateAdd("h", 8, Date)
End Sub

Public Sub mTo9h_Click()
        tToTime = DateAdd("h", 9, Date)
End Sub

Public Sub mToMonthEnd_Click()
        tToTime = DateAdd("d", -1, _
                DateSerial(Year(Date), Month(Date) + 1, 1))
End Sub

Public Sub mToSaturday_Click()
        Dim days
        days = vbSaturday - Weekday(Date, vbSunday)
        tToTime = DateAdd("d", days, Date)
End Sub

Public Sub mToSunday_Click()
        Dim days
        days = vbSunday + 7 - Weekday(Date, vbSunday)
        days = (days - 1) Mod 7 + 1
        tToTime = DateAdd("d", days, Date)
End Sub

Public Sub mToYearEnd_Click()
        tToTime = DateAdd("d", -1, _
                DateSerial(Year(Date) + 1, 1, 1))
End Sub

Public Sub tAfter_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                KeyAscii = 0
                cAfter_Click
                tProjectName.SetFocus
        End If
End Sub

Public Sub tAfter_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
        If Button And vbLeftButton Then
                PopupMenu mPredefinedPeriod
        End If
End Sub

Public Sub tInt_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                KeyAscii = 0
                SetInt
                tToTime.SetFocus
        End If
End Sub

Public Sub tProjectName_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                KeyAscii = 0
                lstInt.SetFocus
        End If
End Sub

Public Sub tToTime_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                KeyAscii = 0
                cCalc_Click
                cToTime_Click
                tAfter.SetFocus
        End If
End Sub

Public Sub tToTime_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
        If Button And vbLeftButton Then
                PopupMenu mPredefinedTime
        End If
End Sub

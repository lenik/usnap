VERSION 5.00
Begin VB.Form frmMain
   Appearance      =   0  'Flat
   BackColor       =   &H00000000&
   BorderStyle     =   0  'None
   Caption         =   "Left Time"
   ClientHeight    =   285
   ClientLeft      =   150
   ClientTop       =   435
   ClientWidth     =   1680
   ControlBox      =   0   'False
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   285
   ScaleWidth      =   1680
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  '所有者中心
   Begin VB.Timer t
      Interval        =   250
      Left            =   480
      Top             =   45
   End
   Begin VB.Label l
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "00"
      BeginProperty Font
         Name            =   "Times New Roman"
         Size            =   24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   540
      Left            =   0
      TabIndex        =   0
      ToolTipText     =   "双击退出,左右键调整大小"
      Top             =   0
      Width           =   480
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public To_Time
Public cIntFormat
Public cIntK As Double
Public d_x, d_y

Public app_name
Public lastappname

Public bMsged As Boolean

Public Sub quit()
        SaveSetting "LeftTime", "_Global", "LastAppName", lastappname
        SaveSetting "LeftTime", "_Recent", lastappname, Date + Time

        SaveSetting app_name, "Options", "To_Time", To_Time
        SaveSetting app_name, "Options", "Repeat", frmSet.cAfter.Value
        SaveSetting app_name, "Options", "cIntFormat", cIntFormat
        SaveSetting app_name, "Options", "cIntK", cIntK
        SaveSetting app_name, "frmSet", "lstInt", frmSet.lstInt.ListIndex
        SaveSetting app_name, "frmSet", "tToTime", frmSet.tToTime
        SaveSetting app_name, "frmSet", "tAfter", frmSet.tAfter
        SaveSetting app_name, "Options", "FontSize", l.FontSize
        SaveSetting app_name, "Options", "Left", Left
        SaveSetting app_name, "Options", "Top", Top
        End
End Sub

Private Sub Form_Activate()
        Dim ll, tt
        ll = GetSetting(app_name, "Options", "Left", -1000)
        tt = GetSetting(app_name, "Options", "Top", -1000)
        If ll > -1000 And tt > -1000 Then
                Left = ll
                Top = tt
        End If
End Sub

Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
        If KeyCode = 37 Then
                If l.FontSize > 3 Then l.FontSize = l.FontSize - 1
        ElseIf KeyCode = 39 Then
                If l.FontSize < 1000 Then l.FontSize = l.FontSize + 1
        Else
                Exit Sub
        End If
        l_Change
End Sub

Private Sub Form_Load()
        Load frmSet

        app_name = "LeftTime\" & lastappname

        To_Time = CDate(GetSetting(app_name, "Options", "To_Time", Date + Time + CDate("0:1:0")))
        cIntFormat = GetSetting(app_name, "Options", "cIntFormat", "s")
        cIntK = GetSetting(app_name, "Options", "cIntK", 1)
        frmSet.lstInt.ListIndex = GetSetting(app_name, "frmSet", "lstInt", 8)
        frmSet.tToTime = GetSetting(app_name, "frmSet", "tToTime", DateAdd("s", 60, Date + Time))
        frmSet.tAfter = GetSetting(app_name, "frmSet", "tAfter", "60 s")
        frmSet.cAfter.Value = GetSetting(app_name, "Options", "Repeat", 0)
        l.FontSize = GetSetting(app_name, "Options", "FontSize", 32)
        SetTopMostWindow Me.hwnd, True
End Sub

Private Sub Form_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
        d_x = x
        d_y = y
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
        If Button And vbLeftButton Then
                Left = Left + x - d_x
                Top = Top + y - d_y
        End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
        quit
End Sub

Private Sub l_Change()
        If l.Width <> Me.Width Then
                Me.Width = l.Width
        End If
        If l.Height <> Me.Height Then
                Me.Height = l.Height
        End If
End Sub

Private Sub l_DblClick()
        quit
End Sub

Private Sub l_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
        If Button And vbLeftButton Then
                Form_MouseDown Button, Shift, x, y
        End If
        If Button And vbRightButton Then
                If Left + frmSet.Width > Screen.Width Then
                        frmSet.Left = Left - frmSet.Width
                ElseIf Left + Width + frmSet.Width < Screen.Width Then
                        frmSet.Left = Left + Width
                Else
                        frmSet.Left = Left
                End If
                If frmSet.Left <> Left Then
                        frmSet.Top = Top
                Else
                        frmSet.Top = Top + Height
                End If
                frmSet.Show 1
                bMsged = False
        End If
End Sub

Private Sub l_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
        Form_MouseMove Button, Shift, x, y
End Sub

Private Sub t_Timer()
        l = Int(DateDiff(cIntFormat, Date + Time, To_Time) / cIntK)
        If l < 0 Then
                If Not bMsged Then
                        MsgBox frmSet.tProjectName & " timeout.", vbOKOnly, frmSet.tProjectName
                        bMsged = True

                        If frmSet.cAfter.Value = 1 Then
                                frmSet.cAfter_Click
                                bMsged = False
                        End If
                End If
        End If
End Sub

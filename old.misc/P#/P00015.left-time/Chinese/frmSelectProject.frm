VERSION 5.00
Begin VB.Form frmSelectProject
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "新建/打开 时间工程"
   ClientHeight    =   3255
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5220
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3255
   ScaleWidth      =   5220
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin VB.ComboBox cboList
      Height          =   2325
      IMEMode         =   1  'ON
      Left            =   270
      Style           =   1  'Simple Combo
      TabIndex        =   0
      Text            =   "-"
      Top             =   720
      Width           =   4605
   End
   Begin VB.Label Label1
      Caption         =   "请在列表框种选择一个已经存在的时间工程，或者通过在下面的时间工程文本框中输入工程的名称以建立一项新的时间工程。"
      Height          =   660
      Left            =   285
      TabIndex        =   1
      Top             =   60
      Width           =   4605
   End
End
Attribute VB_Name = "frmSelectProject"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cboList_DblClick()
        If cboList.Text = "" Then cboList.Text = "未命名时间工程 # " & Date + Time
        frmMain.lastappname = cboList.Text
        frmMain.l.ToolTipText = frmMain.lastappname

        Me.Hide
End Sub

Private Sub cboList_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                KeyAscii = 0
                cboList_DblClick
        End If
End Sub

Private Sub Form_Load()
        Dim lastlist

        lastlist = GetAllSettings("LeftTime", "_Recent")

        cboList.Clear
        If Not IsEmpty(lastlist) Then
                Dim i
                For i = LBound(lastlist) To UBound(lastlist)
                        Dim ds, dt
                        ds = lastlist(i, 0)
                        dt = lastlist(i, 1)
                        If dt <> "" Then
                                dt = DateDiff("s", CDate(dt), Date + Time)
                        Else
                                dt = 0
                        End If

                        Dim j, insert_before As Boolean
                        insert_before = False
                        If dt <> 0 Then
                                For j = 0 To cboList.ListCount - 1
                                        If dt < cboList.ItemData(j) Then
                                                insert_before = True
                                                Exit For
                                        End If
                                Next
                        End If
                        If insert_before Then
                                cboList.AddItem ds, j
                                cboList.ItemData(j) = dt
                        Else
                                cboList.AddItem ds
                                cboList.ItemData(i) = dt
                        End If
                Next
        End If

        cboList.Text = GetSetting("LeftTime", "_Global", "LastAppName", "我的第一个时间项目")
End Sub

VERSION 5.00
Begin VB.Form frmSelectProject
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "New/Open LeftTime Project"
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
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.ComboBox cboList
      Height          =   2160
      Left            =   270
      Style           =   1  'Simple Combo
      TabIndex        =   0
      Text            =   "-"
      Top             =   720
      Width           =   4605
   End
   Begin VB.Label Label1
      Caption         =   "Select an existed project or, create a new project by entering the project name in the project name textbox: "
      Height          =   645
      Left            =   285
      TabIndex        =   1
      Top             =   135
      Width           =   4620
   End
End
Attribute VB_Name = "frmSelectProject"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cboList_DblClick()
        If cboList.Text = "" Then cboList.Text = "Noname project # " & Date + Time
        frmMain.lastappname = cboList.Text
        frmMain.l.ToolTipText = frmMain.lastappname & " : " & frmMain.l.ToolTipText

        Me.Hide
        frmMain.Show
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

        If Command <> "" Then
                cboList.Text = Command
        Else
                cboList.Text = GetSetting("LeftTime", "_Global", "LastAppName", "My First LeftTime Project")
        End If
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
        On Error GoTo x
        cboList_DblClick
        Exit Sub
x:
        Cancel = 1
End Sub

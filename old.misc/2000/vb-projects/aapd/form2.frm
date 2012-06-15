VERSION 5.00
Begin VB.Form frmMain
   Appearance      =   0  'Flat
   BackColor       =   &H00C0FFC0&
   Caption         =   "Anti-Ad.Popup Daemon"
   ClientHeight    =   1545
   ClientLeft      =   165
   ClientTop       =   735
   ClientWidth     =   3345
   Icon            =   "form2.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   1545
   ScaleWidth      =   3345
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox List1
      Appearance      =   0  'Flat
      BackColor       =   &H00C0FFC0&
      Height          =   1200
      Left            =   0
      MultiSelect     =   2  'Extended
      TabIndex        =   0
      Top             =   0
      Width           =   2955
   End
   Begin VB.Timer T
      Interval        =   1000
      Left            =   285
      Top             =   7485
   End
   Begin VB.Menu mAAPD
      Caption         =   "&AAPD"
      Begin VB.Menu mInterval
         Caption         =   "Set daemon smartness"
      End
      Begin VB.Menu mAutoStart
         Caption         =   "&Auto startup"
      End
      Begin VB.Menu mExit
         Caption         =   "E&xit"
         Shortcut        =   ^X
      End
      Begin VB.Menu mAbout
         Caption         =   "About"
      End
   End
   Begin VB.Menu mList
      Caption         =   "&List"
      Begin VB.Menu mInsert
         Caption         =   "Insert item"
         Shortcut        =   {F5}
      End
      Begin VB.Menu mDelete
         Caption         =   "Delete item"
         Shortcut        =   {F6}
      End
      Begin VB.Menu mImport
         Caption         =   "Import list"
         Shortcut        =   {F7}
      End
      Begin VB.Menu mExport
         Caption         =   "Export list"
         Shortcut        =   {F8}
      End
      Begin VB.Menu mInsertSelect
         Caption         =   "Select window to insert"
         Shortcut        =   {F9}
      End
   End
   Begin VB.Menu mStart
      Caption         =   "&Start"
      Enabled         =   0   'False
   End
   Begin VB.Menu mStop
      Caption         =   "S&top"
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()
        mAutoStart.Checked = GetSetting(App.EXEName, "set", "autostart", False)

        Dim nums, I
        nums = GetSetting(App.EXEName, "set", "lists", 0)
        For I = 0 To nums - 1
                List1.AddItem GetSetting(App.EXEName, "lists", Trim(I))
        Next
End Sub

Private Sub Form_Resize()
        Static IGNORE As Boolean

        If Me.WindowState = 0 Then
                List1.Width = ScaleWidth
                List1.Height = ScaleHeight
                DoEvents

                IGNORE = True
                AdjustClientRect Me, _
                        List1.Width, List1.Height, _
                        Me.ScaleMode, Me.ScaleMode
                DoEvents
                IGNORE = False
        ElseIf Me.WindowState = 1 Then
                ' minimize to tray

        End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
        SaveSetting App.EXEName, "set", "lists", List1.ListCount
        Dim I
        For I = 0 To List1.ListCount - 1
                SaveSetting App.EXEName, "lists", Trim(I), List1.List(I)
        Next

        End
End Sub

Private Sub List1_DblClick()
        Dim I
        I = InputBox("Edit selection:", "Edit", List1.Text)
        If Trim(I) <> "" Then
                List1.List(List1.ListIndex) = I
        End If
End Sub

Private Sub List1_KeyDown(KeyCode As Integer, Shift As Integer)
        Select Case KeyCode
        Case vbKeyInsert
                mInsert_Click
        Case vbKeyDelete
                mDelete_Click
        Case vbKeyBack
                If List1.ListIndex > 0 Then
                        Dim j
                        For j = 0 To List1.ListCount - 1
                                List1.Selected(j) = False
                        Next
                        List1.ListIndex = List1.ListIndex - 1
                        List1.Selected(List1.ListIndex) = True
                        mDelete_Click
                End If
        End Select
End Sub

Private Sub mAbout_Click()
        MsgBox "Anti-Ad.Popup Daemon  (version " & App.Major & "." & App.Minor & "." & App.Revision & ")" & vbNewLine & _
                vbNewLine & _
                "Written by ZAUJ.DanSei.G., 2002.10.2"
End Sub

Private Sub mAutoStart_Click()
        mAutoStart.Checked = Not mAutoStart.Checked
        SaveSetting App.EXEName, "set", "autostart", mAutoStart.Checked
End Sub

Private Sub mDelete_Click()
        Dim I, lasti
        For I = List1.ListCount - 1 To 0 Step -1
                If List1.Selected(I) Then
                        List1.RemoveItem I
                        lasti = I
                End If
        Next
        If List1.ListCount > 0 Then
                If lasti >= List1.ListCount Then lasti = List1.ListCount - 1
                List1.ListIndex = lasti
                List1.Selected(List1.ListIndex) = True
        End If
End Sub

Private Sub mExit_Click()
        End
End Sub

Private Sub mImport_Click()
        Dim fn, l
        On Error GoTo x
        fn = InputBox("Input filename to import:", "Import list")
        If Trim(fn) = "" Then Exit Sub
        Open fn For Input As #1
        While Not EOF(1)
                Line Input #1, l
                List1.AddItem l
        Wend
        Close #1
x:
End Sub

Private Sub mExport_Click()
        Dim fn, l, I
        On Error GoTo x
        fn = InputBox("Input filename to export:", "Export list")
        If Trim(fn) = "" Then Exit Sub
        Open fn For Output As #1
        For I = 0 To List1.ListCount - 1
                Print #1, List1.List(I)
        Next
        Close #1
x:
End Sub

Private Sub mInsert_Click()
        Dim I, S
        S = List1.ListIndex
        If S < 0 Then S = List1.ListCount
        I = InputBox("Item:", "insert item")
        If Trim(I) <> "" Then
                Dim j
                For j = 0 To List1.ListCount - 1
                        List1.Selected(j) = False
                Next
                List1.AddItem I, S
                List1.ListIndex = S
                List1.Selected(S) = True
        End If
End Sub

Private Sub mInsertSelect_Click()
        Set winscol = New Collection
        EnumWindows AddressOf EnumProc, 0
        Dim I, S
        I = frmsel.dosel
        If frmsel.canceled Then Exit Sub
        S = List1.ListIndex
        If S < 0 Then S = List1.ListCount
        If Trim(I) <> "" Then
                Dim j
                For j = 0 To List1.ListCount - 1
                        List1.Selected(j) = False
                Next
                List1.AddItem I, S
                List1.ListIndex = S
                List1.Selected(S) = True
        End If
End Sub

Private Sub mInterval_Click()
        Dim I As Long
        I = Val(InputBox("Input interval (ms):", "Set daemon smartness", "1000"))
        If I < 0 Then I = 0
        If I > 10000 Then I = 10000
        T.Interval = I
        SaveSetting App.EXEName, "set", "interval", T.Interval
End Sub

Public Sub ProcessWnd(ByVal hwnd As Long)
        'SendMessage hwnd, WM_QUIT, 0, 0

        If True Then

        'SendMessage hwnd, WM_DESTROY, 0, 0
        'DestroyWindow hwnd
        Dim pid As Long, tid As Long
        tid = GetWindowThreadProcessId(hwnd, pid)
        Dim hproc, hThread
        'hproc = OpenProcess(PROCESS_TERMINATE, 0, pid)
        hThread = OpenThread(THREAD_TERMINATE, 0, tid)
        'TerminateProcess hproc, 0
        TerminateThread hThread, 0
        CloseHandle hThread

        End If
End Sub

Private Sub mStart_Click()
        T.Enabled = True
        mStart.Enabled = False
        mStop.Enabled = True
End Sub

Private Sub mStop_Click()
        T.Enabled = False
        mStop.Enabled = False
        mStart.Enabled = True
End Sub

Private Sub T_Timer()
        Set winscol = New Collection
        EnumWindows AddressOf EnumProc, 1

        If List1.ListCount <= 0 Then Exit Sub

        Dim I, j
        For Each I In winscol
                Dim wint, hwnd
                hwnd = Split(I, ":", 2)(0)
                wint = Split(I, ":", 2)(1)
                For j = 0 To List1.ListCount - 1
                        Dim toDel, toDelLen
                        toDel = List1.List(j)
                        toDelLen = Len(toDel)
                        If toDelLen <= 0 Then Exit For

                        If Len(wint) >= toDelLen Then
                                I = Left(wint, toDelLen)
                                If LCase(I) = LCase(toDel) Then

                                        ProcessWnd hwnd
                                End If
                        End If
                Next
        Next
End Sub

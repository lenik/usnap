Attribute VB_Name = "modEnumWindows"
Option Explicit

Public Function wndproc(ByVal hWnd As Long, ByVal lParam As Long) As Long
    Dim cap As String * 1024
    Dim strlen As Long, wndtxt As String
    GetWindowText hWnd, cap, 1024
    strlen = InStr(cap, Chr(0)) - 1
    If strlen > 0 Then
        wndtxt = Left(cap, strlen)
        frmMain.lstWnd.AddItem hWnd & " " & Trim(cap)
    End If
    wndproc = 1
End Function

Public Sub sendstring(ByVal hWnd As Long, ByVal str As String)
    Dim c As String
    Dim i As Long, l As Long
    Dim ret As Long
    l = Len(str)
    ShowWindow hWnd, SW_SHOW
    UpdateWindow hWnd
    SendMessage hWnd, WM_SETFOCUS, 0, 0
    Dim buf As String * 128
    SendMessage hWnd, EM_SETSEL, 4, 11
    For i = 1 To l
        c = Mid(str, i, 1)
        'c = Int(Rnd * 256)
        ret = SendMessage(hWnd, WM_CHAR, Asc(c), 1 + &H60000)
    Next
End Sub

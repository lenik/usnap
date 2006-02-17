Attribute VB_Name = "Typedefs"
Option Explicit

Public HwndToFilter As New Collection

Public LW As New LowXRuntime.Window

Public Function FilterForward(ByVal hWnd As Long, ByVal Message As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
    Dim ef As EventFilter
    On Error GoTo NotExist
    Set ef = HwndToFilter(CStr(hWnd))
    FilterForward = ef.FilterProc(hWnd, Message, wParam, lParam)
    Exit Function
NotExist:
    FilterForward = 0 ' call next proc
End Function

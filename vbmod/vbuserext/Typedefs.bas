Attribute VB_Name = "Typedefs"
Option Explicit

Public Type Position
    x0 As Double
    y0 As Double
    x1 As Double
    y1 As Double
End Type

Public HwndToFilter As New Collection

Public LC As New LowXRuntime.Component
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

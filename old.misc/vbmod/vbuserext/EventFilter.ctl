VERSION 5.00
Begin VB.UserControl EventFilter
   ClientHeight    =   720
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   735
   HasDC           =   0   'False
   InvisibleAtRuntime=   -1  'True
   Picture         =   "EventFilter.ctx":0000
   ScaleHeight     =   720
   ScaleMode       =   0  'User
   ScaleWidth      =   720
   ToolboxBitmap   =   "EventFilter.ctx":046E
   Windowless      =   -1  'True
End
Attribute VB_Name = "EventFilter"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Enum SizingAtConstants
    vbxSizingAtLeft = 1
    vbxSizingAtRight
    vbxSizingAtTop
    vbxSizingAtTopLeft
    vbxSizingAtTopRight
    vbxSizingAtBottom
    vbxSizingAtBottomLeft
    vbxSizingAtBottomRight
End Enum

Public Event Message(ByVal hWnd As Long, ByVal Message As Long, ByVal wParam As Long, ByVal lParam As Long, ByRef RetCode As Long)
Public Event Sizing(ByVal sizingAt As SizingAtConstants, ByRef Left As Single, ByRef Top As Single, ByRef Right As Single, ByRef Bottom As Single)

Private m_Filter As FILTER
Private LM As New LowXRuntime.Memory

Public Sub Hook()
    On Error GoTo AlreadyExist
    HwndToFilter.Add Me, CStr(UserControl.ContainerHwnd)
DoHook:
    LW.AddFilter UserControl.ContainerHwnd, AddressOf FilterForward, m_Filter
    Exit Sub

AlreadyExist:
    ' Unexpected
    HwndToFilter(CStr(UserControl.ContainerHwnd)) = Me
    GoTo DoHook
End Sub

Public Sub Unhook()
    LW.RemoveFilter m_Filter

    On Error Resume Next
    HwndToFilter.Remove CStr(UserControl.ContainerHwnd)
End Sub

Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    ' Is in design-time ?
    If Not Ambient.UserMode Then Exit Sub
    If DebugMode Then Exit Sub
    Hook
End Sub

Private Sub UserControl_Terminate()
    Unhook
End Sub

Private Sub UserControl_Resize()
    Width = 720
    Height = 720
End Sub

Function FilterProc(ByVal hWnd As Long, ByVal Message As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
    RaiseEvent Message(hWnd, Message, wParam, lParam, FilterProc)
    If FilterProc <> 0 Then Exit Function

    Select Case Message
    Case WM_SIZING
        Dim Rect As Rect
        Dim Left As Single
        Dim Top As Single
        Dim Right As Single
        Dim Bottom As Single

        LM.CopyBytes VarPtr(Rect), lParam, Len(Rect)
        Left = Rect.Left * Screen.TwipsPerPixelX
        Top = Rect.Top * Screen.TwipsPerPixelY
        Right = Rect.Right * Screen.TwipsPerPixelX
        Bottom = Rect.Bottom * Screen.TwipsPerPixelY

        RaiseEvent Sizing(wParam, Left, Top, Right, Bottom)

        Rect.Left = Left / Screen.TwipsPerPixelX
        Rect.Top = Top / Screen.TwipsPerPixelY
        Rect.Right = Right / Screen.TwipsPerPixelX
        Rect.Bottom = Bottom / Screen.TwipsPerPixelY
        LM.CopyBytes lParam, VarPtr(Rect), Len(Rect)
    Case Else
        ' ...
    End Select

    If FilterProc <> 0 Then Exit Function
    FilterProc = LW.NextFilter(m_Filter, hWnd, Message, wParam, lParam)
End Function

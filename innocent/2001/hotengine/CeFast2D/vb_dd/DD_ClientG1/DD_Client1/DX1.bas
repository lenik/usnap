Attribute VB_Name = "modDX1"
Option Explicit

Public dx As New DirectX7

Public lpdd As DirectDraw7
Public lpddsPrimary As DirectDrawSurface7
Public lpddsBack As DirectDrawSurface7
Public lpddc As DirectDrawClipper

Public Property Get MouseX() As Long
        Dim cp As POINTAPI
        GetCursorPos cp
        MouseX = cp.X
End Property
Public Property Get MouseY() As Long
        Dim cp As POINTAPI
        GetCursorPos cp
        MouseY = cp.Y
End Property

Public Property Let MouseX(ByVal nx As Long)
        SetCursorPos nx, MouseY
End Property
Public Property Let MouseY(ByVal ny As Long)
        SetCursorPos MouseX, ny
End Property

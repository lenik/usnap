VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "SimpleImage"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_Picture As IPictureDisp

Implements Renderable

Public Property Get picture() As IPictureDisp
    Set picture = m_Picture
End Property

Public Property Let picture(ByVal newval As IPictureDisp)
    Set m_Picture = newval
End Property

Private Function Renderable_Render(ByVal hDC As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal reserved As Long) As Variant
    If m_Picture Is Nothing Then Exit Function
    If m_Picture.Handle = 0 Then Exit Function
    m_Picture.Render hDC, x, y, cx, cy, _
                     0, 0, m_Picture.Width, m_Picture.Height, ByVal 0&
End Function

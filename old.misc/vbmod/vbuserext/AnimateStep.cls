VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "AnimateStep"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const FILENAME_NOTAVAIL         As String = "<NotAvailable>"

Public Enum AnimateEffectsConstants
    afxNone = 0
    afxHorizontalSlide
    afxVerticalSlide
End Enum

Private m_Filename As String
Private m_Effects As Long
Private m_Delay As Single
Private m_Next As AnimateStep

' Cached
' Private m_Dirty As Boolean
Private m_Picture As StdPicture

Implements Renderable

Event Changed()


Public Property Get Filename() As String
    Filename = m_Filename
End Property
Public Property Let Filename(ByVal newval As String)
    If newval = m_Filename Then Exit Property
    m_Filename = newval
    Set m_Picture = Nothing
    RaiseEvent Changed
End Property

Public Property Get Picture() As StdPicture
    If m_Picture Is Nothing Then
        If m_Filename <> FILENAME_NOTAVAIL Then
            Set m_Picture = LoadPicture(m_Filename)
        End If
    End If
    Set Picture = m_Picture
End Property
Public Property Set Picture(ByVal newval As StdPicture)
    m_Filename = FILENAME_NOTAVAIL
    Set m_Picture = newval
    RaiseEvent Changed
End Property

Public Property Get Effects() As Long
    Effects = m_Effects
End Property
Public Property Let Effects(ByVal newval As Long)
    If newval <> m_Effects Then
        m_Effects = newval
        RaiseEvent Changed
    End If
End Property

Public Property Get Delay() As Single
    Delay = m_Delay
End Property
Public Property Let Delay(ByVal newval As Single)
    m_Delay = newval
End Property

Public Property Get NextStep() As AnimateStep
    Set NextStep = m_Next
End Property
Public Property Set NextStep(ByVal newval As AnimateStep)
    Set m_Next = newval
End Property

Public Sub Reload()
    If m_Filename <> FILENAME_NOTAVAIL Then
        Set m_Picture = LoadPicture(m_Filename)
        RaiseEvent Changed
    End If
End Sub

Public Sub Render(ByVal hDC As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, Optional ByVal mode As Long = 0)
    If Picture Is Nothing Then Exit Sub
    With m_Picture
        .Render hDC, x, y, cx, cy, _
                0, 0, .Width, .Height, ByVal 0&
    End With
End Sub

Public Function CreateInfo(Optional ByVal delim As String = "|") As String
    CreateInfo = delim & m_Filename
    If m_Delay <> 0 Then CreateInfo = CreateInfo & delim & m_Delay
    If m_Effects <> 0 Then CreateInfo = CreateInfo & delim & m_Effects
    If Not m_Next Is Nothing Then CreateInfo = CreateInfo & m_Next.CreateInfo(delim)
End Function

Function ToString() As String
    ToString = m_Filename
    If m_Delay <> 0 Then ToString = ToString & " D:" & m_Delay
    If m_Effects <> 0 Then ToString = ToString & " FX:" & Hex(m_Effects)
    If Not m_Next Is Nothing Then ToString = ToString & " -> " & m_Next.ToString
End Function

Private Function IStringizable_ToString() As String
    IStringizable_ToString = ToString
End Function

Private Sub Renderable_Render(ByVal hDC As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, Optional ByVal mode As Long = 0&)
    Render hDC, x, y, cx, cy, mode
End Sub

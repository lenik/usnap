VERSION 5.00
Begin VB.UserControl Animate
   AutoRedraw      =   -1  'True
   BackStyle       =   0  'Transparent
   ClientHeight    =   750
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   750
   ScaleHeight     =   50
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   50
   Windowless      =   -1  'True
   Begin VB.Timer ClipTimer
      Interval        =   1
      Left            =   0
      Top             =   360
   End
   Begin VB.Image Img
      Height          =   315
      Left            =   0
      Stretch         =   -1  'True
      Top             =   0
      Width           =   315
   End
End
Attribute VB_Name = "Animate"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "VBUserExt::Animate"

Private Const MIN_WIDTH                 As Single = 15 ' Twips
Private Const MIN_HEIGHT                As Single = 15 ' Twips

Private Const DEFAULT_PACKEDSTEPS       As String = ","
Private Const DEFAULT_LOOPED            As Boolean = False
Private Const DEFAULT_SPEED             As Single = 1

Private Const SPEED_SCALE               As Single = 1000

' <delimiter> <step-path> [<delimiter> <step-delay> [<delimiter> <step-fx>]] [...]
Private m_PackedSteps As String
Private m_Looped As Boolean
Private m_FirstStep As AnimateStep
Private m_CurrentStep As AnimateStep
Private m_Shown As Boolean
Private m_Speed As Single               ' Scale delay by / Log(m_Speed)

Public Property Get PackedSteps() As String
    PackedSteps = m_PackedSteps
End Property
Public Property Let PackedSteps(ByVal newval As String)
    If newval <> m_PackedSteps Then
        'On Error GoTo ParseError
        Set m_FirstStep = CreateAnimateSteps(newval)
        Set m_CurrentStep = m_FirstStep
        m_PackedSteps = newval
        If Not m_CurrentStep Is Nothing Then
            Redraw
            Timeout m_CurrentStep.Delay
        End If
    End If
ParseError:
End Property

Public Property Get Steps() As AnimateStep
    Set Steps = m_FirstStep
End Property
Public Property Set Steps(ByVal newval As AnimateStep)
    Assert Not newval Is Nothing
    Set m_FirstStep = newval
    Set m_CurrentStep = m_FirstStep
    If Not m_CurrentStep Is Nothing Then
        Redraw
        Timeout m_CurrentStep.Delay
    End If
End Property

Public Property Get Looped() As Boolean
    Looped = m_Looped
End Property
Public Property Let Looped(ByVal newval As Boolean)
    m_Looped = newval
End Property

Public Property Get Speed() As Integer
    Speed = Log(1 / m_Speed) * SPEED_SCALE
End Property
Public Property Let Speed(ByVal newval As Integer)
    m_Speed = 1 / Exp(newval / SPEED_SCALE)
End Property

Public Property Get CurrentStep() As AnimateStep
    Set CurrentStep = m_CurrentStep
End Property

Private Sub Timeout(ByVal Delay As Single)
    ClipTimer.Interval = Delay * 1000 * m_Speed
    ClipTimer.Enabled = True
End Sub

Private Sub ClipTimer_Timer()
    ClipTimer.Enabled = False
    If Not m_CurrentStep Is Nothing Then
        NextStep
    End If
End Sub

Private Sub NextStep()
    If m_CurrentStep Is Nothing Then Exit Sub
    Set m_CurrentStep = m_CurrentStep.NextStep
    If m_CurrentStep Is Nothing And m_Looped Then
        Set m_CurrentStep = m_FirstStep
    End If
    If Not m_CurrentStep Is Nothing Then
        Redraw
        Timeout m_CurrentStep.Delay
    End If
End Sub

Private Sub Redraw()
    If Not m_Shown Then Exit Sub
    If m_CurrentStep Is Nothing Then Exit Sub
    Cls
    ' PaintPicture m_CurrentStep.Picture, 0, 0, ScaleWidth, ScaleHeight, _
                 , , , , vbMergeCopy
    Set Img.Picture = m_CurrentStep.Picture
    'm_CurrentStep.Render hDC, 0, 0, ScaleWidth, ScaleHeight, 0
    Refresh
End Sub

Private Sub UserControl_HitTest(x As Single, y As Single, HitResult As Integer)
    HitResult = vbHitResultHit
End Sub

Private Sub UserControl_Resize()
    If ScaleWidth < 0 Or Width < MIN_WIDTH Then Width = MIN_WIDTH
    If ScaleHeight < 0 Or Height < MIN_HEIGHT Then Height = MIN_HEIGHT
    Img.Width = ScaleWidth
    Img.Height = ScaleHeight
    Redraw
End Sub

Private Sub UserControl_Show()
    m_Shown = True
    Redraw
End Sub

Private Sub UserControl_InitProperties()
    m_Looped = DEFAULT_LOOPED
    m_Speed = DEFAULT_SPEED
    PackedSteps = DEFAULT_PACKEDSTEPS
End Sub

Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    m_Looped = PropBag.ReadProperty("Looped", DEFAULT_LOOPED)
    m_Speed = PropBag.ReadProperty("Speed", DEFAULT_SPEED)
    PackedSteps = PropBag.ReadProperty("PackedSteps", DEFAULT_PACKEDSTEPS)
End Sub

Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
    PropBag.WriteProperty "Looped", m_Looped, DEFAULT_LOOPED
    PropBag.WriteProperty "Speed", m_Speed, DEFAULT_SPEED
    PropBag.WriteProperty "PackedSteps", m_PackedSteps, DEFAULT_PACKEDSTEPS
End Sub

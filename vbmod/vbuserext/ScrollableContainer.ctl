VERSION 5.00
Begin VB.UserControl ScrollableContainer
   ClientHeight    =   2070
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   2415
   ControlContainer=   -1  'True
   ScaleHeight     =   2070
   ScaleWidth      =   2415
   ToolboxBitmap   =   "ScrollableContainer.ctx":0000
   Begin VB.HScrollBar hs
      Height          =   255
      Left            =   0
      TabIndex        =   1
      Top             =   1740
      Width           =   2115
   End
   Begin VB.VScrollBar vs
      Height          =   1755
      Left            =   2100
      TabIndex        =   0
      Top             =   0
      Width           =   255
   End
End
Attribute VB_Name = "ScrollableContainer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_DeltaX As Single
Private m_DeltaY As Single

Public Property Get SmallChange() As Integer
    SmallChange = hs.SmallChange
End Property
Public Property Let SmallChange(ByVal newval As Integer)
    hs.SmallChange = newval
    vs.SmallChange = newval
End Property

Public Property Get LargeChange() As Integer
    LargeChange = hs.LargeChange
End Property
Public Property Let LargeChange(ByVal newval As Integer)
    hs.LargeChange = newval
    vs.LargeChange = newval
End Property

Private Sub UserControl_Resize()
    hs.Top = ScaleHeight - hs.Height
    hs.Width = ScaleWidth - vs.Width
    vs.Left = ScaleWidth - vs.Width
    vs.Height = ScaleHeight - hs.Height
End Sub

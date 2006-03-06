VERSION 5.00
Begin VB.Form TestRender
   AutoRedraw      =   -1  'True
   Caption         =   "Form1"
   ClientHeight    =   4830
   ClientLeft      =   165
   ClientTop       =   855
   ClientWidth     =   7425
   LinkTopic       =   "Form1"
   ScaleHeight     =   4830
   ScaleWidth      =   7425
   StartUpPosition =   3  'Windows Default
   Begin VB.ComboBox opcode
      Height          =   315
      ItemData        =   "Test_Render.frx":0000
      Left            =   0
      List            =   "Test_Render.frx":007F
      Style           =   2  'Dropdown List
      TabIndex        =   4
      Top             =   0
      Width           =   2175
   End
   Begin VB.Label mark
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Pad left"
      ForeColor       =   &H80000008&
      Height          =   4755
      Index           =   0
      Left            =   540
      TabIndex        =   3
      Top             =   0
      Width           =   195
   End
   Begin VB.Label mark
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Pad right"
      ForeColor       =   &H80000008&
      Height          =   4755
      Index           =   1
      Left            =   6780
      TabIndex        =   2
      Top             =   0
      Width           =   195
   End
   Begin VB.Label mark
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Pad top"
      ForeColor       =   &H80000008&
      Height          =   195
      Index           =   2
      Left            =   0
      TabIndex        =   1
      Top             =   360
      Width           =   7815
   End
   Begin VB.Label mark
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Pad bottom"
      ForeColor       =   &H80000008&
      Height          =   195
      Index           =   3
      Left            =   0
      TabIndex        =   0
      Top             =   4140
      Width           =   7815
   End
   Begin VB.Menu mWindows
      Caption         =   "&windows"
      Begin VB.Menu mSrcpic
         Caption         =   "Source picture"
      End
   End
End
Attribute VB_Name = "TestRender"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Const MARK_LEFT = 0
Const MARK_RIGHT = 1
Const MARK_TOP = 2
Const MARK_BOTTOM = 3
Const MARK_BORDERLEFT = 4
Const MARK_BORDERRIGHT = 5
Const MARK_BORDERTOP = 6
Const MARK_BORDERBOTTOM = 7

Const VERYBIG = 1000000000#

Dim ox, oy
Dim ap As AnimateStep

Property Get MarkLeft() As Single
    MarkLeft = mark(MARK_LEFT).Left + mark(MARK_LEFT).Width
End Property
Property Let MarkLeft(ByVal newval As Single)
    mark(MARK_LEFT).Left = newval - mark(MARK_LEFT).Width
End Property
Property Get MarkRight() As Single
    MarkRight = mark(MARK_RIGHT).Left
End Property
Property Let MarkRight(ByVal newval As Single)
    mark(MARK_RIGHT).Left = newval
End Property
Property Get MarkTop() As Single
    MarkTop = mark(MARK_TOP).Top + mark(MARK_TOP).Height
End Property
Property Let MarkTop(ByVal newval As Single)
    mark(MARK_TOP).Top = newval - mark(MARK_TOP).Height
End Property
Property Get MarkBottom() As Single
    MarkBottom = mark(MARK_BOTTOM).Top
End Property
Property Let MarkBottom(ByVal newval As Single)
    mark(MARK_BOTTOM).Top = newval
End Property


Private Sub Form_Load()
    Set ap = CreateAnimateSteps( _
        "|C:\.lokaj\zbmis\mat\icons\Autoscalelayout.gif|1|C:\.lokaj\zbmis\mat\icons\Auxiliaryshape.gif|1|C:\.lokaj\zbmis\mat\icons\Controller.gif|1|C:\.lokaj\zbmis\mat\icons\Eventfilter.gif|1|C:\.lokaj\zbmis\mat\icons\Favoritebox.gif|1|C:\.lokaj\zbmis\mat\icons\ScrollableContainer.gif|1")
    SourcePicture.Show
    opcode.ListIndex = 0
End Sub

Private Sub Form_Resize()
    MarkLeft = ScaleX(10, vbPixels, ScaleMode)
    MarkTop = ScaleY(10, vbPixels, ScaleMode)
    MarkRight = Me.ScaleWidth - ScaleX(10, vbPixels, ScaleMode)
    MarkBottom = Me.ScaleHeight - ScaleY(10, vbPixels, ScaleMode)
End Sub

Private Sub mark_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    ox = X
    oy = Y
End Sub

Private Sub mark_MouseMove(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Button And vbLeftButton Then
        Dim dx, dy
        dx = X - ox
        dy = Y - oy
        Select Case Index
        Case MARK_LEFT:      dy = 0
        Case MARK_RIGHT:     dy = 0
        Case MARK_TOP:       dx = 0
        Case MARK_BOTTOM:    dx = 0
        End Select

        With mark(Index)
            .Left = .Left + dx
            .Top = .Top + dy
        End With
        Redraw
    End If
End Sub

Private Sub mSrcpic_Click()
    SourcePicture.Show
End Sub

Sub Redraw()
    If SourcePicture.p.Picture.Handle = 0 Then Exit Sub

    Dim tx, ty, tcx, tcy
    'Dim tx As Long, ty As Long, tcx As Long, tcy As Long
    'Dim sx As OLE_XPOS_HIMETRIC, sy As OLE_YPOS_HIMETRIC

    tx = ScaleX(MarkLeft, ScaleMode, vbPixels)
    ty = ScaleY(MarkTop, ScaleMode, vbPixels)
    tcx = ScaleX(MarkRight - MarkLeft, ScaleMode, vbPixels)
    tcy = ScaleY(MarkBottom - MarkTop, ScaleMode, vbPixels)

    Cls

    PaintPicture SourcePicture.p.Picture, MarkLeft, 0, MarkRight - MarkLeft, MarkTop, _
                 , , , , opcode.ItemData(opcode.ListIndex)

    PaintPicture ap.Picture, MarkLeft, MarkTop, MarkRight - MarkLeft, MarkBottom - MarkTop, _
                 , , , , opcode.ItemData(opcode.ListIndex)

    'With SourcePicture.p.Picture
    '    .Render Me.hDC, tx, ty, tcx, -tcy, _
    '        0, 0, .Width, .Height, ByVal 0&
    'End With

    Refresh
End Sub

Private Sub opcode_Click()
    Redraw
End Sub

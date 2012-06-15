VERSION 5.00
Object = "{79D5D6E9-10F5-4F16-AC63-C1A70BF8EA4C}#19.0#0"; "VBUserExt.ocx"
Begin VB.Form Form5
   Caption         =   "ScrollableContainer #2"
   ClientHeight    =   4905
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7995
   LinkTopic       =   "Form1"
   ScaleHeight     =   4905
   ScaleWidth      =   7995
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox cmdscontainer
      Height          =   315
      Left            =   2400
      ScaleHeight     =   255
      ScaleWidth      =   2535
      TabIndex        =   12
      Top             =   4440
      Width           =   2595
      Begin VB.CheckBox chkEditBorder
         Caption         =   "Edit &Border"
         Height          =   255
         Left            =   1380
         Style           =   1  'Graphical
         TabIndex        =   14
         Top             =   0
         Width           =   1035
      End
      Begin VB.CheckBox chkStatic
         Caption         =   "&StaticLayout"
         Height          =   255
         Left            =   120
         Style           =   1  'Graphical
         TabIndex        =   13
         Top             =   0
         Width           =   1155
      End
   End
   Begin VBUserExt.ScrollableContainer sc
      Height          =   3615
      Left            =   720
      TabIndex        =   0
      Top             =   540
      Width           =   6075
      _ExtentX        =   7329
      _ExtentY        =   2355
      StaticLayout    =   0   'False
      BorderLeft      =   0
      BorderTop       =   0
      Appearance      =   0
      BackColor       =   -2147483643
      BorderStyle     =   1
      Begin VB.CommandButton Test
         Caption         =   "Test"
         Height          =   795
         Index           =   0
         Left            =   360
         TabIndex        =   3
         Top             =   240
         Width           =   1155
      End
      Begin VB.CommandButton Test
         Caption         =   "Test"
         Height          =   795
         Index           =   1
         Left            =   1080
         TabIndex        =   2
         Top             =   1920
         Width           =   1155
      End
      Begin VB.CommandButton Test
         Caption         =   "Test"
         Height          =   795
         Index           =   2
         Left            =   2940
         TabIndex        =   1
         Top             =   780
         Width           =   1155
      End
   End
   Begin VB.Label mark
      Appearance      =   0  'Flat
      BackColor       =   &H00C0FFC0&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Border top"
      ForeColor       =   &H80000008&
      Height          =   195
      Index           =   6
      Left            =   0
      TabIndex        =   10
      Top             =   4440
      Width           =   7815
   End
   Begin VB.Label mark
      Appearance      =   0  'Flat
      BackColor       =   &H00C0FFC0&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Border bottom"
      ForeColor       =   &H80000008&
      Height          =   195
      Index           =   7
      Left            =   0
      TabIndex        =   11
      Top             =   120
      Width           =   7815
   End
   Begin VB.Label mark
      Appearance      =   0  'Flat
      BackColor       =   &H00C0FFC0&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Border right"
      ForeColor       =   &H80000008&
      Height          =   4755
      Index           =   5
      Left            =   240
      TabIndex        =   9
      Top             =   0
      Width           =   195
   End
   Begin VB.Label mark
      Appearance      =   0  'Flat
      BackColor       =   &H00C0FFC0&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Border left"
      ForeColor       =   &H80000008&
      Height          =   4755
      Index           =   4
      Left            =   7260
      TabIndex        =   8
      Top             =   0
      Width           =   195
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
      TabIndex        =   7
      Top             =   4140
      Width           =   7815
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
      TabIndex        =   6
      Top             =   360
      Width           =   7815
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
      TabIndex        =   5
      Top             =   0
      Width           =   195
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
      TabIndex        =   4
      Top             =   0
      Width           =   195
   End
End
Attribute VB_Name = "Form5"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Const MARK_PADLEFT = 0
Const MARK_PADRIGHT = 1
Const MARK_PADTOP = 2
Const MARK_PADBOTTOM = 3
Const MARK_BORDERLEFT = 4
Const MARK_BORDERRIGHT = 5
Const MARK_BORDERTOP = 6
Const MARK_BORDERBOTTOM = 7

Const VERYBIG = 1000000000#

Dim ox, oy

Private Sub chkEditBorder_Click()
    Dim b As Boolean
    b = chkEditBorder.Value = vbChecked

    mark(MARK_PADLEFT).Visible = Not b
    mark(MARK_PADRIGHT).Visible = Not b
    mark(MARK_PADTOP).Visible = Not b
    mark(MARK_PADBOTTOM).Visible = Not b
    mark(MARK_BORDERLEFT).Visible = b
    mark(MARK_BORDERRIGHT).Visible = b
    mark(MARK_BORDERTOP).Visible = b
    mark(MARK_BORDERBOTTOM).Visible = b

End Sub

Private Sub chkStatic_Click()
    sc.StaticLayout = chkStatic.Value = vbChecked
End Sub

Private Sub Form_Load()
    chkEditBorder_Click
End Sub

Private Sub Form_Resize()
    sc.Width = ScaleWidth - sc.Left * 2
    sc.Height = ScaleHeight - sc.Top * 2

    mark(MARK_PADLEFT).Height = ScaleHeight
    mark(MARK_PADRIGHT).Height = ScaleHeight
    mark(MARK_PADTOP).Width = ScaleWidth
    mark(MARK_PADBOTTOM).Width = ScaleWidth
    mark(MARK_BORDERLEFT).Height = ScaleHeight
    mark(MARK_BORDERRIGHT).Height = ScaleHeight
    mark(MARK_BORDERTOP).Width = ScaleWidth
    mark(MARK_BORDERBOTTOM).Width = ScaleWidth

    MarkPadLeft = sc.PadLeft
    MarkPadTop = sc.PadTop
    MarkPadRight = sc.PadRight
    MarkPadBottom = sc.PadBottom
    MarkBorderLeft = sc.borderLeft
    MarkBorderTop = sc.borderTop
    MarkBorderRight = sc.borderRight
    MarkBorderBottom = sc.borderBottom

    cmdscontainer.Left = (ScaleWidth - cmdscontainer.Width) / 2
    cmdscontainer.Top = ScaleHeight - cmdscontainer.Height - ScaleY(5, vbPixels, ScaleMode)
End Sub

Property Get MarkPadLeft() As Single
    MarkPadLeft = mark(MARK_PADLEFT).Left + mark(MARK_PADLEFT).Width - sc.Left
End Property
Property Let MarkPadLeft(ByVal newval As Single)
    mark(MARK_PADLEFT).Left = newval + sc.Left - mark(MARK_PADLEFT).Width
End Property
Property Get MarkPadRight() As Single
    MarkPadRight = mark(MARK_PADRIGHT).Left - (sc.Left + sc.Width)
End Property
Property Let MarkPadRight(ByVal newval As Single)
    mark(MARK_PADRIGHT).Left = newval + (sc.Left + sc.Width)
End Property
Property Get MarkPadTop() As Single
    MarkPadTop = mark(MARK_PADTOP).Top + mark(MARK_PADTOP).Height - sc.Top
End Property
Property Let MarkPadTop(ByVal newval As Single)
    mark(MARK_PADTOP).Top = newval + sc.Top - mark(MARK_PADTOP).Height
End Property
Property Get MarkPadBottom() As Single
    MarkPadBottom = mark(MARK_PADBOTTOM).Top - (sc.Top + sc.Height)
End Property
Property Let MarkPadBottom(ByVal newval As Single)
    mark(MARK_PADBOTTOM).Top = newval + (sc.Top + sc.Height)
End Property

Property Get MarkBorderLeft() As Single
    MarkBorderLeft = mark(MARK_BORDERLEFT).Left + mark(MARK_BORDERLEFT).Width - sc.Left
End Property
Property Let MarkBorderLeft(ByVal newval As Single)
    If newval > VERYBIG Then
        mark(MARK_BORDERLEFT).Left = ScaleWidth - mark(MARK_BORDERLEFT).Width / 2
    Else
        mark(MARK_BORDERLEFT).Left = newval + sc.Left - mark(MARK_BORDERLEFT).Width
    End If
End Property
Property Get MarkBorderRight() As Single
    MarkBorderRight = mark(MARK_BORDERRIGHT).Left - (sc.Left + sc.Width)
End Property
Property Let MarkBorderRight(ByVal newval As Single)
    If newval < -VERYBIG Then
        mark(MARK_BORDERRIGHT).Left = -mark(MARK_BORDERRIGHT).Width / 2
    Else
        mark(MARK_BORDERRIGHT).Left = newval + (sc.Left + sc.Width) - mark(MARK_BORDERRIGHT).Width
    End If
End Property
Property Get MarkBorderTop() As Single
    MarkBorderTop = mark(MARK_BORDERTOP).Top + mark(MARK_BORDERTOP).Height - sc.Top
End Property
Property Let MarkBorderTop(ByVal newval As Single)
    If newval > VERYBIG Then
        mark(MARK_BORDERTOP).Top = ScaleHeight - mark(MARK_BORDERTOP).Height / 2
    Else
        mark(MARK_BORDERTOP).Top = newval + sc.Top - mark(MARK_BORDERTOP).Height
    End If
End Property
Property Get MarkBorderBottom() As Single
    MarkBorderBottom = mark(MARK_BORDERBOTTOM).Top - (sc.Top + sc.Height)
End Property
Property Let MarkBorderBottom(ByVal newval As Single)
    If newval < -VERYBIG Then
        mark(MARK_BORDERBOTTOM).Top = -mark(MARK_BORDERBOTTOM).Height / 2
    Else
        mark(MARK_BORDERBOTTOM).Top = newval + (sc.Top + sc.Height) - mark(MARK_BORDERBOTTOM).Height
    End If
End Property

Sub ChangeMark()
    sc.PadLeft = MarkPadLeft
    sc.PadTop = MarkPadTop
    sc.PadRight = MarkPadRight
    sc.PadBottom = MarkPadBottom
    sc.borderLeft = MarkBorderLeft
    sc.borderTop = MarkBorderTop
    sc.borderRight = MarkBorderRight
    sc.borderBottom = MarkBorderBottom

    Caption = "Pad(" & MarkPadLeft & "," & MarkPadTop & "," & MarkPadRight & "," & MarkPadBottom & ") " & _
              "border(" & MarkBorderLeft & "," & MarkBorderTop & "," & MarkBorderRight & "," & MarkBorderBottom & ") "
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
        Case MARK_PADLEFT:      dy = 0
        Case MARK_PADRIGHT:     dy = 0
        Case MARK_PADTOP:       dx = 0
        Case MARK_PADBOTTOM:    dx = 0
        Case MARK_BORDERLEFT:   dy = 0
        Case MARK_BORDERRIGHT:  dy = 0
        Case MARK_BORDERTOP:    dx = 0
        Case MARK_BORDERBOTTOM: dx = 0
        End Select

        With mark(Index)
            .Left = .Left + dx
            .Top = .Top + dy
        End With
        ChangeMark
    End If
End Sub

Private Sub Test_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    ox = X
    oy = Y
End Sub

Private Sub Test_MouseMove(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Button And vbLeftButton Then
        With Test(Index)
            .Left = .Left + X - ox
            .Top = .Top + Y - oy
        End With
    End If
End Sub

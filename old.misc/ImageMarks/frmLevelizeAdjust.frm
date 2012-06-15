VERSION 5.00
Begin VB.Form frmLevelizeAdjust
   BorderStyle     =   4  'Fixed ToolWindow
   Caption         =   "Adjust levelize parameters"
   ClientHeight    =   1305
   ClientLeft      =   45
   ClientTop       =   315
   ClientWidth     =   5220
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1305
   ScaleWidth      =   5220
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmdOK
      Caption         =   "&OK"
      Default         =   -1  'True
      Height          =   315
      Left            =   3900
      TabIndex        =   4
      Top             =   840
      Width           =   975
   End
   Begin VB.HScrollBar step_offset
      Height          =   255
      LargeChange     =   5
      Left            =   1200
      Max             =   255
      Min             =   -255
      TabIndex        =   3
      Top             =   480
      Width           =   3315
   End
   Begin VB.HScrollBar step_size
      Height          =   255
      LargeChange     =   5
      Left            =   1200
      Max             =   21467
      TabIndex        =   1
      Top             =   180
      Value           =   1
      Width           =   3315
   End
   Begin VB.Label txt_step_size
      AutoSize        =   -1  'True
      Caption         =   "1"
      Height          =   195
      Left            =   4620
      TabIndex        =   6
      Top             =   240
      Width           =   90
   End
   Begin VB.Label txt_step_offset
      AutoSize        =   -1  'True
      Caption         =   "0"
      Height          =   195
      Left            =   4620
      TabIndex        =   5
      Top             =   540
      Width           =   90
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "S&tep offset: "
      Height          =   195
      Left            =   240
      TabIndex        =   2
      Top             =   540
      Width           =   855
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "&Step size: "
      Height          =   195
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   735
   End
End
Attribute VB_Name = "frmLevelizeAdjust"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim tM As CeICU1_Image
Dim tPicture As PictureBox

Public Property Get StepSize() As Integer
    StepSize = 255 - Int((step_size.Max - step_size.Value) ^ 0.555555556)
End Property

Public Property Get StepOffset() As Integer
    StepOffset = step_offset.Value
End Property

Public Sub DoAdjust(image As CeICU1_Image, preview As PictureBox)
    tM = image
    Set tPicture = preview
    Me.Show 1
End Sub

Sub render(ByVal commit As Boolean)
    Dim lp As LEVELIZE_PARAMETERS
    lp.level_step = StepSize
    lp.reference_point = StepOffset
    Dim m As CeICU1_Image

    If commit Then
        m = tM
    Else
        CaAssert DuplicateImage(tM, m, -1)
    End If

    'CaAssert InvertImage(m, CLng(Rnd * &H1000000))

    CaAssert LevelizeEx(m, lp)

    CaAssert StretchToHDC(tPicture.hDC, 0, 0, tPicture.ScaleWidth, tPicture.ScaleHeight, _
        0, 0, m.width, m.height, m, CaTrue)

    If Not commit Then
        CaAssert DestroyImage(m)
    End If

    tPicture.Refresh

End Sub

Private Sub cmdOK_Click()
    render True
    Me.Hide
End Sub

Private Sub step_offset_Change()
    txt_step_offset = StepOffset
    render False
End Sub

Private Sub step_offset_Scroll()
    step_offset_Change
End Sub

Private Sub step_size_Change()
    txt_step_size = StepSize
    render False
End Sub

Private Sub step_size_Scroll()
    step_size_Change
End Sub

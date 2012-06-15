VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "IMFDocument"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit


Enum StateConstants
    NAVIGATE
    SELECTING
    DRAW_ARRAY
    DRAW_RECT
    DRAW_ROUNDRECT
    DRAW_ELLIPSE
    DRAW_POLYGON
    DRAW_COLORRANGE
    Selected
    MOVING
    SIZING
End Enum


Public Dirty As Boolean
Public State As StateConstants

Public Layers As New Collection
Public CurrentLayer As Collection
Public Selection As Collection

Public View As frmImageMarks

Public BackPath As String
Public BackLevelStep As Integer     ' 0 if not available
Public BackLevelOffset As Integer

'

Public Sub Create(ByVal path As String)
    Dim picture As IPictureDisp

    On Error GoTo epic
    Set picture = LoadPicture(path)

    Set View = New frmImageMarks
    Set View.document = Me

    View.SetImage picture
    View.Show
    Exit Sub

epic:
    MsgBox "Invalid image file: " + Err.Description, vbExclamation
End Sub

Public Function BuildIMF() As String

End Function

Private Sub Class_Initialize()
    State = NAVIGATE
End Sub

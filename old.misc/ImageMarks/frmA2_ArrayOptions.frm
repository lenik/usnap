VERSION 5.00
Begin VB.Form frmA2_ArrayOptions
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Array parameters"
   ClientHeight    =   5520
   ClientLeft      =   45
   ClientTop       =   435
   ClientWidth     =   6120
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5520
   ScaleWidth      =   6120
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton btnRing
      BackColor       =   &H00E0FFFF&
      Caption         =   "&Ring Array"
      Height          =   2295
      Left            =   480
      Picture         =   "frmA2_ArrayOptions.frx":0000
      Style           =   1  'Graphical
      TabIndex        =   19
      Top             =   2880
      Width           =   2355
   End
   Begin VB.CommandButton btnMatrix
      BackColor       =   &H00E0FFFF&
      Caption         =   "&Matrix Array"
      Height          =   2295
      Left            =   480
      Picture         =   "frmA2_ArrayOptions.frx":C752
      Style           =   1  'Graphical
      TabIndex        =   10
      Top             =   300
      Width           =   2355
   End
   Begin VB.TextBox values
      Height          =   315
      Index           =   6
      Left            =   4680
      TabIndex        =   17
      Tag             =   "RPAD"
      Text            =   "30.0"
      Top             =   4380
      Width           =   615
   End
   Begin VB.TextBox values
      Height          =   315
      Index           =   5
      Left            =   4680
      TabIndex        =   14
      Tag             =   "RSTART"
      Text            =   "90"
      Top             =   3900
      Width           =   615
   End
   Begin VB.TextBox values
      Height          =   315
      Index           =   4
      Left            =   4680
      TabIndex        =   12
      Tag             =   "RNUMBER"
      Text            =   "12"
      Top             =   3420
      Width           =   615
   End
   Begin VB.TextBox values
      Height          =   315
      Index           =   3
      Left            =   4680
      TabIndex        =   8
      Tag             =   "COLPAD"
      Text            =   "30.0"
      Top             =   1980
      Width           =   615
   End
   Begin VB.TextBox values
      Height          =   315
      Index           =   2
      Left            =   4680
      TabIndex        =   5
      Tag             =   "ROWPAD"
      Text            =   "30.0"
      Top             =   1500
      Width           =   615
   End
   Begin VB.TextBox values
      Height          =   315
      Index           =   1
      Left            =   4680
      TabIndex        =   3
      Tag             =   "COLUMNS"
      Text            =   "4"
      Top             =   1020
      Width           =   615
   End
   Begin VB.TextBox values
      Height          =   315
      Index           =   0
      Left            =   4680
      TabIndex        =   1
      Tag             =   "ROWS"
      Text            =   "4"
      Top             =   540
      Width           =   615
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Deg"
      Height          =   195
      Index           =   12
      Left            =   5340
      TabIndex        =   15
      Top             =   3960
      Width           =   300
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "%"
      Height          =   195
      Index           =   9
      Left            =   5340
      TabIndex        =   18
      Top             =   4440
      Width           =   120
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "&Padding"
      Height          =   195
      Index           =   8
      Left            =   3300
      TabIndex        =   16
      Top             =   4440
      Width           =   585
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "&Start angle: "
      Height          =   195
      Index           =   7
      Left            =   3300
      TabIndex        =   13
      Top             =   3960
      Width           =   855
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "&Number: "
      Height          =   195
      Index           =   6
      Left            =   3300
      TabIndex        =   11
      Top             =   3480
      Width           =   645
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "%"
      Height          =   195
      Index           =   5
      Left            =   5340
      TabIndex        =   9
      Top             =   2040
      Width           =   120
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Col&umn padding: "
      Height          =   195
      Index           =   4
      Left            =   3300
      TabIndex        =   7
      Top             =   2040
      Width           =   1230
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "%"
      Height          =   195
      Index           =   3
      Left            =   5340
      TabIndex        =   6
      Top             =   1560
      Width           =   120
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "Ro&w padding: "
      Height          =   195
      Index           =   2
      Left            =   3300
      TabIndex        =   4
      Top             =   1560
      Width           =   1035
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "&Columns: "
      Height          =   195
      Index           =   1
      Left            =   3300
      TabIndex        =   2
      Top             =   1080
      Width           =   690
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "R&ows: "
      Height          =   195
      Index           =   0
      Left            =   3300
      TabIndex        =   0
      Top             =   600
      Width           =   495
   End
End
Attribute VB_Name = "frmA2_ArrayOptions"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public array_type As String     ' NONE MAT RING

Public mat_rows As Integer
Public mat_cols As Integer
Public mat_rowpad As Single
Public mat_colpad As Single
Public ring_number As Integer
Public ring_start_angle As Double
Public ring_pad As Single

Private Sub btnMatrix_Click()
    array_type = "MAT"
    Me.Hide
End Sub

Private Sub btnRing_Click()
    array_type = "RING"
    Me.Hide
End Sub

Private Sub Form_Load()
    array_type = "NONE"
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Cancel = True
    array_type = "NONE"
    Me.Hide
End Sub

Private Sub values_GotFocus(Index As Integer)
    values(Index).SelStart = 0
    values(Index).SelLength = Len(values(Index).Text)
End Sub

Private Sub values_Validate(Index As Integer, Cancel As Boolean)
    Dim vt As String, vi As Integer, vd As Double
    vt = values(Index).Text
    vd = Val(vt)
    vi = Int(vd)

    Select Case values(Index).Tag
    Case "ROWS", "COLUMNS", "NUMBER"
        If Not IsNumeric(vt) Then
            MsgBox "Value shall be numeric"
            Cancel = True
        ElseIf vi <= 0 Or vi > 128 Then
            MsgBox "Value shall be in range 1..128"
            Cancel = True
        End If
    Case "ROWPAD", "COLPAD", "RPAD"
        If Not IsNumeric(vt) Then
            MsgBox "Value shall be numeric"
            Cancel = True
        ElseIf vd < 0 Or vd > 100 Then
            MsgBox "Value shall be in range 0..100"
            Cancel = True
        End If
    Case "RSTART"
        If Not IsNumeric(vt) Then
            MsgBox "Value shall be numeric"
            Cancel = True
        ElseIf vd < -360 Or vd > 360 Then
            MsgBox "Value shall be in range -360..360"
            Cancel = True
        End If
    End Select
End Sub

Public Property Get Value(ByVal name As String) As Single
    Dim i As Integer
    For i = 0 To values.Count - 1
        If values(i).Tag = name Then
            Value = Val(values(i).Text)
            Exit Property
        End If
    Next
    Err.Raise -1, , "Invalid name (" & name & ")"
End Property

Public Function getArrayOptions() As String
    Me.Show 1

    mat_rows = Value("ROWS")
    mat_cols = Value("COLUMNS")
    mat_rowpad = Value("ROWPAD")
    mat_colpad = Value("COLPAD")

    ring_number = Value("RNUMBER")
    ring_start_angle = Value("RSTART")
    ring_pad = Value("RPAD")

    getArrayOptions = array_type
End Function

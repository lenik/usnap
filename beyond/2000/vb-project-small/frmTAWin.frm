VERSION 5.00
Begin VB.Form frmTAWin
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Test Ascii for Win"
   ClientHeight    =   1095
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   2415
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1095
   ScaleWidth      =   2415
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox chkHex
      Caption         =   "&HEX"
      Height          =   255
      Left            =   120
      TabIndex        =   8
      TabStop         =   0   'False
      Top             =   720
      Width           =   735
   End
   Begin VB.TextBox txtAscii
      ForeColor       =   &H00400000&
      Height          =   285
      Left            =   1080
      TabIndex        =   4
      Text            =   "0"
      Top             =   720
      Width           =   735
   End
   Begin VB.Label Label5
      AutoSize        =   -1  'True
      Caption         =   "TOGGLE"
      ForeColor       =   &H00404040&
      Height          =   195
      Left            =   120
      TabIndex        =   9
      ToolTipText     =   "or Click the Form"
      Top             =   0
      Width           =   660
   End
   Begin VB.Label lblScanUp
      AutoSize        =   -1  'True
      Caption         =   "0"
      ForeColor       =   &H00800000&
      Height          =   195
      Left            =   1800
      TabIndex        =   7
      Top             =   240
      Width           =   90
   End
   Begin VB.Label Label4
      AutoSize        =   -1  'True
      Caption         =   "Up"
      Height          =   195
      Left            =   1800
      TabIndex        =   6
      Top             =   0
      Width           =   210
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "Down"
      Height          =   195
      Left            =   1080
      TabIndex        =   5
      Top             =   0
      Width           =   420
   End
   Begin VB.Label lblAscii
      AutoSize        =   -1  'True
      Caption         =   "[ ]"
      ForeColor       =   &H00004000&
      Height          =   195
      Left            =   1080
      TabIndex        =   3
      Top             =   480
      Width           =   255
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "ASCII: "
      Height          =   195
      Left            =   120
      TabIndex        =   2
      Top             =   480
      Width           =   495
   End
   Begin VB.Label lblScanDown
      AutoSize        =   -1  'True
      Caption         =   "0"
      ForeColor       =   &H00800000&
      Height          =   195
      Left            =   1080
      TabIndex        =   1
      Top             =   240
      Width           =   90
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "ScanCode: "
      Height          =   195
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   840
   End
End
Attribute VB_Name = "frmTAWin"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim bHex As Boolean
Private Function s(ByVal n As Integer) As String
    s = LTrim(IIf(bHex, Hex(n), Str(n)))
End Function

Private Function v(ByVal s As String) As Long
    Dim p As Integer, l As Integer
    If bHex Then
        v = 0
        For p = 1 To Len(s)
            l = Asc(UCase(Mid(s, p, 1)))
            If l >= 48 And l <= 57 Or l >= 65 And l <= 70 Then
                v = v * 16 + IIf(l <= 57, l - 48, l - 55)
            End If
        Next
    Else
        v = Val(s)
    End If
End Function

Private Sub ShowAscii(Ascii As Integer)
    Dim c As String
    c = IIf(Ascii = 0, "\0", Chr(Ascii))
    lblAscii = "[" + c + "] " + s(Ascii)
End Sub

Private Sub chkHex_Click()
    bHex = chkHex
    If bHex Then  ' Just On
        lblScanDown = s(Val(lblScanDown))
        lblScanUp = s(Val(lblScanUp))
        txtAscii = s(Val(txtAscii))
    Else    ' Just Off
        bHex = True
        lblScanDown = Str(v(lblScanDown))
        lblScanUp = Str(v(lblScanUp))
        txtAscii = Str(v(txtAscii))
        bHex = False
    End If
    txtAscii_Change
    txtAscii = s(Ascii)
End Sub

Private Sub Form_Click()
    txtAscii.Visible = Not txtAscii.Visible
    chkHex.Visible = Not chkHex.Visible
    frmTAWin.SetFocus
End Sub

Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
    lblScanDown = s(KeyCode) + " * " + s(Shift)
    If KeyCode = 18 And Shift = 4 Then ' Alt
        KeyCode = 0
    End If
End Sub

Private Sub Form_KeyPress(KeyAscii As Integer)
    ShowAscii KeyAscii
    txtAscii = s(Ascii)
End Sub

Private Sub Form_KeyUp(KeyCode As Integer, Shift As Integer)
    lblScanUp = s(KeyCode) + " * " + s(Shift)
End Sub

Private Sub Form_Load()
    bHex = False
End Sub

Private Sub txtAscii_Change()
    ShowAscii v(txtAscii.Text)
End Sub

Private Sub txtAscii_GotFocus()
    txtAscii.SelStart = 0
    txtAscii.SelLength = Len(txtAscii)
End Sub

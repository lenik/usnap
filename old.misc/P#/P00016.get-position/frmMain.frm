VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "Get Cursor Position"
   ClientHeight    =   3255
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5085
   LinkTopic       =   "Form1"
   ScaleHeight     =   3255
   ScaleWidth      =   5085
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.Label info
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "-"
      BeginProperty Font
         Name            =   "Arial Black"
         Size            =   21.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   675
      Index           =   0
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   210
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Form_Load()
        g_count = 1

        r = 0
        r = catchMessage(hWnd, AddressOf switchProc)
End Sub

Private Sub Form_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        Dim p As POINTAPI
        GetCursorPos p

        Load info(g_count)

        With info(g_count)
                .Left = X
                .Top = Y
                .Caption = p.X & "," & p.Y
                .Visible = True
        End With

        g_count = g_count + 1

End Sub

Private Sub info_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
        If Button And vbRightButton Then
                Unload info(Index)
        End If
End Sub

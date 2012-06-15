VERSION 5.00
Begin VB.Form hashtest
   Caption         =   "hashtest"
   ClientHeight    =   3690
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6570
   LinkTopic       =   "Form3"
   ScaleHeight     =   3690
   ScaleWidth      =   6570
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton gene
      Caption         =   "generate lots"
      Height          =   825
      Left            =   4605
      TabIndex        =   5
      Top             =   270
      Width           =   1830
   End
   Begin VB.ListBox l
      Height          =   1860
      Left            =   480
      TabIndex        =   4
      Top             =   1425
      Width           =   3960
   End
   Begin VB.TextBox value
      Height          =   375
      Left            =   1500
      TabIndex        =   3
      Text            =   "v1"
      Top             =   735
      Width           =   2940
   End
   Begin VB.TextBox key
      Height          =   375
      Left            =   1485
      TabIndex        =   2
      Text            =   "k1"
      Top             =   285
      Width           =   2940
   End
   Begin VB.Label lbl
      AutoSize        =   -1  'True
      Caption         =   "value"
      Height          =   180
      Index           =   1
      Left            =   480
      TabIndex        =   1
      Top             =   750
      Width           =   450
   End
   Begin VB.Label lbl
      AutoSize        =   -1  'True
      Caption         =   "key"
      Height          =   180
      Index           =   0
      Left            =   480
      TabIndex        =   0
      Top             =   345
      Width           =   270
   End
End
Attribute VB_Name = "hashtest"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public h As New OeTHash

Public Sub r()
        Dim i As Integer
        Dim kn As String
        l.Clear
        For i = 0 To h.Count - 1
                kn = h.key(i)
                l.AddItem h.key(kn) & "=" & h(kn)
        Next

End Sub

Private Sub key_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                value.SelStart = 0
                value.SelLength = Len(value)
                value.SetFocus
                KeyAscii = 0
        End If
End Sub

Private Sub value_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                h(key.Text) = value.Text

                key.SelStart = 0
                key.SelLength = Len(key)
                key.SetFocus
                KeyAscii = 0

                r
        End If
End Sub

VERSION 5.00
Begin VB.Form Form2
   Caption         =   "Form2"
   ClientHeight    =   5055
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6375
   LinkTopic       =   "Form2"
   ScaleHeight     =   5055
   ScaleWidth      =   6375
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command3
      Caption         =   "get x addr'str"
      Height          =   375
      Left            =   360
      TabIndex        =   8
      Top             =   3960
      Width           =   2115
   End
   Begin VB.CommandButton Command2
      Caption         =   "get x addr'long"
      Height          =   375
      Left            =   360
      TabIndex        =   7
      Top             =   3540
      Width           =   2115
   End
   Begin VB.CommandButton Command1
      Caption         =   "get x address"
      Height          =   315
      Left            =   360
      TabIndex        =   5
      Top             =   3180
      Width           =   2115
   End
   Begin VB.Timer Timer1
      Interval        =   20
      Left            =   5220
      Top             =   2640
   End
   Begin VB.TextBox mval
      Height          =   375
      Left            =   2760
      TabIndex        =   4
      Text            =   "Text4"
      Top             =   2700
      Width           =   2055
   End
   Begin VB.TextBox maddr
      Height          =   315
      Left            =   360
      TabIndex        =   2
      Text            =   "Text3"
      Top             =   2700
      Width           =   1935
   End
   Begin VB.TextBox dump
      Height          =   1695
      Left            =   360
      MultiLine       =   -1  'True
      TabIndex        =   1
      Tag             =   "1000000"
      Text            =   "vbmemTest.frx":0000
      Top             =   600
      Width           =   5835
   End
   Begin VB.TextBox addr
      Height          =   315
      Left            =   360
      TabIndex        =   0
      Text            =   "0"
      Top             =   120
      Width           =   3375
   End
   Begin VB.Label Label2
      Caption         =   "Label2"
      Height          =   315
      Left            =   3240
      TabIndex        =   6
      Top             =   3240
      Width           =   1455
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "="
      Height          =   180
      Left            =   2460
      TabIndex        =   3
      Top             =   2760
      Width           =   90
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim x

Sub setbyte(ByVal addr, ByVal val)
    forceByte addr, 0, val
End Sub

Sub RefreshMem()
    Dim i, j
    Dim base
    Dim x
    base = val(dump.Tag)
    If base < &H128000 Then base = &H128000
    dump = ""
    For j = 0 To 5
        For i = 0 To 15
            x = Hex(returnByte(base, j * 16 + i))
            If Len(x) = 1 Then x = "0" & x
            dump = dump & x & " "
        Next
        dump = dump & vbNewLine
    Next
End Sub

Private Sub addr_KeyPress(KeyAscii As Integer)
    If KeyAscii = Asc(vbNewLine) Then
        dump.Tag = addr
    End If
End Sub

Private Sub Command1_Click()
    Command1.Caption = getAnyPointer(x)
    addr = Command1.Caption
End Sub

Private Sub Command2_Click()
    Command2.Caption = getLongPointer(x)
    addr = Command2.Caption
End Sub

Private Sub Command3_Click()
    Command3.Caption = getStrPointer(x)
    addr = Command3.Caption
End Sub

Private Sub mval_KeyPress(KeyAscii As Integer)
    If KeyAscii = Asc(vbNewLine) Then
        setbyte maddr, mval
    End If
End Sub

Private Sub Timer1_Timer()
    RefreshMem
    Label2 = CStr(x)
End Sub

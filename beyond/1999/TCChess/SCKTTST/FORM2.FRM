VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form Form2
   Caption         =   "Form2"
   ClientHeight    =   3060
   ClientLeft      =   45
   ClientTop       =   270
   ClientWidth     =   4020
   LinkTopic       =   "Form2"
   ScaleHeight     =   3060
   ScaleWidth      =   4020
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2
      Caption         =   "对话"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   3000
      TabIndex        =   2
      Top             =   480
      Width           =   735
   End
   Begin VB.CommandButton Command1
      Caption         =   "返回"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   2160
      TabIndex        =   1
      Top             =   480
      Width           =   735
   End
   Begin VB.TextBox Text1
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   2055
      Left            =   240
      Locked          =   -1  'True
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   0
      Top             =   840
      Width           =   3495
   End
   Begin MSWinsockLib.Winsock a
      Left            =   2880
      Tag             =   "监听"
      Top             =   0
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      RemoteHost      =   "桃壳信业"
   End
   Begin MSWinsockLib.Winsock b
      Index           =   0
      Left            =   3360
      Top             =   0
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "接收的信息"
      BeginProperty Font
         Name            =   "宋体"
         Size            =   9.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   195
      Left            =   240
      TabIndex        =   3
      Top             =   240
      Width           =   975
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Const maxn = 200
Dim user(maxn) As Boolean

Private Sub command1_click()
    Form2.Hide

End Sub

Private Sub command2_click()
    Load Form1
    Form1.Show
End Sub

Private Sub Form_Load()
    Dim str1 As String
    Form2.Caption = "通信"
    a.LocalPort = 3000
    a.Listen
End Sub

Private Sub a_ConnectionRequest(ByVal requestID As Long)
    Dim i As Long
    For i = 1 To maxn
        If Not user(i) Then
            user(i) = True
            Exit For
        End If
    Next i
    If i > maxn Then
        Exit Sub
    End If
    Load b(i)
    b(i).Accept requestID
    If Text1.Text = "" Then
        b(i).SendData Chr(0)
    Else
        b(i).SendData Text1.Text
    End If
    Form2.Show
End Sub

Private Sub b_close(Index As Integer)
    b(Index).Close
    Unload b(Index)
    user(Index) = False
End Sub

Private Sub b_DataArrival(Index As Integer, ByVal bytesTotal As Long)
    Dim str As String
    Dim i As Long
    b(Index).GetData str
    Text1.Text = Text1.Text + str
    For i = 1 To maxn
        If user(Index) Then
            b(Index).SendData str
        End If
    Next i

End Sub

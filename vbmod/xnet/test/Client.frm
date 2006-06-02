VERSION 5.00
Begin VB.Form Client
   Caption         =   "Client"
   ClientHeight    =   5550
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6840
   LinkTopic       =   "Form1"
   ScaleHeight     =   5550
   ScaleWidth      =   6840
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnSend
      Caption         =   "&Send"
      Height          =   915
      Left            =   5280
      TabIndex        =   2
      Top             =   4200
      Width           =   1035
   End
   Begin VB.TextBox Text1
      Height          =   795
      Left            =   720
      TabIndex        =   1
      Text            =   "some text from Client"
      Top             =   4200
      Width           =   4095
   End
   Begin VB.ListBox List1
      Height          =   3375
      Left            =   1020
      TabIndex        =   0
      Top             =   360
      Width           =   4275
   End
End
Attribute VB_Name = "Client"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private WithEvents sd As Socket
Attribute sd.VB_VarHelpID = -1

Private Sub btnSend_Click()
    sd.SendData Text1.Text
End Sub

Private Sub Form_Load()
    Set sd = New Socket
    sd.Connect "127.0.0.1", 5103
    sd.RemotePort = 5103
End Sub

Private Sub sd_OnDataArrival(ByVal bytesTotal As Long)
    Dim data
    sd.GetData data
    List1.AddItem data, 0
End Sub

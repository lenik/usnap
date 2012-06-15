VERSION 5.00
Begin VB.Form frmClient
   Caption         =   "Client"
   ClientHeight    =   5550
   ClientLeft      =   165
   ClientTop       =   555
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
      Left            =   780
      TabIndex        =   0
      Top             =   360
      Width           =   5415
   End
End
Attribute VB_Name = "frmClient"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private WithEvents Client As Client
Attribute Client.VB_VarHelpID = -1

Private Sub btnSend_Click()
    Client.Connection.SendMessage Text1.Text
End Sub

Private Sub Client_OnMessage(ByVal Message As String)
    AddLog Client.Connection.QPeer & " - " & Message
End Sub

Private Sub Form_Load()
    Set Client = Network.Connect(CHAT_PORT)
End Sub

Sub AddLog(ByVal s)
    List1.AddItem s, 0
End Sub

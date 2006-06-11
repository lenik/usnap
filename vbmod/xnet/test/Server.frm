VERSION 5.00
Begin VB.Form frmServer
   Caption         =   "Server"
   ClientHeight    =   5565
   ClientLeft      =   165
   ClientTop       =   555
   ClientWidth     =   6360
   LinkTopic       =   "Form1"
   ScaleHeight     =   5565
   ScaleWidth      =   6360
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox List1
      Height          =   3375
      Left            =   480
      TabIndex        =   2
      Top             =   480
      Width           =   5535
   End
   Begin VB.TextBox Text1
      Height          =   795
      Left            =   480
      TabIndex        =   1
      Text            =   "SOME TEXT FROM sERVER"
      Top             =   4260
      Width           =   4095
   End
   Begin VB.CommandButton btnSend
      Caption         =   "&Send"
      Height          =   915
      Left            =   5040
      TabIndex        =   0
      Top             =   4260
      Width           =   1035
   End
End
Attribute VB_Name = "frmServer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private WithEvents Server As Server
Attribute Server.VB_VarHelpID = -1

Private Sub btnSend_Click()
    Dim i As Long
    Dim Id As Long
    Dim c As Connection
    For i = 0 To Server.Connections - 1
        Id = Server.ConnectionId(i)
        Set c = Server.Connection(Id)
        c.SendMessage Text1.Text
    Next
End Sub

Private Sub Form_Load()
    Set Server = Network.Bind(CHAT_PORT)
End Sub

Sub AddLog(ByVal s)
    List1.AddItem s, 0
End Sub

Private Sub Server_OnMessage(ByVal c As Xnet.Connection, ByVal Message As String)
    AddLog c.QPeer & " - " & Message
End Sub

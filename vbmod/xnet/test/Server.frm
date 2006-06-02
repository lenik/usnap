VERSION 5.00
Begin VB.Form Server
   Caption         =   "Server"
   ClientHeight    =   5565
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6360
   LinkTopic       =   "Form1"
   ScaleHeight     =   5565
   ScaleWidth      =   6360
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox List1
      Height          =   3375
      Left            =   1020
      TabIndex        =   2
      Top             =   540
      Width           =   4275
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
Attribute VB_Name = "Server"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private WithEvents sdserver As Socket
Attribute sdserver.VB_VarHelpID = -1
Private WithEvents sd As Socket
Attribute sd.VB_VarHelpID = -1

Private Sub btnSend_Click()
    sd.SendData Text1.Text
End Sub

Private Sub Form_Load()
    Set sdserver = New Socket
    Set sd = New Socket
    sdserver.Bind
End Sub

Private Sub sdserver_OnConnectionRequest(ByVal requestID As Long)
    sd.Accept requestID
End Sub

Private Sub sd_OnDataArrival(ByVal bytesTotal As Long)
    Dim data
    sd.GetData data
    List1.AddItem data, 0
End Sub

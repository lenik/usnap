VERSION 5.00
Begin VB.Form Client
   Caption         =   "Client"
   ClientHeight    =   5550
   ClientLeft      =   165
   ClientTop       =   555
   ClientWidth     =   6840
   LinkTopic       =   "Form1"
   ScaleHeight     =   5550
   ScaleWidth      =   6840
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnStart
      Caption         =   "Start"
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   240
      Width           =   675
   End
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

Private Sub btnStart_Click()
    Set sd = New Socket
    sd.RemoteHost = "127.0.0.1"
    sd.RemotePort = 5103
    sd.Tag = "Client Connection"

    'sd.AutoMode = amConnect
    sd.Connect
End Sub

Private Sub Form_Load()
    ShowResources
End Sub

Sub AddLog(ByVal s)
    List1.AddItem s, 0
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Set sd = Nothing
End Sub

Private Sub res_Click()
    ShowResources
End Sub

Private Sub sd_OnClose()
    AddLog "sd onclose"
End Sub

Private Sub sd_OnConnect()
    AddLog "sd onconnect"
End Sub

Private Sub sd_OnConnectionRequest(ByVal requestID As Long)
    AddLog "sd onconnectreq:" & requestID
End Sub

Private Sub sd_OnError(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    AddLog "sd onerror:" & Description
End Sub

Private Sub sd_OnDataArrival(ByVal bytesTotal As Long)
    Dim data
    sd.GetData data
    data = BytesToString(data)
    List1.AddItem data, 0
End Sub

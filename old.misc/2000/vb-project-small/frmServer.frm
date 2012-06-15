VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form frmServer
   Caption         =   "·þÎñ³ÌÐò"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin MSWinsockLib.Winsock sockClients
      Index           =   0
      Left            =   1440
      Top             =   480
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
   Begin MSWinsockLib.Winsock sockServer
      Left            =   600
      Top             =   480
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      LocalPort       =   3100
   End
End
Attribute VB_Name = "frmServer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Load()
    sockServer.Listen
End Sub

Private Sub sockClients_DataArrival(Index As Integer, ByVal bytesTotal As Long)
    Dim str As String
    sockClients(0).GetData str
    sockClients(0).SendData str
End Sub

Private Sub sockServer_ConnectionRequest(ByVal requestID As Long)
    sockClients(0).Accept requestID

End Sub

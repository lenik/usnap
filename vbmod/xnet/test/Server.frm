VERSION 5.00
Begin VB.Form Server
   Caption         =   "Server"
   ClientHeight    =   5565
   ClientLeft      =   165
   ClientTop       =   855
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
   Begin VB.Menu res
      Caption         =   "res"
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
    sdserver.Protocol = sckTCPProtocol
    sdserver.Tag = "Server Socket"
    sdserver.LocalPort = 5103

    Set sd = New Socket
    sd.Protocol = sckTCPProtocol
    sd.Tag = "Connection Socket"

    sdserver.AutoMode = amListen
    sdserver.Listen
End Sub

Sub AddLog(ByVal s)
    List1.AddItem s, 0
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

Private Sub sd_OnSendComplete()
    AddLog "sd onsendcompl"
End Sub

Private Sub sd_OnSendProgress(ByVal bytesSent As Long, ByVal bytesRemaining As Long)
    AddLog "sd onsendprog"
End Sub

Private Sub sdserver_OnClose()
    AddLog "sdserver onclose"
End Sub

Private Sub sdserver_OnConnect()
    AddLog "sdserver onconnect"
End Sub

Private Sub sdserver_OnConnectionRequest(ByVal requestID As Long)
    AddLog "sdserver onconnectreq:" & requestID
    sd.Accept requestID
End Sub

Private Sub sd_OnDataArrival(ByVal bytesTotal As Long)
    Dim data
    sd.GetData data
    data = BytesToString(data)
    List1.AddItem data, 0
End Sub

Private Sub sdserver_OnDataArrival(ByVal bytesTotal As Long)
    AddLog "sdserver onrecv:" & bytesTotal
    Dim d
    sdserver.GetData d
    AddLog "sdserver getdata:<" & BytesToString(d) & ">"
End Sub

Private Sub sdserver_OnError(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    AddLog "sdserver onerror:" & Description
End Sub

Private Sub sdserver_OnSendComplete()
    AddLog "sdserver onsendcompl"
End Sub

Private Sub sdserver_OnSendProgress(ByVal bytesSent As Long, ByVal bytesRemaining As Long)
    AddLog "sdserver onsendprogress"
End Sub

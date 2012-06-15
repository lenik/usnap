VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form frmechowebserver
   Caption         =   "回显Web服务器"
   ClientHeight    =   825
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   2295
   LinkTopic       =   "Form1"
   ScaleHeight     =   825
   ScaleWidth      =   2295
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox port
      Appearance      =   0  'Flat
      Height          =   270
      Left            =   600
      TabIndex        =   0
      Text            =   "80"
      Top             =   120
      Width           =   1335
   End
   Begin MSWinsockLib.Winsock sock
      Left            =   120
      Top             =   120
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      LocalPort       =   80
   End
End
Attribute VB_Name = "frmechowebserver"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Public waitdata As Boolean
Public alls As String

Private Sub Form_Activate()
    While True
        While Not waitdata
            DoEvents
        Wend
        sock.SendData "HTTP/1.1" & vbNewLine & "Content-type: text/plain" & vbNewLine & vbNewLine & _
                alls
        waitdata = False
    Wend
End Sub

Private Sub Form_Load()
    waitdata = False
    sock.Listen
End Sub

Private Sub port_KeyPress(KeyAscii As Integer)
    If KeyAscii = 13 Then
        sock.Close
        sock.LocalPort = Val(port)
        sock.Listen
    End If
End Sub

Private Sub sock_Close()
    sock.Close
    sock.Listen
End Sub

Private Sub sock_ConnectionRequest(ByVal requestID As Long)
    sock.Close
    sock.Accept requestID
End Sub

Private Sub sock_DataArrival(ByVal bytesTotal As Long)
    Dim buf As String * 10000
    alls = ""
    While bytesTotal > 0
        sock.GetData buf, , 10000
        alls = alls & Left(buf, IIf(bytesTotal > 10000, 10000, bytesTotal))
        bytesTotal = bytesTotal - 10000
    Wend
    waitdata = True
End Sub

Private Sub sock_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    MsgBox Description
End Sub

Private Sub sock_SendComplete()
    sock.Close
    sock.Listen
End Sub

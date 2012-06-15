VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Object = "{0E59F1D2-1FBE-11D0-8FF2-00A0D10038BC}#1.0#0"; "msscript.ocx"
Begin VB.Form frmSock2
   Caption         =   "Form1"
   ClientHeight    =   6660
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   7680
   LinkTopic       =   "Form1"
   ScaleHeight     =   6660
   ScaleWidth      =   7680
   StartUpPosition =   3  '窗口缺省
   Begin VB.CheckBox Check2
      Caption         =   "Check2"
      Height          =   255
      Left            =   5460
      TabIndex        =   28
      Top             =   6000
      Value           =   1  'Checked
      Width           =   1395
   End
   Begin VB.CheckBox Check1
      Caption         =   "Check1"
      Height          =   255
      Left            =   5460
      TabIndex        =   27
      Top             =   5640
      Width           =   1215
   End
   Begin VB.CommandButton SDClose
      Caption         =   "server close"
      Height          =   375
      Left            =   1740
      TabIndex        =   26
      Top             =   4860
      Width           =   1575
   End
   Begin VB.CommandButton SDSend
      Caption         =   "server"
      Height          =   315
      Left            =   3780
      TabIndex        =   25
      Top             =   6000
      Width           =   1575
   End
   Begin VB.CommandButton CDSend
      Caption         =   "client"
      Height          =   315
      Left            =   3780
      TabIndex        =   24
      Top             =   5640
      Width           =   1575
   End
   Begin VB.TextBox inp
      Height          =   315
      Left            =   3720
      TabIndex        =   23
      Text            =   "Text3"
      Top             =   5280
      Width           =   3255
   End
   Begin VB.TextBox msg
      Height          =   1215
      Left            =   60
      MultiLine       =   -1  'True
      TabIndex        =   22
      Text            =   "vbsocktest2.frx":0000
      Top             =   5280
      Width           =   3555
   End
   Begin VB.CommandButton CDConnect
      Caption         =   "client connect"
      Height          =   375
      Left            =   3420
      TabIndex        =   21
      Top             =   4860
      Width           =   1515
   End
   Begin MSWinsockLib.Winsock sockCDebug
      Left            =   480
      Top             =   4440
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      LocalPort       =   1601
   End
   Begin MSWinsockLib.Winsock sockSDebug
      Left            =   60
      Top             =   4440
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      LocalPort       =   1600
   End
   Begin VB.CommandButton SDListen
      Caption         =   "server listen"
      Height          =   375
      Left            =   60
      TabIndex        =   20
      Top             =   4860
      Width           =   1515
   End
   Begin VB.TextBox cL
      Height          =   390
      Left            =   6480
      TabIndex        =   19
      Top             =   1440
      Width           =   435
   End
   Begin VB.TextBox sL
      Height          =   390
      Left            =   6480
      TabIndex        =   17
      Top             =   1020
      Width           =   435
   End
   Begin VB.TextBox Text1
      Height          =   315
      Left            =   5160
      TabIndex        =   14
      Text            =   "lines"
      Top             =   3060
      Width           =   555
   End
   Begin VB.CommandButton Command6
      Caption         =   "reset socket"
      Height          =   315
      Left            =   2460
      TabIndex        =   13
      Top             =   4200
      Width           =   1215
   End
   Begin VB.TextBox tout
      Height          =   315
      Left            =   4260
      TabIndex        =   12
      Text            =   "Text Out"
      Top             =   3960
      Width           =   3075
   End
   Begin VB.TextBox tt
      Height          =   315
      Left            =   60
      TabIndex        =   11
      Text            =   "Text Netfunc"
      Top             =   3600
      Width           =   3855
   End
   Begin VB.CheckBox chkecho
      Caption         =   "本地回现"
      Height          =   195
      Left            =   5880
      TabIndex        =   10
      Top             =   660
      Width           =   1395
   End
   Begin VB.TextBox tin
      Height          =   315
      Left            =   4260
      TabIndex        =   9
      Text            =   "Text In"
      Top             =   3600
      Width           =   3075
   End
   Begin VB.TextBox txtstatusC
      Height          =   315
      Left            =   60
      TabIndex        =   8
      Text            =   "client status"
      Top             =   660
      Width           =   2235
   End
   Begin VB.CommandButton Command5
      Caption         =   "服务器侦听"
      Height          =   375
      Left            =   6000
      TabIndex        =   7
      Top             =   2280
      Width           =   1275
   End
   Begin VB.CommandButton Command4
      Caption         =   "客户关闭"
      Height          =   375
      Left            =   6000
      TabIndex        =   6
      Top             =   2700
      Width           =   1275
   End
   Begin VB.CommandButton Command3
      Caption         =   "cls"
      Height          =   315
      Left            =   120
      TabIndex        =   5
      Top             =   3240
      Width           =   975
   End
   Begin VB.Timer Timer1
      Interval        =   100
      Left            =   1620
      Top             =   4020
   End
   Begin VB.TextBox txtstatusS
      Height          =   315
      Left            =   60
      TabIndex        =   4
      Text            =   "server status"
      Top             =   360
      Width           =   2235
   End
   Begin VB.CommandButton Command2
      Caption         =   "do"
      Height          =   555
      Left            =   5880
      TabIndex        =   3
      Top             =   60
      Width           =   675
   End
   Begin VB.TextBox testscr
      Height          =   855
      Left            =   2880
      MultiLine       =   -1  'True
      TabIndex        =   2
      Text            =   "vbsocktest2.frx":0006
      Top             =   60
      Width           =   2835
   End
   Begin VB.PictureBox pic
      AutoRedraw      =   -1  'True
      BackColor       =   &H00000000&
      DrawMode        =   7  'Invert
      ForeColor       =   &H00FFFFFF&
      Height          =   2115
      Left            =   60
      ScaleHeight     =   2055
      ScaleWidth      =   5595
      TabIndex        =   1
      Top             =   1020
      Width           =   5655
   End
   Begin MSScriptControlCtl.ScriptControl script
      Left            =   960
      Top             =   4020
      _ExtentX        =   1005
      _ExtentY        =   1005
      AllowUI         =   -1  'True
   End
   Begin VB.TextBox txtremote
      Height          =   315
      Left            =   60
      TabIndex        =   0
      Text            =   "df"
      Top             =   0
      Width           =   2655
   End
   Begin MSWinsockLib.Winsock sockS
      Left            =   60
      Top             =   4020
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      RemotePort      =   1601
      LocalPort       =   1600
   End
   Begin MSWinsockLib.Winsock sockC
      Left            =   480
      Top             =   4020
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      RemotePort      =   1600
      LocalPort       =   1601
   End
   Begin VB.Label Label2
      Caption         =   "Client"
      Height          =   195
      Left            =   5820
      TabIndex        =   18
      Top             =   1500
      Width           =   555
   End
   Begin VB.Label Label1
      Caption         =   "Server"
      Height          =   195
      Left            =   5820
      TabIndex        =   16
      Top             =   1080
      Width           =   555
   End
   Begin VB.Label lblRox
      Caption         =   "??DoEvents"
      Height          =   255
      Left            =   2340
      TabIndex        =   15
      Top             =   360
      Width           =   495
   End
End
Attribute VB_Name = "frmSock2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim bDown As Boolean

Public sp As New ScriptPicture
Public cx As Single, cy As Single, sx As Single, sy As Single

Private Sub CDConnect_Click()
        sockCDebug.Close
        sockCDebug.Connect txtremote, CurrentFN.ServerPort
End Sub

Private Sub CDSend_Click()
        If sockCDebug.State <> sckConnected Then
                MsgBox "unconnected socket", , "sockCDebug"
        Else
                sockCDebug.SendData inp.text
        End If
End Sub

Private Sub Check1_Click()
        Check2.Value = IIf(Check1.Value, 0, 1)
End Sub

Private Sub Check2_Click()
        Check1.Value = IIf(Check2.Value, 0, 1)
End Sub

Private Sub Form_Unload(Cancel As Integer)
        End
End Sub

Private Sub inp_GotFocus()
        inp.SelStart = 0
        inp.SelLength = Len(inp)
End Sub

Private Sub inp_KeyPress(KeyAscii As Integer)
        If KeyAscii = 13 Then
                If Check1 Then CDSend_Click Else: SDSend_Click
                inp_GotFocus
        End If
End Sub

Private Sub SDClose_Click()
        sockSDebug.Close
        sockS.Close
        sockS.Listen
End Sub

Private Sub SDListen_Click()
        sockS.Close
        sockSDebug.Close
        sockSDebug.Listen
End Sub

Private Sub SDSend_Click()
        If sockSDebug.State <> sckConnected Then
                MsgBox "unconnected socket", , "sockSDebug"
        Else
                sockSDebug.SendData inp.text
        End If
End Sub

Private Sub sL_KeyPress(KeyAscii As Integer)
        If Chr(KeyAscii) = "s" Then CurrentFN.ServerSession = False
        If Chr(KeyAscii) = "l" Then CurrentFN.ServerLocked = False
        KeyAscii = 0
End Sub

Private Sub cL_KeyPress(KeyAscii As Integer)
        If Chr(KeyAscii) = "s" Then CurrentFN.ClientSession = False
        If Chr(KeyAscii) = "l" Then CurrentFN.ClientLocked = False
        KeyAscii = 0
End Sub

Private Sub Command2_Click()
        Dim net_done As Boolean
        On Error GoTo e
        If chkecho Then script.ExecuteStatement testscr
        net_done = False
        net_done = FN_ScriptIO(txtremote, testscr)
        Exit Sub
e:
        If net_done Then
                MsgBox "error during network"
        Else
                MsgBox "error before net"
        End If
End Sub

Private Sub Command3_Click()
        pic.Cls
End Sub

Private Sub Command4_Click()
        sockC.Close
End Sub

Private Sub Command5_Click()
        sockS.Close
        sockS.Listen
End Sub

Private Sub Command6_Click()
        FN_change_socket
End Sub

Private Sub Form_Load()
        If Trim(Dir("C:\Low\Go.com")) = "" Then
                txtremote = "tc-info"
                pic.ForeColor = &HFF&
        End If
        script.AddObject "Form", Me, True
        script.AddObject "sockS", sockS
        script.AddObject "sockC", sockC
        script.AddObject "p", pic
        script.AddObject "sp", sp
        Set modFastNet.script = script
        FN_Initialize sockS, sockC, 1600, 1601
End Sub

Private Sub Form_Terminate()
        sockS_Close
        sockC_Close
End Sub

Private Sub pic_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
        sx = x: sy = y
        If chkecho Then script.ExecuteStatement "sp.SetPixel p," & x & ", " & y & ", " & pic.ForeColor
        FN_ScriptIO txtremote, "sp.SetPixel p," & x & ", " & y & ", " & pic.ForeColor
        bDown = True
End Sub

Private Sub pic_MouseMove(Button As Integer, Shift As Integer, x As Single, y As Single)
        Dim lastx As Single, lasty As Single
        If bDown Then
                lastx = sx: lasty = sy
                sx = x: sy = y
                If chkecho Then script.ExecuteStatement "sp.ToPixel p, " & lastx & ", " _
                                                         & lasty & ", " _
                                                         & x & ", " _
                                                         & y & ", " & pic.ForeColor
                FN_ScriptIO txtremote, "sp.ToPixel p, " & lastx & ", " _
                                                         & lasty & ", " _
                                                         & x & ", " _
                                                         & y & ", " & pic.ForeColor
        End If
End Sub

Private Sub pic_MouseUp(Button As Integer, Shift As Integer, x As Single, y As Single)
        If bDown Then bDown = False
End Sub

Private Sub sockCDebug_Close()
        sockCDebug.Close
End Sub

Private Sub sockCDebug_Connect()
        msg = "C/Connect!" & vbNewLine & msg
End Sub

Private Sub sockCDebug_DataArrival(ByVal bytesTotal As Long)
        Dim buf As String
        sockCDebug.GetData buf
        msg = "C/" & buf & vbNewLine & msg
End Sub

Private Sub sockCDebug_Error(ByVal number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        MsgBox Description, vbOKCancel, "sockCDebug"
End Sub

Private Sub sockS_Close(): callProcedure1 CurrentFN.ServerCall.procClose, 0: End Sub
Private Sub sockS_Connect(): callProcedure1 CurrentFN.ServerCall.procConnect, 0: End Sub
Private Sub sockS_ConnectionRequest(ByVal requestID As Long): callProcedure1 CurrentFN.ServerCall.procConnectionRequest, requestID: End Sub
Private Sub sockS_DataArrival(ByVal bytesTotal As Long): callProcedure1 CurrentFN.ServerCall.procDataArrival, bytesTotal: End Sub
Private Sub sockS_Error(ByVal number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        With CurrentFN.ServerError
                .number = number
                .Description = Description
                .Scode = Scode
                .Source = Source
                .HelpFile = HelpFile
                .HelpContext = HelpContext
                .CancelDisplay = CancelDisplay
        End With
        callProcedure1 CurrentFN.ServerCall.procError, number
End Sub
Private Sub sockS_SendComplete(): callProcedure1 CurrentFN.ServerCall.procSendComplete, 0: End Sub
Private Sub sockS_SendProgress(ByVal bytesSent As Long, ByVal bytesRemaining As Long)
        CurrentFN.ServerSend.bytesSent = bytesSent
        CurrentFN.ServerSend.bytesRemaining = bytesRemaining
        callProcedure1 CurrentFN.ServerCall.procSendProgress, 0
End Sub

Private Sub sockC_Close(): callProcedure1 CurrentFN.ClientCall.procClose, 0: End Sub
Private Sub sockC_Connect(): callProcedure1 CurrentFN.ClientCall.procConnect, 0: End Sub
Private Sub sockC_ConnectionRequest(ByVal requestID As Long): callProcedure1 CurrentFN.ClientCall.procConnectionRequest, requestID: End Sub
Private Sub sockC_DataArrival(ByVal bytesTotal As Long): callProcedure1 CurrentFN.ClientCall.procDataArrival, bytesTotal: End Sub
Private Sub sockC_Error(ByVal number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        With CurrentFN.ClientError
                .number = number
                .Description = Description
                .Scode = Scode
                .Source = Source
                .HelpFile = HelpFile
                .HelpContext = HelpContext
                .CancelDisplay = CancelDisplay
        End With
        callProcedure1 CurrentFN.ClientCall.procError, number
End Sub
Private Sub sockC_SendComplete(): callProcedure1 CurrentFN.ClientCall.procSendComplete, 0: End Sub
Private Sub sockC_SendProgress(ByVal bytesSent As Long, ByVal bytesRemaining As Long)
        CurrentFN.ClientSend.bytesSent = bytesSent
        CurrentFN.ClientSend.bytesRemaining = bytesRemaining
        callProcedure1 CurrentFN.ClientCall.procSendProgress, 0
End Sub

Private Sub sockSDebug_Close()
        sockSDebug.Close
End Sub

Private Sub sockSDebug_ConnectionRequest(ByVal requestID As Long)
        sockSDebug.Close
        sockSDebug.Accept requestID
        msg = "S/ConnectionRequest!" & vbNewLine & msg
End Sub

Private Sub sockSDebug_DataArrival(ByVal bytesTotal As Long)
        Dim buf As String
        sockSDebug.GetData buf
        msg = "S/" & buf & vbNewLine & msg
End Sub

Private Sub sockSDebug_Error(ByVal number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
        MsgBox Description, vbOKCancel, "SOCK DEBUG"
        sockSDebug.Close
        sockSDebug.Listen
End Sub

Private Sub TT_KeyPress(KeyAscii As Integer)
        Dim ii As Integer
        Dim es As String

        For ii = 1 To 1
                If KeyAscii <> 13 Then
                        es = "form.tt.text=form.tt.text & chr(" & KeyAscii & ")" _
                                & ":form.tt.selstart=len(form.tt.text):form.tt.sellength=0"
                Else
                        es = "form.tt.text="""""
                End If
                script.ExecuteStatement es
                FN_ScriptIO txtremote, es
        Next

        KeyAscii = 0
End Sub

Private Sub Timer1_Timer()
        Select Case sockS.State
        Case sckClosed: txtstatusS = "sckClosed": Timer1.Interval = 500
        Case sckClosing: txtstatusS = "sckClosing"
        Case sckConnected: txtstatusS = "sckConnected": Timer1.Interval = 1
        Case sckConnecting: txtstatusS = "sckConnecting": Timer1.Interval = 1
        Case sckConnectionPending: txtstatusS = "sckConnectionPending"
        Case sckError: txtstatusS = "sckError"
        Case sckHostResolved: txtstatusS = "sckHostResolved"
        Case sckListening: txtstatusS = "sckListening": Timer1.Interval = 1
        Case sckOpen: txtstatusS = "sckOpen"
        Case sckResolvingHost: txtstatusS = "sckResolvingHost"
        End Select
        txtstatusS = str(sockS.State) & txtstatusS

        Select Case sockC.State
        Case sckClosed: txtstatusC = "sckClosed": Timer1.Interval = 500
        Case sckClosing: txtstatusC = "sckClosing"
        Case sckConnected: txtstatusC = "sckConnected": Timer1.Interval = 1
        Case sckConnecting: txtstatusC = "sckConnecting": Timer1.Interval = 1
        Case sckConnectionPending: txtstatusC = "sckConnectionPending"
        Case sckError: txtstatusC = "sckError"
        Case sckHostResolved: txtstatusC = "sckHostResolved"
        Case sckListening: txtstatusC = "sckListening": Timer1.Interval = 1
        Case sckOpen: txtstatusC = "sckOpen"
        Case sckResolvingHost: txtstatusC = "sckResolvingHost"
        End Select
        txtstatusC = str(sockC.State) & txtstatusC

        tin = CurrentFN.SessionBuffer.TextIn
        tout = CurrentFN.SessionBuffer.TextOut

        Text1 = FN_WaitingLine

        If CurrentFN.ServerSession = False Then
                sL.BackColor = &HFF00&
                If CurrentFN.ServerLocked Then sL.BackColor = &HFF0000
        Else
                sL.BackColor = &HFF&
                If CurrentFN.ServerLocked Then sL.BackColor = &H0&
        End If
        If CurrentFN.ClientSession = False Then
                cL.BackColor = &HFF00&
                If CurrentFN.ClientLocked Then cL.BackColor = &HFF0000
        Else
                cL.BackColor = &HFF&
                If CurrentFN.ClientLocked Then cL.BackColor = &H0&
        End If
End Sub

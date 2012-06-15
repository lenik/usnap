VERSION 5.00
Begin VB.Form frmSDE_Client
   Caption         =   "Form1"
   ClientHeight    =   5910
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6300
   Icon            =   "SDE_Client.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   5910
   ScaleWidth      =   6300
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command10
      Caption         =   "Command10"
      Height          =   870
      Left            =   2865
      TabIndex        =   12
      Top             =   4920
      Width           =   1185
   End
   Begin VB.CommandButton Command9
      Caption         =   "Command9"
      Height          =   900
      Left            =   675
      TabIndex        =   11
      Top             =   4875
      Width           =   855
   End
   Begin VB.CommandButton Command8
      Caption         =   "Command8"
      Height          =   765
      Left            =   4275
      TabIndex        =   10
      Top             =   90
      Width           =   1215
   End
   Begin VB.CommandButton Command7
      Caption         =   "Command7"
      Height          =   570
      Left            =   4860
      TabIndex        =   9
      Top             =   1380
      Width           =   675
   End
   Begin VB.CommandButton Command6
      Caption         =   "Command6"
      Height          =   555
      Left            =   4200
      TabIndex        =   8
      Top             =   2550
      Width           =   1590
   End
   Begin VB.ListBox List1
      Height          =   1425
      Left            =   525
      TabIndex        =   7
      Top             =   3225
      Width           =   5400
   End
   Begin VB.CommandButton Command5
      Caption         =   "grab"
      Height          =   570
      Left            =   3105
      TabIndex        =   5
      Top             =   1365
      Width           =   855
   End
   Begin VB.CommandButton Command4
      Caption         =   "stop"
      Height          =   885
      Left            =   2865
      TabIndex        =   3
      Top             =   2220
      Width           =   960
   End
   Begin VB.CommandButton Command3
      Caption         =   "pause"
      Height          =   885
      Left            =   1725
      TabIndex        =   2
      Top             =   2220
      Width           =   930
   End
   Begin VB.CommandButton Command2
      Caption         =   "play"
      Height          =   885
      Left            =   660
      TabIndex        =   1
      Top             =   2220
      Width           =   855
   End
   Begin VB.CommandButton Command1
      Caption         =   "open"
      Height          =   1485
      Left            =   810
      TabIndex        =   0
      Top             =   225
      Width           =   2010
   End
   Begin VB.Label Label2
      Caption         =   "Label2"
      Height          =   360
      Left            =   2925
      TabIndex        =   6
      Top             =   945
      Width           =   1380
   End
   Begin VB.Label Label1
      Caption         =   "Label1"
      Height          =   495
      Left            =   2970
      TabIndex        =   4
      Top             =   390
      Width           =   1320
   End
End
Attribute VB_Name = "frmSDE_Client"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public caidn As New CaIDNLib.CaIDNGuidName
Public WithEvents caidnx As CaIDNLib.CaIDNGuidName
Attribute caidnx.VB_VarHelpID = -1

Public sde As New CeShowXLibCtl.CeSXSDE
Public WithEvents sdex As CeShowXLibCtl.CeSXSDE
Attribute sdex.VB_VarHelpID = -1

Private Sub caidnx_OnEnumeration(ByVal pGuid As CaIDNLib.ICaIDNGuid, ByVal Name As String)
        Dim am As AM_MEDIA_TYPE
        Dim aml As Long
        aml = pAny(am)

        List1.AddItem Name & pGuid.StringRepresentation
End Sub

Private Sub Command1_Click()

'        sx.InitializeFilters
'        Set sxe = sx
'        sx.RenderFile "H:\avi.avi"
'        sx.RegisterROT
'        sx.UseRenderEvent = True
'        'sx.gr.put_render_proc pFunc(AddressOf RenderProc), 0
'        sx.GR.render_enabled = True
'        sx.UseGrabEvent = True
'        'sx.gr.put_grab_proc pFunc(AddressOf GrabProc), 0
'        sx.GR.grab_enabled = True
End Sub

Private Sub Command10_Click()
        Dim vih2 As VideoInfoHeader2
'        vih2 = GetVih2(sx.GR)
End Sub

Private Sub Command2_Click()
'        sx.Run
End Sub

Private Sub Command3_Click()
'        sx.Pause
End Sub

Private Sub Command4_Click()
'       sx.Stop
End Sub

Private Sub Command5_Click()
'        sx.GR.grab_event = True
End Sub

Private Sub Command6_Click()
        List1.Clear
        Set caidnx = caidn
        caidn.EnumerateStatics
End Sub

Private Sub Command7_Click()
'        MsgBox ctT.reference(sx.GR)
End Sub

Private Sub Command9_Click()
        Dim xx As AM_MEDIA_TYPE
        Dim ll As Long
        ll = pAny(xx)
        MsgBox ll

        List1.Clear
        Set sdex = sde
        sde.Category = fceVideoCaptureSources
        sde.EnumerateDevicesInCurrentCategory
End Sub

Private Sub sdex_OnEnumeration(ByVal Device As CeShowXLibCtl.ICeSXSD)
        List1.AddItem Device.FriendlyName
End Sub

'Private Sub sxe_OnGrab(ByVal pSample As CeShowXLib.IMediaSample, ByVal pGR As CeShowXLib.IGeneralRenderer)
'        Label1 = val(Label1) + 1
'End Sub

'Private Sub sxe_OnRender(ByVal pSample As CeShowXLib.IMediaSample, ByVal pGR As CeShowXLib.IGeneralRenderer)
'        Label2 = val(Label2) + 1
'End Sub

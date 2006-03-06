VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form SourcePicture
   Caption         =   "Source picture"
   ClientHeight    =   3090
   ClientLeft      =   165
   ClientTop       =   855
   ClientWidth     =   4680
   LinkTopic       =   "Form2"
   ScaleHeight     =   206
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   312
   StartUpPosition =   3  'Windows Default
   Begin MSComctlLib.StatusBar sb
      Align           =   2  'Align Bottom
      Height          =   375
      Left            =   0
      TabIndex        =   1
      Top             =   2715
      Width           =   4680
      _ExtentX        =   8255
      _ExtentY        =   661
      _Version        =   393216
      BeginProperty Panels {8E3867A5-8586-11D1-B16A-00C0F0283628}
         NumPanels       =   1
         BeginProperty Panel1 {8E3867AB-8586-11D1-B16A-00C0F0283628}
            Object.Width           =   7937
            MinWidth        =   7937
         EndProperty
      EndProperty
   End
   Begin VB.PictureBox p
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   1800
      Left            =   180
      Picture         =   "SourcePicture.frx":0000
      ScaleHeight     =   120
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   119
      TabIndex        =   0
      Top             =   360
      Width           =   1785
   End
   Begin MSComDlg.CommonDialog cd
      Left            =   60
      Top             =   120
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      CancelError     =   -1  'True
   End
   Begin VB.Menu mLoad
      Caption         =   "Load picture"
   End
End
Attribute VB_Name = "SourcePicture"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()
    picinfo
End Sub

Private Sub mLoad_Click()
    On Error GoTo Canceled
    cd.ShowOpen
    Set p.Picture = LoadPicture(cd.FileName)
    picinfo
    Exit Sub
Canceled:
End Sub

Private Sub picinfo()
    sb.Panels(1).Text = p.ScaleWidth & " x " & p.ScaleHeight & _
                        "  Disp: " & p.Picture.Width & " x " & p.Picture.Height
End Sub

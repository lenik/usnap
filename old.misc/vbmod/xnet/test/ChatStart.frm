VERSION 5.00
Begin VB.Form frmStart
   Caption         =   "Start"
   ClientHeight    =   2430
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6000
   LinkTopic       =   "Form1"
   ScaleHeight     =   2430
   ScaleWidth      =   6000
   Begin VB.ComboBox lstDriver
      BeginProperty Font
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   555
      ItemData        =   "ChatStart.frx":0000
      Left            =   540
      List            =   "ChatStart.frx":0002
      Style           =   2  'Dropdown List
      TabIndex        =   2
      Top             =   240
      Width           =   4935
   End
   Begin VB.CommandButton btnClient
      Caption         =   "&Client"
      Height          =   1035
      Left            =   3180
      TabIndex        =   1
      Top             =   1080
      Width           =   2235
   End
   Begin VB.CommandButton btnServer
      Caption         =   "&Server"
      Height          =   1035
      Left            =   540
      TabIndex        =   0
      Top             =   1080
      Width           =   2235
   End
End
Attribute VB_Name = "frmStart"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub btnServer_Click()
    frmServer.Show
    Unload Me
End Sub

Private Sub btnClient_Click()
    frmClient.Show
    Unload Me
End Sub

Private Sub Form_Load()
    Dim dn
    For Each dn In XnetDriverNames
        lstDriver.AddItem dn
    Next
    lstDriver.ListIndex = 0

    If DebugMode Then
        Caption = Caption & " [Debug]"
    End If
End Sub

Private Sub lstDriver_Click()
    Set Network = XnetCreate(lstDriver.Text)
End Sub

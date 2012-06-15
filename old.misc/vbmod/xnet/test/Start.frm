VERSION 5.00
Begin VB.Form frmStart
   Caption         =   "Form1"
   ClientHeight    =   2820
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6420
   LinkTopic       =   "Form1"
   ScaleHeight     =   2820
   ScaleWidth      =   6420
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnServer
      Caption         =   "&Server"
      Height          =   1035
      Left            =   600
      TabIndex        =   2
      Top             =   1260
      Width           =   2235
   End
   Begin VB.CommandButton btnClient
      Caption         =   "&Client"
      Height          =   1035
      Left            =   3240
      TabIndex        =   1
      Top             =   1260
      Width           =   2235
   End
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
      ItemData        =   "Start.frx":0000
      Left            =   600
      List            =   "Start.frx":0002
      Style           =   2  'Dropdown List
      TabIndex        =   0
      Top             =   420
      Width           =   4935
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
End Sub

Private Sub lstDriver_Click()
    Set Network = XnetCreate(lstDriver.Text)
End Sub

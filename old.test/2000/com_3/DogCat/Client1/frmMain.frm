VERSION 5.00
Begin VB.Form frmMain
   Caption         =   "Form1"
   ClientHeight    =   4335
   ClientLeft      =   2160
   ClientTop       =   2670
   ClientWidth     =   6390
   LinkTopic       =   "Form1"
   ScaleHeight     =   4335
   ScaleWidth      =   6390
   Begin VB.CommandButton Command7
      Caption         =   "plane crash!"
      Height          =   1275
      Left            =   2895
      TabIndex        =   6
      Top             =   2850
      Width           =   3255
   End
   Begin VB.CommandButton Command6
      Caption         =   "earthquake"
      Height          =   630
      Left            =   3225
      TabIndex        =   5
      Top             =   1635
      Width           =   2865
   End
   Begin VB.CommandButton Command5
      Caption         =   "createobject! CaCat::shout"
      Height          =   690
      Left            =   255
      TabIndex        =   4
      Top             =   2370
      Width           =   2400
   End
   Begin VB.CommandButton Command4
      Caption         =   "createobject! CaDog::shout"
      Height          =   705
      Left            =   255
      TabIndex        =   3
      Top             =   1590
      Width           =   2430
   End
   Begin VB.CommandButton Command3
      Caption         =   "bigDog::shout"
      Height          =   1290
      Left            =   3465
      TabIndex        =   2
      Top             =   135
      Width           =   2595
   End
   Begin VB.CommandButton Command2
      Caption         =   "cat::shout"
      Height          =   570
      Left            =   255
      TabIndex        =   1
      Top             =   840
      Width           =   2970
   End
   Begin VB.CommandButton Command1
      Caption         =   "dog::shout"
      Height          =   570
      Left            =   240
      TabIndex        =   0
      Top             =   150
      Width           =   3030
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim dog As New CaDog
Attribute dog.VB_VarHelpID = -1
Dim cat As New CaCat

Public Sub dog_shouted()
        MsgBox "dog_shouted"
End Sub

Private Sub Command1_Click()
        dog.shout
End Sub

Private Sub Command2_Click()
        cat.catshout
End Sub

Public Function getdog() As CaDog
        Set getdog = New BigDog
End Function

Private Sub Command3_Click()
        getdog.shout
End Sub

Private Sub Command4_Click()
        Dim d As Object
        Set d = CreateObject("CampoAccelerate.CaDog.1")
        d.shout
End Sub

Private Sub Command5_Click()
        Dim d As Object
        Set d = CreateObject("CampoAccelerate.CaCat.1")
        d.shout
End Sub

Private Sub Command6_Click()
        frmEarthquake.Show
End Sub

Private Sub Command7_Click()
        frmPlane.Show
End Sub

Private Sub Form_Load()
        Set dog = New CaDog
End Sub

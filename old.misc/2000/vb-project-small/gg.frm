VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5745
   ClientLeft      =   1905
   ClientTop       =   1860
   ClientWidth     =   6555
   LinkTopic       =   "Form1"
   ScaleHeight     =   5745
   ScaleWidth      =   6555
   Begin VB.ListBox List1
      Height          =   2010
      Left            =   1635
      TabIndex        =   1
      Top             =   3360
      Width           =   3060
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   1620
      Left            =   1545
      TabIndex        =   0
      Top             =   1080
      Width           =   2745
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    TEnumProcess List1
End Sub

VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5745
   ClientLeft      =   1800
   ClientTop       =   1530
   ClientWidth     =   6555
   LinkTopic       =   "Form1"
   ScaleHeight     =   5745
   ScaleWidth      =   6555
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   525
      Left            =   1380
      TabIndex        =   1
      Top             =   1470
      Width           =   1245
   End
   Begin VB.ListBox List1
      Height          =   2595
      Left            =   1245
      TabIndex        =   0
      Top             =   2490
      Width           =   2745
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()

    Dim x As Long

    x = CreateToolhelp32SnapshotA(TH32CS_SNAPALL, 0)
    CLoseHandle (x)

End Sub

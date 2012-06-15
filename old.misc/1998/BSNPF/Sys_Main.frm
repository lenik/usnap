VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3945
   ClientLeft      =   1125
   ClientTop       =   1530
   ClientWidth     =   6690
   LinkTopic       =   "Form1"
   ScaleHeight     =   3945
   ScaleWidth      =   6690
   Begin VB.TextBox Text1
      Height          =   315
      Left            =   780
      TabIndex        =   1
      Text            =   "C:\windows\winver.exe"
      Top             =   540
      Width           =   2295
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   1395
      Left            =   1020
      TabIndex        =   0
      Top             =   1800
      Width           =   2775
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Dim sa_pa As SECURITY_ATTRIBUTES, sa_ta As SECURITY_ATTRIBUTES
  Dim si_si As STARTUPINFO, pi_pi As PROCESS_INFORMATION
  sa_pa.bInheritHandle = False
  sa_ta.bInheritHandle = False
  si_si.wShowWindow = SW_NORMAL
  CreateProcess "WinVersion Utility", Text1.Text, sa_pa, sa_ta, False, 0, Null, "C:\windows", si_si, pi_pi
  'WinExec Text1.Text, SW_NORMAL
End Sub

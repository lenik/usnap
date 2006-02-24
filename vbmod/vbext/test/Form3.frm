VERSION 5.00
Begin VB.Form Form3
   Caption         =   "Form1"
   ClientHeight    =   4350
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6690
   LinkTopic       =   "Form1"
   ScaleHeight     =   4350
   ScaleWidth      =   6690
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4
      Caption         =   "ref"
      Height          =   675
      Left            =   5040
      TabIndex        =   4
      Top             =   3060
      Width           =   1035
   End
   Begin VB.CommandButton Command3
      Caption         =   "Findcontrol"
      Height          =   615
      Left            =   4920
      TabIndex        =   3
      Top             =   1860
      Width           =   1095
   End
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   735
      Left            =   3840
      TabIndex        =   2
      Top             =   540
      Width           =   1215
   End
   Begin VB.CommandButton Command1
      Caption         =   "Load config"
      Height          =   735
      Left            =   840
      TabIndex        =   1
      Top             =   600
      Width           =   1635
   End
   Begin VB.ListBox List1
      Height          =   2400
      Left            =   480
      TabIndex        =   0
      Top             =   1560
      Width           =   3975
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    Dim Name
    Dim value
    List1.Clear
    For Each Name In Application.Attributes
        value = Application.Item(Name)
        List1.AddItem Name & " = " & value
    Next
End Sub

Private Sub Command2_Click()
    MsgBox config.runas
End Sub

Private Sub Command3_Click()
    MsgBox TypeName(FindControl(Me, "Command3"))
End Sub

Private Sub Command4_Click()
    ref(vbxSoftReference, "Hello") = Me
    MsgBox TypeName(ref(vbxSoftReference, "Hello"))
    GarbageCollect
    MsgBox TypeName(ref(vbxSoftReference, "Hello"))
End Sub

Private Sub Form_Load()
    Dim Name As String
    Name = App.EXEName
    If LCase(Right(Name, 4)) = ".exe" Then Name = Left(Name, Len(Name) - 4)
    Application.Name = App.EXEName
    Application.HomeDirectory = App.Path
End Sub

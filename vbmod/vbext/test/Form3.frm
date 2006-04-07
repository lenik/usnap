VERSION 5.00
Begin VB.Form Form3
   Caption         =   "Form3"
   ClientHeight    =   4350
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6690
   LinkTopic       =   "Form1"
   ScaleHeight     =   4350
   ScaleWidth      =   6690
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command7
      Caption         =   "Command7"
      Height          =   615
      Left            =   2760
      TabIndex        =   7
      Top             =   180
      Width           =   795
   End
   Begin VB.CommandButton Command6
      Caption         =   "Command6"
      Height          =   375
      Left            =   480
      TabIndex        =   6
      Top             =   120
      Width           =   1035
   End
   Begin VB.CommandButton Command5
      Caption         =   "FindControls"
      Height          =   495
      Left            =   4980
      TabIndex        =   5
      Top             =   2700
      Width           =   1335
   End
   Begin VB.CommandButton Command4
      Caption         =   "ref"
      Height          =   675
      Left            =   4680
      TabIndex        =   4
      Top             =   3480
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
    Dim name
    Dim value
    List1.Clear
    For Each name In Application.Attributes
        value = Application.Item(name)
        List1.AddItem name & " = " & value
    Next
End Sub

Private Sub Command2_Click()
    MsgBox Config.runas2
End Sub

Private Sub Command3_Click()
    MsgBox TypeName(FindControl(Me, "Command3"))
End Sub

Private Sub Command4_Click()
    Ref(vbxSoftReference, "Hello") = Me
    MsgBox TypeName(Ref(vbxSoftReference, "Hello"))
    GarbageCollect
    MsgBox TypeName(Ref(vbxSoftReference, "Hello"))
End Sub

Private Sub Command5_Click()
    Dim m As Map
    Set m = FindControls(Me)
    Dim name
    For Each name In m.KeySet
        MsgBox name
    Next
End Sub

Private Sub Command6_Click()
    Dim x As Object
    Set x = FindControl(Me, "stuff")
    MsgBox TypeName(x)
End Sub

Private Sub Command7_Click()
    MsgBox Config.hello2
End Sub

Private Sub Form_Load()
    If DebugMode Then
        Dim name As String
        name = App.EXEName
        If LCase(Right(name, 4)) = ".exe" Then name = Left(name, Len(name) - 4)
        Application.name = App.EXEName
        Application.HomeDirectory = App.Path
        Application.Reload
    End If
End Sub

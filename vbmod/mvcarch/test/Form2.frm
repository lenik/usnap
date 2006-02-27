VERSION 5.00
Object = "{529C9DC9-47A3-4A28-AC7B-5A7DBB82E939}#17.0#0"; "MVCArch.ocx"
Begin VB.Form Form2
   Caption         =   "Test State"
   ClientHeight    =   4695
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6405
   LinkTopic       =   "Form1"
   ScaleHeight     =   4695
   ScaleWidth      =   6405
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1
      Caption         =   "ok"
      Height          =   615
      Left            =   180
      TabIndex        =   0
      Top             =   840
      Width           =   1335
   End
   Begin VB.CommandButton Command3
      Caption         =   "restart"
      Height          =   555
      Left            =   180
      TabIndex        =   2
      Top             =   2520
      Width           =   1335
   End
   Begin VB.CommandButton Command2
      Caption         =   "failed"
      Height          =   555
      Left            =   180
      TabIndex        =   1
      Top             =   1680
      Width           =   1335
   End
   Begin VB.Timer Timer1
      Interval        =   1000
      Left            =   240
      Top             =   4140
   End
   Begin MVCArch.GraphCO GraphCO1
      Left            =   900
      Top             =   180
      _ExtentX        =   8916
      _ExtentY        =   7646
      Collapsed       =   0   'False
      ExpandedWidth   =   5055
      ExpandedHeight  =   4335
      Title           =   "Controller"
      Appearance      =   1
      BackColor       =   -2147483633
      BorderStyle     =   0
      ScaleWidth      =   5055
      ScaleMode       =   1
      ScaleHeight     =   4335
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Begin MVCArch.GraphSO soStart
         Height          =   645
         Left            =   840
         TabIndex        =   3
         Top             =   900
         Width           =   780
         _ExtentX        =   1376
         _ExtentY        =   1138
         Transparent     =   0   'False
         FontName        =   "Courier New"
         FontSize        =   9
         FontItalic      =   0   'False
         BackColor       =   16777215
         ForeColor       =   0
         BorderStyle     =   1
         BorderWidth     =   1
         Icon            =   "Form2.frx":0000
         Title           =   "Start"
         ControllerName  =   ""
         Commands        =   1
         Name_0          =   "ok"
         TargetName_0    =   "soPrepare"
         Title_0         =   "ok"
         Default_0       =   -1  'True
         Method_0        =   0
         Visible_0       =   -1  'True
      End
      Begin MVCArch.GraphSO soPrepare
         Height          =   585
         Left            =   1980
         TabIndex        =   4
         Top             =   1860
         Width           =   1080
         _ExtentX        =   1905
         _ExtentY        =   1032
         Transparent     =   0   'False
         FontName        =   "Courier New"
         FontSize        =   9
         FontItalic      =   -1  'True
         BackColor       =   13421772
         ForeColor       =   0
         BorderStyle     =   3
         BorderWidth     =   1
         Icon            =   "Form2.frx":001C
         Title           =   "Prepare"
         ControllerName  =   ""
         Commands        =   2
         Name_0          =   "ok"
         TargetName_0    =   "soSubA"
         Title_0         =   "ok"
         Default_0       =   0   'False
         Method_0        =   0
         Visible_0       =   -1  'True
         Name_1          =   "fail"
         TargetName_1    =   "soSubB"
         Title_1         =   "fail"
         Default_1       =   0   'False
         Method_1        =   0
         Visible_1       =   -1  'True
      End
      Begin MVCArch.GraphSO soSubA
         Height          =   615
         Left            =   960
         TabIndex        =   5
         Top             =   2760
         Width           =   720
         _ExtentX        =   1270
         _ExtentY        =   1085
         Transparent     =   0   'False
         FontName        =   "Courier New"
         FontSize        =   9
         FontItalic      =   0   'False
         BackColor       =   12648384
         ForeColor       =   0
         BorderStyle     =   1
         BorderWidth     =   1
         Icon            =   "Form2.frx":0038
         Title           =   "SubA"
         ControllerName  =   ""
         Commands        =   2
         Name_0          =   "ok"
         TargetName_0    =   "soEnd"
         Title_0         =   "ok"
         Default_0       =   0   'False
         Method_0        =   0
         Visible_0       =   -1  'True
         Name_1          =   "fail"
         TargetName_1    =   "soSubB"
         Title_1         =   "fail"
         Default_1       =   0   'False
         Method_1        =   1
         Visible_1       =   -1  'True
      End
      Begin MVCArch.GraphSO soEnd
         Height          =   615
         Left            =   2160
         TabIndex        =   6
         Top             =   3540
         Width           =   720
         _ExtentX        =   1270
         _ExtentY        =   1085
         Transparent     =   0   'False
         FontName        =   "Courier New"
         FontSize        =   9
         FontItalic      =   0   'False
         BackColor       =   16777215
         ForeColor       =   0
         BorderStyle     =   1
         BorderWidth     =   1
         Icon            =   "Form2.frx":0054
         Title           =   "End"
         ControllerName  =   ""
         Commands        =   1
         Name_0          =   "restart"
         TargetName_0    =   "soStart"
         Title_0         =   "restart"
         Default_0       =   0   'False
         Method_0        =   0
         Visible_0       =   -1  'True
      End
      Begin MVCArch.GraphSO soSubB
         Height          =   615
         Left            =   3420
         TabIndex        =   7
         Top             =   2760
         Width           =   720
         _ExtentX        =   1270
         _ExtentY        =   1085
         Transparent     =   0   'False
         FontName        =   "Courier New"
         FontSize        =   9
         FontItalic      =   0   'False
         BackColor       =   12648447
         ForeColor       =   0
         BorderStyle     =   1
         BorderWidth     =   1
         Icon            =   "Form2.frx":0070
         Title           =   "SubB"
         ControllerName  =   ""
         Commands        =   1
         Name_0          =   "def"
         TargetName_0    =   "soEnd"
         Title_0         =   "def"
         Default_0       =   0   'False
         Method_0        =   0
         Visible_0       =   -1  'True
      End
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    GraphCO1.Process "ok"
End Sub

Private Sub Command2_Click()
    GraphCO1.Process "failed"
End Sub

Private Sub Command3_Click()
    GraphCO1.Process "restart"
End Sub

Private Sub soEnd_Enter(ByVal PreviousState As MVCArch.StateObject)
    MsgBox "Ended"
End Sub

Private Sub soPrepare_Enter(ByVal PreviousState As MVCArch.StateObject)
    MsgBox "Preparing"
End Sub

Private Sub soStart_Enter(ByVal PreviousState As MVCArch.StateObject)
    MsgBox "Started"
End Sub

Private Sub Timer1_Timer()
    If Not GraphCO1.ActiveState Is Nothing Then
        Caption = "Current State: " & GraphCO1.ActiveState.this.Name
    End If
End Sub

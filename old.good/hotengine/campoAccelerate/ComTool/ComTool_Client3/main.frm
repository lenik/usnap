VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6195
   LinkTopic       =   "Form1"
   ScaleHeight     =   213
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   413
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command4
      Caption         =   "Command4"
      Height          =   585
      Left            =   405
      TabIndex        =   6
      Top             =   2250
      Width           =   1755
   End
   Begin VB.CommandButton Command3
      Caption         =   "get type info"
      Height          =   465
      Left            =   2745
      TabIndex        =   5
      Top             =   2340
      Width           =   1830
   End
   Begin VB.CommandButton Command2
      Caption         =   "QueryInterface, then move me left"
      Height          =   855
      Left            =   4125
      TabIndex        =   3
      Top             =   1215
      Width           =   1800
   End
   Begin VB.CommandButton Command1
      Caption         =   "AddRef, then Release me"
      Height          =   795
      Left            =   2685
      TabIndex        =   0
      Top             =   345
      Width           =   1740
   End
   Begin VB.Label Label3
      AutoSize        =   -1  'True
      Caption         =   "QueryInterface returns"
      Height          =   180
      Left            =   570
      TabIndex        =   4
      Top             =   1725
      Width           =   1980
   End
   Begin VB.Label Label2
      AutoSize        =   -1  'True
      Caption         =   "After Release"
      Height          =   180
      Left            =   600
      TabIndex        =   2
      Top             =   1380
      Width           =   1170
   End
   Begin VB.Label Label1
      AutoSize        =   -1  'True
      Caption         =   "After AddRef"
      Height          =   180
      Left            =   615
      TabIndex        =   1
      Top             =   1035
      Width           =   1080
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public t As New CaCTools

Public Function getRef(x As Object) As Long
        Dim ra As Long, rr As Long
        ra = t.forceAddRef(x)
        rr = t.forceRelease(x)
        getRef = rr
End Function

Private Sub Command1_Click()
        t.forceAddRef Command1
        Label1.Caption = getRef(Command1)
        t.forceRelease Command1
        Label2.Caption = getRef(Command1)
End Sub

Private Sub Command2_Click()
        Dim l As Object
        Label1.Caption = getRef(Command2)
        Label3.Caption = t.forceQueryInterface(Command2, "{00020400-0000-0000-C000-000000000046}", l)
        Label1.Caption = getRef(Command2)
        l.Left = l.Left - 4
        Set l = Nothing
        Label2.Caption = getRef(Command2)
End Sub

Private Sub Command3_Click()
        Dim ti As Object
        Set ti = t.forceGetTypeInfo(Command3, 0, 0)
        Set ti = Nothing
End Sub

Private Sub Command4_Click()
        t.forceAddRef Nothing
End Sub

VERSION 5.00
Begin VB.Form frmVariant
   Caption         =   "Form3"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form3"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   615
      Left            =   510
      TabIndex        =   1
      Top             =   585
      Width           =   2430
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   405
      Left            =   2010
      TabIndex        =   0
      Top             =   1725
      Width           =   1950
   End
End
Attribute VB_Name = "frmVariant"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
        Dim v As New OeTVariant
        Dim va As Long, vb As Long
        v = "ABCD"
        v.autoTypeConversion = False
        v.VarType = VARTYPE_I4
        va = v
        v.VarType = VARTYPE_BSTR
        vb = v.longVal
        MsgBox v
End Sub

Private Sub Command2_Click()
        Dim v As New OeTVariant
        v = 1234
        v.VarType = VARTYPE_BSTR

End Sub

VERSION 5.00
Begin VB.Form frmSkewOption
   Caption         =   "������б�Ƕ�"
   ClientHeight    =   1335
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3615
   LinkTopic       =   "Form1"
   ScaleHeight     =   1335
   ScaleWidth      =   3615
   StartUpPosition =   3  '����ȱʡ
   Begin VB.CommandButton Command1
      Caption         =   "ȷ��"
      Height          =   375
      Left            =   2040
      TabIndex        =   2
      Top             =   840
      Width           =   1275
   End
   Begin VB.OptionButton optp45
      Caption         =   "��ת+45��"
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Top             =   120
      Value           =   -1  'True
      Width           =   1575
   End
   Begin VB.OptionButton optn45
      Caption         =   "��ת-45��"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   540
      Width           =   1575
   End
End
Attribute VB_Name = "frmSkewOption"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
        Hide
End Sub

VERSION 5.00
Object = "{529C9DC9-47A3-4A28-AC7B-5A7DBB82E939}#22.1#0"; "mvcarch.ocx"
Begin VB.Form State2_Form1
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin MVCArch.GraphCO GraphCO1
      Left            =   840
      Top             =   300
      _ExtentX        =   5106
      _ExtentY        =   4048
      Collapsed       =   0   'False
      ExpandedWidth   =   2895
      ExpandedHeight  =   2295
      Title           =   "Controller"
      Appearance      =   1
      BackColor       =   -2147483633
      BorderStyle     =   0
      ScaleWidth      =   2895
      ScaleMode       =   1
      ScaleHeight     =   2295
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
   End
End
Attribute VB_Name = "State2_Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub GraphCO1_Started(InitState As MVCArch.GraphSO)
    '
End Sub

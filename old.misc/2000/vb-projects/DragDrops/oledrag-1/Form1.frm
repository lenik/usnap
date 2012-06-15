VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   4875
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5520
   LinkTopic       =   "Form1"
   ScaleHeight     =   4875
   ScaleWidth      =   5520
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox Picture2
      Height          =   1230
      Left            =   2835
      OLEDropMode     =   1  'Manual
      Picture         =   "Form1.frx":0000
      ScaleHeight     =   1170
      ScaleWidth      =   1170
      TabIndex        =   4
      Top             =   2685
      Width           =   1230
   End
   Begin VB.PictureBox Picture1
      Height          =   750
      Left            =   2880
      OLEDropMode     =   1  'Manual
      Picture         =   "Form1.frx":EA72
      ScaleHeight     =   690
      ScaleWidth      =   1095
      TabIndex        =   3
      Top             =   1680
      Width           =   1155
   End
   Begin VB.TextBox Text2
      Height          =   1110
      Left            =   510
      OLEDropMode     =   2  'Automatic
      TabIndex        =   1
      Text            =   "Text2"
      Top             =   1710
      Width           =   2025
   End
   Begin VB.TextBox Text1
      Height          =   1065
      Left            =   405
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   165
      Width           =   2115
   End
   Begin VB.Label Label1
      Caption         =   "Label1"
      Height          =   810
      Left            =   2850
      TabIndex        =   2
      Top             =   555
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Label1_Click()
        Label1.OLEDrag
End Sub

Private Sub Picture1_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        Picture1.OLEDrag
End Sub

Private Sub Picture1_OLEDragDrop(Data As DataObject, Effect As Long, Button As Integer, Shift As Integer, X As Single, Y As Single)
        Set Picture1.Picture = Data.GetData(vbCFBitmap)
End Sub

Private Sub Picture1_OLEStartDrag(Data As DataObject, AllowedEffects As Long)
        Data.SetData Picture1.Picture, vbCFBitmap
        AllowedEffects = vbDropEffectCopy
End Sub

Private Sub Picture2_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        Picture2.OLEDrag

End Sub

Private Sub Picture2_OLEDragDrop(Data As DataObject, Effect As Long, Button As Integer, Shift As Integer, X As Single, Y As Single)
        Set Picture2.Picture = Data.GetData(vbCFBitmap)
End Sub

Private Sub Picture2_OLEStartDrag(Data As DataObject, AllowedEffects As Long)
        Data.SetData Picture2.Picture, vbCFBitmap
        AllowedEffects = vbDropEffectMove
End Sub

Private Sub Text1_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
        If Shift And vbCtrlMask Then
                Text1.Drag
        Else
                Text1.OLEDrag
        End If
End Sub

Private Sub Text2_OLEDragDrop(Data As DataObject, Effect As Long, Button As Integer, Shift As Integer, X As Single, Y As Single)
        Text2 = Data.GetData(vbCFText)
End Sub

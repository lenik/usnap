VERSION 5.00
Begin VB.Form Form2
   Caption         =   "我是你的宝贝"
   ClientHeight    =   2580
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4020
   Icon            =   "Form2.frx":0000
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2580
   ScaleWidth      =   4020
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox Picture1
      AutoSize        =   -1  'True
      BorderStyle     =   0  'None
      Height          =   1500
      Left            =   1560
      Picture         =   "Form2.frx":030A
      ScaleHeight     =   1500
      ScaleWidth      =   1080
      TabIndex        =   1
      Top             =   240
      Width           =   1080
   End
   Begin VB.Label Label1
      Caption         =   "你真小气，我要把你格了！"
      Height          =   375
      Left            =   780
      TabIndex        =   0
      Top             =   2100
      Width           =   2955
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   3915
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6315
   LinkTopic       =   "Form1"
   ScaleHeight     =   3915
   ScaleWidth      =   6315
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton cmd
      Caption         =   "获取当前打包函数打包的菜单描述"
      Height          =   1305
      Left            =   900
      TabIndex        =   1
      Top             =   1635
      Width           =   4440
   End
   Begin VB.TextBox Text1
      Height          =   525
      Left            =   300
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   405
      Width           =   5610
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmd_Click()
        Dim vdesc

        vdesc = encodePart( _
                        "File" + _
                                encodePart("FILE", "|") + _
                                encodePart("1", "|") + _
                                encodePart("2", "|") + _
                        encodePart("Open") + _
                                encodePart("OPEN", "|") + _
                                encodePart("16", "|") + _
                        encodePart("Close") + _
                        encodePart("Exit") _
                        ) + _
                encodePart( _
                        "Edit" + _
                        encodePart("Copy") _
                        )
        Text1 = "vdesc = """ + vdesc + """"
End Sub

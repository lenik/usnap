VERSION 5.00
Object = "{529C9DC9-47A3-4A28-AC7B-5A7DBB82E939}#15.1#0"; "MVCArch.ocx"
Begin VB.Form Form2
   Caption         =   "Test State"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3
      Caption         =   "Command3"
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Top             =   1560
      Width           =   555
   End
   Begin VB.CommandButton Command2
      Caption         =   "Command2"
      Height          =   495
      Left            =   120
      TabIndex        =   1
      Top             =   840
      Width           =   555
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   315
      Left            =   180
      TabIndex        =   0
      Top             =   300
      Width           =   375
   End
   Begin MVCArch.StateControl Cond
      Left            =   1260
      Top             =   1380
      _ExtentX        =   1402
      _ExtentY        =   1296
      Transparent     =   0   'False
      FontName        =   "Courier New"
      FontSize        =   9
      FontItalic      =   0   'False
      BackColor       =   16777215
      ForeColor       =   0
      BorderStyle     =   1
      BorderWidth     =   1
      Icon            =   "Form2.frx":0000
      Title           =   "Cond"
      ControllerName  =   ""
      Commands        =   2
      Name_0          =   "e0"
      TargetName_0    =   "1"
      Title_0         =   "da"
      Default_0       =   0   'False
      Method_0        =   0
      Visible_0       =   -1  'True
      Name_1          =   "gfa"
      TargetName_1    =   "1"
      Title_1         =   "fa"
      Default_1       =   -1  'True
      Method_1        =   1
      Visible_1       =   -1  'True
   End
   Begin MVCArch.StateControl StEnd
      Left            =   3120
      Top             =   1860
      _ExtentX        =   1402
      _ExtentY        =   1402
      Transparent     =   0   'False
      FontName        =   "Courier New"
      FontSize        =   9
      FontItalic      =   0   'False
      BackColor       =   16777215
      ForeColor       =   0
      BorderStyle     =   1
      BorderWidth     =   1
      Icon            =   "Form2.frx":001C
      Title           =   "End"
      ControllerName  =   ""
      Commands        =   1
      Name_0          =   "Nafs"
      TargetName_0    =   "xcvcs"
      Title_0         =   ""
      Default_0       =   0   'False
      Method_0        =   0
      Visible_0       =   -1  'True
   End
   Begin MVCArch.StateControl Init
      Left            =   2400
      Top             =   360
      _ExtentX        =   1508
      _ExtentY        =   1402
      Transparent     =   0   'False
      FontName        =   "Courier New"
      FontSize        =   9
      FontItalic      =   0   'False
      BackColor       =   16777215
      ForeColor       =   0
      BorderStyle     =   1
      BorderWidth     =   1
      Icon            =   "Form2.frx":0038
      Title           =   "Init"
      ControllerName  =   ""
      Commands        =   1
      Name_0          =   "Name0"
      TargetName_0    =   "xcvcs"
      Title_0         =   "53454"
      Default_0       =   -1  'True
      Method_0        =   0
      Visible_0       =   0   'False
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

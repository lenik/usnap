VERSION 5.00
Object = "{79D5D6E9-10F5-4F16-AC63-C1A70BF8EA4C}#12.0#0"; "VBUserExt.ocx"
Begin VB.Form Test_LayoutForm3
   Caption         =   "Form3"
   ClientHeight    =   3075
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form3"
   ScaleHeight     =   3075
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox chkCascade
      Caption         =   "&Cascade"
      Height          =   255
      Left            =   60
      TabIndex        =   6
      Top             =   0
      Width           =   1635
   End
   Begin VBUserExt.AutoScaleLayoutContainer c
      Height          =   2415
      Left            =   420
      TabIndex        =   0
      Top             =   300
      Width           =   3855
      _ExtentX        =   6800
      _ExtentY        =   4260
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ScaleWidth      =   3795
      ScaleMode       =   0
      ScaleHeight     =   1920.745
      Begin VB.Frame Frame1
         Caption         =   "Frame1"
         Height          =   1575
         Left            =   1500
         TabIndex        =   2
         Top             =   660
         Width           =   2175
         Begin VBUserExt.AutoScaleLayoutContainer c2
            Height          =   1095
            Left            =   180
            TabIndex        =   3
            Top             =   300
            Width           =   1755
            _ExtentX        =   3096
            _ExtentY        =   1931
            BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851}
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            ScaleWidth      =   1695
            ScaleMode       =   0
            ScaleHeight     =   1725
            Begin VB.CommandButton Command2
               Caption         =   "Command2"
               Height          =   615
               Left            =   0
               TabIndex        =   5
               Top             =   0
               Width           =   855
            End
            Begin VB.PictureBox Picture1
               Height          =   615
               Left            =   1020
               ScaleHeight     =   555
               ScaleWidth      =   375
               TabIndex        =   4
               Top             =   300
               Width           =   435
            End
         End
      End
      Begin VB.CommandButton Command1
         Caption         =   "Command1"
         Height          =   735
         Left            =   540
         TabIndex        =   1
         Top             =   360
         Width           =   735
      End
   End
End
Attribute VB_Name = "Test_LayoutForm3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Resize()
    On Error Resume Next
    c.Width = ScaleWidth - c.Left * 2
    c.Height = ScaleHeight - c.Top * 2
End Sub


Private Sub c_Resize()
    If chkCascade Then
        ' (After c Relayouted)
        On Error Resume Next
        c2.Width = Frame1.Width - c2.Left * 2
        c2.Height = Frame1.Height - c2.Top * 2
    End If
End Sub

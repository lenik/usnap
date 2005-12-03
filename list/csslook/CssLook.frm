VERSION 5.00
Object = "{683364A1-B37D-11D1-ADC5-006008A5848C}#1.0#0"; "dhtmled.ocx"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmCssLook
   Caption         =   "CSS Look"
   ClientHeight    =   4875
   ClientLeft      =   165
   ClientTop       =   855
   ClientWidth     =   7980
   Icon            =   "CssLook.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   4875
   ScaleWidth      =   7980
   StartUpPosition =   3  'Windows Default
   Begin MSComDlg.CommonDialog ofn
      Left            =   960
      Top             =   180
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      CancelError     =   -1  'True
      DefaultExt      =   "css"
      Filter          =   "Cascaded Style-Sheet (*.css)|*.css|All files (*.*)|*.*||"
   End
   Begin DHTMLEDLibCtl.DHTMLEdit html
      Height          =   615
      Left            =   180
      TabIndex        =   0
      Top             =   180
      Width           =   615
      ActivateApplets =   0   'False
      ActivateActiveXControls=   0   'False
      ActivateDTCs    =   -1  'True
      ShowDetails     =   0   'False
      ShowBorders     =   0   'False
      Appearance      =   1
      Scrollbars      =   -1  'True
      ScrollbarAppearance=   1
      SourceCodePreservation=   -1  'True
      AbsoluteDropMode=   0   'False
      SnapToGrid      =   0   'False
      SnapToGridX     =   50
      SnapToGridY     =   50
      BrowseMode      =   -1  'True
      UseDivOnCarriageReturn=   0   'False
   End
   Begin VB.Menu mFile
      Caption         =   "&File"
      Begin VB.Menu mmOpen
         Caption         =   "&Open..."
         Shortcut        =   ^O
      End
      Begin VB.Menu mm_1
         Caption         =   "-"
      End
      Begin VB.Menu mmWrite
         Caption         =   "&Write mode"
         Shortcut        =   {F2}
      End
      Begin VB.Menu mm_2
         Caption         =   "-"
      End
      Begin VB.Menu mmExit
         Caption         =   "E&xit"
      End
   End
   Begin VB.Menu mHelp
      Caption         =   "&Help"
      Begin VB.Menu mAbout
         Caption         =   "&About"
         Shortcut        =   {F1}
      End
   End
End
Attribute VB_Name = "frmCssLook"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()
    html.Left = 0
    html.Top = 0
End Sub

Private Sub Form_Resize()
    html.Width = Me.ScaleWidth
    html.Height = Me.ScaleHeight
End Sub

Private Sub mAbout_Click()
    frmAbout.Show 1, Me
End Sub

Private Sub mmExit_Click()
    End
End Sub

Private Sub mmOpen_Click()
    On Error GoTo x
    ofn.ShowOpen
    OpenCSS ofn.FileName
x:
End Sub

Public Sub loadHtml(htmlText As String)
    ' save to temp-file if possible.
    'On Error GoTo DontSave
    'FSO.CreateTextFile(tempfile, True).Write htmlText
'DontSave:
    html.DocumentHTML = htmlText
End Sub

Private Sub mmWrite_Click()
    mmWrite.Checked = Not mmWrite.Checked
    html.BrowseMode = Not mmWrite.Checked
End Sub

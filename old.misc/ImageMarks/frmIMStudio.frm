VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.MDIForm frmIMStudio
   BackColor       =   &H8000000C&
   Caption         =   "Image Marks"
   ClientHeight    =   4440
   ClientLeft      =   165
   ClientTop       =   855
   ClientWidth     =   6735
   LinkTopic       =   "MDIForm1"
   StartUpPosition =   3  'Windows Default
   Begin MSComDlg.CommonDialog cd
      Left            =   120
      Top             =   300
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      CancelError     =   -1  'True
   End
   Begin VB.Menu mImage
      Caption         =   "&Image"
      Begin VB.Menu mIOpen
         Caption         =   "&Open"
         Shortcut        =   ^O
      End
      Begin VB.Menu mI_
         Caption         =   "-"
      End
      Begin VB.Menu mIExit
         Caption         =   "E&xit"
      End
   End
   Begin VB.Menu mHelp
      Caption         =   "&Help"
      Begin VB.Menu mHManual
         Caption         =   "&Manual"
         Shortcut        =   {F1}
      End
      Begin VB.Menu mH_
         Caption         =   "-"
      End
      Begin VB.Menu mHAbout
         Caption         =   "&About"
         Shortcut        =   +{F1}
      End
   End
End
Attribute VB_Name = "frmIMStudio"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub MDIForm_Load()
    Dim imf As New IMFDocument
    imf.Create "C:\Media\Picture\国际摄影展\6_35_big.jpg"
    Me.width = imf.View.width + 600
    Me.height = imf.View.height + 1000
End Sub

Private Sub MDIForm_Unload(Cancel As Integer)
    End
End Sub

Private Sub mHAbout_Click()
    frmAbout.Show 1
End Sub

Private Sub mHManual_Click()
    frmHelpUsage.Show 1
End Sub

Public Sub mIOpen_Click()
    Dim path As String
    path = GetPathToOpen("Select image file to open", _
            "All image files (*.imf, *.jpg, *.bmp, *.gif, *.wmf)|*.imf;*.jpg;*.bmp;*.gif;*.wmf|" + _
            "ImageMarks File (*.imf)|*.imf|" + _
            "JPEG Image (*.jpg)|*.jpg|Bitmap (*.bmp)|*.bmp|GIF Image (*.gif)|*.gif|Windows Meta-File (*.wmf)|*.wmf|All files (*.*)|*.*||")
    If path = CANCELED_STRING Then Exit Sub

    Dim imf As IMFDocument

    If UCase(Right(path, 4)) = ".IMF" Then
        ' Load IMF to workspace.
        Set imf = New IMFDocument
        ' ...
        imf.Create path
    Else
        Set imf = New IMFDocument
        imf.Create path
    End If
End Sub

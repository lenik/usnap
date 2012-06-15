VERSION 5.00
Begin VB.Form frmEditor
   Caption         =   "CSS Editor"
   ClientHeight    =   4440
   ClientLeft      =   60
   ClientTop       =   750
   ClientWidth     =   7215
   LinkTopic       =   "Form1"
   ScaleHeight     =   4440
   ScaleWidth      =   7215
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox txtSource
      Height          =   915
      Left            =   300
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   0
      Top             =   360
      Width           =   1035
   End
   Begin VB.Menu mFile
      Caption         =   "&File"
      Begin VB.Menu mmSave
         Caption         =   "&Save"
         Shortcut        =   ^S
      End
      Begin VB.Menu mmRevert
         Caption         =   "&Revert"
         Shortcut        =   {F6}
      End
      Begin VB.Menu mm_1
         Caption         =   "-"
      End
      Begin VB.Menu mmClose
         Caption         =   "&Close"
      End
   End
   Begin VB.Menu mEdit
      Caption         =   "&Edit"
      Begin VB.Menu mmFont
         Caption         =   "&Font..."
      End
      Begin VB.Menu mmColor
         Caption         =   "&Color..."
      End
      Begin VB.Menu mmBackColor
         Caption         =   "&Back Color..."
      End
   End
End
Attribute VB_Name = "frmEditor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim Modified As Boolean

Public FileName As String

Public Property Get Source() As String
    Source = txtSource.Text
End Property

Public Property Let Source(ByVal newValue As String)
    txtSource.Text = newValue
    RefreshLook
End Property

Public Sub RefreshLook()
    LoadCSS txtSource.Text
End Sub

Private Sub Form_Load()
    txtSource.Left = 0
    txtSource.Top = 0
    Modified = False
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
    If Modified Then
        Select Case MsgBox("File changed, save now?", vbYesNoCancel, "File changed")
        Case vbYes
            On Error GoTo SaveError
            FSO.CreateTextFile(FileName, True).Write Source
            On Error GoTo 0
            Modified = False
        Case vbNo
            Modified = False
        Case vbCancel
            Cancel = 1
        End Select
    End If
    Exit Sub

SaveError:
    MsgBox "Can't save to file " & FileName & vbNewLine & Err.Description, vbCritical
    Cancel = 1
End Sub

Private Sub Form_Resize()
    txtSource.Width = Me.ScaleWidth
    txtSource.Height = Me.ScaleHeight
End Sub

Private Sub mmClose_Click()
    Unload Me
End Sub

Private Sub txtSource_Change()
    Modified = True
    RefreshLook
End Sub

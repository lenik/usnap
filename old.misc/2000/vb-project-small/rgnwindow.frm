VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5745
   ClientLeft      =   3075
   ClientTop       =   4725
   ClientWidth     =   6555
   LinkTopic       =   "Form1"
   Picture         =   "rgnwindow.frx":0000
   ScaleHeight     =   5745
   ScaleWidth      =   6555
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim sx As Long, sy As Long, sm As Boolean

Declare Function CreateEllipticRgn Lib "gdi32" (ByVal X1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long) As Long

Declare Function SetWindowRgn Lib "user32" (ByVal hWnd As Long, ByVal hRgn As Long, ByVal bRedraw As Boolean) As Integer

Private Sub Form_Load()
    sm = False
    p = CreateEllipticRgn(0, 0, Me.Width / 15, Me.Height / 15)
    SetWindowRgn Me.hWnd, p, True

End Sub

Private Sub Form_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    sx = X
    sy = Y
    sm = True
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If sm Then
        Me.Left = Me.Left + X - sx
        Me.Top = Me.Top + Y - sy
    End If
End Sub

Private Sub Form_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    sm = False
End Sub

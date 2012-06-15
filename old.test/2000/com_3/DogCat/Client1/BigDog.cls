VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "BigDog"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Implements CaCat
Implements CaDog

Private Sub CaCat_catshout()

End Sub

Public Sub CaCat_shout()
        MsgBox "Big cat!"
End Sub

Private Function CaDog_bornCat() As CaDogCatLib.ICaCat
        Set CaDog_bornCat = New CaCat
End Function

Private Function CaDog_bornDog() As CaDogCatLib.ICaDog
        Set CaDog_bornDog = New CaDog
End Function

Private Sub CaDog_shout()
        MsgBox "Big dog!"
End Sub

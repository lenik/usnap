Attribute VB_Name = "Module1"
Option Explicit

Public IsLocked_ As Boolean
Public LastTimer As Single

Public Property Get IsLocked() As Boolean
        IsLocked = IsLocked_
End Property
Public Property Let IsLocked(ByVal v As Boolean)
        IsLocked_ = v
        If IsLocked_ Then
                If frmThread.sLight.BackColor = &HFF& Then
                        frmThread.sLight.BackColor = &HFF00&
                Else
                        frmThread.sLight.BackColor = &HFF&
                End If
        Else
                frmThread.sLight.BackColor = &HFFFFFF
        End If
End Property

Public Function T1(ByVal param As Long) As Long
        Static i As Long
        i = i + 1
        T1 = i
End Function

Public Function WaitAndInc(ByVal param As Long) As Long
        Dim V1 As Single, V2 As Single

        'While IsLocked: DoEvents: Wend
        IsLocked = True

        V1 = Timer
        While Timer - LastTimer < 1
                DoEvents
        Wend
        V2 = Timer
        LastTimer = Timer

        IsLocked = False

        frmThread.lblCount = Val(frmThread.lblCount) + 1
        WaitAndInc = V2 - V1
End Function

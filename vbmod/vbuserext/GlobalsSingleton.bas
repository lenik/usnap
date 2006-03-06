Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Private Const LOCATION                  As String = "VBUserExt::GlobalsSingleton"


' CreateAnimateSteps(
'       file1 [ ,delay [ ,effects ] ],
'       file2 ...
' )
Public Function CreateAnimateSteps(ByVal args) As AnimateStep
    Dim FirstStep As AnimateStep
    Dim Current As AnimateStep
    Dim State As Integer                ' 0: filename,  1: delay,  2: effects
    Dim i As Integer
    State = 0
    If StringP(args) Then
        Dim sargs
        sargs = Split(Mid(args, 2), Left(args, 1))
        ReDim args(LBound(sargs) To UBound(sargs))
        For i = LBound(args) To UBound(args)
            If IsNumeric(sargs(i)) Then
                args(i) = Val(sargs(i))
            Else
                args(i) = sargs(i)
            End If
        Next
    End If
    For i = LBound(args) To UBound(args)
        If StringP(args(i)) Then
            ' Filename
            If Current Is Nothing Then
                Set Current = New AnimateStep
                Set FirstStep = Current
            Else
                Set Current.NextStep = New AnimateStep
                Set Current = Current.NextStep
            End If
            Current.Filename = args(i)
            State = 1
        Else
            If State = 0 Then
                ' Filename
                ' Assert IsString(args(i))
                Unexpected "Invalid filename at argument " & i, LOCATION
            ElseIf State = 1 Then
                ' Delay -or- Filename
                If NumberP(args(i)) Then
                    Current.Delay = CSng(Val(args(i)))
                Else
                    ' Assert IsString(args(i))
                    Unexpected "Invalid filename at argument " & i, LOCATION
                End If
                State = 2
            ElseIf State = 2 Then
                ' Effects -or- Filename
                If NumberP(args(i)) Then
                    Current.Effects = CInt(Val(args(i)))
                Else
                    ' Assert IsString(args(i))
                    Unexpected "Invalid filename at argument " & i, LOCATION
                End If
                State = 0
            End If
        End If
    Next
    Set CreateAnimateSteps = FirstStep
End Function

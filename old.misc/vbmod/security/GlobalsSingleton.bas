Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Public Function ConnectPKIRegistry(ByVal ClientKey As String) As PKIRegistry
    Dim r As New PKIRegistry
    r.ClientKey = ClientKey
    Set ConnectPKIRegistry = r
End Function

Public Property Get Secret(Optional ByVal MinLen As String = 4, _
                           Optional ByVal MaxLen As String = 30) As String
    Dim Consonnants As String
    Dim Vowels As String
    Dim i As Integer
    Dim Name As String

    If MaxLen < 1 Then Exit Property

    Consonnants = "bcdglmnprstvwyz"
    Vowels = "aeiou"

    Do
        For i = 1 To Rnd * 2 + 1
            Name = Name & Mid(Consonnants, Rnd * Len(Consonnants) + 1, 1) & Mid(Vowels, Rnd * (Len(Vowels) - 1) + 1, 1)
        Next i
    Loop Until Len(Name) > 2

    If Len(Name) = 3 And Int(Rnd * 3) = 0 Then Name = Name & Name
    If Len(Name) = 3 And Int(Rnd * 3) = 0 Then Name = Mid(Name, 3, 1) & Mid(Name, 2, 1) & Name
    Name = UCase(Left(Name, 1)) + Trim(Mid(Name, 2))
    If Len(Name) > 4 And Int(Rnd * 3) = 0 Then Name = Left(Name, Len(Name) - 1)
    i = Int(Rnd * 3)
    If Len(Name) > 4 And Int(Rnd * 15) = 0 Then Name = Left(Name, 1 + i) & "-" & Mid(Name, 3 + i)
    If Len(Name) < 7 And Int(Rnd * 15) = 0 Then Name = Name & Mid(" Jr. Sr.ssonson boy girlman manndude2000 2.0oo   #1 ", Int(Rnd * 13) * 4 + 1, 4)
    If Len(Name) < 7 And Int(Rnd * 15) = 0 Then Name = Trim(Mid("Dr. Mr. Ms. Joe ", Int(Rnd * 4) * 4 + 1, 4)) & " " & Name

    Secret = Trim(Name)

    If Len(Secret) = MinLen - 1 Then
        ' if concat with another secret may get a space, so re-generate it
        Secret = Secret(MinLen, MaxLen)
    ElseIf Len(Secret) < MinLen Then
        Secret = Secret & " " & Secret(MinLen - Len(Secret) - 1, MaxLen - Len(Secret) - 1)
    End If

    If Len(Secret) >= MaxLen Then
        Secret = Left(Secret, MaxLen)
        If Right(Secret, 1) = " " Then
            Secret = Left(Secret, Len(Secret) - 1) & "."
        End If
    End If
End Property

Attribute VB_Name = "modFunctions"
Declare Function GetCurrentDirectory Lib "kernel32" Alias "GetCurrentDirectoryA" (ByVal nBufferLength As Long, ByVal lpBuffer As String) As Long

Function XorString(Source As String) As String
  Dim XoredString As String
  Dim XS_C As Integer
  XoredString = ""
  For XS_C = 1 To Len(Source)
    XoredString = XoredString + Chr$(Asc(Mid$(Source, XS_C, 1)) Xor XorValue)
  Next XS_C
  XorString = XoredString
End Function

' Get record and return the translated password
Function GetR(ByVal FileNo As Long, ByRef UserBuf As UserRecord) As String
  On Error Resume Next
  Get #FileNo, , UserBuf
  UserBuf.Password = XorString(UserBuf.Password)
  GetR = UserBuf.Name
End Function

Function FReadIn(WhichForm As frmMain) As Boolean
  Dim s As String
  Dim l As Long, ll As Long
  Dim MI As Integer

  On Error GoTo ErrReadIn
  na = FreeFile
  Open DataDir + ClassDataFile For Input As na
  MaxClass = 0

  '  class, <caption>, <x>, <y>, <width>, <height>
  '     item, <filename>, <printname>, <iconfile>, <x>, <y>
  '     item...
  '  class...

  While Not EOF(na)
    Input #na, s
    Select Case LCase(Trim(s))
      Case "class":
        Input #na, s    ' caption
        If MaxClass < PClassMax Then
          WhichForm.PClass(MaxClass).MaxItem = 0
          WhichForm.PClass(MaxClass).Caption = s
          Input #na, l: WhichForm.PClass(MaxClass).Left = l * 15
          Input #na, l: WhichForm.PClass(MaxClass).Top = l * 15
          Input #na, l: WhichForm.PClass(MaxClass).SetWidth l * 15
          Input #na, l: WhichForm.PClass(MaxClass).SetHeight l * 15
          WhichForm.PClass(MaxClass).Visible = True
          MaxClass = MaxClass + 1
        Else
          MsgBox "too many classes!"
        End If
      Case "item":
        Input #na, s    ' name
        MI = WhichForm.PClass(MaxClass - 1).MaxItem
        If MI < PItemMax Then
          WhichForm.PClass(MaxClass - 1).SetAlias MI, s
          Input #na, s: WhichForm.PClass(MaxClass - 1).SetName MI, s
          Input #na, s: WhichForm.PClass(MaxClass - 1).SetIconName MI, s
          Input #na, l, ll: WhichForm.PClass(MaxClass - 1).SetXY MI, l * 15, ll * 15
          WhichForm.PClass(MaxClass - 1).Show MI
          WhichForm.PClass(MaxClass - 1).MaxItem = MI + 1
        Else
          MsgBox "too many items"
        End If
    End Select
  Wend
  Close #na

  FReadIn = True
  Exit Function
ErrReadIn:
  Close #na
  FReadIn = False
End Function

Function FSave(WhichForm As frmMain) As Boolean
  Dim I As Integer, J As Integer

  'On Error GoTo ErrSave
  na = FreeFile
  Open DataDir + ClassDataFile For Output As na

  For I = 0 To MaxClass - 1
    If WhichForm.PClass(I).Visible = True Then
      Print #na, "Class, "; WhichForm.PClass(I).Caption; ", ";
      Print #na, WhichForm.PClass(I).Left / 15; ", "; WhichForm.PClass(I).Top / 15; ", ";
      Print #na, WhichForm.PClass(I).Width / 15; ", "; WhichForm.PClass(I).Height / 15

      For J = 0 To WhichForm.PClass(I).MaxItem - 1
        If WhichForm.PClass(I).GetItemVisible(J) = True Then
            Print #na, "  Item, "; WhichForm.PClass(I).GetAlias(J);   'Filename
            Print #na, ", "; WhichForm.PClass(I).GetName(J);          'Printname
            Print #na, ", "; WhichForm.PClass(I).GetIconName(J);
            Print #na, ", "; WhichForm.PClass(I).GetX(J) / 15;
            Print #na, ", "; WhichForm.PClass(I).GetY(J) / 15
        End If
      Next J
    End If
  Next I
  Close #na

  FSave = True
  Exit Function
ErrSave:
  Close #na
  FSave = False

End Function

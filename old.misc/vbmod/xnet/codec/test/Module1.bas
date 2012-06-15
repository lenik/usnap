Attribute VB_Name = "Module1"
Option Explicit

Public Function encodeVar(ByVal v As Variant) As Byte()
    Dim st As New Statement
    st.Add v
    encodeVar = st.Encode
End Function

Public Function envar(ByVal v As Variant) As String
    Dim b() As Byte
    b = encodeVar(v)
    envar = BytesToString(b)
    envar = "<" & envar & ">"
    envar = envar & " " & LBound(b) & "-" & UBound(b)
End Function

Public Function Native(ByVal s As String) As String
    Native = StringToBytes(s)
End Function

Public Function t1() As String
    Dim st As New Statement
    st.Add CByte(Asc("X"))
    st.Add Native("MSG")
    st.Add Native(".12..")

    t1 = BytesToString(st.Encode)
End Function

Public Function t2(Optional ByVal msg As Boolean = True) As String
    Dim buf As New InputBuffer
    Dim st As Statement

    ' Xmsg 12 "What\"ever" "Hello, World!" Last;
    ' ---- -- ------------ --------------- ----

    buf.AddBytes StringToBytes( _
        "Xmsg 12 ""What\""ever"" ""Hello, World!"" Last; " + vbNewLine + _
        "Ynew 345 ""What\""ever"" ""Hello, World!"" Last;")

    Dim i
    i = 0
    While buf.StatementReady
        i = i + 1
        Set st = buf.GetStatement
        If msg Then
            MsgBox "[" & i & "]:" & BytesToString(st.Encode)
        End If
    Wend

End Function

Public Sub lot2()
    Dim tt As Long
    For tt = 0 To 100000
        t2 False
        If tt Mod 10 = 0 Then Debug.Print ".";
        If tt Mod 1000 = 0 Then Debug.Print
    Next
End Sub

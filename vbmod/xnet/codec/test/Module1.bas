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

Public Function t1() As String
    Dim st As New Statement
    st.Add CByte(Asc("X"))
    st.Add StringToBytes("MSG")
    t1 = BytesToString(st.Encode)
End Function

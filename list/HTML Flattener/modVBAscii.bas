Attribute VB_Name = "modVBAscii"
Option Explicit


Public Function CreateAscii(vbstr As String) As Long
    Dim buf, buflen

    WideCharToMultiByte _
        0, _
        0, _
        vbstr, _
        Len(vbstr), _
        buf, _
        buflen, _
        Null, _
        0
End Function


Public Sub FreeAscii(ByVal handle As Long)

End Sub


Public Function ToVbstr(ByVal handle As Long) As String

End Function

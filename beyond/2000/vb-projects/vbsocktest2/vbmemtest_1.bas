Attribute VB_Name = "Module1"


Declare Function toNETRESOURCE Lib "LowTool" Alias "returnValue" (ByVal addr As Long) As NETRESOURCE

Declare Function getmbi Lib "scomp.dll" Alias "stream_comp_mbcs_get_element" (ByVal str As String, ByVal index As Integer) As Long
Public s1 As String * 40

Public l1 As Long

Sub ks()
    Dim a, b, c
    a = 1
    b = 2
    critical
    c = a + b
End Sub

Function mbi(ByVal str As String, ByVal index As Integer) As String
        mbi = Chr(getmbi(str, index))
End Function

Attribute VB_Name = "Module1"
Option Explicit

Public st As New SAOT

Public Property Get serials() As String
    Dim n, i, x
    n = st.SlotAllocated
    For i = 0 To n - 1
        If serials <> "" Then serials = serials & " "
        x = st.FindSlot(i)
        If x < 0 Then x = " "
        serials = serials & x
    Next
End Property

Function arrayinfo(arr, Optional delim = " ")
    Dim i, s
    For i = LBound(arr) To UBound(arr)
        If s <> "" Then s = s & delim
        s = s & arr(i)
    Next
    arrayinfo = "Array(" & TypeName(arr) & ")=" & s
End Function

Public Sub test1()
    st.Append 10            ' 0 1 2 3 4 5 6 7 8 9
    Debug.Print serials
    st.Remove 5             ' 0 1 2 3 4   5 6 7 8
    Debug.Print serials
    st.Remove 6             ' 0 1 2 3 4   5   6 7
    Debug.Print serials
    st.Insert 3             ' 0 1 2 4 5 3 6   7 8
    Debug.Print serials     '<0 1 2 3 4 5 6 7 8 9>

    Dim sorted
    sorted = st.SortSlots   ' 0 1 2 5 3 4 6 8 9 -
    Debug.Print arrayinfo(sorted)
End Sub

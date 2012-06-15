Attribute VB_Name = "Module1"
Option Explicit

Type DOG
        a As Integer
        b As Long
        c As String
End Type

Type Sss
        i As Integer
        l1 As Long
        l2 As Long
End Type

Declare Function toDOG Lib "LowTool" Alias "returnValue" (ByVal rectAddr As Long) As DOG
Declare Function vv1 Lib "LowTool" Alias "vbtType" () As Sss


Public d1 As DOG
Public d2 As DOG

Public Sub sd()
        d1.a = &H1234&
        d1.b = &H55667788
        d1.c = "Hello, world!"
End Sub

Public Function adog() As DOG
        d1.a = &H1234&
        d1.b = &H55667788
        adog = toDOG(getAnyPointer(d1))
End Function

Public Function dp() As Long
        dp = getAnyPointer(d1)
End Function

Public Function copydog(adog1 As DOG) As DOG
        copyBytes getAnyPointer(copydog), getAnyPointer(adog1), _
                        Len(adog1)
End Function

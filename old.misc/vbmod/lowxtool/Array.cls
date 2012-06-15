VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Array"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private opString As New LowXTool.String

Public Function InitArray1i(array1() As Integer, ByVal strInitialize As String, Optional ByVal initNum As Long = -1, Optional ByVal optionBase As Long = 0) As Long
        Dim nInited As Long, ps As String
        nInited = 0

        On Error GoTo xexit

        Do While nInited < initNum Or initNum < 0
                ps = opString.decodePart(strInitialize, nInited, False, ",", True)
                If Trim(ps) = "" Then Exit Do
                array1(optionBase + nInited) = ps
                nInited = nInited + 1
        Loop
xexit:
        InitArray1i = nInited
End Function

Public Function InitArray1l(array1() As Long, ByVal strInitialize As String, Optional ByVal initNum As Long = -1, Optional ByVal optionBase As Long = 0) As Long
        Dim nInited As Long, ps As String
        nInited = 0

        On Error GoTo xexit

        Do While nInited < initNum Or initNum < 0
                ps = opString.decodePart(strInitialize, nInited, False, ",", True)
                If Trim(ps) = "" Then Exit Do
                array1(optionBase + nInited) = ps
                nInited = nInited + 1
        Loop
xexit:
        InitArray1l = nInited
End Function

Public Function InitArray1f(array1() As Single, ByVal strInitialize As String, Optional ByVal initNum As Long = -1, Optional ByVal optionBase As Long = 0) As Long
        Dim nInited As Long, ps As String
        nInited = 0

        On Error GoTo xexit

        Do While nInited < initNum Or initNum < 0
                ps = opString.decodePart(strInitialize, nInited, False, ",", True)
                If Trim(ps) = "" Then Exit Do
                array1(optionBase + nInited) = ps
                nInited = nInited + 1
        Loop
xexit:
        InitArray1f = nInited
End Function

Public Function InitArray1d(array1() As Double, ByVal strInitialize As String, Optional ByVal initNum As Long = -1, Optional ByVal optionBase As Long = 0) As Long
        Dim nInited As Long, ps As String
        nInited = 0

        On Error GoTo xexit

        Do While nInited < initNum Or initNum < 0
                ps = opString.decodePart(strInitialize, nInited, False, ",", True)
                If Trim(ps) = "" Then Exit Do
                array1(optionBase + nInited) = ps
                nInited = nInited + 1
        Loop
xexit:
        InitArray1d = nInited
End Function

Public Function InitArray2i(xarray() As Integer, ByVal strInitialize As String, Optional ByVal initNum As Long = -1, Optional ByVal optionBase As Long = 0) As Long
        Dim nInited As Long
        Dim ps0 As String, ps1 As String
        Dim scan0 As Long, scan1 As Long
        nInited = 0

        'on error goto xexit
        scan0 = optionBase
        Do While nInited < initNum Or initNum < 0
                ps0 = opString.decodePart(strInitialize, scan0, False, ";", True)
                If Trim(ps0) = "" Then Exit Do
                scan1 = optionBase
                Do While nInited < initNum Or initNum < 0
                        ps1 = opString.decodePart(ps0, scan1, False, ",", True)
                        If Trim(ps1) = "" Then Exit Do
                        xarray(scan0, scan1) = ps1
                        nInited = nInited + 1
                        scan1 = scan1 + 1
                        nInited = nInited + 1
                Loop
                scan0 = scan0 + 1
        Loop
xexit:
        InitArray2i = nInited
End Function

Public Function InitArray2f(xarray() As Single, ByVal strInitialize As String, Optional ByVal initNum As Long = -1, Optional ByVal optionBase As Long = 0) As Long
        Dim nInited As Long
        Dim ps0 As String, ps1 As String
        Dim scan0 As Long, scan1 As Long
        nInited = 0

        'on error goto xexit
        scan0 = optionBase
        Do While nInited < initNum Or initNum < 0
                ps0 = opString.decodePart(strInitialize, scan0, False, ";", True)
                If Trim(ps0) = "" Then Exit Do
                scan1 = optionBase
                Do While nInited < initNum Or initNum < 0
                        ps1 = opString.decodePart(ps0, scan1, False, ",", True)
                        If Trim(ps1) = "" Then Exit Do
                        xarray(scan0, scan1) = ps1
                        nInited = nInited + 1
                        scan1 = scan1 + 1
                        nInited = nInited + 1
                Loop
                scan0 = scan0 + 1
        Loop
xexit:
        InitArray2f = nInited
End Function

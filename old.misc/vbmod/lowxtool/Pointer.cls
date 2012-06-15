VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Pointer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True

Public Function returnIDFunc() As Long: returnIDFunc = modVBTool01.returnIDFunc: End Function
Public Function returnHandle() As Long: returnHandle = modVBTool01.returnHandle: End Function
Public Function toByte(ByVal valData As Long) As Byte: toByte = modVBTool01.toByte(valData): End Function
Public Function toWord(ByVal valData As Long) As Integer: toWord = modVBTool01.toWord(valData): End Function
Public Function toLong(ByVal valData As Long) As Long: toLong = modVBTool01.toLong(valData): End Function
Public Function toStr(ByVal valData As Long) As String: toStr = modVBTool01.toStr(valData): End Function

Public Function pAny(refData) As Long: pAny = modVBTool01.pAny(refData): End Function
Public Function pByte(ByRef refByte As Byte) As Long: pByte = modVBTool01.pByte(refData): End Function
Public Function pWord(ByRef refWord As Integer) As Long: pWord = modVBTool01.pWord(refData): End Function
Public Function pLong(ByRef refLong As Long) As Long: pLong = modVBTool01.pLong(refData): End Function

Public Function pStr(ByVal lpstring As String) As Long: pStr = modVBTool01.pStr(lpstring): End Function

Public Function ppStr(ByRef refString As String) As Long: ppStr = modVBTool01.ppStr(refString): End Function
Public Function pFunc(ByVal lpPointer As Long) As Long: pFunc = modVBTool01.pFunc(lpPointer): End Function

' MIDDLE LEVEL MEMORY OPERATION
Public Function returnByte(ByVal base As Long, ByVal offset As Long) As Byte
        returnByte = modVBTool01.returnByte(base, offset)
End Function
Public Function returnWord(ByVal base As Long, ByVal offset As Long) As Integer
        returnWord = modVBTool01.returnWord(base, offset)
End Function
Public Function returnLong(ByVal base As Long, ByVal offset As Long) As Long
        returnLong = modVBTool01.returnLong(base, offset)
End Function
Public Function returnNByte(ByVal base As Long, ByVal offset As Long) As Byte
        returnNByte = modVBTool01.returnNByte(base, offset)
End Function
Public Function returnNWord(ByVal base As Long, ByVal offset As Long) As Integer
        returnNWord = modVBTool01.returnNWord(base, offset)
End Function
Public Function returnNLong(ByVal base As Long, ByVal offset As Long) As Long
        returnNLong = modVBTool01.returnNLong(base, offset)
End Function

Public Function forceByte(ByVal base As Long, ByVal offforce As Long, ByVal vByte As Byte) As Byte
        forceByte = modVBTool01.forceByte(base, offforce, vByte)
End Function
Public Function forceWord(ByVal base As Long, ByVal offforce As Long, ByVal vWord As Integer) As Integer
        forceWord = modVBTool01.forceWord(base, offforce, vWord)
End Function
Public Function forceLong(ByVal base As Long, ByVal offforce As Long, ByVal vLong As Long) As Long
        forceLong = modVBTool01.forceLong(base, offforce, vLong)
End Function
Public Function forceNByte(ByVal base As Long, ByVal offforce As Long, ByVal vByte As Byte) As Byte
        forceNByte = modVBTool01.forceNByte(base, offforce, vByte)
End Function
Public Function forceNWord(ByVal base As Long, ByVal offforce As Long, ByVal vWord As Integer) As Integer
        forceNWord = modVBTool01.forceNWord(base, offforce, vWord)
End Function
Public Function forceNLong(ByVal base As Long, ByVal offforce As Long, ByVal vLong As Long) As Long
        forceNLong = modVBTool01.forceNLong(base, offforce, vLong)
End Function

' VB STRING TOOLS
Public Function getStringLengthA(ByVal lpstring As String) As Long
        getStringLengthA = modVBTool01.getStringLengthA(lpstring)
End Function
Public Function getStringLengthW(ByVal lpstring As String) As Long
        getStringLengthW = modVBTool01.getStringLengthW(lpstring)
End Function
Public Function getStringLengthM(ByVal lpstring As String) As Long
        getStringLengthM = modVBTool01.getStringLengthM(lpstring)
End Function

Public Function copyBytes(ByVal pDest As Long, ByVal pSrc As Long, Optional ByVal nCount As Long = 1) As Long
        copyBytes = modVBTool01.copyBytes(pDest, pSrc, nCount)
End Function
Public Function copyAny(ByRef pDest, ByRef pSrc, ByVal nCount As Long) As Long
        copyAny = modVBTool01.copyAny(pDest, pSrc, nCount)
End Function

' ADVANCE VB CALLBACK

Public Function callFunction0(ByVal lpCallback As Long) As Long
        callFunction0 = modVBTool01.callFunction0(lpCallback)
End Function
Public Sub callProcedure0(ByVal lpCallback As Long)
        modVBTool01.callProcedure0 lpCallback
End Sub
Public Function callFunction1(ByVal lpCallback As Long, ByVal parameter1 As Long) As Long
        callFunction1 = modVBTool01.callFunction1(lpCallback, parameter1)
End Function
Public Sub callProcedure1(ByVal lpCallback As Long, ByVal parameter1 As Long)
        modVBTool01.callProcedure1 lpCallback, parameter1
End Sub
Public Function callFunction2(ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long) As Long
        callFunction2 = modVBTool01.callFunction2(lpCallback, parameter1, parameter2)
End Function
Public Sub callProcedure2(ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long)
        modVBTool01.callProcedure2 lpCallback, parameter1, parameter2
End Sub
Public Function callFunction3(ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long) As Long
        callFunction3 = modVBTool01.callFunction3(lpCallback, parameter1, parameter2, parameter3)
End Function
Public Sub callProcedure3(ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long)
        modVBTool01.callProcedure3 lpCallback, parameter1, parameter2, parameter3
End Sub
Public Function callFunction4(ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long, ByVal parameter4 As Long) As Long
        callFunction4 = modVBTool01.callFunction4(lpCallback, parameter1, parameter2, parameter3, parameter4)
End Function
Public Sub callProcedure4(ByVal lpCallback As Long, ByVal parameter1 As Long, ByVal parameter2 As Long, ByVal parameter3 As Long, ByVal parameter4 As Long)
        modVBTool01.callProcedure4 lpCallback, parameter1, parameter2, parameter3, parameter4
End Sub

Public Function callPascal(ByVal lpCallback As Long, ByVal vaCount As Long, ByVal extra_release As Long, ByVal pva As Long) As Long
        callPascal = modVBTool01.callPascal(lpCallback, vaCount, extra_release, pva)
End Function
Public Function callCdecl(ByVal lpCallback As Long, ByVal vaCount As Long, ByVal extra_release As Long, ByVal pva As Long) As Long
        callCdecl = modVBTool01.callCdecl(lpCallback, vaCount, extra_release, pva)
End Function


' LANGUAGE EXTENSION
Public Function dwAdd(ByVal A As Long, ByVal b As Long) As Long: dwAdd = modVBTool01.dwAdd(A, b): End Function
Public Function dwSub(ByVal A As Long, ByVal b As Long) As Long: dwSub = modVBTool01.dwSub(A, b): End Function
Public Function dwMul(ByVal A As Long, ByVal b As Long) As Long: dwMul = modVBTool01.dwMul(A, b): End Function
Public Function dwDiv(ByVal A As Long, ByVal b As Long) As Long: dwDiv = modVBTool01.dwDiv(A, b): End Function
Public Function dwShl(ByVal A As Long, ByVal b As Long) As Long: dwShl = modVBTool01.dwShl(A, b): End Function
Public Function dwShr(ByVal A As Long, ByVal b As Long) As Long: dwShr = modVBTool01.dwShr(A, b): End Function


' KERNEL DEBUG
Public Sub Critical(): modVBTool01.Critical: End Sub

' USER EXTEND
Public Function catchMessage(ByVal hwnd As Long, ByVal switchprocProc As Long) As Long
        catchMessage = modVBTool01.catchMessage(hwnd, switchprocProc)
End Function
Public Function chainMessage(ByVal wndproc As Long, ByVal hwnd As Long, ByVal message As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
        chainMessage = modVBTool01.chainMessage(wndproc, hwnd, message, wParam, lParam)
End Function

' ActiveVBTool test

Public Sub About()
        frmAbout.Show 1
End Sub

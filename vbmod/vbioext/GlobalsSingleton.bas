Attribute VB_Name = "GlobalsSingleton"
Option Explicit

Private Const LOCATION                  As String = "VBIOExt::GlobalsSingleton"

Public g_Cached As New Cached

Public PF As New PathFunctions
Public BU As New BinaryUtilities

Public Function GetErrorString(ByVal e As Long) As String
    Dim Buffer As String * 1024
    Dim l As Long
    l = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, e, 0, Buffer, 1024, 0)

    Dim z As Long
    z = InStr(Buffer, Chr(0))
    If z > 0 Then
        GetErrorString = Left(Buffer, z - 1)
    Else
        GetErrorString = Buffer
    End If
End Function

Public Function DirName(ByVal Path As String) As String
    Dim pos As Integer
    pos = Max(InStrRev(Path, "\"), InStrRev(Path, "/"))

    If pos > 0 Then
        DirName = Left(Path, pos - 1)
    Else
        DirName = "."
    End If
End Function

Public Function BaseName(ByVal Path As String) As String
    Dim pos As Integer
    pos = Max(InStrRev(Path, "\"), InStrRev(Path, "/"))

    If pos > 0 Then
        BaseName = Mid(Path, pos + 1)
    Else
        BaseName = Path
    End If
End Function

Public Function MakeParents(ByVal Path As String) As Integer
    Dim i As Integer
    Dim Folder As String
    Dim Makes As Integer
    Dim Fails As Integer
    i = 0
    Do
        i = InStr(i + 1, Path, "\")
        If i <= 0 Then Exit Do
        Folder = Left(Path, i - 1)
        If Folder <> "" And Not FSO.FolderExists(Folder) Then
            On Error Resume Next
                FSO.CreateFolder Folder
            On Error GoTo 0
            If FSO.FolderExists(Folder) Then
                Makes = Makes + 1
            Else
                Fails = Fails + 1
            End If
        End If
    Loop

    If Makes = 0 And Fails > 0 Then
        MakeParents = -1
    Else
        MakeParents = Makes
    End If
End Function

Public Function MakeDirectories(ByVal Path As String) As Integer
    If Right(Path, 1) <> "\" Then
        Path = Path & "\"
    End If
    MakeDirectories = MakeParents(Path)
End Function

Public Sub SHFree(ByVal p As Long)
    Dim pMalloc As IVBMalloc
    SHGetMalloc pMalloc
    pMalloc.Free p
End Sub

Public Function BrowseForFolder(Optional ByVal Title As String, _
                                Optional ByVal hWndParent As Long = 0) As String
    Dim bi As BROWSEINFO
    Dim l As Long
    Dim Title1() As Byte
    Dim Path1(0 To 1000) As Byte
    Dim DispName As String

    Title1 = StringToBytes(Title)
    bi.lpszTitle = VarPtr(Title1(0))
    bi.pszDisplayName = VarPtr(Path1(0))
    bi.hwndOwner = hWndParent
    bi.ulFlags = BIF_EDITBOX Or BIF_RETURNONLYFSDIRS Or BIF_STATUSTEXT
    l = SHBrowseForFolder(bi)
    If l <> 0 Then
'        ' l -> { ushort cb, char id[] }
'        Dim cb As Integer
'        LP.Base = l
'        cb = LP.Word(0)
'        LM.CopyBytes VarPtr(Path1(0)), l + 0, cb + 20
'        BrowseForFolder = BytesToString(LeftBytes(Path1, cb - 1))
'        SHFree l
        Dim Path As String * 1000
        l = SHGetPathFromIDList(l, Path)
        l = InStr(Path, Chr(0))
        BrowseForFolder = Left(Path, l - 1)

        DispName = BytesToString(Path1)
        l = InStr(DispName, Chr(0))
        DispName = Left(DispName, l - 1)
    End If
End Function

Public Function ReadTextFile(ByVal Path As String, Optional ByVal Default As String) As String
    Dim ts As TextStream
    Set ts = FSO.OpenTextFile(Path, ForReading, False)
    If ts Is Nothing Then
        ReadTextFile = Default
    Else
        ReadTextFile = ts.ReadAll
    End If
End Function

Public Function ReadBinaryFile(ByVal Path As String, Optional ByVal Default As String) As String
    On Error GoTo fail
    Dim bin As New base64
    bin.ReadFile Path
    ReadBinaryFile = bin.GetBase64
    Exit Function
fail:
    ReadBinaryFile = Default
End Function

Public Function TextToBinary(ByVal Text As String, Optional ByVal Encoding As String = "gb2312") As String
    Dim bin As New base64
    bin.SetString Text, Encoding
    TextToBinary = bin.GetBase64
End Function

Public Function BinaryToText(ByVal base64 As String, Optional ByVal Encoding As String = "gb2312") As String
    Dim bin As New base64
    bin.SetBase64 base64
    BinaryToText = bin.GetString(Encoding)
End Function

Public Function BinaryToPicture(ByVal base64 As String, Optional Size, Optional ColorDepth, Optional X, Optional Y) As StdPicture
    Dim bin As New base64
    Dim temppath As String
    temppath = Application.TemporaryPath("pic")
    bin.SetBase64 base64
    bin.WriteFile temppath
    Set BinaryToPicture = LoadPicture(temppath, Size, ColorDepth, X, Y)
    FSO.DeleteFile temppath, True
End Function

Public Function ArraySize(ByRef a) As Long
    If IsEmpty(a) Then
        ArraySize = 0
    Else
        ArraySize = UBound(a) - LBound(a) + 1
    End If
End Function

Public Function StringToBytes(ByVal s As String) As Byte()
    s = StrConv(s, vbFromUnicode)
    StringToBytes = s
End Function

Public Function StringBToBytes(ByVal s As String) As Byte()
    StringBToBytes = s
End Function

Public Function BytesToString(ByVal Bytes) As String
    If IsArray(Bytes) Then
        If UBound(Bytes) < LBound(Bytes) Then Exit Function
    End If
    BytesToString = StrConv(Bytes, vbUnicode)
End Function

Public Function BytesToStringB(ByVal Bytes) As String
    BytesToStringB = Bytes
End Function

Public Function LeftBytes(ByRef Bytes, ByVal Length As Long)
    Dim Size As Long
    Size = ArraySize(Bytes)

    ' Assert Start >= 0 And Start <= Size

    If Length <= 0 Then
        Exit Function
    End If

    If Length >= Size Then
        If VarType(Bytes) = vbArray + vbByte Then
            LeftBytes = Bytes
            Exit Function
        End If
        Length = Size
    End If

    ReDim Partial(0 To Length - 1) As Byte
    Dim i As Long
    For i = 0 To Length - 1
        Partial(i) = Bytes(i)
    Next
    LeftBytes = Partial
End Function

Public Function MidBytes(ByRef Bytes, ByVal Start As Long) ' Start based at 0
    Dim Size As Long
    Size = ArraySize(Bytes)

    ' Assert Start >= 0 And Start <= Size

    If Start < 0 Then
        If VarType(Bytes) = vbArray + vbByte Then
            MidBytes = Bytes
            Exit Function
        End If
        Start = 0
    End If

    If Start >= Size Then
        Exit Function
    End If

    ReDim remains(0 To Size - Start - 1) As Byte
    varscpy remains, 0, Bytes, Start, Size - Start

    MidBytes = remains
End Function

Public Sub varscpy(ByRef dst, ByVal dstoff As Long, _
                   ByRef src, ByVal srcoff As Long, ByVal num As Long)
    Assert 0 <> (VarType(dst) And vbArray), "dst isn't an array"
    Assert 0 <> (VarType(src) And vbArray), "src isn't an array"
    Assert num >= 0, "invalid num of copy items", LOCATION
    Assert dstoff >= LBound(dst) And dstoff + num < UBound(dst), "dst-range out of bounds", LOCATION
    Assert srcoff >= LBound(src) And srcoff + num < UBound(src), "src-range out of bounds", LOCATION
    Dim i As Long
    For i = 0 To num - 1
        dst(dstoff + i) = src(srcoff + i)
    Next
End Sub

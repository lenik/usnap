VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "BinaryUtilities"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public m_Base64 As New BinaryLib.base64

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
    m_Base64.ReadFile Path
    ReadBinaryFile = m_Base64.GetBase64
    Exit Function
fail:
    ReadBinaryFile = Default
End Function

Public Function TextToBinary(ByVal text As String, Optional ByVal encoding As String = "gb2312") As String
    m_Base64.SetString text, encoding
    TextToBinary = m_Base64.GetBase64
End Function

Public Function BinaryToText(ByVal base64 As String, Optional ByVal encoding As String = "gb2312") As String
    m_Base64.SetBase64 base64
    BinaryToText = m_Base64.GetString(encoding)
End Function

Public Function BinaryToPicture(ByVal base64 As String, Optional Size, Optional ColorDepth, Optional X, Optional Y) As StdPicture
    Dim temppath As String
    temppath = Application.TemporaryPath("pic")
    m_Base64.SetBase64 base64
    m_Base64.WriteFile temppath
    Set BinaryToPicture = LoadPicture(temppath, Size, ColorDepth, X, Y)
    FSO.DeleteFile temppath, True
End Function

Attribute VB_Name = "Module1"
Option Explicit

Public m_B As XceedBinaryEncoding
Public cbBytes
Public v

Public Property Get B() As XceedBinaryEncoding
    If m_B Is Nothing Then
        Set m_B = New XceedBinaryEncoding
        m_B.License LICENSE_XC_BINARY
        Set m_B.EncodingFormat = New XceedBinaryEncodingLib.XceedBase64EncodingFormat
    End If
    Set B = m_B
End Property

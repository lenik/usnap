VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "NtCommand"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION                  As String = "NetTools::NtCommand"

Private m_Name As String
Private m_Params

Friend Sub Init(ByVal CmdLine As String)
    Dim c As String
    Do
        c = Right(CmdLine, 1)
        If c = vbLf Or c = vbCr Or c = ";" Or c = " " Then
            CmdLine = Left(CmdLine, Len(CmdLine) - 1)
        Else
            Exit Do
        End If
    Loop
    m_Params = Split(CmdLine, " ")
End Sub

Public Property Get Name() As String
    Name = m_Name
End Property

Public Property Get Parameter(ByVal Index As Integer)
    Assert Index >= 1, _
           "Invalid parameter index " & Index & " for command [" & m_Name & "]", LOCATION
    If Index <= UBound(m_Params) Then
        Parameter = m_Params(Index)
    ' Else return empty
    End If
End Property

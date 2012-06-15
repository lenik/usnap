Attribute VB_Name = "modHelpers"
Option Explicit

Public Const ERROR_CAERR = 4000

Public Const CANCELED_STRING = "<!--CANCELED-->"

Public LevelizeWidth As Byte
Public LevelizeOffset As Byte
Public LevelizeMasks(0 To 255) As Long

Enum ShapeTypeConstants
    shapeRectangle
    shapeRoundRectangle
    shapeEllipse
    shapePolygon
    shapeColorRange
End Enum

Enum ArrayTypeConstants
    arrayMatrix
    arrayRing
End Enum

Type ShapeType
    shape As ShapeTypeConstants
    isArray As Boolean
    array As ArrayTypeConstants
    matRows As Integer
    matColumns As Integer
    matRowPadding As Single
    matColumnPadding As Single
    ringNumber As Integer
    ringStartAngle As Single
    ringPadding As Single
End Type


Public Sub CaAssert(ByVal e As CaError)
    If e = CaErrOK Or e = CaErrWarn Then Exit Sub

    Dim msg As String

    Select Case e
    Case CaErrAlgorithm
        msg = "Error - Algorithm"
    Case CaErrArchitecture
        msg = "Error - Architecture"
    Case CaErrConception
        msg = "Error - Conception"
    Case CaErrFail
        msg = "Error - General Failure"
    Case CaErrMemoryOut
        msg = "Error - Memory out"
    Case CaErrNature
        msg = "Error - Nature"
    Case CaErrNetwork
        msg = "Error - Network"
    Case CaErrNoAccess
        msg = "Error - No access"
    Case CaErrNoCreate
        msg = "Error - No create"
    Case CaErrNoDestroy
        msg = "Error - No destroy"
    Case CaErrNoEnvironment
        msg = "Error - No environment"
    Case CaErrNoExist
        msg = "Error - No exist"
    Case CaErrNoIndex
        msg = "Error - No index"
    Case CaErrNoMatch
        msg = "Error - No match"
    Case CaErrNoSupport
        msg = "Error - No support"
    Case CaErrParameter
        msg = "Error - Parameters"
    Case CaErrPhilosophy
        msg = "Error - Philosophy"
    Case CaErrTimeout
        msg = "Error - Timeout"
    Case CaErrUnexpected
        msg = "Error - Unexpected"
    Case Else
        msg = "Error - No create"
    End Select

    Err.Raise ERROR_CAERR + e, "CeICU Calling", msg
End Sub

Public Function GetPathToOpen(ByVal dialogTitle, ByVal filterString) As String
    With frmIMStudio.cd
        .dialogTitle = dialogTitle
        .Filter = filterString

        On Error GoTo canceled
        .ShowOpen

        GetPathToOpen = .FileName
    End With
    Exit Function

canceled:
    GetPathToOpen = CANCELED_STRING
End Function


Public Function GetPathToSave(ByVal dialogTitle, ByVal filterString) As String
    With frmIMStudio.cd
        .dialogTitle = dialogTitle
        .Filter = filterString

        On Error GoTo canceled
        .ShowSave

        GetPathToSave = .FileName
    End With
    Exit Function

canceled:
    GetPathToSave = CANCELED_STRING
End Function


Public Sub Init()
    Dim i As Long
    For i = 0 To 255
        LevelizeMasks(i) = i Or &H100& * i Or &H10000 * i
    Next
End Sub


Public Sub Main()
    Init

    Load frmIMStudio

    Load frmA1_SelectType
    Load frmA2_ArrayOptions
    Load frmBlockProperties
    Load frmLevelizeAdjust

    Load frmAbout
    Load frmHelpUsage

    frmTip.DisplayCurrentTip
    frmIMStudio.Show
End Sub

Public Function LevelizeProc(ByVal color As Long) As Long
    'Dim r As Byte, g As Byte, b As Byte, a As Byte

    'r = color And &HFF&
    'g = Int(color / &H100&) And &HFF&
    'b = Int(color / &H10000) And &HFF&
    'a = Int(color / &H1000000) And &HFF&

    'r = LPmod(r, LevelizeWidth, LevelizeOffset)
    'g = LPmod(g, LevelizeWidth, LevelizeOffset)
    'b = LPmod(b, LevelizeWidth, LevelizeOffset)
    'a = LPmod(a, LevelizeWidth, LevelizeOffset)

    'LevelizeProc = &H0& Or r Or &H100& * g Or &H10000 * b Or &H1000000 * a
    LevelizeProc = color And Not LevelizeMasks(LevelizeWidth)
End Function

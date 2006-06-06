Attribute VB_Name = "Typedefs"
Option Explicit

Public LC As New LowXRuntime.Component
Public LD As New LowXRuntime.Debugger
Public LE As New LowXRuntime.Execute
Public LK As New LowXRuntime.Call
Public LM As New LowXRuntime.Memory
Public LP As New LowXRuntime.Pointer
Public LR As New LowXRuntime.RawDataType
Public LS As New LowXRuntime.String
Public LV As New LowXRuntime.Vtbl
Public LW As New LowXRuntime.Window
Public LX As New LowXRuntime.PseudoControl
Public LXDefault As New LowXRuntime.PseudoControlSetting

Public FSO As New Scripting.FileSystemObject

Public FC As New ForceCast

Public Function ParamArrayToArray(ParamArray params_()) As Variant()
    Dim Params
    Params = params_(0)
    Dim l As Integer
    l = LBound(Params)
    If l = UBound(Params) Then
        If TypeName(Params(l)) = "Variant()" Then
            ParamArrayToArray = Params(l)
            Exit Function
        End If
    End If
    ParamArrayToArray = Params
End Function

Public Function ParseMap(ByVal str As String) As VBExt.Map
    Set ParseMap = New VBExt.Map
    If str = "" Then Exit Function

    Dim qq_k As String
    Dim qq As String
    Dim segs, kv
    Dim i As Integer, s As String
    Dim k As String, v

    segs = Split(str, ":")
    For i = LBound(segs) To UBound(segs)
        s = segs(i)
        If qq <> "" Then
            If Right(s, 1) = """" Then    ' ..."$
                s = Left(s, Len(s) - 1)
                qq = qq & ":" & QQEval(s)
                ParseMap.Item(qq_k) = qq
                qq = ""
            Else
                qq = qq & ":" & QQEval(s)
            End If
        Else
            kv = Split(s, "=", 2)
            If UBound(kv) = 1 Then      ' key=value where value must be existed
                k = Trim(kv(0))
                If k <> "" Then
                    v = LTrim(kv(1))
                    If Left(v, 1) = """" Then ' ^"...
                        v = Mid(v, 2)
                        If Right(v, 1) = """" Then ' ..."$
                            ' BUGFIX: when \":.. the end-" is quoted
                            If Len(v) > 1 And Left(Right(v, 2), 1) = "\" Then
                                qq = QQEval(v)
                                qq_k = k
                            Else
                                v = Left(v, Len(v) - 1)
                                v = QQEval(v)
                                ParseMap.Item(k) = v
                            End If
                        Else
                            qq = QQEval(v)
                            qq_k = k
                        End If
                    Else
                        v = RTrim(v)
                        ParseMap.Item(k) = v
                    End If ' v =~ m/^\"/
                End If ' k ne ''
            End If ' ubound(kv)=1
        End If ' qq
    Next '
End Function

Public Function QQEval(ByVal str As String) As String
    Dim segs
    Dim i As Integer
    Dim s As String
    segs = Split(str, "\")
    QQEval = segs(0)
    For i = 1 To UBound(segs)
        s = segs(i)
        If s = "" Then                  ' ... \ (\|$)   => \\
            If i < UBound(segs) Then
                segs(i + 1) = "\" & segs(i + 1)
            End If
        Else
            Select Case Left(s, 1)
            Case "n"                    ' ... \ n...    => \n
                s = vbLf & Mid(s, 2)
            Case "r"                    ' ... \ r...    => \r
                s = vbCr & Mid(s, 2)
            Case "t"                    ' ... \ t...    => \t
                s = vbTab & Mid(s, 2)
            Case Else                   ' ... \ .       => .
                '
            End Select
        End If
        QQEval = QQEval & s
    Next
End Function

Public Function VarEval(ByVal str As String, ByVal VarDef As String) As String
    Dim VarMap As VBExt.Map
    Set VarMap = ParseMap(VarDef)
    VarEval = VarEvalMap(str, VarMap)
End Function

Public Function VarEvalMap(ByVal str As String, ByVal VarMap As Map) As String
    Dim matches As MatchCollection
    Dim mat As Match
    Dim i As Integer
    Dim lastIndex As Long
    Dim seg As String
    Dim v

    Set matches = g_Patterns.RE_VAR.Execute(str)
    lastIndex = 1

    For i = 0 To matches.Count - 1
        Set mat = matches(i)
        seg = mat.Value
        VarEvalMap = VarEvalMap & Mid(str, lastIndex, mat.FirstIndex - lastIndex + 1)

        If Left(seg, 1) = "$" Then
            Dim Name As String
            Name = Mid(seg, 2)
            If Left(Name, 1) = "{" Then Name = Mid(Name, 2, Len(Name) - 2)
            v = VarMap.Item(Name)
            If Not IsNull(v) Then
                seg = v
            End If
        Else
            Unexpected "The regexp should only match $..."
        End If
        VarEvalMap = VarEvalMap & seg
        lastIndex = mat.FirstIndex + 1 + mat.length
    Next

    If lastIndex < Len((str)) Then
        VarEvalMap = VarEvalMap & Mid(str, lastIndex)
    End If
End Function

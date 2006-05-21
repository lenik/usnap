VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "SessionEvents"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Event OnPreCommand(ByVal s As Session, ByVal c As NtCommand, ByRef Cancel As Boolean)

Public Event OnCommand(ByVal s As Session, ByVal c As NtCommand)

Public Event OnTouch(ByVal s As Session)

Public Event OnMessage(ByVal s As Session, ByVal Message As String, _
                       ByVal IsEncrypted As Boolean, ByRef AckMessage As String)

Public Event OnVolumes(ByVal s As Session)

Public Event OnScriptResult(ByVal s As Session, ByVal Result As String)

' Public Event OnEnter(ByVal s As Session, ByVal term As String)

' Public Event OnExit(ByVal s As Session, ByVal term As String)

Friend Sub OnPreCommand(ByVal s As Session, ByVal c As NtCommand, ByRef Cancel As Boolean)
    RaiseEvent OnPreCommand(s, c, Cancel)
End Sub

Friend Sub OnCommand(ByVal s As Session, ByVal c As NtCommand)
    RaiseEvent OnCommand(s, c)
End Sub

Friend Sub OnTouch(ByVal s As Session)
    RaiseEvent OnTouch(s)
End Sub

Friend Sub OnMessage(ByVal s As Session, ByVal Message As String, _
                     ByVal IsEncrypted As Boolean, ByRef AckMessage As String)
    RaiseEvent OnMessage(s, Message, IsEncrypted, AckMessage)
End Sub

Friend Sub OnVolumes(ByVal s As Session)
    RaiseEvent OnVolumes(s)
End Sub

Friend Sub OnScriptResult(ByVal s As Session, ByVal Result As String)
    RaiseEvent OnScriptResult(s, Result)
End Sub

'Friend Sub OnEnter(ByVal s As Session, ByVal term As String)
'    RaiseEvent OnEnter(s, term)
'End Sub
'
'Friend Sub OnExit(ByVal s As Session, ByVal term As String)
'    RaiseEvent OnExit(s, term)
'End Sub

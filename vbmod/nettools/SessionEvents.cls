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

Public Event OnGet(ByVal s As Session, ByVal URI As String, ByRef Response As Variant)

Public Event OnResponse(ByVal s As Session, ByVal URI As String, ByVal Response As String)

Public Event OnIncomingFile(ByVal s As Session, ByVal Name As String, _
                            ByVal Category As String, ByVal IsEncrypted As Boolean, _
                            ByVal Size As Long, ByRef SavePath As String)

Public Event OnReceivingFile(ByVal s As Session, ByVal Name As String, _
                             ByVal Category As String, ByVal IsEncrypted As Boolean, _
                             ByVal FileSize As Long, ByVal RecvSize As Long, _
                             ByRef SavePath As String)

Public Event OnReceivedFile(ByVal s As Session, ByVal Name As String, _
                            ByVal Category As String, ByVal IsEncrypted As Boolean, _
                            ByRef SavePath As String)

Public Event OnSendingFile(ByVal s As Session, ByVal Path As String, ByVal RemoteName As String, _
                           ByVal Category As String, ByVal IsEncrypted As Boolean, _
                           ByVal FileSize As Long, ByVal SentSize As Long)

Public Event OnSentFile(ByVal s As Session, ByVal Path As String, ByVal RemoteName As String, _
                        ByVal Category As String, ByVal IsEncrypted As Boolean)

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

Friend Sub OnGet(ByVal s As Session, ByVal URI As String, ByRef Response As Variant)
    RaiseEvent OnGet(s, URI, Response)
End Sub

Friend Sub OnResponse(ByVal s As Session, ByVal URI As String, ByVal Response As String)
    RaiseEvent OnResponse(s, URI, Response)
End Sub

Friend Sub OnIncomingFile(ByVal s As Session, ByVal Name As String, _
                          ByVal Category As String, ByVal IsEncrypted As Boolean, _
                          ByVal Size As Long, ByRef SavePath As String)
    RaiseEvent OnIncomingFile(s, Name, Category, IsEncrypted, Size, SavePath)
End Sub

Friend Sub OnReceivingFile(ByVal s As Session, ByVal Name As String, _
                           ByVal Category As String, ByVal IsEncrypted As Boolean, _
                           ByVal FileSize As Long, ByVal RecvSize As Long, _
                           ByRef SavePath As String)
    RaiseEvent OnReceivingFile(s, Name, Category, IsEncrypted, FileSize, RecvSize, SavePath)
End Sub

Friend Sub OnReceivedFile(ByVal s As Session, ByVal Name As String, _
                          ByVal Category As String, ByVal IsEncrypted As Boolean, _
                          ByRef SavePath As String)
    RaiseEvent OnReceivedFile(s, Name, Category, IsEncrypted, SavePath)
End Sub

Friend Sub OnSendingFile(ByVal s As Session, ByVal Path As String, ByVal RemoteName As String, _
                           ByVal Category As String, ByVal IsEncrypted As Boolean, _
                           ByVal FileSize As Long, ByVal SentSize As Long)
    RaiseEvent OnSendingFile(s, Path, RemoteName, Category, IsEncrypted, FileSize, SentSize)
End Sub

Friend Sub OnSentFile(ByVal s As Session, ByVal Path As String, ByVal RemoteName As String, _
                        ByVal Category As String, ByVal IsEncrypted As Boolean)
    RaiseEvent OnSentFile(s, Path, RemoteName, Category, IsEncrypted)
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

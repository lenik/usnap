VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Hello2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Function ShowHello()
    ShowHello = "Hello, world!"
End Function

Function Baby(ByVal x As String)
    Baby = "<H1>THE BABY EXAMPLE - 3!</H1>"
    Baby = Baby + "<B><I>[" + x + "]</I></B>"
End Function

Function Calc(ByVal cmd As String)
    r = WinExec(Trim(cmd), 0)
    Calc = Str(r)
End Function

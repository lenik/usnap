Dim UserMod, KnlMod
Dim PAddr
Sub InitDLL
	KnlMod = ScriptToolB.VLoadLibrary("Kernel32.dll")
	UserMod = ScriptToolB.VLoadLibrary("User32.dll")
End Sub

PAddr = ScriptToolB.VGetProcAddress(KnlMod, "GetTickCount")
Ticks = ScriptToolA.VcallFunction0(PAddr)
IAddr = ScriptToolB.VGetProcAddress(KnlMod, "InterlockedIncrement")
DAddr = ScriptToolB.VGetProcAddress(KnlMod, "InterlockedDecrement")

s = CLng(1234)
mm = ScriptToolA.VcallFunction1(IAddr, s)
msgbox s
msgbox mm

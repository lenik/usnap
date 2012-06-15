Attribute VB_Name = "DTFunc"
Sub DTEnd()
Dim Buf As String * 512
Dim ReturnVal As Long, ReturnStr As String * 128

    ReturnVal = mciSendString("close all", ReturnStr, 128, 0)
    ReturnVal = mciGetErrorString(ReturnVal, Buf, 512)

End
End Sub

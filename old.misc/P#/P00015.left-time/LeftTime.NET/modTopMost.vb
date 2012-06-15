Option Strict Off
Option Explicit On
Module modTopMost

	Public Const SWP_NOMOVE As Short = 2
	Public Const SWP_NOSIZE As Short = 1
	Public Const FLAGS As Boolean = SWP_NOMOVE Or SWP_NOSIZE
	Public Const HWND_TOPMOST As Short = -1
	Public Const HWND_NOTOPMOST As Short = -2

	Declare Function SetWindowPos Lib "user32" (ByVal hwnd As Integer, ByVal hWndInsertAfter As Integer, ByVal x As Integer, ByVal y As Integer, ByVal cx As Integer, ByVal cy As Integer, ByVal wFlags As Integer) As Integer

	Public Function SetTopMostWindow(ByRef hwnd As Integer, ByRef Topmost As Boolean) As Integer

		If Topmost = True Then 'Make the window topmost
			SetTopMostWindow = SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, FLAGS)
		Else
			SetTopMostWindow = SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, FLAGS)
			SetTopMostWindow = False
		End If
	End Function
End Module
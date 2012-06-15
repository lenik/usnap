Attribute VB_Name = "modFinger"
Option Explicit

Global Const debugMode As Boolean = True

Global Const FingerRoot As String = "�ȴ����\��ԭ���\���ֳ�\��ָ��"

Enum RunningModeType
        M_Idle = 0
        M_Practice = 1
        M_Test = 2
        M_client = 3
        M_Manager = 4
End Enum

Public FLastTimer As Double, RunningMode As RunningModeType
Public FDeltaTimer As Double
Public bHandup As Boolean

Public Property Get Mode() As RunningModeType: Mode = RunningMode: End Property
Public Property Let Mode(ByVal newMode As RunningModeType)
        RunningMode = newMode
        Select Case newMode
        Case M_Idle
                FLastTimer = 0
        Case M_Practice
                FLastTimer = 0
        Case M_Test
                FLastTimer = Timer
        Case M_client
                FLastTimer = Timer
        Case M_Manager
                FLastTimer = Timer
        End Select
End Property

Sub Main()
        Dim sSplash As Integer
        Dim sRan As Long
        Dim sScript As String

        sSplash = GetSetting(FingerRoot, "����ѡ��", "��ʾ��������", 2)
        If sSplash = 2 Then
                SaveSetting FingerRoot, "����ѡ��", "��ʾ��������", 1
        End If
        sRan = GetSetting(FingerRoot, "����ѡ��", "����ID", Timer)
        SaveSetting FingerRoot, "����ѡ��", "����ID", Timer

        sScript = GetSetting(FingerRoot, "����ѡ��", "��������", "")
        SaveSetting FingerRoot, "����ѡ��", "��������", sScript

        forceMbcs = GetSetting(FingerRoot, "����ѡ��", "ʹ��MBCS", "0") = "1"

        frmMain.script.ExecuteStatement sScript

        Randomize sRan
        RunningMode = M_Idle

        Load frmSplash
        If sSplash <> 0 Then frmSplash.Show
        DoEvents
        Load frmMain
        If sSplash = 0 Then frmMain.Show

        SetDepth GetSetting(FingerRoot, "����ѡ��\���Ƚ�", "�Ƚ����", 15)
        SetSame GetSetting(FingerRoot, "����ѡ��\���Ƚ�", "�ȽϹ��", 4)

        Load frmAbout: DoEvents
        Load frmManager: DoEvents
        Load frmApply: DoEvents
        Load frmHoll: DoEvents
        Load frmSelectComputer: DoEvents
        Load frmWaitingBox: DoEvents
        Load frmMessage: DoEvents
        Load frmNetStatus: DoEvents
        Load frmDataSetup: DoEvents
        Load frm_Snow: DoEvents
        If sSplash <> 0 Then frmMain.Show
        frmSplash.Hide
End Sub

Public Sub Terminate()
        Unload frmAbout
        Unload frmManager
        Unload frmApply
        Unload frmHoll
        Unload frmSelectComputer
        Unload frmWaitingBox
        Unload frmMessage
        Unload frmNetStatus
        Unload frmDataSetup
        Unload frm_Snow
        Unload frmSplash
        Unload frmMain
End Sub

Private Function fixStr(ByVal ostr As String, ByVal newlen As Integer, Optional ByVal FillChar As String = " ") As String
        ostr = Trim(ostr)
        While Len(ostr) < newlen
                ostr = FillChar & ostr
        Wend
        fixStr = ostr
End Function

Public Function deltaTime() As String
        Dim dHours, dMinutes, dSeconds, dHSeconds
        Dim delta As Double

        FDeltaTimer = Timer - FLastTimer

        delta = IIf(Mode = M_client, fingerServer.TestTime - FDeltaTimer, FDeltaTimer)

        dHSeconds = delta - Int(delta)
        delta = delta - dHSeconds
        dHSeconds = Int(dHSeconds * 100)

        dSeconds = delta Mod 60
        delta = (delta - dSeconds) / 60

        dMinutes = delta Mod 60
        delta = (delta - dMinutes) / 60

        dHours = delta

        deltaTime = fixStr(dHours, 2, "0") & ":" & _
                        fixStr(dMinutes, 2, "0") & ":" & _
                        fixStr(dSeconds, 2, "0") & "." & _
                        fixStr(dHSeconds, 2, "0")
End Function

Public Function DeltaTimer() As Single
        FDeltaTimer = Timer - FLastTimer
        DeltaTimer = FDeltaTimer
End Function

Public Sub ccs()
        MsgBox frmSelectComputer.Run(True, False, pFunc(AddressOf Finger_EnumComputerProc))
End Sub

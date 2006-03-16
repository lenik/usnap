Attribute VB_Name = "SystemEvents"
Option Explicit

Private Const LOCATION = "VBExt::SystemEvents"

Public g_SystemEventListeners As New Collection

Public Sub RegisterSystemEventListener(ByVal name As String, ByVal listener As SystemEventListener)
    name = Trim(name)
    Assert name <> "", "Illegal Name", LOCATION
    Assert Not listener Is Nothing, "Illegal Listener Object", LOCATION
    On Error GoTo Failed
    g_SystemEventListeners.Add listener, name
    Exit Sub
Failed:
    Assert False, "The listener with name " & name & " has been already registered."
End Sub

Public Sub UnregisterSystemEventListener(ByVal name As String)
    name = Trim(name)
    Assert name <> "", "Illegal Name", LOCATION
    On Error GoTo Failed
    g_SystemEventListeners.Remove name
Failed:
    Assert False, "The listener with name " & name & " hasn't been registered, yet."
End Sub

Public Sub DispatchSystemEvent(ByVal e As SystemEventConstants, parameters)
    Dim listener As SystemEventListener
    For Each listener In g_SystemEventListeners
        listener.Handler e, parameters
    Next
End Sub

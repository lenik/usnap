Attribute VB_Name = "SystemEvents"
Option Explicit

Private Const LOCATION = "VBExt::SystemEvents"

Public g_SystemEventListeners As New Collection

Public Sub RegisterSystemEventListener(ByVal Name As String, ByVal listener As SystemEventListener)
    Name = Trim(Name)
    Assert Name <> "", "Illegal Name", LOCATION
    Assert Not listener Is Nothing, "Illegal Listener Object", LOCATION
    On Error GoTo Failed
    g_SystemEventListeners.Add listener, Name
    Exit Sub
Failed:
    Assert False, "The listener with name " & Name & " has been already registered."
End Sub

Public Sub UnregisterSystemEventListener(ByVal Name As String)
    Name = Trim(Name)
    Assert Name <> "", "Illegal Name", LOCATION
    On Error GoTo Failed
    g_SystemEventListeners.Remove Name
Failed:
    Assert False, "The listener with name " & Name & " hasn't been registered, yet."
End Sub

Public Sub DispatchSystemEvent(ByVal SystemEvent As Long, Parameters)
    Dim listener As SystemEventListener
    For Each listener In g_SystemEventListeners
        listener.Handler SystemEvent, Parameters
    Next
End Sub

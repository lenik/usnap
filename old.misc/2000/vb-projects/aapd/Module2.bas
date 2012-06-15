Attribute VB_Name = "Module2"
Option Explicit

Public Sub register()
        Dim hsc, hs
        hsc = OpenSCManager(vbNullString, vbNullString, SC_MANAGER_CREATE_SERVICE)

        'hs = CreateService(hsc, "aapd", "Anti-Ad.Popup Daemon", _
                SC_MANAGER_CREATE_SERVICE, SERVICE_ALL_ACCESS, service_auto_start,service_error_ignore,)

        CloseServiceHandle hsc
End Sub

Public Sub start()

End Sub

Public Sub stopit()

End Sub

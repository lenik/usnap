Attribute VB_Name = "Sys"
Sub GetSystemEnv()
Dim SysConfiged As Integer, phkResult As Long
Dim r
    SysConfiged = RegOpenKeyEx(HKEY_CLASSES_ROOT, "Top Croak\HTE\Software", 0, KEY_ALL_ACCESS, phkResult)
    If SysConfiged <> ERROR_SUCCESS Then
      r = MsgBox("ϵͳ��δ����, �Ƿ���������?", vbOKCancel, ϵͳ����)
      If r = vbOK Then frmSysCfg.Show 1
      SysConfiged = RegOpenKeyEx(HKEY_CLASSES_ROOT, "Top Croak\HTE\Software", 0, KEY_ALL_ACCESS, phkResult)
      If SysConfiged <> ERROR_SUCCESS Then
        MsgBox "ע������! ���� topcroak@hotmail.com ��ϵ", vbCritical, "ע������"
        End
      End If
    End If
    Main.Label1.Caption = Str(phkResult)
    SysConfiged = RegQueryValueEx(phkResult, "System Path", 0, REG_SZ, SysLoc$, phkResult)
    If SysConfiged <> ERROR_SUCCESS Then
        MsgBox "ע������: " + Str(SysConfiged) + " ���� topcroak@hotmail.com ��ϵ", vbCritical, "ע������"
    '    End
    End If
    'SysLoc = RTrim(SysLoc)
    SysLoc = SysLoc + "  !!  !!"
    Main.Label1.Caption = Main.Label1.Caption + Chr$(13) + Chr$(10) + "Loc: " + SysLoc + ", Len=" + Str(phkResult)

End Sub

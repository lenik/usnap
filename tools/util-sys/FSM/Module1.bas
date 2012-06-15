Attribute VB_Name = "Module1"
Declare Function GetDiskFreeSpace Lib "kernel32" Alias "GetDiskFreeSpaceA" (ByVal lpRootPathName As String, lpSectorsPerCluster As Long, lpBytesPerSector As Long, lpFreeClusters As Long, lpTotalClusters As Long) As Long

Public precise As Integer

Public Function pstr(ByVal n As Double) As String
        Dim dotpos As Integer
        Dim fracnum As Integer
        If precise < 1 Then
                pstr = Trim(Str(Int(n)))
        Else
                pstr = Trim(Str(n))
                dotpos = InStr(pstr, ".")
                fracnum = 0
                If dotpos > 0 Then fracnum = Len(pstr) - dotpos

                If fracnum > precise Then
                        pstr = Left(pstr, dotpos + precise)
                End If
        End If
End Function

Attribute VB_Name = "modMsacm_Utils"
Option Explicit

Private l_P As New LowXRuntime.Pointer
Private l_S As New lowxtool.String
Private ct As New CaComToolLib.CaCTools

Type ACM_METRICS
        CountDrivers As Long
        CountCodecs As Long
        CountConverters As Long
        CountFilters As Long
        CountDisabled As Long
        CountHardware As Long
        CountLocalDrivers As Long
        CountLocalCodecs As Long
        CountLocalConverters As Long
        CountLocalFilters As Long
        CountLocalDisabled As Long
        HardwareWaveInput As Long
        HardwareWaveOutput As Long
        MaxSizeFormat As Long
        MaxSizeFilter As Long
        DriverSupport As Long   ' Hao=DriverID
        DriverPriority As Long  ' Hao=DriverID
End Type


Public Function acmMetrics2(ByVal hacmobjHao As Long) As ACM_METRICS
        Dim l As Long
        With acmMetrics2
                l = acmMetrics(hacmobjHao, ACM_METRIC_COUNT_DRIVERS, l_P.pDword(.CountDrivers))
                l = acmMetrics(hacmobjHao, ACM_METRIC_COUNT_CODECS, l_P.pDword(.CountCodecs))
                l = acmMetrics(hacmobjHao, ACM_METRIC_COUNT_CONVERTERS, l_P.pDword(.CountConverters))
                l = acmMetrics(hacmobjHao, ACM_METRIC_COUNT_FILTERS, l_P.pDword(.CountFilters))
                l = acmMetrics(hacmobjHao, ACM_METRIC_COUNT_DISABLED, l_P.pDword(.CountDisabled))
                l = acmMetrics(hacmobjHao, ACM_METRIC_COUNT_HARDWARE, l_P.pDword(.CountHardware))
                l = acmMetrics(hacmobjHao, ACM_METRIC_COUNT_LOCAL_DRIVERS, _
                        l_P.pDword(.CountLocalDrivers))
                l = acmMetrics(hacmobjHao, ACM_METRIC_COUNT_LOCAL_CODECS, _
                        l_P.pDword(.CountLocalCodecs))
                l = acmMetrics(hacmobjHao, ACM_METRIC_COUNT_LOCAL_CONVERTERS, _
                        l_P.pDword(.CountLocalConverters))
                l = acmMetrics(hacmobjHao, ACM_METRIC_COUNT_LOCAL_FILTERS, _
                        l_P.pDword(.CountLocalFilters))
                l = acmMetrics(hacmobjHao, ACM_METRIC_COUNT_LOCAL_DISABLED, _
                        l_P.pDword(.CountLocalDisabled))
                l = acmMetrics(hacmobjHao, ACM_METRIC_HARDWARE_WAVE_INPUT, _
                        l_P.pDword(.HardwareWaveInput))
                l = acmMetrics(hacmobjHao, ACM_METRIC_HARDWARE_WAVE_OUTPUT, _
                        l_P.pDword(.HardwareWaveOutput))
                l = acmMetrics(hacmobjHao, ACM_METRIC_MAX_SIZE_FORMAT, l_P.pDword(.MaxSizeFormat))
                l = acmMetrics(hacmobjHao, ACM_METRIC_MAX_SIZE_FILTER, l_P.pDword(.MaxSizeFilter))
                l = acmMetrics(hacmobjHao, ACM_METRIC_DRIVER_SUPPORT, l_P.pDword(.DriverSupport))
                l = acmMetrics(hacmobjHao, ACM_METRIC_DRIVER_PRIORITY, l_P.pDword(.DriverPriority))
        End With
End Function

Private Function acmDriverEnum2_CB(ByVal hAcmDriverId As Long, ByVal dwInstance As Long, ByVal fdwSupport As Long) As Boolean
        Dim lCurrentIndex As Long
        Dim lStopIndex As Long
        Dim coll As Collection

        ' prepare
        l_P.Base = dwInstance
        lCurrentIndex = l_P.Dword(0)
        lStopIndex = l_P.Dword(1)
        Set coll = l_P.Disp(2)
        ct.forceAddRef coll

        ' save
        l_P.Dword(3) = hAcmDriverId
        l_P.Dword(4) = fdwSupport

        coll.add l_S.encodePart(hAcmDriverId) & l_S.encodePart(fdwSupport), "K" & Trim(lCurrentIndex)

        ' index++
        acmDriverEnum2_CB = lStopIndex = -1 Or (lCurrentIndex < lStopIndex)
        lCurrentIndex = lCurrentIndex + 1
        l_P.Dword(0) = lCurrentIndex

        Set coll = Nothing
End Function
Public Function acmDriverEnum2() As Collection
        Dim l As Long
        ' [Current Index] [Stop Index] [Collection] [HACMDRIVERID] [fdwSupport]
        Set acmDriverEnum2 = New Collection
        Dim buf(0 To 4) As Long
        buf(0) = 0
        buf(1) = -1
        buf(2) = l_P.pDisp(acmDriverEnum2)
        l = acmDriverEnum(l_P.pFunc(AddressOf acmDriverEnum2_CB), _
                l_P.pDword(buf(0)), _
                ACM_DRIVERENUMF_DISABLED Or ACM_DRIVERENUMF_NOLOCAL)
End Function

Public Function acmDriverIndex(ByVal Index As Long) As Long
        Dim coll As Collection
        Set coll = acmDriverEnum2
        If Index < 0 Or Index >= coll.Count Then
                acmDriverIndex = 0
                Exit Function
        End If

        Dim Key
        Key = "K" & Trim(Index)
        acmDriverIndex = Val(l_S.decodePart(coll(Key), 1))
End Function

Public Function acmDriverID2(ByVal hacmobjHao As Long) As Long
        Dim l As Long
        l = acmDriverID(hacmobjHao, acmDriverID2, 0)
        If l < 0 Then Err.Raise l
End Function

Private Function acmDriverAdd2_CB(ByVal dwID As Long, ByVal hDriver As Long, ByVal uMsg As Long, ByVal lParam1 As Long, ByVal lParam2 As Long) As Long
        Select Case uMsg
        End Select
End Function
Public Function acmDriverAdd2(ByVal fGlobal As Boolean) As Long
        Dim l As Long
        l = acmDriverAdd(acmDriverAdd2, App.hInstance, _
                l_P.pFunc(AddressOf acmDriverAdd2_CB), 0, _
                ACM_DRIVERADDF_FUNCTION Or _
                        IIf(fGlobal, ACM_DRIVERADDF_GLOBAL, ACM_DRIVERADDF_LOCAL))
        If l < 0 Then Err.Raise l
End Function

Public Function acmDriverOpen2(ByVal hAcmDriverId As Long) As Long
        Dim l As Long
        l = acmDriverOpen(acmDriverOpen2, hAcmDriverId, 0)
        If l < 0 Then Err.Raise l
End Function

Public Function acmDriverDetails2(ByVal hAcmDriverId As Long) As acmDriverDetails
        Dim l As Long
        acmDriverDetails2.cbStruct = Len(acmDriverDetails2)
        l = acmDriverDetails(hAcmDriverId, acmDriverDetails2, 0)
        If l < 0 Then Err.Raise l
End Function

Public Function acmFormatTagDetails2(ByVal hAcmDriver As Long, ByVal Index As Long) As acmFormatTagDetails
        Dim l As Long, add As acmDriverDetails, cTags As Long
        add = acmDriverDetails2(hAcmDriver)
        cTags = add.cFormatTags
        If Index >= cTags Then Err.Raise 0, , "Overflow bound"
        acmFormatTagDetails2.dwFormatTagIndex = Index
        acmFormatTagDetails2.cbStruct = Len(acmFormatTagDetails2)

        l = acmFormatTagDetails(hAcmDriver, acmFormatTagDetails2, ACM_FORMATTAGDETAILSF_INDEX)
        If l < 0 Then Err.Raise l
End Function

Private Function acmFormatTagEnum2_CB(ByVal hAcmDriverId As Long, aftd As acmFormatTagDetails, ByVal dwInstance As Long, ByVal fdwSupport As Long) As Boolean
        Dim lCurrentIndex As Long
        Dim lStopIndex As Long
        Dim coll As Collection

        l_P.Base = dwInstance
        lCurrentIndex = l_P.Dword(0)
        lStopIndex = l_P.Dword(1)

        Set coll = l_P.Disp(2)
        ct.forceAddRef coll

        Dim aftdpack As String
        aftdpack = l_S.encodePart(aftd.cbStruct) & _
                l_S.encodePart(aftd.dwFormatTagIndex) & _
                l_S.encodePart(aftd.dwFormatTag) & _
                l_S.encodePart(aftd.cbFormatSize) & _
                l_S.encodePart(aftd.fdwSupport) & _
                l_S.encodePart(aftd.cStandardFormats) & _
                l_S.encodePart(l_S.saveAscizString(l_P.pByte(aftd.szFormatTag(0))))

        'fdwSupport:
        '        ACMDRIVERDETAILS_SUPPORTF_ASYNC
        '        ACMDRIVERDETAILS_SUPPORTF_CODEC
        '        ACMDRIVERDETAILS_SUPPORTF_CONVERTER
        '        ACMDRIVERDETAILS_SUPPORTF_FILTER
        '        ACMDRIVERDETAILS_SUPPORTF_HARDWARE

        coll.add aftdpack, "K" & Trim(lCurrentIndex)
        acmFormatTagEnum2_CB = (lStopIndex = -1) Or (lCurrentIndex + 1 < lStopIndex)
        lCurrentIndex = lCurrentIndex + 1
        l_P.Dword(0) = lCurrentIndex

        Set coll = Nothing
End Function
Public Function acmFormatTagEnum2(ByVal hAcmDriver) As Collection
        Dim l As Long
        Dim buf(0 To 2) As Long
        buf(0) = 0
        buf(1) = -1
        Set acmFormatTagEnum2 = New Collection
        buf(2) = l_P.pDisp(acmFormatTagEnum2)

        Dim aftd As acmFormatTagDetails
        aftd.cbStruct = Len(aftd)

        l = acmFormatTagEnum(hAcmDriver, aftd, l_P.pFunc(AddressOf acmFormatTagEnum2_CB), _
                l_P.pDword(buf(0)), 0)
        If l < 0 Then Err.Raise l
End Function
Public Function acmFormatTagIndex(ByVal hAcmDriver As Long, ByVal Index As Long) As acmFormatTagDetails
        Dim coll As Collection
        Set coll = acmFormatTagEnum2(hAcmDriver)

        If Index < 0 Or Index >= coll.Count Then Err.Raise -1, , "Overflow bound"
        Dim aftdpack As String
        aftdpack = coll("K" & Trim(Index))

        With acmFormatTagIndex
                .cbStruct = l_S.decodePart(aftdpack, 1)
                .dwFormatTagIndex = l_S.decodePart(aftdpack, 2)
                .dwFormatTag = l_S.decodePart(aftdpack, 3)
                .cbFormatSize = l_S.decodePart(aftdpack, 4)
                .fdwSupport = l_S.decodePart(aftdpack, 5)
                .cStandardFormats = l_S.decodePart(aftdpack, 6)

                Dim l_M As New LowXRuntime.Memory
                Dim ls As New LowXRuntime.String
                Dim szFormatTag As String
                szFormatTag = l_S.decodePart(aftdpack, 7)
                l_M.CopyBytes l_P.pByte(.szFormatTag(0)), _
                        l_P.pStr(szFormatTag), _
                        ls.LenW(l_P.pStr(szFormatTag)) + 1
        End With
End Function

Public Function acmFormatChoose2()
        acmFormatChoose
End Function

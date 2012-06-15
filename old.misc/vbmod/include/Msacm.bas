Attribute VB_Name = "modMsacm"
Option Explicit

'
Const DRV_USER = &H4000


Public Const DRV_MAPPER_PREFERRED_INPUT_GET = (DRV_USER + 0)
Public Const DRV_MAPPER_PREFERRED_OUTPUT_GET = (DRV_USER + 2)
Public Const DRVM_MAPPER = &H2000
Public Const DRVM_MAPPER_STATUS = (DRVM_MAPPER + 0)
Public Const WIDM_MAPPER_STATUS = (DRVM_MAPPER_STATUS + 0)
Public Const WAVEIN_MAPPER_STATUS_DEVICE = 0
Public Const WAVEIN_MAPPER_STATUS_MAPPED = 1
Public Const WAVEIN_MAPPER_STATUS_FORMAT = 2
Public Const WODM_MAPPER_STATUS = (DRVM_MAPPER_STATUS + 0)
Public Const WAVEOUT_MAPPER_STATUS_DEVICE = 0
Public Const WAVEOUT_MAPPER_STATUS_MAPPED = 1
Public Const WAVEOUT_MAPPER_STATUS_FORMAT = 2

Public Const ACMERR_BASE = (512)
Public Const ACMERR_NOTPOSSIBLE = (ACMERR_BASE + 0)
Public Const ACMERR_BUSY = (ACMERR_BASE + 1)
Public Const ACMERR_UNPREPARED = (ACMERR_BASE + 2)
Public Const ACMERR_CANCELED = (ACMERR_BASE + 3)

'Public Const MM_ACM_OPEN = (MM_STREAM_OPEN)
'Public Const MM_ACM_CLOSE = (MM_STREAM_CLOSE)
'Public Const MM_ACM_DONE = (MM_STREAM_DONE)


Declare Function acmGetVersion Lib "msacm32.dll" () As Long

Declare Function acmMetrics Lib "msacm32.dll" (ByVal hacmobjHao As Long, ByVal uMetric As Long, ByVal pvMetric As Long) As Long

Public Const ACM_METRIC_COUNT_DRIVERS = 1
Public Const ACM_METRIC_COUNT_CODECS = 2
Public Const ACM_METRIC_COUNT_CONVERTERS = 3
Public Const ACM_METRIC_COUNT_FILTERS = 4
Public Const ACM_METRIC_COUNT_DISABLED = 5
Public Const ACM_METRIC_COUNT_HARDWARE = 6
Public Const ACM_METRIC_COUNT_LOCAL_DRIVERS = 20
Public Const ACM_METRIC_COUNT_LOCAL_CODECS = 21
Public Const ACM_METRIC_COUNT_LOCAL_CONVERTERS = 22
Public Const ACM_METRIC_COUNT_LOCAL_FILTERS = 23
Public Const ACM_METRIC_COUNT_LOCAL_DISABLED = 24
Public Const ACM_METRIC_HARDWARE_WAVE_INPUT = 30
Public Const ACM_METRIC_HARDWARE_WAVE_OUTPUT = 31
Public Const ACM_METRIC_MAX_SIZE_FORMAT = 50
Public Const ACM_METRIC_MAX_SIZE_FILTER = 51
Public Const ACM_METRIC_DRIVER_SUPPORT = 100
Public Const ACM_METRIC_DRIVER_PRIORITY = 101


'typedef bool(CALLBACK * ACMDRIVERENUMCB)
'(
'    HACMDRIVERID            hadid,
'    long_PTR               dwInstance,
'    long                   fdwSupport
');
Declare Function acmDriverEnum Lib "msacm32.dll" (ByVal fnCallback As Long, ByVal dwInstance As Long, ByVal fdwEnum As Long) As Long

Public Const ACM_DRIVERENUMF_NOLOCAL = &H40000000
Public Const ACM_DRIVERENUMF_DISABLED = &H80000000

Declare Function acmDriverID Lib "msacm32.dll" (ByVal hacmobjHao As Long, ByRef hAcmDriverId As Long, ByVal fdwDriverID As Long) As Long

Declare Function acmDriverAdd Lib "msacm32.dll" Alias "acmDriverAddA" (ByRef hAcmDriverId As Long, ByVal hinstModule As Long, ByVal lParam As Long, ByVal dwPriority As Long, ByVal fdwAdd As Long) As Long

Public Const ACM_DRIVERADDF_NAME = &H1
Public Const ACM_DRIVERADDF_FUNCTION = &H3
Public Const ACM_DRIVERADDF_NOTIFYHWND = &H4
Public Const ACM_DRIVERADDF_TYPEMASK = &H7
Public Const ACM_DRIVERADDF_LOCAL = &H0
Public Const ACM_DRIVERADDF_GLOBAL = &H8


'typedef long (CALLBACK *ACMDRIVERPROC)(long_PTR, HACMDRIVERID, UINT, LPARAM, LPARAM);
'typedef ACMDRIVERPROC FAR *LPACMDRIVERPROC;

Declare Function acmDriverRemove Lib "msacm32.dll" (ByVal hAcmDriverId As Long, ByVal fdwRemove As Long) As Long

Declare Function acmDriverOpen Lib "msacm32.dll" (ByVal phacmdriver As Long, ByVal hAcmDriverId As Long, ByVal fdwOpen As Long)

Declare Function acmDriverClose Lib "msacm32.dll" (ByVal hAcmDriver As Long, ByVal fdwClose As Long) As Long
Declare Function acmDriverMessage Lib "msacm32.dll" (ByVal hAcmDriver As Long, ByVal uMsg As Long, ByVal lParam1 As Long, ByVal lParam2 As Long) As Long

Public Const ACMDM_USER = (DRV_USER + &H0)
Public Const ACMDM_RESERVED_LOW = (DRV_USER + &H2000)
Public Const ACMDM_RESERVED_HIGH = (DRV_USER + &H2FFF)

Public Const ACMDM_BASE = ACMDM_RESERVED_LOW

Public Const ACMDM_DRIVER_ABOUT = (ACMDM_BASE + 11)


Declare Function acmDriverPriority Lib "msacm32.dll" (ByVal hAcmDriverId As Long, ByVal dwPriority As Long, ByVal fdwPriority As Long) As Long

Public Const ACM_DRIVERPRIORITYF_ENABLE = &H1
Public Const ACM_DRIVERPRIORITYF_DISABLE = &H2
Public Const ACM_DRIVERPRIORITYF_ABLEMASK = &H3
Public Const ACM_DRIVERPRIORITYF_BEGIN = &H10000
Public Const ACM_DRIVERPRIORITYF_END = &H20000
Public Const ACM_DRIVERPRIORITYF_DEFERMASK = &H30000

Public Const ACMDRIVERDETAILS_SHORTNAME_CHARS = 32
Public Const ACMDRIVERDETAILS_LONGNAME_CHARS = 128
Public Const ACMDRIVERDETAILS_COPYRIGHT_CHARS = 80
Public Const ACMDRIVERDETAILS_LICENSING_CHARS = 128
Public Const ACMDRIVERDETAILS_FEATURES_CHARS = 512

Type acmDriverDetails
        cbStruct As Long
        fccType As Long
        fccComp As Long
        wMid As Integer
        wPid As Integer
        vdwACM As Long
        vdwDriver As Long
        fdwSupport As Long
        cFormatTags As Long
        cFilterTags As Long
        hIcon As Long
        szShortName(0 To ACMDRIVERDETAILS_SHORTNAME_CHARS - 1) As Byte
        szLongName(0 To ACMDRIVERDETAILS_LONGNAME_CHARS - 1) As Byte
        szCopyright(0 To ACMDRIVERDETAILS_COPYRIGHT_CHARS - 1) As Byte
        szLicensing(0 To ACMDRIVERDETAILS_LICENSING_CHARS - 1) As Byte
        szFeature(0 To ACMDRIVERDETAILS_FEATURES_CHARS - 1) As Byte
End Type

Public Const ACMDRIVERDETAILS_FCCTYPE_AUDIOCODEC = &H43445541 'mmioFOURCC('a', 'u', 'd', 'c')
Public Const ACMDRIVERDETAILS_FCCCOMP_UNDEFINED = 0 'mmioFOURCC('\0', '\0', '\0', '\0')

Public Const ACMDRIVERDETAILS_SUPPORTF_CODEC = &H1&
Public Const ACMDRIVERDETAILS_SUPPORTF_CONVERTER = &H2&
Public Const ACMDRIVERDETAILS_SUPPORTF_FILTER = &H4&
Public Const ACMDRIVERDETAILS_SUPPORTF_HARDWARE = &H8&
Public Const ACMDRIVERDETAILS_SUPPORTF_ASYNC = &H10&
Public Const ACMDRIVERDETAILS_SUPPORTF_LOCAL = &H40000000
Public Const ACMDRIVERDETAILS_SUPPORTF_DISABLED = &H80000000

Declare Function acmDriverDetails Lib "msacm32.dll" Alias "acmDriverDetailsA" (ByVal hAcmDriverId As Long, padd As acmDriverDetails, ByVal fdwDetails As Long) As Long

Public Const ACMFORMATTAGDETAILS_FORMATTAG_CHARS = 48

Type acmFormatTagDetails
        cbStruct As Long
        dwFormatTagIndex As Long
        dwFormatTag As Long
        cbFormatSize As Long
        fdwSupport As Long
        cStandardFormats As Long
        szFormatTag(0 To ACMFORMATTAGDETAILS_FORMATTAG_CHARS - 1) As Byte
End Type

Declare Function acmFormatTagDetails Lib "msacm32.dll" Alias "acmFormatTagDetailsA" (ByVal hAcmDriver As Long, paftd As acmFormatTagDetails, ByVal fdwDetails As Long) As Long

Public Const ACM_FORMATTAGDETAILSF_INDEX = &H0&
Public Const ACM_FORMATTAGDETAILSF_FORMATTAG = &H1&
Public Const ACM_FORMATTAGDETAILSF_LARGESTSIZE = &H2&
Public Const ACM_FORMATTAGDETAILSF_QUERYMASK = &HF&

'typedef bool(CALLBACK * ACMFORMATTAGENUMCBA)
'(
'    HACMDRIVERID            hadid,
'    LPACMFORMATTAGDETAILSA  paftd,
'    long_PTR               dwInstance,
'    long                   fdwSupport
');

Declare Function acmFormatTagEnum Lib "msacm32.dll" Alias "acmFormatTagEnumA" (ByVal hAcmDriver As Long, paftd As acmFormatTagDetails, ByVal fnCallback As Long, ByVal dwInstance As Long, ByVal fdwEnum As Long) As Long

Public Const ACMFORMATDETAILS_FORMAT_CHARS = 128

Type acmFormatDetails
        cbStruct As Long
        dwFormatIndex As Long
        dwFormatTag As Long
        fdwSupport As Long
        pwfx As Long
        cbwfx As Long
        szFormat(0 To ACMFORMATDETAILS_FORMAT_CHARS - 1) As Byte
End Type

Declare Function acmFormatDetails Lib "msacm32.dll" Alias "acmFormatDetailsA" (ByVal hAcmDriver As Long, pafd As acmFormatDetails, ByVal fdwDetails As Long) As Long

Public Const ACM_FORMATDETAILSF_INDEX = &H0&
Public Const ACM_FORMATDETAILSF_FORMAT = &H1&
Public Const ACM_FORMATDETAILSF_QUERYMASK = &HF&

'typedef bool(CALLBACK * ACMFORMATENUMCBA)
'(
'    HACMDRIVERID            hadid,
'    LPACMFORMATDETAILSA     pafd,
'    long_PTR               dwInstance,
'    long                   fdwSupport
');

Declare Function acmFormatEnum Lib "msacm32.dll" Alias "acmFormatEnumA" (ByVal hAcmDriver As Long, pafd As acmFormatDetails, ByVal fnCallback As Long, ByVal dwInstance As Long, ByVal fdwEnum As Long) As Long


Public Const ACM_FORMATENUMF_WFORMATTAG = &H10000
Public Const ACM_FORMATENUMF_NCHANNELS = &H20000
Public Const ACM_FORMATENUMF_NSAMPLESPERSEC = &H40000
Public Const ACM_FORMATENUMF_WBITSPERSAMPLE = &H80000
Public Const ACM_FORMATENUMF_CONVERT = &H100000
Public Const ACM_FORMATENUMF_SUGGEST = &H200000
Public Const ACM_FORMATENUMF_HARDWARE = &H400000
Public Const ACM_FORMATENUMF_INPUT = &H800000
Public Const ACM_FORMATENUMF_OUTPUT = &H1000000


Declare Function acmFormatSuggest Lib "msacm32.dll" (ByVal had As Long, pwfxSrc As WAVEFORMATEX, pwfxDst As WAVEFORMATEX, ByVal cbwfxDst As Long, ByVal fdwSuggest As Long) As Long

Public Const ACM_FORMATSUGGESTF_WFORMATTAG = &H10000
Public Const ACM_FORMATSUGGESTF_NCHANNELS = &H20000
Public Const ACM_FORMATSUGGESTF_NSAMPLESPERSEC = &H40000
Public Const ACM_FORMATSUGGESTF_WBITSPERSAMPLE = &H80000

Public Const ACM_FORMATSUGGESTF_TYPEMASK = &HFF0000

Public Const ACMHELPMSGSTRING = "acmchoose_help"
Public Const ACMHELPMSGCONTEXTMENU = "acmchoose_contextmenu"
Public Const ACMHELPMSGCONTEXTHELP = "acmchoose_contexthelp"

Public Const MM_ACM_FORMATCHOOSE = (&H8000)

Public Const FORMATCHOOSE_MESSAGE = 0
Public Const FORMATCHOOSE_FORMATTAG_VERIFY = (FORMATCHOOSE_MESSAGE + 0)
Public Const FORMATCHOOSE_FORMAT_VERIFY = (FORMATCHOOSE_MESSAGE + 1)
Public Const FORMATCHOOSE_CUSTOM_VERIFY = (FORMATCHOOSE_MESSAGE + 2)

'
'typedef UINT(CALLBACK * ACMFORMATCHOOSEHOOKPROC)
'(
'    HWND                    hwnd,
'    UINT                    uMsg,
'    WPARAM                  wParam,
'    lParam lParam
');

Type acmFormatChoose
        cbStruct As Long
        fdwStyle As Long
        hwndOwner As Long
        pwfx As Long
        cbwfx As Long
        pszTitle As Long
        szFormatTag(0 To ACMFORMATTAGDETAILS_FORMATTAG_CHARS - 1) As Byte
        szFormat(0 To ACMFORMATDETAILS_FORMAT_CHARS - 1) As Byte
        pszName As Long
        cchName As Long
        fdwEnum As Long
        pwfxEnum As Long
        hInstance As Long
        pszTemplateName As Long
        lCustData As Long
        pfnHook As Long
End Type

Public Const ACMFORMATCHOOSE_STYLEF_SHOWHELP = &H4&
Public Const ACMFORMATCHOOSE_STYLEF_ENABLEHOOK = &H8&
Public Const ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATE = &H10&
Public Const ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATEHANDLE = &H20&
Public Const ACMFORMATCHOOSE_STYLEF_INITTOWFXSTRUCT = &H40&
Public Const ACMFORMATCHOOSE_STYLEF_CONTEXTHELP = &H80&

Declare Function acmFormatChoose Lib "msacm32.dll" Alias "acmFormatChooseA" (pafc As acmFormatChoose) As Long

Public Const ACMFILTERTAGDETAILS_FILTERTAG_CHARS = 48

Type acmFilterTagDetails
        cbStruct As Long
        dwFilterTagIndex As Long
        dwFilterTag As Long
        cbFilterSize As Long
        fdwSupport As Long
        cStandardFilters As Long
        szFilterTag(0 To ACMFILTERTAGDETAILS_FILTERTAG_CHARS - 1) As Byte
End Type

Declare Function acmFilterTagDetails Lib "msacm32.dll" Alias "acmFilterTagDetailsA" (ByVal hAcmDriver As Long, paftd As acmFilterTagDetails, ByVal fdwDetails As Long) As Long

Public Const ACM_FILTERTAGDETAILSF_INDEX = &H0&
Public Const ACM_FILTERTAGDETAILSF_FILTERTAG = &H1&
Public Const ACM_FILTERTAGDETAILSF_LARGESTSIZE = &H2&
Public Const ACM_FILTERTAGDETAILSF_QUERYMASK = &HF&

Declare Function acmFilterTagEnum Lib "msacm32.dll" (ByVal had As Long, paftd As acmFilterTagDetails, ByVal fnCallback As Long, ByVal dwInstance As Long, ByVal fdwEnum As Long) As Long

Public Const ACMFILTERDETAILS_FILTER_CHARS = 128

Type acmFilterDetails
        cbStruct As Long
        dwFilterIndex As Long
        dwFilterTag As Long
        fdwSupport As Long
        pwavefilter As Long
        cbwavefilter As Long
        szFilter(0 To ACMFILTERDETAILS_FILTER_CHARS - 1) As Byte
End Type

Declare Function acmFilterDetails Lib "msacm32.dll" Alias "acmFilterDetailsA" (ByVal had As Long, pafd As acmFilterDetails, ByVal fdwDetails As Long) As Long

Public Const ACM_FILTERDETAILSF_INDEX = &H0&
Public Const ACM_FILTERDETAILSF_FILTER = &H1&
Public Const ACM_FILTERDETAILSF_QUERYMASK = &HF&

'typedef bool(CALLBACK * ACMFILTERENUMCB)
'(
'    HACMDRIVERID            hadid,
'    LPACMFILTERDETAILS      pafd,
'    long_PTR               dwInstance,
'    long                   fdwSupport
');

Declare Function acmFilterEnum Lib "msacm32.dll" Alias "acmFilterEnumA" (ByVal had As Long, pafd As acmFilterDetails, ByVal fnCallback As Long, ByVal dwInstance As Long, ByVal fdwEnum As Long) As Long

Public Const ACM_FILTERENUMF_DWFILTERTAG = &H10000

Public Const MM_ACM_FILTERCHOOSE = (&H8000)

Public Const FILTERCHOOSE_MESSAGE = 0
Public Const FILTERCHOOSE_FILTERTAG_VERIFY = (FILTERCHOOSE_MESSAGE + 0)
Public Const FILTERCHOOSE_FILTER_VERIFY = (FILTERCHOOSE_MESSAGE + 1)
Public Const FILTERCHOOSE_CUSTOM_VERIFY = (FILTERCHOOSE_MESSAGE + 2)

'typedef UINT(CALLBACK * ACMFILTERCHOOSEHOOKPROC)
'(
'    HWND                    hwnd,
'    UINT                    uMsg,
'    WPARAM                  wParam,
'    lParam lParam
');

Type acmFilterChoose
        cbStruct As Long
        fdwStyle As Long
        hwndOwner As Long
        pwfltr As Long
        cbwfltr As Long
        pszTitle As Long
        szFilterTag(0 To ACMFILTERTAGDETAILS_FILTERTAG_CHARS - 1) As Byte
        szFilter(0 To ACMFILTERDETAILS_FILTER_CHARS - 1) As Byte
        pszName As Long
        cchName As Long
        fdwEnum As Long
        pwfltrEnum As Long
        hInstance As Long
        pszTemplateName As Long
        lCustData As Long
        pfnHook As Long
End Type

Public Const ACMFILTERCHOOSE_STYLEF_SHOWHELP = &H4&
Public Const ACMFILTERCHOOSE_STYLEF_ENABLEHOOK = &H8&
Public Const ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATE = &H10&
Public Const ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATEHANDLE = &H20&
Public Const ACMFILTERCHOOSE_STYLEF_INITTOFILTERSTRUCT = &H40&
Public Const ACMFILTERCHOOSE_STYLEF_CONTEXTHELP = &H80&

Declare Function acmFilterChoose Lib "msacm32.dll" Alias "acmFilterChooseA" (ByVal pafltrc As acmFilterChoose) As Long

Public Const u_DRVRESERVED = 10

Type ACMSTREAMHEADER
        cbStruct As Long
        fdwStatus As Long
        dwUser As Long
        pbSrc As Long
        cbSrcLength As Long
        cbSrcLengthUsed As Long
        dwSrcUser As Long
        pbDst As Long
        cbDstLength As Long
        cbDstLengthUsed As Long
        dwDstUser As Long
        dwReservedDriver(0 To u_DRVRESERVED - 1) As Long
End Type

Public Const ACMSTREAMHEADER_STATUSF_DONE = &H10000
Public Const ACMSTREAMHEADER_STATUSF_PREPARED = &H20000
Public Const ACMSTREAMHEADER_STATUSF_INQUEUE = &H100000

Declare Function acmStreamOpen Lib "msacm32.dll" (ByRef phacmstream As Long, ByVal hAcmDriver As Long, pwfxSrc As WAVEFORMATEX, pwfxDst As WAVEFORMATEX, ByVal pwfltr As Long, ByVal dwCllback As Long, ByVal dwInstance As Long, ByVal fdwOpen As Long) As Long

Public Const ACM_STREAMOPENF_QUERY = &H1
Public Const ACM_STREAMOPENF_ASYNC = &H2
Public Const ACM_STREAMOPENF_NONREALTIME = &H4

Declare Function acmStreamClose Lib "msacm32.dll" (ByVal hacmstream As Long, ByVal fdwClose As Long) As Long

Declare Function acmStreamSize Lib "msacm32.dll" (ByVal hacmstream As Long, ByVal cbInput As Long, ByVal pdwOutputBytes As Long, ByVal fdwSize As Long) As Long

Public Const ACM_STREAMSIZEF_SOURCE = &H0&
Public Const ACM_STREAMSIZEF_DESTINATION = &H1&
Public Const ACM_STREAMSIZEF_QUERYMASK = &HF&


Declare Function acmStreamReset Lib "msacm32.dll" (ByVal hacmstream As Long, ByVal fdwReset As Long) As Long

Declare Function acmStreamMessage Lib "msacm32.dll" (ByVal hacmstream As Long, ByVal uMsg As Long, ByVal lParam1 As Long, ByVal lParam2 As Long) As Long

Declare Function acmStreamConvert Lib "msacm32.dll" (ByVal hacmstream As Long, ByVal pash As ACMSTREAMHEADER, ByVal fdwConvert As Long) As Long

Public Const ACM_STREAMCONVERTF_BLOCKALIGN = &H4
Public Const ACM_STREAMCONVERTF_START = &H10
Public Const ACM_STREAMCONVERTF_END = &H20


Declare Function acmStreamPrepareHeader Lib "msacm32.dll" (ByVal hacmstream As Long, pash As ACMSTREAMHEADER, ByVal fdwPrepare As Long) As Long

Declare Function acmStreamUnprepareHeader Lib "msacm32.dll" (ByVal hacmstream As Long, pash As ACMSTREAMHEADER, ByVal fdwUnprepare As Long) As Long

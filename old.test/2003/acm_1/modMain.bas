Attribute VB_Name = "modMain"
Option Explicit


Public ggDD As acmDriverDetails
Public ggFiC As acmFilterChoose
Public ggFiD As acmFilterDetails
Public ggFiTD As acmFilterTagDetails
Public ggFoC As acmFormatChoose
Public ggFoD As acmFormatDetails
Public ggFoTD As acmFormatTagDetails
Public ggSH As ACMSTREAMHEADER
Public ggFC As FOURCC
Public ggWFX As WAVEFORMATEX

Private l_S As New lowxtool.String
Private l_P As New LowXRuntime.Pointer
Public Function atos(a() As Byte, Optional ByVal offset As Long = 0) As String
        atos = l_S.saveAscizString(l_P.pByte(a(offset)))
End Function

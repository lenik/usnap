Attribute VB_Name = "modLowAPI"
Option Explicit

Declare Function GetEAX Lib "LowAPI" Alias "__eax" () As Long
Declare Function SetEAX Lib "LowAPI" Alias "__eax_" (ByVal V As Long) As Long
Declare Function GetEBX Lib "LowAPI" Alias "__ebx" () As Long
Declare Function SetEBX Lib "LowAPI" Alias "__ebx_" (ByVal V As Long) As Long
Declare Function GetECX Lib "LowAPI" Alias "__ecx" () As Long
Declare Function SetECX Lib "LowAPI" Alias "__ecx_" (ByVal V As Long) As Long
Declare Function GetEDX Lib "LowAPI" Alias "__edx" () As Long
Declare Function SetEDX Lib "LowAPI" Alias "__edx_" (ByVal V As Long) As Long
Declare Function GetESI Lib "LowAPI" Alias "__esi" () As Long
Declare Function SetESI Lib "LowAPI" Alias "__esi_" (ByVal V As Long) As Long
Declare Function GetEDI Lib "LowAPI" Alias "__edi" () As Long
Declare Function SetEDI Lib "LowAPI" Alias "__edi_" (ByVal V As Long) As Long
Declare Function GetESP Lib "LowAPI" Alias "__esp" () As Long
Declare Function SetESP Lib "LowAPI" Alias "__esp_" (ByVal V As Long) As Long
Declare Function GetEBP Lib "LowAPI" Alias "__ebp" () As Long
Declare Function SetEBP Lib "LowAPI" Alias "__ebp_" (ByVal V As Long) As Long
Declare Function GetEFlags Lib "LowAPI" Alias "__eflags" () As Long
Declare Function SetEFlags Lib "LowAPI" Alias "__eflags_" (ByVal V As Long) As Long
Declare Function GetCS Lib "LowAPI" Alias "__cs" () As Integer
Declare Function SetCS Lib "LowAPI" Alias "__cs_" (ByVal V As Integer) As Integer
Declare Function GetDS Lib "LowAPI" Alias "__ds" () As Integer
Declare Function SetDS Lib "LowAPI" Alias "__ds_" (ByVal V As Integer) As Integer
Declare Function GetES Lib "LowAPI" Alias "__es" () As Integer
Declare Function SetES Lib "LowAPI" Alias "__es_" (ByVal V As Integer) As Integer
Declare Function GetSS Lib "LowAPI" Alias "__ss" () As Integer
Declare Function SetSS Lib "LowAPI" Alias "__ss_" (ByVal V As Integer) As Integer
Declare Function GetFS Lib "LowAPI" Alias "__fs" () As Integer
Declare Function SetFS Lib "LowAPI" Alias "__fs_" (ByVal V As Integer) As Integer
Declare Function GetGS Lib "LowAPI" Alias "__gs" () As Integer
Declare Function SetGS Lib "LowAPI" Alias "__gs_" (ByVal V As Integer) As Integer

Declare Sub SaveSafePoint Lib "LowAPI" ()
Declare Sub ssp Lib "LowAPI" Alias "SaveSafePoint" ()
Declare Function GetSafePoint_Global Lib "LowAPI" () As Long
Declare Function SetSafePoint_Global Lib "LowAPI" (ByVal V As Long) As Long
Declare Function GetSafePoint_TLS Lib "LowAPI" () As Long
Declare Function SetSafePoint_TLS Lib "LowAPI" (ByVal V As Long) As Long
Declare Function GetSafePoint Lib "LowAPI" () As Long
Declare Function SetSafePoint Lib "LowAPI" (ByVal V As Long) As Long
Declare Function GetSafePointReference Lib "LowAPI" () As Long
Declare Function SetTLSSafePoint Lib "LowAPI" () As Long
Declare Function SetGlobalSafePoint Lib "LowAPI" () As Long

Declare Function ALCCVerifyStep1 Lib "LowAPI" Alias "__alcc_verify_step1" () As Long
Declare Sub ALCCVerifyStep2 Lib "LowAPI" Alias "__alcc_verify_step2" (ByVal ALCC As Long)
Declare Sub ALCCVerifyStep3 Lib "LowAPI" Alias "__alcc_verify_step3" (ByVal ALCC As Long)

Declare Sub NxP Lib "LowAPI" Alias "NpP" ()
Declare Sub NPx Lib "LowAPI" Alias "NPp" ()
Declare Sub PNx Lib "LowAPI" Alias "PNp" ()
Declare Sub PxN Lib "LowAPI" Alias "PpN" ()
Declare Sub xNP Lib "LowAPI" Alias "pNP" ()
Declare Sub xPN Lib "LowAPI" Alias "pPN" ()
Declare Sub SPx Lib "LowAPI" Alias "SPp" ()
Declare Sub xPM Lib "LowAPI" Alias "pPM" ()
Declare Sub PxM Lib "LowAPI" Alias "PpM" ()

Declare Function Tcdecl CDecl Lib "LowAPI" Alias "_t_cdecl" (ret As Long) As Long
Declare Function Tstdcall Lib "LowAPI" Alias "_t_stdcall" (ret As Long) As Long

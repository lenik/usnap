Attribute VB_Name = "modFastImage"
Option Explicit

Public Const BITBLT_SIMPLE = 1&
Public Const BITBLT_BIDIRECTION = 2&
Public Const BITBLT_ALPHA = 3&
Public Const BITBLT_ALPHA_H = 4&
Public Const BITBLT_ALPHA_V = 5&
Public Const BITBLT_EXTEND = &HFF&
Public Const BITBLT_ONLYDEST = &H100&
Public Const BITBLT_ONLYSRC = &H200&
Public Const BITBLT_TESTBITMAP = &H10000
Public Const BITBLT_TESTCALLBACK = &H20000

Public Const FI_DESTKEY = &H0&
Public Const FI_SRCKEY = &H1000000

Public Const FI_GETADDRESS = 0
Public Const FI_GETVAL = 1
Public Const FI_SETVAL = 2

Public Const FI_VAR_RUNNING = 0&
Public Const FI_VAR_ALPHA1 = 1&
Public Const FI_VAR_ALPHA2 = 2&
Public Const FI_VAR_X = 3&
Public Const FI_VAR_Y = 4&
Public Const FI_VAR_WIDTH = 5&
Public Const FI_VAR_HEIGHT = 6&
Public Const FI_VAR_P = 7&
Public Const FI_VAR_ALPHAT = 10&
Public Const FI_VAR_ALPHAC = 11&
Public Const FI_VAR_BITSDEST = 12&
Public Const FI_VAR_BITSSRC = 13&
Public Const FI_VAR_SIZEDEST = 14&
Public Const FI_VAR_SIZESRC = 15&

' DWORD CallBack(...)
Declare Function BitBltFn Lib "FastImg" Alias "FIBBF" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal fntype As Long, ByVal lParam As Long, ByVal dwParam As Long) As Boolean
' DWORD CallBack(DWORD cSrc, DWORD cDest)
Declare Function BitBltSimpleFn Lib "FastImg" Alias "FIBBSF" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal addrCallback As Long) As Boolean
' DWORD CallBack(DWORD cSrc, DWORD cDest, DWORD alpha)
Declare Function BitBltAlphaFn Lib "FastImg" Alias "FIBBAF" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal addrCallback As Long, ByVal dwParam As Long) As Boolean
' BOOL  CallBack(LPDWORD pcDest, LPDWORD pcSrc, LONG width, LONG height, DWORD param)
Declare Function BitBltExtendFn Lib "FastImg" Alias "FIBBEF" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal addrCallback As Long, ByVal dwParam As Long) As Boolean

Declare Function BitBltAdd Lib "FastImg" Alias "FIBBSA" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long) As Boolean
Declare Function BitBltSub Lib "FastImg" Alias "FIBBSS" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long) As Boolean
Declare Function BitBltMul Lib "FastImg" Alias "FIBBSM" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal Factor As Long) As Boolean
Declare Function BitBltDiv Lib "FastImg" Alias "FIBBSD" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal Factor As Long) As Boolean
Declare Function BitBltMerge Lib "FastImg" Alias "FIBBM" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal cKey As Long) As Boolean
Declare Function BitBltAlphaSimple Lib "FastImg" Alias "FIBBAS" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal alpha As Long) As Boolean
Declare Function BitBltAlphaMerge Lib "FastImg" Alias "FIBBAM" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal alpha As Long, ByVal key As Long) As Boolean
Declare Function BitBltAlphaH Lib "FastImg" Alias "FIBBLAH" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal alphaTop As Long, ByVal alphaBottom As Long) As Boolean
Declare Function BitBltAlphaV Lib "FastImg" Alias "FIBBLAV" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal alphaLeft As Long, ByVal alphaRight As Long) As Boolean
Declare Function BitBltAlphaEx Lib "FastImg" Alias "FIBBLAEx" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal alphaAngleFromCenter As Long) As Boolean

Declare Function FIBB_Copy Lib "FastImg" Alias "FIBBC_C" (ByVal cdest As Long, ByVal csrc As Long) As Long
Declare Function FIBB_Order Lib "FastImg" Alias "FIBBC_O" (ByVal cdest As Long, ByVal csrc As Long) As Long
Declare Function FIBB_Add Lib "FastImg" Alias "FIBBC_A" (ByVal cdest As Long, ByVal csrc As Long) As Long
Declare Function FIBB_Sub Lib "FastImg" Alias "FIBBC_S" (ByVal cdest As Long, ByVal csrc As Long) As Long
Declare Function FIBB_Mul Lib "FastImg" Alias "FIBBC_M" (ByVal cdest As Long, ByVal csrc As Long) As Long
Declare Function FIBB_Div Lib "FastImg" Alias "FIBBC_D" (ByVal cdest As Long, ByVal csrc As Long) As Long
Declare Function FIBB_Light Lib "FastImg" Alias "FIBBCL" (ByVal cdest As Long, ByVal csrc As Long) As Long
Declare Function FIBB_Dark Lib "FastImg" Alias "FIBBCD" (ByVal cdest As Long, ByVal csrc As Long) As Long
Declare Function FIBB_Merge Lib "FastImg" Alias "FIBBCM" (ByVal cdest As Long, ByVal csrc As Long, ByVal key As Long) As Long
Declare Function FIBB_Alpha Lib "FastImg" Alias "FIBBCA" (ByVal cdest As Long, ByVal csrc As Long, ByVal key As Long) As Long
Declare Function FIBB_AlphaMerge Lib "FastImg" Alias "FIBBCAM" (ByVal cdest As Long, ByVal csrc As Long, ByVal alpha As Long) As Long

Declare Function FIBB_SwitchChannels Lib "FastImg" Alias "FIBBCSC" (ByVal c As Long, ByVal newOrder As Byte) As Long
Declare Function FIBB_Rgb_To_Bgr Lib "FastImg" Alias "FIBBR2B" (ByVal c As Long) As Long

Declare Function FIIA Lib "FastImg" (ByVal newA As Long) As Boolean
Declare Function FIBB_Var Lib "FastImg" (ByVal Op As Long, ByVal Index As Long, Optional ByVal dwParam As Long = 0) As Long
Declare Function FIBB_GetAlpha Lib "FastImg" (ByVal alpha As Long, ByVal color As Long) As Byte

Declare Function FIBB_Unit24 Lib "FastImg" Alias "FIBBATGU24" (ByVal pBase As Long, ByVal Width As Long, ByVal X As Long, ByVal Y As Long) As Long
Declare Function FIBB_Unit32 Lib "FastImg" Alias "FIBBATGU32" (ByVal pBase As Long, ByVal Width As Long, ByVal X As Long, ByVal Y As Long) As Long
Declare Function FIBB_GetColor Lib "FastImg" Alias "FIBBATG" (ByVal pColor As Long, Optional ByVal offset As Long = 0) As Long
Declare Function FIBB_SetColor Lib "FastImg" Alias "FIBBATS" (ByVal pColor As Long, ByVal val As Long, Optional ByVal offset As Long = 0) As Long

Declare Function BitBltBlur Lib "FastImg" Alias "FIBBEB" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal blurOption As Long) As Boolean
Declare Function BitBltGradient Lib "FastImg" Alias "FIBBEG" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal color1 As Long, ByVal color2 As Long, ByVal bVertical As Boolean) As Boolean
Declare Function BitBltBrick Lib "FastImg" Alias "FIBBEBr" (ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal brickOption As Long) As Boolean

Public Function FIBB_Running() As Boolean: FIBB_Running = FIBB_Var(FI_GETVAL, FI_VAR_RUNNING): End Function
Public Function FIBB_NoRun() As Boolean: FIBB_Var FI_SETVAL, FI_VAR_RUNNING, 0: End Function

Public Function BB_Copy(ByVal cdest As Long, ByVal csrc As Long) As Long: BB_Copy = csrc: End Function
Public Function BB_Light(ByVal cdest As Long, ByVal csrc As Long) As Long: BB_Light = FIBB_Light(cdest, csrc): End Function
Public Function BB_Dark(ByVal cdest As Long, ByVal csrc As Long) As Long: BB_Dark = FIBB_Dark(cdest, csrc): End Function
Public Function BB_Merge(ByVal cdest As Long, ByVal csrc As Long, ByVal cKey As Long) As Long: BB_Merge = FIBB_Merge(cdest, csrc, cKey): End Function
Public Function BB_Alpha(ByVal cdest As Long, ByVal csrc As Long, ByVal nAlpha As Long) As Long: BB_Alpha = FIBB_Alpha(cdest, csrc, nAlpha): End Function
Public Function BB_RedChannel(ByVal cdest As Long, ByVal csrc As Long) As Long: BB_RedChannel = cdest And &HFF0000: End Function
Public Function BB_GreenChannel(ByVal cdest As Long, ByVal csrc As Long) As Long: BB_GreenChannel = cdest And &HFF00&: End Function
Public Function BB_BlueChannel(ByVal cdest As Long, ByVal csrc As Long) As Long: BB_BlueChannel = cdest And &HFF&: End Function

Public Function BitBltLight(ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long) As Boolean
        BitBltLight = BitBltSimpleFn(hDestDC, destx, desty, Width, Height, hSrcDC, srcx, srcy, AddressOf BB_Light)
End Function
Public Function BitBltDark(ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal hSrcDC As Long, ByVal srcx As Long, ByVal srcy As Long) As Boolean
        BitBltDark = BitBltSimpleFn(hDestDC, destx, desty, Width, Height, hSrcDC, srcx, srcy, AddressOf BB_Dark)
End Function

Public Function BitBltColor(ByVal hDestDC As Long, ByVal destx As Long, ByVal desty As Long, ByVal Width As Long, ByVal Height As Long, ByVal fcolor As Long, Optional ByVal alpha As Long = 0) As Boolean
        FIBB_Var FI_SETVAL, FI_VAR_ALPHA1, fcolor
        If alpha = 0 Then
                BitBltColor = BitBltFn(hDestDC, destx, desty, Width, Height, 0, 0, 0, _
                                BITBLT_SIMPLE Or BITBLT_ONLYDEST, AddressOf BB_Copy, 0)
        Else
                BitBltColor = BitBltFn(hDestDC, destx, desty, Width, Height, 0, 0, 0, _
                                BITBLT_ALPHA Or BITBLT_ONLYDEST, AddressOf BB_Alpha, alpha)
        End If
End Function


Public Function Rgb_To_Bgr(ByVal c As Long) As Long
        Rgb_To_Bgr = dwShl(c And &HFF&, 16) Or _
                        (c And &HFF00&) Or _
                        dwShr(c And &HFF0000, 16) Or _
                        (c And &HFF000000)
End Function

Attribute VB_Name = "modWinGDI"

' -------------
'  GDI Section
' -------------

' Binary raster ops
Public Const R2_BLACK = 1       '   0
Public Const R2_NOTMERGEPEN = 2 '  DPon
Public Const R2_MASKNOTPEN = 3  '  DPna
Public Const R2_NOTCOPYPEN = 4  '  PN
Public Const R2_MASKPENNOT = 5  '  PDna
Public Const R2_NOT = 6 '  Dn
Public Const R2_XORPEN = 7      '  DPx
Public Const R2_NOTMASKPEN = 8  '  DPan
Public Const R2_MASKPEN = 9     '  DPa
Public Const R2_NOTXORPEN = 10  '  DPxn
Public Const R2_NOP = 11        '  D
Public Const R2_MERGENOTPEN = 12        '  DPno
Public Const R2_COPYPEN = 13    '  P
Public Const R2_MERGEPENNOT = 14        '  PDno
Public Const R2_MERGEPEN = 15   '  DPo
Public Const R2_WHITE = 16      '   1
Public Const R2_LAST = 16

'  Ternary raster operations
Public Const SRCCOPY = &HCC0020         ' (DWORD) dest = source
Public Const SRCPAINT = &HEE0086        ' (DWORD) dest = source OR dest
Public Const SRCAND = &H8800C6          ' (DWORD) dest = source AND dest
Public Const SRCINVERT = &H660046       ' (DWORD) dest = source XOR dest
Public Const SRCERASE = &H440328        ' (DWORD) dest = source AND (NOT dest )
Public Const NOTSRCCOPY = &H330008      ' (DWORD) dest = (NOT source)
Public Const NOTSRCERASE = &H1100A6     ' (DWORD) dest = (NOT src) AND (NOT dest)
Public Const MERGECOPY = &HC000CA       ' (DWORD) dest = (source AND pattern)
Public Const MERGEPAINT = &HBB0226      ' (DWORD) dest = (NOT source) OR dest
Public Const PATCOPY = &HF00021         ' (DWORD) dest = pattern
Public Const PATPAINT = &HFB0A09        ' (DWORD) dest = DPSnoo
Public Const PATINVERT = &H5A0049       ' (DWORD) dest = pattern XOR dest
Public Const DSTINVERT = &H550009       ' (DWORD) dest = (NOT dest)
Public Const BLACKNESS = &H42           ' (DWORD) dest = BLACK
Public Const WHITENESS = &HFF0062       ' (DWORD) dest = WHITE

Public Const GDI_ERROR = &HFFFF
Public Const HGDI_ERROR = &HFFFF

' Region Flags
Public Const ERRORAPI = 0
Public Const NULLREGION = 1
Public Const SIMPLEREGION = 2
Public Const COMPLEXREGION = 3

' CombineRgn() Styles
Public Const RGN_AND = 1
Public Const RGN_OR = 2
Public Const RGN_XOR = 3
Public Const RGN_DIFF = 4
Public Const RGN_COPY = 5
Public Const RGN_MIN = RGN_AND
Public Const RGN_MAX = RGN_COPY

' StretchBlt() Modes
Public Const BLACKONWHITE = 1
Public Const WHITEONBLACK = 2
Public Const COLORONCOLOR = 3
Public Const HALFTONE = 4
Public Const MAXSTRETCHBLTMODE = 4

' PolyFill() Modes
Public Const ALTERNATE = 1
Public Const WINDING = 2
Public Const POLYFILL_LAST = 2

' Text Alignment Options
Public Const TA_NOUPDATECP = 0
Public Const TA_UPDATECP = 1

Public Const TA_LEFT = 0
Public Const TA_RIGHT = 2
Public Const TA_CENTER = 6

Public Const TA_TOP = 0
Public Const TA_BOTTOM = 8
Public Const TA_BASELINE = 24
Public Const TA_MASK = (TA_BASELINE + TA_CENTER + TA_UPDATECP)

Public Const VTA_BASELINE = TA_BASELINE
Public Const VTA_LEFT = TA_BOTTOM
Public Const VTA_RIGHT = TA_TOP
Public Const VTA_CENTER = TA_CENTER
Public Const VTA_BOTTOM = TA_RIGHT
Public Const VTA_TOP = TA_LEFT

Public Const ETO_GRAYED = 1
Public Const ETO_OPAQUE = 2
Public Const ETO_CLIPPED = 4

Public Const ASPECT_FILTERING = &H1

Public Const DCB_RESET = &H1
Public Const DCB_ACCUMULATE = &H2
Public Const DCB_DIRTY = DCB_ACCUMULATE
Public Const DCB_SET = (DCB_RESET Or DCB_ACCUMULATE)
Public Const DCB_ENABLE = &H4
Public Const DCB_DISABLE = &H8

' Metafile Functions
Public Const META_SETBKCOLOR = &H201
Public Const META_SETBKMODE = &H102
Public Const META_SETMAPMODE = &H103
Public Const META_SETROP2 = &H104
Public Const META_SETRELABS = &H105
Public Const META_SETPOLYFILLMODE = &H106
Public Const META_SETSTRETCHBLTMODE = &H107
Public Const META_SETTEXTCHAREXTRA = &H108
Public Const META_SETTEXTCOLOR = &H209
Public Const META_SETTEXTJUSTIFICATION = &H20A
Public Const META_SETWINDOWORG = &H20B
Public Const META_SETWINDOWEXT = &H20C
Public Const META_SETVIEWPORTORG = &H20D
Public Const META_SETVIEWPORTEXT = &H20E
Public Const META_OFFSETWINDOWORG = &H20F
Public Const META_SCALEWINDOWEXT = &H410
Public Const META_OFFSETVIEWPORTORG = &H211
Public Const META_SCALEVIEWPORTEXT = &H412
Public Const META_LINETO = &H213
Public Const META_MOVETO = &H214
Public Const META_EXCLUDECLIPRECT = &H415
Public Const META_INTERSECTCLIPRECT = &H416
Public Const META_ARC = &H817
Public Const META_ELLIPSE = &H418
Public Const META_FLOODFILL = &H419
Public Const META_PIE = &H81A
Public Const META_RECTANGLE = &H41B
Public Const META_ROUNDRECT = &H61C
Public Const META_PATBLT = &H61D
Public Const META_SAVEDC = &H1E
Public Const META_SETPIXEL = &H41F
Public Const META_OFFSETCLIPRGN = &H220
Public Const META_TEXTOUT = &H521
Public Const META_BITBLT = &H922
Public Const META_STRETCHBLT = &HB23
Public Const META_POLYGON = &H324
Public Const META_POLYLINE = &H325
Public Const META_ESCAPE = &H626
Public Const META_RESTOREDC = &H127
Public Const META_FILLREGION = &H228
Public Const META_FRAMEREGION = &H429
Public Const META_INVERTREGION = &H12A
Public Const META_PAINTREGION = &H12B
Public Const META_SELECTCLIPREGION = &H12C
Public Const META_SELECTOBJECT = &H12D
Public Const META_SETTEXTALIGN = &H12E
Public Const META_CHORD = &H830
Public Const META_SETMAPPERFLAGS = &H231
Public Const META_EXTTEXTOUT = &HA32
Public Const META_SETDIBTODEV = &HD33
Public Const META_SELECTPALETTE = &H234
Public Const META_REALIZEPALETTE = &H35
Public Const META_ANIMATEPALETTE = &H436
Public Const META_SETPALENTRIES = &H37
Public Const META_POLYPOLYGON = &H538
Public Const META_RESIZEPALETTE = &H139
Public Const META_DIBBITBLT = &H940
Public Const META_DIBSTRETCHBLT = &HB41
Public Const META_DIBCREATEPATTERNBRUSH = &H142
Public Const META_STRETCHDIB = &HF43
Public Const META_EXTFLOODFILL = &H548
Public Const META_DELETEOBJECT = &H1F0
Public Const META_CREATEPALETTE = &HF7
Public Const META_CREATEPATTERNBRUSH = &H1F9
Public Const META_CREATEPENINDIRECT = &H2FA
Public Const META_CREATEFONTINDIRECT = &H2FB
Public Const META_CREATEBRUSHINDIRECT = &H2FC
Public Const META_CREATEREGION = &H6FF


' GDI Escapes
Public Const NEWFRAME = 1
Public Const AbortDocC = 2
Public Const NEXTBAND = 3
Public Const SETCOLORTABLE = 4
Public Const GETCOLORTABLE = 5
Public Const FLUSHOUTPUT = 6
Public Const DRAFTMODE = 7
Public Const QUERYESCSUPPORT = 8
Public Const SetAbortProc = 9
Public Const StartDocC = 10
Public Const EndDocC = 11
Public Const GETPHYSPAGESIZE = 12
Public Const GETPRINTINGOFFSET = 13
Public Const GETSCALINGFACTOR = 14
Public Const MFCOMMENT = 15
Public Const GETPENWIDTH = 16
Public Const SETCOPYCOUNT = 17
Public Const SELECTPAPERSOURCE = 18
Public Const DEVICEDATA = 19
Public Const PASSTHROUGH = 19
Public Const GETTECHNOLGY = 20
Public Const GETTECHNOLOGY = 20
Public Const SETLINECAP = 21
Public Const SETLINEJOIN = 22
Public Const SetMiterLimitC = 23
Public Const BANDInfo = 24
Public Const DRAWPATTERNRECT = 25
Public Const GETVECTORPENSIZE = 26
Public Const GETVECTORBRUSHSIZE = 27
Public Const ENABLEDUPLEX = 28
Public Const GETSETPAPERBINS = 29
Public Const GETSETPRINTORIENT = 30
Public Const ENUMPAPERBINS = 31
Public Const SETDIBSCALING = 32
Public Const EPSPRINTING = 33
Public Const ENUMPAPERMETRICS = 34
Public Const GETSETPAPERMETRICS = 35
Public Const POSTSCRIPT_DATA = 37
Public Const POSTSCRIPT_IGNORE = 38
Public Const MOUSETRAILS = 39
Public Const GETDEVICEUNITS = 42

Public Const GETEXTENDEDTEXTMETRICS = 256
Public Const GETEXTENTTABLE = 257
Public Const GETPAIRKERNTABLE = 258
Public Const GETTRACKKERNTABLE = 259
Public Const ExtTextOutC = 512
Public Const GETFACENAME = 513
Public Const DOWNLOADFACE = 514
Public Const ENABLERELATIVEWIDTHS = 768
Public Const ENABLEPAIRKERNING = 769
Public Const SETKERNTRACK = 770
Public Const SETALLJUSTVALUES = 771
Public Const SETCHARSET = 772

Public Const StretchBltC = 2048
Public Const GETSETSCREENPARAMS = 3072
Public Const BEGIN_PATH = 4096
Public Const CLIP_TO_PATH = 4097
Public Const END_PATH = 4098
Public Const EXT_DEVICE_CAPS = 4099
Public Const RESTORE_CTM = 4100
Public Const SAVE_CTM = 4101
Public Const SET_ARC_DIRECTION = 4102
Public Const SET_BACKGROUND_COLOR = 4103
Public Const SET_POLY_MODE = 4104
Public Const SET_SCREEN_ANGLE = 4105
Public Const SET_SPREAD = 4106
Public Const TRANSFORM_CTM = 4107
Public Const SET_CLIP_BOX = 4108
Public Const SET_BOUNDS = 4109
Public Const SET_MIRROR_MODE = 4110
Public Const OPENCHANNEL = 4110
Public Const DOWNLOADHEADER = 4111
Public Const CLOSECHANNEL = 4112
Public Const POSTSCRIPT_PASSTHROUGH = 4115
Public Const ENCAPSULATED_POSTSCRIPT = 4116

' Spooler Error Codes
Public Const SP_NOTREPORTED = &H4000
Public Const SP_ERROR = (-1)
Public Const SP_APPABORT = (-2)
Public Const SP_USERABORT = (-3)
Public Const SP_OUTOFDISK = (-4)
Public Const SP_OUTOFMEMORY = (-5)

Public Const PR_JOBSTATUS = &H0

'  Object Definitions for EnumObjects()
Public Const OBJ_PEN = 1
Public Const OBJ_BRUSH = 2
Public Const OBJ_DC = 3
Public Const OBJ_METADC = 4
Public Const OBJ_PAL = 5
Public Const OBJ_FONT = 6
Public Const OBJ_BITMAP = 7
Public Const OBJ_REGION = 8
Public Const OBJ_METAFILE = 9
Public Const OBJ_MEMDC = 10
Public Const OBJ_EXTPEN = 11
Public Const OBJ_ENHMETADC = 12
Public Const OBJ_ENHMETAFILE = 13

'  xform stuff
Public Const MWT_IDENTITY = 1
Public Const MWT_LEFTMULTIPLY = 2
Public Const MWT_RIGHTMULTIPLY = 3

Public Const MWT_MIN = MWT_IDENTITY
Public Const MWT_MAX = MWT_RIGHTMULTIPLY

Type xform
        eM11 As Double
        eM12 As Double
        eM21 As Double
        eM22 As Double
        eDx As Double
        eDy As Double
End Type

' Bitmap Header Definition
Type BITMAP '14 bytes
        bmType As Long
        bmWidth As Long
        bmHeight As Long
        bmWidthBytes As Long
        bmPlanes As Integer
        bmBitsPixel As Integer
        bmBits As Long
End Type

Type RGBTRIPLE
        rgbtBlue As Byte
        rgbtGreen As Byte
        rgbtRed As Byte
End Type

Type RGBQUAD
        rgbBlue As Byte
        rgbGreen As Byte
        rgbRed As Byte
        rgbReserved As Byte
End Type

' structures for defining DIBs
Type BITMAPCOREHEADER '12 bytes
        bcSize As Long
        bcWidth As Integer
        bcHeight As Integer
        bcPlanes As Integer
        bcBitCount As Integer
End Type

Type BITMAPINFOHEADER '40 bytes
        biSize As Long
        biWidth As Long
        biHeight As Long
        biPlanes As Integer
        biBitCount As Integer
        biCompression As Long
        biSizeImage As Long
        biXPelsPerMeter As Long
        biYPelsPerMeter As Long
        biClrUsed As Long
        biClrImportant As Long
End Type

' public constants for the biCompression field
Public Const BI_RGB = 0&
Public Const BI_RLE8 = 1&
Public Const BI_RLE4 = 2&
Public Const BI_bitfields = 3&

Type BITMAPINFO
        bmiHeader As BITMAPINFOHEADER
        bmiColors As RGBQUAD
End Type

Type BITMAPCOREINFO
        bmciHeader As BITMAPCOREHEADER
        bmciColors As RGBTRIPLE
End Type

Type BITMAPFILEHEADER
        bfType As Integer
        bfSize As Long
        bfReserved1 As Integer
        bfReserved2 As Integer
        bfOffBits As Long
End Type


' Clipboard Metafile Picture Structure
Type HANDLETABLE
        objectHandle(1) As Long
End Type

Type METARECORD
        rdSize As Long
        rdFunction As Integer
        rdParm(1) As Integer
End Type


Type METAFILEPICT
        mm As Long
        xExt As Long
        yExt As Long
        hMF As Long
End Type

Type METAHEADER
        mtType As Integer
        mtHeaderSize As Integer
        mtVersion As Integer
        mtSize As Long
        mtNoObjects As Integer
        mtMaxRecord As Long
        mtNoParameters As Integer
End Type

Type ENHMETARECORD
        iType As Long
        nSize As Long
        dParm(1) As Long
End Type

Type SIZEL
    cx As Long
    cy As Long
End Type

Type ENHMETAHEADER
        iType As Long
        nSize As Long
        rclBounds As RECTL
        rclFrame As RECTL
        dSignature As Long
        nVersion As Long
        nBytes As Long
        nRecords As Long
        nHandles As Integer
        sReserved As Integer
        nDescription As Long
        offDescription As Long
        nPalEntries As Long
        szlDevice As SIZEL
        szlMillimeters As SIZEL
End Type

Type TEXTMETRIC
        tmHeight As Long
        tmAscent As Long
        tmDescent As Long
        tmInternalLeading As Long
        tmExternalLeading As Long
        tmAveCharWidth As Long
        tmMaxCharWidth As Long
        tmWeight As Long
        tmOverhang As Long
        tmDigitizedAspectX As Long
        tmDigitizedAspectY As Long
        tmFirstChar As Byte
        tmLastChar As Byte
        tmDefaultChar As Byte
        tmBreakChar As Byte
        tmItalic As Byte
        tmUnderlined As Byte
        tmStruckOut As Byte
        tmPitchAndFamily As Byte
        tmCharSet As Byte
End Type

' ntmFlags field flags
Public Const NTM_REGULAR = &H40&
Public Const NTM_BOLD = &H20&
Public Const NTM_ITALIC = &H1&

' Structure passed to FONTENUMPROC
' NOTE: NEWTEXTMETRIC is the same as TEXTMETRIC plus 4 new fields
Type NEWTEXTMETRIC
        tmHeight As Long
        tmAscent As Long
        tmDescent As Long
        tmInternalLeading As Long
        tmExternalLeading As Long
        tmAveCharWidth As Long
        tmMaxCharWidth As Long
        tmWeight As Long
        tmOverhang As Long
        tmDigitizedAspectX As Long
        tmDigitizedAspectY As Long
        tmFirstChar As Byte
        tmLastChar As Byte
        tmDefaultChar As Byte
        tmBreakChar As Byte
        tmItalic As Byte
        tmUnderlined As Byte
        tmStruckOut As Byte
        tmPitchAndFamily As Byte
        tmCharSet As Byte
        ntmFlags As Long
        ntmSizeEM As Long
        ntmCellHeight As Long
        ntmAveWidth As Long
End Type

'  tmPitchAndFamily flags
Public Const TMPF_FIXED_PITCH = &H1
Public Const TMPF_VECTOR = &H2
Public Const TMPF_DEVICE = &H8
Public Const TMPF_TRUETYPE = &H4


' GDI Logical Objects:

Type PELARRAY
        paXCount As Long
        paYCount As Long
        paXExt As Long
        paYExt As Long
        paRGBs As Integer
End Type

' Logical Brush (or Pattern)
Type LOGBRUSH
        lbStyle As Long
        lbColor As Long
        lbHatch As Long
End Type

' Logical Pen
Type LOGPEN
        lopnStyle As Long
        lopnWidth As POINTAPI
        lopnColor As Long
End Type

Type EXTLOGPEN
        elpPenStyle As Long
        elpWidth As Long
        elpBrushStyle As Long
        elpColor As Long
        elpHatch As Long
        elpNumEntries As Long
        elpStyleEntry(1) As Long
End Type

Type PALETTEENTRY
        peRed As Byte
        peGreen As Byte
        peBlue As Byte
        peFlags As Byte
End Type

' Logical Palette
Type LOGPALETTE
        palVersion As Integer
        palNumEntries As Integer
        palPalEntry(1) As PALETTEENTRY
End Type

' Logical Font
Public Const LF_FACESIZE = 32
Public Const LF_FULLFACESIZE = 64

Type LOGFONT
        lfHeight As Long
        lfWidth As Long
        lfEscapement As Long
        lfOrientation As Long
        lfWeight As Long
        lfItalic As Byte
        lfUnderline As Byte
        lfStrikeOut As Byte
        lfCharSet As Byte
        lfOutPrecision As Byte
        lfClipPrecision As Byte
        lfQuality As Byte
        lfPitchAndFamily As Byte
        lfFaceName(1 To LF_FACESIZE) As Byte
End Type

Type NONCLIENTMETRICS
        cbSize As Long
        iBorderWidth As Long
        iScrollWidth As Long
        iScrollHeight As Long
        iCaptionWidth As Long
        iCaptionHeight As Long
        lfCaptionFont As LOGFONT
        iSMCaptionWidth As Long
        iSMCaptionHeight As Long
        lfSMCaptionFont As LOGFONT
        iMenuWidth As Long
        iMenuHeight As Long
        lfMenuFont As LOGFONT
        lfStatusFont As LOGFONT
        lfMessageFont As LOGFONT
End Type

Type ENUMLOGFONT
        elfLogFont As LOGFONT
        elfFullName(LF_FULLFACESIZE) As Byte
        elfStyle(LF_FACESIZE) As Byte
End Type

Public Const OUT_DEFAULT_PRECIS = 0
Public Const OUT_STRING_PRECIS = 1
Public Const OUT_CHARACTER_PRECIS = 2
Public Const OUT_STROKE_PRECIS = 3
Public Const OUT_TT_PRECIS = 4
Public Const OUT_DEVICE_PRECIS = 5
Public Const OUT_RASTER_PRECIS = 6
Public Const OUT_TT_ONLY_PRECIS = 7
Public Const OUT_OUTLINE_PRECIS = 8

Public Const CLIP_DEFAULT_PRECIS = 0
Public Const CLIP_CHARACTER_PRECIS = 1
Public Const CLIP_STROKE_PRECIS = 2
Public Const CLIP_MASK = &HF
Public Const CLIP_LH_ANGLES = 16
Public Const CLIP_TT_ALWAYS = 32
Public Const CLIP_EMBEDDED = 128

Public Const DEFAULT_QUALITY = 0
Public Const DRAFT_QUALITY = 1
Public Const PROOF_QUALITY = 2

Public Const DEFAULT_PITCH = 0
Public Const FIXED_PITCH = 1
Public Const VARIABLE_PITCH = 2

Public Const ANSI_CHARSET = 0
Public Const DEFAULT_CHARSET = 1
Public Const SYMBOL_CHARSET = 2
Public Const SHIFTJIS_CHARSET = 128
Public Const HANGEUL_CHARSET = 129
Public Const CHINESEBIG5_CHARSET = 136
Public Const OEM_CHARSET = 255

' Font Families
'
Public Const FF_DONTCARE = 0    '  Don't care or don't know.
Public Const FF_ROMAN = 16      '  Variable stroke width, serifed.

' Times Roman, Century Schoolbook, etc.
Public Const FF_SWISS = 32      '  Variable stroke width, sans-serifed.

' Helvetica, Swiss, etc.
Public Const FF_MODERN = 48     '  public constant stroke width, serifed or sans-serifed.

' Pica, Elite, Courier, etc.
Public Const FF_SCRIPT = 64     '  Cursive, etc.
Public Const FF_DECORATIVE = 80 '  Old English, etc.

' Font Weights
Public Const FW_DONTCARE = 0
Public Const FW_THIN = 100
Public Const FW_EXTRALIGHT = 200
Public Const FW_LIGHT = 300
Public Const FW_NORMAL = 400
Public Const FW_MEDIUM = 500
Public Const FW_SEMIBOLD = 600
Public Const FW_BOLD = 700
Public Const FW_EXTRABOLD = 800
Public Const FW_HEAVY = 900

Public Const FW_ULTRALIGHT = FW_EXTRALIGHT
Public Const FW_REGULAR = FW_NORMAL
Public Const FW_DEMIBOLD = FW_SEMIBOLD
Public Const FW_ULTRABOLD = FW_EXTRABOLD
Public Const FW_BLACK = FW_HEAVY

Public Const PANOSE_COUNT = 10
Public Const PAN_FAMILYTYPE_INDEX = 0
Public Const PAN_SERIFSTYLE_INDEX = 1
Public Const PAN_WEIGHT_INDEX = 2
Public Const PAN_PROPORTION_INDEX = 3
Public Const PAN_CONTRAST_INDEX = 4
Public Const PAN_STROKEVARIATION_INDEX = 5
Public Const PAN_ARMSTYLE_INDEX = 6
Public Const PAN_LETTERFORM_INDEX = 7
Public Const PAN_MIDLINE_INDEX = 8
Public Const PAN_XHEIGHT_INDEX = 9

Public Const PAN_CULTURE_LATIN = 0

Type PANOSE
        ulculture As Long
        bFamilyType As Byte
        bSerifStyle As Byte
        bWeight As Byte
        bProportion As Byte
        bContrast As Byte
        bStrokeVariation As Byte
        bArmStyle As Byte
        bLetterform As Byte
        bMidline As Byte
        bXHeight As Byte
End Type

Public Const PAN_ANY = 0  '  Any
Public Const PAN_NO_FIT = 1  '  No Fit

Public Const PAN_FAMILY_TEXT_DISPLAY = 2  '  Text and Display
Public Const PAN_FAMILY_SCRIPT = 3  '  Script
Public Const PAN_FAMILY_DECORATIVE = 4  '  Decorative
Public Const PAN_FAMILY_PICTORIAL = 5  '  Pictorial

Public Const PAN_SERIF_COVE = 2  '  Cove
Public Const PAN_SERIF_OBTUSE_COVE = 3  '  Obtuse Cove
Public Const PAN_SERIF_SQUARE_COVE = 4  '  Square Cove
Public Const PAN_SERIF_OBTUSE_SQUARE_COVE = 5  '  Obtuse Square Cove
Public Const PAN_SERIF_SQUARE = 6  '  Square
Public Const PAN_SERIF_THIN = 7  '  Thin
Public Const PAN_SERIF_BONE = 8  '  Bone
Public Const PAN_SERIF_EXAGGERATED = 9  '  Exaggerated
Public Const PAN_SERIF_TRIANGLE = 10  '  Triangle
Public Const PAN_SERIF_NORMAL_SANS = 11  '  Normal Sans
Public Const PAN_SERIF_OBTUSE_SANS = 12  '  Obtuse Sans
Public Const PAN_SERIF_PERP_SANS = 13  '  Prep Sans
Public Const PAN_SERIF_FLARED = 14  '  Flared
Public Const PAN_SERIF_ROUNDED = 15  '  Rounded

Public Const PAN_WEIGHT_VERY_LIGHT = 2  '  Very Light
Public Const PAN_WEIGHT_LIGHT = 3  '  Light
Public Const PAN_WEIGHT_THIN = 4  '  Thin
Public Const PAN_WEIGHT_BOOK = 5  '  Book
Public Const PAN_WEIGHT_MEDIUM = 6  '  Medium
Public Const PAN_WEIGHT_DEMI = 7  '  Demi
Public Const PAN_WEIGHT_BOLD = 8  '  Bold
Public Const PAN_WEIGHT_HEAVY = 9  '  Heavy
Public Const PAN_WEIGHT_BLACK = 10  '  Black
Public Const PAN_WEIGHT_NORD = 11  '  Nord

Public Const PAN_PROP_OLD_STYLE = 2  '  Old Style
Public Const PAN_PROP_MODERN = 3  '  Modern
Public Const PAN_PROP_EVEN_WIDTH = 4  '  Even Width
Public Const PAN_PROP_EXPANDED = 5  '  Expanded
Public Const PAN_PROP_CONDENSED = 6  '  Condensed
Public Const PAN_PROP_VERY_EXPANDED = 7  '  Very Expanded
Public Const PAN_PROP_VERY_CONDENSED = 8  '  Very Condensed
Public Const PAN_PROP_MONOSPACED = 9  '  Monospaced

Public Const PAN_CONTRAST_NONE = 2  '  None
Public Const PAN_CONTRAST_VERY_LOW = 3  '  Very Low
Public Const PAN_CONTRAST_LOW = 4  '  Low
Public Const PAN_CONTRAST_MEDIUM_LOW = 5  '  Medium Low
Public Const PAN_CONTRAST_MEDIUM = 6  '  Medium
Public Const PAN_CONTRAST_MEDIUM_HIGH = 7  '  Mediim High
Public Const PAN_CONTRAST_HIGH = 8  '  High
Public Const PAN_CONTRAST_VERY_HIGH = 9  '  Very High

Public Const PAN_STROKE_GRADUAL_DIAG = 2  '  Gradual/Diagonal
Public Const PAN_STROKE_GRADUAL_TRAN = 3  '  Gradual/Transitional
Public Const PAN_STROKE_GRADUAL_VERT = 4  '  Gradual/Vertical
Public Const PAN_STROKE_GRADUAL_HORZ = 5  '  Gradual/Horizontal
Public Const PAN_STROKE_RAPID_VERT = 6  '  Rapid/Vertical
Public Const PAN_STROKE_RAPID_HORZ = 7  '  Rapid/Horizontal
Public Const PAN_STROKE_INSTANT_VERT = 8  '  Instant/Vertical

Public Const PAN_STRAIGHT_ARMS_HORZ = 2  '  Straight Arms/Horizontal
Public Const PAN_STRAIGHT_ARMS_WEDGE = 3  '  Straight Arms/Wedge
Public Const PAN_STRAIGHT_ARMS_VERT = 4  '  Straight Arms/Vertical
Public Const PAN_STRAIGHT_ARMS_SINGLE_SERIF = 5 '  Straight Arms/Single-Serif
Public Const PAN_STRAIGHT_ARMS_DOUBLE_SERIF = 6 '  Straight Arms/Double-Serif
Public Const PAN_BENT_ARMS_HORZ = 7  '  Non-Straight Arms/Horizontal
Public Const PAN_BENT_ARMS_WEDGE = 8  '  Non-Straight Arms/Wedge
Public Const PAN_BENT_ARMS_VERT = 9  '  Non-Straight Arms/Vertical
Public Const PAN_BENT_ARMS_SINGLE_SERIF = 10  '  Non-Straight Arms/Single-Serif
Public Const PAN_BENT_ARMS_DOUBLE_SERIF = 11  '  Non-Straight Arms/Double-Serif

Public Const PAN_LETT_NORMAL_CONTACT = 2  '  Normal/Contact
Public Const PAN_LETT_NORMAL_WEIGHTED = 3  '  Normal/Weighted
Public Const PAN_LETT_NORMAL_BOXED = 4  '  Normal/Boxed
Public Const PAN_LETT_NORMAL_FLATTENED = 5  '  Normal/Flattened
Public Const PAN_LETT_NORMAL_ROUNDED = 6  '  Normal/Rounded
Public Const PAN_LETT_NORMAL_OFF_CENTER = 7  '  Normal/Off Center
Public Const PAN_LETT_NORMAL_SQUARE = 8  '  Normal/Square
Public Const PAN_LETT_OBLIQUE_CONTACT = 9  '  Oblique/Contact
Public Const PAN_LETT_OBLIQUE_WEIGHTED = 10  '  Oblique/Weighted
Public Const PAN_LETT_OBLIQUE_BOXED = 11  '  Oblique/Boxed
Public Const PAN_LETT_OBLIQUE_FLATTENED = 12  '  Oblique/Flattened
Public Const PAN_LETT_OBLIQUE_ROUNDED = 13  '  Oblique/Rounded
Public Const PAN_LETT_OBLIQUE_OFF_CENTER = 14  '  Oblique/Off Center
Public Const PAN_LETT_OBLIQUE_SQUARE = 15  '  Oblique/Square

Public Const PAN_MIDLINE_STANDARD_TRIMMED = 2  '  Standard/Trimmed
Public Const PAN_MIDLINE_STANDARD_POINTED = 3  '  Standard/Pointed
Public Const PAN_MIDLINE_STANDARD_SERIFED = 4  '  Standard/Serifed
Public Const PAN_MIDLINE_HIGH_TRIMMED = 5  '  High/Trimmed
Public Const PAN_MIDLINE_HIGH_POINTED = 6  '  High/Pointed
Public Const PAN_MIDLINE_HIGH_SERIFED = 7  '  High/Serifed
Public Const PAN_MIDLINE_CONSTANT_TRIMMED = 8  '  public constant/Trimmed
Public Const PAN_MIDLINE_CONSTANT_POINTED = 9  '  public constant/Pointed
Public Const PAN_MIDLINE_CONSTANT_SERIFED = 10  '  public constant/Serifed
Public Const PAN_MIDLINE_LOW_TRIMMED = 11  '  Low/Trimmed
Public Const PAN_MIDLINE_LOW_POINTED = 12  '  Low/Pointed
Public Const PAN_MIDLINE_LOW_SERIFED = 13  '  Low/Serifed

Public Const PAN_XHEIGHT_CONSTANT_SMALL = 2  '  public constant/Small
Public Const PAN_XHEIGHT_CONSTANT_STD = 3  '  public constant/Standard
Public Const PAN_XHEIGHT_CONSTANT_LARGE = 4  '  public constant/Large
Public Const PAN_XHEIGHT_DUCKING_SMALL = 5  '  Ducking/Small
Public Const PAN_XHEIGHT_DUCKING_STD = 6  '  Ducking/Standard
Public Const PAN_XHEIGHT_DUCKING_LARGE = 7  '  Ducking/Large

Public Const ELF_VENDOR_SIZE = 4

Type EXTLOGFONT
        elfLogFont  As LOGFONT
        elfFullName(LF_FULLFACESIZE) As Byte
        elfStyle(LF_FACESIZE) As Byte
        elfVersion As Long
        elfStyleSize As Long
        elfMatch As Long
        elfReserved As Long
        elfVendorId(ELF_VENDOR_SIZE) As Byte
        elfCulture As Long
        elfPanose As PANOSE
End Type

Public Const ELF_VERSION = 0
Public Const ELF_CULTURE_LATIN = 0

'  EnumFonts Masks
Public Const RASTER_FONTTYPE = &H1
Public Const DEVICE_FONTTYPE = &H2
Public Const TRUETYPE_FONTTYPE = &H4

' palette entry flags
Public Const PC_RESERVED = &H1  '  palette index used for animation
Public Const PC_EXPLICIT = &H2  '  palette index is explicit to device
Public Const PC_NOCOLLAPSE = &H4        '  do not match color to system palette

' Background Modes
Public Const TRANSPARENT = 1
Public Const OPAQUE = 2
Public Const BKMODE_LAST = 2

'  Graphics Modes
Public Const GM_COMPATIBLE = 1
Public Const GM_ADVANCED = 2
Public Const GM_LAST = 2

'  PolyDraw and GetPath point types
Public Const PT_CLOSEFIGURE = &H1
Public Const PT_LINETO = &H2
Public Const PT_BEZIERTO = &H4
Public Const PT_MOVETO = &H6

'  Mapping Modes
Public Const MM_TEXT = 1
Public Const MM_LOMETRIC = 2
Public Const MM_HIMETRIC = 3
Public Const MM_LOENGLISH = 4
Public Const MM_HIENGLISH = 5
Public Const MM_TWIPS = 6
Public Const MM_ISOTROPIC = 7
Public Const MM_ANISOTROPIC = 8

'  Min and Max Mapping Mode values
Public Const MM_MIN = MM_TEXT
Public Const MM_MAX = MM_ANISOTROPIC
Public Const MM_MAX_FIXEDSCALE = MM_TWIPS

' Coordinate Modes
Public Const ABSOLUTE = 1
Public Const RELATIVE = 2

' Stock Logical Objects
Public Const WHITE_BRUSH = 0
Public Const LTGRAY_BRUSH = 1
Public Const GRAY_BRUSH = 2
Public Const DKGRAY_BRUSH = 3
Public Const BLACK_BRUSH = 4
Public Const NULL_BRUSH = 5
Public Const HOLLOW_BRUSH = NULL_BRUSH
Public Const WHITE_PEN = 6
Public Const BLACK_PEN = 7
Public Const NULL_PEN = 8
Public Const OEM_FIXED_FONT = 10
Public Const ANSI_FIXED_FONT = 11
Public Const ANSI_VAR_FONT = 12
Public Const SYSTEM_FONT = 13
Public Const DEVICE_DEFAULT_FONT = 14
Public Const DEFAULT_PALETTE = 15
Public Const SYSTEM_FIXED_FONT = 16
Public Const STOCK_LAST = 16

Public Const CLR_INVALID = &HFFFF

' Brush Styles
Public Const BS_SOLID = 0
Public Const BS_NULL = 1
Public Const BS_HOLLOW = BS_NULL
Public Const BS_HATCHED = 2
Public Const BS_PATTERN = 3
Public Const BS_INDEXED = 4
Public Const BS_DIBPATTERN = 5
Public Const BS_DIBPATTERNPT = 6
Public Const BS_PATTERN8X8 = 7
Public Const BS_DIBPATTERN8X8 = 8

'  Hatch Styles
Public Const HS_HORIZONTAL = 0              '  -----
Public Const HS_VERTICAL = 1                '  |||||
Public Const HS_FDIAGONAL = 2               '  \\\\\
Public Const HS_BDIAGONAL = 3               '  /////
Public Const HS_CROSS = 4                   '  +++++
Public Const HS_DIAGCROSS = 5               '  xxxxx
Public Const HS_FDIAGONAL1 = 6
Public Const HS_BDIAGONAL1 = 7
Public Const HS_SOLID = 8
Public Const HS_DENSE1 = 9
Public Const HS_DENSE2 = 10
Public Const HS_DENSE3 = 11
Public Const HS_DENSE4 = 12
Public Const HS_DENSE5 = 13
Public Const HS_DENSE6 = 14
Public Const HS_DENSE7 = 15
Public Const HS_DENSE8 = 16
Public Const HS_NOSHADE = 17
Public Const HS_HALFTONE = 18
Public Const HS_SOLIDCLR = 19
Public Const HS_DITHEREDCLR = 20
Public Const HS_SOLIDTEXTCLR = 21
Public Const HS_DITHEREDTEXTCLR = 22
Public Const HS_SOLIDBKCLR = 23
Public Const HS_DITHEREDBKCLR = 24
Public Const HS_API_MAX = 25

'  Pen Styles
Public Const PS_SOLID = 0
Public Const PS_DASH = 1                    '  -------
Public Const PS_DOT = 2                     '  .......
Public Const PS_DASHDOT = 3                 '  _._._._
Public Const PS_DASHDOTDOT = 4              '  _.._.._
Public Const PS_NULL = 5
Public Const PS_INSIDEFRAME = 6
Public Const PS_USERSTYLE = 7
Public Const PS_ALTERNATE = 8
Public Const PS_STYLE_MASK = &HF

Public Const PS_ENDCAP_ROUND = &H0
Public Const PS_ENDCAP_SQUARE = &H100
Public Const PS_ENDCAP_FLAT = &H200
Public Const PS_ENDCAP_MASK = &HF00

Public Const PS_JOIN_ROUND = &H0
Public Const PS_JOIN_BEVEL = &H1000
Public Const PS_JOIN_MITER = &H2000
Public Const PS_JOIN_MASK = &HF000

Public Const PS_COSMETIC = &H0
Public Const PS_GEOMETRIC = &H10000
Public Const PS_TYPE_MASK = &HF0000

Public Const AD_COUNTERCLOCKWISE = 1
Public Const AD_CLOCKWISE = 2

'  Device Parameters for GetDeviceCaps()
Public Const DRIVERVERSION = 0      '  Device driver version
Public Const TECHNOLOGY = 2         '  Device classification
Public Const HORZSIZE = 4           '  Horizontal size in millimeters
Public Const VERTSIZE = 6           '  Vertical size in millimeters
Public Const HORZRES = 8            '  Horizontal width in pixels
Public Const VERTRES = 10           '  Vertical width in pixels
Public Const BITSPIXEL = 12         '  Number of bits per pixel
Public Const PLANES = 14            '  Number of planes
Public Const NUMBRUSHES = 16        '  Number of brushes the device has
Public Const NUMPENS = 18           '  Number of pens the device has
Public Const NUMMARKERS = 20        '  Number of markers the device has
Public Const NUMFONTS = 22          '  Number of fonts the device has
Public Const NUMCOLORS = 24         '  Number of colors the device supports
Public Const PDEVICESIZE = 26       '  Size required for device descriptor
Public Const CURVECAPS = 28         '  Curve capabilities
Public Const LINECAPS = 30          '  Line capabilities
Public Const POLYGONALCAPS = 32     '  Polygonal capabilities
Public Const TEXTCAPS = 34          '  Text capabilities
Public Const CLIPCAPS = 36          '  Clipping capabilities
Public Const RASTERCAPS = 38        '  Bitblt capabilities
Public Const ASPECTX = 40           '  Length of the X leg
Public Const ASPECTY = 42           '  Length of the Y leg
Public Const ASPECTXY = 44          '  Length of the hypotenuse

Public Const LOGPIXELSX = 88        '  Logical pixels/inch in X
Public Const LOGPIXELSY = 90        '  Logical pixels/inch in Y

Public Const SIZEPALETTE = 104      '  Number of entries in physical palette
Public Const NUMRESERVED = 106      '  Number of reserved entries in palette
Public Const COLORRES = 108         '  Actual color resolution

'  Printing related DeviceCaps. These replace the appropriate Escapes
Public Const PHYSICALWIDTH = 110 '  Physical Width in device units
Public Const PHYSICALHEIGHT = 111 '  Physical Height in device units
Public Const PHYSICALOFFSETX = 112 '  Physical Printable Area x margin
Public Const PHYSICALOFFSETY = 113 '  Physical Printable Area y margin
Public Const SCALINGFACTORX = 114 '  Scaling factor x
Public Const SCALINGFACTORY = 115 '  Scaling factor y

'  Device Capability Masks:

'  Device Technologies
Public Const DT_PLOTTER = 0             '  Vector plotter
Public Const DT_RASDISPLAY = 1          '  Raster display
Public Const DT_RASPRINTER = 2          '  Raster printer
Public Const DT_RASCAMERA = 3           '  Raster camera
Public Const DT_CHARSTREAM = 4          '  Character-stream, PLP
Public Const DT_METAFILE = 5            '  Metafile, VDM
Public Const DT_DISPFILE = 6            '  Display-file

'  Curve Capabilities
Public Const CC_NONE = 0                '  Curves not supported
Public Const CC_CIRCLES = 1             '  Can do circles
Public Const CC_PIE = 2                 '  Can do pie wedges
Public Const CC_CHORD = 4               '  Can do chord arcs
Public Const CC_ELLIPSES = 8            '  Can do ellipese
Public Const CC_WIDE = 16               '  Can do wide lines
Public Const CC_STYLED = 32             '  Can do styled lines
Public Const CC_WIDESTYLED = 64         '  Can do wide styled lines
Public Const CC_INTERIORS = 128 '  Can do interiors
Public Const CC_ROUNDRECT = 256 '

'  Line Capabilities
Public Const LC_NONE = 0                '  Lines not supported
Public Const LC_POLYLINE = 2            '  Can do polylines
Public Const LC_MARKER = 4              '  Can do markers
Public Const LC_POLYMARKER = 8          '  Can do polymarkers
Public Const LC_WIDE = 16               '  Can do wide lines
Public Const LC_STYLED = 32             '  Can do styled lines
Public Const LC_WIDESTYLED = 64         '  Can do wide styled lines
Public Const LC_INTERIORS = 128 '  Can do interiors

'  Polygonal Capabilities
Public Const PC_NONE = 0                '  Polygonals not supported
Public Const PC_POLYGON = 1             '  Can do polygons
Public Const PC_RECTANGLE = 2           '  Can do rectangles
Public Const PC_WINDPOLYGON = 4         '  Can do winding polygons
Public Const PC_TRAPEZOID = 4           '  Can do trapezoids
Public Const PC_SCANLINE = 8            '  Can do scanlines
Public Const PC_WIDE = 16               '  Can do wide borders
Public Const PC_STYLED = 32             '  Can do styled borders
Public Const PC_WIDESTYLED = 64         '  Can do wide styled borders
Public Const PC_INTERIORS = 128 '  Can do interiors

'  Polygonal Capabilities
Public Const CP_NONE = 0                '  No clipping of output
Public Const CP_RECTANGLE = 1           '  Output clipped to rects
Public Const CP_REGION = 2              '

'  Text Capabilities
Public Const TC_OP_CHARACTER = &H1              '  Can do OutputPrecision   CHARACTER
Public Const TC_OP_STROKE = &H2                 '  Can do OutputPrecision   STROKE
Public Const TC_CP_STROKE = &H4                 '  Can do ClipPrecision     STROKE
Public Const TC_CR_90 = &H8                     '  Can do CharRotAbility    90
Public Const TC_CR_ANY = &H10                   '  Can do CharRotAbility    ANY
Public Const TC_SF_X_YINDEP = &H20              '  Can do ScaleFreedom      X_YINDEPENDENT
Public Const TC_SA_DOUBLE = &H40                '  Can do ScaleAbility      DOUBLE
Public Const TC_SA_INTEGER = &H80               '  Can do ScaleAbility      INTEGER
Public Const TC_SA_CONTIN = &H100               '  Can do ScaleAbility      CONTINUOUS
Public Const TC_EA_DOUBLE = &H200               '  Can do EmboldenAbility   DOUBLE
Public Const TC_IA_ABLE = &H400                 '  Can do ItalisizeAbility  ABLE
Public Const TC_UA_ABLE = &H800                 '  Can do UnderlineAbility  ABLE
Public Const TC_SO_ABLE = &H1000                '  Can do StrikeOutAbility  ABLE
Public Const TC_RA_ABLE = &H2000                '  Can do RasterFontAble    ABLE
Public Const TC_VA_ABLE = &H4000                '  Can do VectorFontAble    ABLE
Public Const TC_RESERVED = &H8000
Public Const TC_SCROLLBLT = &H10000             '  do text scroll with blt

'  Raster Capabilities
Public Const RC_NONE = 0
Public Const RC_BITBLT = 1                  '  Can do standard BLT.
Public Const RC_BANDING = 2                 '  Device requires banding support
Public Const RC_SCALING = 4                 '  Device requires scaling support
Public Const RC_BITMAP64 = 8                '  Device can support >64K bitmap
Public Const RC_GDI20_OUTPUT = &H10             '  has 2.0 output calls
Public Const RC_GDI20_STATE = &H20
Public Const RC_SAVEBITMAP = &H40
Public Const RC_DI_BITMAP = &H80                '  supports DIB to memory
Public Const RC_PALETTE = &H100                 '  supports a palette
Public Const RC_DIBTODEV = &H200                '  supports DIBitsToDevice
Public Const RC_BIGFONT = &H400                 '  supports >64K fonts
Public Const RC_STRETCHBLT = &H800              '  supports StretchBlt
Public Const RC_FLOODFILL = &H1000              '  supports FloodFill
Public Const RC_STRETCHDIB = &H2000             '  supports StretchDIBits
Public Const RC_OP_DX_OUTPUT = &H4000
Public Const RC_DEVBITS = &H8000

' DIB color table identifiers
Public Const DIB_RGB_COLORS = 0 '  color table in RGBs
Public Const DIB_PAL_COLORS = 1 '  color table in palette indices
Public Const DIB_PAL_INDICES = 2 '  No color table indices into surf palette
Public Const DIB_PAL_PHYSINDICES = 2 '  No color table indices into surf palette
Public Const DIB_PAL_LOGINDICES = 4 '  No color table indices into DC palette

' public constants for Get/SetSystemPaletteUse()
Public Const SYSPAL_ERROR = 0
Public Const SYSPAL_STATIC = 1
Public Const SYSPAL_NOSTATIC = 2

' public constants for CreateDIBitmap
Public Const CBM_CREATEDIB = &H2      '  create DIB bitmap
Public Const CBM_INIT = &H4           '  initialize bitmap

' ExtFloodFill style flags
Public Const FLOODFILLBORDER = 0
Public Const FLOODFILLSURFACE = 1

'  size of a device name string
Public Const CCHDEVICENAME = 32

'  size of a form name string
Public Const CCHFORMNAME = 32

Type DEVMODE
        dmDeviceName As String * CCHDEVICENAME
        dmSpecVersion As Integer
        dmDriverVersion As Integer
        dmSize As Integer
        dmDriverExtra As Integer
        dmFields As Long
        dmOrientation As Integer
        dmPaperSize As Integer
        dmPaperLength As Integer
        dmPaperWidth As Integer
        dmScale As Integer
        dmCopies As Integer
        dmDefaultSource As Integer
        dmPrintQuality As Integer
        dmColor As Integer
        dmDuplex As Integer
        dmYResolution As Integer
        dmTTOption As Integer
        dmCollate As Integer
        dmFormName As String * CCHFORMNAME
        dmUnusedPadding As Integer
        dmBitsPerPel As Long
        dmPelsWidth As Long
        dmPelsHeight As Long
        dmDisplayFlags As Long
        dmDisplayFrequency As Long
End Type

' current version of specification
Public Const DM_SPECVERSION = &H320

' field selection bits
Public Const DM_ORIENTATION = &H1&
Public Const DM_PAPERSIZE = &H2&
Public Const DM_PAPERLENGTH = &H4&
Public Const DM_PAPERWIDTH = &H8&
Public Const DM_SCALE = &H10&
Public Const DM_COPIES = &H100&
Public Const DM_DEFAULTSOURCE = &H200&
Public Const DM_PRINTQUALITY = &H400&
Public Const DM_COLOR = &H800&
Public Const DM_DUPLEX = &H1000&
Public Const DM_YRESOLUTION = &H2000&
Public Const DM_TTOPTION = &H4000&
Public Const DM_COLLATE As Long = &H8000
Public Const DM_FORMNAME As Long = &H10000

'  orientation selections
Public Const DMORIENT_PORTRAIT = 1
Public Const DMORIENT_LANDSCAPE = 2

'  paper selections
Public Const DMPAPER_LETTER = 1
Public Const DMPAPER_FIRST = DMPAPER_LETTER
               '  Letter 8 1/2 x 11 in
Public Const DMPAPER_LETTERSMALL = 2            '  Letter Small 8 1/2 x 11 in
Public Const DMPAPER_TABLOID = 3                '  Tabloid 11 x 17 in
Public Const DMPAPER_LEDGER = 4                 '  Ledger 17 x 11 in
Public Const DMPAPER_LEGAL = 5                  '  Legal 8 1/2 x 14 in
Public Const DMPAPER_STATEMENT = 6              '  Statement 5 1/2 x 8 1/2 in
Public Const DMPAPER_EXECUTIVE = 7              '  Executive 7 1/4 x 10 1/2 in
Public Const DMPAPER_A3 = 8                     '  A3 297 x 420 mm
Public Const DMPAPER_A4 = 9                     '  A4 210 x 297 mm
Public Const DMPAPER_A4SMALL = 10               '  A4 Small 210 x 297 mm
Public Const DMPAPER_A5 = 11                    '  A5 148 x 210 mm
Public Const DMPAPER_B4 = 12                    '  B4 250 x 354
Public Const DMPAPER_B5 = 13                    '  B5 182 x 257 mm
Public Const DMPAPER_FOLIO = 14                 '  Folio 8 1/2 x 13 in
Public Const DMPAPER_QUARTO = 15                '  Quarto 215 x 275 mm
Public Const DMPAPER_10X14 = 16                 '  10x14 in
Public Const DMPAPER_11X17 = 17                 '  11x17 in
Public Const DMPAPER_NOTE = 18                  '  Note 8 1/2 x 11 in
Public Const DMPAPER_ENV_9 = 19                 '  Envelope #9 3 7/8 x 8 7/8
Public Const DMPAPER_ENV_10 = 20                '  Envelope #10 4 1/8 x 9 1/2
Public Const DMPAPER_ENV_11 = 21                '  Envelope #11 4 1/2 x 10 3/8
Public Const DMPAPER_ENV_12 = 22                '  Envelope #12 4 \276 x 11
Public Const DMPAPER_ENV_14 = 23                '  Envelope #14 5 x 11 1/2
Public Const DMPAPER_CSHEET = 24                '  C size sheet
Public Const DMPAPER_DSHEET = 25                '  D size sheet
Public Const DMPAPER_ESHEET = 26                '  E size sheet
Public Const DMPAPER_ENV_DL = 27                '  Envelope DL 110 x 220mm
Public Const DMPAPER_ENV_C5 = 28                '  Envelope C5 162 x 229 mm
Public Const DMPAPER_ENV_C3 = 29                '  Envelope C3  324 x 458 mm
Public Const DMPAPER_ENV_C4 = 30                '  Envelope C4  229 x 324 mm
Public Const DMPAPER_ENV_C6 = 31                '  Envelope C6  114 x 162 mm
Public Const DMPAPER_ENV_C65 = 32               '  Envelope C65 114 x 229 mm
Public Const DMPAPER_ENV_B4 = 33                '  Envelope B4  250 x 353 mm
Public Const DMPAPER_ENV_B5 = 34                '  Envelope B5  176 x 250 mm
Public Const DMPAPER_ENV_B6 = 35                '  Envelope B6  176 x 125 mm
Public Const DMPAPER_ENV_ITALY = 36             '  Envelope 110 x 230 mm
Public Const DMPAPER_ENV_MONARCH = 37           '  Envelope Monarch 3.875 x 7.5 in
Public Const DMPAPER_ENV_PERSONAL = 38          '  6 3/4 Envelope 3 5/8 x 6 1/2 in
Public Const DMPAPER_FANFOLD_US = 39            '  US Std Fanfold 14 7/8 x 11 in
Public Const DMPAPER_FANFOLD_STD_GERMAN = 40    '  German Std Fanfold 8 1/2 x 12 in
Public Const DMPAPER_FANFOLD_LGL_GERMAN = 41    '  German Legal Fanfold 8 1/2 x 13 in

Public Const DMPAPER_LAST = DMPAPER_FANFOLD_LGL_GERMAN

Public Const DMPAPER_USER = 256

'  bin selections
Public Const DMBIN_UPPER = 1
Public Const DMBIN_FIRST = DMBIN_UPPER

Public Const DMBIN_ONLYONE = 1
Public Const DMBIN_LOWER = 2
Public Const DMBIN_MIDDLE = 3
Public Const DMBIN_MANUAL = 4
Public Const DMBIN_ENVELOPE = 5
Public Const DMBIN_ENVMANUAL = 6
Public Const DMBIN_AUTO = 7
Public Const DMBIN_TRACTOR = 8
Public Const DMBIN_SMALLFMT = 9
Public Const DMBIN_LARGEFMT = 10
Public Const DMBIN_LARGECAPACITY = 11
Public Const DMBIN_CASSETTE = 14
Public Const DMBIN_LAST = DMBIN_CASSETTE

Public Const DMBIN_USER = 256               '  device specific bins start here

'  print qualities
Public Const DMRES_DRAFT = (-1)
Public Const DMRES_LOW = (-2)
Public Const DMRES_MEDIUM = (-3)
Public Const DMRES_HIGH = (-4)

'  color enable/disable for color printers
Public Const DMCOLOR_MONOCHROME = 1
Public Const DMCOLOR_COLOR = 2

'  duplex enable
Public Const DMDUP_SIMPLEX = 1
Public Const DMDUP_VERTICAL = 2
Public Const DMDUP_HORIZONTAL = 3

'  TrueType options
Public Const DMTT_BITMAP = 1            '  print TT fonts as graphics
Public Const DMTT_DOWNLOAD = 2          '  download TT fonts as soft fonts
Public Const DMTT_SUBDEV = 3            '  substitute device fonts for TT fonts

'  Collation selections
Public Const DMCOLLATE_FALSE = 0
Public Const DMCOLLATE_TRUE = 1

'  DEVMODE dmDisplayFlags flags

Public Const DM_GRAYSCALE = &H1
Public Const DM_INTERLACED = &H2

'  GetRegionData/ExtCreateRegion

Public Const RDH_RECTANGLES = 1

Type RGNDATAHEADER
        dwSize As Long
        iType As Long
        nCount As Long
        nRgnSize As Long
        rcBound As RECT
End Type

Type RgnData
        rdh As RGNDATAHEADER
        Buffer As Byte
End Type

Type ABC
        abcA As Long
        abcB As Long
        abcC As Long
End Type

Type ABCFLOAT
        abcfA As Double
        abcfB As Double
        abcfC As Double
End Type

Type OUTLINETEXTMETRIC
        otmSize As Long
        otmTextMetrics As TEXTMETRIC
        otmFiller As Byte
        otmPanoseNumber As PANOSE
        otmfsSelection As Long
        otmfsType As Long
        otmsCharSlopeRise As Long
        otmsCharSlopeRun As Long
        otmItalicAngle As Long
        otmEMSquare As Long
        otmAscent As Long
        otmDescent As Long
        otmLineGap As Long
        otmsCapEmHeight As Long
        otmsXHeight As Long
        otmrcFontBox As RECT
        otmMacAscent As Long
        otmMacDescent As Long
        otmMacLineGap As Long
        otmusMinimumPPEM As Long
        otmptSubscriptSize As POINTAPI
        otmptSubscriptOffset As POINTAPI
        otmptSuperscriptSize As POINTAPI
        otmptSuperscriptOffset As POINTAPI
        otmsStrikeoutSize As Long
        otmsStrikeoutPosition As Long
        otmsUnderscorePosition As Long
        otmsUnderscoreSize As Long
        otmpFamilyName As String
        otmpFaceName As String
        otmpStyleName As String
        otmpFullName As String
End Type

Type POLYTEXT
        x As Long
        y As Long
        n As Long
        lpStr As String
        uiFlags As Long
        rcl As RECT
        pdx As Long
End Type

Type FIXED
        fract As Integer
        Value As Integer
End Type

Type MAT2
        eM11 As FIXED
        eM12 As FIXED
        eM21 As FIXED
        eM22 As FIXED
End Type

Type GLYPHMETRICS
        gmBlackBoxX As Long
        gmBlackBoxY As Long
        gmptGlyphOrigin As POINTAPI
        gmCellIncX As Integer
        gmCellIncY As Integer
End Type


' GetGlyphOutline public constants
Public Const GGO_METRICS = 0
Public Const GGO_BITMAP = 1
Public Const GGO_NATIVE = 2

Public Const TT_POLYGON_TYPE = 24

Public Const TT_PRIM_LINE = 1
Public Const TT_PRIM_QSPLINE = 2

Type POINTFX
        x As FIXED
        y As FIXED
End Type

Type TTPOLYCURVE
        wType As Integer
        cpfx As Integer
        apfx As POINTFX
End Type

Type TTPOLYGONHEADER
        cb As Long
        dwType As Long
        pfxStart As POINTFX
End Type

Type RASTERIZER_STATUS
        nSize As Integer
        wFlags As Integer
        nLanguageID As Integer
End Type

' bits defined in wFlags of RASTERIZER_STATUS
Public Const TT_AVAILABLE = &H1
Public Const TT_ENABLED = &H2

Declare Function AddFontResource Lib "gdi32" Alias "AddFontResourceA" (ByVal lpFileName As String) As Long

Declare Function AnimatePalette Lib "gdi32" Alias "AnimatePaletteA" (ByVal hPalette As Long, ByVal wStartIndex As Long, ByVal wNumEntries As Long, lpPaletteColors As PALETTEENTRY) As Long
Declare Function Arc Lib "gdi32" (ByVal hdc As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long, ByVal X3 As Long, ByVal Y3 As Long, ByVal X4 As Long, ByVal Y4 As Long) As Long
Declare Function CancelDC Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function Chord Lib "gdi32" (ByVal hdc As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long, ByVal X3 As Long, ByVal Y3 As Long, ByVal X4 As Long, ByVal Y4 As Long) As Long
Declare Function CloseMetaFile Lib "gdi32" (ByVal hMF As Long) As Long
Declare Function CombineRgn Lib "gdi32" (ByVal hDestRgn As Long, ByVal hSrcRgn1 As Long, ByVal hSrcRgn2 As Long, ByVal nCombineMode As Long) As Long
Declare Function CopyMetaFile Lib "gdi32" Alias "CopyMetaFileA" (ByVal hMF As Long, ByVal lpFileName As String) As Long

Declare Function CreateBitmap Lib "gdi32" (ByVal nWidth As Long, ByVal nHeight As Long, ByVal nPlanes As Long, ByVal nBitCount As Long, ByVal lpBits As Long) As Long
Declare Function CreateBitmapIndirect Lib "gdi32" (lpBitmap As BITMAP) As Long
Declare Function CreateBrushIndirect Lib "gdi32" (lpLogBrush As LOGBRUSH) As Long
Declare Function CreateCompatibleBitmap Lib "gdi32" (ByVal hdc As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Long
Declare Function CreateDiscardableBitmap Lib "gdi32" (ByVal hdc As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Long

Declare Function CreateCompatibleDC Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function CreateDC Lib "gdi32" Alias "CreateDCA" (ByVal lpDriverName As String, ByVal lpDeviceName As String, ByVal lpOutput As String, ByVal lpInitData_DEVMODE As Long) As Long
Declare Function CreateDeviceDC Lib "gdi32" Alias "CreateDCA" (ByVal lpDriverName As Long, ByVal lpszDeviceName As String, ByVal lpszOutput As Long, ByVal lpInitData_DEVMODE As Long) As Long

Declare Function CreateDIBitmap Lib "gdi32" (ByVal hdc As Long, lpInfoHeader As BITMAPINFOHEADER, ByVal dwUsage As Long, ByVal lpInitBits As Long, lpInitInfo As BITMAPINFO, ByVal wUsage As Long) As Long
Declare Function CreateDIBPatternBrush Lib "gdi32" (ByVal hPackedDIB As Long, ByVal wUsage As Long) As Long
Declare Function CreateDIBPatternBrushPt Lib "gdi32" (ByVal lpPackedDIB As Long, ByVal iUsage As Long) As Long
Declare Function CreateEllipticRgnIndirect Lib "gdi32" (lpRect As RECT) As Long
Declare Function CreateEllipticRgn Lib "gdi32" (ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long) As Long

Declare Function CreateFontIndirect Lib "gdi32" Alias "CreateFontIndirectA" (lpLogFont As LOGFONT) As Long
Declare Function CreateFont Lib "gdi32" Alias "CreateFontA" (ByVal H As Long, ByVal W As Long, ByVal e As Long, ByVal O As Long, ByVal W As Long, ByVal i As Long, ByVal u As Long, ByVal s As Long, ByVal c As Long, ByVal op As Long, ByVal cp As Long, ByVal Q As Long, ByVal PAF As Long, ByVal f As String) As Long

Declare Function CreateHatchBrush Lib "gdi32" (ByVal nIndex As Long, ByVal crColor As Long) As Long
Declare Function CreateIC Lib "gdi32" Alias "CreateICA" (ByVal lpDriverName As String, ByVal lpDeviceName As String, ByVal lpOutput As String, lpInitData As DEVMODE) As Long

Declare Function CreateMetaFile Lib "gdi32" Alias "CreateMetaFileA" (ByVal lpstring As String) As Long

Declare Function CreatePalette Lib "gdi32" (lpLogPalette As LOGPALETTE) As Long
Declare Function CreatePen Lib "gdi32" (ByVal nPenStyle As Long, ByVal nWidth As Long, ByVal crColor As Long) As Long
Declare Function CreatePenIndirect Lib "gdi32" (lpLogPen As LOGPEN) As Long
Declare Function CreateRectRgn Lib "gdi32" (ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long) As Long
Declare Function CreateRectRgnIndirect Lib "gdi32" (lpRect As RECT) As Long
Declare Function CreatePolyPolygonRgn Lib "gdi32" (lpPoint As POINTAPI, lpPolyCounts As Long, ByVal nCount As Long, ByVal nPolyFillMode As Long) As Long
Declare Function CreatePatternBrush Lib "gdi32" (ByVal hBitmap As Long) As Long
Declare Function CreateRoundRectRgn Lib "gdi32" (ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long, ByVal X3 As Long, ByVal Y3 As Long) As Long
Declare Function CreateScalableFontResource Lib "gdi32" Alias "CreateScalableFontResourceA" (ByVal fHidden As Long, ByVal lpszResourceFile As String, ByVal lpszFontFile As String, ByVal lpszCurrentPath As String) As Long
Declare Function CreateSolidBrush Lib "gdi32" (ByVal crColor As Long) As Long

Declare Function DeleteDC Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function DeleteObject Lib "gdi32" (ByVal hObject As Long) As Long
Declare Function DeleteMetaFile Lib "gdi32" (ByVal hMF As Long) As Long

'  mode selections for the device mode function
Public Const DM_UPDATE = 1
Public Const DM_COPY = 2
Public Const DM_PROMPT = 4
Public Const DM_MODIFY = 8

Public Const DM_IN_BUFFER = DM_MODIFY
Public Const DM_IN_PROMPT = DM_PROMPT
Public Const DM_OUT_BUFFER = DM_COPY
Public Const DM_OUT_DEFAULT = DM_UPDATE

'  device capabilities indices
Public Const DC_FIELDS = 1
Public Const DC_PAPERS = 2
Public Const DC_PAPERSIZE = 3
Public Const DC_MINEXTENT = 4
Public Const DC_MAXEXTENT = 5
Public Const DC_BINS = 6
Public Const DC_DUPLEX = 7
Public Const DC_SIZE = 8
Public Const DC_EXTRA = 9
Public Const DC_VERSION = 10
Public Const DC_DRIVER = 11
Public Const DC_BINNAMES = 12
Public Const DC_ENUMRESOLUTIONS = 13
Public Const DC_FILEDEPENDENCIES = 14
Public Const DC_TRUETYPE = 15
Public Const DC_PAPERNAMES = 16
Public Const DC_ORIENTATION = 17
Public Const DC_COPIES = 18

'  bit fields of the return value (DWORD) for DC_TRUETYPE
Public Const DCTT_BITMAP = &H1&
Public Const DCTT_DOWNLOAD = &H2&
Public Const DCTT_SUBDEV = &H4&

Declare Function DeviceCapabilities Lib "winspool.drv" Alias "DeviceCapabilitiesA" (ByVal lpDeviceName As String, ByVal lpPort As String, ByVal iIndex As Long, ByVal lpOutput As String, lpDevMode As DEVMODE) As Long

Declare Function Ellipse Lib "gdi32" (ByVal hdc As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long) As Long

Declare Function EqualRgn Lib "gdi32" (ByVal hSrcRgn1 As Long, ByVal hSrcRgn2 As Long) As Long
Declare Function Escape Lib "gdi32" (ByVal hdc As Long, ByVal nEscape As Long, ByVal nCount As Long, ByVal lpInData As String, ByVal lpOutData As Long) As Long
Declare Function ExtEscape Lib "gdi32" (ByVal hdc As Long, ByVal nEscape As Long, ByVal cbInput As Long, ByVal lpszInData As String, ByVal cbOutput As Long, ByVal lpszOutData As String) As Long
Declare Function DrawEscape Lib "gdi32" (ByVal hdc As Long, ByVal nEscape As Long, ByVal cbInput As Long, ByVal lpszInData As String) As Long
Declare Function ExcludeClipRect Lib "gdi32" (ByVal hdc As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long) As Long
Declare Function ExtCreateRegion Lib "gdi32" (lpXform As xform, ByVal nCount As Long, lpRgnData As RgnData) As Long
Declare Function ExtFloodFill Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal crColor As Long, ByVal wFillType As Long) As Long
Declare Function FillRgn Lib "gdi32" (ByVal hdc As Long, ByVal hRgn As Long, ByVal hBrush As Long) As Long
Declare Function FrameRgn Lib "gdi32" (ByVal hdc As Long, ByVal hRgn As Long, ByVal hBrush As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Long
Declare Function FloodFill Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal crColor As Long) As Long
Declare Function GetROP2 Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetAspectRatioFilterEx Lib "gdi32" (ByVal hdc As Long, lpAspectRatio As Size) As Long
Declare Function GetBkColor Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetBkMode Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetBitmapBits Lib "gdi32" (ByVal hBitmap As Long, ByVal dwCount As Long, ByVal lpBits As Long) As Long
Declare Function GetBitmapDimensionEx Lib "gdi32" (ByVal hBitmap As Long, lpDimension As Size) As Long
Declare Function GetBoundsRect Lib "gdi32" (ByVal hdc As Long, lprcBounds As RECT, ByVal flags As Long) As Long

Declare Function GetCharWidth Lib "gdi32" Alias "GetCharWidthA" (ByVal hdc As Long, ByVal wFirstChar As Long, ByVal wLastChar As Long, lpBuffer As Long) As Long

Declare Function GetCharWidth32 Lib "gdi32" Alias "GetCharWidth32A" (ByVal hdc As Long, ByVal iFirstChar As Long, ByVal iLastChar As Long, lpBuffer As Long) As Long
Declare Function GetCharWidthFloat Lib "gdi32" Alias "GetCharWidthFloatA" (ByVal hdc As Long, ByVal iFirstChar As Long, ByVal iLastChar As Long, pxBuffer As Double) As Long

Declare Function GetCharABCWidths Lib "gdi32" Alias "GetCharABCWidthsA" (ByVal hdc As Long, ByVal uFirstChar As Long, ByVal uLastChar As Long, lpabc As ABC) As Long
Declare Function GetCharABCWidthsFloat Lib "gdi32" Alias "GetCharABCWidthsFloatA" (ByVal hdc As Long, ByVal iFirstChar As Long, ByVal iLastChar As Long, lpABCF As ABCFLOAT) As Long

Declare Function GetClipBox Lib "gdi32" (ByVal hdc As Long, lpRect As RECT) As Long
Declare Function GetClipRgn Lib "gdi32" (ByVal hdc As Long, ByVal hRgn As Long) As Long
Declare Function GetMetaRgn Lib "gdi32" (ByVal hdc As Long, ByVal hRgn As Long) As Long
Declare Function GetCurrentObject Lib "gdi32" (ByVal hdc As Long, ByVal uObjectType As Long) As Long
Declare Function GetCurrentPositionEx Lib "gdi32" (ByVal hdc As Long, lpPoint As POINTAPI) As Long
Declare Function GetDeviceCaps Lib "gdi32" (ByVal hdc As Long, ByVal nIndex As Long) As Long
Declare Function GetDIBits Lib "gdi32" (ByVal aHDC As Long, ByVal hBitmap As Long, ByVal nStartScan As Long, ByVal nNumScans As Long, ByVal lpBits As Long, lpBI As BITMAPINFO, ByVal wUsage As Long) As Long
Declare Function GetFontData Lib "gdi32" Alias "GetFontDataA" (ByVal hdc As Long, ByVal dwTable As Long, ByVal dwOffset As Long, ByVal lpvBuffer As Long, ByVal cbData As Long) As Long
Declare Function GetGlyphOutline Lib "gdi32" Alias "GetGlyphOutlineA" (ByVal hdc As Long, ByVal uChar As Long, ByVal fuFormat As Long, lpgm As GLYPHMETRICS, ByVal cbBuffer As Long, ByVal lpBuffer As Long, lpmat2 As MAT2) As Long
Declare Function GetGraphicsMode Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetMapMode Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetMetaFileBitsEx Lib "gdi32" (ByVal hMF As Long, ByVal nSize As Long, ByVal lpvData As Long) As Long
Declare Function GetMetaFile Lib "gdi32" Alias "GetMetaFileA" (ByVal lpFileName As String) As Long
Declare Function GetNearestColor Lib "gdi32" (ByVal hdc As Long, ByVal crColor As Long) As Long
Declare Function GetNearestPaletteIndex Lib "gdi32" (ByVal hPalette As Long, ByVal crColor As Long) As Long
Declare Function GetObjectType Lib "gdi32" (ByVal hgdiobj As Long) As Long

Declare Function GetOutlineTextMetrics Lib "gdi32" Alias "GetOutlineTextMetricsA" (ByVal hdc As Long, ByVal cbData As Long, lpotm As OUTLINETEXTMETRIC) As Long

Declare Function GetPaletteEntries Lib "gdi32" (ByVal hPalette As Long, ByVal wStartIndex As Long, ByVal wNumEntries As Long, lpPaletteEntries As PALETTEENTRY) As Long
Declare Function GetPixel Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long) As Long
Declare Function GetPolyFillMode Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetRasterizerCaps Lib "gdi32" (lpraststat As RASTERIZER_STATUS, ByVal cb As Long) As Long
Declare Function GetRegionData Lib "gdi32" Alias "GetRegionDataA" (ByVal hRgn As Long, ByVal dwCount As Long, lpRgnData As RgnData) As Long
Declare Function GetRgnBox Lib "gdi32" (ByVal hRgn As Long, lpRect As RECT) As Long
Declare Function GetStockObject Lib "gdi32" (ByVal nIndex As Long) As Long
Declare Function GetStretchBltMode Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetSystemPaletteEntries Lib "gdi32" (ByVal hdc As Long, ByVal wStartIndex As Long, ByVal wNumEntries As Long, lpPaletteEntries As PALETTEENTRY) As Long
Declare Function GetSystemPaletteUse Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetTextCharacterExtra Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetTextAlign Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetTextColor Lib "gdi32" (ByVal hdc As Long) As Long

Declare Function GetTextExtentPoint Lib "gdi32" Alias "GetTextExtentPointA" (ByVal hdc As Long, ByVal lpszString As String, ByVal cbString As Long, ByVal lpSize As Long) As Long
Declare Function GetTextExtentPoint32 Lib "gdi32" Alias "GetTextExtentPoint32A" (ByVal hdc As Long, ByVal lpsz As String, ByVal cbString As Long, ByVal lpSize As Long) As Long
Declare Function GetTextExtentExPoint Lib "gdi32" Alias "GetTextExtentExPointA" (ByVal hdc As Long, ByVal lpszStr As String, ByVal cchString As Long, ByVal nMaxExtent As Long, lpnFit As Long, ByVal alpDx As Long, ByVal lpSize As Long) As Long

Declare Function GetViewportExtEx Lib "gdi32" (ByVal hdc As Long, lpSize As Size) As Long
Declare Function GetViewportOrgEx Lib "gdi32" (ByVal hdc As Long, lpPoint As POINTAPI) As Long
Declare Function GetWindowExtEx Lib "gdi32" (ByVal hdc As Long, lpSize As Size) As Long
Declare Function GetWindowOrgEx Lib "gdi32" (ByVal hdc As Long, lpPoint As POINTAPI) As Long

Declare Function IntersectClipRect Lib "gdi32" (ByVal hdc As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long) As Long
Declare Function InvertRgn Lib "gdi32" (ByVal hdc As Long, ByVal hRgn As Long) As Long
Declare Function LineTo Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long) As Long

Declare Function OffsetClipRgn Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long) As Long
Declare Function OffsetRgn Lib "gdi32" (ByVal hRgn As Long, ByVal x As Long, ByVal y As Long) As Long
Declare Function Pie Lib "gdi32" (ByVal hdc As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long, ByVal X3 As Long, ByVal Y3 As Long, ByVal X4 As Long, ByVal Y4 As Long) As Long
Declare Function PlayMetaFile Lib "gdi32" (ByVal hdc As Long, ByVal hMF As Long) As Long
Declare Function PaintRgn Lib "gdi32" (ByVal hdc As Long, ByVal hRgn As Long) As Long
Declare Function PolyPolygon Lib "gdi32" (ByVal hdc As Long, lpPoint As POINTAPI, lpPolyCounts As Long, ByVal nCount As Long) As Long
Declare Function PtInRegion Lib "gdi32" (ByVal hRgn As Long, ByVal x As Long, ByVal y As Long) As Long
Declare Function PtVisible Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long) As Long
Declare Function RectVisible Lib "gdi32" (ByVal hdc As Long, lpRect As RECT) As Long
Declare Function RectInRegion Lib "gdi32" (ByVal hRgn As Long, lpRect As RECT) As Long
Declare Function Rectangle Lib "gdi32" (ByVal hdc As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long) As Long
Declare Function RestoreDC Lib "gdi32" (ByVal hdc As Long, ByVal nSavedDC As Long) As Long
Declare Function ResetDC Lib "gdi32" Alias "ResetDCA" (ByVal hdc As Long, lpInitData As DEVMODE) As Long
Declare Function RealizePalette Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function RemoveFontResource Lib "gdi32" Alias "RemoveFontResourceA" (ByVal lpFileName As String) As Long
Declare Function RoundRect Lib "gdi32" (ByVal hdc As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long, ByVal X3 As Long, ByVal Y3 As Long) As Long
Declare Function ResizePalette Lib "gdi32" (ByVal hPalette As Long, ByVal nNumEntries As Long) As Long

Declare Function SaveDC Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function SelectClipRgn Lib "gdi32" (ByVal hdc As Long, ByVal hRgn As Long) As Long
Declare Function ExtSelectClipRgn Lib "gdi32" (ByVal hdc As Long, ByVal hRgn As Long, ByVal fnMode As Long) As Long
Declare Function SetMetaRgn Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function SelectObject Lib "gdi32" (ByVal hdc As Long, ByVal hObject As Long) As Long
Declare Function SelectPalette Lib "gdi32" (ByVal hdc As Long, ByVal hPalette As Long, ByVal bForceBackground As Long) As Long
Declare Function SetBkColor Lib "gdi32" (ByVal hdc As Long, ByVal crColor As Long) As Long
Declare Function SetBkMode Lib "gdi32" (ByVal hdc As Long, ByVal nBkMode As Long) As Long
Declare Function SetBitmapBits Lib "gdi32" (ByVal hBitmap As Long, ByVal dwCount As Long, ByVal lpBits As Long) As Long

Declare Function SetBoundsRect Lib "gdi32" (ByVal hdc As Long, lprcBounds As RECT, ByVal flags As Long) As Long
Declare Function SetDIBits Lib "gdi32" (ByVal hdc As Long, ByVal hBitmap As Long, ByVal nStartScan As Long, ByVal nNumScans As Long, ByVal lpBits As Long, lpBI As BITMAPINFO, ByVal wUsage As Long) As Long
Declare Function SetDIBitsToDevice Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal dx As Long, ByVal dy As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal Scan As Long, ByVal NumScans As Long, ByVal Bits As Long, BitsInfo As BITMAPINFO, ByVal wUsage As Long) As Long
Declare Function SetMapperFlags Lib "gdi32" (ByVal hdc As Long, ByVal dwFlag As Long) As Long
Declare Function SetGraphicsMode Lib "gdi32" (ByVal hdc As Long, ByVal iMode As Long) As Long
Declare Function SetMapMode Lib "gdi32" (ByVal hdc As Long, ByVal nMapMode As Long) As Long
Declare Function SetMetaFileBitsEx Lib "gdi32" (ByVal nSize As Long, lpData As Byte) As Long
Declare Function SetPaletteEntries Lib "gdi32" (ByVal hPalette As Long, ByVal wStartIndex As Long, ByVal wNumEntries As Long, lpPaletteEntries As PALETTEENTRY) As Long
Declare Function SetPixel Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal crColor As Long) As Long
Declare Function SetPixelV Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal crColor As Long) As Long
Declare Function SetPolyFillMode Lib "gdi32" (ByVal hdc As Long, ByVal nPolyFillMode As Long) As Long
Declare Function SetRectRgn Lib "gdi32" (ByVal hRgn As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long) As Long
Declare Function StretchDIBits Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal dx As Long, ByVal dy As Long, ByVal srcx As Long, ByVal srcy As Long, ByVal wSrcWidth As Long, ByVal wSrcHeight As Long, ByVal lpBits As Long, lpBitsInfo As BITMAPINFO, ByVal wUsage As Long, ByVal dwRop As Long) As Long
Declare Function SetROP2 Lib "gdi32" (ByVal hdc As Long, ByVal nDrawMode As Long) As Long
Declare Function SetStretchBltMode Lib "gdi32" (ByVal hdc As Long, ByVal nStretchMode As Long) As Long
Declare Function SetSystemPaletteUse Lib "gdi32" (ByVal hdc As Long, ByVal wUsage As Long) As Long
Declare Function SetTextCharacterExtra Lib "gdi32" Alias "SetTextCharacterExtraA" (ByVal hdc As Long, ByVal nCharExtra As Long) As Long
Declare Function SetTextColor Lib "gdi32" (ByVal hdc As Long, ByVal crColor As Long) As Long
Declare Function SetTextAlign Lib "gdi32" (ByVal hdc As Long, ByVal wFlags As Long) As Long
Declare Function SetTextJustification Lib "gdi32" (ByVal hdc As Long, ByVal nBreakExtra As Long, ByVal nBreakCount As Long) As Long
Declare Function UpdateColors Lib "gdi32" (ByVal hdc As Long) As Long

Declare Function GetProcAddress Lib "kernel32" (ByVal hModule As Long, ByVal lpProcName As String) As Long

Declare Function PlayMetaFileRecord Lib "gdi32" (ByVal hdc As Long, lpHandletable As HANDLETABLE, lpMetaRecord As METARECORD, ByVal nHandles As Long) As Long

Declare Function CloseEnhMetaFile Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function CopyEnhMetaFile Lib "gdi32" Alias "CopyEnhMetaFileA" (ByVal hemfSrc As Long, ByVal lpszFile As String) As Long
Declare Function CreateEnhMetaFile Lib "gdi32" Alias "CreateEnhMetaFileA" (ByVal hdcRef As Long, ByVal lpFileName As String, lpRect As RECT, ByVal lpDescription As String) As Long
Declare Function DeleteEnhMetaFile Lib "gdi32" (ByVal hemf As Long) As Long
Declare Function EnumEnhMetaFile Lib "gdi32" (ByVal hdc As Long, ByVal hemf As Long, ByVal lpEnhMetaFunc As Long, ByVal lpData As Long, lpRect As RECT) As Long
Declare Function GetEnhMetaFile Lib "gdi32" Alias "GetEnhMetaFileA" (ByVal lpszMetaFile As String) As Long
Declare Function GetEnhMetaFileBits Lib "gdi32" (ByVal hemf As Long, ByVal cbBuffer As Long, lpbBuffer As Byte) As Long
Declare Function GetEnhMetaFileDescription Lib "gdi32" Alias "GetEnhMetaFileDescriptionA" (ByVal hemf As Long, ByVal cchBuffer As Long, ByVal lpszDescription As String) As Long
Declare Function GetEnhMetaFileHeader Lib "gdi32" (ByVal hemf As Long, ByVal cbBuffer As Long, lpemh As ENHMETAHEADER) As Long
Declare Function GetEnhMetaFilePaletteEntries Lib "gdi32" (ByVal hemf As Long, ByVal cEntries As Long, lppe As PALETTEENTRY) As Long
Declare Function GetWinMetaFileBits Lib "gdi32" (ByVal hemf As Long, ByVal cbBuffer As Long, lpbBuffer As Byte, ByVal fnMapMode As Long, ByVal hdcRef As Long) As Long
Declare Function PlayEnhMetaFile Lib "gdi32" (ByVal hdc As Long, ByVal hemf As Long, lpRect As RECT) As Long
Declare Function PlayEnhMetaFileRecord Lib "gdi32" (ByVal hdc As Long, lpHandletable As HANDLETABLE, lpEnhMetaRecord As ENHMETARECORD, ByVal nHandles As Long) As Long
Declare Function SetEnhMetaFileBits Lib "gdi32" (ByVal cbBuffer As Long, lpData As Byte) As Long
Declare Function SetWinMetaFileBits Lib "gdi32" (ByVal cbBuffer As Long, lpbBuffer As Byte, ByVal hdcRef As Long, lpmfp As METAFILEPICT) As Long
Declare Function GdiComment Lib "gdi32" (ByVal hdc As Long, ByVal cbSize As Long, lpData As Byte) As Long

Declare Function GetTextMetrics Lib "gdi32" Alias "GetTextMetricsA" (ByVal hdc As Long, lpMetrics As TEXTMETRIC) As Long

Declare Function AngleArc Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal dwRadius As Long, ByVal eStartAngle As Double, ByVal eSweepAngle As Double) As Long
Declare Function PolyPolyline Lib "gdi32" (ByVal hdc As Long, lppt As POINTAPI, lpdwPolyPoints As Long, ByVal cCount As Long) As Long
Declare Function GetWorldTransform Lib "gdi32" (ByVal hdc As Long, lpXform As xform) As Long
Declare Function SetWorldTransform Lib "gdi32" (ByVal hdc As Long, lpXform As xform) As Long
Declare Function ModifyWorldTransform Lib "gdi32" (ByVal hdc As Long, lpXform As xform, ByVal iMode As Long) As Long
Declare Function CombineTransform Lib "gdi32" (lpxformResult As xform, lpxform1 As xform, lpxform2 As xform) As Long

'  Flags value for COLORADJUSTMENT
Public Const CA_NEGATIVE = &H1
Public Const CA_LOG_FILTER = &H2

'  IlluminantIndex values
Public Const ILLUMINANT_DEVICE_DEFAULT = 0
Public Const ILLUMINANT_A = 1
Public Const ILLUMINANT_B = 2
Public Const ILLUMINANT_C = 3
Public Const ILLUMINANT_D50 = 4
Public Const ILLUMINANT_D55 = 5
Public Const ILLUMINANT_D65 = 6
Public Const ILLUMINANT_D75 = 7
Public Const ILLUMINANT_F2 = 8
Public Const ILLUMINANT_MAX_INDEX = ILLUMINANT_F2

Public Const ILLUMINANT_TUNGSTEN = ILLUMINANT_A
Public Const ILLUMINANT_DAYLIGHT = ILLUMINANT_C
Public Const ILLUMINANT_FLUORESCENT = ILLUMINANT_F2
Public Const ILLUMINANT_NTSC = ILLUMINANT_C

'  Min and max for RedGamma, GreenGamma, BlueGamma
Public Const RGB_GAMMA_MIN = 2500 'words
Public Const RGB_GAMMA_MAX = 65000

'  Min and max for ReferenceBlack and ReferenceWhite
Public Const REFERENCE_WHITE_MIN = 6000 'words
Public Const REFERENCE_WHITE_MAX = 10000
Public Const REFERENCE_BLACK_MIN = 0
Public Const REFERENCE_BLACK_MAX = 4000

'  Min and max for Contrast, Brightness, Colorfulness, RedGreenTint
Public Const COLOR_ADJ_MIN = -100 'shorts
Public Const COLOR_ADJ_MAX = 100

Type ColorAdjustment
        caSize As Integer
        caFlags As Integer
        caIlluminantIndex As Integer
        caRedGamma As Integer
        caGreenGamma As Integer
        caBlueGamma As Integer
        caReferenceBlack As Integer
        caReferenceWhite As Integer
        caContrast As Integer
        caBrightness As Integer
        caColorfulness As Integer
        caRedGreenTint As Integer
End Type

Declare Function SetColorAdjustment Lib "gdi32" (ByVal hdc As Long, lpca As ColorAdjustment) As Long
Declare Function GetColorAdjustment Lib "gdi32" (ByVal hdc As Long, lpca As ColorAdjustment) As Long
Declare Function CreateHalftonePalette Lib "gdi32" (ByVal hdc As Long) As Long

Type DOCINFO
        cbSize As Long
        lpszDocName As String
        lpszOutput As String
End Type

Declare Function StartDoc Lib "gdi32" Alias "StartDocA" (ByVal hdc As Long, lpdi As DOCINFO) As Long
Declare Function StartPage Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function EndPage Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function EndDoc Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function AbortDoc Lib "gdi32" (ByVal hdc As Long) As Long

Declare Function AbortPath Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function ArcTo Lib "gdi32" (ByVal hdc As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long, ByVal X3 As Long, ByVal Y3 As Long, ByVal X4 As Long, ByVal Y4 As Long) As Long
Declare Function BeginPath Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function CloseFigure Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function EndPath Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function FillPath Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function FlattenPath Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetPath Lib "gdi32" (ByVal hdc As Long, lpPoint As POINTAPI, lpTypes As Byte, ByVal nSize As Long) As Long
Declare Function PathToRegion Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function PolyDraw Lib "gdi32" (ByVal hdc As Long, lppt As POINTAPI, lpbTypes As Byte, ByVal cCount As Long) As Long
Declare Function SelectClipPath Lib "gdi32" (ByVal hdc As Long, ByVal iMode As Long) As Long
Declare Function SetArcDirection Lib "gdi32" (ByVal hdc As Long, ByVal ArcDirection As Long) As Long
Declare Function SetMiterLimit Lib "gdi32" (ByVal hdc As Long, ByVal eNewLimit As Double, peOldLimit As Double) As Long
Declare Function StrokeAndFillPath Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function StrokePath Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function WidenPath Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function ExtCreatePen Lib "gdi32" (ByVal dwPenStyle As Long, ByVal dwWidth As Long, lplb As LOGBRUSH, ByVal dwStyleCount As Long, lpStyle As Long) As Long
Declare Function GetMiterLimit Lib "gdi32" (ByVal hdc As Long, peLimit As Double) As Long
Declare Function GetArcDirection Lib "gdi32" (ByVal hdc As Long) As Long

Declare Function GetObject Lib "gdi32" Alias "GetObjectA" (ByVal hObject As Long, ByVal nCount As Long, lpObject As Any) As Long
Declare Function MoveToEx Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, lpPoint As POINTAPI) As Long
Declare Function TextOut Lib "gdi32" Alias "TextOutA" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal lpstring As String, ByVal nCount As Long) As Long
Declare Function ExtTextOut Lib "gdi32" Alias "ExtTextOutA" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal wOptions As Long, lpRect As RECT, ByVal lpstring As String, ByVal nCount As Long, lpDX As Long) As Long
Declare Function PolyTextOut Lib "gdi32" Alias "PolyTextOutA" (ByVal hdc As Long, pptxt As POLYTEXT, cStrings As Long) As Long

Declare Function CreatePolygonRgn Lib "gdi32" (lpPoint As POINTAPI, ByVal nCount As Long, ByVal nPolyFillMode As Long) As Long
Declare Function DPtoLP Lib "gdi32" (ByVal hdc As Long, lpPoint As POINTAPI, ByVal nCount As Long) As Long
Declare Function LPtoDP Lib "gdi32" (ByVal hdc As Long, lpPoint As POINTAPI, ByVal nCount As Long) As Long
Declare Function Polyline Lib "gdi32" (ByVal hdc As Long, lpPoint As POINTAPI, ByVal nCount As Long) As Long
Declare Function Polygon Lib "gdi32" (ByVal hdc As Long, lpPoint As POINTAPI, ByVal nCount As Long) As Long

Declare Function PolyBezier Lib "gdi32" (ByVal hdc As Long, lppt As POINTAPI, ByVal cPoints As Long) As Long
Declare Function PolyBezierTo Lib "gdi32" (ByVal hdc As Long, lppt As POINTAPI, ByVal cCount As Long) As Long
Declare Function PolylineTo Lib "gdi32" (ByVal hdc As Long, lppt As POINTAPI, ByVal cCount As Long) As Long

Declare Function SetViewportExtEx Lib "gdi32" (ByVal hdc As Long, ByVal nX As Long, ByVal nY As Long, lpSize As Size) As Long
Declare Function SetViewportOrgEx Lib "gdi32" (ByVal hdc As Long, ByVal nX As Long, ByVal nY As Long, lpPoint As POINTAPI) As Long
Declare Function SetWindowOrgEx Lib "gdi32" (ByVal hdc As Long, ByVal nX As Long, ByVal nY As Long, lpPoint As POINTAPI) As Long
Declare Function SetWindowExtEx Lib "gdi32" (ByVal hdc As Long, ByVal nX As Long, ByVal nY As Long, lpSize As Size) As Long

Declare Function OffsetViewportOrgEx Lib "gdi32" (ByVal hdc As Long, ByVal nX As Long, ByVal nY As Long, lpPoint As POINTAPI) As Long
Declare Function OffsetWindowOrgEx Lib "gdi32" (ByVal hdc As Long, ByVal nX As Long, ByVal nY As Long, lpPoint As POINTAPI) As Long
Declare Function ScaleWindowExtEx Lib "gdi32" (ByVal hdc As Long, ByVal nXnum As Long, ByVal nXdenom As Long, ByVal nYnum As Long, ByVal nYdenom As Long, lpSize As Size) As Long
Declare Function ScaleViewportExtEx Lib "gdi32" (ByVal hdc As Long, ByVal nXnum As Long, ByVal nXdenom As Long, ByVal nYnum As Long, ByVal nYdenom As Long, lpSize As Size) As Long
Declare Function SetBitmapDimensionEx Lib "gdi32" (ByVal hbm As Long, ByVal nX As Long, ByVal nY As Long, lpSize As Size) As Long
Declare Function SetBrushOrgEx Lib "gdi32" (ByVal hdc As Long, ByVal nXOrg As Long, ByVal nYOrg As Long, lppt As POINTAPI) As Long

Declare Function BitBlt Lib "gdi32" (ByVal hDestDC As Long, ByVal x As Long, ByVal y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hSrcDC As Long, ByVal xSrc As Long, ByVal ySrc As Long, ByVal dwRop As Long) As Long
Declare Function StretchBlt Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hSrcDC As Long, ByVal xSrc As Long, ByVal ySrc As Long, ByVal nSrcWidth As Long, ByVal nSrcHeight As Long, ByVal dwRop As Long) As Long
Declare Function MaskBlt Lib "gdi32" (ByVal hDCDest As Long, ByVal nXDest As Long, ByVal nYDest As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hdcSrc As Long, ByVal nXSrc As Long, ByVal nYSrc As Long, ByVal hbmMask As Long, ByVal xMask As Long, ByVal yMask As Long, ByVal dwRop As Long) As Long
Declare Function PlgBlt Lib "gdi32" (ByVal hDCDest As Long, lpPoint As POINTAPI, ByVal hdcSrc As Long, ByVal nXSrc As Long, ByVal nYSrc As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hbmMask As Long, ByVal xMask As Long, ByVal yMask As Long) As Long
Declare Function PatBlt Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal dwRop As Long) As Long

Type TRIVERTEX
        x As Long
        y As Long
        Red As Integer
        Green As Integer
        Blue As Integer
        alpha As Integer
End Type

Type GRADIENT_TRIANGLE
        Vertex1 As Long
        Vertex2 As Long
        Vertex3 As Long
End Type

Type GRADIENT_RECT
        UpperLeft As Long
        LowerRight As Long
End Type

Public Const GRADIENT_FILL_RECT_H    As Long = &H0
Public Const GRADIENT_FILL_RECT_V    As Long = &H1
Public Const GRADIENT_FILL_TRIANGLE  As Long = &H2
Public Const GRADIENT_FILL_OP_FLAG   As Long = &HFF

Declare Function GradientFill Lib "gdi32" Alias "GdiGradientFill" (ByVal hdc As Long, ByVal addrVertexs As Long, ByVal dwNumVertexes As Long, ByVal addrMeshs As Long, ByVal dwNumMeshes As Long, ByVal Mode As Long) As Long

Declare Function GetTextFace Lib "gdi32" Alias "GetTextFaceA" (ByVal hdc As Long, ByVal nCount As Long, ByVal lpFacename As String) As Long

Public Const FONTMAPPER_MAX = 10

Type KERNINGPAIR
        wFirst As Integer
        wSecond As Integer
        iKernAmount As Long
End Type

Declare Function GetKerningPairs Lib "gdi32" Alias "GetKerningPairsA" (ByVal hdc As Long, ByVal cPairs As Long, lpkrnpair As KERNINGPAIR) As Long

Declare Function GetDCOrgEx Lib "gdi32" (ByVal hdc As Long, lpPoint As POINTAPI) As Long
Declare Function UnrealizeObject Lib "gdi32" (ByVal hObject As Long) As Long

Declare Function GdiFlush Lib "gdi32" () As Long
Declare Function GdiSetBatchLimit Lib "gdi32" (ByVal dwLimit As Long) As Long
Declare Function GdiGetBatchLimit Lib "gdi32" () As Long

' Enhanced metafile public constants

Public Const ENHMETA_SIGNATURE = &H464D4520

'  Stock object flag used in the object handle
' index in the enhanced metafile records.
'  E.g. The object handle index (META_STOCK_OBJECT Or BLACK_BRUSH)
'  represents the stock object BLACK_BRUSH.

Public Const ENHMETA_STOCK_OBJECT = &H80000000

'  Enhanced metafile record types.

Public Const EMR_HEADER = 1
Public Const EMR_POLYBEZIER = 2
Public Const EMR_POLYGON = 3
Public Const EMR_POLYLINE = 4
Public Const EMR_POLYBEZIERTO = 5
Public Const EMR_POLYLINETO = 6
Public Const EMR_POLYPOLYLINE = 7
Public Const EMR_POLYPOLYGON = 8
Public Const EMR_SETWINDOWEXTEX = 9
Public Const EMR_SETWINDOWORGEX = 10
Public Const EMR_SETVIEWPORTEXTEX = 11
Public Const EMR_SETVIEWPORTORGEX = 12
Public Const EMR_SETBRUSHORGEX = 13
Public Const EMR_EOF = 14
Public Const EMR_SETPIXELV = 15
Public Const EMR_SETMAPPERFLAGS = 16
Public Const EMR_SETMAPMODE = 17
Public Const EMR_SETBKMODE = 18
Public Const EMR_SETPOLYFILLMODE = 19
Public Const EMR_SETROP2 = 20
Public Const EMR_SETSTRETCHBLTMODE = 21
Public Const EMR_SETTEXTALIGN = 22
Public Const EMR_SETCOLORADJUSTMENT = 23
Public Const EMR_SETTEXTCOLOR = 24
Public Const EMR_SETBKCOLOR = 25
Public Const EMR_OFFSETCLIPRGN = 26
Public Const EMR_MOVETOEX = 27
Public Const EMR_SETMETARGN = 28
Public Const EMR_EXCLUDECLIPRECT = 29
Public Const EMR_INTERSECTCLIPRECT = 30
Public Const EMR_SCALEVIEWPORTEXTEX = 31
Public Const EMR_SCALEWINDOWEXTEX = 32
Public Const EMR_SAVEDC = 33
Public Const EMR_RESTOREDC = 34
Public Const EMR_SETWORLDTRANSFORM = 35
Public Const EMR_MODIFYWORLDTRANSFORM = 36
Public Const EMR_SELECTOBJECT = 37
Public Const EMR_CREATEPEN = 38
Public Const EMR_CREATEBRUSHINDIRECT = 39
Public Const EMR_DELETEOBJECT = 40
Public Const EMR_ANGLEARC = 41
Public Const EMR_ELLIPSE = 42
Public Const EMR_RECTANGLE = 43
Public Const EMR_ROUNDRECT = 44
Public Const EMR_ARC = 45
Public Const EMR_CHORD = 46
Public Const EMR_PIE = 47
Public Const EMR_SELECTPALETTE = 48
Public Const EMR_CREATEPALETTE = 49
Public Const EMR_SETPALETTEENTRIES = 50
Public Const EMR_RESIZEPALETTE = 51
Public Const EMR_REALIZEPALETTE = 52
Public Const EMR_EXTFLOODFILL = 53
Public Const EMR_LINETO = 54
Public Const EMR_ARCTO = 55
Public Const EMR_POLYDRAW = 56
Public Const EMR_SETARCDIRECTION = 57
Public Const EMR_SETMITERLIMIT = 58
Public Const EMR_BEGINPATH = 59
Public Const EMR_ENDPATH = 60
Public Const EMR_CLOSEFIGURE = 61
Public Const EMR_FILLPATH = 62
Public Const EMR_STROKEANDFILLPATH = 63
Public Const EMR_STROKEPATH = 64
Public Const EMR_FLATTENPATH = 65
Public Const EMR_WIDENPATH = 66
Public Const EMR_SELECTCLIPPATH = 67
Public Const EMR_ABORTPATH = 68

Public Const EMR_GDICOMMENT = 70
Public Const EMR_FILLRGN = 71
Public Const EMR_FRAMERGN = 72
Public Const EMR_INVERTRGN = 73
Public Const EMR_PAINTRGN = 74
Public Const EMR_EXTSELECTCLIPRGN = 75
Public Const EMR_BITBLT = 76
Public Const EMR_STRETCHBLT = 77
Public Const EMR_MASKBLT = 78
Public Const EMR_PLGBLT = 79
Public Const EMR_SETDIBITSTODEVICE = 80
Public Const EMR_STRETCHDIBITS = 81
Public Const EMR_EXTCREATEFONTINDIRECTW = 82
Public Const EMR_EXTTEXTOUTA = 83
Public Const EMR_EXTTEXTOUTW = 84
Public Const EMR_POLYBEZIER16 = 85
Public Const EMR_POLYGON16 = 86
Public Const EMR_POLYLINE16 = 87
Public Const EMR_POLYBEZIERTO16 = 88
Public Const EMR_POLYLINETO16 = 89
Public Const EMR_POLYPOLYLINE16 = 90
Public Const EMR_POLYPOLYGON16 = 91
Public Const EMR_POLYDRAW16 = 92
Public Const EMR_CREATEMONOBRUSH = 93
Public Const EMR_CREATEDIBPATTERNBRUSHPT = 94
Public Const EMR_EXTCREATEPEN = 95
Public Const EMR_POLYTEXTOUTA = 96
Public Const EMR_POLYTEXTOUTW = 97

Public Const EMR_MIN = 1
Public Const EMR_MAX = 97

Type emr
        iType As Long
        nSize As Long
End Type

Type emrtext
        ptlReference As POINTL
        nchars As Long
        offString As Long
        fOptions As Long
        rcl As RECTL
        offDx As Long
End Type

Type EMRABORTPATH
        pEmr As emr
End Type

Type EMRBEGINPATH
        pEmr As emr
End Type

Type EMRENDPATH
        pEmr As emr
End Type

Type EMRCLOSEFIGURE
        pEmr As emr
End Type

Type EMRFLATTENPATH
        pEmr As emr
End Type

Type EMRWIDENPATH
        pEmr As emr
End Type

Type EMRSETMETARGN
        pEmr As emr
End Type

Type EMREMRSAVEDC
        pEmr As emr
End Type

Type EMRREALIZEPALETTE
        pEmr As emr
End Type

Type EMRSELECTCLIPPATH
        pEmr As emr
        iMode As Long
End Type

Type EMRSETBKMODE
        pEmr As emr
        iMode As Long
End Type

Type EMRSETMAPMODE
        pEmr As emr
        iMode As Long
End Type

Type EMRSETPOLYFILLMODE
        pEmr As emr
        iMode As Long
End Type

Type EMRSETROP2
        pEmr As emr
        iMode As Long
End Type

Type EMRSETSTRETCHBLTMODE
        pEmr As emr
        iMode As Long
End Type

Type EMRSETTEXTALIGN
        pEmr As emr
        iMode As Long
End Type

Type EMRSETMITERLIMIT
        pEmr As emr
        eMiterLimit As Double
End Type

Type EMRRESTOREDC
        pEmr As emr
        iRelative As Long
End Type

Type EMRSETARCDIRECTION
        pEmr As emr
        iArcDirection As Long
End Type

Type EMRSETMAPPERFLAGS
        pEmr As emr
        dwFlags As Long
End Type

Type EMRSETTEXTCOLOR
        pEmr As emr
        crColor As Long
End Type

Type EMRSETBKCOLOR
        pEmr As emr
        crColor As Long
End Type

Type EMRSELECTOBJECT
        pEmr As emr
        ihObject As Long
End Type

Type EMRDELETEOBJECT
        pEmr As emr
        ihObject As Long
End Type

Type EMRSELECTPALETTE
        pEmr As emr
        ihPal As Long
End Type

Type EMRRESIZEPALETTE
        pEmr As emr
        ihPal As Long
        cEntries As Long
End Type

Type EMRSETPALETTEENTRIES
        pEmr As emr
        ihPal As Long
        iStart As Long
        cEntries As Long
        aPalEntries(1) As PALETTEENTRY
End Type

Type EMRSETCOLORADJUSTMENT
        pEmr As emr
        ColorAdjustment As ColorAdjustment
End Type

Type EMRGDICOMMENT
        pEmr As emr
        cbData As Long
        Data(1) As Integer
End Type

Type EMREOF
        pEmr As emr
        nPalEntries As Long
        offPalEntries As Long
        nSizeLast As Long
End Type

Type EMRLINETO
        pEmr As emr
        ptl As POINTL
End Type

Type EMRMOVETOEX
        pEmr As emr
        ptl As POINTL
End Type

Type EMROFFSETCLIPRGN
        pEmr As emr
        ptlOffset As POINTL
End Type

Type EMRFILLPATH
        pEmr As emr
        rclBounds As RECTL
End Type

Type EMRSTROKEANDFILLPATH
        pEmr As emr
        rclBounds As RECTL
End Type

Type EMRSTROKEPATH
        pEmr As emr
        rclBounds As RECTL
End Type

Type EMREXCLUDECLIPRECT
        pEmr As emr
        rclClip As RECTL
End Type

Type EMRINTERSECTCLIPRECT
        pEmr As emr
        rclClip As RECTL
End Type

Type EMRSETVIEWPORTORGEX
        pEmr As emr
        ptlOrigin As POINTL
End Type

Type EMRSETWINDOWORGEX
        pEmr As emr
        ptlOrigin As POINTL
End Type

Type EMRSETBRUSHORGEX
        pEmr As emr
        ptlOrigin As POINTL
End Type

Type EMRSETVIEWPORTEXTEX
        pEmr As emr
        szlExtent As SIZEL
End Type

Type EMRSETWINDOWEXTEX
        pEmr As emr
        szlExtent As SIZEL
End Type

Type EMRSCALEVIEWPORTEXTEX
        pEmr As emr
        xNum As Long
        xDenom As Long
        yNum As Long
        yDemon As Long
End Type

Type EMRSCALEWINDOWEXTEX
        pEmr As emr
        xNum As Long
        xDenom As Long
        yNum As Long
        yDemon As Long
End Type

Type EMRSETWORLDTRANSFORM
        pEmr As emr
        xform As xform
End Type

Type EMRMODIFYWORLDTRANSFORM
        pEmr As emr
        xform As xform
        iMode As Long
End Type

Type EMRSETPIXELV
        pEmr As emr
        ptlPixel As POINTL
        crColor As Long
End Type

Type EMREXTFLOODFILL
        pEmr As emr
        ptlStart As POINTL
        crColor As Long
        iMode As Long
End Type

Type EMRELLIPSE
        pEmr As emr
        rclBox As RECTL
End Type

Type EMRRECTANGLE
        pEmr As emr
        rclBox As RECTL
End Type

Type EMRROUNDRECT
        pEmr As emr
        rclBox As RECTL
        szlCorner As SIZEL
End Type

Type EMRARC
        pEmr As emr
        rclBox As RECTL
        ptlStart As POINTL
        ptlEnd As POINTL
End Type

Type EMRARCTO
        pEmr As emr
        rclBox As RECTL
        ptlStart As POINTL
        ptlEnd As POINTL
End Type

Type EMRCHORD
        pEmr As emr
        rclBox As RECTL
        ptlStart As POINTL
        ptlEnd As POINTL
End Type

Type EMRPIE
        pEmr As emr
        rclBox As RECTL
        ptlStart As POINTL
        ptlEnd As POINTL
End Type

Type EMRANGLEARC
        pEmr As emr
        ptlCenter As POINTL
        nRadius As Long
        eStartAngle As Double
        eSweepAngle As Double
End Type

Type EMRPOLYLINE
        pEmr As emr
        rclBounds As RECTL
        cptl As Long
        aptl(1) As POINTL
End Type

Type EMRPOLYBEZIER
        pEmr As emr
        rclBounds As RECTL
        cptl As Long
        aptl(1) As POINTL
End Type

Type EMRPOLYGON
        pEmr As emr
        rclBounds As RECTL
        cptl As Long
        aptl(1) As POINTL
End Type

Type EMRPOLYBEZIERTO
        pEmr As emr
        rclBounds As RECTL
        cptl As Long
        aptl(1) As POINTL
End Type

Type EMRPOLYLINE16
        pEmr As emr
        rclBounds As RECTL
        cpts As Long
        apts(1) As POINTS
End Type

Type EMRPOLYBEZIER16
        pEmr As emr
        rclBounds As RECTL
        cpts As Long
        apts(1) As POINTS
End Type

Type EMRPOLYGON16
        pEmr As emr
        rclBounds As RECTL
        cpts As Long
        apts(1) As POINTS
End Type

Type EMRPLOYBEZIERTO16
        pEmr As emr
        rclBounds As RECTL
        cpts As Long
        apts(1) As POINTS
End Type

Type EMRPOLYLINETO16
        pEmr As emr
        rclBounds As RECTL
        cpts As Long
        apts(1) As POINTS
End Type

Type EMRPOLYDRAW
        pEmr As emr
        rclBounds As RECTL
        cptl As Long
        aptl(1) As POINTL
        abTypes(1) As Integer
End Type

Type EMRPOLYDRAW16
        pEmr As emr
        rclBounds As RECTL
        cpts As Long
        apts(1) As POINTS
        abTypes(1) As Integer
End Type

Type EMRPOLYPOLYLINE
        pEmr As emr
        rclBounds As RECTL
        nPolys As Long
        cptl As Long
        aPolyCounts(1) As Long
        aptl(1) As POINTL
End Type

Type EMRPOLYPOLYGON
        pEmr As emr
        rclBounds As RECTL
        nPolys As Long
        cptl As Long
        aPolyCounts(1) As Long
        aptl(1) As POINTL
End Type

Type EMRPOLYPOLYLINE16
        pEmr As emr
        rclBounds As RECTL
        nPolys As Long
        cpts As Long
        aPolyCounts(1) As Long
        apts(1) As POINTS
End Type

Type EMRPOLYPOLYGON16
        pEmr As emr
        rclBounds As RECTL
        nPolys As Long
        cpts As Long
        aPolyCounts(1) As Long
        apts(1) As POINTS
End Type

Type EMRINVERTRGN
        pEmr As emr
        rclBounds As RECTL
        cbRgnData As Long
        RgnData(1) As Integer
End Type

Type EMRPAINTRGN
        pEmr As emr
        rclBounds As RECTL
        cbRgnData As Long
        RgnData(1) As Integer
End Type

Type EMRFILLRGN
        pEmr As emr
        rclBounds As RECTL
        cbRgnData As Long
        ihBrush As Long
        RgnData(1) As Integer
End Type

Type EMRFRAMERGN
        pEmr As emr
        rclBounds As RECTL
        cbRgnData As Long
        ihBrush As Long
        szlStroke As SIZEL
        RgnData(1) As Integer
End Type

Type EMREXTSELECTCLIPRGN
        pEmr As emr
        cbRgnData As Long
        iMode As Long
        RgnData(1) As Integer
End Type

Type EMREXTTEXTOUT
        pEmr As emr
        rclBounds As RECTL
        iGraphicsMode As Long
        exScale As Double
        eyScale As Double
        emrtext As emrtext
End Type

Type EMRBITBLT
        pEmr As emr
        rclBounds As RECTL
        xDest As Long
        yDest As Long
        cxDest As Long
        cyDest As Long
        dwRop As Long
        xSrc As Long
        ySrc As Long
        xformSrc As xform
        crBkColorSrc As Long
        iUsageSrc As Long
        offBmiSrc As Long
        cbBmiSrc As Long
        offBitsSrc As Long
        cbBitsSrc As Long
End Type

Type EMRSTRETCHBLT
        pEmr As emr
        rclBounds As RECTL
        xDest As Long
        yDest As Long
        cxDest As Long
        cyDest As Long
        dwRop As Long
        xSrc As Long
        ySrc As Long
        xformSrc As xform
        crBkColorSrc As Long
        iUsageSrc As Long
        offBmiSrc As Long
        cbBmiSrc As Long
        offBitsSrc As Long
        cbBitsSrc As Long
        cxSrc As Long
        cySrc As Long
End Type

Type EMRMASKBLT
        pEmr As emr
        rclBounds As RECTL
        xDest As Long
        yDest As Long
        cxDest As Long
        cyDest As Long
        dwRop As Long
        xSrc2 As Long
        cyDest2 As Long
        dwRop2 As Long
        xSrc As Long
        ySrc As Long
        xformSrc As xform
        crBkColorSrc As Long
        iUsageSrc As Long
        offBmiSrc As Long
        cbBmiSrc As Long
        offBitsSrc As Long
        cbBitsSrc As Long
        xMask As Long
        yMask As Long
        iUsageMask As Long
        offBmiMask As Long
        cbBmiMask As Long
        offBitsMask As Long
        cbBitsMask As Long
End Type

Type EMRPLGBLT
        pEmr As emr
        rclBounds As RECTL
        aptlDest(3) As POINTL
        xSrc As Long
        ySrc As Long
        cxSrc As Long
        cySrc As Long
        xformSrc As xform
        crBkColorSrc As Long
        iUsageSrc As Long
        offBmiSrc As Long
        cbBmiSrc As Long
        offBitsSrc As Long
        cbBitsSrc As Long
        xMask As Long
        yMask As Long
        iUsageMask As Long
        offBmiMask As Long
        cbBmiMask As Long
        offBitsMask As Long
        cbBitsMask As Long
End Type

Type EMRSETDIBITSTODEVICE
        pEmr As emr
        rclBounds As RECTL
        xDest As Long
        yDest As Long
        xSrc As Long
        ySrc As Long
        cxSrc As Long
        cySrc As Long
        offBmiSrc As Long
        cbBmiSrc As Long
        offBitsSrc As Long
        cbBitsSrc As Long
        iUsageSrc As Long
        iStartScan As Long
        cScans As Long
End Type

Type EMRSTRETCHDIBITS
        pEmr As emr
        rclBounds As RECTL
        xDest As Long
        yDest As Long
        xSrc As Long
        ySrc As Long
        cxSrc As Long
        cySrc As Long
        offBmiSrc As Long
        cbBmiSrc As Long
        offBitsSrc As Long
        cbBitsSrc As Long
        iUsageSrc As Long
        dwRop As Long
        cxDest As Long
        cyDest As Long
End Type

Type EMREXTCREATEFONTINDIRECT
        pEmr As emr
        ihFont As Long
        elfw As EXTLOGFONT
End Type

Type EMRCREATEPALETTE
        pEmr As emr
        ihPal As Long
        lgpl As LOGPALETTE
End Type

Type EMRCREATEPEN
        pEmr As emr
        ihPen As Long
        lopn As LOGPEN
End Type

Type EMREXTCREATEPEN
        pEmr As emr
        ihPen As Long
        offBmi As Long
        cbBmi As Long
        offBits As Long
        cbBits As Long
        elp As EXTLOGPEN
End Type

Type EMRCREATEBRUSHINDIRECT
        pEmr As emr
        ihBrush As Long
        lb As LOGBRUSH
End Type

Type EMRCREATEMONOBRUSH
        pEmr As emr
        ihBrush As Long
        iUsage As Long
        offBmi As Long
        cbBmi As Long
        offBits As Long
        cbBits As Long
End Type

Type EMRCREATEDIBPATTERNBRUSHPT
        pEmr As emr
        ihBursh As Long
        iUsage As Long
        offBmi As Long
        cbBmi As Long
        offBits As Long
        cbBits As Long
End Type

' new wingdi
' *************************************************************************
' *                                                                         *
' * wingdi.h -- GDI procedure declarations, public constant definitions and macros *
' *                                                                         *
' * Copyright (c) 1985-1995, Microsoft Corp. All rights reserved.           *
' *                                                                         *
' **************************************************************************/

'  StretchBlt() Modes
Public Const STRETCH_ANDSCANS = 1
Public Const STRETCH_ORSCANS = 2
Public Const STRETCH_DELETESCANS = 3
Public Const STRETCH_HALFTONE = 4

Type BITMAPV4HEADER
        bV4Size As Long
        bV4Width As Long
        bV4Height As Long
        bV4Planes As Integer
        bV4BitCount As Integer
        bV4V4Compression As Long
        bV4SizeImage As Long
        bV4XPelsPerMeter As Long
        bV4YPelsPerMeter As Long
        bV4ClrUsed As Long
        bV4ClrImportant As Long
        bV4RedMask As Long
        bV4GreenMask As Long
        bV4BlueMask As Long
        bV4AlphaMask As Long
        bV4CSType As Long
        bV4Endpoints As Long
        bV4GammaRed As Long
        bV4GammaGreen As Long
        bV4GammaBlue As Long
End Type

Type FONTSIGNATURE
        fsUsb(4) As Long
        fsCsb(2) As Long
End Type

Type CHARSETINFO
        ciCharset As Long
        ciACP As Long
        fs As FONTSIGNATURE
End Type

Public Const TCI_SRCCHARSET = 1
Public Const TCI_SRCCODEPAGE = 2
Public Const TCI_SRCFONTSIG = 3

Type LOCALESIGNATURE
        lsUsb(4) As Long
        lsCsbDefault(2) As Long
        lsCsbSupported(2) As Long
End Type

Type NEWTEXTMETRICEX
        ntmTm As NEWTEXTMETRIC
        ntmFontSig As FONTSIGNATURE
End Type

Type ENUMLOGFONTEX
        elfLogFont As LOGFONT
        elfFullName(LF_FULLFACESIZE) As Byte
        elfStyle(LF_FACESIZE) As Byte
        elfScript(LF_FACESIZE) As Byte
End Type

Public Const MONO_FONT = 8
Public Const JOHAB_CHARSET = 130
Public Const HEBREW_CHARSET = 177
Public Const ARABIC_CHARSET = 178
Public Const GREEK_CHARSET = 161
Public Const TURKISH_CHARSET = 162
Public Const THAI_CHARSET = 222
Public Const EASTEUROPE_CHARSET = 238
Public Const RUSSIAN_CHARSET = 204

Public Const MAC_CHARSET = 77
Public Const BALTIC_CHARSET = 186

Public Const FS_LATIN1 = &H1&
Public Const FS_LATIN2 = &H2&
Public Const FS_CYRILLIC = &H4&
Public Const FS_GREEK = &H8&
Public Const FS_TURKISH = &H10&
Public Const FS_HEBREW = &H20&
Public Const FS_ARABIC = &H40&
Public Const FS_BALTIC = &H80&
Public Const FS_THAI = &H10000
Public Const FS_JISJAPAN = &H20000
Public Const FS_CHINESESIMP = &H40000
Public Const FS_WANSUNG = &H80000
Public Const FS_CHINESETRAD = &H100000
Public Const FS_JOHAB = &H200000
Public Const FS_SYMBOL = &H80000000
Public Const DEFAULT_GUI_FONT = 17
'  current version of specification
Public Const DM_RESERVED1 = &H800000
Public Const DM_RESERVED2 = &H1000000
Public Const DM_ICMMETHOD = &H2000000
Public Const DM_ICMINTENT = &H4000000
Public Const DM_MEDIATYPE = &H8000000
Public Const DM_DITHERTYPE = &H10000000
Public Const DMPAPER_ISO_B4 = 42                '  B4 (ISO) 250 x 353 mm
Public Const DMPAPER_JAPANESE_POSTCARD = 43     '  Japanese Postcard 100 x 148 mm
Public Const DMPAPER_9X11 = 44                  '  9 x 11 in
Public Const DMPAPER_10X11 = 45                 '  10 x 11 in
Public Const DMPAPER_15X11 = 46                 '  15 x 11 in
Public Const DMPAPER_ENV_INVITE = 47            '  Envelope Invite 220 x 220 mm
Public Const DMPAPER_RESERVED_48 = 48           '  RESERVED--DO NOT USE
Public Const DMPAPER_RESERVED_49 = 49           '  RESERVED--DO NOT USE
Public Const DMPAPER_LETTER_EXTRA = 50              '  Letter Extra 9 \275 x 12 in
Public Const DMPAPER_LEGAL_EXTRA = 51               '  Legal Extra 9 \275 x 15 in
Public Const DMPAPER_TABLOID_EXTRA = 52              '  Tabloid Extra 11.69 x 18 in
Public Const DMPAPER_A4_EXTRA = 53                   '  A4 Extra 9.27 x 12.69 in
Public Const DMPAPER_LETTER_TRANSVERSE = 54     '  Letter Transverse 8 \275 x 11 in
Public Const DMPAPER_A4_TRANSVERSE = 55         '  A4 Transverse 210 x 297 mm
Public Const DMPAPER_LETTER_EXTRA_TRANSVERSE = 56 '  Letter Extra Transverse 9\275 x 12 in
Public Const DMPAPER_A_PLUS = 57                '  SuperA/SuperA/A4 227 x 356 mm
Public Const DMPAPER_B_PLUS = 58                '  SuperB/SuperB/A3 305 x 487 mm
Public Const DMPAPER_LETTER_PLUS = 59           '  Letter Plus 8.5 x 12.69 in
Public Const DMPAPER_A4_PLUS = 60               '  A4 Plus 210 x 330 mm
Public Const DMPAPER_A5_TRANSVERSE = 61         '  A5 Transverse 148 x 210 mm
Public Const DMPAPER_B5_TRANSVERSE = 62         '  B5 (JIS) Transverse 182 x 257 mm
Public Const DMPAPER_A3_EXTRA = 63              '  A3 Extra 322 x 445 mm
Public Const DMPAPER_A5_EXTRA = 64              '  A5 Extra 174 x 235 mm
Public Const DMPAPER_B5_EXTRA = 65              '  B5 (ISO) Extra 201 x 276 mm
Public Const DMPAPER_A2 = 66                    '  A2 420 x 594 mm
Public Const DMPAPER_A3_TRANSVERSE = 67         '  A3 Transverse 297 x 420 mm
Public Const DMPAPER_A3_EXTRA_TRANSVERSE = 68   '  A3 Extra Transverse 322 x 445 mm
Public Const DMTT_DOWNLOAD_OUTLINE = 4 '  download TT fonts as outline soft fonts

'  ICM methods
Public Const DMICMMETHOD_NONE = 1       '  ICM disabled
Public Const DMICMMETHOD_SYSTEM = 2     '  ICM handled by system
Public Const DMICMMETHOD_DRIVER = 3     '  ICM handled by driver
Public Const DMICMMETHOD_DEVICE = 4     '  ICM handled by device
Public Const DMICMMETHOD_USER = 256     '  Device-specific methods start here

'  ICM Intents
Public Const DMICM_SATURATE = 1         '  Maximize color saturation
Public Const DMICM_CONTRAST = 2         '  Maximize color contrast
Public Const DMICM_COLORMETRIC = 3      '  Use specific color metric
Public Const DMICM_USER = 256           '  Device-specific intents start here

'  Media types
Public Const DMMEDIA_STANDARD = 1         '  Standard paper
Public Const DMMEDIA_GLOSSY = 2           '  Glossy paper
Public Const DMMEDIA_TRANSPARENCY = 3     '  Transparency

Public Const DMMEDIA_USER = 256           '  Device-specific media start here

'  Dither types
Public Const DMDITHER_NONE = 1          '  No dithering
Public Const DMDITHER_COARSE = 2        '  Dither with a coarse brush
Public Const DMDITHER_FINE = 3          '  Dither with a fine brush
Public Const DMDITHER_LINEART = 4       '  LineArt dithering
Public Const DMDITHER_GRAYSCALE = 5     '  Device does grayscaling
Public Const DMDITHER_USER = 256        '  Device-specific dithers start here
Public Const GGO_GRAY2_BITMAP = 4
Public Const GGO_GRAY4_BITMAP = 5
Public Const GGO_GRAY8_BITMAP = 6
Public Const GGO_GLYPH_INDEX = &H80
Public Const GCP_DBCS = &H1
Public Const GCP_REORDER = &H2
Public Const GCP_USEKERNING = &H8
Public Const GCP_GLYPHSHAPE = &H10
Public Const GCP_LIGATE = &H20
Public Const GCP_DIACRITIC = &H100
Public Const GCP_KASHIDA = &H400
Public Const GCP_ERROR = &H8000
Public Const FLI_MASK = &H103B
Public Const GCP_JUSTIFY = &H10000
Public Const GCP_NODIACRITICS = &H20000
Public Const FLI_GLYPHS = &H40000
Public Const GCP_CLASSIN = &H80000
Public Const GCP_MAXEXTENT = &H100000
Public Const GCP_JUSTIFYIN = &H200000
Public Const GCP_DISPLAYZWG = &H400000
Public Const GCP_SYMSWAPOFF = &H800000
Public Const GCP_NUMERICOVERRIDE = &H1000000
Public Const GCP_NEUTRALOVERRIDE = &H2000000
Public Const GCP_NUMERICSLATIN = &H4000000
Public Const GCP_NUMERICSLOCAL = &H8000000
Public Const GCPCLASS_LATIN = 1
Public Const GCPCLASS_HEBREW = 2
Public Const GCPCLASS_ARABIC = 2
Public Const GCPCLASS_NEUTRAL = 3
Public Const GCPCLASS_LOCALNUMBER = 4
Public Const GCPCLASS_LATINNUMBER = 5
Public Const GCPCLASS_LATINNUMERICTERMINATOR = 6
Public Const GCPCLASS_LATINNUMERICSEPARATOR = 7
Public Const GCPCLASS_NUMERICSEPARATOR = 8
Public Const GCPCLASS_PREBOUNDRTL = &H80
Public Const GCPCLASS_PREBOUNDLTR = &H40



Type GCP_RESULTS
        lStructSize As Long
        lpOutString As String
        lpOrder As Long
        lpDX As Long
        lpCaretPos As Long
        lpClass As String
        lpGlyphs As String
        nGlyphs As Long
        nMaxFit As Long
End Type

Public Const DC_BINADJUST = 19
Public Const DC_EMF_COMPLIANT = 20
Public Const DC_DATATYPE_PRODUCED = 21
Public Const DC_COLLATE = 22

Public Const DCTT_DOWNLOAD_OUTLINE = &H8&

'  return values for DC_BINADJUST
Public Const DCBA_FACEUPNONE = &H0
Public Const DCBA_FACEUPCENTER = &H1
Public Const DCBA_FACEUPLEFT = &H2
Public Const DCBA_FACEUPRIGHT = &H3
Public Const DCBA_FACEDOWNNONE = &H100
Public Const DCBA_FACEDOWNCENTER = &H101
Public Const DCBA_FACEDOWNLEFT = &H102
Public Const DCBA_FACEDOWNRIGHT = &H103

Declare Function EnumFontFamilies Lib "gdi32" Alias "EnumFontFamiliesA" (ByVal hdc As Long, ByVal lpszFamily As String, ByVal lpEnumFontFamProc As Long, ByVal lParam As Long) As Long
Declare Function EnumFontFamiliesEx Lib "gdi32" Alias "EnumFontFamiliesExA" (ByVal hdc As Long, lpLogFont As LOGFONT, ByVal lpEnumFontProc As Long, ByVal lParam As Long, ByVal dw As Long) As Long
Declare Function GetTextCharset Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetTextCharsetInfo Lib "gdi32" (ByVal hdc As Long, lpSig As FONTSIGNATURE, ByVal dwFlags As Long) As Long

Declare Function TranslateCharsetInfo Lib "gdi32" (lpSrc As Long, lpcs As CHARSETINFO, ByVal dwFlags As Long) As Long
Declare Function GetFontLanguageInfo Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetCharacterPlacement Lib "gdi32" Alias " GetCharacterPlacementA" (ByVal hdc As Long, ByVal lpsz As String, ByVal n1 As Long, ByVal n2 As Long, lpGcpResults As GCP_RESULTS, ByVal dw As Long) As Long

Public Const ICM_OFF = 1
Public Const ICM_ON = 2
Public Const ICM_QUERY = 3

Type CIEXYZ
        ciexyzX As Long
        ciexyzY As Long
        ciexyzZ As Long
End Type

Type CIEXYZTRIPLE
    ciexyzRed As CIEXYZ
    ciexyzGreen As CIEXYZ
    ciexyBlue As CIEXYZ
End Type

Public Const MAX_PATH As Integer = 260

Type LOGCOLORSPACE
    lcsSignature As Long
    lcsVersion As Long
    lcsSize As Long
    lcsCSType As Long
    lcsIntent As Long
    lcsEndPoints As CIEXYZTRIPLE
    lcsGammaRed As Long
    lcsGammaGreen As Long
    lcsGammaBlue As Long
    lcsFileName As String * MAX_PATH
End Type

Declare Function SetICMMode Lib "gdi32" (ByVal hdc As Long, ByVal n As Long) As Long
Declare Function CheckColorsInGamut Lib "gdi32" (ByVal hdc As Long, lpv As Any, lpv2 As Any, ByVal dw As Long) As Long
Declare Function GetLogColorSpace Lib "gdi32" Alias "GetLogColorSpaceA" (ByVal hcolorspace As Long, ByVal lplogcolorspace As LOGCOLORSPACE, ByVal dw As Long) As Long
Declare Function GetColorSpace Lib "gdi32" (ByVal hdc As Long) As Long

Declare Function CreateColorSpace Lib "gdi32" Alias "CreateColorSpaceA" (lplogcolorspace As LOGCOLORSPACE) As Long

Declare Function SetColorSpace Lib "gdi32" (ByVal hdc As Long, ByVal hcolorspace As Long) As Long
Declare Function DeleteColorSpace Lib "gdi32" (ByVal hcolorspace As Long) As Long
Declare Function GetICMProfile Lib "gdi32" Alias "GetICMProfileA" (ByVal hdc As Long, ByVal dw As Long, ByVal lpStr As String) As Long
Declare Function SetICMProfile Lib "gdi32" Alias "SetICMProfileA" (ByVal hdc As Long, ByVal lpStr As String) As Long
Declare Function GetDeviceGammaRamp Lib "gdi32" (ByVal hdc As Long, lpv As Any) As Long
Declare Function SetDeviceGammaRamp Lib "gdi32" (ByVal hdc As Long, lpv As Any) As Long
Declare Function ColorMatchToTarget Lib "gdi32" (ByVal hdc As Long, ByVal hdc2 As Long, ByVal dw As Long) As Long

Declare Function EnumICMProfiles Lib "gdi32" Alias "EnumICMProfilesA" (ByVal hdc As Long, ByVal icmEnumProc As Long, ByVal lParam As Long) As Long

Public Const EMR_SETICMMODE = 98
Public Const EMR_CREATECOLORSPACE = 99
Public Const EMR_SETCOLORSPACE = 100
Public Const EMR_DELETECOLORSPACE = 101

Type EMRSELECTCOLORSPACE
        pEmr As emr
        ihCS As Long               '  ColorSpace handle index
End Type

Type EMRCREATECOLORSPACE
        pEmr As emr
        ihCS As Long        '  ColorSpace handle index
        lcs As LOGCOLORSPACE
End Type

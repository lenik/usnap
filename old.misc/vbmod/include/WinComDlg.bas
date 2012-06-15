Attribute VB_Name = "modWinCommonDialog"
Option Explicit

Type OPENFILENAME
        lStructSize As Long
        hwndOwner As Long
        hInstance As Long
        strFilter As String
        lpstrCustomFilter As Long
        nMaxCustFilter As Long
        nFilterIndex As Long

        lpstrFile As Long
        nMaxFile As Long

        lpstrFileTitle As Long
        nMaxFileTitle As Long

        strInitialDir As String
        strTitle As String
        Flags As Long
        nFileOffset As Integer
        nFileExtension As Integer
        lpstrDefExt As String
        lCustData As Long
        lpfnHook As Long
        lpTemplateName As String
End Type

Declare Function GetOpenFileName Lib "comdlg32.dll" Alias "GetOpenFileNameA" (pOpenfilename As OPENFILENAME) As Long

Declare Function GetSaveFileName Lib "comdlg32.dll" Alias "GetSaveFileNameA" (pOpenfilename As OPENFILENAME) As Long

Declare Function GetFileTitle Lib "comdlg32.dll" Alias "GetFileTitleA" (ByVal lpszFile As String, ByVal lpszTitle As String, ByVal cbBuf As Integer) As Integer

Const OFN_READONLY = &H1
Const OFN_OVERWRITEPROMPT = &H2
Const OFN_HIDEREADONLY = &H4
Const OFN_NOCHANGEDIR = &H8
Const OFN_SHOWHELP = &H10
Const OFN_ENABLEHOOK = &H20
Const OFN_ENABLETEMPLATE = &H40
Const OFN_ENABLETEMPLATEHANDLE = &H80
Const OFN_NOVALIDATE = &H100
Const OFN_ALLOWMULTISELECT = &H200
Const OFN_EXTENSIONDIFFERENT = &H400
Const OFN_PATHMUSTEXIST = &H800
Const OFN_FILEMUSTEXIST = &H1000
Const OFN_CREATEPROMPT = &H2000
Const OFN_SHAREAWARE = &H4000
Const OFN_NOREADONLYRETURN = &H8000
Const OFN_NOTESTFILECREATE = &H10000
Const OFN_NONETWORKBUTTON = &H20000
Const OFN_NOLONGNAMES = &H40000                      '  force no long names for 4.x modules
Const OFN_EXPLORER = &H80000                         '  new look commdlg
Const OFN_NODEREFERENCELINKS = &H100000
Const OFN_LONGNAMES = &H200000                       '  force long names for 3.x modules

Const OFN_SHAREFALLTHROUGH = 2
Const OFN_SHARENOWARN = 1
Const OFN_SHAREWARN = 0

Type NMHDR
    hwndFrom As Long
    idfrom As Long
    code As Long
End Type

Type OFNOTIFY
        hdr As NMHDR
        lpOFN As OPENFILENAME
        pszFile As String        '  May be NULL
End Type

Const CDM_FIRST = (WM_USER + 100)
Const CDM_LAST = (WM_USER + 200)
Const CDM_GETSPEC = (CDM_FIRST + &H0)
Const CDM_GETFILEPATH = (CDM_FIRST + &H1)
Const CDM_GETFOLDERPATH = (CDM_FIRST + &H2)
Const CDM_GETFOLDERIDLIST = (CDM_FIRST + &H3)
Const CDM_SETCONTROLTEXT = (CDM_FIRST + &H4)
Const CDM_HIDECONTROL = (CDM_FIRST + &H5)
Const CDM_SETDEFEXT = (CDM_FIRST + &H6)

Type ChooseColor
        lStructSize As Long
        hwndOwner As Long
        hInstance As Long
        rgbResult As Long
        lpCustColors As Long
        Flags As Long
        lCustData As Long
        lpfnHook As Long
        lpTemplateName As String
End Type

Declare Function ChooseColor Lib "comdlg32.dll" Alias "ChooseColorA" (pChoosecolor As ChooseColor) As Long

Const CC_RGBINIT = &H1
Const CC_FULLOPEN = &H2
Const CC_PREVENTFULLOPEN = &H4
Const CC_SHOWHELP = &H8
Const CC_ENABLEHOOK = &H10
Const CC_ENABLETEMPLATE = &H20
Const CC_ENABLETEMPLATEHANDLE = &H40
Const CC_SOLIDCOLOR = &H80
Const CC_ANYCOLOR = &H100

Type FINDREPLACE
        lStructSize As Long        '  size of this struct 0x20
        hwndOwner As Long          '  handle to owner's window
        hInstance As Long          '  instance handle of.EXE that
                                    '    contains cust. dlg. template
        Flags As Long              '  one or more of the FR_??
        lpstrFindWhat As String      '  ptr. to search string
        lpstrReplaceWith As String   '  ptr. to replace string
        wFindWhatLen As Integer       '  size of find buffer
        wReplaceWithLen As Integer    '  size of replace buffer
        lCustData As Long          '  data passed to hook fn.
        lpfnHook As Long            '  ptr. to hook fn. or NULL
        lpTemplateName As String     '  custom template name
End Type

Const FR_DOWN = &H1
Const FR_WHOLEWORD = &H2
Const FR_MATCHCASE = &H4
Const FR_FINDNEXT = &H8
Const FR_REPLACE = &H10
Const FR_REPLACEALL = &H20
Const FR_DIALOGTERM = &H40
Const FR_SHOWHELP = &H80
Const FR_ENABLEHOOK = &H100
Const FR_ENABLETEMPLATE = &H200
Const FR_NOUPDOWN = &H400
Const FR_NOMATCHCASE = &H800
Const FR_NOWHOLEWORD = &H1000
Const FR_ENABLETEMPLATEHANDLE = &H2000
Const FR_HIDEUPDOWN = &H4000
Const FR_HIDEMATCHCASE = &H8000
Const FR_HIDEWHOLEWORD = &H10000

Declare Function FindText Lib "comdlg32.dll" Alias "FindTextA " (pFindreplace As FINDREPLACE) As Long

Declare Function ReplaceText Lib "comdlg32.dll" Alias "ReplaceTextA" (pFindreplace As FINDREPLACE) As Long

Type ChooseFont
        lStructSize As Long
        hwndOwner As Long          '  caller's window handle
        hdc As Long                '  printer DC/IC or NULL
        lpLogFont As Long
        iPointSize As Long         '  10 * size in points of selected font
        Flags As Long              '  enum. type flags
        rgbColors As Long          '  returned text color
        lCustData As Long          '  data passed to hook fn.
        lpfnHook As Long           '  ptr. to hook function
        lpTemplateName As String     '  custom template name
        hInstance As Long          '  instance handle of.EXE that
                                       '    contains cust. dlg. template
        lpszStyle As String          '  return the style field here
                                       '  must be LF_FACESIZE or bigger
        nFontType As Integer          '  same value reported to the EnumFonts
                                       '    call back with the extra FONTTYPE_
                                       '    bits added
        MISSING_ALIGNMENT As Integer
        nSizeMin As Long           '  minimum pt size allowed &
        nSizeMax As Long           '  max pt size allowed if
                                       '    CF_LIMITSIZE is used
End Type

Declare Function ChooseFont Lib "comdlg32.dll" Alias "ChooseFontA" (pChoosefont As ChooseFont) As Long

Const CF_SCREENFONTS = &H1
Const CF_PRINTERFONTS = &H2
Const CF_BOTH = (CF_SCREENFONTS Or CF_PRINTERFONTS)
Const CF_SHOWHELP = &H4&
Const CF_ENABLEHOOK = &H8&
Const CF_ENABLETEMPLATE = &H10&
Const CF_ENABLETEMPLATEHANDLE = &H20&
Const CF_INITTOLOGFONTSTRUCT = &H40&
Const CF_USESTYLE = &H80&
Const CF_EFFECTS = &H100&
Const CF_APPLY = &H200&
Const CF_ANSIONLY = &H400&
Const CF_SCRIPTSONLY = CF_ANSIONLY
Const CF_NOVECTORFONTS = &H800&
Const CF_NOOEMFONTS = CF_NOVECTORFONTS
Const CF_NOSIMULATIONS = &H1000&
Const CF_LIMITSIZE = &H2000&
Const CF_FIXEDPITCHONLY = &H4000&
Const CF_WYSIWYG = &H8000 '  must also have CF_SCREENFONTS CF_PRINTERFONTS
Const CF_FORCEFONTEXIST = &H10000
Const CF_SCALABLEONLY = &H20000
Const CF_TTONLY = &H40000
Const CF_NOFACESEL = &H80000
Const CF_NOSTYLESEL = &H100000
Const CF_NOSIZESEL = &H200000
Const CF_SELECTSCRIPT = &H400000
Const CF_NOSCRIPTSEL = &H800000
Const CF_NOVERTFONTS = &H1000000

Const SIMULATED_FONTTYPE = &H8000
Const PRINTER_FONTTYPE = &H4000
Const SCREEN_FONTTYPE = &H2000
Const BOLD_FONTTYPE = &H100
Const ITALIC_FONTTYPE = &H200
Const REGULAR_FONTTYPE = &H400

Const WM_CHOOSEFONT_GETLOGFONT = (WM_USER + 1)
Const WM_CHOOSEFONT_SETLOGFONT = (WM_USER + 101)
Const WM_CHOOSEFONT_SETFLAGS = (WM_USER + 102)

Const LBSELCHSTRING = "commdlg_LBSelChangedNotify"
Const SHAREVISTRING = "commdlg_ShareViolation"
Const FILEOKSTRING = "commdlg_FileNameOK"
Const COLOROKSTRING = "commdlg_ColorOK"
Const SETRGBSTRING = "commdlg_SetRGBColor"
Const HELPMSGSTRING = "commdlg_help"
Const FINDMSGSTRING = "commdlg_FindReplace"

Const CD_LBSELNOITEMS = -1
Const CD_LBSELCHANGE = 0
Const CD_LBSELSUB = 1
Const CD_LBSELADD = 2

Type PrintDlg
        lStructSize As Long
        hwndOwner As Long
        hDevMode As Long
        hDevNames As Long
        hdc As Long
        Flags As Long
        nFromPage As Integer
        nToPage As Integer
        nMinPage As Integer
        nMaxPage As Integer
        nCopies As Integer
        hInstance As Long
        lCustData As Long
        lpfnPrintHook As Long
        lpfnSetupHook As Long
        lpPrintTemplateName As String
        lpSetupTemplateName As String
        hPrintTemplate As Long
        hSetupTemplate As Long
End Type

Declare Function PrintDlg Lib "comdlg32.dll" Alias "PrintDlgA" (pPrintdlg As PrintDlg) As Long

Const PD_ALLPAGES = &H0
Const PD_SELECTION = &H1
Const PD_PAGENUMS = &H2
Const PD_NOSELECTION = &H4
Const PD_NOPAGENUMS = &H8
Const PD_COLLATE = &H10
Const PD_PRINTTOFILE = &H20
Const PD_PRINTSETUP = &H40
Const PD_NOWARNING = &H80
Const PD_RETURNDC = &H100
Const PD_RETURNIC = &H200
Const PD_RETURNDEFAULT = &H400
Const PD_SHOWHELP = &H800
Const PD_ENABLEPRINTHOOK = &H1000
Const PD_ENABLESETUPHOOK = &H2000
Const PD_ENABLEPRINTTEMPLATE = &H4000
Const PD_ENABLESETUPTEMPLATE = &H8000
Const PD_ENABLEPRINTTEMPLATEHANDLE = &H10000
Const PD_ENABLESETUPTEMPLATEHANDLE = &H20000
Const PD_USEDEVMODECOPIES = &H40000
Const PD_USEDEVMODECOPIESANDCOLLATE = &H40000
Const PD_DISABLEPRINTTOFILE = &H80000
Const PD_HIDEPRINTTOFILE = &H100000
Const PD_NONETWORKBUTTON = &H200000

Type DEVNAMES
        wDriverOffset As Integer
        wDeviceOffset As Integer
        wOutputOffset As Integer
        wDefault As Integer
End Type

Const DN_DEFAULTPRN = &H1

Declare Function CommDlgExtendedError Lib "comdlg32.dll" () As Long

Const WM_PSD_PAGESETUPDLG = (WM_USER)
Const WM_PSD_FULLPAGERECT = (WM_USER + 1)
Const WM_PSD_MINMARGINRECT = (WM_USER + 2)
Const WM_PSD_MARGINRECT = (WM_USER + 3)
Const WM_PSD_GREEKTEXTRECT = (WM_USER + 4)
Const WM_PSD_ENVSTAMPRECT = (WM_USER + 5)
Const WM_PSD_YAFULLPAGERECT = (WM_USER + 6)

Type PageSetupDlg
        lStructSize As Long
        hwndOwner As Long
        hDevMode As Long
        hDevNames As Long
        Flags As Long
        ptPaperSize As POINTAPI
        rtMinMargin As RECT
        rtMargin As RECT
        hInstance As Long
        lCustData As Long
        lpfnPageSetupHook As Long
        lpfnPagePaintHook As Long
        lpPageSetupTemplateName As String
        hPageSetupTemplate As Long
End Type

Declare Function PageSetupDlg Lib "comdlg32.dll" Alias "PageSetupDlgA" (pPagesetupdlg As PageSetupDlg) As Long

Const PSD_DEFAULTMINMARGINS = &H0 '  default (printer's)
Const PSD_INWININIINTLMEASURE = &H0 '  1st of 4 possible

Const PSD_MINMARGINS = &H1 '  use caller's
Const PSD_MARGINS = &H2 '  use caller's
Const PSD_INTHOUSANDTHSOFINCHES = &H4 '  2nd of 4 possible
Const PSD_INHUNDREDTHSOFMILLIMETERS = &H8 '  3rd of 4 possible
Const PSD_DISABLEMARGINS = &H10
Const PSD_DISABLEPRINTER = &H20
Const PSD_NOWARNING = &H80 '  must be same as PD_*
Const PSD_DISABLEORIENTATION = &H100
Const PSD_RETURNDEFAULT = &H400 '  must be same as PD_*
Const PSD_DISABLEPAPER = &H200
Const PSD_SHOWHELP = &H800 '  must be same as PD_*
Const PSD_ENABLEPAGESETUPHOOK = &H2000 '  must be same as PD_*
Const PSD_ENABLEPAGESETUPTEMPLATE = &H8000 '  must be same as PD_*
Const PSD_ENABLEPAGESETUPTEMPLATEHANDLE = &H20000 '  must be same as PD_*
Const PSD_ENABLEPAGEPAINTHOOK = &H40000
Const PSD_DISABLEPAGEPAINTING = &H80000

Public Function getfile333()
        Dim ofn As OPENFILENAME

        Dim fn(0 To 511) As Byte
        Dim fnt As String * 512
        Dim r As Long
        ofn.lStructSize = Len(ofn)
        ofn.strTitle = "open file"

        ofn.lpstrFile = StrPtr(fn)
        ofn.nMaxFile = 512
        ofn.lpstrFileTitle = StrPtr(fnt)
        ofn.nMaxFileTitle = 512

        r = GetOpenFileName(ofn)
        MsgBox fn
        'getfile = fn
End Function

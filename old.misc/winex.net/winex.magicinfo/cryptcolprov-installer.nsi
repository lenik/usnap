; !define DEBUG

; !include "MUI.nsh"
; !include "nsis-ioutil.nsh"

; Basic
    OutFile "cryptcolprov_installer.exe"

    XPStyle on

    Page license
    ; Page components
    Page instfiles

    UninstPage uninstConfirm
    UninstPage instfiles

; Languages
    ; First is default
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\SimpChinese.nlf"        ; 2052
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\English.nlf"            ; 1033
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\Dutch.nlf"              ; 1043
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\French.nlf"             ; 1036
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\German.nlf"             ; 1031
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\Korean.nlf"             ; 1042
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\Russian.nlf"            ; 1049
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\Spanish.nlf"            ; 1034
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\Swedish.nlf"            ; 1053
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\TradChinese.nlf"        ; 1028
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\Slovak.nlf"             ; 1052

    LicenseData "ReadMe.txt"

; Main parameters
    Name "cryptcolprov"
    Caption "cryptcolprov installer"

    InstallDir C:\Keling
    ; InstallDirRegKey

    ShowInstDetails show

; Sections

    Var KEY

    Section "system files"
        SetOutPath "$SYSDIR"
            ;File /nonfatal "$SYSDIR\MFC90U.DLL"
            ;File /nonfatal "$SYSDIR\MSVCR90.DLL"
            ;File /nonfatal "$SYSDIR\ATL90.DLL"
    SectionEnd

    Section "core program"
        SetOutPath "$SYSDIR"
            File /nonfatal "Release\winex.magicinfo.dll"

        RegDLL $SYSDIR\winex.magicinfo.dll

        StrCpy $KEY "ns\winex\winex.magicinfo\winex.magicinfo.FragmentsColumn"

        WriteRegStr HKCR "*\Shell\setfootmagic" "" "����Ϊ�ο�������"
        WriteRegStr HKCR "*\Shell\setfootmagic\Command" "" "rundll32 winex.magicinfo.dll,setFootMagic �� 6 $\"%1$\""
        WriteRegStr HKCR "*\Shell\setheadmagic" "" "����Ϊ���������"
        WriteRegStr HKCR "*\Shell\setheadmagic\Command" "" "rundll32 winex.magicinfo.dll,setHeadMagic �� 4 $\"%1$\""

        WriteRegDWORD   HKCU $KEY show_2        1
        WriteRegStr     HKCU $KEY footerLen     6
        WriteRegStr     HKCU $KEY title_2       ����
        WriteRegStr     HKCU $KEY magic_��      $$AABBCCDDEEFF
    SectionEnd

; Pre-declared functions
    ReserveFile "${NSISDIR}\Plugins\InstallOptions.dll"
    ; ReserveFile "datacfg.ini"

    Function .onInit
	Push ""
	Push ${LANG_SIMPCHINESE}
	Push "Simplified Chinese"
	Push A ; A means auto count languages
	       ; for the auto count to work the first empty push (Push "") must remain
	LangDLL::LangDialog "ѡ��װ����" "��ѡ��װ����ʹ�õ�����"

	Pop $LANGUAGE
	StrCmp $LANGUAGE "cancel" 0 +2
		Abort

        InitPluginsDir
            ; File /oname=$PLUGINSDIR\datacfg.ini datacfg.ini
    FunctionEnd

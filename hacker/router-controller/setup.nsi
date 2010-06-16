
; !define DEBUG

!include "Sections.nsh"
!include "nsis-ioutil.nsh"

; Basic

    Var InsPos
    Var InsDrive
    Var FH

    Set NAME="Roco"
    Set VER="1.0"
    Set NAMEVER "$(NAME)-$(VER)"

    OutFile "$(NAMEVER).exe"

    XPStyle on

    Page license
    Page components
    Page directory
    ; Page custom         config configValidate ": 参数设置"
    Page instfiles

    UninstPage uninstConfirm
    UninstPage instfiles

; Languages

    ; First is default
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\SimpChinese.nlf"        ; 2052
    LoadLanguageFile "${NSISDIR}\Contrib\Language files\English.nlf"            ; 1033

    LicenseLangString myLicenseData ${LANG_ENGLISH}     "GPL"
    LicenseLangString myLicenseData ${LANG_SIMPCHINESE} "GPL"

    LicenseData $(myLicenseData)

    LangString ROCO_TITLE   ${LANG_ENGLISH}     "Roco $(VER) (Router Controller)"
    LangString ROCO_TITLE   ${LANG_SIMPCHINESE} "Roco $(VER) (路由器控制程序)"
    LangString INSTALLER    ${LANG_ENGLISH}     "Installer"
    LangString INSTALLER    ${LANG_SIMPCHINESE} "安装程序"

; Main parameters

    Name $(ROCO_TITLE)
    Caption "$(ROCO_TITLE) $(INSTALLER)"

    InstallDir "$PROGRAMFILES\$(NAME)"
    ; InstallDirRegKey

    ShowInstDetails show

; Sections

!include "setup_ext.nsi"

    Section $(S_PROGRAM)
        SetOutPath "$INSTDIR"
        !system "build.bat"
        File /nonfatal /r "Program Files\Li Yuan\*"
    SectionEnd

    Section /o $(S_USEDIRT)
    SectionEnd

    Section $(S_SMICONS)
        SetOutPath "$INSTDIR\bin"
        CreateDirectory $SMPROGRAMS\$(NAME)
        CreateShortCut $SMPROGRAMS\$(NAME)\$(NAMEVER).lnk \
            "$INSTDIR\bin\net.bodz.cbl.Main.bat"
        CreateShortCut $SMPROGRAMS\\Uninstall-$(NAMEVER).lnk \
            "$INSTDIR\bin\net.bodz.cbl.Uninstall.exe"
    SectionEnd

    Section $(S_DESKICONS)
        SetOutPath "$INSTDIR\bin"
        CreateShortCut $DESKTOP\吊顶设计程序.lnk \
            "$INSTDIR\bin\net.bodz.cbl.Main.bat"
    SectionEnd

    ;Section "$Name卸载程序" UNI
    ;    WriteUninstaller $INSTDIR\bin\net.bodz.cbl.Uninstall.exe
    ;SectionEnd

; Pre-declared functions

    Function .onInit
	Push ""
	Push ${LANG_SIMPCHINESE}
	Push "简体中文"
	Push A ; A means auto count languages
	       ; for the auto count to work the first empty push (Push "") must remain
	LangDLL::LangDialog "选择安装语言" "请选择安装程序使用的语言"

	Pop $LANGUAGE
	StrCmp $LANGUAGE "cancel" 0 +2
		Abort

        InitPluginsDir

     FindJava_Begin:
        StrCmp $%JAVA_HOME% "" NoSysJava
        IfFileExists $%JAVA_HOME%\jre\bin\javaw.exe HaveJava

      NoSysJava:
        IfFileExists $INSTDIR\.cirkonstancoj\java\${JREVER}\bin\javaw.exe HaveJava

      NoJava:
        !insertmacro SelectSection ${JRE}
        Goto FindJava_End

      HaveJava:
        !insertmacro UnselectSection ${JRE}

     FindJava_End:

    FunctionEnd

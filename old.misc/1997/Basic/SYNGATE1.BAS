DEFINT A-Z

type CardHandleStruct
	HandleNumber AS integer
	ThandleNum AS integer
	CurrPtr AS long
	CurrRec AS long
	FreeSpace AS long
	TablePtr AS long
	TotRecs AS long
	TotImgs AS long
	Res1 AS long
	FFlags AS integer
	TmplAddr AS long
	Res2 AS integer
	TempFName AS string*74
END TYPE

TYPE LayoutCardDescStruct
	DDesc1 AS INTEGER
	DDesc2 AS INTEGER
	DDesc3 AS INTEGER
	DDesc4 AS INTEGER
	DDesc5 AS INTEGER
	DDesc6 AS INTEGER
	DDesc7 AS INTEGER
	DDesc8 AS INTEGER
	DDesc9 AS INTEGER
	DFName AS STRING*22
	DLblk1 AS INTEGER
	DLblk2 AS INTEGER
	DLblk3 AS INTEGER
	DLblk4 AS INTEGER
END TYPE

TYPE LayoutObjectStruct
	ObjectType AS STRING*1
	ObjectData1 AS INTEGER
	ObjectData2 AS INTEGER
	ObjectData3 AS INTEGER
	ObjectData4 AS INTEGER
	CardName AS STRING*16
END TYPE

TYPE LayoutCardHeaderStruct
	CFlags AS INTEGER
	CTot AS INTEGER
	CLen AS INTEGER
	CDOff AS INTEGER
	CTOff AS INTEGER
	CCOff AS INTEGER
	CardOrig AS INTEGER
	CDim AS INTEGER
	CardName AS STRING*16
END TYPE

TYPE LayoutCardUnknownStruct
	LayoutCardHeaderStruct AS LayoutCardHeaderStruct
	NullCond AS INTEGER
	TmplAddr AS LONG
END TYPE

TYPE LayoutCardPblockStruct
	PblockTopOff AS INTEGER
	PCOff AS INTEGER
	PEOF AS INTEGER
	PTot AS INTEGER
	PTLn AS INTEGER
	PCLn AS INTEGER
	PMax AS INTEGER
	Res AS INTEGER
END TYPE

TYPE LayoutListVarStruct
	LVTFlags AS INTEGER
	LVTSize AS INTEGER
	ListVarTypeOff AS LONG
END TYPE

DECLARE SUB alert.box.off ALIAS "alert_box_off" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB alert.box.on ALIAS "alert_box_on" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB beep.synergy ALIAS "beep_synergy"
DECLARE SUB blank.block ALIAS "blank_block" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB blank.pixel.block ALIAS "blank_pixel_block" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB clear.block ALIAS "clear_block" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB clear.pixel.block ALIAS "clear_pixel_block" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB clear.screen ALIAS "clear_screen"
DECLARE SUB close.process ALIAS "close_process"
DECLARE SUB close.window ALIAS "close_window" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB color.block ALIAS "color_block" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%, BYVAL e%)
DECLARE SUB color.pixel.block ALIAS "color_pixel_block" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%, BYVAL e%)
DECLARE SUB dialog.box.off ALIAS "dialog_box_off" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB dialog.box.on ALIAS "dialog_box_on" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB draw.box ALIAS "draw_box" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB draw.ellipse ALIAS "draw_ellipse" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%, BYVAL e%)
DECLARE SUB draw.line ALIAS "draw_line" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB draw.string ALIAS "draw_string" (BYVAL a%, BYVAL b%, c$, d%, e%)
DECLARE SUB fill.block ALIAS "fill_block" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%, BYVAL e%, BYVAL f%)
DECLARE SUB fill.desktop ALIAS "fill_desktop" (BYVAL a%)
DECLARE SUB get.graphics.color ALIAS "get_graphics_color" (a%)
DECLARE SUB initialize.mouse ALIAS "initialize_mouse"
DECLARE SUB initialize.screen ALIAS "initialize_screen" (BYVAL a%)
DECLARE SUB invert.block ALIAS "invert_block" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB name.window ALIAS "name_window" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%, e$, BYVAL f%)
DECLARE SUB open.process ALIAS "open_process"
DECLARE SUB open.window ALIAS "open_window" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB set.desktop ALIAS "set_desktop" (BYVAL a%, BYVAL b%, BYVAL c%)
DECLARE SUB set.font.buffer ALIAS "set_font_buffer" (BYVAL a%, BYVAL b%)
DECLARE SUB set.graphics.color ALIAS "set_graphics_color" (BYVAL a%)
DECLARE SUB set.kern.width ALIAS "set_kern_width" (BYVAL a%)
DECLARE SUB set.proportional.font ALIAS "set_proportional_font" (BYVAL a%)
DECLARE SUB set.refresh.buffer ALIAS "set_refresh_buffer" (BYVAL a%, BYVAL b%)
DECLARE SUB set.refresh.mode ALIAS "set_refresh_mode" (BYVAL a%)
DECLARE SUB setup.menu ALIAS "setup_menu" (SEG a$)
DECLARE SUB sound.synergy ALIAS "sound_synergy" (BYVAL a%, BYVAL b%)
DECLARE SUB time.box.off ALIAS "time_box_off" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB time.box.on ALIAS "time_box_on" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB wait.synergy ALIAS "wait_synergy"
DECLARE SUB write.text ALIAS "write_text" (BYVAL a%, BYVAL b, c$, BYVAL d%)
DECLARE SUB xor.block ALIAS "xor_block" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB xor.box ALIAS "xor_box" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB xor.line ALIAS "xor_line" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)
DECLARE SUB xor.pixel.block ALIAS "xor_pixel_block" (BYVAL a%, BYVAL b%, BYVAL c%, BYVAL d%)

DECLARE SUB Setup.Screen.Variables ALIAS "SETUP_SCREEN_VARIABLES" (SEG A)
DECLARE SUB Reset.Program ALIAS "RESET_PROGRAM"
DECLARE SUB Allocate.Refresh ALIAS "ALLOCATE_REFRESH" (byval A%, byval B%)
DECLARE SUB Deallocate.Refresh ALIAS "DEALLOCATE_REFRESH"
DECLARE SUB Allocate.Fixed.Buffer ALIAS "ALLOCATE_FIXED_BUFFER" (SEG A&, byval B%)
DECLARE FUNCTION Allocate.var.Buffer ALIAS "ALLOCATE_VAR_BUFFER" (SEG A&, byval B%)
DECLARE SUB Get.Bit.Parameters ALIAS "GET_BIT_PARAMETERS" (byval A%, byval B%, byval C%, byval D%, byval E%, byval F%, byval G%)
DECLARE SUB Get.Byte.Parameters ALIAS "GET_BYTE_PARAMETERS" (byval A%, byval B%, byval C%, byval D%, byval E%, byval F%, byval G%)
DECLARE SUB Set.Relative.Origin ALIAS "SET_RELATIVE_ORIGIN" (byval A%, byval B%, byval C%, byval D%)
DECLARE SUB Reset.Relative.Origin ALIAS "RESET_RELATIVE_ORIGIN"
DECLARE SUB Get.General.Input ALIAS "GET_GENERAL_INPUT" (byval A%, byval BX, byval B, SEG C%, SEG D%, SEG E%, SEG F%, SEG G%)
DECLARE SUB Get.Menu.Input ALIAS "GET_MENU_INPUT" (byval A%, byval BX, byval B)
DECLARE SUB Get.Card.Input ALIAS "GET_CARD_INPUT" (byval A%, byval B%, byval C%, byval DX, byval D, byval EX, byval E, byval FX, byval F)
DECLARE SUB Do.Clear.Card ALIAS "DO_CLEAR_CARD" (byval AX, byval A)
DECLARE SUB Do.Display.Card ALIAS "DO_DISPLAY_CARD" (byval AX, byval A, byval b%, byval CX, byval C)
DECLARE SUB Do.Print.Card ALIAS "DO_PRINT_CARD" (byval AX, byval A)
DECLARE SUB Do.Print.Text ALIAS "DO_PRINT_TEXT" (SEG A$, byval B%)
DECLARE SUB Print.Variable ALIAS "PRINT_VARIABLE" (SEG A AS ANY, byval B%, byval C%)
DECLARE SUB Print.Crlf ALIAS "PRINT_CRLF"
DECLARE SUB Print.Page ALIAS "PRINT_PAGE"
DECLARE SUB Display.Variable ALIAS "DISPLAY_VARIABLE" (SEG A AS ANY, byval B%, byval C%, byval D%, byval E%)
DECLARE SUB Open.Card.File ALIAS "OPEN_CARD_FILE" (byval A%, byval BX, byval B, SEG C$, byval DX, byval D, SEG E$)
DECLARE SUB Close.Card.File ALIAS "CLOSE_CARD_FILE" (byval AX, byval A, SEG B$)
DECLARE SUB Move.File.Ptr ALIAS "MOVE_FILE_PTR" (byval A&, SEG B&, byval CX, byval C, BYVAL D%)
DECLARE SUB Goto.CardFile.ID ALIAS "GOTO_CARDFILE_ID" (SEG A#, SEG B&, byval CX, byval C, BYVAL D%)
DECLARE SUB Add.Card ALIAS "ADD_CARD" (byval AX, byval A, SEG B$)
DECLARE SUB Replace.Card ALIAS "REPLACE_CARD" (byval AX, byval A, SEG B$)
DECLARE SUB Delete.Card ALIAS "DELETE_CARD" (byval AX, byval A, SEG B$)
DECLARE SUB Get.Current.Card ALIAS "GET_CURRENT_CARD" (byval AX, byval A, SEG B$)
DECLARE SUB Get.Card.ID ALIAS "GET_CARD_ID" (byval AX, byval A, SEG B#, SEG C$)
DECLARE SUB Display.Image ALIAS "DISPLAY_IMAGE" (byval A, byval B, byval C, byval D, byval EX, byval E)
DECLARE SUB Get.Cardfile.Info ALIAS "GET_CARDFILE_INFO" (byval AX, byval A, SEG B&, SEG C&)
DECLARE SUB Get.Chosen.Link ALIAS "GET_CHOSEN_LINK" (SEG A#, SEG B$)
DECLARE SUB Set.Card.Link ALIAS "SET_CARD_LINK" (byval AX, byval A, SEG B#, SEG C$)
DECLARE SUB Get.Card.Link ALIAS "GET_CARD_LINK" (byval AX, byval A, SEG B#, SEG C$)
DECLARE SUB Set.List.Size ALIAS "SET_LIST_SIZE" (byval AX, byval A, byval B%, byval C%, byval D%)
DECLARE SUB Get.Current.Item ALIAS "GET_CURRENT_ITEM" (byval AX, byval A, SEG B%, SEG C%)
DECLARE SUB Insert.List.Item ALIAS "INSERT_LIST_ITEM" (byval A%, byval BX, byval B)
DECLARE SUB Delete.List.Item ALIAS "DELETE_LIST_ITEM" (byval A%, byval BX, byval B)

DECLARE SUB Setup.Help ALIAS "SETUP_HELP" (SEG A$, SEG B AS ANY)
DECLARE SUB Do.Help.Box ALIAS "DO_HELP_BOX"
DECLARE SUB Set.Help.Page ALIAS "SET_HELP_PAGE" (BYVAL A)

DECLARE SUB Load.Run.BBX.Name ALIAS "LOAD_RUN_BBX_NAME" (SEG A%, SEG B$)

DECLARE FUNCTION SBFOpen ALIAS "SBF_OPEN" (A$)
DECLARE SUB SBFClose ALIAS "SBF_CLOSE"
DECLARE SUB SBF (byval AX, byval A, byval B%, byval c&)
DECLARE SUB SBFString ALIAS "SBF_STRING" (SEG A$, byval B%, byval c&)
DECLARE FUNCTION AsciizLength (SEG A$)
DECLARE FUNCTION GetCardSeg (A AS ANY)
DECLARE FUNCTION GetCardPtr (A AS ANY)
DECLARE SUB SetCardOrig ALIAS "SET_CARD_ORIG" (BYVAL AX, BYVAL A, BYVAL B)

DECLARE FUNCTION GetListDword& ALIAS "GET_LIST_DWORD" (SEG A AS ANY, BYVAL B)
DECLARE FUNCTION GetListInteger ALIAS "get_list_integer" (SEG A AS ANY, BYVAL B)
DECLARE FUNCTION GetListFloat# ALIAS "get_list_float" (SEG A AS ANY, BYVAL B)
DECLARE FUNCTION GetListString$ ALIAS "get_list_string" (SEG A AS ANY, BYVAL B)

DECLARE SUB SetListDword ALIAS "set_list_dword" (SEG A AS ANY, BYVAL B, BYVAL C&)
DECLARE SUB SetListInteger ALIAS "set_list_integer" (SEG A AS ANY, BYVAL B, BYVAL C)
DECLARE SUB SetListFloat ALIAS "set_list_float" (SEG A AS ANY, BYVAL B, BYVAL C#)
DECLARE SUB SetListString ALIAS "set_list_string" (SEG A AS ANY, BYVAL B, SEG C$)

DECLARE FUNCTION LGetListDword& ALIAS "GET_LIST_DWORD" (BYVAL A&, BYVAL B)
DECLARE FUNCTION LGetListInteger ALIAS "get_list_integer" (BYVAL A&, BYVAL B)
DECLARE FUNCTION LGetListFloat# ALIAS "get_list_float" (BYVAL A&, BYVAL B)
DECLARE FUNCTION LGetListString$ ALIAS "get_list_string" (BYVAL A&, BYVAL B)

DECLARE SUB LSetListDword ALIAS "set_list_dword" (BYVAL A&, BYVAL B, BYVAL C&)
DECLARE SUB LSetListInteger ALIAS "set_list_integer" (BYVAL A&, BYVAL B, BYVAL C)
DECLARE SUB LSetListFloat ALIAS "set_list_float" (BYVAL A&, BYVAL B, BYVAL C#)
DECLARE SUB LSetListString ALIAS "set_list_string" (BYVAL A&, BYVAL B, SEG C$)

COMMON SHARED /LayoutCommon/ MaximumScreenRows, MaximumScreenColumns, XResolution, YResolution, ColorsAvailable, ScreenPlanes, _
	DboxSrow, DboxScol, DboxErow, DboxEcol, DboxWidth, DboxHeight, SX1, SY1, SX2, SY2, _
	MenuFlag, DataMenuTitles, MaxMenuWidth, MaxMenuHeight, MenuOff, MenuSeg

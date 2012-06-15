DECLARE SUB endct ()
DECLARE SUB MNSJF ()
DECLARE SUB pause ()
DECLARE SUB d16 (char$, xx!, xy!, xc!)
SCREEN 9: CLS : DIM temp(656), temp1(1305): RANDOMIZE TIMER
CALL d16("让", 8, 16, INT(RND * 14) + 1)
CALL d16("你送", 8, 32, INT(RND * 14) + 1)
CALL d16("学你这", 8, 48, INT(RND * 14) + 1)
CALL d16("到一套希", 8, 64, INT(RND * 14) + 1)
CALL d16("更个系望", 8, 80, INT(RND * 14) + 1)
CALL d16("多轻统", 8, 96, INT(RND * 14) + 1)
CALL d16("知松", 8, 112, INT(RND * 14) + 1)
CALL d16("识", 8, 128, INT(RND * 14) + 1)
GET (0, 0)-(70, 144), temp1
CALL d16("欢迎使用鸿风教学系统  之  ＧＷＢＡＳＩＣ", 8, 0, INT(RND * 14) + 1)
GET (0, 0)-(324, 15), temp
CLS
FOR xx = 80 TO 0 STEP -16
FOR x = 0 TO xx STEP 2
    PUT (lastx, lastx), temp
    PUT (x, x), temp
    PUT (lastx, 176 - lastx), temp
    PUT (x, 176 - x), temp
    lastx = x
    IF x = xx THEN PUT (x, x), temp: PUT (x, 176 - x), temp
NEXT x, xx
FOR x = 0 TO 400 STEP 4
 PUT (lastx, 16), temp1
 PUT (x, 16), temp1
 lastx = x
NEXT x
CALL d16("制作：谢继雷", 450, 20, INT(RND * 14) + 1)
CALL d16("（修订版）", 560, 20, INT(RND * 14) + 1)
CALL d16("一九九六年九月三日", 450, 40, INT(RND * 14) + 1)
CALL d16("按任意键继续……", 450, 170, INT(RND * 14) + 1)
CALL pause
CLS
CALL d16("本人亲手签名：", 30, 0, INT(RND * 14) + 1)
PSET (65, 28), INT(RND * 14) + 1
LINE -(74, 40), INT(RND * 14) + 1
PSET (60, 55), INT(RND * 14) + 1
LINE -(79, 50), INT(RND * 14) + 1
LINE -(66, 89), INT(RND * 14) + 1
LINE -(81, 78), INT(RND * 14) + 1
PSET (99, 21), INT(RND * 14) + 1
LINE -(85, 37), INT(RND * 14) + 1
LINE -(85, 66), INT(RND * 14) + 1
PSET (85, 37), INT(RND * 14) + 1
LINE -(108, 37), INT(RND * 14) + 1
LINE -(108, 92), INT(RND * 14) + 1
LINE -(95, 87), INT(RND * 14) + 1
PSET (85, 46), INT(RND * 14) + 1
LINE -(108, 46), INT(RND * 14) + 1
PSET (85, 57), INT(RND * 14) + 1
LINE -(108, 63), INT(RND * 14) + 1
PSET (76, 71), INT(RND * 14) + 1
LINE -(113, 64), INT(RND * 14) + 1
PSET (103, 66), INT(RND * 14) + 1
LINE -(88, 90), INT(RND * 14) + 1
LINE -(76, 92), INT(RND * 14) + 1
PSET (114, 59), INT(RND * 14) + 1
LINE -(130, 57), INT(RND * 14) + 1
PSET (122, 26), INT(RND * 14) + 1
LINE -(122, 87), INT(RND * 14) + 1
LINE -(115, 80), INT(RND * 14) + 1
PSET (114, 72), INT(RND * 14) + 1
LINE -(118, 75), INT(RND * 14) + 1
PSET (145, 43), INT(RND * 14) + 1
LINE -(123, 64), INT(RND * 14) + 1
LINE -(139, 63), INT(RND * 14) + 1
LINE -(124, 83), INT(RND * 14) + 1
LINE -(137, 80), INT(RND * 14) + 1
PSET (119, 99), INT(RND * 14) + 1
LINE -(137, 87), INT(RND * 14) + 1
PSET (158, 50), INT(RND * 14) + 1
LINE -(178, 95), INT(RND * 14) + 1
PSET (188, 54), INT(RND * 14) + 1
LINE -(151, 91), INT(RND * 14) + 1
PSET (172, 51), INT(RND * 14) + 1
LINE -(164, 96), INT(RND * 14) + 1
PSET (153, 70), INT(RND * 14) + 1
LINE -(187, 76), INT(RND * 14) + 1
PSET (151, 47), INT(RND * 14) + 1
LINE -(142, 99), INT(RND * 14) + 1
LINE -(190, 106), INT(RND * 14) + 1
PSET (271, 52), INT(RND * 14) + 1
LINE -(312, 67), INT(RND * 14) + 1
PSET (256, 73), INT(RND * 14) + 1
LINE -(259, 59), INT(RND * 14) + 1
LINE -(322, 82), INT(RND * 14) + 1
LINE -(320, 96), INT(RND * 14) + 1
PSET (292, 59), INT(RND * 14) + 1
LINE -(286, 91), INT(RND * 14) + 1
PSET (268, 70), INT(RND * 14) + 1
LINE -(281, 75), INT(RND * 14) + 1
PSET (267, 76), INT(RND * 14) + 1
LINE -(280, 80), INT(RND * 14) + 1
PSET (298, 81), INT(RND * 14) + 1
LINE -(311, 86), INT(RND * 14) + 1
PSET (297, 87), INT(RND * 14) + 1
LINE -(310, 92), INT(RND * 14) + 1
PSET (270, 90), INT(RND * 14) + 1
LINE -(303, 103), INT(RND * 14) + 1
LINE -(300, 123), INT(RND * 14) + 1
LINE -(266, 110), INT(RND * 14) + 1
LINE -(270, 90), INT(RND * 14) + 1
PSET (302, 113), INT(RND * 14) + 1
LINE -(268, 100), INT(RND * 14) + 1
PSET (285, 96), INT(RND * 14) + 1
LINE -(282, 116), INT(RND * 14) + 1
CALL d16("按任意键继续……", 10, 170, 14)
CALL pause
start:
CLS
CALL d16("          鸿飞家教系列  之  ＧＷＢＡＳＩＣ", 8, 0, INT(RND * 14) + 1)
CALL d16("                      主菜单", 8, 32, INT(RND * 14) + 1)
CALL d16("          ⒈输入语句          ⒎字符函数调用", 8, 48, INT(RND * 14) + 1)
CALL d16("          ⒉输出语句          ⒏图形绘制", 8, 64, INT(RND * 14) + 1)
CALL d16("          ⒊循环语句          ⒐音乐编谱", 8, 80, INT(RND * 14) + 1)
CALL d16("          ⒋判断语句          ＡＤＯＳ调用", 8, 96, INT(RND * 14) + 1)
CALL d16("          ⒌数组操作          ＢＧＷＢＡＳＩＣ", 8, 112, INT(RND * 14) + 1)
CALL d16("          ⒍数字函数调用      Ｃ其它", 8, 128, INT(RND * 14) + 1)
CALL d16("                      Ｘ  退出", 8, 144, INT(RND * 14) + 1)
CALL d16("          请选择：", 8, 160, INT(RND * 14) + 1)
FOR x = 450 TO 600 STEP 5
LINE (x, 10)-(1050 - x, 190), INT(RND * 14) + 1
NEXT x
FOR x = 50 TO 140 STEP 5
LINE (450, x)-(600, 200 - x), INT(RND * 14) + 1
NEXT x
menu: k$ = INKEY$: IF k$ = "" THEN GOTO menu
count = 0
SELECT CASE k$
  CASE "1"
    SHELL "tlet"
  CASE "2"
    SHELL "tprint"
  CASE "3"
    CLS
    SHELL "tfor"
  CASE "4"
    CLS
    CALL d16("尚未完工，请在１２月左右来信寻问", 8, 112, INT(RND * 14) + 1)
    CALL pause
   'SHELL "tif"
  CASE "5"
    CLS
    CALL d16("尚未完工，请在１２月左右来信寻问", 8, 112, INT(RND * 14) + 1)
    CALL pause
    'SHELL "tdim"
  CASE "6"
    CLS
    CALL d16("尚未完工，请在１２月左右来信寻问", 8, 112, INT(RND * 14) + 1)
    CALL pause
    'SHELL "tnfn"
  CASE "7"
    CLS
    CALL d16("尚未完工，请在１２月左右来信寻问", 8, 112, INT(RND * 14) + 1)
    CALL pause
    'SHELL "tcfn"
  CASE "8"
    CLS
    CALL d16("尚未完工，请在１２月左右来信寻问", 8, 112, INT(RND * 14) + 1)
    CALL pause
    'SHELL "tdraw"
  CASE "9"
    SHELL "tplay"
  CASE "A", "a"
    CLS
    CALL d16("尚未完工，请在１２月左右来信寻问", 8, 112, INT(RND * 14) + 1)
    CALL pause
    'SHELL "tdos"
  CASE "B", "b"
    CLS
    CALL d16("尚未完工，请在１２月左右来信寻问", 8, 112, INT(RND * 14) + 1)
    CALL pause
   'SHELL "tgw"
  CASE "C", "c"
    CLS
    CALL d16("尚未完工，请在１２月左右来信寻问", 8, 112, INT(RND * 14) + 1)
    CALL pause
   'SHELL "tother"
  CASE "X", "x"
   CALL endct
    SHELL "type nul>Config.tgw"
    END
  CASE ELSE
    GOTO menu
END SELECT
    SHELL "type nul>Config.tgw"
GOTO start

SUB d16 (char$, xx, xy, xc)
a = 1
OPEN "hzk16" FOR RANDOM AS #1 LEN = 1
FIELD #1, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd16
r = (qm * 94 + wm) * 32 + 1
IF yq = 1 THEN xc = INT(RND * 14) + 1
FOR xs = 0 TO 15
GET #1, r: r = r + 1: LINE (xx + 7, xy + xs)-(xx - 8, xy + xs), xc, , ASC(f$)
GET #1, r: r = r + 1: LINE (xx + 15, xy + xs)-(xx, xy + xs), xc, , ASC(f$)
NEXT xs
endd16: xx = xx + 16
NEXT k
CLOSE #1
END SUB

SUB endct
CLS
CALL d16("    谢谢使用本系统！", 8, 0, INT(RND * 14) + 1)
CALL d16("    希望您会给本人一个答复。", 8, 16, 15)
CALL d16("        地址：浙江省玉环县楚门镇城东路１１号", 8, 48, INT(RND * 14) + 1)
CALL d16("        邮编：３１７６０５  电话：７４４４６５９", 8, 64, INT(RND * 14) + 1)
CALL d16("        联系人：谢继雷", 8, 80, INT(RND * 14) + 1)
CALL d16("    软件价格：单位：ＶＧＡ彩显：４０元  其它：４５元", 8, 96, INT(RND * 14) + 1)
CALL d16("              个人：ＶＧＡ彩显：２０元  其它：２５元", 8, 112, INT(RND * 14) + 1)
END SUB

SUB pause
MOMENT: IF INKEY$ = "" THEN GOTO MOMENT
END SUB

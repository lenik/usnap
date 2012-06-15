DECLARE SUB d16 (char$, xx!, xy!, xc!)
SCREEN 2: CLS
CALL d16("当帅系列软件", 8, 0, INT(RND * 14) + 1)
CALL d16("  本套软件共有四部分组成：", 8, 16, INT(RND * 14) + 1)
CALL d16("      ①说明程序（即本程序）", 8, 32, INT(RND * 14) + 1)
CALL d16("      ②字符动画一则", 8, 48, INT(RND * 14) + 1)
CALL d16("      ③鸿飞家教——ＧＷＢＡＳＩＣ", 8, 64, INT(RND * 14) + 1)
CALL d16("      ④新海龟作图Ｉ版", 8, 80, INT(RND * 14) + 1)
CALL d16("  操作说明：", 8, 96, INT(RND * 14) + 1)
CALL d16("      ①如果你想退出这个说明程序，请按＜Ｅｓｃ＞键", 8, 112, INT(RND * 14) + 1)
CALL d16("        （此键位于键盘左上角）", 8, 128, INT(RND * 14) + 1)
CALL d16("      ②退出字符动画，请安＜Ｅｓｃ＞键", 8, 144, INT(RND * 14) + 1)
CALL d16("      ③退出新海龟，请安ＱＵＩＴ", 8, 160, INT(RND * 14) + 1)
CALL d16("  制作：谢继雷  １９９６年１１月", 300, 176, INT(RND * 14) + 1)
3 K$ = INKEY$: IF K$ = "" THEN 3
IF K$ = CHR$(27) THEN END
GOTO 3
END

SUB d16 (char$, xx, xy, xc)
OPEN "hzk16" FOR RANDOM AS #1 LEN = 1
FIELD #1, 1 AS f$
FOR K = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, K, 1)) - 161
wm = ASC(MID$(char$, K + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd16
r = (qm * 94 + wm) * 32 + 1
FOR xs = 0 TO 15
GET #1, r: r = r + 1: LINE (xx + 7, xy + xs)-(xx - 8, xy + xs), xc, , ASC(f$)
GET #1, r: r = r + 1: LINE (xx + 15, xy + xs)-(xx, xy + xs), xc, , ASC(f$)
NEXT xs
endd16: xx = xx + 16
NEXT K
CLOSE #1
END SUB

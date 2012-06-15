DECLARE SUB tbasic ()
DECLARE SUB tline ()
DECLARE SUB MNSJF ()
DECLARE SUB pause ()
DECLARE SUB tlet ()
DECLARE SUB tread ()
DECLARE SUB tinput ()
DECLARE SUB d16 (char$, xx!, xy!, xc!)
RANDOMIZE TIMER
CLS
start:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("            （Ｃ）ＣＯＰＹＲＩＧＨＴ  １９９７，１９９８", 8, 16, INT(RND * 14) + 1)
CALL d16("                          第一章", 8, 48, INT(RND * 14) + 1)
CALL d16("                  ＧＷＢＡＳＩＣ－赋值语句", 8, 64, INT(RND * 14) + 1)
CALL d16("              主要内容：  ※１※  简介ＧＷＢＡＳＩＣ", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※２※  ＧＷＢＡＳＩＣ程序例行", 8, 112, INT(RND * 14) + 1)
CALL d16("                          ※３※  语句ＬＥＴ", 8, 128, INT(RND * 14) + 1)
CALL d16("                          ※４※  语句ＩＮＰＵＴ", 8, 144, INT(RND * 14) + 1)
CALL d16("                          ※５※  语句ＲＥＡＤ", 8, 160, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 176, INT(RND * 14) + 1)
CALL d16("请选择：", 420, 176, INT(RND * 14) + 1)
3 k$ = INKEY$: IF k$ = "" THEN 3
SELECT CASE k$
  CASE "1"
    CALL tbasic
  CASE "2"
    CALL tline
  CASE "3"
    CALL tlet
  CASE "4"
    CALL tinput
  CASE "5"
    CALL tread
  CASE "0"
    GOTO endstart
  CASE ELSE
    GOTO 3
END SELECT
GOTO start
endstart:
END

SUB d16 (char$, xx, xy, xc)
OPEN "hzk16" FOR RANDOM AS #1 LEN = 1
FIELD #1, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd16
r = (qm * 94 + wm) * 32 + 1
FOR xs = 0 TO 15
GET #1, r: r = r + 1: LINE (xx + 7, xy + xs)-(xx - 8, xy + xs), xc, , ASC(f$)
GET #1, r: r = r + 1: LINE (xx + 15, xy + xs)-(xx, xy + xs), xc, , ASC(f$)
NEXT xs
endd16: xx = xx + 16
NEXT k
CLOSE #1
END SUB

SUB MNSJF
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          模拟上机", 8, 16, INT(RND * 14) + 1)
LINE (20, 40)-(580, 150), INT(RND * 14) + 1, B
END SUB

SUB pause
MOMENT: IF INKEY$ = "" THEN GOTO MOMENT
END SUB

SUB tbasic
startsg:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第一章    第一节    什么是ＧＷＢＡＳＩＣ", 8, 32, INT(RND * 14) + 1)
CALL d16("        ＧＷＢＡＳＩＣ是一种ＢＡＳＩＣ语言，属于解释语言的一种，", 8, 64, INT(RND * 14) + 1)
CALL d16("    因为它的好学，而深受广大用户的喜爱，本软件的主要内容也是教", 8, 80, INT(RND * 14) + 1)
CALL d16("    大家ＢＡＳＩＣ语言。", 8, 96, INT(RND * 14) + 1)
CALL d16("        ＢＡＳＩＣ可以为大家做很多事，它不仅能用于工业统计，也", 8, 112, INT(RND * 14) + 1)
CALL d16("    可以用于自编一些简单的程序，甚至可以编写某些系统、游戏等软", 8, 128, INT(RND * 14) + 1)
CALL d16("    件，最主要的是因为ＢＡＳＩＣ语言的易编易用，所以有不少人都", 8, 144, INT(RND * 14) + 1)
CALL d16("    喜欢用ＢＡＳＩＣ语言编写程序。", 8, 160, INT(RND * 14) + 1)
CALL d16("        按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
END SUB

SUB tinput
DIM temp(10000)
startin:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第一章    第四节    ＩＮＰＵＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("                  主要内容：  １．ＩＮＰＵＴ的功能", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．ＩＮＰＵＴ的格式", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 112, INT(RND * 14) + 1)
4 k$ = INKEY$: IF k$ = "" THEN 4
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第一章    第四节    ＩＮＰＵＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("            ＩＮＰＵＴ是的功能是给一个变量输入数值，一般就叫做输", 8, 48, INT(RND * 14) + 1)
CALL d16("            入语句。它不仅可以输入数值，而且也可以输入字符，字符", 8, 64, INT(RND * 14) + 1)
CALL d16("            和数值统称数据。", 8, 80, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 96, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第一章    第四节    ＩＮＰＵＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("    ＩＮＰＵＴ语句的格式：", 8, 48, INT(RND * 14) + 1)
CALL d16("    ＜行号＞ＩＮＰＵＴ  “＜提示信息＞”｛，｜；｝", 8, 64, INT(RND * 14) + 1)
CALL d16("                          ＜变量＞［，＜变量＞］［，＜变量＞］……", 8, 80, INT(RND * 14) + 1)
CALL d16("    尖括号“｛｝”中的字符表示选择，只能选择一个（‘｜’表示分隔符）", 8, 96, INT(RND * 14) + 1)
CALL d16("    提示信息可以是不带双引号的任何字符，只能有一句。", 8, 112, INT(RND * 14) + 1)
CALL d16("    提示信息后如果加“；”的话将会在提示信息后加一个“？”。", 8, 128, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 150, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 144), 0, BF
CALL d16("    例行：", 8, 48, INT(RND * 14) + 1)
CALL d16("    １０  ＩＮＰＵＴ  “输入Ａ（带？号）”；Ａ", 8, 64, INT(RND * 14) + 1)
CALL d16("    ２０  ＩＮＰＵＴ  “输入Ａ（不带？号）”，Ａ", 8, 80, INT(RND * 14) + 1)
CALL d16("    ３０  ＩＮＰＵＴ  “输入姓名（字符型）”；ＮＡＭＥ￥", 8, 96, INT(RND * 14) + 1)
CALL d16("                                变量后加“￥”代表字符↑", 8, 112, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 150, INT(RND * 14) + 1)
CALL pause
LINE (0, 112)-(639, 144), 0, BF
CALL d16("    ４０  ＩＮＰＵＴ  “输入性别（字符型）”，ＳＥＧ￥", 8, 112, INT(RND * 14) + 1)
CALL d16("    ＲＵＮ  ＜回车＞    （ＲＵＮ是执行程序的命令）”；ＮＡＭＥ￥", 8, 128, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 150, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 145), temp
VIEW (0, 64)-(540, 145)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    输入Ａ（带？号）？", 8, 128, INT(RND * 14) + 1)
LOCATE 18, 24: INPUT "", a

GET (0, 64)-(540, 145), temp
VIEW (0, 64)-(540, 145)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    输入Ａ（不带？号）", 8, 128, INT(RND * 14) + 1)
LOCATE 18, 23: INPUT "", a

GET (0, 64)-(540, 145), temp
VIEW (0, 64)-(540, 145)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    输入姓名（字符型）？", 8, 128, INT(RND * 14) + 1)
LOCATE 18, 26: INPUT "", a$

GET (0, 64)-(540, 145), temp
VIEW (0, 64)-(540, 145)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    输入性别（字符型）", 8, 128, INT(RND * 14) + 1)
LOCATE 18, 23: INPUT "", a$
CASE "3"
CLS
CALL MNSJF
CALL d16("            现在请输入一条语句（行号４０），", 8, 48, INT(RND * 14) + 1)
CALL d16("            提示信息为“ＤＳ＝”（不带？），并输入ＤＳ", 8, 64, INT(RND * 14) + 1)
LOCATE 12, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "40input " + CHR$(34) + "ds=" + CHR$(34) + ",ds" THEN a = 1
IF test$ = "40 input " + CHR$(34) + "ds=" + CHR$(34) + ",ds" THEN a = 1
IF test$ = "40input " + CHR$(34) + "ds=" + CHR$(34) + ", ds" THEN a = 1
IF test$ = "40 input " + CHR$(34) + "ds=" + CHR$(34) + ",ds" THEN a = 1
IF test$ = "40input " + CHR$(34) + "ds=" + CHR$(34) + " ,ds" THEN a = 1
IF test$ = "40 input " + CHR$(34) + "ds=" + CHR$(34) + " ,ds" THEN a = 1
IF test$ = "40input" + CHR$(34) + "ds=" + CHR$(34) + ",ds" THEN a = 1
IF test$ = "40 input" + CHR$(34) + "ds=" + CHR$(34) + ",ds" THEN a = 1
IF test$ = "40input" + CHR$(34) + "ds=" + CHR$(34) + ", ds" THEN a = 1
IF test$ = "40 input" + CHR$(34) + "ds=" + CHR$(34) + ",ds" THEN a = 1
IF test$ = "40input" + CHR$(34) + "ds=" + CHR$(34) + " ,ds" THEN a = 1
IF test$ = "40 input" + CHR$(34) + "ds=" + CHR$(34) + " ,ds" THEN a = 1
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1) ELSE CALL d16("ＧＯＯＤ！好样的！", 8, 160, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endin
CASE ELSE
GOTO 4
END SELECT
GOTO startin
endin:
END SUB

SUB tlet
startpl:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第一章    第三节    ＬＥＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("                  主要内容：  １．ＬＥＴ的功能", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．ＬＥＴ的格式", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 112, INT(RND * 14) + 1)
6 k$ = INKEY$: IF k$ = "" THEN 6
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第一章    第三节    ＬＥＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("            ＬＥＴ是一个最简单的语句，也是一个最常用的语句，", 8, 48, INT(RND * 14) + 1)
CALL d16("            它的功能就是给一个变量赋值。", 8, 64, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第一章    第三节    ＬＥＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("    ＬＥＴ语句的格式：", 8, 48, INT(RND * 14) + 1)
CALL d16("    ＜行号＞［ＬＥＴ］＜变量＞＝＜表达式＞", 8, 64, INT(RND * 14) + 1)
CALL d16("    方括号“［］”中的字符表示可以省略", 8, 80, INT(RND * 14) + 1)
CALL d16("    表达式指的是一个算式，它可以包含变量。", 8, 96, INT(RND * 14) + 1)
CALL d16("    如，ＬＥＴ  ＡＢ＝２３的功能就是把２３赋给ＡＢ", 8, 112, INT(RND * 14) + 1)
CALL d16("    （在ＢＡＳＩＣ中，ＡＢ≠Ａ×Ｂ）", 8, 128, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 144, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS
CALL MNSJF
CALL d16("            现在请输入一条语句（行号１５０），把１１３赋给变量Ｓ", 8, 48, INT(RND * 14) + 1)
LOCATE 10, 5: INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ <> "150 s=113" AND test$ <> "150s=113" AND test$ <> "150 let s=113" AND test$ <> "150let s=113" THEN CALL d16("输入错误！", 8, 180, INT(RND * 14) + 1) ELSE CALL d16("真棒！", 8, 180, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 180, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endpl
CASE ELSE
GOTO 6
END SELECT
GOTO startpl
endpl:

END SUB

SUB tline
startsd:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第一章    第二节    程序例行", 8, 32, INT(RND * 14) + 1)
CALL d16("  １０    ＣＬＳ    ’清屏。ＣＬＳ的功能就是清屏。", 8, 64, INT(RND * 14) + 1)
CALL d16("  ↑行号  ↑清屏    ↑解释（“’”后面的语句不执行）", 8, 80, INT(RND * 14) + 1)
CALL d16("  按任意键继续……", 8, 96, INT(RND * 14) + 1)
CALL pause
LINE (0, 80)-(639, 112), 0, BF
CALL d16("  ２０    ＩＮＰＵＴ  “单价”，Ａ  ’输入Ａ（Ａ是变量，代表单价，", 8, 80, INT(RND * 14) + 1)
CALL d16("          ↑输入语句    ↑提示信息            引号里的内容是提示信息）", 8, 96, INT(RND * 14) + 1)
CALL d16("  按任意键继续……", 8, 112, INT(RND * 14) + 1)
CALL pause
LINE (0, 96)-(639, 144), 0, BF
CALL d16("  ３０    ＩＮＰＵＴ  “数量”，Ｂ  ’输入Ｂ（Ｂ也是变量，代表数量）", 8, 96, INT(RND * 14) + 1)
CALL d16("  按任意键继续……", 8, 112, INT(RND * 14) + 1)
CALL pause
LINE (0, 112)-(639, 144), 0, BF
CALL d16("  ４０    Ｃ＝Ａ＊Ｂ  ’Ｃ（代表金额）等于Ａ乘以Ｂ（Ｃ也是变量，“＊”是等号）", 8, 112, INT(RND * 14) + 1)
CALL d16("  按任意键继续……", 8, 128, INT(RND * 14) + 1)
CALL pause
LINE (0, 128)-(639, 144), 0, BF
CALL d16("  ５０    ＰＲＩＮＴ  “金额＝”；Ｃ  ’显示金额，引号里的文字只是显示，", 8, 128, INT(RND * 14) + 1)
CALL d16("                        ↑              而在引号外的字符做变量看，电脑会", 8, 144, INT(RND * 14) + 1)
CALL d16("                    显示内容            自动把变量的内容代进去的。", 8, 160, INT(RND * 14) + 1)
CALL d16("  按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
LINE (0, 144)-(639, 199), 0, BF
CALL d16("  ＲＵＮ  ＜回车＞      （执行程序）", 8, 144, INT(RND * 14) + 1)
CALL d16("  按任意键继续……", 8, 160, INT(RND * 14) + 1)
CALL pause
LINE (0, 64)-(639, 199), 0, BF
CALL d16("  单价＝", 8, 64, INT(RND * 14) + 1)
LOCATE 10, 10: INPUT "", a
CALL d16("  数量＝", 8, 80, INT(RND * 14) + 1)
LOCATE 12, 10: INPUT "", b
c = a * b
CALL d16("  金额＝", 8, 96, INT(RND * 14) + 1)
LOCATE 14, 10: PRINT c
CALL d16("  按任意键继续……", 8, 112, INT(RND * 14) + 1)
CALL pause
LINE (0, 112)-(639, 128), 0, BF
CALL d16("  怎么样？有意思么？", 8, 112, INT(RND * 14) + 1)
CALL d16("  按任意键继续……", 8, 128, INT(RND * 14) + 1)
CALL pause
END SUB

SUB tread
DIM temp(10000)
startre:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第一章    第五节    ＲＥＡＤ", 8, 32, INT(RND * 14) + 1)
CALL d16("                  主要内容：  １．ＲＥＡＤ的功能", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．ＲＥＡＤ的格式", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 112, INT(RND * 14) + 1)
8 k$ = INKEY$: IF k$ = "" THEN 8
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第一章    第五节    ＲＥＡＤ", 8, 32, INT(RND * 14) + 1)
CALL d16("            ＲＥＡＤ的功能是给多个变量赋值，它的好处就是一次", 8, 48, INT(RND * 14) + 1)
CALL d16("            赋给很多变量。", 8, 64, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第一章    第五节    ＲＥＡＤ", 8, 32, INT(RND * 14) + 1)
CALL d16("    ＲＥＡＤ语句的格式：", 8, 48, INT(RND * 14) + 1)
CALL d16("    ＜行号＞ＲＥＡＤ  ＜变量＞［，＜变量＞］［，＜变量＞］……", 8, 64, INT(RND * 14) + 1)
CALL d16("    ……", 8, 80, INT(RND * 14) + 1)
CALL d16("    ＜行号＞ＤＡＴＡ  数据", 8, 96, INT(RND * 14) + 1)
CALL d16("    各个数据之间用“，”隔开，字符要用双引号。", 8, 112, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 144, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 144), 0, BF
CALL d16("    例行：", 8, 48, INT(RND * 14) + 1)
CALL d16("    １０  ＲＥＡＤ  ＸＨ１，ＮＡＭＥ１￥，ＳＥＧ１￥，", 8, 64, INT(RND * 14) + 1)
CALL d16("          ＸＨ２，ＮＡＭＥ２￥，ＳＥＧ２￥", 8, 80, INT(RND * 14) + 1)
CALL d16("    ２０  ＰＲＩＮＴ  “学号：”；ＸＨ１，“姓名：”；", 8, 96, INT(RND * 14) + 1)
CALL d16("          ＮＡＭＥ１￥，“性别：”；ＳＥＧ１￥", 8, 112, INT(RND * 14) + 1)
CALL d16("          ＰＲＩＮＴ是显示语句。具体内容见下章。", 8, 128, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 144, INT(RND * 14) + 1)
CALL pause
LINE (0, 128)-(639, 160), 0, BF
CALL d16("    ３０  ＰＲＩＮＴ  “学号：”；ＸＨ２，“姓名：”；", 8, 128, INT(RND * 14) + 1)
CALL d16("          ＮＡＭＥ２￥，“性别：”；ＳＥＧ２￥", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 160, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 176), 0, BF
CALL d16("    ４０  ＤＡＴＡ  ２６，“高丹雅”", 8, 48, INT(RND * 14) + 1)
CALL d16("    ５０  ＤＡＴＡ  “女”，１７，“黄凌峰”，“男”", 8, 64, INT(RND * 14) + 1)
CALL d16("    ＲＵＮ  ＜回车＞    （ＲＵＮ是执行程序的命令）”；ＮＡＭＥ￥", 8, 80, INT(RND * 14) + 1)
CALL d16("    学号：２６      姓名：高丹雅    性别：女", 8, 96, INT(RND * 14) + 1)
CALL d16("    学号：１７      姓名：黄凌峰    性别：男", 8, 112, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 128, INT(RND * 14) + 1)
CALL pause
LINE (0, 128)-(639, 144), 0, BF
CALL d16("    从上述例子中我们看到：ＤＡＴＡ语句不管放哪里都行，只要安顺序排", 8, 128, INT(RND * 14) + 1)
CALL d16("    列，不管它是在一行还是两行。", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 160, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS
CALL MNSJF
CALL d16("            现在请输入一段程序（行号１０起，十位递增）", 8, 48, INT(RND * 14) + 1)
CALL d16("            把１３、６６５、“ＸＸ”分别赋给Ａ、Ｂ、Ｃ", 8, 64, INT(RND * 14) + 1)
LOCATE 12, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0: score = 100
IF test$ = "10read a,b,c" THEN a = 1
IF test$ = "10 read a,b,c" THEN a = 1
IF test$ = "10read a ,b ,c" THEN a = 1
IF test$ = "10 read a ,b ,c" THEN a = 1
IF test$ = "10read a, b, c" THEN a = 1
IF test$ = "10 read a, b, c" THEN a = 1
IF test$ = "10read a , b , c" THEN a = 1
IF test$ = "10 read a , b , c" THEN a = 1
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 33:     ELSE CALL d16("输入真确！", 8, 160, INT(RND * 14) + 1)
LOCATE 13, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "20data 13,665," + CHR$(34) + "xx" + CHR$(34) THEN a = 1
IF test$ = "20 data 13,665," + CHR$(34) + "xx" + CHR$(34) THEN a = 1
IF test$ = "20data 13 ,665 ," + CHR$(34) + "xx" + CHR$(34) THEN a = 1
IF test$ = "20 data 13 ,665 ," + CHR$(34) + "xx" + CHR$(34) THEN a = 1
IF test$ = "20data 13, 665," + CHR$(34) + "xx" + CHR$(34) THEN a = 1
IF test$ = "20 data 13, 665," + CHR$(34) + "xx" + CHR$(34) THEN a = 1
IF test$ = "20data 13 , 665 ," + CHR$(34) + "xx" + CHR$(34) THEN a = 1
IF test$ = "20 data 13 , 665 ," + CHR$(34) + "xx" + CHR$(34) THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 34:       ELSE CALL d16("输入真确！", 8, 160, INT(RND * 14) + 1)
CALL d16("输入程序结束语句：ＥＮＤ  格式：＜行号＞ＥＮＤ", 8, 176, INT(RND * 14) + 1)
LOCATE 14, 5: LINE INPUT "HongFei>", test$
LINE (0, 176)-(639, 192), 0, BF
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "30end" THEN a = 1
IF test$ = "30 end" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 33:      ELSE CALL d16("输入真确！", 8, 160, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
CLS
CALL MNSJF
CALL d16("            您的分数是：", 8, 48, INT(RND * 14) + 1)
LOCATE 8, 30: PRINT score
     SELECT CASE score
       CASE 100
         CALL d16("      Ｃｏｎｇｒａｔｕｌａｔｉｏｎ！祝您能够保持下去！", 8, 64, INT(RND * 14) + 1)
       CASE 66, 67
         CALL d16("      好！虽然您没有多得胜利，但还不错！", 8, 64, INT(RND * 14) + 1)
       CASE 33, 34
         CALL d16("      祝您再接再厉！", 8, 64, INT(RND * 14) + 1)
       CASE 0
         CALL d16("      加油！一次失败算不了什么！", 8, 64, INT(RND * 14) + 1)
     END SELECT
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endre
CASE ELSE
GOTO 8
END SELECT
GOTO startre
endre:
END SUB

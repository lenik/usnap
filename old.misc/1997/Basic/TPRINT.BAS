DECLARE SUB tzfi ()
DECLARE SUB tchr ()
DECLARE SUB tasc ()
DECLARE SUB tlen ()
DECLARE SUB tinkey ()
DECLARE SUB tprint ()
DECLARE SUB ttab ()
DECLARE SUB tlocate ()
DECLARE SUB tfn1 ()
DECLARE SUB d16 (char$, xx!, xy!, xc!)
DECLARE SUB pause ()
DECLARE SUB mnsjf ()
RANDOMIZE TIMER
start:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("            （Ｃ）ＣＯＰＹＲＩＧＨＴ  １９９７，１９９８", 8, 16, INT(RND * 14) + 1)
CALL d16("                          第二章", 8, 48, INT(RND * 14) + 1)
CALL d16("                  ＧＷＢＡＳＩＣ－显示语句", 8, 64, INT(RND * 14) + 1)
CALL d16("              主要内容：  ※１※  ＰＲＩＮＴ", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※２※  ＴＡＢ", 8, 112, INT(RND * 14) + 1)
CALL d16("                          ※３※  ＬＯＣＡＴＥ", 8, 128, INT(RND * 14) + 1)
CALL d16("                          ※４※  字符函数（一）", 8, 144, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 160, INT(RND * 14) + 1)
CALL d16("请选择：", 80, 176, INT(RND * 14) + 1)
3 k$ = INKEY$: IF k$ = "" THEN 3
SELECT CASE k$
  CASE "1"
    CALL tprint
  CASE "2"
    CALL ttab
  CASE "3"
    CALL tlocate
  CASE "4"
    CALL tfn1
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

SUB mnsjf
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          模拟上机", 8, 16, INT(RND * 14) + 1)
LINE (20, 40)-(580, 150), INT(RND * 14) + 1, B
END SUB

SUB pause
MOMENT: IF INKEY$ = "" THEN GOTO MOMENT
END SUB

SUB tasc
DIM temp(10000)
startasc:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＡＳＣ", 8, 32, INT(RND * 14) + 1)
CALL d16("                          ※１※  ＡＳＣ的功能？", 8, 64, INT(RND * 14) + 1)
CALL d16("                          ※２※  ＡＳＣ的格式？", 8, 80, INT(RND * 14) + 1)
CALL d16("                          ※３※  模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 112, INT(RND * 14) + 1)
CALL d16("请选择：", 80, 176, INT(RND * 14) + 1)
112 k$ = INKEY$: IF k$ = "" THEN 112
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＡＳＣ的功能", 8, 16, INT(RND * 14) + 1)
CALL d16("      ＡＳＣ的功能是把对应的字符转换成对应的ＡＳＣＩＩ值", 8, 48, INT(RND * 14) + 1)
CALL d16("  一般用于特殊字符和字符序列判别（如小写和大写的判别）。", 8, 64, INT(RND * 14) + 1)
CALL d16("      它的功能与ＣＨＲ￥函数相反。", 8, 80, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＡＳＣ的格式？", 8, 16, INT(RND * 14) + 1)
CALL d16("  ＡＳＣ的格式是：", 8, 48, INT(RND * 14) + 1)
CALL d16("      ＜数字变量＞＝ＡＳＣ（“＜字符＞”）", 8, 64, INT(RND * 14) + 1)
CALL d16("  如：Ｋ＝ＡＳＣ（“Ａ”）：ＰＲＩＮＴ  Ｋ", 8, 80, INT(RND * 14) + 1)
CALL d16("  将显示６５，因为“Ａ”（不等于“ａ”）的ＡＳＣＩＩ码是６５", 8, 96, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CALL d16("  １０  Ａ￥＝ＣＨＲ￥（１００）：ＰＲＩＮＴ  ＡＳＣ（Ａ￥）", 8, 112, INT(RND * 14) + 1)
CALL d16("  ２０  Ｂ＝ＡＳＣ（“！”）：ＰＲＩＮＴ  ＣＨＲ￥（Ｂ）", 8, 128, INT(RND * 14) + 1)
CALL d16("  ３０  ＥＮＤ", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  ＲＵＮ", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  １００", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  ！", 8, 144, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS : a = 0
CALL mnsjf
CALL d16("现在请输入一条语句（行号为２０），", 68, 48, INT(RND * 14) + 1)
CALL d16("在行１０列５显示“＃”的ＡＳＣＩＩ值", 68, 64, INT(RND * 14) + 1)
LOCATE 12, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "20locate 10,5:print" + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20 locate 10,5:print" + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20locate 10,5:print " + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20 locate 10,5:print " + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20locate 10 ,5:print" + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20 locate 10 ,5:print" + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20locate 10 ,5:print " + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20 locate 10 ,5:print " + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20locate 10, 5:print" + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20 locate 10, 5:print" + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20locate 10, 5:print " + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20 locate 10, 5:print " + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20locate 10 , 5:print" + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20 locate 10 , 5:print" + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20locate 10 , 5:print " + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF test$ = "20 locate 10 , 5:print " + CHR$(34) + "#" + CHR$(34) THEN a = 1
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("有进步！", 8, 160, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endasc
CASE ELSE
GOTO 112
END SELECT
GOTO startasc
endasc:
END SUB

SUB tchr
DIM temp(10000)
startchr:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＣＨＲ￥", 8, 32, INT(RND * 14) + 1)
CALL d16("                          ※１※  ＣＨＲ￥的功能？", 8, 64, INT(RND * 14) + 1)
CALL d16("                          ※２※  ＣＨＲ￥的格式？", 8, 80, INT(RND * 14) + 1)
CALL d16("                          ※３※  模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 112, INT(RND * 14) + 1)
CALL d16("请选择：", 80, 176, INT(RND * 14) + 1)
111 k$ = INKEY$: IF k$ = "" THEN 111
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＣＨＲ￥的功能", 8, 16, INT(RND * 14) + 1)
CALL d16("      ＣＨＲ￥的功能是把对应的ＡＳＣＩＩ值转换", 8, 48, INT(RND * 14) + 1)
CALL d16("  成字符。一般用于特殊字符。", 8, 64, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＣＨＲ￥的格式？", 8, 16, INT(RND * 14) + 1)
CALL d16("  ＣＨＲ￥的格式是：", 8, 48, INT(RND * 14) + 1)
CALL d16("      ＜字符变量＞＝ＣＨＲ￥（ＡＳＣＩＩ值）", 8, 64, INT(RND * 14) + 1)
CALL d16("  如：Ｋ￥＝ＣＨＲ￥（３３）：ＰＲＩＮＴ  Ｋ￥", 8, 80, INT(RND * 14) + 1)
CALL d16("  将显示“３”，因为３的ＡＳＣＩＩ码中的３３就是３。", 8, 96, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CALL d16("  １０  ＰＲＩＮＴ  “双引号”；ＣＨＲ￥（３４）", 8, 112, INT(RND * 14) + 1)
CALL d16("        ’双引号的ＡＳＣＩＩ码是３４", 8, 128, INT(RND * 14) + 1)
CALL pause
LINE (0, 128)-(639, 144), 0, BF
CALL d16("  ２０  ＰＲＩＮＴ  “除号：”；ＣＨＲ￥（２４６）", 8, 128, INT(RND * 14) + 1)
CALL d16("  ３０  ＥＮＤ", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  ＲＵＮ", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  双引号  “", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  除号：  ÷", 8, 144, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS : a = 0
CALL mnsjf
CALL d16("现在请输入一条语句（行号为１００），", 68, 48, INT(RND * 14) + 1)
CALL d16("在横坐标２０显示ＡＳＣＩＩ码的４４", 68, 64, INT(RND * 14) + 1)
LOCATE 12, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "100print tab(20);chr$(44)" THEN a = 1
IF test$ = "100 print tab(20);chr$(44)" THEN a = 1
IF test$ = "100print tab(20) chr$(44)" THEN a = 1
IF test$ = "100 print tab(20) chr$(44)" THEN a = 1
IF test$ = "100print tab(20); chr$(44)" THEN a = 1
IF test$ = "100 print tab(20); chr$(44)" THEN a = 1
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("高手！", 8, 160, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endchr
CASE ELSE
GOTO 111
END SELECT
GOTO startchr
endchr:
END SUB

SUB tfn1
starttf:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第二章    第四节    字符函数（一）", 8, 32, INT(RND * 14) + 1)
CALL d16("              主要内容：  ※１※  什么叫字符函数", 8, 64, INT(RND * 14) + 1)
CALL d16("                          ※２※  ＣＨＲ￥", 8, 80, INT(RND * 14) + 1)
CALL d16("                          ※３※  ＡＳＣ", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※４※  ＬＥＮ", 8, 112, INT(RND * 14) + 1)
CALL d16("                          ※５※  ＩＮＫＥＹ￥", 8, 128, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 144, INT(RND * 14) + 1)
CALL d16("请选择：", 80, 176, INT(RND * 14) + 1)
10 k$ = INKEY$: IF k$ = "" THEN 10
SELECT CASE k$
  CASE "1"
    CALL tzfi
  CASE "2"
    CALL tchr
  CASE "3"
    CALL tasc
  CASE "4"
    CALL tlen
  CASE "5"
    CALL tinkey
  CASE "0"
    GOTO endtf
  CASE ELSE
    GOTO 10
END SELECT
GOTO starttf
endtf:
END SUB

SUB tinkey
DIM temp(10000)
startink:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＩＮＫＥＹ", 8, 32, INT(RND * 14) + 1)
CALL d16("                          ※１※  ＩＮＫＥＹ的功能？", 8, 64, INT(RND * 14) + 1)
CALL d16("                          ※２※  ＩＮＫＥＹ的格式？", 8, 80, INT(RND * 14) + 1)
CALL d16("                          ※３※  模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 112, INT(RND * 14) + 1)
CALL d16("请选择：", 80, 176, INT(RND * 14) + 1)
115 k$ = INKEY$: IF k$ = "" THEN 115
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＩＮＫＥＹ的功能", 8, 16, INT(RND * 14) + 1)
CALL d16("      ＩＮＫＥＹ的功能是从键盘上读入一个字符。", 8, 48, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＩＮＫＥＹ的格式？", 8, 16, INT(RND * 14) + 1)
CALL d16("  ＩＮＫＥＹ的格式是：", 8, 48, INT(RND * 14) + 1)
CALL d16("      １、＜字符变量＞＝ＩＮＫＥＹ￥", 8, 64, INT(RND * 14) + 1)
CALL d16("      ２、＜判断语句＞  ＩＮＫＥＹ￥＝＜字符表达式＞", 8, 80, INT(RND * 14) + 1)
CALL d16("  一般用的是第一种。", 8, 96, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CALL d16("  １０  Ｋ￥＝ＩＮＫＥＹ￥：ＩＦ  Ｋ￥＝“”  ＴＨＥＮ  １０", 8, 112, INT(RND * 14) + 1)
CALL d16("        ↑读取一个字符            ↑判断读取的字符是否为", 8, 128, INT(RND * 14) + 1)
CALL d16("                                    空字符", 8, 144, INT(RND * 14) + 1)
CALL pause
LINE (0, 128)-(639, 160), 0, BF
CALL d16("        可见，这是一个判断语句，它的功能是等待键盘输入，", 8, 128, INT(RND * 14) + 1)
CALL d16("        也就是说，它是一个斩停语句。", 8, 144, INT(RND * 14) + 1)
CALL pause
LINE (0, 128)-(639, 160), 0, BF
CALL d16("  ２０  ＩＦ  Ｋ￥＝ＣＨＲ￥（１３）  ＴＨＥＮ  ＰＲＩＮＴ  “敲的是回车键”", 8, 128, INT(RND * 14) + 1)
CALL d16("  ３０  ＩＦ  Ｋ￥＜＞ＣＨＲ￥（１３）  ＴＨＥＮ  ＰＲＩＮＴ  “敲的不回车键”", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(639, 161), temp
VIEW (0, 64)-(639, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  可见，这两句都是判断语句，头一句是说如果敲入的是回车键，", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(639, 161), temp
VIEW (0, 64)-(639, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  则显示“敲入的是回车键”，第二句是说如果敲入的不是回车键，", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(639, 161), temp
VIEW (0, 64)-(639, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  则显示“敲入的不是回车键”。", 8, 144, INT(RND * 14) + 1)
CALL pause
LINE (0, 112)-(639, 160), 0, BF
CALL d16("  ４０  ＥＮＤ", 8, 112, INT(RND * 14) + 1)
CALL d16("  ＲＵＮ", 8, 128, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(639, 161), temp
VIEW (0, 64)-(639, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  （输入一个字符）", 8, 128, INT(RND * 14) + 1)
f: k$ = INKEY$: IF k$ = "" THEN GOTO f
LINE (0, 144)-(639, 160), 0, BF
IF k$ = CHR$(13) THEN CALL d16("敲入的是回车键", 8, 144, INT(RND * 14) + 1) ELSE CALL d16("敲入的不是回车键", 8, 144, INT(RND * 14) + 1)
CALL pause

CASE "3"
CLS : a = 0
CALL mnsjf
CALL d16("现在请输入一条语句（行号为９０），", 68, 48, INT(RND * 14) + 1)
CALL d16("等待用户敲入一键", 68, 64, INT(RND * 14) + 1)
LOCATE 12, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "90if inkey$=" + CHR$(34) + CHR$(34) + " then 90" THEN a = 1
IF test$ = "90 if inkey$=" + CHR$(34) + CHR$(34) + " then 90" THEN a = 1
IF test$ = "90if inkey$=" + CHR$(34) + CHR$(34) + "then 90" THEN a = 1
IF test$ = "90 if inkey$=" + CHR$(34) + CHR$(34) + "then 90" THEN a = 1
IF test$ = "90if inkey$=" + CHR$(34) + CHR$(34) + " then90" THEN a = 1
IF test$ = "90 if inkey$=" + CHR$(34) + CHR$(34) + " then90" THEN a = 1
IF test$ = "90if inkey$=" + CHR$(34) + CHR$(34) + "then90" THEN a = 1
IF test$ = "90 if inkey$=" + CHR$(34) + CHR$(34) + "then90" THEN a = 1
IF test$ = "90k$=inkey$:if k$=" + CHR$(34) + CHR$(34) + " then 90" THEN a = 1
IF test$ = "90 k$=inkey$:if k$=" + CHR$(34) + CHR$(34) + " then 90" THEN a = 1
IF test$ = "90k$=inkey$:if k$=" + CHR$(34) + CHR$(34) + "then 90" THEN a = 1
IF test$ = "90 k$=inkey$:if k$=" + CHR$(34) + CHR$(34) + "then 90" THEN a = 1
IF test$ = "90k$=inkey$:if k$=" + CHR$(34) + CHR$(34) + " then90" THEN a = 1
IF test$ = "90 k$=inkey$:if k$=" + CHR$(34) + CHR$(34) + " then90" THEN a = 1
IF test$ = "90k$=inkey$:if k$=" + CHR$(34) + CHR$(34) + "then90" THEN a = 1
IF test$ = "90 k$=inkey$:if k$=" + CHR$(34) + CHR$(34) + "then90" THEN a = 1
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("天才！", 8, 160, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endink
CASE ELSE
GOTO 115
END SELECT
GOTO startink
endink:
END SUB

SUB tlen
DIM temp(15000)
startlen:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＬＥＮ", 8, 32, INT(RND * 14) + 1)
CALL d16("                          ※１※  ＬＥＮ的功能？", 8, 64, INT(RND * 14) + 1)
CALL d16("                          ※２※  ＬＥＮ的格式？", 8, 80, INT(RND * 14) + 1)
CALL d16("                          ※３※  模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 112, INT(RND * 14) + 1)
CALL d16("请选择：", 80, 176, INT(RND * 14) + 1)
113 k$ = INKEY$: IF k$ = "" THEN 113
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＬＥＮ的功能", 8, 16, INT(RND * 14) + 1)
CALL d16("      ＬＥＮ的功能是求字符串的长度。", 8, 48, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～ＬＥＮ的格式？", 8, 16, INT(RND * 14) + 1)
CALL d16("  ＬＥＮ的格式是：", 8, 48, INT(RND * 14) + 1)
CALL d16("      ＜数字变量＞＝ＬＥＮ（＜字符＞）", 8, 64, INT(RND * 14) + 1)
CALL d16("  如：Ｋ＝ＬＥＮ（“ＡＢＣＤＥ”）：ＰＲＩＮＴ  Ｋ", 8, 80, INT(RND * 14) + 1)
CALL d16("  将显示５，因为“ＡＢＣＤＥ”的长度是５", 8, 96, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CALL d16("  １０  Ａ￥＝“１２３４５”：Ｂ＝ＬＥＮ（Ａ￥）", 8, 112, INT(RND * 14) + 1)
CALL d16("  ２０  Ｃ￥＝“ＴＴ”＋Ａ￥：Ｄ＝ＬＥＮ（Ｃ￥）", 8, 128, INT(RND * 14) + 1)
CALL d16("        ’字符串相加是把几个字符串按所要求的顺序连接起来", 8, 144, INT(RND * 14) + 1)
CALL pause
LINE (0, 144)-(639, 160), 0, BF
CALL d16("  ３０  ＰＲＩＮＴ  Ａ￥＋“＝”；Ｂ", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  ４０  ＰＲＩＮＴ  Ｃ￥＋“＝”；Ｄ", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  ５０  ＥＮＤ", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  ＲＵＮ", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  １２３４５＝  ５", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("  ＴＴ１２３４５＝  ７", 8, 144, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS : a = 0: score = 100
CALL mnsjf
CALL d16("现在请输入一条语句（行号为１０起，十位递增），", 68, 48, INT(RND * 14) + 1)
CALL d16("（１）输入Ａ￥", 68, 64, INT(RND * 14) + 1)
LOCATE 12, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "10input a$" THEN a = 1
IF test$ = "10 input a$" THEN a = 1
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
a = 0
CALL d16("            按任意键继续……", 8, 176, INT(RND * 14) + 1)
LINE (60, 64)-(200, 80), 0, BF
CALL d16("（２）输入Ｂ￥", 68, 64, INT(RND * 14) + 1)
LOCATE 13, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "20input b$" THEN a = 1
IF test$ = "20 input b$" THEN a = 1
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
a = 0
CALL d16("            按任意键继续……", 8, 176, INT(RND * 14) + 1)
LINE (60, 64)-(200, 80), 0, BF
CALL d16("（３）把Ａ￥和Ｂ￥相加并赋给Ｃ￥", 68, 64, INT(RND * 14) + 1)
LOCATE 14, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "30c$=a$+b$" THEN a = 1
IF test$ = "30 c$=a$+b$" THEN a = 1
IF test$ = "30c$=b$+a$" THEN a = 1
IF test$ = "30 c$=b$+a$" THEN a = 1
IF test$ = "30c$ = a$ + b$" THEN a = 1
IF test$ = "30 c$ = a$ + b$" THEN a = 1
IF test$ = "30c$ = b$ + a$" THEN a = 1
IF test$ = "30 c$ = b$ + a$" THEN a = 1
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
a = 0
CALL d16("            按任意键继续……", 8, 176, INT(RND * 14) + 1)
LINE (60, 64)-(350, 80), 0, BF
CALL d16("（４）显示Ｃ￥的长度", 68, 64, INT(RND * 14) + 1)
LOCATE 15, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "40print len(c$)" THEN a = 1
IF test$ = "40 print len(c$)" THEN a = 1
IF test$ = "40print len (c$)" THEN a = 1
IF test$ = "40 print len (c$)" THEN a = 1
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
CLS
CALL mnsjf
CALL d16("            您的分数是：", 8, 48, INT(RND * 14) + 1)
LOCATE 8, 30: PRINT score
     SELECT CASE score
       CASE 100
         CALL d16("      Ｃｏｎｇｒａｔｕｌａｔｉｏｎ！祝您能够保持下去！", 8, 64, INT(RND * 14) + 1)
       CASE 75
         CALL d16("      好！虽然您没有夺得胜利，但还不错！", 8, 64, INT(RND * 14) + 1)
       CASE 50, 25
         CALL d16("      祝您再接再厉！", 8, 64, INT(RND * 14) + 1)
       CASE 0
         CALL d16("      加油！一次失败算不了什么！", 8, 64, INT(RND * 14) + 1)
     END SELECT
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endlen
CASE ELSE
GOTO 113
END SELECT
GOTO startlen
endlen:
END SUB

SUB tlocate
DIM temp(10000)
startl:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第二章    第三节    ＬＯＣＡＴＥ", 8, 32, INT(RND * 14) + 1)
CALL d16("                  主要内容：  １．ＬＯＣＡＴＥ的功能", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．ＬＯＣＡＴＥ的格式", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 112, INT(RND * 14) + 1)
8 k$ = INKEY$: IF k$ = "" THEN 8
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                      第二章    第三节    ＬＯＣＡＴＥ", 8, 32, INT(RND * 14) + 1)
CALL d16("            ＬＯＣＡＴＥ的功能是定义光标的坐标。", 8, 64, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 96, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                      第二章    第三节    ＬＯＣＡＴＥ", 8, 32, INT(RND * 14) + 1)
CALL d16("    ＬＯＣＡＴＥ语句的格式：", 8, 48, INT(RND * 14) + 1)
CALL d16("    ＜行号＞ＬＯＣＡＴＥ  ＜行数＞，＜列数＞", 8, 64, INT(RND * 14) + 1)
CALL d16("    这里的行和列只能用整数而且行列不能超出范围，否则将显示错误信息", 8, 80, INT(RND * 14) + 1)
CALL d16("    如：ＬＯＣＡＴＥ  ３，２：ＰＲＩＮＴ  “ＣＲＣ１  ＯＫ”", 8, 96, INT(RND * 14) + 1)
CALL d16("        ＬＯＣＡＴＥ  ４，３：ＰＲＩＮＴ  “ＣＲＣ２  ＯＫ”", 8, 112, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 160, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 176), 0, BF
CALL d16("      ＣＲＣ１  ＯＫ", 8, 80, INT(RND * 14) + 1)
CALL d16("        ＣＲＣ２  ＯＫ", 8, 96, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 160, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 176), 0, BF
CALL d16("    例行：", 8, 48, INT(RND * 14) + 1)
CALL d16("    １０  Ａ＝３：Ｂ＝１０：Ｃ＝７：Ｄ＝８", 8, 64, INT(RND * 14) + 1)
CALL d16("    ２０  ＬＯＣＡＴＥ  Ａ，Ｃ：ＰＲＩＮＴ  Ａ；“，”；Ｃ", 8, 80, INT(RND * 14) + 1)
CALL d16("    ３０  ＬＯＣＡＴＥ  Ｂ，Ｃ：ＰＲＩＮＴ  Ｂ；“，”；Ｃ", 8, 96, INT(RND * 14) + 1)
CALL d16("    ４０  ＬＯＣＡＴＥ  Ｃ，Ｄ：ＰＲＩＮＴ  Ｃ；“，”；Ｄ", 8, 112, INT(RND * 14) + 1)
CALL d16("    ５０  ＥＮＤ", 8, 128, INT(RND * 14) + 1)
CALL d16("    ＲＵＮ", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 180), 0, BF
CALL d16("    ３，７", 44, 112, INT(RND * 14) + 1)
CALL pause
CALL d16("    １０，７", 156, 112, INT(RND * 14) + 1)
CALL pause
CALL d16("    ７，８", 108, 128, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 176), 0, BF
CALL d16("    １０  ＣＬＳ    ’清屏", 8, 48, INT(RND * 14) + 1)
CALL d16("    ２０  ＲＥＡＤ  Ｘ，Ｙ", 8, 64, INT(RND * 14) + 1)
CALL d16("    ３０  ＬＯＣＡＴＥ  ６，４：ＩＮＰＵＴ  “Ａ＝”；Ａ", 8, 80, INT(RND * 14) + 1)
CALL d16("    ４０  ＬＯＣＡＴＥ  ７，４：ＩＮＰＵＴ  “Ｂ＝”；Ｂ", 8, 96, INT(RND * 14) + 1)
CALL d16("    ５０  ＬＯＣＡＴＥ  ８，４", 8, 112, INT(RND * 14) + 1)
CALL d16("    ６０  ＰＲＩＮＴ  “Ｘ＝      Ａ＝      Ｙ＝      Ｂ＝”", 8, 128, INT(RND * 14) + 1)
CALL d16("    ７０  ＰＲＩＮＴ    Ｘ，Ａ，Ｙ，Ｂ", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    ８０  ＤＡＴＡ  １２２，５５", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    ＲＵＮ", 8, 144, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 180), 0, BF
CALL d16("    Ａ＝？", 60, 80, INT(RND * 14) + 1)
LOCATE 12, 20: INPUT "", TEMPA
CALL d16("    Ｂ＝？", 60, 96, INT(RND * 14) + 1)
LOCATE 14, 20: INPUT "", TEMPB
CALL d16("    Ｘ＝      Ａ＝      Ｙ＝      Ｂ＝", 60, 112, INT(RND * 14) + 1)
LOCATE 17, 13: PRINT "225      "; TEMPA; : LOCATE 17, 33: PRINT "44      "; TEMPB
CALL pause
CASE "3"
CLS : score = 100: a = 0
CALL mnsjf
CALL d16("现在请输入一段语句（１０号开始是十位递增），", 68, 48, INT(RND * 14) + 1)
CALL d16("（１）在行１０，列２０输入Ａ", 68, 64, INT(RND * 14) + 1)
LOCATE 12, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "10locate 10,20:input a" THEN a = 1
IF test$ = "10 locate 10,20:input a" THEN a = 1
IF test$ = "10locate 10 ,20:input a" THEN a = 1
IF test$ = "10 locate 10 ,20:input a" THEN a = 1
IF test$ = "10locate 10, 20:input a" THEN a = 1
IF test$ = "10 locate 10, 20:input a" THEN a = 1
IF test$ = "10locate 10 , 20:input a" THEN a = 1
IF test$ = "10 locate 10 , 20:input a" THEN a = 1
IF test$ = "10locate 10,20:input " + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10 locate 10,20:input " + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10locate 10 ,20:input " + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10 locate 10 ,20:input " + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10locate 10, 20:input " + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10 locate 10, 20:input " + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10locate 10 , 20:input " + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10 locate 10 , 20:input " + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10locate 10,20:input " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10 locate 10,20:input " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10locate 10 ,20:input " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10 locate 10 ,20:input " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10locate 10, 20:input " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10 locate 10, 20:input " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10locate 10 , 20:input " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10 locate 10 , 20:input " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10locate 10,20:input" + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10 locate 10,20:input" + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10locate 10 ,20:input" + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10 locate 10 ,20:input" + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10locate 10, 20:input" + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10 locate 10, 20:input" + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10locate 10 , 20:input" + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10 locate 10 , 20:input" + CHR$(34) + "a=" + CHR$(34) + ",a" THEN a = 1
IF test$ = "10locate 10,20:input" + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10 locate 10,20:input" + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10locate 10 ,20:input" + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10 locate 10 ,20:input" + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10locate 10, 20:input" + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10 locate 10, 20:input" + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10locate 10 , 20:input" + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "10 locate 10 , 20:input" + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(400, 80), 0, BF
CALL d16("（２）在行１１，列２０处输入Ｂ", 68, 64, INT(RND * 14) + 1)
LOCATE 13, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "20locate 11,20:input b" THEN a = 1
IF test$ = "20 locate 11,20:input b" THEN a = 1
IF test$ = "20locate 11 ,20:input b" THEN a = 1
IF test$ = "20 locate 11 ,20:input b" THEN a = 1
IF test$ = "20locate 11, 20:input a" THEN a = 1
IF test$ = "20 locate 11, 20:input b" THEN a = 1
IF test$ = "20locate 11 , 20:input b" THEN a = 1
IF test$ = "20 locate 11 , 20:input b" THEN a = 1
IF test$ = "20locate 11,20:input " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20 locate 11,20:input " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20locate 11 ,20:input " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20 locate 11 ,20:input " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20locate 11, 20:input " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20 locate 11, 20:input " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20locate 11 , 20:input " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20 locate 11 , 20:input " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20locate 11,20:input " + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20 locate 11,20:input " + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20locate 11 ,20:input " + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20 locate 11 ,20:input " + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20locate 11, 20:input " + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20 locate 11, 20:input " + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20locate 11 , 20:input " + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20 locate 11 , 20:input " + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20locate 11,20:input" + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20 locate 11,20:input" + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20locate 11 ,20:input" + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20 locate 11 ,20:input" + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20locate 11, 20:input" + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20 locate 11, 20:input" + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20locate 11 , 20:input" + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20 locate 11 , 20:input" + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "20locate 11,20:input" + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20 locate 11,20:input" + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20locate 11 ,20:input" + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20 locate 11 ,20:input" + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20locate 11, 20:input" + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20 locate 11, 20:input" + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20locate 11 , 20:input" + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
IF test$ = "20 locate 11 , 20:input" + CHR$(34) + "b=" + CHR$(34) + ";b" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(400, 80), 0, BF
CALL d16("（３）在行１３，列２０显示“Ａ＝”并紧跟显示Ａ", 68, 64, INT(RND * 14) + 1)
LOCATE 14, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "30locate 13,20:print " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "30 locate 13,20:print " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "30locate 13,20:print " + CHR$(34) + "a= " + CHR$(34) + ";a" THEN a = 1
IF test$ = "30 locate 13,20:print " + CHR$(34) + "a= " + CHR$(34) + ";a" THEN a = 1
IF test$ = "30locate 13 ,20:print " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "30 locate 13 ,20:print " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "30locate 13 ,20:print " + CHR$(34) + "a= " + CHR$(34) + ";a" THEN a = 1
IF test$ = "30 locate 13 ,20:print " + CHR$(34) + "a= " + CHR$(34) + ";a" THEN a = 1
IF test$ = "30locate 13, 20:print " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "30 locate 13, 20:print " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "30locate 13, 20:print " + CHR$(34) + "a= " + CHR$(34) + ";a" THEN a = 1
IF test$ = "30 locate 13, 20:print " + CHR$(34) + "a= " + CHR$(34) + ";a" THEN a = 1
IF test$ = "30locate 13 , 20:print " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "30 locate 13 , 20:print " + CHR$(34) + "a=" + CHR$(34) + ";a" THEN a = 1
IF test$ = "30locate 13 , 20:print " + CHR$(34) + "a= " + CHR$(34) + ";a" THEN a = 1
IF test$ = "30 locate 13 , 20:print " + CHR$(34) + "a= " + CHR$(34) + ";a" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(420, 80), 0, BF
CALL d16("（４）在行１４，列２０显示“Ｂ＝”并制表显示Ｂ", 68, 64, INT(RND * 14) + 1)
LOCATE 15, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "40locate 14,20:print " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "40 locate 14,20:print " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "40locate 14,20:print " + CHR$(34) + "b= " + CHR$(34) + ",b" THEN a = 1
IF test$ = "40 locate 14,20:print " + CHR$(34) + "b= " + CHR$(34) + ",b" THEN a = 1
IF test$ = "40locate 14 ,20:print " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "40 locate 14 ,20:print " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "40locate 14 ,20:print " + CHR$(34) + "b= " + CHR$(34) + ",b" THEN a = 1
IF test$ = "40 locate 14 ,20:print " + CHR$(34) + "b= " + CHR$(34) + ",b" THEN a = 1
IF test$ = "40locate 14, 20:print " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "40 locate 14, 20:print " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "40locate 14, 20:print " + CHR$(34) + "b= " + CHR$(34) + ",b" THEN a = 1
IF test$ = "40 locate 14, 20:print " + CHR$(34) + "b= " + CHR$(34) + ",b" THEN a = 1
IF test$ = "40locate 14 , 20:print " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "40 locate 14 , 20:print " + CHR$(34) + "b=" + CHR$(34) + ",b" THEN a = 1
IF test$ = "40locate 14 , 20:print " + CHR$(34) + "b= " + CHR$(34) + ",b" THEN a = 1
IF test$ = "40 locate 14 , 20:print " + CHR$(34) + "b= " + CHR$(34) + ",b" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
CLS
CALL mnsjf
CALL d16("            您的分数是：", 8, 48, INT(RND * 14) + 1)
LOCATE 8, 30: PRINT score
     SELECT CASE score
       CASE 100
         CALL d16("      Ｃｏｎｇｒａｔｕｌａｔｉｏｎ！祝您能够保持下去！", 8, 64, INT(RND * 14) + 1)
       CASE 75
         CALL d16("      好！虽然您没有夺得胜利，但还不错！", 8, 64, INT(RND * 14) + 1)
       CASE 50, 25
         CALL d16("      祝您再接再厉！", 8, 64, INT(RND * 14) + 1)
       CASE 0
         CALL d16("      加油！一次失败算不了什么！", 8, 64, INT(RND * 14) + 1)
     END SELECT
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endl
CASE ELSE
GOTO 8
END SELECT
GOTO startl
endl:
END SUB

SUB tprint
DIM temp(10000)
startin:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第二章    第一节    ＰＲＩＮＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("                  主要内容：  １．ＰＲＩＮＴ的功能", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．ＰＲＩＮＴ的格式", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 112, INT(RND * 14) + 1)
4 k$ = INKEY$: IF k$ = "" THEN 4
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                      第二章    第一节    ＰＲＩＮＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("            ＰＲＩＮＴ的功能就是显示输出。它可以输出数字、字符。", 8, 48, INT(RND * 14) + 1)
CALL d16("            ＰＲＩＮＴ是ＢＡＳＩＣ中输出的基本功能。", 8, 64, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 96, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                      第二章    第一节    ＰＲＩＮＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("    ＰＲＩＮＴ语句的格式：", 8, 48, INT(RND * 14) + 1)
CALL d16("    ＜行号＞ＰＲＩＮＴ  ＜表达示＞［｛，｜；｝］……", 8, 64, INT(RND * 14) + 1)
CALL d16("    表达示可以多个，它可以是带双引号的字符，也可以是数字，如果是", 8, 80, INT(RND * 14) + 1)
CALL d16("    一个算式的话，就会输出计算结果。", 8, 96, INT(RND * 14) + 1)
CALL d16("    如：ＰＲＩＮＴ  “３＊２＝”；３＊２", 8, 112, INT(RND * 14) + 1)
CALL d16("    其中“３＊２＝”是显示的内容，“；”是紧跟输出，输出结果为：", 8, 128, INT(RND * 14) + 1)
CALL d16("    ３＊２＝６", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 160, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 176), 0, BF
CALL d16("    例行：", 8, 48, INT(RND * 14) + 1)
CALL d16("    １０  ＬＥＴ  Ａ＝１００  ’把１００赋给Ａ", 8, 64, INT(RND * 14) + 1)
CALL d16("    ２０  ＬＥＴ  Ｂ＝２００  ’把２００赋给Ｂ", 8, 80, INT(RND * 14) + 1)
CALL d16("    ３０  ＰＲＩＮＴ  “Ａ＊Ｂ”", 8, 96, INT(RND * 14) + 1)
CALL d16("    ４０  ＰＲＩＮＴ  Ａ＊Ｂ  ’显示表达式的值", 8, 112, INT(RND * 14) + 1)
CALL d16("    ５０  ＥＮＤ              ’结束程序", 8, 128, INT(RND * 14) + 1)
CALL d16("    ＲＵＮ  ＜回车＞    （ＲＵＮ是执行程序的命令）", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＊Ｂ", 8, 144, INT(RND * 14) + 1)
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    ２００００", 8, 144, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 176), 0, BF
CALL d16("    １０  Ａ＝１５５：Ｂ＝２＊Ａ：Ｃ＝Ａ＊Ｂ", 8, 48, INT(RND * 14) + 1)
CALL d16("          ’ＬＥＴ语句中ＬＥＴ可以省略，“：”是语句", 8, 64, INT(RND * 14) + 1)
CALL d16("            分隔符，即上述语句中一共有三个语句", 8, 80, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
LINE (0, 64)-(639, 96), 0, BF
CALL d16("    ２０  ＰＲＩＮＴ  Ａ，Ｂ，Ｂ    ’紧跟输出", 8, 64, INT(RND * 14) + 1)
CALL d16("    ３０  ＰＲＩＮＴ  Ａ；Ｂ；Ｃ    ’制表输出", 8, 80, INT(RND * 14) + 1)
CALL d16("    ４０  ＰＲＩＮＴ  Ａ：ＰＲＩＮＴ  Ｂ：ＰＲＩＮＴ  Ｃ", 8, 96, INT(RND * 14) + 1)
CALL d16("          ’隔行输出", 8, 112, INT(RND * 14) + 1)
CALL pause
LINE (0, 112)-(639, 128), 0, BF
CALL d16("    ５０  ＰＲＩＮＴ：ＰＲＩＮＴ  ’显示二空行", 8, 112, INT(RND * 14) + 1)
CALL d16("    ６０  ＥＮＤ", 8, 128, INT(RND * 14) + 1)
CALL d16("    ＲＵＮ", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    １５５        ３１０        ４８０５０", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    １５５  ３１０  ４８０５０", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    １５５", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    ３１０", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    ４８０５０", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL pause
CASE "3"
CLS : score = 100: a = 0
CALL mnsjf
CALL d16("现在请输入一段语句（１０号开始是十位递增），", 68, 48, INT(RND * 14) + 1)
CALL d16("计算：１０＊２＋１００—２０", 68, 64, INT(RND * 14) + 1)
LOCATE 12, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "10print10*2+100-20" THEN a = 1
IF test$ = "10 print10*2+100-20" THEN a = 1
IF test$ = "10print 10*2+100-20" THEN a = 1
IF test$ = "10 print 10*2+100-20" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(400, 80), 0, BF
CALL d16("计算：（２３＋４４—３２）＊２２２", 68, 64, INT(RND * 14) + 1)
LOCATE 13, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "20print(23+44-32)*222" THEN a = 1
IF test$ = "20 print(23+44-32)*222" THEN a = 1
IF test$ = "20print (23+44-32)*222" THEN a = 1
IF test$ = "20 print (23+44-32)*222" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(400, 80), 0, BF
CALL d16("显示“Ｉ’ｍ  Ａ  Ｓｔｕｄｅｎｔ”", 68, 64, INT(RND * 14) + 1)
LOCATE 14, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "30print" + CHR$(34) + "i'm a student" + CHR$(34) THEN a = 1
IF test$ = "30 print" + CHR$(34) + "i'm a student" + CHR$(34) THEN a = 1
IF test$ = "30print " + CHR$(34) + "i'm a student" + CHR$(34) THEN a = 1
IF test$ = "30 print " + CHR$(34) + "i'm a student" + CHR$(34) THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(400, 80), 0, BF
CALL d16("显示一空行", 68, 64, INT(RND * 14) + 1)
LOCATE 15, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "40print" THEN a = 1
IF test$ = "40 print" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
CLS
CALL mnsjf
CALL d16("            您的分数是：", 8, 48, INT(RND * 14) + 1)
LOCATE 8, 30: PRINT score
     SELECT CASE score
       CASE 100
         CALL d16("      Ｃｏｎｇｒａｔｕｌａｔｉｏｎ！祝您能够保持下去！", 8, 64, INT(RND * 14) + 1)
       CASE 75
         CALL d16("      好！虽然您没有夺得胜利，但还不错！", 8, 64, INT(RND * 14) + 1)
       CASE 50, 25
         CALL d16("      祝您再接再厉！", 8, 64, INT(RND * 14) + 1)
       CASE 0
         CALL d16("      加油！一次失败算不了什么！", 8, 64, INT(RND * 14) + 1)
     END SELECT
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endin
CASE ELSE
GOTO 4
END SELECT
GOTO startin
endin:
END SUB

SUB ttab
DIM temp(10000)
starti:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第二章    第二节    ＴＡＢ", 8, 32, INT(RND * 14) + 1)
CALL d16("                  主要内容：  １．ＴＡＢ的功能", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．ＴＡＢ的格式", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 112, INT(RND * 14) + 1)
5 k$ = INKEY$: IF k$ = "" THEN 5
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                      第二章    第二节    ＴＡＢ", 8, 32, INT(RND * 14) + 1)
CALL d16("            ＴＡＢ的功能是确定输出的初始横坐标。", 8, 64, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 96, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                      第二章    第二节    ＴＡＢ", 8, 32, INT(RND * 14) + 1)
CALL d16("    ＴＡＢ语句的格式：", 8, 48, INT(RND * 14) + 1)
CALL d16("    ＜行号＞  ＰＲＩＮＴ  ＴＡＢ（ｎ）；＜表达示＞［｛，｜；｝］……", 8, 64, INT(RND * 14) + 1)
CALL d16("    其中ｎ的值是任何整数，应为显示器的横坐标只能放８０个字符，", 8, 80, INT(RND * 14) + 1)
CALL d16("    所以真正的有效值只是２～７８。如果超过这个值就会换行。", 8, 96, INT(RND * 14) + 1)
CALL d16("    如：ＰＲＩＮＴ  ＴＡＢ（２０）；“ＯＫ！”", 8, 112, INT(RND * 14) + 1)
CALL d16("    输出结果为：", 8, 128, INT(RND * 14) + 1)
CALL d16("                  ＯＫ！", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 160, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 176), 0, BF
CALL d16("    例行：", 8, 48, INT(RND * 14) + 1)
CALL d16("    １０  ＰＲＩＮＴ  ＴＡＢ（１０）；“ＡＡ”", 8, 64, INT(RND * 14) + 1)
CALL d16("    ２０  ＰＲＩＮＴ  ＴＡＢ（２０）；“ＢＢ”", 8, 80, INT(RND * 14) + 1)
CALL d16("    ３０  ＰＲＩＮＴ  ＴＡＢ（３０）；“ＣＣ”", 8, 96, INT(RND * 14) + 1)
CALL d16("    ４０  ＰＲＩＮＴ  ＴＡＢ（４０）；“ＤＤ”", 8, 112, INT(RND * 14) + 1)
CALL d16("    ５０  ＥＮＤ", 8, 128, INT(RND * 14) + 1)
CALL d16("    ＲＵＮ  ＜回车＞    （ＲＵＮ是执行程序的命令）", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("                ＡＢ", 8, 144, INT(RND * 14) + 1)
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("                          ＢＢ", 8, 144, INT(RND * 14) + 1)
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("                                    ＣＣ", 8, 144, INT(RND * 14) + 1)
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("                                              ＤＤ", 8, 144, INT(RND * 14) + 1)
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL pause
CASE "3"
CLS : a = 0
CALL mnsjf
CALL d16("现在请输入一条语句（行号为５０），", 68, 48, INT(RND * 14) + 1)
CALL d16("在横坐标４０显示“Ｔｈａｎｋ  ｙｏｕ！”", 68, 64, INT(RND * 14) + 1)
LOCATE 12, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "50print tab(40);" + CHR$(34) + "thank you!" + CHR$(34) THEN a = 1
IF test$ = "50 print tab(40);" + CHR$(34) + "thank you!" + CHR$(34) THEN a = 1
IF test$ = "50print tab(40); " + CHR$(34) + "thank you!" + CHR$(34) THEN a = 1
IF test$ = "50 print tab(40); " + CHR$(34) + "thank you!" + CHR$(34) THEN a = 1
IF test$ = "50print tab(40)" + CHR$(34) + "thank you!" + CHR$(34) THEN a = 1
IF test$ = "50 print tab(40)" + CHR$(34) + "thank you!" + CHR$(34) THEN a = 1
IF test$ = "50print tab(40) " + CHR$(34) + "thank you!" + CHR$(34) THEN a = 1
IF test$ = "50 print tab(40) " + CHR$(34) + "thank you!" + CHR$(34) THEN a = 1
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 25 ELSE CALL d16("高明！", 8, 160, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endi
CASE ELSE
GOTO 5
END SELECT
GOTO starti
endi:
END SUB

SUB tzfi
startzfi:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～什么叫字符函数？", 8, 32, INT(RND * 14) + 1)
CALL d16("                          ※１※  什么叫字符函数？", 8, 64, INT(RND * 14) + 1)
CALL d16("                          ※２※  字符函数有哪些？", 8, 80, INT(RND * 14) + 1)
CALL d16("                          ※３※  字符函数有什么用？", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 112, INT(RND * 14) + 1)
CALL d16("请选择：", 80, 176, INT(RND * 14) + 1)
11 k$ = INKEY$: IF k$ = "" THEN 11
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～什么叫字符函数？", 8, 16, INT(RND * 14) + 1)
CALL d16("      所谓字符函数，就是对字符操作的某些语句，", 8, 48, INT(RND * 14) + 1)
CALL d16("  这种语句不能单独使用，只能放在某个语句的当中", 8, 64, INT(RND * 14) + 1)
CALL d16("  所以我们且管它叫字符函数。", 8, 80, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～字符函数有哪些？", 8, 16, INT(RND * 14) + 1)
CALL d16("  （１）用于字符与字符之间的字符函数，如ＬＴＲＩＭ￥", 8, 48, INT(RND * 14) + 1)
CALL d16("  （２）用于字符与数字之间的字符函数，如ＡＳＣ、ＬＥＮ", 8, 64, INT(RND * 14) + 1)
CALL d16("  （３）用于读取键盘状态的字符函数，如ＩＮＫＥＹ￥", 8, 80, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（一）～～～字符函数有什么作用？", 8, 16, INT(RND * 14) + 1)
CALL d16("  （１）利用字符函数可以进行字符与数据间的交换", 8, 48, INT(RND * 14) + 1)
CALL d16("  （２）利用字符函数可以显示一些特殊字符", 8, 64, INT(RND * 14) + 1)
CALL d16("  （３）利用字符函数可以方便输入（特别是ＩＮＫＥＹ￥函数）", 8, 80, INT(RND * 14) + 1)
CALL d16("  （４）利用字符函数可以简化判断", 8, 96, INT(RND * 14) + 1)
CALL d16("        ……", 8, 112, INT(RND * 14) + 1)
CALL d16("  总之，字符函数的作用很大。", 8, 128, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endzfi
CASE ELSE
GOTO 11
END SELECT
GOTO startzfi
endzfi:
END SUB

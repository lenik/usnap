DECLARE SUB tspace ()
DECLARE SUB tstr ()
DECLARE SUB tleft ()
DECLARE SUB tright ()
DECLARE SUB tmid ()
DECLARE SUB d16 (char$, xx!, xy!, xc!)
DECLARE SUB tfor ()
DECLARE SUB tdo ()
DECLARE SUB tfn2 ()
DECLARE SUB mnsjf ()
DECLARE SUB pause ()
RANDOMIZE TIMER
start:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("            （Ｃ）ＣＯＰＹＲＩＧＨＴ  １９９７，１９９８", 8, 16, INT(RND * 14) + 1)
CALL d16("                          第三章", 8, 48, INT(RND * 14) + 1)
CALL d16("                  ＧＷＢＡＳＩＣ－循环语句", 8, 64, INT(RND * 14) + 1)
CALL d16("              主要内容：  ※１※  ＦＯＲ／ＮＥＸＴ", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※２※  ＷＨＩＬＥ／ＷＥＮＤ", 8, 112, INT(RND * 14) + 1)
CALL d16("                          ※３※  字符函数（二）", 8, 128, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 144, INT(RND * 14) + 1)
CALL d16("请选择：", 80, 176, INT(RND * 14) + 1)
3 k$ = INKEY$: IF k$ = "" THEN 3
SELECT CASE k$
  CASE "1"
    CALL tfor
  CASE "2"
    CALL tdo
  CASE "3"
    CALL tfn2
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

SUB tdo
DIM temp(10000)
startdo:
CLS
CALL d16("        电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("          第三章  第二节  ＷＨＩＬＥ／ＷＥＮＤ", 8, 32, INT(RND * 14) + 1)
CALL d16("        主要内容：  １．ＷＨＩＬＥ／ＷＥＮＤ的功能", 8, 64, INT(RND * 14) + 1)
CALL d16("                    ２．ＷＨＩＬＥ／ＷＥＮＤ的格式", 8, 80, INT(RND * 14) + 1)
CALL d16("                    ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                    ０．返回", 8, 112, INT(RND * 14) + 1)
28 k$ = INKEY$: IF k$ = "" THEN 28
SELECT CASE k$
CASE "1"
CLS
CALL d16("        电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("          第三章  第二节  ＷＨＩＬＥ／ＷＥＮＤ", 8, 32, INT(RND * 14) + 1)
CALL d16("        ＷＨＩＬＥ／ＷＥＮＤ是条件循环语句。", 8, 64, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 96, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("        电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("          第三章  第二节  ＷＨＩＬＥ／ＷＥＮＤ", 8, 32, INT(RND * 14) + 1)
CALL d16("  ＷＨＩＬＥ／ＷＥＮＤ语句的格式：", 8, 48, INT(RND * 14) + 1)
CALL d16("  ＜行号＞ＷＨＩＬＥ  ＜条件＞", 8, 64, INT(RND * 14) + 1)
CALL d16("          …………", 8, 80, INT(RND * 14) + 1)
CALL d16("  ＜行号＞ＷＥＮＤ", 8, 96, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 160, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 176), 0, BF
CALL d16("    例行一：", 8, 48, INT(RND * 14) + 1)
CALL d16("    １０  ＷＨＩＬＥ  Ａ＜１０  ’开始循环，当Ａ＞＝１０则退出", 8, 64, INT(RND * 14) + 1)
CALL d16("                                  循环，跳到ＷＥＮＤ语句后面", 8, 80, INT(RND * 14) + 1)
CALL d16("    ２０  Ａ＝Ａ＋１  ’Ａ＋１（赋给）→Ａ", 8, 96, INT(RND * 14) + 1)
CALL d16("    ３０  ＰＲＩＮＴ  “Ａ＝”；Ａ  ’显示Ａ", 8, 112, INT(RND * 14) + 1)
CALL d16("    ４０  ＷＥＮＤ    ’返回循环开始处", 8, 128, INT(RND * 14) + 1)
CALL d16("    ５０  ＰＲＩＮＴ  “结束”：ＥＮＤ", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 165, INT(RND * 14) + 1)
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
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝１", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝２", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝３", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝４", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝５", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝６", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝７", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝８", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝９", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    结束", 8, 144, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 176), 0, BF
CALL d16("    例行二：", 8, 48, INT(RND * 14) + 1)
CALL d16("    １０  ＷＨＩＬＥ  Ａ＜＝３２", 8, 64, INT(RND * 14) + 1)
CALL d16("    ２０  ＰＲＩＮＴ  “Ａ＝”；Ａ", 8, 80, INT(RND * 14) + 1)
CALL d16("    ３０  Ａ＝Ａ＋３", 8, 96, INT(RND * 14) + 1)
CALL d16("    ４０  ＷＥＮＤ：ＰＲＩＮＴ  “结束”", 8, 112, INT(RND * 14) + 1)
CALL d16("    ５０  ＥＮＤ", 8, 128, INT(RND * 14) + 1)
CALL d16("    ＲＵＮ", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝０", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝３", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝６", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝９", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝１２", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝１５", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝１８", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝２１", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝２４", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝２７", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝３０", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    结束", 8, 144, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS : score = 100: a = 0
CALL mnsjf
CALL d16("现在请输入一段语句计算５＋７＋９＋……＋２３（十行起，实为递增）", 48, 48, INT(RND * 14) + 1)
CALL d16("（１）初始化ＳＵＭ为０", 68, 64, INT(RND * 14) + 1)
LOCATE 12, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "10sum=0" THEN a = 1
IF test$ = "10 sum=0" THEN a = 1
IF test$ = "10sum = 0" THEN a = 1
IF test$ = "10 sum = 0" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 20 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(400, 80), 0, BF
CALL d16("（２）设置循环，Ａ＜＝２３", 68, 64, INT(RND * 14) + 1)
LOCATE 13, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "20while a<=23" THEN a = 1
IF test$ = "20 while a<=23" THEN a = 1
IF test$ = "20while a <=23" THEN a = 1
IF test$ = "20 while a <=23" THEN a = 1
IF test$ = "20while a<= 23" THEN a = 1
IF test$ = "20 while a<= 23" THEN a = 1
IF test$ = "20while a <= 23" THEN a = 1
IF test$ = "20 while a <= 23" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 20 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(400, 80), 0, BF
CALL d16("（３）把ＳＵＭ的值加上Ａ", 68, 64, INT(RND * 14) + 1)
LOCATE 14, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "30sum=sum+a" THEN a = 1
IF test$ = "30 sum=sum+a" THEN a = 1
IF test$ = "30sum =sum+a" THEN a = 1
IF test$ = "30 sum =sum+a" THEN a = 1
IF test$ = "30sum= sum+a" THEN a = 1
IF test$ = "30 sum= sum+a" THEN a = 1
IF test$ = "30sum = sum+a" THEN a = 1
IF test$ = "30 sum = sum+a" THEN a = 1
IF test$ = "30sum=sum +a" THEN a = 1
IF test$ = "30 sum=sum +a" THEN a = 1
IF test$ = "30sum =sum +a" THEN a = 1
IF test$ = "30 sum =sum +a" THEN a = 1
IF test$ = "30sum= sum +a" THEN a = 1
IF test$ = "30 sum= sum +a" THEN a = 1
IF test$ = "30sum = sum +a" THEN a = 1
IF test$ = "30 sum = sum +a" THEN a = 1
IF test$ = "30sum=sum+ a" THEN a = 1
IF test$ = "30 sum=sum+ a" THEN a = 1
IF test$ = "30sum =sum+ a" THEN a = 1
IF test$ = "30 sum =sum+ a" THEN a = 1
IF test$ = "30sum= sum+ a" THEN a = 1
IF test$ = "30 sum= sum+ a" THEN a = 1
IF test$ = "30sum = sum+ a" THEN a = 1
IF test$ = "30 sum = sum+ a" THEN a = 1
IF test$ = "30sum=sum + a" THEN a = 1
IF test$ = "30 sum=sum + a" THEN a = 1
IF test$ = "30sum =sum + a" THEN a = 1
IF test$ = "30 sum =sum + a" THEN a = 1
IF test$ = "30sum= sum + a" THEN a = 1
IF test$ = "30 sum= sum + a" THEN a = 1
IF test$ = "30sum = sum + a" THEN a = 1
IF test$ = "30 sum = sum + a" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 20 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(420, 80), 0, BF
CALL d16("（４）将Ａ值增２", 68, 64, INT(RND * 14) + 1)
LOCATE 15, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "40a=a+2" THEN a = 1
IF test$ = "40 a=a+2" THEN a = 1
IF test$ = "40a =a+2" THEN a = 1
IF test$ = "40 a =a+2" THEN a = 1
IF test$ = "40a= a+2" THEN a = 1
IF test$ = "40 a= a+2" THEN a = 1
IF test$ = "40a = a+2" THEN a = 1
IF test$ = "40 a = a+2" THEN a = 1
IF test$ = "40a=a +2" THEN a = 1
IF test$ = "40 a=a +2" THEN a = 1
IF test$ = "40a =a +2" THEN a = 1
IF test$ = "40 a =a +2" THEN a = 1
IF test$ = "40a= a +2" THEN a = 1
IF test$ = "40 a= a +2" THEN a = 1
IF test$ = "40a = a +2" THEN a = 1
IF test$ = "40 a = a +2" THEN a = 1
IF test$ = "40a=a+ 2" THEN a = 1
IF test$ = "40 a=a+ 2" THEN a = 1
IF test$ = "40a =a+ 2" THEN a = 1
IF test$ = "40 a =a+ 2" THEN a = 1
IF test$ = "40a= a+ 2" THEN a = 1
IF test$ = "40 a= a+ 2" THEN a = 1
IF test$ = "40a = a+ 2" THEN a = 1
IF test$ = "40 a = a+ 2" THEN a = 1
IF test$ = "40a=a + 2" THEN a = 1
IF test$ = "40 a=a + 2" THEN a = 1
IF test$ = "40a =a + 2" THEN a = 1
IF test$ = "40 a =a + 2" THEN a = 1
IF test$ = "40a= a + 2" THEN a = 1
IF test$ = "40 a= a + 2" THEN a = 1
IF test$ = "40a = a + 2" THEN a = 1
IF test$ = "40 a = a + 2" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 20 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(400, 80), 0, BF
CALL d16("（５）返回循环开始处", 68, 64, INT(RND * 14) + 1)
LOCATE 16, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "50wend" THEN a = 1
IF test$ = "50 wend" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 20 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
CLS
CALL mnsjf
CALL d16("            您的分数是：", 8, 48, INT(RND * 14) + 1)
LOCATE 8, 30: PRINT score
     SELECT CASE score
       CASE 100
         CALL d16("            祝贺您！胜利来之不易，但愿您能够保持下去！", 8, 64, INT(RND * 14) + 1)
       CASE 80
         CALL d16("            欲穷千里目，更上一层楼！", 8, 64, INT(RND * 14) + 1)
       CASE 60
         CALL d16("            虽然您没有夺得胜利，但还过的去！", 8, 64, INT(RND * 14) + 1)
       CASE 40
         CALL d16("            还需好好努力！", 8, 64, INT(RND * 14) + 1)
       CASE 20, 0
         CALL d16("            失败乃成功之母！", 8, 64, INT(RND * 14) + 1)
     END SELECT
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO enddo
CASE ELSE
GOTO 28
END SELECT
GOTO startdo
enddo:

END SUB

SUB tfn2
starttf:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第三章    第四节    字符函数（二）", 8, 32, INT(RND * 14) + 1)
CALL d16("              主要内容：  ※１※  ＳＰＡＣＥ￥", 8, 64, INT(RND * 14) + 1)
CALL d16("                          ※２※  ＳＴＲ￥", 8, 80, INT(RND * 14) + 1)
CALL d16("                          ※３※  ＬＥＦＴ￥", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※４※  ＲＩＧＨＴ￥", 8, 112, INT(RND * 14) + 1)
CALL d16("                          ※５※  ＭＩＤ￥", 8, 128, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 144, INT(RND * 14) + 1)
CALL d16("请选择：", 80, 176, INT(RND * 14) + 1)
10 k$ = INKEY$: IF k$ = "" THEN 10
SELECT CASE k$
CASE "1"
  CALL tspace
CASE "2"
  CALL tstr
CASE "3"
  CALL tleft
CASE "4"
  CALL tright
CASE "5"
  CALL tmid
CASE "0"
  GOTO endtf
CASE ELSE
GOTO 10
END SELECT
GOTO starttf
endtf:
END SUB

SUB tfor
DIM temp(10000)
startfor:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("              第三章    第一节    ＦＯＲ／ＮＥＸＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("                  主要内容：  １．ＦＯＲ／ＮＥＸＴ的功能", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．ＦＯＲ／ＮＥＸＴ的格式", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 112, INT(RND * 14) + 1)
18 k$ = INKEY$: IF k$ = "" THEN 18
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("              第三章    第一节    ＦＯＲ／ＮＥＸＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("            ＦＯＲ／ＮＥＸＴ是增量循环语句。", 8, 64, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 96, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("              第三章    第一节    ＦＯＲ／ＮＥＸＴ", 8, 32, INT(RND * 14) + 1)
CALL d16("  ＦＯＲ／ＮＥＸＴ语句的格式：", 8, 48, INT(RND * 14) + 1)
CALL d16("  ＜行号＞ＦＯＲ  ＜变量＞＝＜表达式＞  ＴＯ  ＜表达式＞［ＳＴＥＰ  ＜步长＞］", 8, 64, INT(RND * 14) + 1)
CALL d16("          …………", 8, 80, INT(RND * 14) + 1)
CALL d16("  ＜行号＞ＮＥＸＴ  ＜变量＞", 8, 96, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 160, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 176), 0, BF
CALL d16("    例行一：", 8, 48, INT(RND * 14) + 1)
CALL d16("    １０  ＦＯＲ  Ａ＝１  ＴＯ  １０", 8, 64, INT(RND * 14) + 1)
CALL d16("    ２０  ＰＲＩＮＴ  “Ａ＝”；Ａ", 8, 80, INT(RND * 14) + 1)
CALL d16("    ３０  ＮＥＸＴ  Ａ", 8, 96, INT(RND * 14) + 1)
CALL d16("    ４０  ＰＲＩＮＴ  “结束”", 8, 112, INT(RND * 14) + 1)
CALL d16("    ５０  ＥＮＤ", 8, 128, INT(RND * 14) + 1)
CALL d16("    ＲＵＮ", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝１", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝２", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝３", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝４", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝５", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝６", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝７", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝８", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝９", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝１０", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    结束", 8, 144, INT(RND * 14) + 1)
CALL pause
LINE (0, 48)-(639, 176), 0, BF
CALL d16("    例行二：", 8, 48, INT(RND * 14) + 1)
CALL d16("    １０  ＦＯＲ  Ａ＝０  ＴＯ  ２０  ＳＴＥＰ  ２", 8, 64, INT(RND * 14) + 1)
CALL d16("    ２０  ＰＲＩＮＴ  “Ａ＝”；Ａ", 8, 80, INT(RND * 14) + 1)
CALL d16("    ３０  ＮＥＸＴ  Ａ", 8, 96, INT(RND * 14) + 1)
CALL d16("    ４０  ＰＲＩＮＴ  “结束”", 8, 112, INT(RND * 14) + 1)
CALL d16("    ５０  ＥＮＤ", 8, 128, INT(RND * 14) + 1)
CALL d16("    ＲＵＮ", 8, 144, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝０", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝２", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝４", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝６", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝８", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝１０", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝１２", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝１４", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝１６", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝１８", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    Ａ＝２０", 8, 144, INT(RND * 14) + 1)
CALL pause
GET (0, 64)-(540, 161), temp
VIEW (0, 64)-(540, 161)
CLS
FOR y = 0 TO -16 STEP -1
PUT (0, y), temp, PSET
NEXT y
VIEW
CALL d16("    结束", 8, 144, INT(RND * 14) + 1)
CALL pause


CASE "3"
CLS : score = 100: a = 0
CALL mnsjf
CALL d16("现在请输入一段语句计算１＋３＋５＋……＋９９（三十行起，实为递增）", 48, 48, INT(RND * 14) + 1)
CALL d16("（１）初始化ＳＵＭ为０", 68, 64, INT(RND * 14) + 1)
LOCATE 12, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ = "30sum=0" THEN a = 1
IF test$ = "30 sum=0" THEN a = 1
IF test$ = "30sum = 0" THEN a = 1
IF test$ = "30 sum = 0" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 20 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(400, 80), 0, BF
CALL d16("（２）设置循环，Ａ为１到９９步长２", 68, 64, INT(RND * 14) + 1)
LOCATE 13, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "40for a=1 to 99 step 2" THEN a = 1
IF test$ = "40 for a=1 to 99 step 2" THEN a = 1
IF test$ = "40for a=1to 99 step 2" THEN a = 1
IF test$ = "40 for a=1to 99 step 2" THEN a = 1
IF test$ = "40for a=1 to99 step 2" THEN a = 1
IF test$ = "40 for a=1 to99 step 2" THEN a = 1
IF test$ = "40for a=1to99 step 2" THEN a = 1
IF test$ = "40 for a=1to99 step 2" THEN a = 1
IF test$ = "40for a=1 to 99 step2" THEN a = 1
IF test$ = "40 for a=1 to 99 step2" THEN a = 1
IF test$ = "40for a=1to 99 step2" THEN a = 1
IF test$ = "40 for a=1to 99 step2" THEN a = 1
IF test$ = "40for a=1 to99 step2" THEN a = 1
IF test$ = "40 for a=1 to99 step2" THEN a = 1
IF test$ = "40for a=1to99 step2" THEN a = 1
IF test$ = "40 for a=1to99 step2" THEN a = 1
IF test$ = "40for a=1 to 99step 2" THEN a = 1
IF test$ = "40 for a=1 to 99step 2" THEN a = 1
IF test$ = "40for a=1to 99step 2" THEN a = 1
IF test$ = "40 for a=1to 99step 2" THEN a = 1
IF test$ = "40for a=1 to99step 2" THEN a = 1
IF test$ = "40 for a=1 to99step 2" THEN a = 1
IF test$ = "40for a=1to99step 2" THEN a = 1
IF test$ = "40 for a=1to99step 2" THEN a = 1
IF test$ = "40for a=1 to 99step2" THEN a = 1
IF test$ = "40 for a=1 to 99step2" THEN a = 1
IF test$ = "40for a=1to 99step2" THEN a = 1
IF test$ = "40 for a=1to 99step2" THEN a = 1
IF test$ = "40for a=1 to99step2" THEN a = 1
IF test$ = "40 for a=1 to99step2" THEN a = 1
IF test$ = "40for a=1to99step2" THEN a = 1
IF test$ = "40 for a=1to99step2" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 20 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(400, 80), 0, BF
CALL d16("（３）把ＳＵＭ的值加上Ａ", 68, 64, INT(RND * 14) + 1)
LOCATE 14, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "50sum=sum+a" THEN a = 1
IF test$ = "50 sum=sum+a" THEN a = 1
IF test$ = "50sum =sum+a" THEN a = 1
IF test$ = "50 sum =sum+a" THEN a = 1
IF test$ = "50sum= sum+a" THEN a = 1
IF test$ = "50 sum= sum+a" THEN a = 1
IF test$ = "50sum = sum+a" THEN a = 1
IF test$ = "50 sum = sum+a" THEN a = 1
IF test$ = "50sum=sum +a" THEN a = 1
IF test$ = "50 sum=sum +a" THEN a = 1
IF test$ = "50sum =sum +a" THEN a = 1
IF test$ = "50 sum =sum +a" THEN a = 1
IF test$ = "50sum= sum +a" THEN a = 1
IF test$ = "50 sum= sum +a" THEN a = 1
IF test$ = "50sum = sum +a" THEN a = 1
IF test$ = "50 sum = sum +a" THEN a = 1
IF test$ = "50sum=sum+ a" THEN a = 1
IF test$ = "50 sum=sum+ a" THEN a = 1
IF test$ = "50sum =sum+ a" THEN a = 1
IF test$ = "50 sum =sum+ a" THEN a = 1
IF test$ = "50sum= sum+ a" THEN a = 1
IF test$ = "50 sum= sum+ a" THEN a = 1
IF test$ = "50sum = sum+ a" THEN a = 1
IF test$ = "50 sum = sum+ a" THEN a = 1
IF test$ = "50sum=sum + a" THEN a = 1
IF test$ = "50 sum=sum + a" THEN a = 1
IF test$ = "50sum =sum + a" THEN a = 1
IF test$ = "50 sum =sum + a" THEN a = 1
IF test$ = "50sum= sum + a" THEN a = 1
IF test$ = "50 sum= sum + a" THEN a = 1
IF test$ = "50sum = sum + a" THEN a = 1
IF test$ = "50 sum = sum + a" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 20 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(420, 80), 0, BF
CALL d16("（４）返回循环。", 68, 64, INT(RND * 14) + 1)
LOCATE 15, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "60next a" THEN a = 1
IF test$ = "60 next a" THEN a = 1
IF test$ = "60next" THEN a = 1
IF test$ = "60 next" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 20 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
LINE (68, 64)-(400, 80), 0, BF
CALL d16("（５）显示ＳＵＭ", 68, 64, INT(RND * 14) + 1)
LOCATE 16, 5: LINE INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
a = 0
IF test$ = "70print sum" THEN a = 1
IF test$ = "70 print sum" THEN a = 1
IF test$ = "70print  sum" THEN a = 1
IF test$ = "70 print  sum" THEN a = 1
LINE (0, 160)-(639, 176), 0, BF
IF a <> 1 THEN CALL d16("输入错误！", 8, 160, INT(RND * 14) + 1): score = score - 20 ELSE CALL d16("输入正确！", 8, 160, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 176, INT(RND * 14) + 1)
CALL pause
CLS
CALL mnsjf
CALL d16("            您的分数是：", 8, 48, INT(RND * 14) + 1)
LOCATE 8, 30: PRINT score
     SELECT CASE score
       CASE 100
         CALL d16("            祝贺您！胜利来之不易，但愿您能够保持下去！", 8, 64, INT(RND * 14) + 1)
       CASE 80
         CALL d16("            欲穷千里目，更上一层楼！", 8, 64, INT(RND * 14) + 1)
       CASE 60
         CALL d16("            虽然您没有夺得胜利，但还过的去！", 8, 64, INT(RND * 14) + 1)
       CASE 40
         CALL d16("            还需好好努力！", 8, 64, INT(RND * 14) + 1)
       CASE 20, 0
         CALL d16("            失败乃成功之母！", 8, 64, INT(RND * 14) + 1)
     END SELECT
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endfor
CASE ELSE
GOTO 18
END SELECT
GOTO startfor
endfor:
END SUB

SUB tleft
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

SUB tmid
DIM temp(10000)
startink:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（二）～～～ＩＮＫＥＹ", 8, 32, INT(RND * 14) + 1)
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
CALL d16("      第二章    第四节    字符函数（二）～～～ＩＮＫＥＹ的功能", 8, 16, INT(RND * 14) + 1)
CALL d16("      ＩＮＫＥＹ的功能是从键盘上读入一个字符。", 8, 48, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（二）～～～ＩＮＫＥＹ的格式？", 8, 16, INT(RND * 14) + 1)
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

SUB tright
DIM temp(15000)
startlen:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（二）～～～ＬＥＮ", 8, 32, INT(RND * 14) + 1)
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
CALL d16("      第二章    第四节    字符函数（二）～～～ＬＥＮ的功能", 8, 16, INT(RND * 14) + 1)
CALL d16("      ＬＥＮ的功能是求字符串的长度。", 8, 48, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（二）～～～ＬＥＮ的格式？", 8, 16, INT(RND * 14) + 1)
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

SUB tspace
startzfi:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（二）～～～ＳＰＡＣＥ￥", 8, 32, INT(RND * 14) + 1)
CALL d16("                          ※１※  ＳＰＡＣＥ￥的功能", 8, 64, INT(RND * 14) + 1)
CALL d16("                          ※２※  ＳＰＡＣＥ￥的格式", 8, 80, INT(RND * 14) + 1)
CALL d16("                          ※３※  模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 112, INT(RND * 14) + 1)
CALL d16("请选择：", 80, 176, INT(RND * 14) + 1)
11 k$ = INKEY$: IF k$ = "" THEN 11
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（二）～～～ＳＰＡＣＥ￥的功能", 8, 16, INT(RND * 14) + 1)
CALL d16("      ＳＰＡＣＥ￥的功能是取ｎ的空格的字符串。", 8, 48, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（二）～～～ＳＰＡＣＥ￥的格式", 8, 16, INT(RND * 14) + 1)
CALL d16("  Ｖ￥＝ＳＰＡＣＥ￥（ｎ）", 8, 48, INT(RND * 14) + 1)
CALL d16("  例行：１０  Ａ￥＝“下面有”：Ｂ￥＝“个空格”", 8, 64, INT(RND * 14) + 1)
CALL d16("        ２０  Ｃ￥＝ＳＰＡＣＥ￥（１０）", 8, 80, INT(RND * 14) + 1)
CALL d16("        ３０  Ｄ￥＝Ａ￥＋Ｃ￥＋Ｂ￥", 8, 96, INT(RND * 14) + 1)
CALL d16("        ４０  ＰＲＩＮＴ  Ｄ￥", 8, 114, INT(RND * 14) + 1)
CALL d16("        ５０  ＰＲＩＮＴ  Ａ￥；ＬＥＮ（Ｃ￥）；Ｂ￥", 8, 128, INT(RND * 14) + 1)
CALL d16("        ６０  ＥＮＤ", 8, 144, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "3"


CALL pause
CASE "0"
GOTO endzfi
CASE ELSE
GOTO 11
END SELECT
GOTO startzfi
endzfi:
END SUB

SUB tstr
DIM temp(10000)
startasc:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（二）～～～ＡＳＣ", 8, 32, INT(RND * 14) + 1)
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
CALL d16("      第二章    第四节    字符函数（二）～～～ＡＳＣ的功能", 8, 16, INT(RND * 14) + 1)
CALL d16("      ＡＳＣ的功能是把对应的字符转换成对应的ＡＳＣＩＩ值", 8, 48, INT(RND * 14) + 1)
CALL d16("  一般用于特殊字符和字符序列判别（如小写和大写的判别）。", 8, 64, INT(RND * 14) + 1)
CALL d16("      它的功能与ＣＨＲ￥函数相反。", 8, 80, INT(RND * 14) + 1)
CALL d16("    按任意键继续……", 8, 165, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("      第二章    第四节    字符函数（二）～～～ＡＳＣ的格式？", 8, 16, INT(RND * 14) + 1)
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

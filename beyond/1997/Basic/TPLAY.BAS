DECLARE SUB MNSJF ()
DECLARE SUB pause ()
DECLARE SUB ym ()
DECLARE SUB pl ()
DECLARE SUB sg ()
DECLARE SUB sd ()
DECLARE SUB yq ()
DECLARE SUB d16 (char$, xx!, xy!, xc!)
RANDOMIZE TIMER
start:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("            （Ｃ）ＣＯＰＹＲＩＧＨＴ  １９９７，１９９８", 8, 16, INT(RND * 14) + 1)
CALL d16("                          第九章", 8, 48, INT(RND * 14) + 1)
CALL d16("                  ＧＷＢＡＳＩＣ－ＰＬＡＹ", 8, 64, INT(RND * 14) + 1)
CALL d16("              主要内容：  ※１※  音名", 8, 96, INT(RND * 14) + 1)
CALL d16("                          ※２※  频率", 8, 112, INT(RND * 14) + 1)
CALL d16("                          ※３※  声高", 8, 128, INT(RND * 14) + 1)
CALL d16("                          ※４※  速度", 8, 144, INT(RND * 14) + 1)
CALL d16("                          ※５※  方式", 8, 160, INT(RND * 14) + 1)
CALL d16("                          ※０※  退出", 8, 176, INT(RND * 14) + 1)
CALL d16("请选择：", 420, 176, INT(RND * 14) + 1)
3 k$ = INKEY$: IF k$ = "" THEN 3
SELECT CASE k$
  CASE "1"
    CALL ym
  CASE "2"
    CALL pl
  CASE "3"
    CALL sg
  CASE "4"
    CALL sd
  CASE "5"
    CALL yq
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

SUB pl
startpl:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)

CALL d16("                          第九章    第二节    频率", 8, 32, INT(RND * 14) + 1)

CALL d16("                  主要内容：  １．什么是频率", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．如何将频率翻译成机器谱", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 112, INT(RND * 14) + 1)
6 k$ = INKEY$: IF k$ = "" THEN 6
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第二节    频率", 8, 32, INT(RND * 14) + 1)
CALL d16("            什么是频率？", 8, 48, INT(RND * 14) + 1)
CALL d16("            描述单个音符速度的就是频率，也就是每个音符的快慢。", 8, 64, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第二节    频率", 8, 32, INT(RND * 14) + 1)
CALL d16("    如何将频率翻译成机器谱？很简单，只需按照下列格式转换：", 8, 48, INT(RND * 14) + 1)
CALL d16("        １  ２  ３  ４  ５  ６  ７", 8, 64, INT(RND * 14) + 1)
CALL d16("        １  ２  ３  ４  ５  ６  ７", 8, 80, INT(RND * 14) + 1)
CALL d16("        ─────────────", 8, 90, INT(RND * 14) + 1)
CALL d16("                      ┃          ", 8, 81, INT(RND * 14) + 1)
CALL d16("        １  ２  ３  ４  ５  ６  ７", 8, 100, INT(RND * 14) + 1)
CALL d16("        ─────────────", 8, 110, INT(RND * 14) + 1)
CALL d16("        ─────────────", 8, 112, INT(RND * 14) + 1)
CALL d16("                      ┃          ", 8, 101, INT(RND * 14) + 1)
CALL d16("        １  ２  ３  ４  ５  ６  ７", 8, 120, INT(RND * 14) + 1)
CALL d16("        ─────────────", 8, 130, INT(RND * 14) + 1)
CALL d16("        ─────────────", 8, 132, INT(RND * 14) + 1)
CALL d16("        ─────────────", 8, 134, INT(RND * 14) + 1)
CALL d16("                      ┃          ", 8, 121, INT(RND * 14) + 1)
CALL d16("        １  ２  ３  ４  ５  ６  ７", 8, 144, INT(RND * 14) + 1)
CALL d16("        ─────────────", 8, 154, INT(RND * 14) + 1)
CALL d16("        ─────────────", 8, 156, INT(RND * 14) + 1)
CALL d16("        ─────────────", 8, 158, INT(RND * 14) + 1)
CALL d16("        ─────────────", 8, 160, INT(RND * 14) + 1)
CALL d16("                      ┃          ", 8, 145, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 170, INT(RND * 14) + 1)
CALL pause
CALL d16("对应机器谱↑", 300, 170, INT(RND * 14) + 1)
CALL d16("Ｃ４Ｄ４Ｅ４Ｆ４Ｇ４Ａ４Ｂ４", 300, 64, INT(RND * 14) + 1)
CALL d16("Ｃ８Ｄ８Ｅ８Ｆ８Ｇ８Ａ８Ｂ８", 300, 80, INT(RND * 14) + 1)
CALL d16("Ｃ１６Ｄ１６Ｅ１６Ｆ１６Ｇ１６Ａ１６Ｂ１６", 300, 98, INT(RND * 14) + 1)
CALL d16("Ｃ３２Ｄ３２Ｅ３２Ｆ３２Ｇ３２Ａ３２Ｂ３２", 300, 120, INT(RND * 14) + 1)
CALL d16("Ｃ６４Ｄ６４Ｅ６４Ｆ６４Ｇ６４Ａ６４Ｂ６４", 300, 144, INT(RND * 14) + 1)
CALL pause
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第二节    频率", 8, 32, INT(RND * 14) + 1)
CALL d16("        １—２—┃３—４—┃５—６—┃７—", 8, 64, INT(RND * 14) + 1)
CALL d16("        １——２┃２—３—┃３４——┃５——６┃６—７—┃７", 8, 112, INT(RND * 14) + 1)
CALL d16("              ／  ＼  ／    ＼              ／  ＼  ／    ＼", 8, 96, INT(RND * 14) + 1)
CALL d16("                —      ——                  —      ——", 8, 88, INT(RND * 14) + 1)
CALL d16("        １———┃２———┃３———┃４———┃５———┃６———  ７———", 8, 144, INT(RND * 14) + 1)
CALL d16("            按任意键显示对应机器谱……", 8, 180, INT(RND * 14) + 1)
CALL pause
CALL d16("        Ｃ３Ｄ３  Ｅ３Ｆ３  Ｇ３Ａ３  Ｂ３", 8, 80, INT(RND * 14) + 1)
CALL d16("        Ｃ２  Ｄ２    Ｅ２    Ｆ２    Ｇ２  Ａ２  Ｂ２", 8, 128, INT(RND * 14) + 1)
CALL d16("        Ｃ１      Ｄ１      Ｅ１      Ｆ１      Ｇ１      Ａ１      Ｂ１", 8, 160, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第二节    频率", 8, 32, INT(RND * 14) + 1)
CALL d16("            现在将模拟上机，先介绍一下音乐的基本格式：", 8, 48, INT(RND * 14) + 1)
CALL d16("            ＜行号＞ＰＬＡＹ  “ＸＸＸＸ”", 8, 64, INT(RND * 14) + 1)
CALL d16("            如：２１０  ＰＬＡＹ  “ＣＤＥ”", 8, 80, INT(RND * 14) + 1)
CALL d16("          按任意键继续……", 8, 96, INT(RND * 14) + 1)
CALL pause
CLS
CALL MNSJF
CALL d16("            现在请输入一条语句（行号１５０），让计算机演奏“６６１７２”", 8, 48, INT(RND * 14) + 1)
CALL d16("                                                            ————    ", 8, 56, INT(RND * 14) + 1)
CALL d16("                                                            —    —    ", 8, 58, INT(RND * 14) + 1)
LOCATE 10, 5: INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ <> "150 play" + CHR$(34) + "a16a8c8b16d" + CHR$(34) AND test$ <> "150play" + CHR$(34) + "a16a8c8b16d" + CHR$(34) AND test$ <> "150 play " + CHR$(34) + "a16a8c8b16d" + CHR$(34) AND test$ <> "150play " + CHR$(34) + "a16a8c8b16d" + CHR$(34)  _
THEN CALL d16("输入错误！", 8, 180, INT(RND * 14) + 1) ELSE PLAY "mft120a16a8c8b16d"
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

SUB sd
startsd:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)

CALL d16("                          第九章    第四节    速度", 8, 32, INT(RND * 14) + 1)

CALL d16("                  主要内容：  １．什么是速度", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．如何将简谱翻译成机器谱", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 112, INT(RND * 14) + 1)
8 k$ = INKEY$: IF k$ = "" THEN 8
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第四节    速度", 8, 32, INT(RND * 14) + 1)
CALL d16("            什么是速度？", 8, 48, INT(RND * 14) + 1)
CALL d16("            所谓速度，就是乐谱的总体速度。", 8, 64, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第四节    速度", 8, 32, INT(RND * 14) + 1)
CALL d16("        如何将速度翻译成机器谱？", 8, 48, INT(RND * 14) + 1)
CALL d16("        再简单不过了！", 8, 64, INT(RND * 14) + 1)
CALL d16("        速度的上限为Ｔ２５５，下限为Ｔ３２", 8, 80, INT(RND * 14) + 1)
CALL d16("        数值越大总体速速度越快，如“Ｔ２３０”比“Ｔ１１０”快的多！", 8, 96, INT(RND * 14) + 1)
CALL d16("                                                  （一般速为１１０）", 8, 112, INT(RND * 14) + 1)
CALL d16("        按任意键继续……", 8, 128, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS
CALL MNSJF
CALL d16("    现在请输入一条语句（行号４０），让计算机演奏的总体速度为常速。", 8, 48, INT(RND * 14) + 1)
LOCATE 10, 5: INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ <> "40 play" + CHR$(34) + "t110" + CHR$(34) AND test$ <> "40play" + CHR$(34) + "t110" + CHR$(34) AND test$ <> "40 play " + CHR$(34) + "t110" + CHR$(34) AND test$ <> "40play " + CHR$(34) + "t110" + CHR$(34) THEN CALL d16("输入错误！", 8, 180 _
, INT(RND * 14) + 1) ELSE PLAY "mft255l64cdefgab>cdefgab>cdefgab>cdefgabt110l4o3": CALL d16("ＧＯＯＤ！", 300, 180, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 180, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endsd
CASE ELSE
GOTO 8
END SELECT
GOTO startsd
endsd:

END SUB

SUB sg
startsg:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)

CALL d16("                          第九章    第三节    声高", 8, 32, INT(RND * 14) + 1)

CALL d16("                  主要内容：  １．什么是声高", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．如何将声高翻译成机器谱", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 112, INT(RND * 14) + 1)
7 k$ = INKEY$: IF k$ = "" THEN 7
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第三节    声高", 8, 32, INT(RND * 14) + 1)
CALL d16("            什么是声高？", 8, 48, INT(RND * 14) + 1)
CALL d16("            所谓声高，就是描述声音的高低的数值。", 8, 64, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第三节    声高", 8, 32, INT(RND * 14) + 1)
CALL d16("            如何将简谱翻译成机器谱？很简单，只要安下列方式转换即可：", 8, 48, INT(RND * 14) + 1)
CALL d16("            ．", 12, 59, INT(RND * 14) + 1)
CALL d16("            ．  ．", 12, 64, INT(RND * 14) + 1)
CALL d16("            １  ２  ３  ４", 8, 80, INT(RND * 14) + 1)
CALL d16("                    ．  ．", 12, 82, INT(RND * 14) + 1)
CALL d16("                        ．", 12, 87, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 128, INT(RND * 14) + 1)
CALL pause
CALL d16("                                Ｏ５ＣＯ４ＤＯ２ＥＯ１Ｆ", 8, 80, INT(RND * 14) + 1)
CALL pause
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第三节    声高", 8, 32, INT(RND * 14) + 1)
CALL d16("            总结：", 8, 48, INT(RND * 14) + 1)
CALL d16("            ．", 12, 60, INT(RND * 14) + 1)
CALL d16("            ．  ．", 12, 64, INT(RND * 14) + 1)
CALL d16("            ．  ．  ．", 12, 68, INT(RND * 14) + 1)
CALL d16("            Ｘ  Ｘ  Ｘ  Ｘ  Ｘ  Ｘ  Ｘ", 8, 85, INT(RND * 14) + 1)
CALL d16("                            ．  ．  ．", 12, 96, INT(RND * 14) + 1)
CALL d16("                                ．  ．", 12, 100, INT(RND * 14) + 1)
CALL d16("                                    ．", 12, 104, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 180, INT(RND * 14) + 1)
CALL pause
CALL d16("            Ｏ６Ｏ５Ｏ４Ｏ３Ｏ２Ｏ１Ｏ０", 8, 128, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS
CALL MNSJF
CALL d16("                                                              ．", 12, 32, INT(RND * 14) + 1)
CALL d16("            现在请输入一条语句（行号３３０），让计算机演奏“５１—７６”", 8, 48, INT(RND * 14) + 1)
LOCATE 10, 5: INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ <> "330 play" + CHR$(34) + "o3go4c3o3ba" + CHR$(34) AND test$ <> "330play" + CHR$(34) + "o3go4c3o3ba" + CHR$(34) AND test$ <> "330 play " + CHR$(34) + "o3go4c3o3ba" + CHR$(34) AND test$ <> "330play " + CHR$(34) + "o3go4c3o3ba" + CHR$(34)  _
THEN CALL d16("输入错误！", 8, 180, INT(RND * 14) + 1) ELSE PLAY "mft120gcbe"
CALL d16("            按任意键继续……", 8, 180, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endsg
CASE ELSE
GOTO 7
END SELECT
GOTO startsg
endsg:
END SUB

SUB ym
startym:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)

CALL d16("                          第九章    第一节    音名", 8, 32, INT(RND * 14) + 1)

CALL d16("                  主要内容：  １．什么是音名", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．什么是简谱", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．如何将简谱翻译成机器谱", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ４．模拟上机", 8, 112, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 128, INT(RND * 14) + 1)
5 k$ = INKEY$: IF k$ = "" THEN 5
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第一节    音名", 8, 32, INT(RND * 14) + 1)
CALL d16("            什么是音名？", 8, 48, INT(RND * 14) + 1)
CALL d16("            所谓音名，就是我们常说的“哆、来、咪”", 8, 64, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第一节    音名", 8, 32, INT(RND * 14) + 1)
CALL d16("            什么是简谱？", 8, 48, INT(RND * 14) + 1)
CALL d16("            所谓简谱，就是我们常见的“１、２、３、４、５、６、７”", 8, 64, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 80, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第一节    音名", 8, 32, INT(RND * 14) + 1)
CALL d16("            如何将简谱翻译成机器谱？很简单，只要安下列方式转换即可：", 8, 48, INT(RND * 14) + 1)
CALL d16("            １  ２  ３  ４  ５  ６  ７", 8, 64, INT(RND * 14) + 1)
CALL d16("            Ｃ  Ｄ  Ｅ  Ｆ  Ｇ  Ａ  Ｂ", 8, 80, INT(RND * 14) + 1)
CALL d16("            如１２３可以写ＣＤＥ", 8, 96, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 112, INT(RND * 14) + 1)
CALL pause
CASE "4"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第一节    音名", 8, 32, INT(RND * 14) + 1)
CALL d16("            现在将模拟上机，先介绍一下音乐的基本格式：", 8, 48, INT(RND * 14) + 1)
CALL d16("            ＜行号＞ＰＬＡＹ  “ＸＸＸＸ”", 8, 64, INT(RND * 14) + 1)
CALL d16("            如：２１０  ＰＬＡＹ  “ＣＤＥ”", 8, 80, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 96, INT(RND * 14) + 1)
CALL pause
CLS
CALL MNSJF
CALL d16("            现在请输入一条语句（行号１４０），让计算机演奏“５１７３”", 8, 48, INT(RND * 14) + 1)
LOCATE 10, 5: INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ <> "140 play" + CHR$(34) + "gcbe" + CHR$(34) AND test$ <> "140play" + CHR$(34) + "gcbe" + CHR$(34) AND test$ <> "140 play " + CHR$(34) + "gcbe" + CHR$(34) AND test$ <> "140play " + CHR$(34) + "gcbe" + CHR$(34) THEN CALL d16("输入错误！", 8 _
, 180, INT(RND * 14) + 1) ELSE PLAY "mft120gcbe"
CALL d16("            按任意键继续……", 8, 180, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endym
CASE ELSE
GOTO 5
END SELECT
GOTO startym
endym:
END SUB

SUB yq
startyq:
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第五节    方式", 8, 32, INT(RND * 14) + 1)
CALL d16("                  主要内容：  １．什么是方式", 8, 64, INT(RND * 14) + 1)
CALL d16("                              ２．如何将方式翻译成机器谱", 8, 80, INT(RND * 14) + 1)
CALL d16("                              ３．模拟上机", 8, 96, INT(RND * 14) + 1)
CALL d16("                              ４．注意事项", 8, 112, INT(RND * 14) + 1)
CALL d16("                              ０．返回", 8, 128, INT(RND * 14) + 1)
9 k$ = INKEY$: IF k$ = "" THEN 9
SELECT CASE k$
CASE "1"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第五节    方式", 8, 32, INT(RND * 14) + 1)
CALL d16("            什么是方式？", 8, 48, INT(RND * 14) + 1)
CALL d16("            所谓方式，就是演奏的方式", 8, 64, INT(RND * 14) + 1)
CALL d16("            分为前台演奏，柔和演奏，活动演奏，后台伴奏", 8, 80, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 96, INT(RND * 14) + 1)
CALL pause
CASE "2"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第五节    方式", 8, 32, INT(RND * 14) + 1)
CALL d16("            如何将方式翻译成机器谱？很简单，只要安下列方式转换即可：", 8, 48, INT(RND * 14) + 1)
CALL d16("            前台演奏  柔和演奏  活动演奏", 8, 80, INT(RND * 14) + 1)
CALL d16("              ＭＦ      ＭＬ      ＭＳ", 8, 96, INT(RND * 14) + 1)
CALL d16("            （这里不谈后台伴奏）", 8, 112, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 128, INT(RND * 14) + 1)
CALL pause
CASE "3"
CLS
CALL MNSJF
CALL d16("            现在请输入一条语句（行号１４０）", 8, 48, INT(RND * 14) + 1)
CALL d16("            让计算机演奏把演奏方式设定成为活动演奏，并演奏１２３４", 8, 66, INT(RND * 14) + 1)
LOCATE 11, 5: INPUT "HongFei>", test$
test$ = LTRIM$(RTRIM$(LCASE$(test$)))
IF test$ <> "140 play" + CHR$(34) + "mscdef" + CHR$(34) AND test$ <> "140play" + CHR$(34) + "mscdef" + CHR$(34) AND test$ <> "140 play " + CHR$(34) + "mscdef" + CHR$(34) AND test$ <> "140play " + CHR$(34) + "mscdef" + CHR$(34) THEN CALL d16( _
"输入错误！", 8, 180, INT(RND * 14) + 1) ELSE PLAY "mscdef"
CALL d16("            按任意键继续……", 8, 180, INT(RND * 14) + 1)
CALL pause
CASE "4"
CLS
CALL d16("            电脑小家教  版本：１．００  制作：谢继雷", 8, 0, INT(RND * 14) + 1)
CALL d16("                          第九章    第五节    方式", 8, 32, INT(RND * 14) + 1)
CALL d16("            ①、休止符后的频率如果是４的话，这个４不能省略。", 8, 48, INT(RND * 14) + 1)
CALL d16("            ②、声高如果有变动的话，必须先加以说明。", 8, 64, INT(RND * 14) + 1)
CALL d16("            ③、每行最好不要超过一排，以免出现差错。", 8, 80, INT(RND * 14) + 1)
CALL d16("            按任意键继续……", 8, 96, INT(RND * 14) + 1)
CALL pause
CASE "0"
GOTO endyq
CASE ELSE
GOTO 9
END SELECT
GOTO startyq
endyq:
END SUB

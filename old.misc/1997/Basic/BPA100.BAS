DECLARE SUB bpshell ()
DECLARE SUB fb (f$, rst%)
DECLARE SUB IIAB (filename$, yn%)
DECLARE SUB toup (CHAR$)
COMMON SHARED lu$, u$, ru$, l$, r$, ld$, rd$, d$, skip
COMMON SHARED f1$, f2$, f3$, f4$, f5$, f6$, f7$, f8$, f9$, f10$, f11$, f12$
COMMON SHARED sf1$, sf2$, sf3$, sf4$, sf5$, sf6$, sf7$, sf8$, sf9$, sf10$, sf11$, sf12$
COMMON SHARED cf1$, cf2$, cf3$, cf4$, cf5$, cf6$, cf7$, cf8$, cf9$, cf10$, cf11$, cf12$
COMMON SHARED af1$, af2$, af3$, af4$, af5$, af6$, af7$, af8$, af9$, af10$, af11$, af12$
COMMON SHARED delete$, insert$
COMMON SHARED x, y, c
DECLARE SUB star4 ()
DECLARE SUB finh ()
DECLARE SUB games ()
DECLARE SUB dir ()
DECLARE SUB dline (x!, y!, c!, s!)
DECLARE SUB dpset (x!, y!, c!, s!)
DECLARE SUB tutor1 ()
DECLARE SUB d16 (CHAR$, xx!, xy!, xc!)
DECLARE SUB ur (aaa$)
DECLARE SUB tutor ()
DECLARE SUB dcircle (x!, y!, c!, s!, f!)
DECLARE SUB dpm ()
DECLARE SUB dlt ()
DECLARE SUB ds ()
DECLARE SUB dother ()
DECLARE SUB dclear ()
DECLARE SUB dpaint (x!, y!, c!, s!)
DECLARE SUB dbox (x!, y!, c!, s!, f!)
DECLARE SUB bp ()
DECLARE SUB dtext (tx!, ty!, tc!)
RANDOMIZE TIMER
lu$ = CHR$(0) + CHR$(71)
ru$ = CHR$(0) + CHR$(73)
ld$ = CHR$(0) + CHR$(79)
rd$ = CHR$(0) + CHR$(81)
l$ = CHR$(0) + CHR$(75)
r$ = CHR$(0) + CHR$(77)
u$ = CHR$(0) + CHR$(72)
d$ = CHR$(0) + CHR$(80)
skip = 1: c = 15
x = 300: y = 150: c = 15
f1$ = CHR$(0) + CHR$(59)
f2$ = CHR$(0) + CHR$(60)
f3$ = CHR$(0) + CHR$(61)
f4$ = CHR$(0) + CHR$(62)
f5$ = CHR$(0) + CHR$(63)
f6$ = CHR$(0) + CHR$(64)
f7$ = CHR$(0) + CHR$(65)
f8$ = CHR$(0) + CHR$(66)
f9$ = CHR$(0) + CHR$(67)
f10$ = CHR$(0) + CHR$(68)

sf1$ = CHR$(0) + CHR$(84)
sf2$ = CHR$(0) + CHR$(85)
sf3$ = CHR$(0) + CHR$(86)
sf4$ = CHR$(0) + CHR$(87)
sf5$ = CHR$(0) + CHR$(88)
sf6$ = CHR$(0) + CHR$(89)
sf7$ = CHR$(0) + CHR$(90)
sf8$ = CHR$(0) + CHR$(91)
sf9$ = CHR$(0) + CHR$(92)
sf10$ = CHR$(0) + CHR$(93)
cf1$ = CHR$(0) + CHR$(94)
cf2$ = CHR$(0) + CHR$(95)
cf3$ = CHR$(0) + CHR$(96)
cf4$ = CHR$(0) + CHR$(97)
cf5$ = CHR$(0) + CHR$(98)
cf6$ = CHR$(0) + CHR$(99)
cf7$ = CHR$(0) + CHR$(100)
cf8$ = CHR$(0) + CHR$(101)
cf9$ = CHR$(0) + CHR$(102)
cf10$ = CHR$(0) + CHR$(103)
af1$ = CHR$(0) + CHR$(104)
af2$ = CHR$(0) + CHR$(105)
af3$ = CHR$(0) + CHR$(106)
af4$ = CHR$(0) + CHR$(107)
af5$ = CHR$(0) + CHR$(108)
af6$ = CHR$(0) + CHR$(109)
af7$ = CHR$(0) + CHR$(110)
af8$ = CHR$(0) + CHR$(111)
af9$ = CHR$(0) + CHR$(112)
af10$ = CHR$(0) + CHR$(113)
f11$ = CHR$(0) + CHR$(133)
f12$ = CHR$(0) + CHR$(134)
sf11$ = CHR$(0) + CHR$(135)
sf12$ = CHR$(0) + CHR$(136)
cf11$ = CHR$(0) + CHR$(137)
cf12$ = CHR$(0) + CHR$(138)
af11$ = CHR$(0) + CHR$(139)
af12$ = CHR$(0) + CHR$(140)
delete$ = CHR$(0) + CHR$(83)
insert$ = CHR$(0) + CHR$(82)
SCREEN 9
COLOR 15, 0
CALL d16("ÎÄ¼þÃû£¿", 8, 120, 15)
LOCATE 10, 10: INPUT "", nf$
ext$ = ".BP"
CLOSE
IF nf$ = "" THEN nf$ = "UNKNOW" + ext$ ELSE nf$ = nf$ + ext$
OPEN nf$ FOR OUTPUT AS #1
WRITE #1, "ÿ ÿBpÿ ÿ"
CLS
begin:
DO
VIEW (1, 1)-(400, 70), , 15
CLS
CALL d16("£Â£Á£Ó£É£Ã³ÌÐòÉú³ÉÆ÷  ÖÆ×÷£ºÐ»¼ÌÀ×  °æ±¾£±£®£°£°", 8, 0, 14)
CALL d16("    £±¡ªÏµÍ³Éè¶¨    £³¡ªÆ½ÃæÍ¼ÐÎ    £µ¡ªÉùÒô", 8, 19, 11)
CALL d16("    £²¡ªÄ¿Â¼²Ù×÷    £´¡ªÁ¢ÌåÍ¼ÐÎ    £¶¡ªÆäËü", 8, 35, 11)
CALL d16("    £°¡ªÍË³ö        £Ó¡ª£Ó£è£å£ì£ì  £¡¡ªÐÝÏ¢", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
VIEW (405, 1)-(619, 70), , 15
CALL d16("ÐÅÏ¢´°", 8, 0, 13)
VIEW (1, 75)-(619, 345), , 15
1 k$ = INKEY$
  IF k$ = "" THEN 1
  SELECT CASE k$
   CASE "1"
      CALL bp
   CASE "2"
      CALL dir
   CASE "3"
      CALL dpm
   CASE "4"
      CALL dlt
   CASE "5"
      CALL ds
   CASE "6"
      CALL dother
   CASE "0", CHR$(27)
      CALL finh
   CASE "S", "s"
      CALL bpshell
   CASE "&"
      CALL dclear
   CASE "!"
      CALL games
   CASE ELSE
      GOTO 1
END SELECT
LOOP

SUB bp
VIEW (1, 1)-(400, 70), , 15
CLS
CALL d16("£Â£Á£Ó£É£Ã³ÌÐòÉú³ÉÆ÷  ÖÆ×÷£ºÐ»¼ÌÀ×  °æ±¾£±£®£°£°", 8, 0, 14)
CALL d16("  £±¡ªÏÔÊ¾°æ±¾    £²¡ªÊ¹ÓÃËµÃ÷    £³¡ª²Ù×÷Ö¸ÄÏ", 8, 19, 11)

CALL d16("                  £°¡ªÍË³ö", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
CALL ur(xz$)
SELECT CASE xz$
  CASE "1"
    VIEW (405, 1)-(619, 70), , 15
    LINE (10, 20)-(10, 50), 14
    CIRCLE (25, 50), 1, 15
    CIRCLE (35, 35), 15, , , , 2
    CIRCLE (55, 35), 15, , , , 2
  CASE "2"
    CALL tutor
  CASE "3"
    CALL tutor1
  CASE ELSE
END SELECT
END SUB

SUB bpshell
DIM qj1(10569), qj2(10569)
VIEW
GET (1, 75)-(310, 345), qj1
GET (310, 75)-(619, 345), qj2
CLS
SHELL
PUT (1, 75), qj1, PSET
PUT (310, 75), qj2, PSET
VIEW (1, 75)-(619, 345), , 15
END SUB

SUB d16 (CHAR$, xx, xy, xc)
nn = FREEFILE
OPEN "hzk16" FOR RANDOM AS #nn LEN = 1
FIELD #nn, 1 AS f$
FOR k = 1 TO LEN(CHAR$) STEP 2
qm = ASC(MID$(CHAR$, k, 1)) - 161
wm = ASC(MID$(CHAR$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd16
r = (qm * 94 + wm) * 32 + 1
FOR xs = 0 TO 15
GET #nn, r: r = r + 1: LINE (xx + 7, xy + xs)-(xx - 8, xy + xs), xc, , ASC(f$)
GET #nn, r: r = r + 1: LINE (xx + 15, xy + xs)-(xx, xy + xs), xc, , ASC(f$)
NEXT xs
endd16: xx = xx + 16
NEXT k
CLOSE #nn
END SUB

SUB dbox (x, y, c, skip, f)
VIEW (1, 1)-(400, 70), , 15
CLS
CALL d16("°ïÖú£³£³£º»­·½¿ò", 8, 0, 14)
CALL d16("ÒÆ¶¯£º·½Ïò¼ü»òÊý×Ö¼ü  ¸Ä±äÑÕÉ«£º£µ", 8, 19, 11)
CALL d16("Ôö´óËõÐ¡µ¥Î»£º£Ó£¯£ó  ¿Õ¸ñ»­µã", 8, 35, 11)
CALL d16("»Ø³µ£º¶¨ÓÒÏÂ½Ç    £Å£ó£ã£ºÍË³ö", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
VIEW (1, 75)-(619, 345), , 15
oc = POINT(x, y)
dbox1: pk$ = INKEY$: IF pk$ = "" THEN GOTO dbox1
       PSET (x, y), oc
       SELECT CASE pk$
    CASE lu$, "7"
       x = x - skip: y = y - skip
    CASE u$, "8"
      y = y - skip
    CASE ru$, "9"
      x = x + skip: y = y - skip
    CASE l$, "4"
      x = x - skip
    CASE r$, "6"
      x = x + skip
    CASE ld$, "1"
      x = x - skip: y = y + skip
    CASE d$, "2"
      y = y + skip
    CASE rd$, "3"
      x = x + skip: y = y + skip
    CASE " "
       PSET (x, y), c
       WRITE #1, 1, x, y, c
    CASE "S"
      skip = skip - 1
    CASE "s"
      skip = skip + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE CHR$(13)
      PSET (x, y), c
    GOTO edbox1
    CASE CHR$(27)
      GOTO edbox
    CASE ELSE
END SELECT
      oc = POINT(x, y): PSET (x, y), c
LOCATE 3, 52: PRINT "X="; USING "###"; x;
PRINT "  Y="; USING "###"; y;
PRINT "  C="; USING "##"; c
LOCATE 4, 52: PRINT "S="; USING "###"; skip;
GOTO dbox1
edbox1:
VIEW (1, 1)-(400, 70), , 15
CLS
CALL d16("°ïÖú£³£³£º»­·½¿ò", 8, 0, 14)
CALL d16("ÒÆ¶¯£º·½Ïò¼ü»òÊý×Ö¼ü  ¸Ä±äÑÕÉ«£º£µ", 8, 19, 11)
CALL d16("Ôö´óËõÐ¡¾àÀë£º£Ó£¯£ó  ¿Õ¸ñ»­·½¿ò", 8, 35, 11)
CALL d16("»Ø³µ£º»­·½¿ò²¢ÍË³ö  £Å£ó£ã£ºÍË³ö", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
VIEW (1, 75)-(619, 345), , 15
xt = x: yt = y
oc = POINT(xt, yt)
dbox2: pk$ = INKEY$: IF pk$ = "" THEN GOTO dbox2
       PSET (xt, yt), oc
       SELECT CASE pk$
    CASE lu$, "7"
       xt = xt - skip: yt = yt - skip
    CASE u$, "8"
      yt = yt - skip
    CASE ru$, "9"
      xt = xt + skip: yt = yt - skip
    CASE l$, "4"
      xt = xt - skip
    CASE r$, "6"
      xt = xt + skip
    CASE ld$, "1"
      xt = xt - skip: yt = yt + skip
    CASE d$, "2"
      yt = yt + skip
    CASE rd$, "3"
      xt = xt + skip: yt = yt + skip
    CASE " "
       IF f = 0 THEN LINE (x, y)-(xt, yt), c, B
       IF f = 1 THEN LINE (x, y)-(xt, yt), c, BF
       IF f = 0 THEN WRITE #1, 2, "B", x, y, xt, yt, c
       IF f = 1 THEN WRITE #1, 2, "F", x, y, xt, yt, c
    CASE "S"
      skip = skip - 1
    CASE "s"
      skip = skip + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE CHR$(13)
       IF f = 0 THEN LINE (x, y)-(xt, yt), c, B
       IF f = 1 THEN LINE (x, y)-(xt, yt), c, BF
       IF f = 0 THEN WRITE #1, 2, "B", x, y, xt, yt, c
       IF f = 1 THEN WRITE #1, 2, "F", x, y, xt, yt, c
    GOTO edbox
    CASE CHR$(27)
       GOTO edbox
    CASE ELSE
END SELECT
      oc = POINT(xt, yt): PSET (xt, yt), c
LOCATE 3, 52: PRINT "X="; USING "###"; xt;
PRINT "  Y="; USING "###"; yt;
PRINT "  C="; USING "##"; c
LOCATE 4, 52: PRINT "S="; USING "###"; skip;
VIEW (405, 1)-(619, 70), , 15
LINE (190, 60)-(212, 68), c, BF
VIEW (1, 75)-(619, 345), , 15
GOTO dbox2
edbox:
END SUB

SUB dcircle (x, y, c, skip, f)
VIEW (1, 1)-(400, 70), , 15
CLS : zhb = 1
CALL d16("°ïÖú£³£´£º»­Ô²", 8, 0, 14)
CALL d16("ÒÆ¶¯£º·½Ïò¼ü»òÊý×Ö¼ü  ¸Ä±äÑÕÉ«£º£µ", 8, 19, 11)
CALL d16("Ôö´óËõÐ¡µ¥Î»£º£Ó£¯£ó  ¿Õ¸ñ»­µã", 8, 35, 11)
CALL d16("»Ø³µ£º¶¨°ë¾¶£Ò    £Å£ó£ã£ºÍË³ö", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
VIEW (1, 75)-(619, 345), , 15
oc = POINT(x, y)
dcir1: pk$ = INKEY$: IF pk$ = "" THEN GOTO dcir1
       PSET (x, y), oc
       SELECT CASE pk$
    CASE lu$, "7"
       x = x - skip: y = y - skip
    CASE u$, "8"
      y = y - skip
    CASE ru$, "9"
      x = x + skip: y = y - skip
    CASE l$, "4"
      x = x - skip
    CASE r$, "6"
      x = x + skip
    CASE ld$, "1"
      x = x - skip: y = y + skip
    CASE d$, "2"
      y = y + skip
    CASE rd$, "3"
      x = x + skip: y = y + skip
    CASE " "
       PSET (x, y), c
       WRITE #1, 1, x, y, c
    CASE "S"
      skip = skip - 1
    CASE "s"
      skip = skip + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE CHR$(13)
      PSET (x, y), c
    GOTO edcir1
    CASE CHR$(27)
      GOTO edcir
    CASE ELSE
END SELECT
      oc = POINT(x, y): PSET (x, y), c
LOCATE 3, 52: PRINT "X="; USING "###"; x;
PRINT "  Y="; USING "###"; y;
PRINT "  C="; USING "##"; c
LOCATE 4, 52: PRINT "S="; USING "###"; skip;
VIEW (405, 1)-(619, 70), , 15
LINE (190, 60)-(212, 68), c, BF
VIEW (1, 75)-(619, 345), , 15
GOTO dcir1
edcir1:
VIEW (1, 1)-(400, 70), , 15
CLS
CALL d16("°ïÖú£³£´£º»­Ô²¡ª¶¨°ë¾¶", 8, 0, 14)
CALL d16("ÒÆ¶¯£º·½Ïò¼ü»òÊý×Ö¼ü  ¸Ä±äÑÕÉ«£º£µ", 8, 19, 11)
CALL d16("Ôö´óËõÐ¡µ¥Î»£º£Ó£¯£ó  ¿Õ¸ñ»­Ô²", 8, 35, 11)
CALL d16("»Ø³µ£º»­Ô²²¢ÍË³ö  £Å£ó£ã£ºÍË³ö", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
VIEW (1, 75)-(619, 345), , 15
xt = x: yt = y
oc = POINT(xt, yt)
dcir2: pk$ = INKEY$: IF pk$ = "" THEN GOTO dcir2
       PSET (xt, yt), oc
       SELECT CASE pk$
    CASE lu$, "7"
       xt = xt - skip: yt = yt - skip
    CASE u$, "8"
      yt = yt - skip
    CASE ru$, "9"
      xt = xt + skip: yt = yt - skip
    CASE l$, "4"
      xt = xt - skip
    CASE r$, "6"
      xt = xt + skip
    CASE ld$, "1"
      xt = xt - skip: yt = yt + skip
    CASE d$, "2"
      yt = yt + skip
    CASE rd$, "3"
      xt = xt + skip: yt = yt + skip
    CASE "T"
      zhb = zhb + .001
    CASE "t"
      zhb = zhb - .001
    CASE " "
       PSET (x, y), 0
       CIRCLE (x, y), SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c, 0, 2 * 3.1415926535897#, zhb
       IF f = 1 THEN PAINT (x, y), c
       IF f = 0 THEN WRITE #1, 3, "O", x, y, SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c, 0, 2 * 3.1415926535897#, zhb
       IF f = 1 THEN WRITE #1, 3, "*", x, y, SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c, 0, 2 * 3.1415926535897#, zhb: WRITE #1, 4, x, y, c, c
    CASE "S"
      skip = skip - 1
    CASE "s"
      skip = skip + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE CHR$(13)
       PSET (x, y), 0
       CIRCLE (x, y), SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c, 0, 2 * 3.1415926535897#, zhb
       IF f = 1 THEN PAINT (x, y), c
       IF f = 0 THEN WRITE #1, 3, "O", x, y, SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c, 0, 2 * 3.1415926535897#, zhb
       IF f = 1 THEN WRITE #1, 3, "*", x, y, SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c, 0, 2 * 3.1415926535897#, zhb: WRITE #1, 4, x, y, c, c
    GOTO edcir
    CASE CHR$(27)
       GOTO edcir
    CASE ELSE
END SELECT
      oc = POINT(xt, yt): PSET (xt, yt), c
LOCATE 3, 52: PRINT "X="; USING "###"; xt;
PRINT "  Y="; USING "###"; yt;
PRINT "  C="; USING "##"; c
LOCATE 4, 52: PRINT "S="; USING "###"; skip;
PRINT "  R="; USING "###"; SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2);
PRINT "  Y/X="; USING "#.###"; zhb
VIEW (405, 1)-(619, 70), , 15
LINE (190, 60)-(212, 68), c, BF
VIEW (1, 75)-(619, 345), , 15
GOTO dcir2
edcir:
END SUB

SUB dclear
DIM qj1(10569), qj2(10569)
VIEW
GET (1, 75)-(310, 345), qj1
GET (310, 75)-(619, 345), qj2
CLS
PUT (1, 75), qj1, PSET
PUT (310, 75), qj2, PSET
VIEW (1, 75)-(619, 345), , 15
END SUB

SUB dir
VIEW PRINT 1 TO 6
nn = FREEFILE
FILES
CALL ur(t$)
CLS 2
VIEW PRINT
END SUB

SUB dline (x, y, c, s)
VIEW (1, 1)-(400, 70), , 15
CLS
CALL d16("°ïÖú£³£²£º»­Ïß¡ªÆðµã", 8, 0, 14)
CALL d16("ÒÆ¶¯£º·½Ïò¼ü»òÊý×Ö¼ü  ¸Ä±äÑÕÉ«£º£µ", 8, 19, 11)
CALL d16("Ôö´óËõÐ¡µ¥Î»£º£Ó£¯£ó  ¿Õ¸ñ»­µã", 8, 35, 11)
CALL d16("»Ø³µ£º¶¨ÖÕÖ¹µã    £Å£ó£ã£ºÍË³ö", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
VIEW (1, 75)-(619, 345), , 15
oc = POINT(x, y)
dline1: pk$ = INKEY$: IF pk$ = "" THEN GOTO dline1
       PSET (x, y), oc
       SELECT CASE pk$
    CASE lu$, "7"
       x = x - skip: y = y - skip
    CASE u$, "8"
      y = y - skip
    CASE ru$, "9"
      x = x + skip: y = y - skip
    CASE l$, "4"
      x = x - skip
    CASE r$, "6"
      x = x + skip
    CASE ld$, "1"
      x = x - skip: y = y + skip
    CASE d$, "2"
      y = y + skip
    CASE rd$, "3"
      x = x + skip: y = y + skip
    CASE " "
       PSET (x, y), c
       WRITE #1, 1, x, y, c
    CASE "S"
      skip = skip - 1
    CASE "s"
      skip = skip + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE CHR$(13)
      PSET (x, y), c
    GOTO edline1
    CASE CHR$(27)
      GOTO edline
    CASE ELSE
END SELECT
      oc = POINT(x, y): PSET (x, y), c
LOCATE 3, 52: PRINT "X="; USING "###"; x;
PRINT "  Y="; USING "###"; y;
PRINT "  C="; USING "##"; c
LOCATE 4, 52: PRINT "S="; USING "###"; skip;
GOTO dline1
edline1:
VIEW (1, 1)-(400, 70), , 15
CLS
CALL d16("°ïÖú£³£²£º»­Ïß¡ªÖÕµã", 8, 0, 14)
CALL d16("ÒÆ¶¯£º·½Ïò¼ü»òÊý×Ö¼ü  ¸Ä±äÑÕÉ«£º£µ", 8, 19, 11)
CALL d16("Ôö´óËõÐ¡µ¥Î»£º£Ó£¯£ó  ¿Õ¸ñ»­Ïß", 8, 35, 11)
CALL d16("»Ø³µ£º»­Ïß²¢ÍË³ö  £Å£ó£ã£ºÍË³ö", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
VIEW (1, 75)-(619, 345), , 15
xt = x: yt = y
oc = POINT(xt, yt)
dline2: pk$ = INKEY$: IF pk$ = "" THEN GOTO dline2
       PSET (xt, yt), oc
       SELECT CASE pk$
    CASE lu$, "7"
       xt = xt - skip: yt = yt - skip
    CASE u$, "8"
      yt = yt - skip
    CASE ru$, "9"
      xt = xt + skip: yt = yt - skip
    CASE l$, "4"
      xt = xt - skip
    CASE r$, "6"
      xt = xt + skip
    CASE ld$, "1"
      xt = xt - skip: yt = yt + skip
    CASE d$, "2"
      yt = yt + skip
    CASE rd$, "3"
      xt = xt + skip: yt = yt + skip
    CASE " "
       LINE (x, y)-(xt, yt), c
       WRITE #1, 2, "&", x, y, xt, yt, c
    CASE "S"
      skip = skip - 1
    CASE "s"
      skip = skip + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE CHR$(13)
       LINE (x, y)-(xt, yt), c
       WRITE #1, 2, "&", x, y, xt, yt, c
    GOTO edline
    CASE CHR$(27)
       GOTO edline
    CASE ELSE
END SELECT
      oc = POINT(xt, yt): PSET (xt, yt), c
LOCATE 3, 52: PRINT "X="; USING "###"; xt;
PRINT "  Y="; USING "###"; yt;
PRINT "  C="; USING "##"; c
LOCATE 4, 52: PRINT "S="; USING "###"; skip;
VIEW (405, 1)-(619, 70), , 15
LINE (190, 60)-(212, 68), c, BF
VIEW (1, 75)-(619, 345), , 15
GOTO dline2
edline:
END SUB

SUB dlt
DIM tname$(1 TO 28), txznum%(1 TO 28), tnum%(1 TO 25)
DIM qj1(10569), qj2(10569), qj(5000)
VIEW
GET (1, 75)-(310, 345), qj1
GET (310, 75)-(619, 345), qj2
PUT (1, 75), qj1, PSET
PUT (310, 75), qj2, PSET
p = 3.14159 / 180
startlt:
       VIEW (1, 1)-(500, 70), , 15: CLS
       LOCATE 2, 3: INPUT "3DT Filename:", f$
       f$ = f$ + ".3DT"
       CALL toup(f$)
       rs% = 0
       CALL fb(f$, rs%)
       IF rs% = 0 THEN GOTO ed3dt
       CALL IIAB(f$, yn%)
       IF yn = 1 THEN GOTO ed3dt
       OPEN f$ FOR INPUT AS #2
       INPUT #2, bsf$
       IF bsf$ <> "ÿÿ3DTÿ" THEN LOCATE 3, 3: PRINT "This file isn't a right 3DT file": CLOSE #2
       INPUT #2, tnum%
       IF tnum% > 28 THEN GOTO ed3dt
       CLS
       FOR fdim% = 1 TO tnum%
         INPUT #2, tmp$, tmp%
         tname$(fdim%) = tmp$
         txznum%(fdim%) = tmp%
         LOCATE 2 + INT((fdim% - 1) / 7), 3 + ((fdim% - 1) MOD 7) * 8: PRINT USING "##"; fdim%; : PRINT "."; USING "&&&&&&"; tmp$
       NEXT fdim%
       CLOSE #2
do3xz: LOCATE 5, 65: INPUT "Select:", xm%
       IF xm% > tnum% OR xm% < 1 THEN GOTO do3xz
       DIM ox4(txznum%(xm%)), oy4(txznum%(xm%)), ofs$(txznum%(xm%))
       yr = 0: xr = 0: zr = 0: yrr = yr: xrr = xr: zrr = zr
       VIEW (505, 1)-(619, 70), , 15: CLS
       s% = 1: zo = 1: c = 15
aj:    IF dr% = 1 THEN GOTO ed3dt
       k$ = INKEY$: IF k$ = "" THEN GOTO aj
       SELECT CASE k$
       CASE "E", "e"
         GOTO ed3dt
       CASE "Y"
         yrr = yrr + s%
       CASE "y"
         yrr = yrr - s%
       CASE "X"
         xrr = xrr + s%
       CASE "x"
         xrr = xrr - s%
       CASE "Z"
         zrr = zrr + s%
       CASE "z"
         zrr = zrr - s%
       CASE "S"
         s% = s% + 1
       CASE "s"
         s% = s% - 1
       CASE "+"
         zo = zo * 1.01
       CASE "-"
         zo = zo * .99
       CASE l$
         ax% = ax% - skip
       CASE r$
         ax% = ax% + skip
       CASE d$
         ay% = ay% + skip
       CASE u$
         ay% = ay% - skip
       CASE "C"
         IF c < 15 THEN c = c + 1
       CASE "c"
         IF c > 0 THEN c = c - 1
       CASE CHR$(13)
         dr% = 1
       CASE ELSE
       END SELECT
       LOCATE 2, 3: PRINT "Skip="; s%, "Zoom="; zo, "X="; ax%, "Y="; ay%, "C="; c
       xr = xrr: yr = yrr: zr = zrr
       yr = yr * p: xr = xr * p: zr = zr * p
       FOR i% = 1 TO txznum%(xm%)
         IF ofs$(i%) = "p" THEN PSET (ox4(i%) + oax%, oy4(i%) + oay%), 0 ELSE IF ofs$(i%) = "l" THEN LINE -(ox4(i%) + oax%, oy4(i%) + oay%), 0
       NEXT i%
       OPEN f$ FOR INPUT AS #2
       INPUT #2, tmp$, tmp%
         FOR jumperror% = 1 TO tmp%
           INPUT #2, tmpp$, tmpp%
         NEXT jumperror%
         FOR jumperror% = 1 TO xm% - 1
         INPUT #2, tmpp$
           FOR jumperror1% = 1 TO tnum%(jumperror%)
             INPUT #2, tmpp%, tmpp%, tmpp%, tmpp$
           NEXT jumperror1%
         NEXT jumperror%
       INPUT #2, tmp%
FOR i% = 1 TO txznum%(xm%)
  INPUT #2, x1, y1, z1, fs$
  x1 = x1 * zo: y1 = y1 * zo: z1 = z1 * zo
  GOSUB 201
  IF fs$ = "p" THEN PSET (x4 + ax%, y4 + ay%), c ELSE IF fs$ = "l" THEN LINE -(x4 + ax%, y4 + ay%), c
  ox4(i%) = x4: oy4(i%) = y4: ofs$(i%) = fs$: oax% = ax%: oay% = ay%
NEXT i%
CLOSE #2
GOTO aj
VIEW (1, 75)-(619, 345), , 15
201 y2 = y1
x2 = x1 * COS(yr) - z1 * SIN(yr)
z2 = x1 * SIN(yr) + z1 * COS(yr)
y3 = z2 * SIN(xr) + y2 * COS(xr)
x3 = x2
z3 = z2 * COS(xr) - y2 * SIN(xr)
y4 = y3 * COS(zr) - x3 * SIN(zr)
x4 = y3 * SIN(zr) + x3 * COS(zr)
z4 = z3
RETURN
ed3dt:
GET (0, 0)-(114, 69), qj: VIEW: CLS
PUT (1, 75), qj1, PSET
PUT (310, 75), qj2, PSET
VIEW (1, 75)-(619, 345), , 15
ox = x: oy = y
PUT (ox, oy), qj
dlt: pk$ = INKEY$: IF pk$ = "" THEN GOTO dlt
PUT (ox, oy), qj
SELECT CASE pk$
    CASE lu$, "7"
       IF x - skip > 0 THEN x = x - skip
       IF y - skip > 0 THEN y = y - skip
    CASE u$, "8"
       IF y - skip > 0 THEN y = y - skip
    CASE ru$, "9"
       IF x + skip < 505 THEN x = x + skip
       IF y - skip > 0 THEN y = y - skip
    CASE l$, "4"
       IF x - skip > 0 THEN x = x - skip
    CASE r$, "6"
       IF x + skip < 505 THEN x = x + skip
    CASE ld$, "1"
       IF x - skip > 0 THEN x = x - skip
       IF y + skip < 202 THEN y = y + skip
    CASE d$, "2"
       IF y + skip < 202 THEN y = y + skip
    CASE rd$, "3"
       IF x + skip < 505 THEN x = x + skip
       IF y + skip < 202 THEN y = y + skip
    CASE " "
       PUT (x, y), qj
       dx = x: dy = y
       OPEN f$ FOR INPUT AS #2
       INPUT #2, tmp$, tmp%
         FOR jumperror% = 1 TO tmp%
           INPUT #2, tmpp$, tmpp%
         NEXT jumperror%
         FOR jumperror% = 1 TO xm% - 1
         INPUT #2, tmpp$
           FOR jumperror1% = 1 TO tnum%(jumperror%)
             INPUT #2, tmpp%, tmpp%, tmpp%, tmpp$
           NEXT jumperror1%
         NEXT jumperror%
       INPUT #2, tmp%
FOR i% = 1 TO txznum%(xm%)
  INPUT #2, x1, y1, z1, fs$
  x1 = x1 * zo: y1 = y1 * zo: z1 = z1 * zo
  GOSUB 201
  IF fs$ = "p" THEN WRITE #1, 1, INT(x4 + dx), INT(y4 + dy), c ELSE WRITE #1, 2, "-", INT(x4 + dx), INT(y4 + dy), c
NEXT i%
CLOSE #2
    CASE "S"
      skip = skip - 1
    CASE "s"
      skip = skip + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE CHR$(13)
       PUT (x, y), qj
       dx = x: dy = y
       OPEN f$ FOR INPUT AS #2
       INPUT #2, tmp$, tmp%
         FOR jumperror% = 1 TO tmp%
           INPUT #2, tmpp$, tmpp%
         NEXT jumperror%
         FOR jumperror% = 1 TO xm% - 1
         INPUT #2, tmpp$
           FOR jumperror1% = 1 TO tnum%(jumperror%)
             INPUT #2, tmpp%, tmpp%, tmpp%, tmpp$
           NEXT jumperror1%
         NEXT jumperror%
       INPUT #2, tmp%
FOR i% = 1 TO txznum%(xm%)
  INPUT #2, x1, y1, z1, fs$
  x1 = x1 * zo: y1 = y1 * zo: z1 = z1 * zo
  GOSUB 201
  IF fs$ = "p" THEN WRITE #1, 1, INT(x4 + dx), INT(y4 + dy), c ELSE WRITE #1, 2, "-", INT(x4 + dx), INT(y4 + dy), c
NEXT i%
CLOSE #2
    GOTO edlt
    CASE CHR$(27)
    GOTO edlt
    CASE ELSE
END SELECT
    PUT (x, y), qj
    ox = x: oy = y
LOCATE 3, 52: PRINT "X="; USING "###"; x;
PRINT "  Y="; USING "###"; y;
LOCATE 4, 52: PRINT "S="; USING "###"; skip;
GOTO dlt
edlt:
END SUB

SUB dother


END SUB

SUB dpaint (x, y, c, s)
VIEW (1, 1)-(400, 70), , 15
CLS : bc = c
CALL d16("°ïÖú£³£µ£ºÍ¿É«", 8, 0, 14)
CALL d16("ÒÆ¶¯£º·½Ïò¼ü»òÊý×Ö¼ü  ¸Ä±äÍ¿É«£¯±ßÉ«£º£ã£¯£Ã", 8, 19, 11)
CALL d16("Ôö´óËõÐ¡¾àÀë£º£Ó£¯£ó  ¿Õ¸ñÍ¿É«", 8, 35, 11)
CALL d16("»Ø³µ£ºÍ¿É«²¢ÍË³ö  £Å£ó£ã£ºÍË³ö", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
VIEW (1, 75)-(619, 345), , 15
oc = POINT(x, y)
dpaint: pk$ = INKEY$: IF pk$ = "" THEN GOTO dpaint
       PSET (x, y), oc
       SELECT CASE pk$
    CASE lu$, "7"
       x = x - skip: y = y - skip
    CASE u$, "8"
      y = y - skip
    CASE ru$, "9"
      x = x + skip: y = y - skip
    CASE l$, "4"
      x = x - skip
    CASE r$, "6"
      x = x + skip
    CASE ld$, "1"
      x = x - skip: y = y + skip
    CASE d$, "2"
      y = y + skip
    CASE rd$, "3"
      x = x + skip: y = y + skip
    CASE " "
       PAINT (x, y), c, bc
       WRITE #1, 4, x, y, c, bc
    CASE "S"
      skip = skip - 1
    CASE "s"
      skip = skip + 1
    CASE "C"
      IF bc < 15 THEN bc = bc + 1 ELSE bc = 0
    CASE "c"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE CHR$(13)
      PAINT (x, y), c, bc
      WRITE #1, 4, x, y, c, bc
    GOTO edpaint
    CASE CHR$(27)
    GOTO edpaint
    CASE ELSE
END SELECT
      oc = POINT(x, y): PSET (x, y), c
LOCATE 3, 52: PRINT "X="; USING "###"; x;
PRINT "  Y="; USING "###"; y;
PRINT " TC="; USING "##"; c;
PRINT " BC="; USING "##"; bc
LOCATE 4, 52: PRINT "S="; USING "###"; skip;
VIEW (1, 75)-(619, 345), , 15
GOTO dpaint
edpaint:
END SUB

SUB dpm
startdpm:
VIEW (1, 1)-(400, 70), , 15
CLS
CALL d16("£Â£Á£Ó£É£Ã³ÌÐòÉú³ÉÆ÷  ÖÆ×÷£ºÐ»¼ÌÀ×  °æ±¾£±£®£°£°", 8, 0, 14)
CALL d16("    £±¡ª»­µã  £³¡ª»­¿ÕÐÄ·½¿ò  £¶¡ª»­ÊµÐÄÔ²", 8, 19, 11)
CALL d16("    £²¡ª»­Ïß  £´¡ª»­ÊµÐÄ·½¿ò  £·¡ªÍ¿É«", 8, 35, 11)
CALL d16("    £°¡ªÍË³ö  £µ¡ª»­¿ÕÐÄÔ²    £¸¡ªÊäÈëÎÄ×Ö", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
2 CALL ur(s$)
  SELECT CASE s$
    CASE "1"
      CALL dpset(x, y, c, skip)
    CASE "2"
      CALL dline(x, y, c, skip)
    CASE "3"
      CALL dbox(x, y, c, skip, 0)
    CASE "4"
      CALL dbox(x, y, c, skip, 1)
    CASE "5"
      CALL dcircle(x, y, c, skip, 0)
    CASE "6"
      CALL dcircle(x, y, c, skip, 1)
    CASE "7"
      CALL dpaint(x, y, c, skip)
    CASE "8"
      CALL dtext(tx, ty, tc)
    CASE CHR$(27), "0"
      GOTO enddpm
    CASE ELSE
      GOTO 2
  END SELECT
  GOTO startdpm:
enddpm:

END SUB

SUB dpset (x, y, c, skip)
VIEW (1, 1)-(400, 70), , 15
CLS
CALL d16("°ïÖú£³£±£º»­µã", 8, 0, 14)
CALL d16("ÒÆ¶¯£º·½Ïò¼ü»òÊý×Ö¼ü  ¸Ä±äÑÕÉ«£º£µ", 8, 19, 11)
CALL d16("Ôö´óËõÐ¡µ¥Î»£º£Ó£¯£ó  ¿Õ¸ñ»­µã", 8, 35, 11)
CALL d16("»Ø³µ£º»­µã²¢ÍË³ö  £Å£ó£ã£ºÍË³ö", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
VIEW (1, 75)-(619, 345), , 15
oc = POINT(x, y)
dpset: pk$ = INKEY$: IF pk$ = "" THEN GOTO dpset
       PSET (x, y), oc
       SELECT CASE pk$
    CASE lu$, "7"
       x = x - skip: y = y - skip
    CASE u$, "8"
      y = y - skip
    CASE ru$, "9"
      x = x + skip: y = y - skip
    CASE l$, "4"
      x = x - skip
    CASE r$, "6"
      x = x + skip
    CASE ld$, "1"
      x = x - skip: y = y + skip
    CASE d$, "2"
      y = y + skip
    CASE rd$, "3"
      x = x + skip: y = y + skip
    CASE " "
       PSET (x, y), c
       WRITE #1, 1, x, y, c
    CASE "S"
      skip = skip - 1
    CASE "s"
      skip = skip + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE CHR$(13)
      PSET (x, y), c
      WRITE #1, 1, x, y, c
    GOTO edpset
    CASE CHR$(27)
    GOTO edpset
    CASE ELSE
END SELECT
      oc = POINT(x, y): PSET (x, y), c
LOCATE 3, 52: PRINT "X="; USING "###"; x;
PRINT "  Y="; USING "###"; y;
PRINT "  C="; USING "##"; c
LOCATE 4, 52: PRINT "S="; USING "###"; skip;
VIEW (405, 1)-(619, 70), , 15
LINE (190, 60)-(212, 68), c, BF
VIEW (1, 75)-(619, 345), , 15
GOTO dpset
edpset:
END SUB

SUB ds
END SUB

SUB dtext (tex, tey, tec)
DIM fk(70)
VIEW (1, 75)-(619, 345), , 15
dtext: k$ = INKEY$: IF k$ = "" THEN GOTO dtext
GET (x - 1, y - 1)-(x + 15, y + 15), fk
SELECT CASE k$
  CASE lu$
  CASE u$
  CASE ru$
  CASE l$
  CASE r$
  CASE ld$
  CASE d$, CHR$(13)
  CASE rd$
  CASE CHR$(27)
    GOTO edtext
  CASE ELSE
    zf$ = k$
END SELECT
LOCATE 3, 52: PRINT "X="; USING "##"; tex - 1;
PRINT "  Y="; USING "##"; tey - 6;
PRINT "  C="; USING "##"; tec
IF zf$ = CHR$(8) THEN IF tex > 2 THEN tex = tex - skip: zf$ = " ": lg = 1
LOCATE oldy, oldx: PRINT old$
IF zf$ <> "" AND tey < 24 THEN LOCATE tey, tex: COLOR tec: PRINT zf$: zf$ = "": IF lg <> 1 THEN tex = tex + skip: IF tex = 78 THEN tex = 2: tey = tey + skip: IF tey = 24 THEN tey = 254
old$ = CHR$(SCREEN(tey, tex))
oldx = tex: oldy = tey
LOCATE tey, tex: PRINT CHR$(3)
GOTO dtext
edtext:
END SUB

SUB fb (f$, rst%)
SHELL "dir/b >context.dat"
fwjh = FREEFILE
OPEN "context.dat" FOR INPUT AS fwjh
DO WHILE NOT EOF(fwjh)
INPUT #fwjh, tempf$
IF tempf$ = f$ THEN rst% = 1
LOOP
CLOSE #fwjh
END SUB

SUB finh
CLS
CLOSE
END
END SUB

SUB games
DIM qj1(10569), qj2(10569)
VIEW
GET (1, 75)-(310, 345), qj1
GET (310, 75)-(619, 345), qj2
PUT (1, 75), qj1, PSET
PUT (310, 75), qj2, PSET
VIEW (10, 10)-(400, 100), , 15
300 CLS
LOCATE 2, 3: COLOR 11, 0: PRINT "  W o r l d    W i n d o w skip    Ver 3.00"
LOCATE 3, 3: COLOR 10, 0: PRINT "    1 --- Guess v1.00"
LOCATE 4, 3: COLOR 10, 0: PRINT "    2 --- StarStarStars!"
LOCATE 5, 3: COLOR 10, 0: PRINT "    0 --- Exit"
games: k$ = INKEY$: IF k$ = "" THEN GOTO games
SELECT CASE k$
  CASE "1"
  CLS
  LOCATE 2, 3: PRINT "Guess Version:1.00"
  LOCATE 3, 3: INPUT "What's the MAX Num?", max
  max$ = STR$(max)
  sz = LEN(max$)
  ps = (sz + 1) ^ 2
  n = INT(RND * max)
301 LOCATE 2, 35: PRINT "Max="; max
  LOCATE 3, 35: PRINT "Lifes="; ps
  LOCATE 4, 3: INPUT "What's me"; nn
  IF nn > n THEN LOCATE 5, 3: PRINT "Too big!": ps = ps - 1
  IF nn < n THEN LOCATE 5, 3: PRINT "Too Small!": ps = ps - 1
  IF ps <= 0 THEN LOCATE 5, 3: PRINT "You LOST!!!": GOTO 302
  IF nn = n THEN LOCATE 5, 3: PRINT "You are winner! Congratulation!": GOTO 302
GOTO 301
302 '
  CASE "2"
    CALL star4
  CASE "0"
   GOTO 303
  CASE ELSE
   LOCATE 7, 52: PRINT "Error!": BEEP
END SELECT
304 GOTO 300
303 '
VIEW
PUT (1, 75), qj1, PSET
PUT (310, 75), qj2, PSET
END SUB

SUB hand
       p = 1: mo$ = "Draw"
       LOCATE 7, 52: INPUT "Start x= ", x
       LOCATE 7, 52: INPUT "Start y= ", y
       LOCATE 7, 52: INPUT "Start colour:", c
       IF x = 0 AND y = 0 AND c = 0 THEN x = 250: y = 100: c = 15
       VIEW (10, 10)-(400, 100), , 15
       CLS
       LOCATE 3, 3: COLOR 11, 0: PRINT "         World Windows --- Hand Draw"
       LOCATE 4, 3: PRINT "  7  8  9   5 Change Colour   + Pest >"
       LOCATE 5, 3: PRINT "  4 way 6   0 Pen Up          - Pest <"
       LOCATE 6, 3: PRINT "  1  2  3   . Pen Down        / Paint"
       VIEW (10, 110)-(600, 330), , 15
       PSET (x, y), c
       DO
       LOCATE 7, 3: PRINT "X="; x; " Y="; y; " Colour="; c; " Step="; p; "  Mode:" + mo$;
121    k$ = INKEY$: IF k$ = "" THEN 121
       SELECT CASE k$
    CASE "7"
       x = x - p: y = y - p
    CASE "8"
      y = y - p
    CASE "9"
      x = x + p: y = y - p
    CASE "4"
      x = x - p
    CASE "6"
      x = x + p
    CASE "1"
      x = x - p: y = y + p
    CASE "2"
      y = y + p
    CASE "3"
      x = x + p: y = y + p
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE "+"
      p = p + 1
    CASE "-"
      IF p > 0 THEN p = p - 1 ELSE LOCATE 7, 70: PRINT "Error!": BEEP
    CASE "."
      mo$ = "Draw"
    CASE "0"
      mo$ = "Move"
    CASE "/"
      PAINT (x, y), c
      IF op = 0 THEN PRINT #1, "PAINT ("; x; ","; y; "),"; c ELSE PRINT #1, 6, x, y, c
    CASE ELSE
      EXIT DO
END SELECT
IF mo$ = "Draw" THEN IF op = 0 THEN PRINT #1, "PSET ("; x; ","; y; "),"; c:           ELSE PRINT #1, 1, x, y, c
IF mo$ = "Draw" THEN PSET (x, y), c
IF mo$ = "Move" THEN cc = POINT(x, y): FOR z = 1 TO 500: PSET (x, y), 15: PSET (x, y), cc: NEXT z
LOOP

END SUB

SUB help
VIEW (10, 10)-(400, 100), , 15
CLS
LOCATE 3, 3: PRINT "--------------------- Help --------------------"
LOCATE 4, 3: PRINT "  W o r l d   W i n d o w s      V e r 3 . 0 0"
LOCATE 5, 3: PRINT "  M a d e     X i e J i l e i"
LOCATE 6, 3: PRINT "  T h a n k s    f o r    y o u   u s e d"
LOCATE 7, 3: PRINT "-----------------------------------------------"
5 IF INKEY$ = "" THEN 5
END SUB

SUB IIAB (filename$, yn%)
yn% = 0
OPEN filename$ FOR BINARY AS #3 LEN = 1
FOR cscd% = 1 TO 10
GET #3, cscd%, zf%
IF zf% > 0 AND zf% < 10 THEN yn% = 1
IF zf% > 10 AND zf% < 13 THEN yn% = 1
IF zf% > 13 AND zf% < 32 THEN yn% = 1
IF zf% > 126 AND zf% < 255 THEN yn% = 1
NEXT
CLOSE #3
END SUB

SUB star4
VIEW (0, 0)-(639, 340)
CLS
10 CLS
20 INPUT "Your name", NA$
30 IF LEN(NA$) > 9 THEN PRINT "Too long!": GOTO 20
40 INPUT "Your age", AG
50 IF AG > 200 THEN PRINT "How are you? Do you ill?": GOTO 40
60 SCREEN 9: CLS : RANDOMIZE TIMER: k = 10: KK = 1000: l = 1: M = 5
70 l = 1: M = 5: x = 280: y = 150
80 FOR RE = 1 TO INT(l / 3) * 30
90 x = INT(545 * RND) + 3: y = INT(290 * RND) + 3
100 PSET (x, y), 4
110 NEXT RE
120 CLS : KK = KK + KK: FOR WH = 1 TO 150
131 x = INT(545 * RND) + 3: y = INT(290 * RND) + 3
140 PSET (x, y), 15
150 NEXT WH
160 FOR YE = 1 TO 200 - (l * 20)
170 x = INT(545 * RND) + 3: y = INT(290 * RND) + 3
180 PSET (x, y), 14
190 NEXT YE
200 k$ = INKEY$
210 LINE (550, 0)-(550, 400), 4
220 IF k$ = "4" THEN x = x - 1
230 IF k$ = "6" THEN x = x + 1
240 IF k$ = "8" THEN y = y - 1
250 IF k$ = "2" THEN y = y + 1
260 IF k$ = "1" THEN x = x - 1: y = y + 1
270 IF k$ = "3" THEN x = x + 1: y = y + 1
280 IF k$ = "7" THEN x = x - 1: y = y - 1
290 IF k$ = "9" THEN x = x + 1: y = y - 1
311 IF k$ = "u" THEN IF x > 550 THEN x = 300 ELSE IF x < 550 THEN x = 554
310 IF k$ <> "" THEN Bs = Bs + 1
320 IF k$ = CHR$(27) THEN 540
330 IF POINT(x, y) = 15 THEN s = s + 10
340 IF POINT(x, y) = 14 THEN M = M + 1: PLAY "t250l64cdefgab"
350 IF POINT(x, y) = 4 THEN M = M - 1: PLAY "t250l64ccddee"
360 IF x = 550 THEN M = M - 30: PLAY "t250l64o5bbaaggffeeddcc<bbaaggffeeddcc<baggffeeddcc<bbaaggffeeddcc<bbaaggffeeddcc"
370 IF M > k THEN PLAY "t250o2f16f16f16f16p8g16g16d16d16p8c16d16e16f8": k = M + 10
380 LOCATE 1, 71: PRINT "--NAME--": LOCATE 2, 70: PRINT NA$: LOCATE 3, 71: PRINT "--AGE--": LOCATE 4, 70: PRINT USING "##########"; AG
390 LOCATE 5, 70: PRINT "x="; USING "#######"; x: LOCATE 6, 70: PRINT "y="; USING "#######"; y: LOCATE 7, 70: PRINT "S="; USING "#######"; s
400 LOCATE 8, 70: PRINT "B="; USING "#######"; Bs: LOCATE 9, 70: PRINT "m="; USING "#######"; M: LOCATE 10, 70: PRINT "Level:": LOCATE 11, 70: PRINT USING "##########"; LE
410 IF M < 1 THEN PLAY "mbt200l32o2bagedfcbagedfcbagedfcbagedfco1c1": ' END
420 FOR o = 1 TO 20: PSET (x, y), 15: NEXT o: PSET (x, y), 0
430 IF s > KK THEN LE = LE + 1: GOTO 120
440 GOTO 200
450 OPEN NA$ FOR APPEND AS #1
460 PRINT #1, "Name  :", NA$
470 PRINT #1, "Age   :", AG
480 PRINT #1, "Foor  :", Bs
490 PRINT #1, "Score :", s
500 PRINT #1, "People:", M
510 PRINT #1, "Level :", LE
520 PRINT #1, "------------------------------------ TheEnd ------------------------------------"
530 PRINT #1, "------------------------ M a k i n g  :X i e J i l e i ------------------------"
540 '
END SUB

SUB tblock

END SUB

SUB toup (CHAR$) STATIC
FOR fone% = 1 TO LEN(CHAR$)
IF ASC(MID$(CHAR$, fone%, 1)) >= 97 AND ASC(MID$(CHAR$, fone%, 1)) <= 122 THEN MID$(CHAR$, fone%, 1) = CHR$(ASC(MID$(CHAR$, fone%, 1)) - 32)
NEXT fone%
END SUB

SUB tutor

END SUB

SUB tutor1

END SUB

SUB ur (aaa$)
ur: k$ = INKEY$: IF k$ = "" THEN GOTO ur
aaa$ = k$
END SUB

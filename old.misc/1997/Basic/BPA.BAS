COMMON SHARED lu$, u$, ru$, l$, r$, ld$, rd$, d$, skip
COMMON SHARED x, y, c
DECLARE SUB star4 ()
DECLARE SUB finh ()
DECLARE SUB games ()
DECLARE SUB dir ()
DECLARE SUB dline (x!, y!, c!, s!)
DECLARE SUB dpset (x!, y!, c!, s!)
DECLARE SUB tutor1 ()
DECLARE SUB d16 (char$, xx!, xy!, xc!)
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
CALL d16("    £°¡ªÍË³ö        £¿¡ª°ïÖú        £¡¡ªÐÝÏ¢", 8, 51, 11)
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

SUB d16 (char$, xx, xy, xc)
nn = FREEFILE
OPEN "hzk16" FOR RANDOM AS #nn LEN = 1
FIELD #nn, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
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
GOTO dbox2
edbox:
END SUB

SUB dcircle (x, y, c, skip, f)
VIEW (1, 1)-(400, 70), , 15
CLS
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
    CASE " "
       PSET (x, y), 0
       CIRCLE (x, y), SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c
       IF f = 1 THEN PAINT (x, y), c
       IF f = 0 THEN WRITE #1, 3, "O", x, y, SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c
       IF f = 1 THEN WRITE #1, 3, "*", x, y, SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c: WRITE #1, 4, x, y, c, c
    CASE "S"
      skip = skip - 1
    CASE "s"
      skip = skip + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE CHR$(13)
       PSET (x, y), 0
       CIRCLE (x, y), SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c
       IF f = 1 THEN PAINT (x, y), c
       IF f = 0 THEN WRITE #1, 3, "O", x, y, SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c
       IF f = 1 THEN WRITE #1, 3, "*", x, y, SQR(ABS(xt - x) ^ 2 + ABS(yt - y) ^ 2), c: WRITE #1, 4, x, y, c, c
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
GOTO dline2
edline:
END SUB

SUB dlt


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
VIEW (1, 75)-(619, 345), , 15
GOTO dpset
edpset:
END SUB

SUB ds
END SUB

SUB dtext (tex, tey, tec)
VIEW (1, 1)-(400, 70), , 15
CLS
CALL d16("°ïÖú£³£µ£ºÍ¿É«", 8, 0, 14)
CALL d16("ÒÆ¶¯£º·½Ïò¼ü»òÊý×Ö¼ü  ¸Ä±äÍ¿É«£¯±ßÉ«£º£ã£¯£Ã", 8, 19, 11)
CALL d16("Ôö´óËõÐ¡¾àÀë£º£Ó£¯£ó  ¿Õ¸ñÍ¿É«", 8, 35, 11)
CALL d16("»Ø³µ£ºÍ¿É«²¢ÍË³ö  £Å£ó£ã£ºÍË³ö", 8, 51, 11)
LINE (1, 17)-(400, 17), 15
VIEW (1, 75)-(619, 345), , 15
tex = 40: tey = 10: tec = 15
oldx = tex: oldy = tey
dtext: k$ = INKEY$: IF k$ = "" THEN GOTO dtext
lg = 0
SELECT CASE k$
  CASE lu$
    IF tex > 2 AND tey > 7 THEN tex = tex - 1: tey = tey - 1
  CASE u$
    IF tey > 7 THEN tey = tey - 1
  CASE ru$
    IF tex < 77 AND tey > 7 THEN tex = tex + 1: tey = tey - 1
  CASE l$
    IF tex > 2 THEN tex = tex - 1
  CASE r$
    IF tex < 77 THEN tex = tex + 1
  CASE ld$
    IF tex > 2 AND tey < 23 THEN tex = tex - 1: tey = tey + 1
  CASE d$, CHR$(13)
    IF tey < 23 THEN tey = tey + 1
  CASE rd$
    IF tex < 77 AND tey < 23 THEN tex = tex + 1: tey = tey + 1
  CASE CHR$(0) + CHR$(82)
    IF tec < 15 THEN tec = tec + 1
  CASE CHR$(0) + CHR$(83)
    IF tec > 0 THEN tec = tec - 1
  CASE CHR$(27)
    GOTO edtext
  CASE ELSE
    zf$ = k$
END SELECT
LOCATE 3, 52: PRINT "X="; USING "##"; tex - 1;
PRINT "  Y="; USING "##"; tey - 6;
PRINT "  C="; USING "##"; tec
IF zf$ = CHR$(8) THEN IF tex > 2 THEN tex = tex - 1: zf$ = " ": lg = 1
LOCATE oldy, oldx: PRINT old$
IF zf$ <> "" AND tey < 24 THEN LOCATE tey, tex: COLOR tec: PRINT zf$: zf$ = "": IF lg <> 1 THEN tex = tex + 1: IF tex = 78 THEN tex = 2: tey = tey + 1: IF tey = 24 THEN tey = 23
old$ = CHR$(SCREEN(tey, tex))
oldx = tex: oldy = tey
LOCATE tey, tex: PRINT CHR$(3)
GOTO dtext
edtext:
FOR y = 7 TO 23
  FOR x = 2 TO 77
    a$ = a$ + CHR$(SCREEN(y, x))
  NEXT x
  WRITE #1, 5, a$
  a$ = ""
NEXT y
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
OPEN filename$ FOR BINARY AS #5 LEN = 1
FOR cscd% = 1 TO 10
GET #5, cscd%, zf%
IF zf% > 0 AND zf% < 10 THEN yn% = 1
IF zf% > 10 AND zf% < 13 THEN yn% = 1
IF zf% > 13 AND zf% < 32 THEN yn% = 1
IF zf% > 126 AND zf% < 255 THEN yn% = 1
NEXT
CLOSE #5
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
410 IF M < 1 THEN PLAY "mbt200l32o2bagedfcbagedfcbagedfcbagedfco1c1": END
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

SUB toup (char$) STATIC
FOR fone% = 1 TO LEN(char$)
IF ASC(MID$(char$, fone%, 1)) >= 97 AND ASC(MID$(char$, fone%, 1)) <= 122 THEN MID$(char$, fone%, 1) = CHR$(ASC(MID$(char$, fone%, 1)) - 32)
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

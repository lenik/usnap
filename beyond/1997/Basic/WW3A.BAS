DECLARE SUB toup (char$)
DECLARE SUB IIAB (filename$, yn%)
DECLARE SUB pe ()
DECLARE SUB fb (f$, rst%)
DECLARE SUB star4 ()
DECLARE SUB finh ()
DECLARE SUB help ()
DECLARE SUB games ()
SCREEN 9
RANDOMIZE TIMER
DIM qj(10000)
COLOR 15, 0
LOCATE 7, 15: INPUT "Edit a world(.ww) file or a basic file(.bas)? [W/B)"; wb$
IF wb$ = "W" OR wb$ = "w" THEN op = 1
IF op = 1 THEN ext$ = ".WW" ELSE ext$ = ".BAS"
DIM opf$(1023)
CLOSE
nf$ = "UNKNOW" + ext$
OPEN nf$ FOR OUTPUT AS #1
IF op <> 6 THEN PRINT #1, "screen 9:cls" ELSE PRINT #1, "ww3"
CLS
begin:
DO
VIEW (10, 10)-(400, 100), , 15
LOCATE 2, 3: COLOR 11, 0: PRINT "  W o r l d    W i n d o w s    Ver 3.00"
LOCATE 3, 3: COLOR 10, 0: PRINT "    1 === Open      4 === DrawS  7 === Muisc"
LOCATE 4, 3: COLOR 10, 0: PRINT "    2 === New       5 === DrawM  8 === 3DBox"
LOCATE 5, 3: COLOR 10, 0: PRINT "    3 === Directory 6 === DrawL  9 --- PenHD"
LOCATE 6, 3: COLOR 10, 0: PRINT "    0 === Exit      ? === Help   & === Clear"
LOCATE 7, 3: COLOR 11, 0: PRINT "  ZheJiangYuhuanChumen PO.317605 ! === Rest!"
LOCATE 7, 52: PRINT SPACE$(28)
LINE (0, 17)-(400, 17), 15
VIEW (410, 10)-(600, 69), , 15
LOCATE 2, 57: COLOR 12, 0: PRINT "XJL-WW3.0"
LOCATE 3, 57: COLOR 13, 0: PRINT "MADE XIEJILEI"
LOCATE 4, 57: COLOR 13, 0: PRINT "1996.MAY.22nd"
nf$ = UCASE$(nf$)
LOCATE 5, 57: COLOR 13, 0: PRINT nf$ + SPACE$(13 - LEN(nf$))
FOR r = 1 TO 16
CIRCLE (17, 13), r, r
NEXT r
FOR r = 1 TO 16
CIRCLE (170, 13), r, r
NEXT r
LINE (0, 30)-(190, 30), 15
LINE (0, 43)-(190, 43), 15
VIEW (10, 110)-(600, 330), , 15
1 k$ = INKEY$
  IF k$ = "" THEN 1
  VIEW (10, 10)-(400, 100)
  CLS
  SELECT CASE k$
   CASE "1"
     LOCATE 2, 3: PRINT "   Open File"
     LOCATE 3, 3: PRINT "  1 === Open File"
     LOCATE 4, 3: PRINT "  0 === Exit"
       LOCATE 5, 3: INPUT x1
        IF x1 = 1 THEN k$ = "2"
        IF x1 = 0 THEN GOTO 88
   CASE "2"
     LOCATE 2, 3: PRINT "   New File"
     LOCATE 3, 3: PRINT "  1 === New File"
     LOCATE 4, 3: PRINT "  0 === Exit"
     LOCATE 5, 3: INPUT x1
        IF x1 = 1 THEN k$ = "1"
        IF x1 = 0 THEN GOTO 88
   CASE "3"
      k$ = "3"
   CASE "4"
      LOCATE 2, 3: PRINT "  Draw small picture"
      LOCATE 3, 4: PRINT "  1 === Draw Pset"
      LOCATE 4, 4: PRINT "  2 === Draw Line"
      LOCATE 5, 4: PRINT "  0 === Exit"
      LOCATE 6, 3: INPUT x1
        IF x1 = 1 THEN k$ = "4"
        IF x1 = 2 THEN k$ = "5"
        IF x1 = 0 THEN GOTO 88
   CASE "5"
      LOCATE 2, 3: PRINT "  Draw Middle picture"
      LOCATE 3, 4: PRINT "  1 === Draw Box"
      LOCATE 4, 4: PRINT "  2 === Draw Circle"
      LOCATE 5, 4: PRINT "  0 === Exit"
      LOCATE 6, 3: INPUT x1
        IF x1 = 1 THEN k$ = "6"
        IF x1 = 2 THEN k$ = "7"
        IF x1 = 0 THEN GOTO 88
   CASE "6"
      LOCATE 2, 3: PRINT "  Draw Large picture"
      LOCATE 3, 4: PRINT "  1 === Paint"
      LOCATE 4, 4: PRINT "  2 === Get Block"
      LOCATE 5, 4: PRINT "  3 === Put Block"
      LOCATE 6, 3: INPUT x1
        IF x1 = 1 THEN k$ = "8"
        IF x1 = 2 THEN k$ = "G"
        IF x1 = 3 THEN k$ = "P"
        IF x1 = 0 THEN GOTO 88
   CASE "7"
       k$ = "^"
       LOCATE 2, 3: PRINT "  Make Music        | Make Sound"
       LOCATE 3, 3: PRINT "  1 === Input Music | 4 === Make Sound"
       LOCATE 4, 3: PRINT "  2 === Test        | 5 === Test"
       LOCATE 5, 3: PRINT "  3 === Save        | 6 === Save"
       LOCATE 6, 3: PRINT "               0 === Exit"
       LOCATE 7, 3: INPUT x1
         IF x1 = 1 THEN LOCATE 7, 3: INPUT "Music:", M$
         IF x1 = 2 THEN PLAY "x" + VARPTR$(M$)
         IF x1 = 3 THEN PRINT #1, "PLAY " + CHR$(23) + M$ + CHR$(23)
         IF x1 = 4 THEN LOCATE 7, 3: INPUT "Voice,Speed", v, s
         IF x1 = 5 THEN SOUND v, s
         IF x1 = 6 THEN PRINT #1, "SOUND"; v; ","; s
         IF x1 = 0 THEN GOTO 88
     CASE "8"
       k$ = "~"
     CASE "9"
       k$ = "9"
     CASE "0"
       k$ = "0"
     CASE "?"
       k$ = "?"
     CASE "/"
       k$ = "/"
     CASE "&"
       k$ = "&"
     CASE "!"
       k$ = "!"
     CASE ELSE
       k$ = "="
130 END SELECT
      SELECT CASE k$
     CASE "1"
         LOCATE 7, 52: INPUT "New Filename:", nf$
         IF op = 0 THEN ext$ = ".BAS" ELSE IF op = 1 THEN ext$ = ".WW"
         nf$ = nf$ + ext$
         CLOSE
         ON ERROR GOTO 2
         OPEN nf$ FOR OUTPUT AS #1: GOTO 3
2        LOCATE 7, 70: PRINT "Error!": BEEP
3        IF op <> 1 THEN PRINT #1, "cls:view (10,110)-(600,330),,15" ELSE PRINT #1, "ww2"
     CASE "2"
         LOCATE 7, 52: INPUT "Open Filename :", opfn$
         op = 1: ext$ = ".WW"
         opfn$ = opfn$ + ext$
         CALL fb(opfn$, rst%)
         IF rst% <> 1 THEN CALL pe: GOTO 88
         OPEN opfn$ FOR INPUT AS #3
         INPUT #3, bz$
         IF bz$ <> "ww3" THEN CALL pe: CLOSE #3: GOTO 88
         VIEW (10, 110)-(600, 330)
         DO WHILE NOT EOF(3)
           INPUT #3, x$
             SELECT CASE x$
               CASE "1"
               INPUT #3, x, y, c
               PSET (x, y), c
               CASE "2"
               INPUT #3, x1, y1, x2, y2, c
               LINE (x1, y1)-(x2, y2), c
               CASE "3"
               INPUT #3, x1, y1, x2, y2, c
               LINE (x1, y1)-(x2, y2), c, B
               CASE "4"
               INPUT #3, x1, y1, x2, y2, c
               LINE (x1, y1)-(x2, y2), c, BF
               CASE "5"
               INPUT #3, x, y, r, c, q, z, t
               CIRCLE (x, y), r, c, q, z, t
               CASE "6"
               INPUT #3, x, y, c, bc
               PAINT (x, y), c, bc
               CASE "7"
               INPUT #3, x, y, c
               LINE -(x, y), c
               CASE ELSE
                LOCATE 7, 72: PRINT "Error!": BEEP
             END SELECT
         LOOP
         CLOSE #3
         OPEN opfn$ FOR APPEND AS #1
       CASE "3"
         ON ERROR GOTO 32
15       IF INKEY$ = "" THEN 15
         CLS
         SHELL "dir *.ww/b >context.dat"
         OPEN "context.dat" FOR INPUT AS #2
         x = 1
         DO WHILE NOT EOF(2)
         INPUT #2, opf$(x)
         x = x + 1
         LOOP
16       CLOSE #2
         FOR xx = 1 TO x STEP 5
         FOR B = xx TO xx + 5
         LOCATE B - xx + 2, 3: COLOR 15, 0: PRINT opf$(B)
         NEXT B
18       IF INKEY$ = "" THEN 18
         CLS
         NEXT xx
GOTO 33
32 LOCATE 7, 70: PRINT "Ver too low!"
33   CASE "4"
       LOCATE 7, 52: INPUT "Start X= ", x
       LOCATE 7, 52: INPUT "Start Y= ", y
       LOCATE 7, 52: INPUT "Start Colour: ", c
       IF x = 0 AND y = 0 AND c = 0 THEN x = 250: y = 100: c = 15
       IF x < 0 OR x > 570 OR y < 0 OR y > 230 OR c < 0 OR c > 15 THEN CALL pe: GOTO 88
       VIEW (10, 110)-(600, 330), , 15
dpset: pk$ = INKEY$: IF pk$ = "" THEN GOTO dpset
       PSET (x, y), oc
       SELECT CASE pk$
    CASE "7"
       x = x - 1: y = y - 1
    CASE "8"
      y = y - 1
    CASE "9"
      x = x + 1: y = y - 1
    CASE "4"
      x = x - 1
    CASE "6"
      x = x + 1
    CASE "1"
      x = x - 1: y = y + 1
    CASE "2"
      y = y + 1
    CASE "3"
      x = x + 1: y = y + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE CHR$(13)
      PSET (x, y), c
    GOTO edpest
    CASE ELSE
END SELECT
      oc = POINT(x, y): PSET (x, y), c
      LOCATE 7, 52: PRINT "Color=  "; c
GOTO dpset
edpest: IF op <> 1 THEN PRINT #1, "PSET ("; x; ","; y; ")" + ","; c:                 ELSE PRINT #1, 1; x; y; c
        GOTO 33
     CASE "5"
       LOCATE 7, 52: INPUT "START X=", x1
       LOCATE 7, 52: INPUT "START Y=", y1
       LOCATE 7, 52: INPUT "END X=", x2
       LOCATE 7, 52: INPUT "END Y=", y2
       LOCATE 7, 52: INPUT "COLOUR: ", c
       IF x1 = 0 AND y1 = 0 AND c = 0 AND x2 = 0 AND y2 = 0 THEN x1 = 250: y1 = 100: c = 15: x2 = 260: y2 = 110
       IF x1 <= 0 OR x1 > 530 OR x2 <= 0 OR x2 > 530 OR y1 <= 0 OR y1 > 230 OR y2 <= 0 OR y2 > 230 OR c < 0 OR c > 15 THEN CALL pe
       VIEW (10, 110)-(600, 330), , 15
       GET (0, 0)-(590, 220), qj
dline: pk$ = INKEY$: IF pk$ = "" THEN GOTO dline
       SELECT CASE pk$
    CASE "7"
       x1 = x1 - 1: y1 = y1 - 1
    CASE "8"
      y1 = y1 - 1
    CASE "9"
      x1 = x1 + 1: y1 = y1 - 1
    CASE "4"
      x1 = x1 - 1
    CASE "6"
      x1 = x1 + 1
    CASE "1"
      x1 = x1 - 1: y1 = y1 + 1
    CASE "2"
      y1 = y1 + 1
    CASE "3"
      x1 = x1 + 1: y1 = y1 + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE "Q", "q"
       x2 = x2 - 1: y2 = y2 - 1
    CASE "W", "w"
      y2 = y2 - 1
    CASE "E", "e"
      x2 = x2 + 1: y2 = y2 - 1
    CASE "A", "a"
      x2 = x2 - 1
    CASE "D", "d"
      x2 = x2 + 1
    CASE "Z", "z"
      x2 = x2 - 1: y2 = y2 + 1
    CASE "X", "x"
      y2 = y2 + 1
    CASE "C", "c"
      x2 = x2 + 1: y2 = y2 + 1
    CASE CHR$(13)
    GOTO edline
    CASE ELSE
END SELECT
      CLS : LINE (x1, y1)-(x2, y2), c
      LOCATE 7, 52: PRINT "Color=  "; c
GOTO dline
edline: IF op <> 1 THEN PRINT #1, "LINE ("; x1; ","; y1; ")-("; x2; ","; y2; "),"; c:                 ELSE PRINT #1, 2; x1; y1; x2; y2; c
       CLS
       PUT (0, 0), qj
       LINE (x1, y1)-(x2, y2), c
     CASE "6"
       LOCATE 7, 52: INPUT "LeftUp X=", x1
       LOCATE 7, 52: INPUT "LeftUp Y=", y1
       LOCATE 7, 52: INPUT "RightDown X=", x2
       LOCATE 7, 52: INPUT "RightDown Y=", y2
       LOCATE 7, 52: INPUT "COLOUR: ", c
       LOCATE 7, 52: INPUT "Paint?", pp$
       IF x1 = 0 AND y1 = 0 AND c = 0 AND x2 = 0 AND y2 = 0 THEN x1 = 250: y1 = 100: c = 15: x2 = 260: y2 = 110
       IF x1 <= 0 OR x1 > 530 OR x2 <= 0 OR x2 > 530 OR y1 <= 0 OR y1 > 230 OR y2 <= 0 OR y2 > 230 OR c < 0 OR c > 15 THEN LOCATE 7, 70: PRINT "Error!": BEEP
       IF pp$ = "Y" OR pp$ = "y" THEN pp$ = "BF" ELSE pp$ = "B"
       VIEW (10, 110)-(600, 330), , 15
       GET (0, 0)-(590, 220), qj
dbox: pk$ = INKEY$: IF pk$ = "" THEN GOTO dbox
       SELECT CASE pk$
    CASE "7"
       x1 = x1 - 1: y1 = y1 - 1
    CASE "8"
      y1 = y1 - 1
    CASE "9"
      x1 = x1 + 1: y1 = y1 - 1
    CASE "4"
      x1 = x1 - 1
    CASE "6"
      x1 = x1 + 1
    CASE "1"
      x1 = x1 - 1: y1 = y1 + 1
    CASE "2"
      y1 = y1 + 1
    CASE "3"
      x1 = x1 + 1: y1 = y1 + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE "Q", "q"
       x2 = x2 - 1: y2 = y2 - 1
    CASE "W", "w"
      y2 = y2 - 1
    CASE "E", "e"
      x2 = x2 + 1: y2 = y2 - 1
    CASE "A", "a"
      x2 = x2 - 1
    CASE "D", "d"
      x2 = x2 + 1
    CASE "Z", "z"
      x2 = x2 - 1: y2 = y2 + 1
    CASE "X", "x"
      y2 = y2 + 1
    CASE "C", "c"
      x2 = x2 + 1: y2 = y2 + 1
    CASE CHR$(13)
    GOTO edbox
    CASE ELSE
END SELECT
      CLS : IF pp$ = "B" THEN LINE (x1, y1)-(x2, y2), c, B ELSE IF pp$ = "BF" THEN LINE (x1, y1)-(x2, y2), c, BF
      LOCATE 7, 52: PRINT "Color=  "; c
GOTO dbox
edbox: IF op <> 1 THEN PRINT #1, "LINE ("; x1; ","; y1; ")-("; x2; ","; y2; "),"; c; "," + pp$:                 ELSE IF pp$ <> "B" THEN PRINT #1, 3; x1; y1; x2; y2; c ELSE PRINT #1, 4; x1; y1; x2; y2; c
       CLS
       PUT (0, 0), qj
       IF pp$ = "BF" THEN LINE (x1, y1)-(x2, y2), c, BF
       IF pp$ = "B" THEN LINE (x1, y1)-(x2, y2), c, B
     CASE "7"
       LOCATE 7, 52: INPUT "X= ", x
       LOCATE 7, 52: INPUT "Y= ", y
       LOCATE 7, 52: INPUT "r= ", r
       LOCATE 7, 52: INPUT "Colour: ", c
       LOCATE 7, 52: INPUT "Xf=", xf
       LOCATE 7, 52: INPUT "T=", t
       LOCATE 7, 52: INPUT "Z=", z
       LOCATE 7, 52: INPUT "S=", s
       IF x = 0 AND y = 0 AND r = 0 AND c = 0 AND xf = 0 AND t = 0 AND z = 0 AND s = 0 THEN x = 250: y = 100: c = 15: r = 20: xf = 1: t = .73: z = 6.28: s = .001
       IF x < 0 OR y < 0 OR r < 0 OR c < 0 OR x > 570 OR y > 230 OR c > 16 THEN LOCATE 7, 70: PRINT "Error!": BEEP
       VIEW (10, 10)-(400, 100)
       CLS : VIEW (10, 10)-(400, 100), , 15
       LOCATE 2, 3: COLOR 11, 0: PRINT "           D r a w      C i r c l e  "
       LOCATE 3, 3: COLOR 10, 0: PRINT "   Arrow === Move"
       LOCATE 4, 3: COLOR 10, 0: PRINT "  Q(S+Q) === Start J"
       LOCATE 5, 3: COLOR 10, 0: PRINT "  Z(S+Z) === End J"
       LOCATE 6, 3: COLOR 10, 0: PRINT "  T(S+T) === TYCD"
       LOCATE 7, 3: COLOR 11, 0: PRINT "   Enter === Draw"
       VIEW (10, 110)-(600, 330), , 15
       GET (0, 0)-(590, 220), qj
dcircle: k$ = INKEY$: IF k$ = "" THEN GOTO dcircle
IF k$ = "t" THEN t = t + s
IF k$ = "T" THEN t = t - s
IF k$ = "q" THEN q = q + s
IF k$ = "Q" THEN q = q - s
IF k$ = "z" THEN z = z + s
IF k$ = "Z" THEN z = z - s
IF k$ = "S" THEN s = s - .01
IF k$ = "s" THEN s = s + .01
IF k$ = "6" THEN x = x + 1
IF k$ = "4" THEN x = x - 1
IF k$ = "8" THEN y = y - 1
IF k$ = "2" THEN y = y + 1
IF k$ = "7" THEN x = x - 1: y = y - 1
IF k$ = "9" THEN x = x + 1: y = y - 1
IF k$ = "1" THEN x = x - 1: y = y + 1
IF k$ = "3" THEN x = x + 1: y = y + 1
IF k$ = "r" THEN r = r + 1
IF k$ = "R" THEN r = r - 1
IF k$ = "c" THEN IF c < 15 THEN c = c + 1
IF k$ = "C" THEN IF c > 1 THEN c = c - 1
IF k$ = CHR$(8) THEN xf = -xf
IF k$ = CHR$(13) THEN GOTO edcircle
CLS : CIRCLE (x, y), r, c, q, z, t
LOCATE 3, 22: PRINT "X="; x: LOCATE 3, 30: PRINT "Y="; y
LOCATE 4, 22: PRINT "C="; c: LOCATE 4, 30: PRINT "R="; r
LOCATE 5, 22: PRINT "Q="; q: LOCATE 5, 30: PRINT "Z="; z
LOCATE 6, 22: PRINT "T="; t: LOCATE 6, 30: PRINT "S="; s
GOTO dcircle
edcircle: IF op <> 1 THEN PRINT #1, "CIRCLE ("; x; ","; y; "),"; r; ","; c; ","; q; ","; z; ","; t ELSE PRINT #1, 5; x; y; r; c; q; z; t
       CLS
       PUT (0, 0), qj
       CIRCLE (x, y), r, c, q, z, t
     CASE "8"
       LOCATE 7, 52: INPUT "Paint X= ", x
       LOCATE 7, 52: INPUT "Paint Y= ", y
       LOCATE 7, 52: INPUT "Paint Colour:", c
       LOCATE 7, 52: INPUT "OutLine Colour:", bc
       IF x < 0 OR y < 0 OR x > 570 OR y > 230 OR c < 0 OR c > 15 OR bc < 0 OR bc > 15 THEN LOCATE 7, 70: PRINT "Error!": BEEP
dpaint: pk$ = INKEY$: IF pk$ = "" THEN GOTO dpaint
       PSET (x, y), oc
       SELECT CASE pk$
    CASE "7"
       x = x - 1: y = y - 1
    CASE "8"
      y = y - 1
    CASE "9"
      x = x + 1: y = y - 1
    CASE "4"
      x = x - 1
    CASE "6"
      x = x + 1
    CASE "1"
      x = x - 1: y = y + 1
    CASE "2"
      y = y + 1
    CASE "3"
      x = x + 1: y = y + 1
    CASE "5"
      IF c < 15 THEN c = c + 1 ELSE c = 0
    CASE "c", "C"
      IF bc < 15 THEN bc = bc + 1 ELSE bc = 0
    CASE CHR$(13)
      PAINT (x, y), c, bc
    GOTO edpaint
    CASE ELSE
END SELECT
      oc = POINT(x, y): PSET (x, y), c
      LOCATE 7, 52: PRINT "Color=  "; c
GOTO dpaint
edpaint: IF op <> 1 THEN PRINT #1, "PAINT ("; x; ","; y; "),"; c; ","; bc ELSE PRINT #1, 6; x; y; c; bc
       PAINT (x, y), c, bc
     CASE "G"
       LOCATE 7, 52: INPUT "LeftUp X=", x1
       LOCATE 7, 52: INPUT "LeftUp Y=", y1
       LOCATE 7, 52: INPUT "RightDown X=", x2
       LOCATE 7, 52: INPUT "RightDown Y=", y2
       IF x1 = 0 AND y1 = 0 AND c = 0 AND x2 = 0 AND y2 = 0 THEN x1 = 250: y1 = 100: c = 15: x2 = 260: y2 = 110
       IF x1 <= 0 OR x1 > 530 OR x2 <= 0 OR x2 > 530 OR y1 <= 0 OR y1 > 230 OR y2 <= 0 OR y2 > 230 THEN LOCATE 7, 70: PRINT "Error!": BEEP
       VIEW (10, 110)-(600, 330), , 15
       GET (0, 0)-(590, 220), qj
dget: pk$ = INKEY$: IF pk$ = "" THEN GOTO dget
       SELECT CASE pk$
    CASE "7"
       x1 = x1 - 1: y1 = y1 - 1
    CASE "8"
      y1 = y1 - 1
    CASE "9"
      x1 = x1 + 1: y1 = y1 - 1
    CASE "4"
      x1 = x1 - 1
    CASE "6"
      x1 = x1 + 1
    CASE "1"
      x1 = x1 - 1: y1 = y1 + 1
    CASE "2"
      y1 = y1 + 1
    CASE "3"
      x1 = x1 + 1: y1 = y1 + 1
    CASE "Q", "q"
       x2 = x2 - 1: y2 = y2 - 1
    CASE "W", "w"
      y2 = y2 - 1
    CASE "E", "e"
      x2 = x2 + 1: y2 = y2 - 1
    CASE "A", "a"
      x2 = x2 - 1
    CASE "D", "d"
      x2 = x2 + 1
    CASE "Z", "z"
      x2 = x2 - 1: y2 = y2 + 1
    CASE "X", "x"
      y2 = y2 + 1
    CASE CHR$(13)
    GOTO edget
    CASE ELSE
END SELECT
      LINE (x1, y1)-(x2, y2), 7, B
GOTO dget
edget: IF op <> 1 THEN PRINT #1, "GET ("; x1; ","; y1; ")-("; x2; ","; y2; "),"; c; "," + pp$:                 ELSE IF pp$ <> "B" THEN PRINT #1, 3, x1, y1, x2, y2, c ELSE PRINT #1, "G"; x1; y1; x2; y2
       PUT (0, 0), qj
       'GET (x1, y1)-(x2, y2), block
     CASE "P"
       LOCATE 7, 52: INPUT "Start X= ", x
       LOCATE 7, 52: INPUT "Start Y= ", y
       IF x = 0 AND y = 0 THEN x = 250: y = 100
       IF x < 0 OR x > 570 OR y < 0 OR y > 230 THEN LOCATE 7, 70: PRINT "Error!": BEEP: GOTO 88
       VIEW (10, 110)-(600, 330), , 15
dput: pk$ = INKEY$: IF pk$ = "" THEN GOTO dput
       PSET (x, y), oc
       SELECT CASE pk$
    CASE "7"
       x = x - 1: y = y - 1
    CASE "8"
      y = y - 1
    CASE "9"
      x = x + 1: y = y - 1
    CASE "4"
      x = x - 1
    CASE "6"
      x = x + 1
    CASE "1"
      x = x - 1: y = y + 1
    CASE "2"
      y = y + 1
    CASE "3"
      x = x + 1: y = y + 1
    CASE CHR$(13)
    GOTO edput
    CASE ELSE
END SELECT
      oc = POINT(x, y): PSET (x, y), c
GOTO dput
edput: LOCATE 3, 3: PRINT "Type:           "
       LOCATE 4, 3: PRINT "1 === Pset", "2 === Preset"
       LOCATE 5, 3: PRINT "3 === And", "4 === Or"
       LOCATE 6, 3: PRINT "      5 === Xor"
       LOCATE 7, 3: INPUT "Type is:", st
       SELECT CASE st
         CASE 1
           st$ = "P": hs$ = "PSET"': PUT (x, y), block, PSET
         CASE 2
           st$ = "R": hs$ = "PRESET"': PUT (x, y), block, PRESET
         CASE 3
           st$ = "A": hs$ = "AND"': PUT (x, y), block, AND
         CASE 4
           st$ = "O": hs$ = "OR"': PUT (x, y), block, OR
         CASE 5
           st$ = "X": hs$ = "XOR"': PUT (x, y), block, XOR
         CASE 0
         CASE ELSE
         LOCATE 7, 70: PRINT "Error!"
         IF op <> 1 THEN PRINT #1, "PUT ("; x; ","; y; "),"; hs$ ELSE PRINT #1, "P"; x; y; st$
         END SELECT
     CASE "9"
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
IF mo$ = "Draw" THEN IF op = 0 THEN PRINT #1, "PSET ("; x; ","; y; "),"; c:                         ELSE PRINT #1, 1, x, y, c
IF mo$ = "Draw" THEN PSET (x, y), c
IF mo$ = "Move" THEN cc = POINT(x, y): FOR z = 1 TO 500:  PSET (x, y), 15: PSET (x, y), cc: NEXT z
LOOP
     CASE "0"
       LOCATE 7, 52: INPUT "Are you sure? ", yn$
       IF yn$ = "Y" OR yn$ = "y" THEN
       LOCATE 7, 52: INPUT "Again?", yn$: IF yn$ <> "Y" OR yn$ <> "y" THEN CALL finh
END IF
     CASE "?"
       CALL help
     CASE "/"
       SHELL
     CASE "&"
       VIEW (10, 110)-(600, 330), , 15
       GET (0, 0)-(590, 219), qj
       VIEW (0, 0)-(639, 340)
       CLS
       VIEW (10, 110)-(600, 330), , 15
       PUT (0, 0), qj
     CASE "!"
       CALL games
     CASE "^"
88   CASE ELSE
       LOCATE 7, 70: PRINT "Error!": BEEP
END SELECT
LOOP

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
FOR x = 0 TO 295 STEP .5
VIEW (10, 10)-(400, 100)
LINE (x * 195 / 295, 0)-(x * 195 / 295, 90), INT(15 * RND)
LINE (390 - x * 195 / 295, 0)-(390 - x * 195 / 295, 90), INT(15 * RND)
VIEW (410, 10)-(600, 69)
LINE (x * 95 / 295, 0)-(x * 95 / 295, 59), INT(RND * 15)
LINE (190 - x * 95 / 295, 0)-(190 - x * 95 / 295, 59), INT(RND * 15)
VIEW (10, 110)-(600, 330)
LINE (x, 0)-(x, 230), INT(15 * RND)
LINE (590 - x, 0)-(590 - x, 230), INT(15 * RND)
IF o = 1 THEN LOCATE 7, 52: PRINT "Thank you very much!": KK = KK + 1: IF KK >= 30 AND o = 1 THEN KK = 0: o = 0
IF o = 0 THEN LOCATE 7, 52: PRINT "Let's say--Good bye!": KK = KK + 1: IF KK >= 30 AND o = 0 THEN KK = 0: o = 1
FOR u = 1 TO 2000: NEXT
NEXT x
END
END SUB

SUB games
VIEW (10, 10)-(400, 100), , 15
300 CLS
LOCATE 2, 3: COLOR 11, 0: PRINT "  W o r l d    W i n d o w s    Ver 3.00"
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

SUB pe
LOCATE 7, 70: PRINT "Sth. Error!": BEEP
END SUB

SUB star4
       VIEW (0, 0)-(639, 340)
       CLS
10 CLS
20 INPUT "Your name", NA$
30 IF LEN(NA$) > 9 THEN PRINT "Too long!": GOTO 20
40 INPUT "Your age", AG
50 IF AG > 200 THEN PRINT "How are you? Do you ill?": GOTO 40
60 SCREEN 9: CLS : RANDOMIZE TIMER: k = 10: KK = 1000: L = 1: M = 5
70 L = 1: M = 5: x = 280: y = 150
80 FOR RE = 1 TO INT(L / 3) * 30
90 x = INT(545 * RND) + 3: y = INT(290 * RND) + 3
100 PSET (x, y), 4
110 NEXT RE
120 CLS : KK = KK + KK: FOR WH = 1 TO 150
131 x = INT(545 * RND) + 3: y = INT(290 * RND) + 3
140 PSET (x, y), 15
150 NEXT WH
160 FOR YE = 1 TO 200 - (L * 20)
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
530 PRINT #1, "------------------------ M a k i n g  : X i e J i l e i ------------------------"
540 '
END SUB

SUB toup (char$) STATIC
FOR fone% = 1 TO LEN(char$)
IF ASC(MID$(char$, fone%, 1)) >= 97 AND ASC(MID$(char$, fone%, 1)) <= 122 THEN MID$(char$, fone%, 1) = CHR$(ASC(MID$(char$, fone%, 1)) - 32)
NEXT fone%
END SUB

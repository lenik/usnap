1 SCREEN 9: CLS
OPEN "xy" FOR INPUT AS #1
INPUT #1, l
CLOSE #1
l = l + 1
OPEN "xy" FOR OUTPUT AS #1
PRINT #1, l
CLOSE #1
OPEN "xy" FOR INPUT AS #1
INPUT #1, l$
CLOSE #1
fl$ = "le" + l$ + ".map"
OPEN fl$ FOR OUTPUT AS #1
PRINT #1, PT, SP
CLS
4 INPUT "PSET=", PT: IF 512 / PT <> INT(512 / PT) THEN 4
INPUT "speed=", SP
PRINT "UP:8 LEFT:4 RIGHT:6 DOWN:2"
PRINT "Press any key to countinue......"
5 IF INKEY$ = "" THEN 5
CLS
PSET (10, 110), 14
PSET (522, 110), 14
x = 10: y = 110
LOCATE 1, 60: PRINT fl$
6 xm = x: ym = y
7 k$ = INKEY$: IF k$ = "" THEN 7
IF k$ = "2" THEN y = y + PT: n$ = "d"
IF k$ = "4" THEN x = x - PT: n$ = "l"
IF k$ = "6" THEN x = x + PT: n$ = "r"
IF k$ = "8" THEN y = y - PT: n$ = "u"
LINE (xm, ym)-(x, y), 15
PRINT #1, n$;
IF x = 522 AND y = 110 THEN PRINT "Thank you!": GOTO 8
GOTO 6
8 CLOSE #1
INPUT "Cont?(Y/n)", s$
IF s$ = "Y" OR s$ = "y" THEN CLOSE : GOTO 1
END

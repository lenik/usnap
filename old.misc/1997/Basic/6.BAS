1 ' OUR STUDENT --- COMPUTER
2 ' AT1$-NAME,AT2$-AIR/LAND AT3$-FOOT,EYE...
3 'AT1-LEVEL AT2-LIKE
CLS : COLOR 15, 1
10 DIM AT1$(2000)
20 DIM AT2$(2000)
30 DIM AT3$(2000)
40 DIM AT1(2000)
50 DIM AT2(2000)
60 DIM kcb$(5, 8)
CLS
FOR kcbx = 1 TO 5
FOR kcby = 1 TO 8
CLS
4 LOCATE 5, 5: PRINT "Week:"; kcbx, "Lesson "; kcby;
INPUT kcb$(kcbx, kcby)
IF LEN(kcb$(kcbx, kcby)) > 6 THEN LOCATE 20, 1: PRINT "The lesson name is too long!": GOTO 4
NEXT kcby, kcbx
CLS
COLOR 14, 1: PRINT "      Mon     Tue     Wed     Thr     Fri"
FOR kcbx = 1 TO 5
FOR kcby = 1 TO 8
  LOCATE kcby + 1, 2: COLOR 14, 1: PRINT kcby
  LOCATE kcby + 1, kcbx * 8 - 1: COLOR 15, 1: PRINT kcb$(kcbx, kcby)
NEXT kcby, kcbx
LOCATE 10, 1: PRINT "Do you like this Lesson Table?", yn$
IF yn$ = "N" OR yn$ = "n" THEN GOTO 4
OPEN "LT.TAB" FOR RANDOM AS #1
FOR kcbx = 1 TO 5
FOR kcby = 1 TO 8
PRINT #1, kcb$(kcbx, kcby);
NEXT kcby, kcbx
CLOSE #1

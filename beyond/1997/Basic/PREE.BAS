DECLARE SUB d16 (char$, xx!, xy!, xc!)
DECLARE SUB press (jr$(), jr!(), func$(), func!(), size!)
DECLARE SUB ys (time!)
TYPE regtype
ax AS INTEGER: bx AS INTEGER: cx AS INTEGER: dx AS INTEGER
bp AS INTEGER: si AS INTEGER: di AS INTEGER: filags AS INTEGER
END TYPE
TYPE regtypex
ax AS INTEGER: bx AS INTEGER: cx AS INTEGER: dx AS INTEGER
bp AS INTEGER: si AS INTEGER: di AS INTEGER: flags AS INTEGER
ds AS INTEGER: es AS INTEGER
END TYPE
CLS : SCREEN 12
DIM inregs AS regtype, outregs AS regtype
inregs.ax = &H1
CALL interrupt(&H33, inregs, outregs)
inregs.ax = &H7
inregs.cx = 10
inregs.dx = 600
CALL interrupt(&H33, inregs, outregs)
inregs.ax = &H8
inregs.cx = 10
inregs.dx = 470
CALL interrupt(&H33, inregs, outregs)
SCREEN 12
WHILE INKEY$ <> CHR$(27)
LOCATE 2, 1: PRINT bx, by, b
inregs.ax = &H3
b = outregs.bx
bx = outregs.cx
by = outregs.dx
CALL interrupt(&H33, inregs, outregs)

COMMON SHARED freq
a = TIMER
ks: IF TIMER = a THEN GOTO ks
a = TIMER
cpu: IF TIMER - a >= 1 THEN freq = sd: GOTO eexit ELSE sd = sd + 1
GOTO cpu
eexit:
SCREEN 12: CLS
DIM an$(1 TO 3), an(1 TO 3, 11), gn$(1 TO 3), gn(1 TO 4)
an$(1) = "`Ok"
an(1, 0) = 150: an(1, 1) = 100: an(1, 2) = 180: an(1, 3) = 120
an(1, 4) = 157: an(1, 5) = 104
an(1, 6) = 14: an(1, 7) = 7: an(1, 8) = 1: an(1, 9) = 14: an(1, 10) = 0: an(1, 11) = 4
an$(2) = "`Cancel"
an(2, 0) = 248: an(2, 1) = 100: an(2, 2) = 300: an(2, 3) = 120
an(2, 4) = 252: an(2, 5) = 104
an(2, 6) = 14: an(2, 7) = 7: an(2, 8) = 1: an(2, 9) = 14: an(2, 10) = 0: an(2, 11) = 5
an$(3) = "~FÐ»¼ÌÀ×"
an(3, 0) = 200: an(3, 1) = 150: an(3, 2) = 280: an(3, 3) = 200
an(3, 4) = 205: an(3, 5) = 160
an(3, 6) = 12: an(3, 7) = 6: an(3, 8) = 2: an(3, 9) = 13: an(3, 10) = 0: an(3, 11) = 11
gn$(1) = CHR$(9)
gn$(2) = CHR$(0) + CHR$(15)
gn$(3) = CHR$(13)
gn(1) = 3
gn(2) = .1
gn(3) = 1

start:
gn(4) = gn(4) + 1

press an$(), an(), gn$(), gn(), 1000
LOCATE 15, 15: PRINT an$(gn(3)), gn(4)
GOTO start

SUB d16 (char$, xx, xy, xc)
OPEN "d:\ucdos\hzk16" FOR RANDOM AS #1 LEN = 1
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

SUB press (jr$(), jr!(), func$(), func(), size)
DIM bchar(size), kj$(func(1))
FOR xh = 1 TO func(1)
   GET (0, 0)-(jr(xh, 2) - jr(xh, 0), jr(xh, 3) - jr(xh, 1)), bchar
    js = 0
    FOR sx = 1 TO LEN(jr$(xh))
      IF sx + 1 <= LEN(jr$(xh)) AND (LCASE$(MID$(jr$(xh), sx, 1)) = "~") + (LCASE$(MID$(jr$(xh), sx, 1)) = "`") THEN
         sc$ = MID$(jr$(xh), 1, sx - 1) + MID$(jr$(xh), sx + 1, LEN(jr$(xh)))
         kj$(xh) = MID$(jr$(xh), sx + 1, 1)
         js = 1
         wz = sx
      END IF
    NEXT sx
    IF js <> 1 THEN kj$(func(1)) = "": sc$ = jr$(xh)
   LINE (0, 0)-(jr(xh, 2) - jr(xh, 0), jr(xh, 3) - jr(xh, 1)), 0, BF
   IF LEFT$(jr$(xh), 1) = "~" THEN d16 MID$(sc$, 2, LEN(sc$)), 8, 0, jr(xh, 7): GOTO jump
   LOCATE 1, 1: PRINT sc$
jump: LINE (jr(xh, 0) - 1, jr(xh, 1) - 1)-(jr(xh, 2) + 1, jr(xh, 3) + 1), jr(xh, 9), B
   LINE (jr(xh, 0), jr(xh, 1))-(jr(xh, 2), jr(xh, 3)), jr(xh, 8), BF
   FOR change = 1 TO LEN(sc$)
    FOR x = 0 TO 7
     FOR y = 0 TO 15
      IF POINT((change - 1) * 8 + x, y) <> 0 THEN PSET (jr(xh, 4) + (change - 1) * 8 + x, jr(xh, 5) + y), jr(xh, 7)
     NEXT y
    NEXT x
   NEXT change
   IF kj$(xh) <> "" THEN
     LOCATE 1, 1: PRINT SPACE$(LEN(sc$))
     LOCATE 1, 1: PRINT kj$(xh)
     FOR x = 0 TO 7
      FOR y = 0 TO 10
       IF POINT(x, y) <> 0 THEN PSET ((wz - 1) * 8 + jr(xh, 4) + x, jr(xh, 5) + y), jr(xh, 6)
      NEXT y
     NEXT x
     LINE ((wz - 1) * 8 + jr(xh, 4) - 1, jr(xh, 5) + 12)-(wz * 8 + jr(xh, 4) - 1, jr(xh, 5) + 12), jr(xh, 6)
   END IF
PUT (0, 0), bchar, PSET
NEXT xh
   ob = func(3)
   LINE (jr(func(3), 4) - 4, jr(func(3), 5) - 1)-STEP((LEN(jr$(func(3))) - 1) * 8 + 4, 16), jr(func(3), 11), B, &HDDDD
change: k$ = INKEY$: IF k$ = "" THEN GOTO change
   ob = func(3)
   SELECT CASE LCASE$(k$)
     CASE LCASE$(func$(1))
       func(3) = func(3) + 1: IF func(3) >= func(1) + 1 THEN func(3) = 1
     CASE LCASE$(func$(2))
       func(3) = func(3) - 1: IF func(3) <= 0 THEN func(3) = func(1)
     CASE func$(3)
       GOTO finish
     CASE ELSE
       tg = 0
       FOR sx = func(3) TO func(1)
         IF LCASE$(k$) = LCASE$(kj$(sx)) THEN func(3) = sx: tg = 1
       NEXT sx
       IF tg = 0 THEN
       FOR sx = 1 TO func(3)
         IF LCASE$(k$) = LCASE$(kj$(sx)) THEN func(3) = sx: tg = 1
       NEXT sx
       END IF
   END SELECT
   LINE (jr(ob, 4) - 4, jr(ob, 5) - 1)-STEP((LEN(jr$(ob)) - 1) * 8 + 4, 16), jr(ob, 8), B
   LINE (jr(func(3), 4) - 4, jr(func(3), 5) - 1)-STEP((LEN(jr$(func(3))) - 1) * 8 + 4, 16), jr(func(3), 11), B, &HDDDD
GOTO change
finish:
   VIEW (jr(func(3), 0), jr(func(3), 1))-(jr(func(3), 2), jr(func(3), 3)), , jr(func(3), 9)
   SELECT CASE func(4)
     CASE 0
       LINE (0, 0)-(jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10), BF
     CASE 1
       FOR y = 0 TO jr(func(3), 3) - jr(func(3), 1)
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2)
       NEXT y
     CASE 2
       FOR y = jr(func(3), 3) - jr(func(3), 1) TO 0 STEP -1
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2)
       NEXT y
     CASE 3
       FOR x = 0 TO jr(func(3), 2) - jr(func(3), 0)
         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2)
       NEXT x
     CASE 4
       FOR x = jr(func(3), 2) - jr(func(3), 0) TO 0 STEP -1
         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2)
       NEXT x
     CASE 5
       FOR y = (jr(func(3), 3) - jr(func(3), 1)) / 2 TO jr(func(3), 3) - jr(func(3), 1)
         LINE (0, jr(func(3), 3) - jr(func(3), 1) - y)-(jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1) - y), jr(func(3), 10)
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2) * 2
       NEXT y
     CASE 6
       FOR y = jr(func(3), 3) - jr(func(3), 1) TO (jr(func(3), 3) - jr(func(3), 1)) / 2 STEP -1
         LINE (0, jr(func(3), 3) - jr(func(3), 1) - y)-(jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1) - y), jr(func(3), 10)
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2) * 2
       NEXT y
     CASE 7
       FOR x = (jr(func(3), 2) - jr(func(3), 0)) / 2 TO jr(func(3), 2) - jr(func(3), 0)
         LINE (jr(func(3), 2) - jr(func(3), 0) - x, 0)-(jr(func(3), 2) - jr(func(3), 0) - x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2) * 2
       NEXT x
     CASE 8
       FOR x = jr(func(3), 2) - jr(func(3), 0) TO (jr(func(3), 2) - jr(func(3), 0)) / 2 STEP -1
         LINE (jr(func(3), 2) - jr(func(3), 0) - x, 0)-(jr(func(3), 2) - jr(func(3), 0) - x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2) * 2
       NEXT x
     CASE 9
       FOR y = 0 TO jr(func(3), 3) - jr(func(3), 1)
         LINE (jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1))-(0, jr(func(3), 3) - jr(func(3), 1) - y), jr(func(3), 10)
         LINE (0, 0)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2) * 2
       NEXT y
     CASE 10
       FOR y = jr(func(3), 3) - jr(func(3), 1) TO 0 STEP -1
         LINE (jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1))-(0, jr(func(3), 3) - jr(func(3), 1) - y), jr(func(3), 10)
         LINE (0, 0)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2) * 2
       NEXT y
     CASE 11

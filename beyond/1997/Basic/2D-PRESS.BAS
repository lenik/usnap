DECLARE SUB press (jr$(), jr!(), func$(), func!(), back$)
DECLARE SUB ys (time!)
SCREEN 12: CLS
DIM an$(1 TO 3), an(1 TO 3, 11), gn$(1 TO 3), gn(1 TO 4)
an$(1) = "`Yes"
an(1, 0) = 150: an(1, 1) = 200: an(1, 2) = 180: an(1, 3) = 220
an(1, 4) = 155: an(1, 5) = 204
an(1, 6) = 14: an(1, 7) = 7: an(1, 8) = 1: an(1, 9) = 14: an(1, 10) = 0: an(1, 11) = 4
an$(2) = "`No"
an(2, 0) = 240: an(2, 1) = 200: an(2, 2) = 262: an(2, 3) = 220
an(2, 4) = 245: an(2, 5) = 204
an(2, 6) = 14: an(2, 7) = 7: an(2, 8) = 1: an(2, 9) = 14: an(2, 10) = 0: an(2, 11) = 4
an$(3) = "`Cancel"
an(3, 0) = 320: an(3, 1) = 200: an(3, 2) = 375: an(3, 3) = 220
an(3, 4) = 325: an(3, 5) = 204
an(3, 6) = 14: an(3, 7) = 7: an(3, 8) = 1: an(3, 9) = 14: an(3, 10) = 0: an(3, 11) = 4
gn$(1) = CHR$(9)
gn$(2) = CHR$(0) + CHR$(15)
gn$(3) = CHR$(13)
gn(1) = 3
gn(2) = .1
gn(3) = 1
start:
gn(4) = gn(4) + 1
press an$(), an(), gn$(), gn(), fh$
SELECT CASE fh$


END SELECT
LOCATE 20, 20: PRINT fh$



GOTO start

SUB press (jr$(), jr!(), func$(), func(), back$)
DIM bchar(1000), kj$(func(1))
FOR xh = 1 TO func(1)
   GET (0, 0)-(jr(xh, 2) - jr(xh, 0), jr(xh, 3) - jr(xh, 1)), bchar
    js = 0
    FOR sx = 1 TO LEN(jr$(xh))
      IF sx + 1 <= LEN(jr$(xh)) AND LCASE$(MID$(jr$(xh), sx, 1)) = "`" THEN
         sc$ = MID$(jr$(xh), 1, sx - 1) + MID$(jr$(xh), sx + 1, LEN(jr$(xh)))
         kj$(xh) = MID$(jr$(xh), sx + 1, 1)
         js = 1
         wz = sx
      END IF
    NEXT sx
    IF js <> 1 THEN kj$(func(1)) = "": sc$ = jr$(xh)
   LINE (0, 0)-(jr(xh, 2) - jr(xh, 0), jr(xh, 3) - jr(xh, 1)), 0, BF
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
       back$ = jr$(func(3))
     CASE 1
       FOR y = 0 TO jr(func(3), 3) - jr(func(3), 1)
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2)
       NEXT y
       back$ = jr$(func(3))
     CASE 2
       FOR y = jr(func(3), 3) - jr(func(3), 1) TO 0 STEP -1
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2)
       NEXT y
       back$ = jr$(func(3))
     CASE 3
       FOR x = 0 TO jr(func(3), 2) - jr(func(3), 0)
         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2)
       NEXT x
       back$ = jr$(func(3))
     CASE 4
       FOR x = jr(func(3), 2) - jr(func(3), 0) TO 0 STEP -1
         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2)
       NEXT x
       back$ = jr$(func(3))
     CASE 5
       FOR y = (jr(func(3), 3) - jr(func(3), 1)) / 2 TO jr(func(3), 3) - jr(func(3), 1)
         LINE (0, jr(func(3), 3) - jr(func(3), 1) - y)-(jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1) - y), jr(func(3), 10)
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2) * 2
       NEXT y
       back$ = jr$(func(3))
     CASE 6
       FOR y = jr(func(3), 3) - jr(func(3), 1) TO (jr(func(3), 3) - jr(func(3), 1)) / 2 STEP -1
         LINE (0, jr(func(3), 3) - jr(func(3), 1) - y)-(jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1) - y), jr(func(3), 10)
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2) * 2
       NEXT y
       back$ = jr$(func(3))
     CASE 7
       FOR x = (jr(func(3), 2) - jr(func(3), 0)) / 2 TO jr(func(3), 2) - jr(func(3), 0)
         LINE (jr(func(3), 2) - jr(func(3), 0) - x, 0)-(jr(func(3), 2) - jr(func(3), 0) - x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2) * 2
       NEXT x
       back$ = jr$(func(3))
     CASE 8
       FOR x = jr(func(3), 2) - jr(func(3), 0) TO (jr(func(3), 2) - jr(func(3), 0)) / 2 STEP -1
         LINE (jr(func(3), 2) - jr(func(3), 0) - x, 0)-(jr(func(3), 2) - jr(func(3), 0) - x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2) * 2
       NEXT x
       back$ = jr$(func(3))
     CASE 9
       FOR y = 0 TO jr(func(3), 3) - jr(func(3), 1)
         LINE (jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1))-(0, jr(func(3), 3) - jr(func(3), 1) - y), jr(func(3), 10)
         LINE (0, 0)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2) * 2
       NEXT y
       back$ = jr$(func(3))
     CASE 10
       FOR y = jr(func(3), 3) - jr(func(3), 1) TO 0 STEP -1
         LINE (jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1))-(0, jr(func(3), 3) - jr(func(3), 1) - y), jr(func(3), 10)
         LINE (0, 0)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2) * 2
       NEXT y
       back$ = jr$(func(3))
     CASE 11
       FOR x = 0 TO jr(func(3), 2) - jr(func(3), 0)
         LINE (jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1))-(jr(func(3), 2) - jr(func(3), 0) - x, 0), jr(func(3), 10)
         LINE (0, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2) * 2
       NEXT x
       back$ = jr$(func(3))
     CASE 12
       FOR x = jr(func(3), 2) - jr(func(3), 0) TO 0 STEP -1
         LINE (jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1))-(jr(func(3), 2) - jr(func(3), 0) - x, 0), jr(func(3), 10)
         LINE (0, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2) * 2
       NEXT x
       back$ = jr$(func(3))
     CASE 13
       IF jr(func(3), 2) - jr(func(3), 0) > jr(func(3), 3) - jr(func(3), 1) THEN tk = jr(func(3), 2) - jr(func(3), 0) ELSE tk = jr(func(3), 3) - jr(func(3), 1)
       FOR r = 0 TO tk
         CIRCLE ((jr(func(3), 2) - jr(func(3), 0)) / 2, (jr(func(3), 3) - jr(func(3), 1)) / 2), r, jr(func(3), 10)
         CIRCLE ((jr(func(3), 2) - jr(func(3), 0)) / 2, (jr(func(3), 3) - jr(func(3), 1)) / 2 + 1), r, jr(func(3), 10)
         ys func(2)
       NEXT r
       back$ = jr$(func(3))
     CASE 14
       IF jr(func(3), 2) - jr(func(3), 0) > jr(func(3), 3) - jr(func(3), 1) THEN tk = jr(func(3), 2) - jr(func(3), 0) ELSE tk = jr(func(3), 3) - jr(func(3), 1)
       FOR r = tk TO 0 STEP -1
         CIRCLE ((jr(func(3), 2) - jr(func(3), 0)) / 2, (jr(func(3), 3) - jr(func(3), 1)) / 2), r, jr(func(3), 10)
         CIRCLE ((jr(func(3), 2) - jr(func(3), 0)) / 2, (jr(func(3), 3) - jr(func(3), 1)) / 2 + 1), r, jr(func(3), 10)
         ys func(2)
       NEXT r
       back$ = jr$(func(3))
     CASE 15, 16, 17, 18, 19, 20
       FOR r = 1 TO (jr(func(3), 2) - jr(func(3), 0)) * (jr(func(3), 3) - jr(func(3), 1))
         x = RND * (jr(func(3), 2) - jr(func(3), 0))
         y = RND * (jr(func(3), 3) - jr(func(3), 1))
         PSET (x, y), jr(func(3), 10)
           ys func(2) / 20
       NEXT r
       LINE (0, 0)-(jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10), BF
       back$ = jr$(func(3))

     CASE 21, 22
       y1 = 0: y2 = jr(func(3), 3) - jr(func(3), 1)
       IF func(4) = 22 THEN SWAP y1, y2
       FOR y = y1 TO y2 STEP (21.5 - func(4)) * 2
         GET (0, y)-(jr(func(3), 2) - jr(func(3), 0), jr(func(3), 3) - jr(func(3), 1) - 1), bchar
         IF y < jr(func(3), 3) - jr(func(3), 1) THEN PUT (0, y + 1), bchar, PSET
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2) * 2
       NEXT y
     CASE 23, 24
       y1 = jr(func(3), 3) - jr(func(3), 1): y2 = 0
       IF func(4) = 24 THEN SWAP y1, y2
       FOR y = y1 TO y2 STEP (func(4) - 23.5) * 2
         GET (0, 1)-(jr(func(3), 2) - jr(func(3), 0), y), bchar
         PUT (0, 0), bchar, PSET
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2) * 2
       NEXT y
     CASE 25, 26
       x1 = 0: x2 = jr(func(3), 2) - jr(func(3), 0)
       IF func(4) = 26 THEN SWAP x1, x2
       FOR x = x1 TO x2 STEP (25.5 - func(4)) * 2
         GET (x, 0)-(jr(func(3), 2) - jr(func(3), 0) - 1, jr(func(3), 3) - jr(func(3), 1)), bchar
         IF x < jr(func(3), 2) - jr(func(3), 0) THEN PUT (x + 1, 0), bchar, PSET
         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2) * 2
       NEXT x
     CASE 27, 28
       x1 = jr(func(3), 2) - jr(func(3), 0): x2 = 0
       IF func(4) = 28 THEN SWAP x1, x2
       FOR x = x1 TO x2 STEP (func(4) - 27.5) * 2
         GET (1, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), bchar
         PUT (0, 0), bchar, PSET
         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2) * 2
       NEXT x
     CASE 29, 30
       y2 = jr(func(3), 3) - jr(func(3), 1): y1 = (jr(func(3), 3) - jr(func(3), 1)) / 2
       yy2 = (jr(func(3), 3) - jr(func(3), 1)): yy1 = (jr(func(3), 3) - jr(func(3), 1)) / 2
       IF func(4) = 30 THEN SWAP yy1, yy2
       FOR y = yy1 TO yy2 STEP (29.5 - func(4)) * 2
         GET (0, 1)-(jr(func(3), 2) - jr(func(3), 0), (jr(func(3), 3) - jr(func(3), 1)) - y), bchar
         PUT (0, 0), bchar, PSET
         LINE (0, (jr(func(3), 3) - jr(func(3), 1)) - y)-(jr(func(3), 2) - jr(func(3), 0), (jr(func(3), 3) - jr(func(3), 1)) - y), jr(func(3), 10)
         GET (0, y)-(jr(func(3), 2) - jr(func(3), 0), (jr(func(3), 3) - jr(func(3), 1)) - 1), bchar
         IF y < (jr(func(3), 3) - jr(func(3), 1)) THEN PUT (0, y + 1), bchar, PSET
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         ys func(2) * 4
       NEXT y
     CASE 31, 32
       y2 = jr(func(3), 3) - jr(func(3), 1): y1 = (jr(func(3), 3) - jr(func(3), 1)) / 2
       yy2 = (jr(func(3), 3) - jr(func(3), 1)): yy1 = (jr(func(3), 3) - jr(func(3), 1)) / 2
       IF func(4) = 32 THEN SWAP yy1, yy2
       FOR y = yy2 TO yy1 STEP (func(4) - 31.5) * 2
         GET (0, (jr(func(3), 3) - jr(func(3), 1)) / 2 + 1)-(jr(func(3), 2) - jr(func(3), 0), y), bchar
         PUT (0, (jr(func(3), 3) - jr(func(3), 1)) / 2), bchar, PSET
         LINE (0, y)-(jr(func(3), 2) - jr(func(3), 0), y), jr(func(3), 10)
         GET (0, (jr(func(3), 3) - jr(func(3), 1)) - y)-(jr(func(3), 2) - jr(func(3), 0), (jr(func(3), 3) - jr(func(3), 1)) / 2 - 1), bchar
         PUT (0, (jr(func(3), 3) - jr(func(3), 1)) - y + 1), bchar, PSET
         LINE (0, (jr(func(3), 3) - jr(func(3), 1)) - y)-(jr(func(3), 2) - jr(func(3), 0), (jr(func(3), 3) - jr(func(3), 1)) - y), jr(func(3), 10)
         ys func(2) * 4
       NEXT y
     CASE 33, 34
       x2 = jr(func(3), 2) - jr(func(3), 0): x1 = (jr(func(3), 2) - jr(func(3), 0)) / 2
       xx2 = (jr(func(3), 2) - jr(func(3), 0)): xx1 = (jr(func(3), 2) - jr(func(3), 0)) / 2
       IF func(4) = 34 THEN SWAP xx1, xx2
       FOR x = xx1 TO xx2 STEP (33.5 - func(4)) * 2
         GET (x, 0)-((jr(func(3), 2) - jr(func(3), 0)) - 1, jr(func(3), 3) - jr(func(3), 1)), bchar
         IF x < (jr(func(3), 2) - jr(func(3), 0)) THEN PUT (x + 1, 0), bchar, PSET

         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         GET (1, 0)-((jr(func(3), 2) - jr(func(3), 0)) - x, jr(func(3), 3) - jr(func(3), 1)), bchar
         PUT (0, 0), bchar, PSET
         LINE ((jr(func(3), 2) - jr(func(3), 0)) - x, 0)-((jr(func(3), 2) - jr(func(3), 0)) - x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2) * 4
       NEXT x
     CASE 35, 36
       x2 = jr(func(3), 2) - jr(func(3), 0): x1 = (jr(func(3), 2) - jr(func(3), 0)) / 2
       xx2 = (jr(func(3), 2) - jr(func(3), 0)): xx1 = (jr(func(3), 2) - jr(func(3), 0)) / 2
       IF func(4) = 36 THEN SWAP xx1, xx2
       FOR x = xx2 TO xx1 STEP (func(4) - 35.5) * 2
         GET ((jr(func(3), 2) - jr(func(3), 0)) / 2 + 1, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), bchar
         PUT ((jr(func(3), 2) - jr(func(3), 0)) / 2, 0), bchar, PSET
         LINE (x, 0)-(x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         GET ((jr(func(3), 2) - jr(func(3), 0)) - x, 0)-((jr(func(3), 2) - jr(func(3), 0)) / 2 - 1, jr(func(3), 3) - jr(func(3), 1)), bchar
         PUT ((jr(func(3), 2) - jr(func(3), 0)) - x + 1, 0), bchar, PSET
         LINE ((jr(func(3), 2) - jr(func(3), 0)) - x, 0)-((jr(func(3), 2) - jr(func(3), 0)) - x, jr(func(3), 3) - jr(func(3), 1)), jr(func(3), 10)
         ys func(2) * 4
       NEXT x
     CASE ELSE
   END SELECT
VIEW

END SUB

SUB ys (time)
FOR times = 1 TO 20483 * time
NEXT

END SUB

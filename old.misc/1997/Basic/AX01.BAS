DECLARE SUB ys (time!)
SCREEN 2: CLS : rt = .5: DIM ccx(500), ccy(500), ccp$(500): ss = 1: ssz = .01
RANDOMIZE TIMER
pox = 640: poy = 200
WINDOW (-pox / 2 - x0, -poy / 2 + y0)-(pox / 2 - x0, poy / 2 + y0)
WHILE INKEY$ = ""
y = y + 4
x = x + 3
z = z + 2
IF rt < .1 OR rt > 1 THEN ssz = -ssz
rt = rt + ssz
IF ax < -50 OR ax > 50 OR ay < -50 OR ay > 50 THEN ss = -ss
ax = ax + ss: ay = ay + ss
yr = y: xr = x: zr = z
FOR i = 1 TO 72
IF ccp$(i) = "p" THEN PSET (ccx(i) - 50 + oax, -ccy(i) + 50 + oay), 0 ELSE LINE -(ccx(i) - 50 + oax, -ccy(i) + 50 + oay), 0
NEXT i
p = 3.14159 / 180: yr = yr * p: xr = xr * p: zr = zr * p
RESTORE
FOR i = 1 TO 72
READ x1, y1, z1, d$: x1 = x1 * rt: y1 = y1 * rt: z1 = z1 * rt: GOSUB 200
IF d$ = "p" THEN PSET (x4 - 50 + ax, -y4 + 50 + ay) ELSE LINE -(x4 - 50 + ax, -y4 + 50 + ay)
ccx(i) = x4: ccy(i) = y4: ccp$(i) = d$: oax = ax: oay = ay
NEXT i
WEND: END

200 y2 = y1
x2 = x1 * COS(yr) - z1 * SIN(yr)
z2 = x1 * SIN(yr) + z1 * COS(yr)
y3 = z2 * SIN(xr) + y2 * COS(xr)
x3 = x2
z3 = z2 * COS(xr) - y2 * SIN(xr)
y4 = y3 * COS(zr) - x3 * SIN(zr)
x4 = y3 * SIN(zr) + x3 * COS(zr)
z4 = z3
RETURN
DATA 16,20,0,p,26,32,0,l,11,48,0,p,31,43,0,l,17,84,0,l,33,73,0,l,53,12,0,p,38,29,0,l,38,60,0,l,38,29,0,p,62,29,0,l,62,88,0,l,48,82,0,l,38,39,0,p,62,39,0,l,38,50,0,p
DATA 62,57,0,l,28,65,0,p,67,58,0,l,57,60,0,p,41,86,0,l,28,88,0,l,68,53,0,p,85,50,0,l,77,17,0,p,77,82,0,l,70,75,0,l,69,66,0,p,73,70,0,l
DATA 129,19,0,p,111,43,0,l,127,39,0,l,115,62,0,l,128,57,0,l,113,78,0,p,129,63,0,l,143,23,0,p,171,64,0,l,173,22,0,p,143,65,0,l,157,22,0,p,157,68,0,l,142,44,0,p,176,44,0,l,136,22,0,p
DATA 136,74,0,l,184,73,0,l
DATA 227,25,0,p,269,25,0,l,216,52,0,p,216,37,0,l,282,37,0,l,282,52,0,l,248,25,0,p,248,59,0,l,227,45,0,p,240,45,0,l,227,51,0,p,240,51,0,l,258,45,0,p,272,45,0,l,258,51,0,p,272,51,0,l
DATA 232,65,0,p,267,65,0,l,267,87,0,l,232,87,0,l,232,65,0,l,267,76,0,p,232,76,0,l,248,65,0,p,248,87,0,l


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

SUB ys (time)
FOR times = 1 TO 20483 * time
NEXT
END SUB

11 DIM tname$(1 TO 28), txznum%(1 TO 28)
OPEN "temp.dat" FOR OUTPUT AS #4
DIM qj(16383): p = 3.14159 / 180
mup$ = CHR$(0) + CHR$(80): mdown$ = CHR$(0) + CHR$(72): mleft$ = CHR$(0) + CHR$(75): mright$ = CHR$(0) + CHR$(77)
start: VIEW (1, 1)-(500, 70), , 15
       GET (0, 0)-(589, 219), qj
       VIEW (1, 1)-(500, 70), , 15
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
       s = 10: zo = 1
aj:    IF dr% = 1 THEN GOTO ed3dt
       k$ = INKEY$: IF k$ = "" THEN GOTO aj
       SELECT CASE k$
       CASE "E", "e"
         GOTO ed3dt
       CASE "Y"
         yrr = yrr + s
       CASE "y"
         yrr = yrr - s
       CASE "X"
         xrr = xrr + s
       CASE "x"
         xrr = xrr - s
       CASE "Z"
         zrr = zrr + s
       CASE "z"
         zrr = zrr - s
       CASE "S"
         s% = s% + 1
       CASE "s"
         s% = s% - 1
       CASE "+"
         zo = zo * 1.01
       CASE "-"
         zo = zo * .99
       CASE mleft$
         ax% = ax% - 1
       CASE mright$
         ax% = ax% + 1
       CASE mup$
         ay% = ay% + 1
       CASE mdown$
         ay% = ay% - 1
       CASE CHR$(13)
         dr% = 1
       CASE ELSE
       END SELECT
       LOCATE 2, 3: PRINT "Skip="; s%, "Zoom=", z
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
  IF fs$ = "p" THEN PSET (x4 + ax%, y4 + ay%), 15 ELSE IF fs$ = "l" THEN LINE -(x4 + ax%, y4 + ay%), 15
  ox4(i%) = x4: oy4(i%) = y4: ofs$(i%) = fs$: oax% = ax%: oay% = ay%
NEXT i%
CLOSE #2
GOTO aj
VIEW (1, 75)-(619, 345), , 15
END
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
CLOSE

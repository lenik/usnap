SCREEN 9: CLS : dr = -1
INPUT "3DT Filename:", file$
IF file$ = "" THEN END
CONST u = 80, d = 72, l = 75, r = 77
ON ERROR GOTO 1
OPEN file$ + ".3DT" FOR INPUT AS #1
1 PRINT "No this file": END
INPUT #1, bsf$
IF bsf$ <> "ÿÿ3DTÿ" THEN PRINT "File format error!": END
INPUT #1, num
mnum = num
CLOSE #1
DIM ox4(num), oy4(num), ofs$(num)
yr = 50: xr = 50: zr = 50: yrr = yr: xrr = xr: zrr = zr
WINDOW (-320, -200)-(320, 200)
s = 1: zo = 1: bl$ = CHR$(0)
aj: K$ = INKEY$: IF K$ = "" THEN GOTO aj
SELECT CASE K$
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
    s = s + 1
  CASE "s"
    s = s - 1
  CASE "+"
    zo = zo * 1.01
  CASE "-"
    zo = zo * .99
  CASE bl$ + CHR$(l)
    ax = ax - 1
  CASE bl$ + CHR$(r)
    ax = ax + 1
  CASE bl$ + CHR$(u)
    ay = ay - 1
  CASE bl$ + CHR$(d)
    ay = ay + 1
  CASE CHR$(13)
    dr = 1
  CASE ELSE
END SELECT
LOCATE 1, 1: PRINT "Skip:"; s
xr = xrr: yr = yrr: zr = zrr
p = 3.14159 / 180: yr = yr * p: xr = xr * p: zr = zr * p
FOR i = 1 TO mnum
IF dr <> 1 THEN IF ofs$(i) = "p" THEN PSET (ox4(i) + oax, -oy4(i) + oay), 0 ELSE IF ofs$(i) = "l" THEN LINE -(ox4(i) + oax, -oy4(i) + oay), 0
NEXT i
IF dr = 1 THEN dr = 0: ax = ax + 100: ay = ay + 100
OPEN file$ + ".3DT" FOR INPUT AS #1
INPUT #1, tmp$, tmp
FOR i = 1 TO mnum
INPUT #1, x1, y1, z1, fs$
x1 = x1 * zo: y1 = y1 * zo: z1 = z1 * zo: GOSUB 200
IF fs$ = "p" THEN PSET (x4 + ax, -y4 + ay), 15 ELSE IF fs$ = "l" THEN LINE -(x4 + ax, -y4 + ay), 15
ox4(i) = x4: oy4(i) = y4: ofs$(i) = fs$: oax = ax: oay = ay
NEXT i
CLOSE #1
GOTO aj
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

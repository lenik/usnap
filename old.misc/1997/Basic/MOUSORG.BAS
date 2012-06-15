TYPE regtype
ax AS INTEGER
bx AS INTEGER
cx AS INTEGER
dx AS INTEGER
bp AS INTEGER
si AS INTEGER
di AS INTEGER
filags AS INTEGER
END TYPE
TYPE regtypex
ax AS INTEGER
bx AS INTEGER
cx AS INTEGER
dx AS INTEGER
bp AS INTEGER
si AS INTEGER
di AS INTEGER
flags AS INTEGER
ds AS INTEGER
es AS INTEGER
END TYPE
DECLARE SUB interrupt (intno AS INTEGER, inregs AS regtype, outregs AS regtype)
DECLARE SUB interruptx (intno AS INTEGER, inregs AS regtypex, outregs AS regtypex)
CLS : SCREEN 12
DIM inregs AS regtype, outregs AS regtype
inregs.ax = &H0
inregs.ax = &HFFFF
inregs.bx = &H2
CALL interrupt(&H33, inregs, outregs)
inregs.ax = &H1
CALL interrupt(&H33, inregs, outregs)
inregs.ax = &H7
inregs.cx = 40
inregs.dx = 600
CALL interrupt(&H33, inregs, outregs)
inregs.ax = &H8
inregs.cx = 90
inregs.dx = 190
CALL interrupt(&H33, inregs, outregs)
inregs.ax = &H4
inregs.cx = 30
inregs.dx = 96
CALL interrupt(&H33, inregs, outregs)
DIM wx(48), wy(48)
CLS : SCREEN 12: PALETTE 0, 43 * 65536: PALETTE 1, 0
sx = 38: sy = 118: z = 12.2 * 1.5: x = 0
LINE (0, 0)-(640, 480), 0, BF
LINE (sx - 15, sy - 31)-(sx + (z + 2) * 28 + 15, sy + 86), 1, BF
LINE (sx - 16, sy - 34)-(sx - 10, sy + 86), 15, BF
LINE (sx - 16, sy - 34)-(sx + (z + 2) * 28 + 16, sy - 28), 15, BF
LINE (sx - 10, sy + 80)-(sx + (z + 2) * 28 + 10, sy + 80), 1, BF
LINE (sx + (z + 2) * 28 + 16, sy + 86)-(sx + (z + 2) * 28 + 10, sy - 34), 1, BF
LINE (sx - 8, sy - 26)-(sx + (z + 2) * 28 + 8, sy + 78), 4, BF
LINE (36, 116)-(607, 193), 1, BF
FOR w = 1 TO 28
 LINE (sx + x, sy)-(sx + x + 12.2 * 1.5, sy + 73.2), 15, BF
 wx(w) = sx + x + 12.2 * 1.5
 IF w <> 28 THEN
  LINE (sx + x + 12.2 * 1.5, sy + 71.2)-(sx + x + 12.2 * 1.5, sy + 73.2), 15, BF
  LINE (sx + x + 12.2 * 1.5 - 1, sy + 73.2)-(sx + x + 12.2 * 1.5, sy + 72.2), 6
  LINE (sx + x + 12.2 * 1.5, sy + 72.2)-(sx + 12.2 * 1.5 + x + 2, sy + 73.2), 6
 END IF
 x = x + z + 2
NEXT w
 po = 29
x = z
FOR w = 1 TO 28
 IF w = 3 OR w = 7 OR w = 10 OR w = 14 OR w = 17 OR w = 21 OR w = 24 OR w = 28 THEN GOTO c
 wx(po) = sx + x - 12.2 * .5: po = po + 1
 LINE (sx + x - 12.2 * .5, sy)-(sx + x + 12.2 * .5, sy + 36.6), 1, BF
 LINE (sx + x - 12.2 * .5 + 1, sy - 1)-(sx + x + 12.2 * .5 - 1, sy - 1), 15
 LINE (sx + x - 12.2 * .5 + 1, sy - 1)-(sx + x - 12.2 * .5 + 1, sy + 37.6), 15
 LINE (sx + x - 12.2 * .5 + 1, sy + 37.6)-(sx + x + 12.2 * .5 - 1, sy + 37.6), 1
 LINE (sx + x + 12.2 * .5 + 1, sy - 1)-(sx + x + 12.2 * .5 + 1, sy + 37.6), 1
 LINE (sx + x - 12.2 * .5 + 1, sy + 36)-(sx + x + 12.2 * .5 - 1, sy + 36), 7
 LINE (sx + x + 12.2 * .5, sy)-(sx + x + 12.2 * .5, sy + 35), 7
c: x = x + z + 2
NEXT w
LOCATE 14, 6: PRINT "                                    . .  . .  . .  . :  : :  :  :  : :"
LOCATE 15, 6: PRINT " 1 2  3 4  5 6  7 1  2 3  4 5  6 7  1 2  3 4  5 6  7 1  2 3  4  5  6 7"
LOCATE 16, 6: PRINT " ù ù  ù ù  ù ù  ù"
PLAY "mlt255l64"
WHILE INKEY$ <> CHR$(27)
inregs.ax = &H5
inregs.bx = &H0
B = outregs.bx
x = outregs.cx
y = outregs.dx
CALL interrupt(&H33, inregs, outregs)
LOCATE 7, 5: PRINT so$
LOCATE 7, 68: PRINT TIME$
inregs.ax = &H3
bx = outregs.cx
by = outregs.dx
CALL interrupt(&H33, inregs, outregs)
IF B = 1 THEN
IF x > wx(0) AND x < wx(1) AND POINT(x, y) = 15 THEN so$ = "o2c "
IF x > wx(1) AND x < wx(2) AND POINT(x, y) = 15 THEN so$ = "o2d "
IF x > wx(2) AND x < wx(3) AND POINT(x, y) = 15 THEN so$ = "o2e "
IF x > wx(3) AND x < wx(4) AND POINT(x, y) = 15 THEN so$ = "o2f "
IF x > wx(4) AND x < wx(5) AND POINT(x, y) = 15 THEN so$ = "o2g "
IF x > wx(5) AND x < wx(6) AND POINT(x, y) = 15 THEN so$ = "o2a "
IF x > wx(6) AND x < wx(7) AND POINT(x, y) = 15 THEN so$ = "o2b "
IF x > wx(7) AND x < wx(8) AND POINT(x, y) = 15 THEN so$ = "o3c "
IF x > wx(8) AND x < wx(9) AND POINT(x, y) = 15 THEN so$ = "o3d "
IF x > wx(9) AND x < wx(10) AND POINT(x, y) = 15 THEN so$ = "o3e "
IF x > wx(10) AND x < wx(11) AND POINT(x, y) = 15 THEN so$ = "o3f "
IF x > wx(11) AND x < wx(12) AND POINT(x, y) = 15 THEN so$ = "o3g "
IF x > wx(12) AND x < wx(13) AND POINT(x, y) = 15 THEN so$ = "o3a "
IF x > wx(13) AND x < wx(14) AND POINT(x, y) = 15 THEN so$ = "o3b "
IF x > wx(14) AND x < wx(15) AND POINT(x, y) = 15 THEN so$ = "o4c "
IF x > wx(15) AND x < wx(16) AND POINT(x, y) = 15 THEN so$ = "o4d "
IF x > wx(16) AND x < wx(17) AND POINT(x, y) = 15 THEN so$ = "o4e "
IF x > wx(17) AND x < wx(18) AND POINT(x, y) = 15 THEN so$ = "o4f "
IF x > wx(18) AND x < wx(19) AND POINT(x, y) = 15 THEN so$ = "o4g "
IF x > wx(19) AND x < wx(20) AND POINT(x, y) = 15 THEN so$ = "o4a "
IF x > wx(20) AND x < wx(21) AND POINT(x, y) = 15 THEN so$ = "o4b "
IF x > wx(21) AND x < wx(22) AND POINT(x, y) = 15 THEN so$ = "o5c "
IF x > wx(22) AND x < wx(23) AND POINT(x, y) = 15 THEN so$ = "o5d "
IF x > wx(23) AND x < wx(24) AND POINT(x, y) = 15 THEN so$ = "o5e "
IF x > wx(24) AND x < wx(25) AND POINT(x, y) = 15 THEN so$ = "o5f "
IF x > wx(25) AND x < wx(26) AND POINT(x, y) = 15 THEN so$ = "o5g "
IF x > wx(26) AND x < wx(27) AND POINT(x, y) = 15 THEN so$ = "o5a "
IF x > wx(27) AND x < wx(28) AND POINT(x, y) = 15 THEN so$ = "o5b "
IF x > wx(28) AND x < wx(29) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o2c#"
IF x > wx(29) AND x < wx(30) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o2c#"
IF x > wx(30) AND x < wx(31) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o2d#"
IF x > wx(31) AND x < wx(32) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o2f#"
IF x > wx(32) AND x < wx(33) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o2g#"
IF x > wx(33) AND x < wx(34) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o2a#"
IF x > wx(34) AND x < wx(35) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o3c#"
IF x > wx(35) AND x < wx(36) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o3d#"
IF x > wx(36) AND x < wx(37) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o3f#"
IF x > wx(37) AND x < wx(38) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o3g#"
IF x > wx(38) AND x < wx(39) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o3a#"
IF x > wx(39) AND x < wx(40) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o4c#"
IF x > wx(40) AND x < wx(41) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o4d#"
IF x > wx(41) AND x < wx(42) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o4f#"
IF x > wx(42) AND x < wx(43) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o4g#"
IF x > wx(43) AND x < wx(44) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o4a#"
IF x > wx(44) AND x < wx(45) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o5c#"
IF x > wx(45) AND x < wx(46) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o5d#"
IF x > wx(46) AND x < wx(47) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o5f#"
IF x > wx(47) AND x < wx(48) AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o5g#"
IF x > wx(48) AND x < 600 AND POINT(x, y) = 1 AND y < 152 THEN so$ = "o5a#"
END IF
IF B = 2 THEN so$ = "    "
PLAY so$
 WEND

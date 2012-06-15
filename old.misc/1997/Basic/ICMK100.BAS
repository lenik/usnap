DECLARE SUB d24 (char$, xx!, xy!, xc!, lx$)
DECLARE SUB d16 (char$, xx!, xy!, xc!)
'$INCLUDE: 'qb.bi'
DIM inregs AS RegType, outregs AS RegType
DIM dat(1 TO 32, 1 TO 32)
SCREEN 12: CLS
inregs.ax = &H0
inregs.ax = &HFFFF
inregs.bx = &H2
CALL INTERRUPT(&H33, inregs, outregs)
inregs.ax = &H1
CALL INTERRUPT(&H33, inregs, outregs)
inregs.ax = &H7
inregs.cx = 600
inregs.dx = 600
CALL INTERRUPT(&H33, inregs, outregs)
inregs.ax = &H8
inregs.cx = 10
inregs.dx = 440
CALL INTERRUPT(&H33, inregs, outregs)
SCREEN 12
CLS
DIM c AS INTEGER: c = 0
OPEN "~~blank.tmp" FOR BINARY AS #1
FOR cs = 1 TO 765 STEP 2
PUT #1, cs, c
NEXT
CLOSE #1
FOR xt = 0 TO 32: LINE (20 + xt * 10, 50)-(20 + xt * 10, 370), 16: NEXT xt
FOR yt = 0 TO 32: LINE (20, 50 + yt * 10)-(340, 50 + yt * 10), 16: NEXT yt
FOR c = 0 TO 15
LINE (380, 50 + c * 21)-(420, 64 + c * 21), c, BF
LINE (378, 48 + c * 21)-(422, 66 + c * 21), 16, B
NEXT c
FOR c = 0 TO 9
  LINE (468, 48 + c * 34)-(572, 75 + c * 34), 15, B
NEXT c
c = 7
d24 "图标制作  版本", 20, 10, 14, "s"
d16 "：１．００", 176, 26, 14
d24 "制作", 368, 10, 13, "s"
d16 "：", 406, 26, 13
d24 "谢继雷", 432, 10, 13, "s"
d16 "新文件", 488, 54, 15
d16 "打开文件", 480, 90, 15
d16 "保存文件", 480, 124, 15
d16 "另存为", 488, 158, 15
d16 "画点", 496, 191, 15
d16 "画线", 496, 224, 15
d16 "画方框", 488, 259, 15
d16 "涂色", 496, 293, 15
d16 "改变背景色", 472, 327, 15
d16 "刷新图标", 480, 361, 15


inregs.ax = &H7
inregs.cx = 10
inregs.dx = 600
CALL INTERRUPT(&H33, inregs, outregs)
inregs.bx = &H0
inregs.ax = &H3
DO
CALL INTERRUPT(&H33, inregs, outregs)
B = outregs.bx
x = outregs.cx
y = outregs.dx

IF B = 1 THEN
  IF x > 377 AND x < 423 AND y > 48 AND y < 381 AND (y - 27) MOD 21 < 28 THEN c = (y - 27) \ 21 - 1
  IF x > 470 AND x < 570 AND y > 48 AND y < 381 AND (y - 14) MOD 34 < 28 THEN cmd = (y - 14) \ 34
  IF x > 20 AND x < 340 AND y > 50 AND y < 370 THEN xx = (x - 20) \ 10 + 1: yy = (y - 50) \ 10 + 1: dat(xx, yy) = c ': LINE (xx * 10 + 1, yy * 10 + 41)-(xx * 10 + 9, yy * 10 + 49), c, BF
  FOR xt = 1 TO 32: FOR yt = 1 TO 32: LINE (xt * 10 + 11, yt * 10 + 41)-(xt * 10 + 19, yt * 10 + 49), dat(xt, yt), BF: NEXT yt, xt
END IF
LOCATE 25, 1: PRINT "B="; B, "X="; x, "Y="; y, "C="; c, "cmd="; cmd, "Xx="; xx, "Yy="; yy
SELECT CASE cmd
  CASE 0

  CASE 9
    bc = c
  CASE 10
    FOR xt = 1 TO 32: FOR yt = 1 TO 32: dat(xt, yt) = bc: NEXT yt, xt
  CASE ELSE
END SELECT
cmd = 0
'NEXT
LOOP
END

'SEEK #1, 127
'FIELD #1, 1 AS integer
'FOR y = 32 TO 1 STEP -1
'  FOR x = 1 TO 32 STEP 2
'    GET #1, , c
'    PSET (x + 100, y + 100), ASC(c) MOD 16
'    PSET (x + 99, y + 100), ASC(c) \ 16
'NEXT: NEXT
'd$ = INPUT$(1)
'CLOSE #1
'LOOP
'CLOSE #2
     'IF y > 48 AND y < 66 THEN c = 0: GOTO qe1
     'IF y > 69 AND y < 87 THEN c = 1: GOTO qe1
     'IF y > 90 AND y < 108 THEN c = 2: GOTO qe1
     'IF y > 111 AND y < 129 THEN c = 3: GOTO qe1
     'IF y > 132 AND y < 150 THEN c = 4: GOTO qe1
     'IF y > 153 AND y < 171 THEN c = 5: GOTO qe1
     'IF y > 174 AND y < 192 THEN c = 6: GOTO qe1
     'IF y > 195 AND y < 213 THEN c = 7: GOTO qe1
     'IF y > 216 AND y < 234 THEN c = 8: GOTO qe1
     'IF y > 237 AND y < 255 THEN c = 9: GOTO qe1
     'IF y > 258 AND y < 276 THEN c = 10: GOTO qe1
     'IF y > 279 AND y < 297 THEN c = 11: GOTO qe1
     'IF y > 300 AND y < 318 THEN c = 12: GOTO qe1
     'IF y > 321 AND y < 339 THEN c = 13: GOTO qe1
     'IF y > 342 AND y < 360 THEN c = 14: GOTO qe1
     'IF y > 363 AND y < 381 THEN c = 15
'    FOR xt = 0 TO 32: LINE (20 + xt * 10, 50)-(20 + xt * 10, 370), 16: NEXT xt
'    FOR yt = 0 TO 32: LINE (20, 50 + yt * 10)-(340, 50 + yt * 10), 16: NEXT yt


SUB d16 (char$, xx, xy, xc)
OPEN "d:\ucdos\hzk16" FOR RANDOM AS #1 LEN = 1
FIELD #1, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd16
r = (qm * 94 + wm) * 32 + 1
FOR xs = 0 TO 15
GET #1, r: r = r + 1: LINE (xx + 15, xy + xs)-(xx, xy + xs), xc, , ASC(f$)
GET #1, r: r = r + 1: LINE (xx + 23, xy + xs)-(xx + 8, xy + xs), xc, , ASC(f$)
NEXT xs
endd16: xx = xx + 16
NEXT k
CLOSE #1
END SUB

SUB d24 (char$, xx, xy, xc, lx$)
OPEN "d:\ucdos\fnt\hzk24" + lx$ FOR RANDOM AS #1 LEN = 1
FIELD #1, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd24
r = ((qm - 15) * 94 + wm) * 72 + 1
FOR xs = 0 TO 23
GET #1, r: r = r + 1: LINE (xx + xs, xy)-(xx + xs, xy + 15), xc, , ASC(f$)
GET #1, r: r = r + 1: LINE (xx + xs, xy + 8)-(xx + xs, xy + 23), xc, , ASC(f$)
GET #1, r: r = r + 1: LINE (xx + xs, xy + 16)-(xx + xs, xy + 31), xc, , ASC(f$)
NEXT xs
endd24: xx = xx + 24
NEXT k
CLOSE #1
END SUB

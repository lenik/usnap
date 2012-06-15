DECLARE SUB d40 (char$, xx!, xy!, xc!, lx$)
SCREEN 9: CLS
CALL d40("°¡", 0, 0, 11, "s")

SUB d40 (char$, xx, xy, xc, lx$)
OPEN "d:\ucdos\fnt\hzk40" + lx$ FOR RANDOM AS #1 LEN = 1
FIELD #1, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd40
r = ((qm - 15) * 94 + wm) * 200 + 1
FOR xs = 0 TO 39
  FOR xh = 1 TO 5
    GET #1, r: r = r + 1: LINE (xx + (xh - 1) * 8, xy + xs)-(xx + (xh + 1) * 8 - 1, xy + xs), xc, , ASC(f$)
  NEXT xh
NEXT xs
endd40: xx = xx + 40
NEXT k
CLOSE #1
END SUB

DECLARE SUB d24 (char$, xx!, xy!, xc!, lx$)
SCREEN 9: CLS
CALL d24("°¡", 0, 8, 11, "s")

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

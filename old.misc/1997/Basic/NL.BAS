DECLARE SUB d16 (char$, xx!, xy!, xc!)
SCREEN 2: KEY OFF: CLS : PENZ = 0: cc = 7: VIEW PRINT
DIM qj(11850)
LINE (30, 30)-(200, 80), 15, B
CALL d16("      新海龟", 32, 32, 15)
CALL d16("＜回车＞进入作图", 32, 48, 15)
CALL d16("＜Ｑ＞退出新海龟", 32, 64, 15)
CALL d16("制作：谢继雷", 32, 90, 15)
80 k$ = INKEY$: IF k$ = "" THEN 80
IF k$ = "q" OR k$ = "Q" THEN END
IF k$ <> CHR$(13) THEN 80
CLS
VIEW (1, 1)-(590, 160), , 15: CLS : PSET (280, 80): X = 280: Y = 80
VIEW PRINT 22 TO 24
130 er = 0: PRINT "X="; X, "Y="; Y, "C="; cc: INPUT "New-Logo>", nl$
nl$ = LTRIM$(RTRIM$(LCASE$(nl$)))
IF LEN(nl$) < 2 THEN PRINT "       ^Error!": GOTO 130
                      zfs = 0
                      FOR js = 1 TO LEN(nl$)
                          k = ASC(MID$(nl$, js, 1))
                          IF k > 96 AND k < 123 THEN zfs = zfs + 1
                      NEXT js
                   k = zfs
         mlh$ = LEFT$(nl$, k): mlh$ = LTRIM$(RTRIM$(LCASE$(mlh$)))
         sz$ = MID$(nl$, 1 + k, LEN(nl$))
         FOR JCS = 1 TO LEN(sz$)
           IF ASC(MID$(sz$, JCS, 1)) > 57 OR ASC(MID$(sz$, JCS, 1)) < 48 THEN
           er = 1
           END IF
         NEXT JCS
        IF er = 1 THEN PRINT "       ^Error!": GOTO 130
        IF LEN(sz$) > 8 THEN PRINT "Too long!"
        IF LEN(sz$) < 5 THEN sz = VAL(sz$) ELSE file$ = sz$

  SELECT CASE mlh$
    CASE "u"
      Y = Y - sz: IF PENZ = 0 THEN LINE -(X, Y), cc ELSE PSET (X, Y), POINT(X, Y): GOTO 130
    CASE "d"
      Y = Y + sz: IF PENZ = 0 THEN LINE -(X, Y), cc ELSE PSET (X, Y), POINT(X, Y): GOTO 130
    CASE "l"
      X = X - sz: IF PENZ = 0 THEN LINE -(X, Y), cc ELSE PSET (X, Y), POINT(X, Y): GOTO 130
    CASE "r"
      X = X + sz: IF PENZ = 0 THEN LINE -(X, Y), cc ELSE PSET (X, Y), POINT(X, Y): GOTO 130
    CASE "lu"
      Y = Y - sz: X = X - sz: IF PENZ = 0 THEN LINE -(X, Y), cc ELSE PSET (X, Y), POINT(X, Y): GOTO 130
    CASE "ru"
      Y = Y - sz: X = X + sz: IF PENZ = 0 THEN LINE -(X, Y), cc ELSE PSET (X, Y), POINT(X, Y): GOTO 130
    CASE "ld"
      Y = Y + sz: X = X - sz: IF PENZ = 0 THEN LINE -(X, Y), cc ELSE PSET (X, Y), POINT(X, Y): GOTO 130
    CASE "rd"
      Y = Y + sz: X = X + sz: IF PENZ = 0 THEN LINE -(X, Y), cc ELSE PSET (X, Y), POINT(X, Y): GOTO 130
    CASE "c"
      IF sz < 0 OR sz > 15 THEN PRINT "       ^Error!": GOTO 130 ELSE cc = sz: GOTO 130
    CASE "home"
      CLS : GOTO 130
    CASE "charx"
      IF sz < 1 OR sz > 80 THEN PRINT "       ^Error!": GOTO 130 ELSE YX = sz: GOTO 130
    CASE "chary"
      IF sz < 1 OR sz > 20 THEN PRINT "       ^Error!": GOTO 130 ELSE YY = sz: GOTO 130
    CASE "chars"
      VIEW PRINT
      LOCATE YY, YX: INPUT "", char$
      VIEW PRINT 22 TO 24
      GOTO 130
    CASE "boxl"
      BX = sz: GOTO 130
    CASE "boxw"
      BY = sz: GOTO 130
    CASE "boxs"
      LINE (X, Y)-(X + BX, Y + BY), cc, B: GOTO 130
    CASE "cir"
      CIRCLE (X, Y), sz, cc: GOTO 130
    CASE "pu"
      PENZ = 1: GOTO 130
    CASE "pd"
      PENZ = 0: GOTO 130
    CASE "mtx"
      X = sz: GOTO 130
    CASE "mty"
      Y = sz: GOTO 130
    CASE "mtp"
      PSET (X, Y), POINT(X, Y): GOTO 130
    CASE "pax"
      PAX = sz: GOTO 130
    CASE "pay"
      PAY = sz: GOTO 130
    CASE "pac"
      PAC = sz: GOTO 130
    CASE "paj"
      PAJ = sz: BJSM = 1: GOTO 130
    CASE "pap"
      IF BJSM = 1 THEN
         PAINT (PAX, PAY), PAC, PAJ
      ELSE
         PAINT (PAX, PAY), PAC: GOTO 130
      END IF

    CASE "svpt"
      GET (0, 0)-(589, 159), qj
    CASE "ldpt"
      PUT (0, 0), qj, PSET
    CASE "textx"
      xx = sz: GOTO 130
    CASE "texty"
      xy = sz: GOTO 130
    CASE "textc"
      xc = sz: GOTO 130
    CASE "textn"
      tec$ = CHR$(INT(sz / 100) + 160) + CHR$(sz - INT(sz / 100) * 100 + 160): GOTO 130
    CASE "texts"
      CALL d16(tec$, xx, xy, xc)

enddd16: xx = xx + 16
      CLOSE #1
    CASE "sp"
      SP = sz
    CASE "st"
      ST = sz
    CASE "sf"
      SOUND SP, ST * 17

    CASE "shell"
      SHELL
    CASE IS = "quit"
      END
    CASE ELSE
      PRINT "       ^Error!"
  END SELECT
  GOTO 130
  END

SUB d16 (char$, xx, xy, xc)
OPEN "hzk16" FOR RANDOM AS #1 LEN = 1
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

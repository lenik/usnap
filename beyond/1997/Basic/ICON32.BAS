DECLARE FUNCTION format$ (num!, bytes!)
DECLARE FUNCTION format1$ (num$, bytes!)
OPEN "icon32" FOR OUTPUT AS #1
FOR qm = 176 TO 255
FOR wm = 161 TO 254 STEP 10
      out$ = "`M" + CHR$(qm) + CHR$(wm) + "  " + "`M" + CHR$(qm) + CHR$(wm + 1) + "  "
      out$ = out$ + "`M" + CHR$(qm) + CHR$(wm + 2) + "  " + "`M" + CHR$(qm) + CHR$(wm + 3) + "  "
IF wm < 250 THEN
      out$ = out$ + "`M" + CHR$(qm) + CHR$(wm + 4) + "  " + "`M" + CHR$(qm) + CHR$(wm + 5) + "  "
      out$ = out$ + "`M" + CHR$(qm) + CHR$(wm + 6) + "  " + "`M" + CHR$(qm) + CHR$(wm + 7) + "  "
      out$ = out$ + "`M" + CHR$(qm) + CHR$(wm + 8) + "  " + "`M" + CHR$(qm) + CHR$(wm + 9)
END IF
PRINT #1, out$
      out$ = "`N" + CHR$(qm) + CHR$(wm) + "  " + "`N" + CHR$(qm) + CHR$(wm + 1) + "  "
      out$ = out$ + "`N" + CHR$(qm) + CHR$(wm + 2) + "  " + "`N" + CHR$(qm) + CHR$(wm + 3) + "  "
IF wm < 250 THEN
      out$ = out$ + "`N" + CHR$(qm) + CHR$(wm + 4) + "  " + "`N" + CHR$(qm) + CHR$(wm + 5) + "  "
      out$ = out$ + "`N" + CHR$(qm) + CHR$(wm + 6) + "  " + "`N" + CHR$(qm) + CHR$(wm + 7) + "  "
      out$ = out$ + "`N" + CHR$(qm) + CHR$(wm + 8) + "  " + "`N" + CHR$(qm) + CHR$(wm + 9)
END IF
PRINT #1, out$
cr$ = format$((qm - 160) * 100 + wm - 160, 4): cr$ = cr$ + "  " + format$((qm - 160) * 100 + wm - 159, 4)
cr$ = cr$ + "  " + format$((qm - 160) * 100 + wm - 158, 4): cr$ = cr$ + "  " + format$((qm - 160) * 100 + wm - 157, 4)
IF wm < 250 THEN
      cr$ = cr$ + "  " + format$((qm - 160) * 100 + wm - 156, 4): cr$ = cr$ + "  " + format$((qm - 160) * 100 + wm - 155, 4)
      cr$ = cr$ + "  " + format$((qm - 160) * 100 + wm - 154, 4): cr$ = cr$ + "  " + format$((qm - 160) * 100 + wm - 153, 4)
      cr$ = cr$ + "  " + format$((qm - 160) * 100 + wm - 152, 4): cr$ = cr$ + "  " + format$((qm - 160) * 100 + wm - 151, 4)
END IF
 PRINT #1, cr$
 PRINT #1, STRING$(79, "-")

NEXT wm
PRINT #1, STRING$(79, "*")
NEXT qm
CLOSE #1

FUNCTION format$ (num, bytes)
  format$ = STRING$(bytes - LEN(LTRIM$(RTRIM$(STR$(num)))), "0") + LTRIM$(RTRIM$(STR$(num)))
END FUNCTION

FUNCTION format1$ (num$, bytes)
  format1$ = STRING$(bytes - LEN(num$), "0") + nmu$

END FUNCTION

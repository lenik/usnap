OPEN "icon32" FOR OUTPUT AS #1
FOR qm = 176 TO 255
FOR wm = 161 TO 254
PRINT #1, "`M" + CHR$(qm) + CHR$(wm)
PRINT #1, "`N" + CHR$(qm) + CHR$(wm)
qm$ = RTRIM$(LTRIM$(STR$(qm - 160)))
IF wm - 161 < 9 THEN wm$ = "0" + RTRIM$(LTRIM$(STR$(wm - 160))) ELSE wm$ = RTRIM$(LTRIM$(STR$(wm - 160)))
PRINT #1, qm$ + wm$
NEXT wm, qm

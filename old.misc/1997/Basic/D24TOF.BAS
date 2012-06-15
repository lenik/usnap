DECLARE FUNCTION format$ (num!, bytes!)
DECLARE SUB d24tof (char$)
DIM r AS DOUBLE
IF LTRIM$(RTRIM$(COMMAND$)) = "" THEN INPUT "Text:", TX$ ELSE 10
d24tof TX$
END
10 'ON ERROR GOTO cw
   n = FREEFILE: OPEN COMMAND$ FOR INPUT AS n
   DO WHILE NOT EOF(n)
   LINE INPUT #n, TX$
   TX$ = LTRIM$(RTRIM$(TX$))
   d24tof TX$
   LOOP
   END
cw: PRINT "Error!!!": END

SUB d24tof (char$)
n1 = FREEFILE
OPEN "d:\ucdos\fnt\hzk24k" FOR RANDOM AS #n1 LEN = 1
n2 = FREEFILE
OPEN "sltq" FOR APPEND AS #n2
FIELD #n1, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd16
r = ((qm - 15) * 94 + wm) * 72 + 1
PRINT #n2, "{";
FOR xs = 0 TO 23
 FOR tt = 1 TO 3
  GET #n1, r: r = r + 1: PRINT #n2, LTRIM$(RTRIM$(STR$(ASC(f$)))); : IF xs <> 23 OR tt <> 3 THEN PRINT #n2, ",";
 NEXT tt
NEXT xs
PRINT #n2, "},"
endd16:
NEXT k
CLOSE #n2
CLOSE #n1
END SUB

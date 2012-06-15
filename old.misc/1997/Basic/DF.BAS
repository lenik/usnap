DECLARE SUB d16 (char$)
INPUT "text:", tx$
d16 tx$

SUB d16 (char$)
OPEN "d:\ucdos\hzk16" FOR RANDOM AS #1 LEN = 1
OPEN "sltq" FOR OUTPUT AS #2
FIELD #1, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd16
r = (qm * 94 + wm) * 32 + 1
PRINT #2, MID$(char$, k, 1) + MID$(char$, k + 1, 1);
FOR xs = 0 TO 15
GET #1, r: r = r + 1: zero = 3 - LEN(RTRIM$(LTRIM$(STR$(ASC(f$))))): IF zero = 1 THEN zero$ = "0" ELSE IF zero = 2 THEN zero$ = "00" ELSE IF zero = 0 THEN zero$ = ""
                      PRINT #2, zero$ + RTRIM$(LTRIM$(STR$(ASC(f$))));
GET #1, r: r = r + 1: zero = 3 - LEN(RTRIM$(LTRIM$(STR$(ASC(f$))))): IF zero = 1 THEN zero$ = "0" ELSE IF zero = 2 THEN zero$ = "00" ELSE IF zero = 0 THEN zero$ = ""
                      PRINT #2, zero$ + RTRIM$(LTRIM$(STR$(ASC(f$))));
NEXT xs
PRINT #2,
endd16:
NEXT k
CLOSE #1
END SUB

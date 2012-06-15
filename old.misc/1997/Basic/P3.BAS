DECLARE SUB disp16 (s$, x0!, y0!, cc!)
SCREEN 9
CALL disp16("ÔÝÍ£", 200, 220, 10)
CALL disp16("©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥", 0, 296, 3)
CALL disp16("ªÜ±äµ÷  £Æ£¸  ÍË³ö  £Æ£±Ñ¡Çú  £Æ£²´æÅÌ  £Æ£³Çå³ý  £Æ£´ÑÝ×à", 10, 305, 14)

SUB disp16 (s$, x0, y0, cc)
 OPEN "D:\UCDOS\hzk16" FOR RANDOM AS #1 LEN = 1
 FIELD #1, 1 AS f$
 ls = LEN(s$)
 FOR K = 1 TO ls STEP 2
  qm = ASC(MID$(s$, K, 1)) - 161
  wm = ASC(MID$(s$, K + 1, 1)) - 161
  IF qm < 0 OR wm < 0 THEN GOTO z
  N = qm * 94 + wm
  r = N * 32 + 1
  FOR i = 0 TO 15
  GET #1, r: r = r + 1
  A$ = f$
FOR A = 1 TO LEN(A$)
V$ = MID$(A$, A, 1)
IF V$ = "0" THEN O = 0
IF V$ = "1" THEN O = 1
IF V$ = "2" THEN O = 2
IF V$ = "3" THEN O = 3
IF V$ = "4" THEN O = 4
IF V$ = "5" THEN O = 5
IF V$ = "6" THEN O = 6
IF V$ = "7" THEN O = 7
IF V$ = "8" THEN O = 8
IF V$ = "9" THEN O = 9
IF V$ = "a" OR V$ = "A" THEN O = 10
IF V$ = "b" OR V$ = "B" THEN O = 11
IF V$ = "c" OR V$ = "C" THEN O = 12
IF V$ = "d" OR V$ = "D" THEN O = 13
IF V$ = "e" OR V$ = "E" THEN O = 14
IF V$ = "f" OR V$ = "F" THEN O = 15
IF A <> LEN(A$) THEN K = O * 16 ELSE K = O
P = P + O * 16 ^ (LEN(A$) - A)
NEXT A
DIM k(20)
dec=p
hh = dec
10 IF INT(hh / 2) < hh / 2 THEN k(o) = 1 ELSE k(o) = 0
  o = o + 1: hh = INT(hh / 2)
  IF hh <> 0 THEN 10
  FOR p = o - 1 TO 0 STEP -1
   bin$=bin$+str$(k(p)
  NEXT p






  'LINE (x0 + 7, y0 + i)-(x0 - 8, y0 + i), cc, , ASC(f$): ' LOCATE 20, 20: PRINT LEN(f$)
  GET #1, r: r = r + 1: 'LINE (x0 + 15, y0 + i)-(x0, y0 + i), cc, , ASC(f$)
  NEXT i
z: x0 = x0 + 16
  NEXT K
  CLOSE #1
END SUB

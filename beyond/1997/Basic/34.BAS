10 CLS
20 INPUT "Your name", NA$
30 IF LEN(NA$) > 9 THEN PRINT "Too long!": GOTO 20
40 INPUT "Your age", AG
50 IF AG > 200 THEN PRINT "How are you? Do you ill?": GOTO 40
60 SCREEN 9: CLS : RANDOMIZE TIMER: K = 10: KK = 1000: L = 1: M = 5
70 L = 1: M = 5: X = 280: Y = 150
80 FOR RE = 1 TO INT(L / 3) * 30
90 X = INT(545 * RND) + 3: Y = INT(290 * RND) + 3
100 PSET (X, Y), 4
110 NEXT RE
120 CLS : KK = KK + KK: FOR WH = 1 TO 150
130 X = INT(545 * RND) + 3: Y = INT(290 * RND) + 3
140 PSET (X, Y), 15
150 NEXT WH
160 FOR YE = 1 TO 200 - (L * 20)
170 X = INT(545 * RND) + 3: Y = INT(290 * RND) + 3
180 PSET (X, Y), 14
190 NEXT YE
200 K$ = INKEY$
210 LINE (550, 0)-(550, 400), 4
220 IF K$ = "4" THEN X = X - 1
230 IF K$ = "6" THEN X = X + 1
240 IF K$ = "8" THEN Y = Y - 1
250 IF K$ = "2" THEN Y = Y + 1
260 IF K$ = "1" THEN X = X - 1: Y = Y + 1
270 IF K$ = "3" THEN X = X + 1: Y = Y + 1
280 IF K$ = "7" THEN X = X - 1: Y = Y - 1
290 IF K$ = "9" THEN X = X + 1: Y = Y - 1
300 IF K$ = "u" THEN IF X > 550 THEN X = 300 ELSE IF X < 550 THEN X = 554
310 IF K$ <> "" THEN Bs = Bs + 1
320 IF K$ = "q" THEN 450
330 IF POINT(X, Y) = 15 THEN S = S + 10
340 IF POINT(X, Y) = 14 THEN M = M + 1: PLAY "t250l64cdefgab"
350 IF POINT(X, Y) = 4 THEN M = M - 1: PLAY "t250l64ccddee"
360 IF X = 550 THEN M = M - 30: PLAY "t250l64o5bbaaggffeeddcc<bbaaggffeeddcc<baggffeeddcc<bbaaggffeeddcc<bbaaggffeeddcc"
370 IF M > K THEN PLAY "t250o2f16f16f16f16p8g16g16d16d16p8c16d16e16f8": K = M + 10
380 LOCATE 1, 71: PRINT "--NAME--": LOCATE 2, 70: PRINT NA$: LOCATE 3, 71: PRINT "--AGE--": LOCATE 4, 70: PRINT USING "##########"; AG
390 LOCATE 5, 70: PRINT "x="; USING "#######"; X: LOCATE 6, 70: PRINT "y="; USING "#######"; Y
: LOCATE 7, 70: PRINT "S="; USING "#######"; S
400 LOCATE 8, 70: PRINT "B="; USING "#######"; Bs: LOCATE 9, 70: PRINT "m="; USING "#######"; M: LOCATE 10, 70: PRINT "Level:": LOCATE 11, 70: PRINT USING "##########"; LE
410 IF M < 1 THEN PLAY "mbt200l32o2bagedfcbagedfcbagedfcbagedfco1c1": END
420 FOR O = 1 TO 20: PSET (X, Y), 15: NEXT O: PSET (X, Y), 0
430 IF S > KK THEN LE = LE + 1: GOTO 120
440 GOTO 200
450 OPEN NA$ FOR APPEND AS #1
460 PRINT #1, "Name  :", NA$
470 PRINT #1, "Age   :", AG
480 PRINT #1, "Foor  :", Bs
490 PRINT #1, "Score :", S
500 PRINT #1, "People:", M
510 PRINT #1, "Level :", LE
520 PRINT #1, "------------------------------------ TheEnd ------------------------------------"
530 PRINT #1, "------------------------ M a k i n g  : X i e J i l e i ------------------------"
540 END

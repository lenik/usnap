10 SCREEN 9: CLS : RANDOMIZE TIMER: m = 5: k = 10: KEY OFF: s = 0
20 CLS
30 INPUT "Your name(Sheng Mu) ", NA$
40 IF LEN(NA$) > 5 THEN PRINT "Too long!": GOTO 30
50 INPUT "Your age", ag
60 IF ag > 200 THEN PRINT "How are you? Do you ill?": GOTO 50
70 INPUT "Do you want to load file?", LL$
80 IF LL$ <> "Y" OR LL$ <> "y" THEN GOTO 150
90 ON ERROR GOTO 650
100 NAA$ = NA$ + "S"
110 OPEN NAA$ FOR INPUT AS #3
130 INPUT #3, NA$, ag, BS, s, m, le
150 CLS : kk = kk + 1000: FOR RE = 1 TO le * 10
160 x = INT(545 * RND) + 3: y = INT(320 * RND) + 3
170 PSET (x, y), 4
180 NEXT RE
190 FOR WH = 1 TO 300
200 x = INT(545 * RND) + 3: y = INT(320 * RND) + 3
210 PSET (x, y), 15
220 NEXT WH
230 FOR YE = 1 TO 200 - (L * 20)
240 x = INT(545 * RND) + 3: y = INT(320 * RND) + 3
250 PSET (x, y), 14
260 NEXT YE
265 x = 250: y = 150
270 k$ = INKEY$
280 LINE (550, 0)-(550, 400), 4
290 IF k$ = "4" THEN x = x - 1
300 IF k$ = "6" THEN x = x + 1
310 IF k$ = "8" THEN y = y - 1
320 IF k$ = "2" THEN y = y + 1
330 IF k$ = "1" THEN x = x - 1: y = y + 1
340 IF k$ = "3" THEN x = x + 1: y = y + 1
350 IF k$ = "7" THEN x = x - 1: y = y - 1
360 IF k$ = "9" THEN x = x + 1: y = y - 1
370 IF k$ = "l" THEN IF x > 550 THEN x = 300 ELSE IF x < 550 THEN x = 554
375 IF k$ = "e" THEN le = le + 1: GOTO 150
380 IF k$ <> "" THEN BS = BS + 1
390 IF k$ = "q" THEN 520
395 IF k$ = "x" THEN m = m + 10
400 IF POINT(x, y) = 15 THEN s = s + 10
410 IF POINT(x, y) = 14 THEN m = m + 1
420 IF POINT(x, y) = 4 THEN m = m - 5
430 IF x = 550 THEN m = m - 30
440 IF m > k THEN m = m + 1: k = k * 10
450 LOCATE 1, 71: PRINT "--NAME--": LOCATE 2, 70: PRINT NA$: LOCATE 3, 71: PRINT "--AGE--": LOCATE 4, 70: PRINT USING "##########"; ag
460 LOCATE 5, 70: PRINT "x="; USING "#######"; x: LOCATE 6, 70: PRINT "y="; USING "#######"; y: LOCATE 7, 70: PRINT "S="; USING "#######"; s
461 LOCATE 8, 70: PRINT "B="; USING "#######"; BS: LOCATE 9, 70: PRINT "m="; USING "#######"; m: LOCATE 10, 70: PRINT "Level:": LOCATE 11, 70: PRINT USING "##########"; le
462 o = m * .07
463 FOR ag = 0 TO 15
464 LINE (560 + ag * 5, 180)-(570 + ag * 5, 180 + o), 1, BF: LINE (570 + ag * 5, 180 + o)-(560 + ag * 5, 320), 4, BF
465 NEXT ag
480 IF m < 1 THEN END
490 FOR o = 1 TO 100: PSET (x, y), 15: NEXT o: PSET (x, y), 0
500 IF s > kk THEN le = le + 1: GOTO 150
510 GOTO 270
520 OPEN NA$ FOR APPEND AS #1
530 PRINT #1, "Name  :", NA$
540 PRINT #1, "Age   :", ag
550 PRINT #1, "Foor  :", BS
560 PRINT #1, "Score :", s
570 PRINT #1, "People:", m
580 PRINT #1, "Level :", le
590 PRINT #1, "------------------------------------ TheEnd ------------------------------------"
600 PRINT #1, "------------------------ M a k i n g  : X i e J i l e i ------------------------"
610 NAA$ = NA$ + "S"
620 OPEN NAA$ FOR RANDOM AS #2
630 WRITE #2, NA$, ag, BS, s, m, le
640 END
650 PRINT "File not found!!!!"
660 GOTO 70

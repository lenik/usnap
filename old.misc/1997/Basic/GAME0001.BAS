10 CLS : RANDOMIZE TIMER: NJ = 100: SSP = 10000
20 SCREEN 0, 0, 0: COLOR 15, 1: CLS
30 PRINT "         +----------------------------------+"
40 PRINT "         |   X i e  J i l e i    Game - 1.0 |"
50 PRINT "         |----------------------------------|"
60 PRINT "         |    1 --- P o w e r  O n          |"
70 PRINT "         |                                  |"
80 PRINT "         |    2 --- P o w e r  O f f        |"
90 PRINT "         +----------------------------------+"
100 INPUT "Which do you want to do?", NNN
110 IF NNN <> 1 AND NNN <> 2 THEN BEEP: GOTO 10
120 IF NNN = 2 THEN PRINT : PRINT : PRINT "Thank": PRINT : PRINT "You!": END
130 CLS : LOCATE 2, 1
140 PRINT "         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
150 PRINT "           XieJilei Game - 1.0  L e t t e r"
160 PRINT "         ****************************** --- Game ***"
170 PRINT "         *  1 -- S t a r t   *   Start to play game"
180 PRINT "         *  2 -- S p e e d   *   Change speed(Level)"
190 PRINT "         *  3 -- N  u  m     *   Change one game"
200 PRINT "         *                   *       has ?? letter"
210 PRINT "         *******************************************"
220 PRINT "         *  0 -- Q u i t     *   Exit this game"
230 PRINT "         *******************************************"
240 INPUT "What do YOU WANT to D O?", N
250 IF N <> 1 AND N <> 2 AND N <> 3 AND N <> 0 THEN BEEP: GOTO 130
260 ON N GOTO 320, 280, 300
270 END
280 CLS : LOCATE 10, 10: INPUT "S p e e d? ", SSP
290 GOTO 130
300 CLS : LOCATE 10, 10: INPUT "N U M? ", NJ
310 GOTO 130
320 CLS
330 FOR GA = 1 TO NJ
340 C$ = CHR$(INT(RND * 26) + 97): LOCATE 10, 40: PRINT C$
350 TI = TI + 1
360 IF TI > SSP THEN PLAY "mbt250l64bagfedc": SC = SC - 5: GOTO 400
365 K$ = INKEY$: IF K$ = "" THEN 350
370 IF K$ <> C$ THEN PLAY "mbt250l64bagfedc": PRINT "Pig!": SC = SC - 5: GOTO 400
380 IF K$ = C$ THEN PLAY "mbt250l64cdefgab": PRINT "Good!": SC = SC + 3: GOTO 400
390 GOTO 350
400 LOCATE 1, 60: PRINT "Score="; SC: LOCATE 2, 60: PRINT "Speed="; SSP: LOCATE 3, 60: PRINT "Num="; NJ - GA
410 NEXT GA

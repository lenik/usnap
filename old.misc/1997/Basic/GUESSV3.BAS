10 RANDOMIZE TIMER: DIM AA(10): s = 1000: CLS : OPEN "guessv3.xjl" FOR APPEND AS #1
PRINT #1, "----------------- G u e s s   G a m e  V3.0   Made:XieJilei -----------------"
20 H = 0: AA(1) = 8: AA(2) = 5: AA(3) = 4: AA(4) = 7
25 LOCATE 8, 10: PRINT "G u e s s   G a m e   V e r  3.0  M a d e : X i e J i l e i"
30 LOCATE 2, 60: PRINT "Score="; USING "##########"; s
40 LOCATE 10, 5: PRINT a1: FOR O = 1 TO 500: NEXT
50 LOCATE 10, 8: PRINT a2: FOR O = 1 TO 500: NEXT
60 LOCATE 10, 11: PRINT a3: FOR O = 1 TO 500: NEXT
70 LOCATE 10, 14: PRINT a4: FOR O = 1 TO 500: NEXT
80 IF H = 4 THEN GOTO 150
90 IF AA(1) <> 0 THEN IF a1 >= 9 THEN a1 = 0 ELSE a1 = a1 + 1
100 IF AA(2) <> 0 THEN IF a2 >= 9 THEN a2 = 0 ELSE a2 = a2 + 1
110 IF AA(3) <> 0 THEN IF a3 >= 9 THEN a3 = 0 ELSE a3 = a3 + 1
120 IF AA(4) <> 0 THEN IF a4 >= 9 THEN a4 = 0 ELSE a4 = a4 + 1
130 IF INKEY$ = CHR$(13) THEN H = H + 1: AA(H) = 0
140 GOTO 30
150 aaa = a1 * 1000 + a2 * 100 + a3 * 10 + a4
PRINT #1, "Number is"; aaa, "And Score="; INT(s)
IF (a1 = a2 - 1 AND a2 = a3 - 1 AND a3 = a4 - 1) OR (a1 = a2 + 1 AND a2 = a3 + 1 AND a3 = a4 + 1) THEN LOCATE 13, 50: PRINT aaa: s = s + aaa * 2: GOTO 20
IF a1 = a2 AND a2 = a3 AND a3 = a4 THEN s = s + a1 * 500: LOCATE 13, 10: PRINT aaa: GOTO 20
160 IF (a1 = a2 AND a2 = a3) OR (a1 = a2 AND a2 = a4) OR (a1 = a3 AND a3 = a4) OR (a2 = a3 AND a3 = a4) THEN s = s + 500 + aaa: LOCATE 13, 20: PRINT aaa: GOTO 20
170 IF a1 = a2 OR a1 = a3 OR a1 = a4 OR a2 = a3 OR a2 = a4 OR a3 = a4 THEN s = s + INT(aaa / 10): LOCATE 13, 30: PRINT aaa: GOTO 20
180 s = s - (10000 - aaa) / 10
190 IF s <= 0 THEN LOCATE 15, 20: PRINT " Y o u r ' r e      F a i l ......": CLOSE #1: END
200 LOCATE 13, 40: PRINT aaa: GOTO 20

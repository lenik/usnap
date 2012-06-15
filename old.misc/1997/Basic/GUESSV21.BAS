RANDOMIZE TIMER
10 COLOR 15, 1: SCREEN 13: CLS : KEY OFF: sc = 1000
15 FOR r = 1 TO 200 STEP 3
rn = INT(RND * 15)
20 CIRCLE (160, 100), r, rn
30 NEXT r
40 FOR x = 160 TO 30 STEP -1
rn = INT(RND * 15)
50 LINE (x, 0)-(320 - x, 200), rn
51 LINE (320 - x, 0)-(x, 200), rn
52 LINE (x + 160, 0)-(x + 160, 200), rn
53 LINE (160 - x, 0)-(160 - x, 200), rn
60 NEXT x
999 um = INT(RND * 1000)
1000 LOCATE 5, 10: PRINT "G u e s s    G a m e    V2.01"
LOCATE 7, 10: PRINT "M a k i n g : X i e J i l e i"
LOCATE 3, 20: PRINT "Score = "; USING "##########"; sc
1030 b = INT(RND * 15): b1 = INT(RND * 15): IF b = b1 THEN 1030
LOCATE 12, 10: INPUT "What's me?(0~1000)", n
IF n > um THEN LOCATE 15, 10: PRINT "T o o   B i g....": sc = sc - 10
IF n < um THEN LOCATE 15, 10: PRINT "T o o   Small....": sc = sc - 10
IF n = um THEN LOCATE 15, 10: PRINT "Ha!You're right!!": sc = sc + 500: GOTO 999
IF sc <= 0 THEN LOCATE 15, 10: PRINT "Ha!Yor're Fail!!!": END
GOTO 1000

SUB colo
b = INT(RND * 15): b1 = INT(RND * 15)
END SUB

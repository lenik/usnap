DECLARE SUB d16 (char$, xx!, xy!, xc!)
SCREEN 13: CLS
DIM sj(16000)
FOR k = 18 TO 24
 PALETTE k, (k - 18) * 10
NEXT
FOR k = 1 TO 6
 LINE (k, k)-(320 - k, 200 - k), k + 17, B
 LINE (k + 6, k + 6)-(314 - k, 194 - k), 25 - k, B
NEXT
COLOR 14
LOCATE 3, 6: PRINT "INTERNET BROWSER VERSION 2.50"
COLOR 3
LOCATE 4, 12: PRINT "MADE : Robert.King "
COLOR 1
LOCATE 6, 3: PRINT "Date / " + DATE$
LOCATE 6, 24: PRINT "Time / " + TIME$
COLOR 13
FOR k = 30 TO 34
 PALETTE k, (256 + 1) * (k - 25) * 6
NEXT
COLOR 34
LOCATE 8, 10: PRINT "1 [ Dial to INTERNET ]"
COLOR 33
LOCATE 9, 10: PRINT "2 [ Hang Up ]"
COLOR 32
LOCATE 10, 10: PRINT "3 [ Text Browser ]"
COLOR 31
LOCATE 11, 10: PRINT "4 [ Program Browser ]"
COLOR 30
LOCATE 12, 10: PRINT "0 [ Quit ]"
FOR k = 25 TO 29
 PALETTE k, (65536 + 256) * (k - 20) * 6
NEXT
d16 "按：１：拨号入国际互连网", 30, 100, 25
d16 "２：中断", 62, 116, 26
d16 "３：文本浏览器", 62, 132, 27
d16 "４：程序浏览器", 62, 148, 28
d16 "５：退出", 62, 164, 29
GET (0, 0)-(319, 199), sj
0 PUT (0, 0), sj, PSET
1 k$ = INKEY$: IF k$ = "" THEN 1
SELECT CASE k$
 CASE "1": OPEN "com2:" FOR OUTPUT AS #1
           PRINT #1, "ATDT05767444659"
           PRINT #1, "+++"
           CLOSE #1
           CLS : PRINT "Ok!"
2          IF INKEY$ = "" THEN 2
 CASE "2": OPEN "com2:" FOR OUTPUT AS #1
           PRINT #1, "+++"
           CLOSE #1
           CLS : PRINT "Ok!"
3          IF INKEY$ = "" THEN 3
 CASE "3": CLS
           SHELL "echo Terminal Computer / Huge"
           SHELL "echo Finding..."
           SHELL "dir c:\windows\*.txt/s/b>nul"
           OPEN "F:\d" FOR INPUT AS #2
           k = 4
            WHILE NOT EOF(2)
             LOCATE k
             LINE INPUT #2, m$
             PRINT m$
             k = k + 1
             IF k = 20 THEN
               k = 4
4              IF INKEY$ = "" THEN 4
             END IF
            WEND
           CLOSE #2
5          IF INKEY$ = "" THEN 5
           CLS
           INPUT "Filename:", ff$
           IF ff$ = "note" THEN SHELL "F:\xjl\q\l\note" ELSE SHELL "er f:\txt\" + ff$
 CASE "4": CLS : PRINT "File not found"
6          IF INKEY$ = "" THEN 6
 CASE "5": END
 CASE ELSE: :
END SELECT
GOTO 0

SUB d16 (char$, xx, xy, xc)
OPEN "d:\ucdos\hzk16" FOR RANDOM AS #1 LEN = 1
FIELD #1, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd16
r = (qm * 94 + wm) * 32 + 1
FOR xs = 0 TO 15
GET #1, r: r = r + 1: LINE (xx + 15, xy + xs)-(xx, xy + xs), xc, , ASC(f$)
GET #1, r: r = r + 1: LINE (xx + 23, xy + xs)-(xx + 8, xy + xs), xc, , ASC(f$)
NEXT xs
endd16: xx = xx + 16
NEXT k
CLOSE #1
END SUB

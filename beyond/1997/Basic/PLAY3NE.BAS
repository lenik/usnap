DECLARE SUB disp16 (s$, x0!, y0!, cc!)
DEFINT A-Z: DEFSNG S, X, Z
RANDOMIZE TIMER
DIM k$(0 TO 2540), zz%(0 TO 2540): qzw% = 1: qh% = 1: bc% = 1
DIM qc%(100), qm$(100), qf$(100), qw%(30), qw$(30), yf%(16)
SCREEN 9
LINE (100, 98)-(102, 100), 2
LINE (100, 98)-(98, 100), 2
LINE (99, 100)-(101, 100), 2
LINE (100, 98)-(100, 102), 2
LINE (99, 102)-(101, 102), 2
PAINT (100, 100), 2
GET (98, 98)-(102, 102), yf%
PUT (200, 200), yf%, XOR
CLS : COLOR 15, 16: YN = 1: ret = 1
PLAY "mlt255l64"
GOSUB SOIDX: GOSUB CHANDG
GOSUB ke
PUT (sx + (w - 1) * (z + 2) + z / 2, sy + 63), yf%
d:
PLAY c$: l = l + 1
IF l > 3000 THEN l = 0
LOCATE 8, 59: PRINT TIME$
a$ = INKEY$
IF a$ = CHR$(32) THEN
CALL disp16("暂停", 200, 220, 10)
SLEEP: LINE (200, 220)-(260, 240), 0, BF
END IF
IF a$ > CHR$(26) AND yr = 1 THEN PUT (sx + w * z + (w - 1) * 2, sy + 29), yf%: c$ = "": zz%(jj) = l: yr = 0: GOSUB a
IF a$ > CHR$(26) THEN PUT (sx + (w - 1) * (z + 2) + z / 2, sy + 63), yf%: c$ = "": zz%(jj) = l: GOSUB a ELSE GOTO d
a:
IF a$ = CHR$(27) THEN END
IF a$ = "/" THEN bc = bc + 1: IF bc = 64 THEN bc = 0: COLOR , bc ELSE COLOR , bc
IF a$ = "," OR a$ = "." THEN c$ = "n0"
IF a$ = "}" THEN GOSUB dr
IF a$ = "?" THEN ret = -ret
IF a$ = "`" THEN YN = YN + 1: IF YN = 7 THEN YN = 0
IF a$ = "!" THEN c$ = "n" + STR$(14 + N): w = 1: N = N + 1
IF a$ = "@" THEN c$ = "n" + STR$(16 + N): w = 2: N = N + 1
IF a$ = "$" THEN c$ = "n" + STR$(19 + N): w = 4: N = N + 1
IF a$ = "%" THEN c$ = "n" + STR$(21 + N): w = 5: N = N + 1
IF a$ = "^" THEN c$ = "n" + STR$(23 + N): w = 6: N = N + 1
IF ASC(a$) < 97 AND VAL(a$) = 0 THEN a$ = CHR$(ASC(a$) + 32): N = N + 1
IF a$ = "|" THEN c$ = "n 0 ": GOSUB CHANDG
IF a$ = "1" THEN c$ = "n" + STR$(13 + N): w = 1
IF a$ = "2" THEN c$ = "n" + STR$(15 + N): w = 2
IF a$ = "3" THEN c$ = "n" + STR$(17 + N): w = 3
IF a$ = "4" THEN c$ = "n" + STR$(18 + N): w = 4
IF a$ = "5" THEN c$ = "n" + STR$(20 + N): w = 5
IF a$ = "6" THEN c$ = "n" + STR$(22 + N): w = 6
IF a$ = "7" THEN c$ = "n" + STR$(24 + N): w = 7
IF a$ = "8" OR a$ = "9" THEN c$ = "n0"
IF a$ = "q" THEN c$ = "n" + STR$(25 + N): w = 8
IF a$ = "w" THEN c$ = "n" + STR$(27 + N): w = 9
IF a$ = "e" THEN c$ = "n" + STR$(29 + N): w = 10
IF a$ = "r" THEN c$ = "n" + STR$(30 + N): w = 11
IF a$ = "t" THEN c$ = "n" + STR$(32 + N): w = 12
IF a$ = "y" THEN c$ = "n" + STR$(34 + N): w = 13
IF a$ = "u" THEN c$ = "n" + STR$(36 + N): w = 14
IF a$ = "a" THEN c$ = "n" + STR$(37 + N): w = 15
IF a$ = "s" THEN c$ = "n" + STR$(39 + N): w = 16
IF a$ = "d" THEN c$ = "n" + STR$(41 + N): w = 17
IF a$ = "f" THEN c$ = "n" + STR$(42 + N): w = 18
IF a$ = "g" THEN c$ = "n" + STR$(44 + N): w = 19
IF a$ = "h" THEN c$ = "n" + STR$(46 + N): w = 20
IF a$ = "j" THEN c$ = "n" + STR$(48 + N): w = 21
IF a$ = "z" THEN c$ = "n" + STR$(49 + N): w = 22
IF a$ = "x" THEN c$ = "n" + STR$(51 + N): w = 23
IF a$ = "c" THEN c$ = "n" + STR$(53 + N): w = 24
IF a$ = "v" THEN c$ = "n" + STR$(54 + N): w = 25
IF a$ = "b" THEN c$ = "n" + STR$(56 + N): w = 26
IF a$ = "n" THEN c$ = "n" + STR$(58 + N): w = 27
IF a$ = "m" THEN c$ = "n" + STR$(60 + N): w = 28
IF a$ = "k" OR a$ = "o" OR a$ = "p" OR a$ = "i" OR a$ = "l" THEN c$ = "n 0 "
IF c$ <> "" AND YN > 0 THEN SOUND 32767, .03 * YN * YN
IF N <> -k AND w <> 3 AND w <> 7 AND w <> 10 AND w <> 14 AND w <> 17 AND w <> 21 AND w <> 24 AND w <> 28 THEN
PUT (sx + w * z + (w - 1) * 2, sy + 29), yf%
N = -k: yr = 1: RETURN d
END IF
N = -k
IF c$ = "" THEN PUT (sx + (w - 1) * (z + 2) + z / 2, sy + 63), yf%
IF c$ <> "" THEN PUT (sx + (w - 1) * (z + 2) + z / 2, sy + 63), yf%: GOSUB g
l = 0
RETURN d
g:
jj = jj + 1: k$(jj) = c$
IF jj = 2540 THEN jj = jj - 1
LINE (150, 95)-(150 + jj / 8.46, 103), 5, BF
LOCATE 8, 73: PRINT YN
LOCATE 23, 76: IF ret = 1 THEN PRINT "ON " ELSE PRINT "OFF"
RETURN
CHANDG:
IF dr = 0 THEN GOSUB dr: dr = dr + 1
LOCATE 4, 6: PRINT "0-C  1-bD  2-D  3-bE  4-E  5-F  6-bG  7-G  8-bA  9-A  10-bB  11-B"
LOCATE 5, 6: PRINT "key(0-11)"; : INPUT k: N = -k
IF N > 24 OR N < -14 THEN N = 0
IF N = 0 THEN l$ = "C "
IF N = -1 THEN l$ = "C#"
IF N = -2 THEN l$ = "D "
IF N = -3 THEN l$ = "bE"
IF N = -4 THEN l$ = "E "
IF N = -5 THEN l$ = "F "
IF N = -6 THEN l$ = "#F"
IF N = -7 THEN l$ = "G "
IF N = -8 THEN l$ = "bA"
IF N = -9 THEN l$ = "A "
IF N = -10 THEN l$ = "bB"
IF N = -11 THEN l$ = "B "
LOCATE 8, 10: PRINT "1="; l$
LINE (0, 10)-(640, 69), 0, BF
PLAY "n0"
RETURN
dr:
PALETTE 6, 0
CLS
 sx = 38: sy = 118: z = 12.2 * 1.5: x = 0
LINE (sx - 15, sy - 31)-(sx + (z + 2) * 28 + 15, sy + 83), 6, B
LINE (sx - 10, sy - 28)-(sx - 10, sy + 80), 15, BF
LINE (sx - 10, sy - 28)-(sx + (z + 2) * 28 + 10, sy - 28), 15, BF
LINE (sx - 10, sy + 80)-(sx + (z + 2) * 28 + 10, sy + 80), 6, BF
LINE (sx + (z + 2) * 28 + 10, sy + 80)-(sx + (z + 2) * 28 + 10, sy - 28), 6, BF
LINE (sx - 8, sy - 26)-(sx + (z + 2) * 28 + 8, sy + 78), 8, BF
LINE (36, 116)-(607, 193), 6, BF
FOR w = 1 TO 28
 LINE (sx + x, sy)-(sx + x + 12.2 * 1.5, sy + 73.2), 15, BF
 IF w <> 28 THEN
  LINE (sx + x + 12.2 * 1.5, sy + 71.2)-(sx + x + 12.2 * 1.5, sy + 73.2), 15, BF
  LINE (sx + x + 12.2 * 1.5 - 1, sy + 73.2)-(sx + x + 12.2 * 1.5, sy + 72.2), 6
  LINE (sx + x + 12.2 * 1.5, sy + 72.2)-(sx + 12.2 * 1.5 + x + 2, sy + 73.2), 6
 END IF
 x = x + z + 2
NEXT w
x = z
FOR w = 1 TO 28
 IF w = 3 OR w = 7 OR w = 10 OR w = 14 OR w = 17 OR w = 21 OR w = 24 OR w = 28 THEN GOTO c
 LINE (sx + x - 12.2 * .5, sy)-(sx + x + 12.2 * .5, sy + 36.6), 6, BF
 LINE (sx + x - 12.2 * .5 + 1, sy - 1)-(sx + x + 12.2 * .5 - 1, sy - 1), 8
 LINE (sx + x - 12.2 * .5 + 1, sy - 1)-(sx + x - 12.2 * .5 + 1, sy + 37.6), 15
 LINE (sx + x - 12.2 * .5 + 1, sy + 37.6)-(sx + x + 12.2 * .5 - 1, sy + 37.6), 6
 LINE (sx + x + 12.2 * .5 + 1, sy - 1)-(sx + x + 12.2 * .5 + 1, sy + 37.6), 6
 LINE (sx + x - 12.2 * .5 + 1, sy + 36)-(sx + x + 12.2 * .5 - 1, sy + 36), 8
 LINE (sx + x + 12.2 * .5, sy)-(sx + x + 12.2 * .5, sy + 35), 8
c: x = x + z + 2
NEXT w
LOCATE 8, 10: PRINT "1="; l$
CALL disp16("电子琴⒊３  作者￣金光铃", 180, 70, 15)
CALL disp16("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", 0, 296, 3)
CALL disp16("变调  Ｆ８  退出  Ｆ１选曲  Ｆ２存盘  Ｆ３清除  Ｆ４演奏", 10, 305, 14)
LINE (149, 94)-(149, 104), 15
LINE (150, 94)-(450, 94), 15, BF
LINE (150, 104)-(450, 104), 6, BF
LINE (451, 94)-(451, 104), 6, BF
LINE (150, 95)-(450, 103), 3, BF
CALL disp16("连音", 538, 95, 10)
CALL disp16("连续演奏", 516, 305, 10)
IF ret = 1 THEN LOCATE 23, 76: PRINT "ON " ELSE PRINT "OFF"
FOR y = 322 TO 460
LINE (0, y)-(640, y + 10), INT(RND * 16), BF
NEXT y
LINE (150, 95)-(150 + jj / 8.36, 103), 5, BF
RETURN
pl:
KEY(1) OFF
KEY(2) OFF
KEY(3) OFF
KEY(4) OFF
LINE (150, 95)-(150 + jj / 8.46, 103), 5, BF
IF jj = 0 THEN
CALL disp16("没有歌", 178, 210, 5)
BEEP: BEEP: SLEEP: kz = 1: GOSUB cl: RETURN
END IF
CALL disp16("慢（－８０  ８０）快？", 230, 220, 11)
LOCATE 19, 40: INPUT ""; fas
LOCATE 19, 20: PRINT CHR$(16); "  <<  >>  <<|  |>>  "; CHR$(219); "   ||        -  +": CALL disp16("速度", 376, 250, 10)
LOCATE 20, 20: PRINT "Q  W   E    R    T   Y   U  "; : PRINT "       I  O  "
CALL disp16("歌曲号", 110, 217, 14)
nw = 1
IF jj > 1 AND qzw = 1 THEN qw%(1) = jj: qw$(1) = "未名": qzw = 2
WHILE nw <= qzw
LINE (206, 216)-(640, 250), 0, BF
CALL disp16(qw$(nw), 206, 217, 11)
FOR o = qw%(nw - 1) TO qw%(nw)
LINE (150 + o / 8.36, 105)-(150 + o / 8.36, 110), 15
 FOR j = 0 TO zz%(o) * ABS(1 + (-fas / 80))
 PLAY k$(o)
 y$ = INKEY$
 IF y$ = "?" THEN ret = -ret
 IF y$ = "`" OR y$ = "~" THEN YN = YN + 1: LOCATE 8, 73: PRINT YN - 1: IF YN > 6 THEN YN = 0
 IF (y$ = "i" OR y$ = "I") AND fas > -80 THEN fas = fas - 1: GOTO 8
 IF (y$ = "o" OR y$ = "O") AND fas < 80 THEN fas = fas + 1: GOTO 8
 IF y$ = "E" OR y$ = "e" THEN GOTO 9
 IF y$ = "u" OR y$ = "U" THEN SLEEP: GOTO 8
 IF VAL(y$) > 0 AND (VAL(y$) + cz) < qzw THEN nw = VAL(y$) + cz: cz = 0: GOTO 10 ELSE IF cz > INT(qzw / 10) * 10 THEN cz = 0
 IF y$ = CHR$(27) THEN END
 IF (y$ = "=" OR y$ = "+") AND nw < INT(qzw / 10) * 10 THEN cz = cz + 10
 IF (y$ = "=" OR y$ = "+") AND nw >= INT(qzw / 10) * 10 THEN cz = 10
 IF y$ = "W" OR y$ = "w" THEN o = o - 2: GOTO 9
 IF (y$ = "t" OR y$ = "T") AND nw < qzw THEN nw = nw + 1: GOTO 10
 IF (y$ = "t" OR y$ = "T") AND nw = qzw THEN nw = 1: GOTO 10
 IF (y$ = "r" OR y$ = "R") AND nw = 1 THEN nw = qzw - 1: GOTO 10
 IF (y$ = "r" OR y$ = "R") AND nw >= 2 THEN nw = nw - 1: GOTO 10
 IF (y$ = "q" OR y$ = "Q") AND nw >= 1 THEN GOTO 10
 IF y$ = "y" OR y$ = "Y" THEN GOSUB cl: RETURN
 IF y$ = "/" THEN bc = bc + 1: IF bc = 64 THEN bc = 0: COLOR , bc ELSE COLOR , bc
8 LOCATE 20, 49: PRINT fas
LOCATE 23, 76: IF ret = 1 THEN PRINT "ON   " ELSE PRINT "OFF "
LOCATE 17, 21: PRINT nw;
LOCATE 8, 59: PRINT TIME$
 NEXT j
9 IF YN < 7 THEN SOUND 32767, .03 * YN * YN
 LINE (150, 105)-(450, 110), 8, BF
 NEXT o
IF nw < qzw THEN nw = nw + 1
IF nw >= qzw THEN nw = 1
IF ret = -1 AND nw = qzw THEN nw = qzw + 1
10
WEND
GOSUB cl
RETURN
re:
KEY(1) OFF
KEY(2) OFF
KEY(3) OFF
KEY(4) OFF
st = 1: aa$ = "": qh = 0: ost = 0: kz = 1: bcc = 1
WHILE aa$ <> CHR$(27)
IF ost <> st THEN
LINE (0, 210)-(640, 298), 0, BF
LOCATE 17, 15: PRINT "   ": LOCATE 17, 15: IF bcc = 1 AND qm$(st) > " " THEN COLOR 12: PRINT st ELSE COLOR 10: PRINT st
CALL disp16(qm$(st), 162, 222, 10)
LOCATE 18, 15: PRINT "   ": LOCATE 18, 15: IF bcc = 2 AND qm$(st + 1) > " " THEN COLOR 12: PRINT st + 1 ELSE COLOR 10: PRINT st + 1
CALL disp16(qm$(st + 1), 162, 237, 10)
LOCATE 19, 15: PRINT "   ": LOCATE 19, 15: IF bcc = 3 AND qm$(st + 2) > " " THEN COLOR 12: PRINT st + 2 ELSE COLOR 10: PRINT st + 2
CALL disp16(qm$(st + 2), 162, 252, 10)
LOCATE 20, 15: PRINT "   ": LOCATE 20, 15: IF bcc = 4 AND qm$(st + 3) > " " THEN COLOR 12: PRINT st + 3 ELSE COLOR 10: PRINT st + 3
CALL disp16(qm$(st + 3), 162, 267, 10)
LOCATE 21, 15: PRINT "   ": LOCATE 21, 15: IF bcc = 5 AND qm$(st + 4) > " " THEN COLOR 12: PRINT st + 4 ELSE COLOR 10: PRINT st + 4
 CALL disp16(qm$(st + 4), 162, 282, 10)
IF qm$(st) < " " THEN LOCATE 17, 15: PRINT "    "
IF qm$(st + 1) < " " THEN LOCATE 18, 15: PRINT "    "
IF qm$(st + 2) < " " THEN LOCATE 19, 15: PRINT "    "
IF qm$(st + 3) < " " THEN LOCATE 20, 15: PRINT "    "
IF qm$(st + 4) < " " THEN LOCATE 21, 15: PRINT "    "
END IF
IF obcc <> bcc THEN
LOCATE 17, 15: IF bcc = 1 THEN COLOR 12: PRINT st ELSE COLOR 10: PRINT st
IF qm$(st) < " " THEN LOCATE 17, 15: PRINT "    "
LOCATE 18, 15: IF bcc = 2 AND qm$(st + 1) > " " THEN COLOR 12: PRINT st + 1 ELSE COLOR 10: PRINT st + 1
IF qm$(st + 1) < " " THEN LOCATE 18, 15: PRINT "    "
LOCATE 19, 15: IF bcc = 3 AND qm$(st + 2) > " " THEN COLOR 12: PRINT st + 2 ELSE COLOR 10: PRINT st + 2
IF qm$(st + 2) < " " THEN LOCATE 19, 15: PRINT "    "
LOCATE 20, 15: IF bcc = 4 AND qm$(st + 3) > " " THEN COLOR 12: PRINT st + 3 ELSE COLOR 10: PRINT st + 3
IF qm$(st + 3) < " " THEN LOCATE 20, 15: PRINT "    "
LOCATE 21, 15: IF bcc = 5 AND qm$(st + 4) > " " THEN COLOR 12: PRINT st + 4 ELSE COLOR 10: PRINT st + 4
IF qm$(st + 4) < " " THEN LOCATE 21, 15: PRINT "    "
END IF: COLOR 15
IF aa$ = " " THEN
LOCATE 16, 32: CALL disp16("请点歌", 178, 205, 10): INPUT qh
END IF
IF aa$ = CHR$(13) THEN qh = st + bcc - 1
IF qh < 0 THEN GOSUB cl: RETURN
IF qh = 0 THEN LINE (178, 205)-(300, 221), 0, BF
IF qh > qz THEN
CALL disp16("没有这首歌", 300, 210, 12): SLEEP: GOSUB cl: RETURN
END IF
IF jj + qc%(qh) >= 2540 THEN BEEP: SLEEP: GOSUB cl: RETURN
IF qzw > 16 THEN
CALL disp16("没有空间", 300, 210, 12): SLEEP: GOSUB cl: RETURN
END IF
IF qh > 0 AND qh < qz THEN
LOCATE 20, 36: CALL disp16("读谱", 378, 210, 10): GOTO ra
END IF
aa$ = INKEY$
ost = st: obcc = bcc
IF aa$ = CHR$(0) + "P" THEN bcc = bcc + 1
IF aa$ = CHR$(0) + "M" AND st < qz - 5 THEN st = st + 5
IF aa$ = CHR$(0) + "K" AND st > 5 THEN st = st - 5
IF bcc > 5 THEN bcc = 1
IF aa$ = CHR$(0) + "H" THEN bcc = bcc - 1
IF bcc < 1 THEN bcc = 5
WEND
GOSUB cl
RETURN
ra: OPEN qf$(qh) FOR INPUT AS #2
WHILE NOT EOF(2)
INPUT #2, k$(jj + 1), zz%(jj + 1), k$(jj + 2), zz%(jj + 2), k$(jj + 3), zz%(jj + 3), k$(jj + 4), zz%(jj + 4)
jj = jj + 4
WEND
qw%(qzw) = jj
qw$(qzw) = qm$(qh)
qzw = qzw + 1
CLOSE #2: GOSUB cl
RETURN
sa:
KEY(1) OFF
KEY(2) OFF
KEY(3) OFF
KEY(4) OFF
LOCATE 18, 30
CALL disp16("输入文件名", 238, 210, 13): INPUT qm$
LINE (238, 210)-(360, 230), 0, BF
IF qm$ <= " " THEN LOCATE 18, 30: PRINT SPC(40); : RETURN
FOR zo = 1 TO LEN(qm$)
IF MID$(qm$, zo, 1) = "." THEN GOTO T
NEXT zo
qm$ = qm$ + ".SOU"
T: qm$ = "c:\DOS\BASIC\SOUND\" + qm$
LINE (238, 210)-(400, 230), 0, BF
CALL disp16("写谱", 378, 210, 13)
LINE (378, 210)-(500, 230), 0, BF
LOCATE 20, 25: PRINT SPC(50);
OPEN qm$ FOR OUTPUT AS #1
FOR o = 1 TO jj STEP 4
WRITE #1, k$(o), zz%(o), k$(o + 1), zz%(o + 1), k$(o + 2), zz%(o + 2), k$(o + 3), zz%(o + 3)
NEXT o
CLOSE #1
LOCATE 18, 30: CALL disp16("详细歌名", 238, 210, 13): INPUT qz$
LINE (238, 210)-(400, 230), 0, BF
OPEN "C:\DOS\BASIC\SOUND\CSOUND.IDX" FOR APPEND AS #2
WRITE #2, qz$, qm$, jj
CLOSE #2
LOCATE 18, 30: PRINT SPC(50);
qh = 0: GOSUB cl: GOSUB SOIDX
RETURN
cl:
KEY(1) ON: KEY(2) ON
KEY(3) ON: KEY(4) ON
LINE (150 + o / 8.36, 105)-(150 + o / 8.36, 110), 7
LINE (0, 205)-(640, 297), 0, BF
IF kz = 0 THEN CALL disp16("清除", 280, 210, 15): LOCATE 18, 36: INPUT o$
LINE (278, 210)-(380, 230), 0, BF
IF kz = 1 THEN kz = 0: GOTO DZ
c$ = "N 0 "
IF o$ = "Y" OR o$ = "y" THEN
 jj = 0: qzw = 1: LINE (150, 95)-(450, 103), 3, BF
 LINE (150, 105)-(450, 110), 8, BF
END IF
DZ: LOCATE 18, 36: PRINT SPC(10);
RETURN
er:
BEEP: BEEP: BEEP
IF ERR = 53 THEN
CALL disp16("文件没找到", 178, 210, 15): SLEEP
LINE (178, 210)-(300, 230), 0, BF: RESUME re
END IF
IF ERR = 54 THEN
CALL disp16("文件格式不对", 178, 210, 4): SLEEP
LINE (178, 210)-(300, 230), 0, BF: RESUME re
END IF
IF ERR = 64 THEN
CALL disp16("错误的文件名", 178, 210, 4): SLEEP
LINE (178, 210)-(300, 230), 0, BF: RESUME sa
END IF
IF ERR = 58 THEN
CALL disp16("文件已存在", 178, 210, 4): SLEEP
LINE (178, 210)-(300, 230), 0, BF: RESUME re
END IF
IF ERR = 76 OR ERR = 75 THEN
CALL disp16("路径错误", 178, 210, 4): SLEEP
LINE (178, 210)-(300, 230), 0, BF: RESUME re
END IF
kz = 1: GOSUB cl: GOTO d
SOIDX:
OPEN "nul" FOR INPUT AS #1
 WHILE NOT EOF(1)
 INPUT #1, qm$(qh), qf$(qh), qc%(qh)
 qh = qh + 1
 WEND: qz = qh
 CLOSE #1
RETURN
ed:
CALL disp16("结束（Ｙ／Ｎ）", 280, 250, 11)
LOCATE 21, 40: INPUT k$
IF k$ = "y" OR k$ = "Y" THEN END
LINE (280, 250)-(420, 270), 0, BF
LOCATE 21, 31: PRINT SPC(12);
RETURN
ke:
KEY(8) ON: KEY(1) ON
KEY(2) ON: KEY(3) ON
KEY(4) ON
ON ERROR GOTO er
ON KEY(8) GOSUB ed
ON KEY(1) GOSUB re
ON KEY(2) GOSUB sa
ON KEY(3) GOSUB cl
ON KEY(4) GOSUB pl
RETURN

DEFSNG A-R, T-W, Y
SUB disp16 (s$, x0, y0, cc)
 OPEN "C:\UCDOS\hzk16" FOR RANDOM AS #1 LEN = 1
 FIELD #1, 1 AS f$
 ls = LEN(s$)
 FOR k = 1 TO ls STEP 2
  qm = ASC(MID$(s$, k, 1)) - 161
  wm = ASC(MID$(s$, k + 1, 1)) - 161
  IF qm < 0 OR wm < 0 THEN GOTO z
  N = qm * 94 + wm
  r = N * 32 + 1
  FOR i = 0 TO 15
  GET #1, r: r = r + 1: LINE (x0 + 7, y0 + i)-(x0 - 8, y0 + i), cc, , ASC(f$)
  GET #1, r: r = r + 1: LINE (x0 + 15, y0 + i)-(x0, y0 + i), cc, , ASC(f$)
  NEXT i
z: x0 = x0 + 16
  NEXT k
  CLOSE #1
END SUB

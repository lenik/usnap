DECLARE SUB hz (char$, xx!, yy!, xc!)
CALL bwcga
SCREEN 1: CLS : RANDOMIZE TIMER: DIM p$(1 TO 4, 1 TO 8), q$(4, 8), bj(111), zw$(1 TO 27), BF(1 TO 4), md(1000)
turn = 0: FOR c! = 1 TO 27: READ zw$(c!): NEXT c!: i = 63: cs = 1: z$ = "ABBCCDDEEFFGGGGGabbccddeeffggggg"
       hz zw$(15), 0, 0, 1: hz zw$(16), 25, 0, 1: hz zw$(17), 50, 0, 1: hz zw$(18), 75, 0, 1: hz zw$(23), 100, 0, 1: hz zw$(24), 125, 0, 1: hz zw$(25), 150, 0, 1: hz zw$(26), 175, 0, 1: hz zw$(27), 200, 0, 1
       GET (0, 0)-(232, 16), md
IF LTRIM$(COMMAND$) <> "" THEN
   a = FREEFILE: OPEN COMMAND$ + ".cfg" FOR INPUT AS #a: INPUT #1, turn, z$, pp$
   FOR pbx = 1 TO 4: FOR pby = 1 TO 8: q$(pbx, pby) = LTRIM$(MID$(pp$, (pbx - 1) * 8 + pby, 1)): NEXT pby, pbx: CLOSE #a
END IF
FOR pbx = 1 TO 4: FOR pby = 1 TO 8
    wz = INT(RND * LEN(z$)) + 1
    p$(pbx, pby) = MID$(z$, wz, 1)
    IF LTRIM$(COMMAND$) <> "" THEN q$(pbx, pby) = MID$(pp$, wz, 1)
    IF LTRIM$(p$(pbx, pby)) <> "" THEN IF LTRIM$(COMMAND$) = "" THEN IF ASC(p$(pbx, pby)) < 72 THEN q$(pbx, pby) = "D" ELSE q$(pbx, pby) = "d"
    z$ = MID$(z$, 1, wz - 1) + MID$(z$, wz + 1, LEN(z$))
    IF LTRIM$(COMMAND$) <> "" THEN pp$ = MID$(pp$, 1, wz - 1) + MID$(pp$, wz + 1, LEN(z$))
NEXT pby, pbx: x = 1: y = 1: GOTO retst
start: k$ = INKEY$: IF k$ = "" THEN GOTO start
ox = x: oy = y
  IF k$ = CHR$(0) + CHR$(72) OR k$ = "8" THEN IF y > 1 THEN y = y - 1
  IF k$ = CHR$(0) + CHR$(80) OR k$ = "6" THEN IF y < 8 THEN y = y + 1
  IF k$ = CHR$(0) + CHR$(75) OR k$ = "2" THEN IF x > 1 THEN x = x - 1
  IF k$ = CHR$(0) + CHR$(77) OR k$ = "4" THEN IF x < 4 THEN x = x + 1
  IF k$ = CHR$(17) THEN GOTO fni
  IF k$ = " " OR k$ = CHR$(13) THEN GOTO cl
retst: IF cs = 1 THEN
         CLS : af = 0: BF = 0: FOR pbx = 1 TO 4: FOR pby = 1 TO 8: IF LTRIM$(q$(pbx, pby)) <> "" THEN CIRCLE (pbx * 25 + 10, pby * 21 + 10), 10, 4: PAINT (pbx * 25 + 10, pby * 21 + 11), c, c
         IF LTRIM$(p$(pbx, pby)) <> "" THEN
             IF ASC(p$(pbx, pby)) < 90 THEN af = af + 1
             IF ASC(p$(pbx, pby)) > 90 THEN BF = BF + 1
         END IF
         NEXT pby, pbx: cs = 0
        IF BF = 0 THEN LOCATE 20, 18: PRINT "Black Win!!!!!!": GOTO fni
        IF af = 0 THEN LOCATE 20, 18: PRINT "Blue Win!!!!!?": GOTO fni
        FOR pbx = 1 TO 5: LINE (pbx * 25 - 3, 21)-(pbx * 25 - 3, 189), 12: NEXT: FOR pby = 1 TO 9: LINE (22, pby * 21)-(122, pby * 21), 12: NEXT
        PUT (0, 0), md, PSET
       LINE (200, 150)-(215, 165), 4, BF: hz zw$(8 - turn * 7), 192, 150, 2 - turn * 2
        FOR pbx = 1 TO 4: FOR pby = 1 TO 8
         SELECT CASE p$(pbx, pby)
           CASE "A", "B", "C", "D", "E", "F", "G": IF q$(pbx, pby) <> "D" THEN hz zw$(ASC(p$(pbx, pby)) - 64), pbx * 25 - 6, pby * 21 + 3, 0
           CASE "a", "b", "c", "d", "e", "f", "g": IF q$(pbx, pby) <> "d" THEN hz zw$(ASC(p$(pbx, pby)) - 89), pbx * 25 - 6, pby * 21 + 3, 2
         CASE ELSE: END SELECT: NEXT pby, pbx
       END IF
       IF cs = 2 THEN
         SELECT CASE p$(x, y)
           CASE "A", "B", "C", "D", "E", "F", "G": IF q$(x, y) <> "D" THEN hz zw$(ASC(p$(x, y)) - 64), x * 25 - 6, y * 21 + 3, 0
           CASE "a", "b", "c", "d", "e", "f", "g": IF q$(x, y) <> "d" THEN hz zw$(ASC(p$(x, y)) - 89), x * 25 - 6, y * 21 + 3, 2
         CASE ELSE: END SELECT: cs = 0
       END IF
  DRAW "c0bm" + STR$(ox * 25 - 1) + "," + STR$(oy * 21 + 2) + "r4g4u3r2g1" + "bm" + STR$(ox * 25 + 20) + "," + STR$(oy * 21 + 2) + "d4h4r3d2h1"
  DRAW "bm" + STR$(ox * 25 - 1) + "," + STR$(oy * 21 + 19) + "u4f4l3u2f2bm" + STR$(ox * 25 + 20) + "," + STR$(oy * 21 + 19) + "u4g4r3u2g2"
  DRAW "c12bm" + STR$(x * 25 - 1) + "," + STR$(y * 21 + 2) + "r4g4u3r2g1" + "bm" + STR$(x * 25 + 20) + "," + STR$(y * 21 + 2) + "d4h4r3d2h1"
  DRAW "bm" + STR$(x * 25 - 1) + "," + STR$(y * 21 + 19) + "u4f4l3u2f2bm" + STR$(x * 25 + 20) + "," + STR$(y * 21 + 19) + "u4g4r3u2g2"
GOTO start
cl: IF q$(x, y) = "D" AND turn = 1 THEN q$(x, y) = "E": turn = 0: cs = 2: GOTO retst
    IF q$(x, y) = "d" AND turn = 0 THEN q$(x, y) = "e": turn = 1: cs = 2: GOTO retst
    IF q$(x, y) = "E" AND turn = 1 THEN GOTO movef
    IF q$(x, y) = "e" AND turn = 0 THEN GOTO movef
GOTO retst
movef: FOR tmp = 1 TO 4: BF(tmp) = 0: NEXT
       LINE (190, 100)-(224, 100), 14: LINE (207, 85)-(207, 115), 14
       IF y - 1 > 0 THEN IF UCASE$(q$(x, y - 1)) <> "D" THEN hz zw$(19), 191, 70, 2: BF(1) = 1
       IF x + 1 < 5 THEN IF UCASE$(q$(x + 1, y)) <> "D" THEN hz zw$(20), 215, 93, 2: BF(2) = 1
       IF y + 1 < 9 THEN IF UCASE$(q$(x, y + 1)) <> "D" THEN hz zw$(21), 191, 115, 2: BF(3) = 1
       IF x - 1 > 0 THEN IF UCASE$(q$(x - 1, y)) <> "D" THEN hz zw$(22), 165, 93, 2: BF(4) = 1
       FOR tmp = 1 TO 4: tmpp = tmpp + BF(tmp): NEXT
       IF tmpp = 0 THEN GOTO retst
xz:    num = 0: N$ = INKEY$: IF N$ = "" THEN GOTO xz
       IF N$ = CHR$(0) + CHR$(72) OR N$ = "8" THEN IF y - 1 > 0 AND UCASE$(q$(x, y - 1)) <> "D" THEN num = 8
       IF N$ = CHR$(0) + CHR$(77) OR N$ = "6" THEN IF x + 1 < 5 AND UCASE$(q$(x + 1, y)) <> "D" THEN num = 6
       IF N$ = CHR$(0) + CHR$(80) OR N$ = "2" THEN IF y + 1 < 9 AND UCASE$(q$(x, y + 1)) <> "D" THEN num = 2
       IF N$ = CHR$(0) + CHR$(75) OR N$ = "4" THEN IF x - 1 > 0 AND UCASE$(q$(x - 1, y)) <> "D" THEN num = 4
       IF num = 0 THEN GOTO xz
ex:
xx = x: yy = y
SELECT CASE num:  CASE 8: yy = y - 1: CASE 6: xx = x + 1: CASE 2: yy = y + 1: CASE 4: xx = x - 1: CASE ELSE: END SELECT
IF LCASE$(q$(xx, yy)) = "d" THEN cs = 1: GOTO retst
IF LTRIM$(q$(xx, yy)) = "" THEN q$(xx, yy) = q$(x, y): q$(x, y) = "": p$(xx, yy) = p$(x, y): p$(x, y) = "": cs = 1: turn = 1 - turn: GOTO retst
IF ABS(ASC(p$(xx, yy)) - ASC(p$(x, y))) > 10 AND ASC(LCASE$(p$(x, y))) <= ASC(LCASE$(p$(xx, yy))) AND ASC(LCASE$(p$(x, y))) - ASC(LCASE$(p$(xx, yy))) <> -6 AND ASC(p$(x, y)) - ASC(p$(xx, yy)) <> -38 THEN p$(xx, yy) = p$(x, y): p$(x, y) = "": q$(xx,  _
yy) = q$(x, y): q$(x, y) = "": turn = 1 - turn: cs = 1: GOTO retst
IF p$(xx, yy) = "A" AND p$(x, y) = "g" THEN p$(xx, yy) = p$(x, y): p$(x, y) = "": q$(xx, yy) = q$(x, y): q$(x, y) = "": turn = 1 - turn: cs = 1: GOTO retst
IF p$(xx, yy) = "a" AND p$(x, y) = "G" THEN p$(xx, yy) = p$(x, y): p$(x, y) = "": q$(xx, yy) = q$(x, y): q$(x, y) = "": turn = 1 - turn
cs = 1: GOTO retst
GOTO start
fni: a$ = INPUT$(1)
END
DATA"015240048012068034068034149253149037149037149037149037149037133037137045080034064034048012015240","015240048012068066072066152065171253136065136065136065136065136065136065073242064002048012015240"
DATA"015240048012068002068250191137132137140249142137149137148249164137132137068250068002048012015240","015240056028097134079242193131143241137145143241137145143241129129223251065130097134056028015240"
DATA"015240048012071226066034130033130033130033131249128009128009159233128009064018064098048012015240","015240056028096134064130222251140009136233158169170233138137138185206131064250096006056028015240"
DATA"015240048012064194071002132001132001135241132065132065132065191253130065068034072018048012015240","015240059220123014090102219115219167192015251247194001219247218119219183091230123206059028015240"
DATA"015240063252126126126126254127254127192003254127254127254127254127254127126126096006063252015240","015240061252112030103190255127224007238247224007253255226239253015226063125094099070062252013240"
DATA"015240062124126126096006254127240015246111240015246111240015254127254127064002126126062124015240","015240063252096030125222253223253223253223253223252007255247255247192023127246127238063028015240"
DATA"015240063124127126065002246123228251205011131107171011235099235127235127099122127002063252015240","015240060252127126096006251191251191229079206231254255192003254255254255126254126254062252015240"
DATA"001000001000001004127254065004065004065004065004127252065004001000001000001000001000001000001000","000004127254064036095244065004065004065068079228065004065068065036065004095244064004127252064004"
DATA"008000015224016072063252097008161008063248006016025032098192012192049160006144024142098132001000","017008017008019252017008253008017248049008057008085248081008145008023254016000017008019006020002"
DATA"003224012024017196035098038050070049067097065193067097070049038050035098017196012024003224000000","003224012024017228035050038018070001070193071097071049070049038050035098017196012024003224000000"
DATA"003224012024017196035098038050068049064049064097064193065129035018039242016004012024003224000000","003224012024016068032194033194066193066193068193068193079241032194032194017228012024003224000000"
DATA"004004036004037004063164036036068164255228004036063164036164036164036132038132037004004020004008","009000009000009004017254018128050128084144152248016128016128016136016252016128016128016128016128"
DATA"000000000000000000000000000000000000006000015000015000006000000000006000015000015000006000000000"
DATA"016032018032034032035036074172250112018032035252066032250112066172003036026032226036067254000000","000016063248001000127254065002157116001000029112001000063248033008033008063248033008033008063248"

SUB hz (char$, xx, yy, xc)
FOR dr = 0 TO 15
  LINE (xx + 15, yy + dr)-(xx, yy + dr), xc, , VAL(MID$(char$, dr * 6 + 1, 3))
  LINE (xx + 23, yy + dr)-(xx + 8, yy + dr), xc, , VAL(MID$(char$, dr * 6 + 4, 3))
NEXT dr
END SUB

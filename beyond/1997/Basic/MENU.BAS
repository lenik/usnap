SCREEN 2: CLS : DIM a$(3)
a$(1) = "M a d e : X i e J i l e i"
a$(2) = "H e l l o ! L i n W e i !"
a$(3) = "Happy  birthday  to  you!"
FOR co = 1 TO 2
CLS
FOR h = 1 TO LEN(a$(1))
LOCATE 1, 1: PRINT MID$(a$(co), h, 1)
FOR y = 0 TO 15: FOR x = 0 TO 8
IF POINT(x, y) <> 0 THEN FOR r = 1 TO 5: CIRCLE (x * 5 + h * 24, 80 + y * 5), r, 15: NEXT r
NEXT x, y
NEXT h
10 IF INKEY$ = "" THEN 10
NEXT co
CLS
FOR h = 1 TO LEN(a$(3))
LOCATE 1, 1: PRINT MID$(a$(3), h, 1)
FOR y = 0 TO 15: FOR x = 0 TO 8
IF POINT(x, y) <> 0 THEN FOR r = 1 TO 3: CIRCLE (x * 3 + h * 24, 80 + y * 3), r, 15: NEXT r
NEXT x, y, h
20 IF INKEY$ = "" THEN 20

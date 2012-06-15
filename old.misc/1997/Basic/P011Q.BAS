DECLARE SUB dd (c!, he!)
DIM pi AS INTEGER
pi = 3.14159
SCREEN 12: CLS
 LINE (160, 190)-(170, 200), 3, BF
 FOR he = 178 TO 0 STEP -1
 dd 2, he
 FOR c = 1 TO 32767
 NEXT
 dd 0, he
 NEXT

DATA 5,0,4,1 ,6,1 ,3,2 ,7,2 ,3,3 ,7,3 ,3,4 ,7,4 , 3,5,7,5 ,3,6 ,7,6 ,3,7 ,7,7 ,2,8 ,8,8 ,1,9 ,9,9 ,0 ,10,1,10,2,10,3,10,4,10,5,10,6,10,7,10,8,10,9,10,10,10,3,11,4,11,6,11,7,11

SUB dd (c, he)
DIM xy(33, 1) AS INTEGER, dot AS INTEGER
RESTORE

FOR xx = 0 TO 33: READ xy(xx, 0), xy(xx, 1): NEXT
FOR dot = 0 TO 33: PSET (160 + xy(dot, 0), he + xy(dot, 1)), c: NEXT
END SUB

DECLARE SUB X97 ()
DECLARE SUB d16 (char$, xx!, xy!, xc!)
DECLARE SUB X96 ()
DECLARE SUB pause (r$)
DECLARE SUB ysc (sj!)
DECLARE SUB d16xcsc (char$, xx!, xy!, xc!, sc!)
DECLARE SUB d16xycsc (char$, xx!, xy!, xc!, scx!, scy!)
DEFINT S
DIM sj(8952), smfl(625)
ON ERROR GOTO serr
     OPEN "\sys\pa.dat" FOR INPUT AS 2
     IF NOT EOF(2) THEN
       INPUT #2, pa$
     END IF
     CLOSE #2

SCREEN 2: CLS
CALL d16xcsc("�ة���", 8, 0, INT(RND * 15) + 1, 3)
CALL d16xcsc("�����޿ˡ�����������", 156, 0, INT(RND * 15) + 1, 3)
GET (9, 0)-(632, 15), smfl
CALL d16xcsc("л����  ���������ꣳ��", 200, 20, INT(RND * 15) + 1, 2)
CALL d16xycsc("���������������", 100, 100, INT(RND * 15) + 1, 1.99999, 1)
CALL pause(a$)
CLS
FOR r = 1 TO 100 STEP 4
CIRCLE (300, 100), r
IF a = 2 THEN CIRCLE (300 - r + 1, 100), r: CIRCLE (300 + r + 1, 100), r: a = 0 ELSE a = a + 1
NEXT
FOR r = 200 TO 400 STEP 4
CIRCLE (300, 100), r
IF a = 2 THEN CIRCLE (300 - r + 1, 100), r: CIRCLE (300 + r + 1, 100), r: a = 0 ELSE a = a + 1
NEXT
FOR x = 0 TO 320 STEP 2
CALL ysc(50)
LINE (x, 0)-(x, 220), 0
LINE (640 - x, 0)-(640 - x, 220), 0
NEXT
FOR y = 0 TO 220 STEP 2
CALL ysc(100)
LINE (0, y)-(640, y), 0
NEXT
CALL d16xcsc("�ة���", 8, 0, INT(RND * 15) + 1, 3)
CALL d16xcsc("�����޿ˡ�����������", 156, 0, INT(RND * 15) + 1, 3)
CALL d16xcsc("Ŀ  ¼", 230, 20, INT(RND * 15) + 1, 2.5)
CALL d16xcsc("��  ����ά��    ��  ����", 20, 60, INT(RND * 15) + 1, 2.3)
CALL d16xcsc("��  �����Ϸ    ��  �ǣף£��ӣɣ�", 20, 80, INT(RND * 15) + 1, 2.3)
CALL d16xcsc("��  ��Ϣ����        �˳�", 20, 100, INT(RND * 15) + 1, 2.3)
CALL d16xcsc("ʹ��Ȩ�ޣ�������", 240, 170, INT(RND * 15) + 1, 3)
DRAW "bm332,102l12r3d12l3r12l9u6r6br12l6d3r6d3l6bu6br16l6d6r6"
GET (0, 0)-(639, 199), sj
start: SCREEN 2
       CALL d16xcsc("������", 0, 136, 0, 3)
       CALL d16xcsc("���룺", 0, 136, INT(RND * 15) + 1, 3)
       LOCATE 18, 20: INPUT "", op$
       IF op$ <> pa$ THEN GOTO start
PUT (0, 0), sj, PSET
ss: CALL pause(a$)
SELECT CASE a$
   CASE "1"
     OPEN "\sys\pa.dat" FOR INPUT AS 2
     IF NOT EOF(2) THEN
       CALL d16xcsc("������", 0, 136, INT(RND * 15) + 1, 3)
       INPUT #2, pa$
       LOCATE 18, 20: INPUT "", op$
       IF op$ <> pa$ THEN BEEP ELSE CALL d16xcsc("������", 0, 155, INT(RND * 15) + 1, 3): LOCATE 21, 20: INPUT "", np$: pa$ = np$
     END IF
     CLOSE #2
     OPEN "\sys\pa.dat" FOR OUTPUT AS 2
     PRINT #2, pa$
     CLOSE #2
   CASE "2"
     SHELL "xqmono"
   CASE "3"
     SHELL "prince  "
   CASE "4"
     SHELL "GW ST."
   CASE "5"
     CALL X97
   CASE CHR$(27)
     SHELL "Boot"
   CASE ELSE
     GOTO ss
END SELECT
GOTO start
serr: RESUME NEXT

DEFSNG S
SUB d16 (char$, xx, xy, xc)
OPEN "hzk16" FOR RANDOM AS #1 LEN = 1
FIELD #1, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd16
r = (qm * 94 + wm) * 32 + 1
FOR xs = 0 TO 15
GET #1, r: r = r + 1: LINE (xx + 7, xy + xs)-(xx - 8, xy + xs), xc, , ASC(f$)
GET #1, r: r = r + 1: LINE (xx + 15, xy + xs)-(xx, xy + xs), xc, , ASC(f$)
NEXT xs
endd16: xx = xx + 16
NEXT k
CLOSE #1
END SUB

SUB d16xcsc (char$, xx, xy, xc, sc)
OPEN "hzk16" FOR RANDOM AS #1 LEN = 1
FIELD #1, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd16xcsc
r = (qm * 94 + wm) * 32 + 1
FOR xs = 0 TO 15
GET #1, r: r = r + 1
      f = ASC(f$)
      FOR t = 7 TO 0 STEP -1
      IF f / 2 <> INT(f / 2) THEN LINE (xx + t * sc, xy + xs)-(xx + INT(t + sc / 2) * sc, xy + xs), xc, BF
      f = INT(f / 2)
      NEXT t
GET #1, r: r = r + 1
      f = ASC(f$)
      FOR t = 15 TO 8 STEP -1
      IF f / 2 <> INT(f / 2) THEN LINE (xx + t * sc, xy + xs)-(xx + INT(t + sc / 2) * sc, xy + xs), xc, BF
      f = INT(f / 2)
      NEXT t
NEXT xs
endd16xcsc: xx = xx + 16 * sc
NEXT k
CLOSE #1
END SUB

SUB d16xycsc (char$, xx, xy, xc, scx, scy)
OPEN "hzk16" FOR RANDOM AS #1 LEN = 1
FIELD #1, 1 AS f$
FOR k = 1 TO LEN(char$) STEP 2
qm = ASC(MID$(char$, k, 1)) - 161
wm = ASC(MID$(char$, k + 1, 1)) - 161
IF qm < 0 OR wm < 0 THEN GOTO endd16xycsc
r = (qm * 94 + wm) * 32 + 1
FOR xs = 0 TO 15
GET #1, r: r = r + 1
      f = ASC(f$)
      FOR t = 7 TO 0 STEP -1
      IF f / 2 <> INT(f / 2) THEN LINE (xx + t * scx, xy + xs * scy)-(xx + INT(t + scx / 2) * scx, xy + INT(xs + scy / 2) * scy), xc, BF
      f = INT(f / 2)
      NEXT t
GET #1, r: r = r + 1
      f = ASC(f$)
      FOR t = 15 TO 8 STEP -1
      IF f / 2 <> INT(f / 2) THEN LINE (xx + t * scx, xy + xs * scy)-(xx + INT(t + scx / 2) * scx, xy + INT(xs + scy / 2) * scy), xc, BF
      f = INT(f / 2)
      NEXT t
NEXT xs
endd16xycsc: xx = xx + 16 * scx
NEXT k
CLOSE #1

END SUB

SUB pause (r$)
MOMENT: r$ = INKEY$: IF r$ = "" THEN GOTO MOMENT
END SUB

SUB X97
CLS
CALL d16xycsc("        ��Ϣ����", 8, 0, INT(RND * 14) + 1, 3, 2)
CALL d16("�����㽭ʡ���س��ųǶ�·������  ����������������", 8, 48, INT(RND * 14) + 1)
CALL d16("            л����  ���գ�  ����������������������������", 8, 70, INT(RND * 14) + 1)
CALL d16("    һ�������ṩ�������ṩ��ʮ����������������Ϸ����ѧ�����ֹ���", 8, 100, INT(RND * 14) + 1)
CALL d16("        �Լ����ֲ���ϵͳ�ͱ�̻������շѻ����ϣ��ף�Ԫ�����̣���Ԫ��", 8, 116, INT(RND * 14) + 1)
CALL d16("    ����������ƣ�������桢�̱ꡢ������Ӧ��ϵͳ�Լ���ý�����ְ���", 8, 132, INT(RND * 14) + 1)
CALL d16("    ��������ά�ޡ�������ѵ�������������У���������֤�飩", 8, 148, INT(RND * 14) + 1)
CALL d16("                                          ������������ź���", 8, 176, INT(RND * 14) + 1)
CALL pause(tmp$)
END SUB

SUB ysc (sj)
FOR t = 1 TO sj
NEXT t
END SUB
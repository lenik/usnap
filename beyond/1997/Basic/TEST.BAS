COMMON SHARED freq
a = TIMER
ks: IF TIMER = a THEN GOTO ks
a = TIMER
cpu: IF TIMER - a >= 1 THEN freq = sd: GOTO eexit ELSE sd = sd + 1
GOTO cpu
eexit:
SCREEN 12: CLS
DIM an$(1 TO 3), an(1 TO 3, 11), gn$(1 TO 3), gn(1 TO 4)
an$(1) = "`Ok"
an(1, 0) = 150: an(1, 1) = 100: an(1, 2) = 180: an(1, 3) = 120
an(1, 4) = 157: an(1, 5) = 104
an(1, 6) = 14: an(1, 7) = 7: an(1, 8) = 1: an(1, 9) = 14: an(1, 10) = 0: an(1, 11) = 4
an$(2) = "`Cancel"
an(2, 0) = 248: an(2, 1) = 100: an(2, 2) = 300: an(2, 3) = 120
an(2, 4) = 252: an(2, 5) = 104
an(2, 6) = 14: an(2, 7) = 7: an(2, 8) = 1: an(2, 9) = 14: an(2, 10) = 0: an(2, 11) = 5
an$(3) = "~FÐ»¼ÌÀ×"
an(3, 0) = 200: an(3, 1) = 150: an(3, 2) = 280: an(3, 3) = 200
an(3, 4) = 205: an(3, 5) = 160
an(3, 6) = 12: an(3, 7) = 6: an(3, 8) = 2: an(3, 9) = 13: an(3, 10) = 0: an(3, 11) = 11
gn$(1) = CHR$(9)
gn$(2) = CHR$(0) + CHR$(15)
gn$(3) = CHR$(13)
gn(1) = 3
gn(2) = .1
gn(3) = 1

start:
gn(4) = gn(4) + 1

CALL press(an$(), an(), gn$(), gn(), 1000)
LOCATE 15, 15: PRINT an$(gn(3)), gn(4)
GOTO start

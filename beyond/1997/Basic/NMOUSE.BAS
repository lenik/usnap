'$INCLUDE: 'qb.bi'
DIM regs AS regtype
SCREEN 12
regs.ax = 0
interrupt &H33, regs, regs
IF regs.ax = -1 THEN BEEP
regs.ax = 1
interrupt &H33, regs, regs
WHILE INKEY$ <> CHR$(27)
regs.ax = 3
interrupt &H33, regs, regs
x = regs.cx: y = regs.dx
LOCATE 1, 1: PRINT "x="; x, "y="; y
regs.ax = 6
regs.bx = 0
interrupt &H33, regs, regs
b = regs.ax
IF b = 1 THEN PLAY "t255l64o3cgagefgagb"
IF b = 2 THEN PLAY "t255l64o4adfeggggfebcdfgea"
IF b = 3 THEN PLAY "t255l64o5fgfedefedcdeagfegbgfaggfe"
LOCATE 1, 23: PRINT b
WEND

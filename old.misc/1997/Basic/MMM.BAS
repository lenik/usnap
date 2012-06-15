TYPE regtype
ax AS INTEGER: bx AS INTEGER: cx AS INTEGER: dx AS INTEGER
bp AS INTEGER: si AS INTEGER: di AS INTEGER: filags AS INTEGER
END TYPE
TYPE regtypex
ax AS INTEGER: bx AS INTEGER: cx AS INTEGER: dx AS INTEGER
bp AS INTEGER: si AS INTEGER: di AS INTEGER: flags AS INTEGER
ds AS INTEGER: es AS INTEGER
END TYPE
CLS : SCREEN 13
DIM inregs AS regtype, outregs AS regtype
inregs.ax = &H1
CALL interrupt(&H33, inregs, outregs)
inregs.ax = &H7
inregs.cx = 10
inregs.dx = 600
CALL interrupt(&H33, inregs, outregs)
inregs.ax = &H8
inregs.cx = 10
inregs.dx = 470
CALL interrupt(&H33, inregs, outregs)
SCREEN 13
WHILE INKEY$ <> CHR$(27)
LOCATE 2, 1: PRINT bx, by, b
inregs.ax = &H3
b = outregs.bx
bx = outregs.cx
by = outregs.dx
CALL interrupt(&H33, inregs, outregs)
WEND

TYPE regtype
ax AS INTEGER
bx AS INTEGER
cx AS INTEGER
dx AS INTEGER
bp AS INTEGER
si AS INTEGER
di AS INTEGER
filags AS INTEGER
END TYPE
TYPE regtypex
ax AS INTEGER
bx AS INTEGER
cx AS INTEGER
dx AS INTEGER
bp AS INTEGER
si AS INTEGER
di AS INTEGER
flags AS INTEGER
ds AS INTEGER
es AS INTEGER
END TYPE
DECLARE SUB interrupt (intno AS INTEGER, inregs AS regtype, outregs AS regtype)
DECLARE SUB interruptx (intno AS INTEGER, inregs AS regtypex, outregs AS regtypex)
CLS : SCREEN 12
DIM inregs AS regtype, outregs AS regtype
inregs.ax = &H0
inregs.ax = &HFFFF
inregs.bx = &H2
CALL interrupt(&H33, inregs, outregs)
inregs.ax = &H1
CALL interrupt(&H33, inregs, outregs)
inregs.ax = &H7
inregs.cx = 40
inregs.dx = 600
CALL interrupt(&H33, inregs, outregs)
inregs.ax = &H8
inregs.cx = 10
inregs.dx = 470
CALL interrupt(&H33, inregs, outregs)
DIM wx(48), wy(48)
CLS : SCREEN 12
WHILE INKEY$ <> " "
inregs.ax = &H5
inregs.bx = &H0
b = outregs.bx
x = outregs.cx
y = outregs.dx
CALL interrupt(&H33, inregs, outregs)
LOCATE 2, 2: PRINT x, y, b, INT(bx / 10)
inregs.ax = &H3
bx = outregs.cx
by = outregs.dx
CALL interrupt(&H33, inregs, outregs)
IF b = 2 THEN PLAY "t255l64o4cdefgabagfedc"
IF b = 1 THEN PLAY "t255l64o3cdefgabagfedc"
IF b = 3 THEN PLAY "t255l64o5cdefgabagfedc"
WEND

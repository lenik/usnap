; Debug Register Assembler Lib
; DanSei 1998.10.15

Debug_DumpRegs proc
  pushf
  push ax
  push dx
  push bx

  push ds
  push cs
  push ds
  push cs
  pop ds

  push dx
  push bx
  mov dx, ax
  mov bx, offset Debug_DumpRegsAX
  call Debug_WordToASCII
  pop bx
  mov dx, bx
  mov bx, offset Debug_DumpRegsBX
  call Debug_WordToASCII
  mov dx, cx
  mov bx, offset Debug_DumpRegsCX
  call Debug_WordToASCII
  pop dx
  mov bx, offset Debug_DumpRegsDX
  call Debug_WordToASCII

  mov dx, sp
  mov bx, offset Debug_DumpRegsSP
  call Debug_WordToASCII
  mov dx, Debug_DumpRegsSaveBP
  mov bx, offset Debug_DumpRegsBP
  call Debug_WordToASCII
  mov dx, si
  mov bx, offset Debug_DumpRegsSI
  call Debug_WordToASCII
  mov dx, di
  mov bx, offset Debug_DumpRegsDI
  call Debug_WordToASCII

  mov dx, cs
  mov bx, offset Debug_DumpRegsCS
  call Debug_WordToASCII
  pop ds        ; Origin DS
  mov dx, ds
  pop ds        ; DS = CS
  mov bx, offset Debug_DumpRegsDS
  call Debug_WordToASCII
  mov dx, es
  mov bx, offset Debug_DumpRegsES
  call Debug_WordToASCII
  mov dx, ss
  mov bx, offset Debug_DumpRegsSS
  call Debug_WordToASCII

  mov ah, 9
  lea dx, Debug_DumpRegsString
  int 21h

  pop ds        ; Restore DS

  pop bx
  pop dx
  pop ax
  popf
  ret

  Debug_DumpRegsSaveBP            dw ?
  Debug_DumpRegsString            db 'Current Registers: ', 0ah, 0dh
                                  db 'AX='
  Debug_DumpRegsAX                db 4 dup (' '), '  '
                                  db 'BX='
  Debug_DumpRegsBX                db 4 dup (' '), '  '
                                  db 'CX='
  Debug_DumpRegsCX                db 4 dup (' '), '  '
                                  db 'DX='
  Debug_DumpRegsDX                db 4 dup (' '), '  '
                                  db 'SP='
  Debug_DumpRegsSP                db 4 dup (' '), '  '
                                  db 'BP='
  Debug_DumpRegsBP                db 4 dup (' '), '  '
                                  db 'SI='
  Debug_DumpRegsSI                db 4 dup (' '), '  '
                                  db 'DI='
  Debug_DumpRegsDI                db 4 dup (' '), 0ah, 0dh
                                  db 'CS='
  Debug_DumpRegsCS                db 4 dup (' '), '  '
                                  db 'DS='
  Debug_DumpRegsDS                db 4 dup (' '), '  '
                                  db 'ES='
  Debug_DumpRegsES                db 4 dup (' '), '  '
                                  db 'SS='
  Debug_DumpRegsSS                db 4 dup (' '), '  '
                                  db 'FLAGS='
  Debug_DumpRegsFLAGS             db 4 dup (' '), 0ah, 0dh
                                  db '$'
Debug_DumpRegs endp

Debug_WordToASCII proc
; DX -> [BX]
  push dx
  push bx

  push dx
  call Debug_ToASCII
  mov byte ptr [bx+2], dh
  mov byte ptr [bx+3], dl
  pop dx
  mov dl, dh
  call Debug_ToASCII
  mov byte ptr [bx], dh
  mov byte ptr [bx+1], dl

  pop bx
  pop dx
  ret

Debug_WordToASCII endp

Debug_ToASCII proc
; DL -> DX, DX Destroyed
  mov dh, dl
  and dl, 0Fh
  or dl, 30h
  cmp dl, 3Ah
  jl Debug_ToASCIIExit1
  add dl, 7
Debug_ToASCIIExit1:
  shr dh, 1
  shr dh, 1
  shr dh, 1
  shr dh, 1
  or dh, 30h
  cmp dh, 3Ah
  jl Debug_ToASCIIExit2
  add dh, 7
Debug_ToASCIIExit2:
  ret
Debug_ToASCII endp

code segment para public
  org 100h
  assume cs:code, ds:code

start:
  mov ax, cs
  mov ds, ax
  mov di, offset disp
  mov dh, 0
loop0:
  mov dl, [di]
  cmp dl, 0
  je vdone
  inc di
  mov si, [di]
  call dvector
  add di, 2
  call dcrlf
  jmp loop0
vdone:
  call dcrlf
  mov ah, 4ch
  int 21h
  ret

dvector proc near
  call dstring
  call dbyte
  call dspace
  mov al, dl
  mov ah, 35h
  int 21h
  mov dx, bx
  call ddword
  call dspace
  ret
dvector endp

dstring proc near
  push si
  push ax
dis:
  mov al, [si]
  cmp al, 0
  je disdone
  call dchar
  inc si
  jmp dis
disdone:
  pop ax
  pop si
  ret
dstring endp

ddword proc near
  push dx
  mov dx, es
  call dsword
  call dcolon
  pop dx
  call dsword
  ret
ddword endp

dsword proc near
  push dx
  mov dl, dh
  call dbyte
  pop dx
  call dbyte
  ret
dsword endp

dbyte proc near
  push ax
  push dx
  push si
  push dx
  push cx
  mov cl, 4
  shr dx, cl
  and dx, 0fh
  mov si, dx
  mov al, hextab[si]
  call dchar
  pop cx
  and dx, 0fh
  mov si, dx
  mov al, hextab[si]
  call dchar
  pop si
  pop dx
  pop ax
  ret
dbyte endp

dcolon proc near
  mov al, ':'
  call dchar
  ret
dcolon endp

dspace proc near
  mov al, 32
  call dchar
  ret
dspace endp

dcrlf proc near
  mov al, 0dh
  call dchar
  mov al, 0ah
  call dchar
  ret
dcrlf endp

dchar proc near
  push ax
  push bx
  mov bh, 1
  mov ah, 0eh
  int 10h
  pop bx
  pop ax
  ret
dchar endp

hextab db '01234567ABCDEF', 0

disp db 05h
     dw v05
     db 19h
     dw v19
     db 08h
     dw v08
     db 1ah
     dw v1a
     db 09h
     dw v09
     db 1bh
     dw v1b
     db 0bh
     dw v0b
     db 1ch
     dw v1c
     db 0ch
     dw v0c
     db 1dh
     dw v1d
     db 0dh
     dw v0d
     db 1eh
     dw v1e
     db 0eh
     dw v0e
     db 1fh
     dw v1f
     db 0fh
     dw v0f
     db 20h
     dw v20
     db 10h
     dw v10
     db 21h
     dw v21
     db 11h
     dw v11
     db 22h
     dw v22
     db 12h
     dw v12
     db 23h
     dw v23
     db 13h
     dw v13
     db 24h
     dw v24
     db 14h
     dw v14
     db 25h
     dw v25
     db 15h
     dw v15
     db 26h
     dw v26
     db 16h
     dw v16
     db 27h
     dw v27
     db 17h
     dw v17
     db 2fh
     dw v2f
     db 18h
     dw v18
     db 0
     dw 0
v05 db 'Print Screen:id0', 0
v08 db 'Timer Tick Controller:id0', 0
v09 db 'Keyboard Input:id0', 0
v0b db 'Communication port 1:id0', 0
v0c db 'Communication Port 2:id0', 0
v0d db 'Hard Disk Controller:id0', 0
v0e db 'Floopy Disk Controller:id0', 0
v0f db 'Printer Controller:id0', 0
v10 db 'Video Driver:id0', 0
v11 db 'Equipment Check:id0', 0
v12 db 'Memory Size Check:id0', 0
v13 db 'Disk Driver:id0', 0
v14 db 'Communication Driver:id0', 0
v15 db 'Cassette Driver:id0', 0
v16 db 'Keyboard Driver:id0', 0
v17 db 'Printer Driver:id0', 0
v18 db 'ROM BASIC:id0', 0
v19 db 'BootStrap Loader:id0', 0
v1a db 'Realtime Clock:id0', 0
v1b db 'Ctrl-Break Handler:id0', 0
v1c db 'Timer Controller:id0', 0
v1d db 'Video Parameter Table:id0', 0
v1e db 'Disk Parameter Table:id0', 0
v1f db 'Graphic Character Table:id0', 0
v20 db 'Program Terminate:id0', 0
v21 db 'DOS universal function:id0', 0
v22 db 'Terminate Vector:id0',, 0
v23 db 'Ctrl-C Vector:id0', 0
v24 db 'Critical Error Vector:id0', 0
v25 db 'Absolute Disk Read:id0', 0
v26 db 'Absolute Disk Write:id0', 0
v27 db 'Terminate/Stay Resident:id0', 0
v2f db 'Print Spooler:id0', 0

code ends

end start

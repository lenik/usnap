.model tiny

PSP_ParamCount  equ     80H
PSP_ParamBegin  equ     82H     ; Ignored the 1st Space.

.code
  org 100h

start:
  mov ah, 9
  lea dx, Welcome
  int 21h

  mov bx, PSP_ParamCount
  xor ch, ch
  mov cl, [bx]
  cmp cx, 4     ; Size of Parameters
  jge NumOK
  lea dx, CommandLine
  int 21h
  jmp Exit

NumOK:
  ; Initializing Files
  mov ah, 1ah   ; Set DTA Address
  lea dx, TB_DTA
  int 21h

  mov dx, PSP_ParamBegin        ; Begin of Parameter Address ( PSP+81h )
  call ClearSpace

  mov ah, 4eh   ; Find First Matching File
  mov cx, 20h   ; Find Attribution
  int 21h
  jc FindError

  mov ah, 3dh   ; Open File     ; Update: dx=TB_DTA_FileName
  int 21h
  jc FileError
  mov TB_hfIn, ax

  mov ah, 3ch   ; Create File
  mov cx, 20h   ; File Attribution. Normal
  call SeekToNext       ; The 2nd Parameter = Text File.
  int 21h
  jnc FileCreateOK
  jmp short FileError
FileCreateOK:
  mov TB_hfOut, ax

  ; Initializing Memory
  mov cl, 4             ; 1 Paragraph = 10h Bytes

  mov ah, 4ah           ; Modify Allocated Memory Block
  mov bx, offset TheEnd
  add bx, 10h
  shr bx, cl
  mov TB_Size, bx
  int 21h

  mov ah, 48h   ; Allocate Memory, AX = seg if successful
  mov bx, TB_DTA_Size
  push bx
  add bx, 10h
  ; shr bx, cl
  int 21h
  jc MemAllocError
  push ax

  ; Reading     ; Update: No memory using.
  mov TB_ReadDataSeg, ax
  mov bx, TB_hfIn

  mov ah, 3fh   ; Read File
  pop ds        ; Note that DS wasn't the code segment after now
  xor dx, dx
  pop cx        ; File Size, In DTA, Returned by Calling Find Files of Which AX=4Eh of Interrupt 21h Did
  int 21h
  jc FileError

  call Converting

  ; Close Files
L_CloseFile:
  mov ah, 3eh
  mov bx, TB_hfIn
  int 21h
  mov bx, TB_hfOut
  int 21h

  mov ah, 9
  lea dx, Done
  int 21h
  jmp short Exit

; Error Man
FindError:
  mov ah, 9
  lea dx, NoFile
  int 21h
  jmp short Exit

FileError:
  mov bx, ax
  mov ah, 9
  lea dx, FileErrorString
  int 21h
FileError2:
  cmp bx, 2
  jz FileNotFound
  cmp bx, 3
  jz PathNotFound
  cmp bx, 5
  jz AccessDenied
  cmp bx, 6
  jz HandleWrong
  lea dx, UnknownError
  jmp short DispString
FileNotFound:
  lea dx, NoFile
  jmp short DispString
PathNotFound:
  lea dx, NoPath
  jmp short DispString
AccessDenied:
  lea dx, AccessError
  jmp short DispString
HandleWrong:
  lea dx, InvalidHandle
  jmp short DispString
DispString:
  int 21h
  cmp ch, 2
  jz ErrorReturn
  jmp short Exit
ErrorReturn:
  ret

MemAllocError:
  pop bx
  mov ah, 9
  lea dx, MemOut
  int 21h
  jmp short Exit

Exit:
  int 20h

ClearSpace proc
  push ax

  mov al, 20h
  mov di, dx
  mov cx, 80h
  repnz scasb
  dec di
  mov byte ptr [di], 0
  inc di

  mov al, 0dh
  repnz scasb
  dec di
  mov byte ptr [di], 0

  pop ax
  ret
ClearSpace endp

SeekToNext proc
  xchg bx, dx
L_SeekToNext:
  inc bx
  cmp byte ptr [bx], 0
  jne L_SeekToNext
  inc bx
  xchg bx, dx
  ret
SeekToNext endp

Converting proc
  ; Converting and Writing
  mov bx, es: TB_hfOut
  mov cx, 3
  mov si, dx
L_Converting:
  push cx
  lea di, TB_TransferBuf
  rep movsb

  dec di
  dec di
  mov dx, es: [di]
  inc di
  and dl, 0Fh
  or dl, 10h
  shl dl, 1
  shl dl, 1
  mov es: [di], dl
  mov dl, dh
  mov cl, 6
  shr dl, cl
  add es: [di], dl
  inc di
  and dh, 3Fh
  or dh, 40h
  mov es: [di], dh
  sub di, 3
  mov dx, es: [di]
  inc di
  mov cl, 4
  shr dh, cl
  mov es: [di], dh
  mov dh, dl
  and dh, 3
  or dh, 4
  shl dh, cl
  add es: [di], dh
  dec di
  shr dl, 1
  shr dl, 1
  or dl, 40h
  mov es: [di], dl

  push ds
  push es
  pop ds
  pop es

  pop cx

  ; Writing to File
  mov dx, TB_DTA_Size
  cmp dx, 0
  jz L_Success
  cmp dx, 3
  jl FewLeft
  sub TB_DTA_Size, 3
  jmp short L_Writing
FewLeft:
  mov cx, dx
  mov TB_DTA_Size, 0

L_Writing:
  mov ah, 40h
  lea dx, TB_TransferBuf
  inc cx
  int 21h       ; Note: This call will modify the value of register AX to the size of wrote bytes.
  jc WritingError
  dec cx

  push ds
  push es
  pop ds
  pop es
  jmp L_Converting

WritingError:
  mov bx, ax
  mov ah, 9
  lea dx, ErrorInWriting
  int 21h
  mov ch, 2
  call FileError2
  jmp L_CloseFile

L_Success:
  mov ah, 9
  lea dx, Success
  int 21h
  jmp L_CloseFile

Converting endp

Welcome         db 'Text Form Binary    Version 1.00', 0dh, 0ah
                db 'DanSei/1998.10.15', 0dh, 0ah, 0dh, 0ah, '$'
Success         db 'Successful in Forming Text Form Binary File. ', 0dh, 0ah
                db 'Thanks for using TopCroak Software. ', 0dh, 0ah, '$'
Done            db 'Done. $'
CommandLine     db 'Syntax:  TB <In: Binary Filename> <Out: Text Filename>', 0dh, 0ah
                db 'Example: TB Hello.com Hello.TB', 0dh, 0ah, '$'

FileErrorString db 'File Error: $'
ErrorInWriting  db 'Error During Writing. ', 0dh, 0ah, '$'
NoFile          db 'No File. ', 0dh, 0ah, '$'
NoPath          db 'No Path. ', 0dh, 0ah, '$'
AccessError     db 'Access Error. ', 0dh, 0ah, '$'
InvalidHandle   db 'Invalid Handle. ', 0dh, 0ah, '$'
UnknownError    db 'Unknown Error. ', 0dh, 0ah, '$'

MemOut          db 'No Enough Memory. ', 0dh, 0ah, '$'

TB_DTA          db 0            ; Attribute of Search
TB_Size         label           ; TB/Size of This Executable File
                db 0            ; Drive Used in Search
                db 11 dup (0)   ; Search Name Used
TB_TransferBuf  dw 0            ; Directory Entry Number
TB_hfIn         dw 0            ; Starting Cluster Number of Current Directory
TB_hfOut        dw 0            ; Reserved
TB_ReadDataSeg  dw 0            ; Starting Cluster Number of Current Directory
                db 0            ; Attribute of Matching File
                dw 0, 0         ; File Time, Date
TB_DTA_Size     dw 0            ; File Size
TB_DTA_FileName db 13 dup (0)   ; ASCIZ Filename and Extension in the Form NAME.EXT with blanks stripped.

TheEnd          label

end start

;001 00000-001 11111     Control 5 bits, 0-31, +2: 2-33
;                        Next data dup 2-33 times
;01 000000-01 111111     Text Form Binary Data   6 bits
;                        8 text bytes equal 6 bin bytes

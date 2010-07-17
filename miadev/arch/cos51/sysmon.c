#include "sysmon.h"

#pragma codeseg PAGE1

#define getsfr_entry(idat) \
        mov a, idat \
        ajmp getsfr_ret // 2k boundary.

#define setsfr_entry(idat) \
        mov idat, r0 \
        ajmp setsfr_ret // 2k boundary.

#define getsfrX_(X) \
        getsfr_entry(0x##X##0) \
        getsfr_entry(0x##X##1) \
        getsfr_entry(0x##X##2) \
        getsfr_entry(0x##X##3) \
        getsfr_entry(0x##X##4) \
        getsfr_entry(0x##X##5) \
        getsfr_entry(0x##X##6) \
        getsfr_entry(0x##X##7) \
        getsfr_entry(0x##X##8) \
        getsfr_entry(0x##X##9) \
        getsfr_entry(0x##X##a) \
        getsfr_entry(0x##X##b) \
        getsfr_entry(0x##X##c) \
        getsfr_entry(0x##X##d) \
        getsfr_entry(0x##X##e) \
        getsfr_entry(0x##X##f)

#define setsfrX_(X) \
        setsfr_entry(0x##X##0) \
        setsfr_entry(0x##X##1) \
        setsfr_entry(0x##X##2) \
        setsfr_entry(0x##X##3) \
        setsfr_entry(0x##X##4) \
        setsfr_entry(0x##X##5) \
        setsfr_entry(0x##X##6) \
        setsfr_entry(0x##X##7) \
        setsfr_entry(0x##X##8) \
        setsfr_entry(0x##X##9) \
        setsfr_entry(0x##X##a) \
        setsfr_entry(0x##X##b) \
        setsfr_entry(0x##X##c) \
        setsfr_entry(0x##X##d) \
        setsfr_entry(0x##X##e) \
        setsfr_entry(0x##X##f)

/**
 * addr must be passed by DPL, must be 80..ff
 * @return in DPL
 */
byte getsfr(register byte addr)
__naked __reentrant __using(0) {
    addr;
    __asm
    push psw
    anl psw, #0xe7  // 111.RS.111

    push dph
    push 0          // using(0) r0
    push 1          // using(0) r0
    push acc

    // r0: low addr
    // r1: tmp
    mov a, dpl
    anl a, #0x7f

    mov dph, #(_getsfr_tab >> 8)
    mov dpl, #(_getsfr_tab)
    rl a
    rl a
    mov r0, a

    // dph += a & 3
    anl a, #3
    mov r1, a
    mov a, dph
    add a, r1
    mov dph, a

    // call tab'[low-addr]
    mov a, r0
    anl a, #0xfc
    jmp @a + dptr

getsfr_ret:
    mov dpl, acc
    pop acc
    pop 0
    pop 1
    pop dph
    pop psw
    ret
    __endasm;
}

// size=0x200 (0.5k)
void getsfr_tab()
__naked {
    __asm
    getsfrX_(8)
    getsfrX_(9)
    getsfrX_(a)
    getsfrX_(b)
    getsfrX_(c)
    getsfrX_(d)
    getsfrX_(e)
    getsfrX_(f)
    __endasm;
}

/**
 * addr must be passed by dph, must be 80..ff
 * val  must be passed by dpl
 * @return in DPL
 */
void _setsfr(register word addr_val)
__naked __reentrant __using(0) {
    addr_val;
    __asm
    push psw
    anl psw, #0xe7  // 111.RS.111

    push dph
    push dpl
    push 0          // using(0) r0
    push 1          // using(0) r1
    push 2          // using(0) r2
    push acc

    // r0: new value
    // r1: tmp
    // r2: low addr
    mov a, dph
    anl a, #0x7f

    mov r0, dpl
    mov dph, #(_setsfr_tab >> 8)
    mov dpl, #(_setsfr_tab)
    rl a
    rl a
    mov r2, a

    // dph += a & 3
    anl a, #3
    mov r1, a
    mov a, dph
    add a, r1
    mov dph, a

    // call tab'[low-addr]
    mov a, r2
    anl a, #0xfc
    jmp @a + dptr

setsfr_ret:
    pop acc
    pop 2
    pop 1
    pop 0
    pop dpl
    pop dph
    pop psw
    ret
    __endasm;
}

// size=0x200 (0.5k)
void setsfr_tab()
__naked {
    __asm
    setsfrX_(8)
    setsfrX_(9)
    setsfrX_(a)
    setsfrX_(b)
    setsfrX_(c)
    setsfrX_(d)
    setsfrX_(e)
    setsfrX_(f)
    __endasm;
}

#ifndef _safeproc_umac_n_xWDeY8hySH5Vej_
#define _safeproc_umac_n_xWDeY8hySH5Vej_

#include "config.h"

#define SAFE_DELETE(p)       if (p) { delete (p); (p) = NULL; }
#define SAFE_DELETE_ARRAY(p) if(p) { delete[] (p); (p) = NULL; }
#define SAFE_DEREF_(p, def)  ((p) == 0 ? (def) : *(p))
#define SAFE_DEREF(p)        SAFE_DEREF_(p, 0)
#define SAFE_ADDREF(p)       if (p) { (p)->AddRef(); }
#define SAFE_RELEASE(p)      if (p) { (p)->Release(); (p) = NULL; }
#define SAFE_RC(p)           ((p) ? ((p)->AddRef() - 1, (p)->Release()) : 0)

/*
   Usage of SAFE PROCEDURE
   --------------------------------------------------------------------------------
   SP_BEGIN        or:         "SP_BEGIN_(hr)", "SP_BEGIN_(dwError)"
   ....
   SP_GATE_(is_ok(pwd))        "__sp_hr=func(); SP_GATE"
   "SP_GATEx_(magic==0x1234, E_UNEXPECTED) "
   ....
   (do some process need clean-up)
   ....
   SP_GATE1_(pv != NULL)       "SP_GATEx1_(pv, E_OUTOFMEMORY) "
   ....
   // if (no_clean_up) return SP_RETVAL;
   SP_BREAK_(S_OK)             "if (no_clean_up) SP_BREAK"

   SP_REV                      "SP_END SP_BACK"

   SP_L                        "SP_L1 SAFE_DELETE(pv)
   SP_L3                       \
   SP_L2                       \
   SP_L1   SAFE_DELETE(pv);    \
   SP_L0                       \

   SP_LEND                     SP_LEND"

   return SP_RETVAL;           "return SP_RETVAL_(DWORD); "
   ---------------------------------------------------------------------------------
   copy&paste:

   SP_BEGIN_(hr)
   // SP_GATEx1_(pv, E_OUTOFMEMORY)
   // if (release_gates)
   SP_BREAK_(S_OK)
   SP_REV
   SP_L
   SP_L1
   SP_L0
   SP_LEND
   return SP_RETVAL;
*/

#define SP_BEGIN \
        void *__sp_ret = 0; \
        int __sp_level = 0; \
        for (;;) {
#define SP_BEGIN_(ret) \
        void *& __sp_ret = *(void **)&ret; \
        int __sp_level = 0; \
        for (;;) {
#define SP_BREAK break;
#define SP_BREAK_(r)    { __sp_hr = (void *)(r); break; }
#define SP_END          __sp_level = -1; break; }
#define SP_GATE         if (FAILED(__sp_hr)) break;
#define SP_GATE1        { SP_GATE; __sp_level++; }
#define SP_GATE2        { SP_GATE; __sp_level+=2; }
#define SP_GATE3        { SP_GATE; __sp_level+=3; }
#define SP_GATE4        { SP_GATE; __sp_level+=4; }
#define SP_GATE_(c)     if (!(c)) break;
#define SP_GATE1_(c)    { SP_GATE_(c); __sp_level++; }
#define SP_GATE2_(c)    { SP_GATE_(c); __sp_level+=2; }
#define SP_GATE3_(c)    { SP_GATE_(c); __sp_level+=3; }
#define SP_GATE4_(c)    { SP_GATE_(c); __sp_level+=4; }
#define SP_GATEx(x)     if (FAILED(__sp_hr)) { __sp_hr = (void *)(x); break; }
#define SP_GATEx1(x)    { SP_GATEx(x); __sp_level++; }
#define SP_GATEx2(x)    { SP_GATEx(x); __sp_level+=2; }
#define SP_GATEx3(x)    { SP_GATEx(x); __sp_level+=3; }
#define SP_GATEx4(x)    { SP_GATEx(x); __sp_level+=4; }
#define SP_GATEx_(c,x)  if (!(c)) { __sp_hr = (void *)(x); break; }
#define SP_GATEx1_(c,x) { SP_GATEx_(c,x); __sp_level++; }
#define SP_GATEx2_(c,x) { SP_GATEx_(c,x); __sp_level+=2; }
#define SP_GATEx3_(c,x) { SP_GATEx_(c,x); __sp_level+=3; }
#define SP_GATEx4_(c,x) { SP_GATEx_(c,x); __sp_level+=4; }
#define SP_BACK         switch (__sp_level) {
#define SP_REV          SP_END SP_BACK
#define SP_L            default:
#define SP_L_(n)        case (n):
#define SP_Lz           case 35:
#define SP_Ly           case 34:
#define SP_Lx           case 33:
#define SP_Lw           case 32:
#define SP_Lv           case 31:
#define SP_Lu           case 30:
#define SP_Lt           case 29:
#define SP_Ls           case 28:
#define SP_Lr           case 27:
#define SP_Lq           case 26:
#define SP_Lp           case 25:
#define SP_Lo           case 24:
#define SP_Ln           case 23:
#define SP_Lm           case 22:
#define SP_Ll           case 21:
#define SP_Lk           case 20:
#define SP_Lj           case 19:
#define SP_Li           case 18:
#define SP_Lh           case 17:
#define SP_Lg           case 16:
#define SP_Lf           case 15:
#define SP_Le           case 14:
#define SP_Ld           case 13:
#define SP_Lc           case 12:
#define SP_Lb           case 11:
#define SP_La           case 10:
#define SP_L39          case 39:
#define SP_L38          case 38:
#define SP_L37          case 37:
#define SP_L36          case 36:
#define SP_L35          case 35:
#define SP_L34          case 34:
#define SP_L33          case 33:
#define SP_L32          case 32:
#define SP_L31          case 31:
#define SP_L30          case 30:
#define SP_L29          case 29:
#define SP_L28          case 28:
#define SP_L27          case 27:
#define SP_L26          case 26:
#define SP_L25          case 25:
#define SP_L24          case 24:
#define SP_L23          case 23:
#define SP_L22          case 22:
#define SP_L21          case 21:
#define SP_L20          case 20:
#define SP_L19          case 19:
#define SP_L18          case 18:
#define SP_L17          case 17:
#define SP_L16          case 16:
#define SP_L15          case 15:
#define SP_L14          case 14:
#define SP_L13          case 13:
#define SP_L12          case 12:
#define SP_L11          case 11:
#define SP_L10          case 10:
#define SP_L9           case 9:
#define SP_L8           case 8:
#define SP_L7           case 7:
#define SP_L6           case 6:
#define SP_L5           case 5:
#define SP_L4           case 4:
#define SP_L3           case 3:
#define SP_L2           case 2:
#define SP_L1           case 1:
#define SP_L0           case 0:
#define SP_LEND         break; }
#define SP_GROUP        break;
#define SP_RETVAL       __sp_hr
#define SP_RETVAL_(t)   ((t)__sp_hr)

#endif

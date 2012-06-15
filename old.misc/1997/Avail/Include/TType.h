#ifndef __TTYPE_H

#define __TTYPE_H

#include <_Null.h>

#ifndef Byte
#define Byte unsigned char
#endif

#ifndef Word
#define Word unsigned int
#endif

#ifndef DWord
#define DWord unsigned long
#endif

#ifndef __TRETURNTYPE__

#define __TRETURNTYPE__

struct TRetStr{
  Byte *r;	// Return String
  char	s;	// Return Status
};
struct TRetNum{
  int 	r;	// Return Number
  char	s;	// Return Status
};

struct TRetByte{
  Byte	r;	// Return Number
  char	s;	// Return Status
};

struct TRetWord{
  Word	r;	// Return Number
  char	s;	// Return Status
};

struct TRetDWord{
  DWord	r;	// Return Number
  char	s;	// Return Status
};

extern TRetNum _TRetNum;
extern TRetStr _TRetStr;

extern TRetByte _TRetByte;
extern TRetWord _TRetWord;
extern TRetDWord _TRetDWord;

#endif  // __TRETURNTYPE__

Byte GetBit(Byte _SrcByte, Byte _Bit);
Byte GetBit(Word _SrcWord, Byte _Bit);
Byte GetBit(DWord _SrcDWord, Byte _Bit);

void SetBit(Byte& _SrcByte, Byte _Bit, Byte _Val);
void SetBit(Word& _SrcWord, Byte _Bit, Byte _Val);
void SetBit(DWord& _SrcDWord, Byte _Bit, Byte _Val);

#ifndef __TVARSET__

#define __TVARSET__

union TVarSet{			// Total Size = 10h Bytes
  // DWords Pack
  struct __tvs__dw{
    DWord r, s, t, u;
  }dw;
  struct __tvs__dwa{
    DWord ab, cd, ef, gh;
  }dwa;
  struct __tvs__dwr{
    DWord r1, r2, r3, r4;
  }dwr;
  DWord d32[4];
  // Words Pack
  struct __tvs__w{
    Word rh, rl, sh, sl, th, tl, uh, ul;
  }w;
  struct __tvs__wa{
    Word a, b, c, d, e, f, g, h;
  }wa;
  struct __tvs__wr{
    Word r1, r2, r3, r4, r5, r6, r7, r8;
  }wr;
  Word d16[8];
  // Bytes Pack
  struct __tvs__b{
    Byte rhh, rhl, rlh, rll, shh, shl, slh, sll,
	 thh, thl, tlh, tll, uhh, uhl, ulh, ull;
  }b;
  struct __tvs__ba{
    Byte ah, al, bh, bl, ch, cl, dh, dl, eh, el, fh, fl, gh, gl, hh, hl;
  }ba;
  struct __tvs__br{
    Byte r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16, r17, r18;
  }br;
  Byte d8[16];
  // 4 Bits Pack
  struct __tvs__bitquad{
    Byte rhhh:4, rhhl:4, rhlh:4, rhll:4, rlhh:4, rlhl:4, rllh:4, rlll:4,
	 shhh:4, shhl:4, shlh:4, shll:4, slhh:4, slhl:4, sllh:4, slll:4,
	 thhh:4, thhl:4, thlh:4, thll:4, tlhh:4, tlhl:4, tllh:4, tlll:4,
	 uhhh:4, uhhl:4, uhlh:4, uhll:4, ulhh:4, ulhl:4, ullh:4, ulll:4;
  }bq;
  struct __tvs__bitquada{
    Byte ahh:4, ahl:4, alh:4, all:4, bhh:4, bhl:4, blh:4, bll:4,
	 chh:4, chl:4, clh:4, cll:4, dhh:4, dhl:4, dlh:4, dll:4,
	 ehh:4, ehl:4, elh:4, ell:4, fhh:4, fhl:4, flh:4, fll:4,
	 ghh:4, ghl:4, glh:4, gll:4, hhh:4, hhl:4, hlh:4, hll:4;
  }bqa;
  struct __tvs__bitquadr{
    Byte r1:4,  r2:4,  r3:4,  r4:4,  r5:4,  r6:4,  r7:4,  r8:4,
	 r9:4,  r10:4, r11:4, r12:4, r13:4, r14:4, r15:4, r16:4,
	 r17:4, r18:4, r19:4, r20:4, r21:4, r22:4, r23:4, r24:4,
	 r25:4, r26:4, r27:4, r28:4, r29:4, r30:4, r31:4, r32:4;
  }bqr;
  // 2 Bits Pack
  struct __tvs__bitdual{
    Byte rhhhh:2, rhhhl:2, rhhlh:2, rhhll:2, rhlhh:2, rhlhl:2, rhllh:2, rhlll:2,
	 rlhhh:2, rlhhl:2, rlhlh:2, rlhll:2, rllhh:2, rllhl:2, rlllh:2, rllll:2,
	 shhhh:2, shhhl:2, shhlh:2, shhll:2, shlhh:2, shlhl:2, shllh:2, shlll:2,
	 slhhh:2, slhhl:2, slhlh:2, slhll:2, sllhh:2, sllhl:2, slllh:2, sllll:2,
	 thhhh:2, thhhl:2, thhlh:2, thhll:2, thlhh:2, thlhl:2, thllh:2, thlll:2,
	 tlhhh:2, tlhhl:2, tlhlh:2, tlhll:2, tllhh:2, tllhl:2, tlllh:2, tllll:2,
	 uhhhh:2, uhhhl:2, uhhlh:2, uhhll:2, uhlhh:2, uhlhl:2, uhllh:2, uhlll:2,
	 ulhhh:2, ulhhl:2, ulhlh:2, ulhll:2, ullhh:2, ullhl:2, ulllh:2, ullll:2;
  }bd;
  struct __tvs__bitduala{
    Byte ahhh:2, ahhl:2, ahlh:2, ahll:2, alhh:2, alhl:2, allh:2, alll:2,
	 bhhh:2, bhhl:2, bhlh:2, bhll:2, blhh:2, blhl:2, bllh:2, blll:2,
	 chhh:2, chhl:2, chlh:2, chll:2, clhh:2, clhl:2, cllh:2, clll:2,
	 dhhh:2, dhhl:2, dhlh:2, dhll:2, dlhh:2, dlhl:2, dllh:2, dlll:2,
	 ehhh:2, ehhl:2, ehlh:2, ehll:2, elhh:2, elhl:2, ellh:2, elll:2,
	 fhhh:2, fhhl:2, fhlh:2, fhll:2, flhh:2, flhl:2, fllh:2, flll:2,
	 ghhh:2, ghhl:2, ghlh:2, ghll:2, glhh:2, glhl:2, gllh:2, glll:2,
	 hhhh:2, hhhl:2, hhlh:2, hhll:2, hlhh:2, hlhl:2, hllh:2, hlll:2;
  }bda;
  struct __tvs__bitdualr{
    Byte r1:2,  r2:2,  r3:2,  r4:2,  r5:2,  r6:2,  r7:2,  r8:2,
	 r9:2,  r10:2, r11:2, r12:2, r13:2, r14:2, r15:2, r16:2,
	 r17:2, r18:2, r19:2, r20:2, r21:2, r22:2, r23:2, r24:2,
	 r25:2, r26:2, r27:2, r28:2, r29:2, r30:2, r31:2, r32:2,
	 r33:2, r34:2, r35:2, r36:2, r37:2, r38:2, r39:2, r40:2,
	 r41:2, r42:2, r43:2, r44:2, r45:2, r46:2, r47:2, r48:2,
	 r49:2, r50:2, r51:2, r52:2, r53:2, r54:2, r55:2, r56:2,
	 r57:2, r58:2, r59:2, r60:2, r61:2, r62:2, r63:2, r64:2;
  }bdr;
  // Bits Pack
  struct __tvs__bit{
    Byte rhh1:1, rhh2:1, rhh3:1, rhh4:1, rhh5:1, rhh6:1, rhh7:1, rhh8:1,
	 rhl1:1, rhl2:1, rhl3:1, rhl4:1, rhl5:1, rhl6:1, rhl7:1, rhl8:1,
	 rlh1:1, rlh2:1, rlh3:1, rlh4:1, rlh5:1, rlh6:1, rlh7:1, rlh8:1,
	 rll1:1, rll2:1, rll3:1, rll4:1, rll5:1, rll6:1, rll7:1, rll8:1,
	 shh1:1, shh2:1, shh3:1, shh4:1, shh5:1, shh6:1, shh7:1, shh8:1,
	 shl1:1, shl2:1, shl3:1, shl4:1, shl5:1, shl6:1, shl7:1, shl8:1,
	 slh1:1, slh2:1, slh3:1, slh4:1, slh5:1, slh6:1, slh7:1, slh8:1,
	 sll1:1, sll2:1, sll3:1, sll4:1, sll5:1, sll6:1, sll7:1, sll8:1,
	 thh1:1, thh2:1, thh3:1, thh4:1, thh5:1, thh6:1, thh7:1, thh8:1,
	 thl1:1, thl2:1, thl3:1, thl4:1, thl5:1, thl6:1, thl7:1, thl8:1,
	 tlh1:1, tlh2:1, tlh3:1, tlh4:1, tlh5:1, tlh6:1, tlh7:1, tlh8:1,
	 tll1:1, tll2:1, tll3:1, tll4:1, tll5:1, tll6:1, tll7:1, tll8:1,
	 uhh1:1, uhh2:1, uhh3:1, uhh4:1, uhh5:1, uhh6:1, uhh7:1, uhh8:1,
	 uhl1:1, uhl2:1, uhl3:1, uhl4:1, uhl5:1, uhl6:1, uhl7:1, uhl8:1,
	 ulh1:1, ulh2:1, ulh3:1, ulh4:1, ulh5:1, ulh6:1, ulh7:1, ulh8:1,
	 ull1:1, ull2:1, ull3:1, ull4:1, ull5:1, ull6:1, ull7:1, ull8:1;
  }bit;
  struct __tvs__bita{
    Byte ah1:1, ah2:1, ah3:1, ah4:1, ah5:1, ah6:1, ah7:1, ah8:1,
	 al1:1, al2:1, al3:1, al4:1, al5:1, al6:1, al7:1, al8:1,
	 bh1:1, bh2:1, bh3:1, bh4:1, bh5:1, bh6:1, bh7:1, bh8:1,
	 bl1:1, bl2:1, bl3:1, bl4:1, bl5:1, bl6:1, bl7:1, bl8:1,
	 ch1:1, ch2:1, ch3:1, ch4:1, ch5:1, ch6:1, ch7:1, ch8:1,
	 cl1:1, cl2:1, cl3:1, cl4:1, cl5:1, cl6:1, cl7:1, cl8:1,
	 dh1:1, dh2:1, dh3:1, dh4:1, dh5:1, dh6:1, dh7:1, dh8:1,
	 dl1:1, dl2:1, dl3:1, dl4:1, dl5:1, dl6:1, dl7:1, dl8:1,
	 eh1:1, eh2:1, eh3:1, eh4:1, eh5:1, eh6:1, eh7:1, eh8:1,
	 el1:1, el2:1, el3:1, el4:1, el5:1, el6:1, el7:1, el8:1,
	 fh1:1, fh2:1, fh3:1, fh4:1, fh5:1, fh6:1, fh7:1, fh8:1,
	 fl1:1, fl2:1, fl3:1, fl4:1, fl5:1, fl6:1, fl7:1, fl8:1,
	 gh1:1, gh2:1, gh3:1, gh4:1, gh5:1, gh6:1, gh7:1, gh8:1,
	 gl1:1, gl2:1, gl3:1, gl4:1, gl5:1, gl6:1, gl7:1, gl8:1,
	 hh1:1, hh2:1, hh3:1, hh4:1, hh5:1, hh6:1, hh7:1, hh8:1,
	 hl1:1, hl2:1, hl3:1, hl4:1, hl5:1, hl6:1, hl7:1, hl8:1;
  }bita;
  struct __tvs__bitr{
    Byte r1:1,   r2:1,   r3:1,   r4:1,   r5:1,   r6:1,   r7:1,   r8:1,
	 r9:1,   r10:1,  r11:1,  r12:1,  r13:1,  r14:1,  r15:1,  r16:1,
	 r17:1,  r18:1,  r19:1,  r20:1,  r21:1,  r22:1,  r23:1,  r24:1,
	 r25:1,  r26:1,  r27:1,  r28:1,  r29:1,  r30:1,  r31:1,  r32:1,
	 r33:1,  r34:1,  r35:1,  r36:1,  r37:1,  r38:1,  r39:1,  r40:1,
	 r41:1,  r42:1,  r43:1,  r44:1,  r45:1,  r46:1,  r47:1,  r48:1,
	 r49:1,  r50:1,  r51:1,  r52:1,  r53:1,  r54:1,  r55:1,  r56:1,
	 r57:1,  r58:1,  r59:1,  r60:1,  r61:1,  r62:1,  r63:1,  r64:1,
	 r65:1,  r66:1,  r67:1,  r68:1,  r69:1,  r70:1,  r71:1,  r72:1,
	 r73:1,  r74:1,  r75:1,  r76:1,  r77:1,  r78:1,  r79:1,  r80:1,
	 r81:1,  r82:1,  r83:1,  r84:1,  r85:1,  r86:1,  r87:1,  r88:1,
	 r89:1,  r90:1,  r91:1,  r92:1,  r93:1,  r94:1,  r95:1,  r96:1,
	 r97:1,  r98:1,  r99:1,  r100:1, r101:1, r102:1, r103:1, r104:1,
	 r105:1, r106:1, r107:1, r108:1, r109:1, r110:1, r111:1, r112:1,
	 r113:1, r114:1, r115:1, r116:1, r117:1, r118:1, r119:1, r120:1,
	 r121:1, r122:1, r123:1, r124:1, r125:1, r126:1, r127:1, r128:1;
  }bitr;
};

class TVarSetFuncs{
public:
  void Clear(TVarSet *_tvs);
  void Fill(TVarSet *_tvs);

  Byte B4Get(TVarSet _tvs, Byte Num);
  Byte B2Get(TVarSet _tvs, Byte Num);
  Byte B1Get(TVarSet _tvs, Byte Num);

  void B4Set(TVarSet *_tvs, Byte Num, Byte Val);
  void B2Set(TVarSet *_tvs, Byte Num, Byte Val);
  void B1Set(TVarSet *_tvs, Byte Num, Byte Val);
};

#endif  // __TVARSET__

#endif  // __TTYPE_H

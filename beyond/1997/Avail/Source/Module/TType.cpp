#include "TType.h"

struct TRetStr _TRetStr;
struct TRetNum _TRetNum;

struct TRetByte _TRetByte;
struct TRetWord _TRetWord;
struct TRetDWord _TRetDWord;


Byte GetBit(Byte _SrcByte, Byte _Bit){
  return (_SrcByte>>_Bit)&0x1;
}
Byte GetBit(Word _SrcWord, Byte _Bit){
  return (_SrcWord>>_Bit)&0x1;
}
Byte GetBit(DWord _SrcDWord, Byte _Bit){
  return (_SrcDWord>>_Bit)&0x1;
}
void SetBit(Byte& _SrcByte, Byte _Bit, Byte _Val){
  if (GetBit(_SrcByte, _Bit)!=_Val){
    if (_Val) _SrcByte+=_Val<<_Bit;
    else _SrcByte-=_Val<<_Bit;
  }
}
void SetBit(Word& _SrcWord, Byte _Bit, Byte _Val){
  if (GetBit(_SrcWord, _Bit)!=_Val){
    if (_Val) _SrcWord+=_Val<<_Bit;
    else _SrcWord-=_Val<<_Bit;
  }
}
void SetBit(DWord& _SrcDWord, Byte _Bit, Byte _Val){
  if (GetBit(_SrcDWord, _Bit)!=_Val){
    if (_Val) _SrcDWord+=_Val<<_Bit;
    else _SrcDWord-=_Val<<_Bit;
  }
}

void TVarSetFuncs::Clear(TVarSet *_tvs){
  _tvs->d32[0]=_tvs->d32[1]=_tvs->d32[2]=_tvs->d32[3]=0;
}
void TVarSetFuncs::Fill(TVarSet *_tvs){
  _tvs->d32[0]=_tvs->d32[1]=_tvs->d32[2]=_tvs->d32[3]=0xFFFFFFFFul;
}

Byte TVarSetFuncs::B4Get(TVarSet _tvs, Byte Num){
  Num%=0x20;
  return (Num&1)?(_tvs.d8[Num/2]&0xF):(_tvs.d8[Num/2]>>4);
}
Byte TVarSetFuncs::B2Get(TVarSet _tvs, Byte Num){
  Num%=0x40;
  return (Num&1)?(B4Get(_tvs, Num/2)&0x3):(B4Get(_tvs, Num/2)>>2);
}
Byte TVarSetFuncs::B1Get(TVarSet _tvs, Byte Num){
  Num%=0x80;
  return (Num&1)?(B2Get(_tvs, Num/2)&0x1):(B2Get(_tvs, Num/2)>>1);
}

void TVarSetFuncs::B4Set(TVarSet *_tvs, Byte Num, Byte Val){
  Num%=0x20; Val%=0x10;
  (Num&1)?(_tvs->d8[Num/2]=(_tvs->d8[Num/2]&0xF0)|Val):(_tvs->d8[Num/2]=(_tvs->d8[Num/2]&0xF)|(Val<<4));
}
void TVarSetFuncs::B2Set(TVarSet *_tvs, Byte Num, Byte Val){
  Num%=0x40; Val%=0x4;
  (Num&1)?(B4Set(_tvs, Num/2, (B4Get(*_tvs, Num/2)&0xC)|Val)):
	  (B4Set(_tvs, Num/2, (B4Get(*_tvs, Num/2)&3)|(Val<<2)));
}
void TVarSetFuncs::B1Set(TVarSet *_tvs, Byte Num, Byte Val){
  Num%=0x80; Val%=0x2;
  (Num&1)?(B2Set(_tvs, Num/2, (B2Get(*_tvs, Num/2)&0x2)|Val)):
	  (B2Set(_tvs, Num/2, (B2Get(*_tvs, Num/2)&0x1)|(Val<<1)));
}

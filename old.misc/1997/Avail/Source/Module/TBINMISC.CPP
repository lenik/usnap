#include "TBinMisc.h"

TBinaryMisc::TBinaryMisc (Byte *_Binary, Word _Length) {
  Stream = _Binary;
  StreamLength = _Length;
}

void TBinaryMisc::operator = (Byte _n) { 	// Assignment
  for (int i = 0; i <StreamLength; i++)
    Stream[i] = _n;
  return;
}

void TBinaryMisc::operator ++ () {		// Increment
  for (int i = 0; i <StreamLength; i++)
    Stream[i]++;
  return;
}

void TBinaryMisc::operator -- () {		// Decrement
  for (int i = 0; i <StreamLength; i++)
    Stream[i]--;
  return;
}

void TBinaryMisc::operator += (Byte _n) {	// Addition
  for (int i = 0; i <StreamLength; i++)
    Stream[i] += _n;
  return;
}

void TBinaryMisc::operator -= (Byte _n) {	// Substraction
  for (int i = 0; i <StreamLength; i++)
    Stream[i] -= _n;
  return;
}

void TBinaryMisc::operator *= (Byte _n) {	// Multiply
  for (int i = 0; i <StreamLength; i++)
    Stream[i] *= _n;
  return;
}

void TBinaryMisc::operator /= (Byte _n) {	// Divide
  for (int i = 0; i <StreamLength; i++)
    Stream[i] /= _n;
  return;
}

void TBinaryMisc::operator %= (Byte _n) {	// Remainder
  for (int i = 0; i <StreamLength; i++)
    Stream[i] %= _n;
  return;
}


void TBinaryMisc::operator &= (Byte _n) {	// Logical AND
  for (int i = 0; i <StreamLength; i++)
    Stream[i] &= _n;
  return;
}

void TBinaryMisc::operator |= (Byte _n) {	// Logical OR
  for (int i = 0; i <StreamLength; i++)
    Stream[i] |= _n;
  return;
}

void TBinaryMisc::operator ^= (Byte _n) {	// Logical XOR
  for (int i = 0; i <StreamLength; i++)
    Stream[i] ^= _n;
  return;
}

void TBinaryMisc::operator <<= (Byte _c) {	// Left Shift
  for (int i = 0; i <StreamLength; i++)
    Stream[i] <<= _c;
  return;
}

void TBinaryMisc::operator >>= (Byte _c) {	// Right Shift
  for (int i = 0; i <StreamLength; i++)
    Stream[i] >>= _c;
  return;
}

void TBinaryMisc::SubFrom (Byte _n) {
  for (int i = 0; i <StreamLength; i++)
    Stream[i] = _n - Stream[i];
  return;
}

void TBinaryMisc::DivFrom (Byte _n) {
  for (int i = 0; i <StreamLength; i++)
    Stream[i] = _n / Stream[i];
  return;
}

void TBinaryMisc::Not () {
  asm Push AX
  for (int i = 0; i <StreamLength; i++) {
    _AL = Stream[i];
    asm Not AL
    Stream[i] = _AL;
  }
  asm Pop AX
  return;
}

void TBinaryMisc::Neg () {
  asm Push AX
  for (int i = 0; i <StreamLength; i++) {
    _AL = Stream[i];
    asm Neg AL
    Stream[i] = _AL;
  }
  asm Pop AX
  return;
}

void TBinaryMisc::Rol (Byte _c) {
  asm Push AX
  for (int i = 0; i <StreamLength; i++) {
    _AL = Stream[i];
    _CL = _c;
    asm Rol AL, CL
    Stream[i] = _AL;
  }
  asm Pop AX
  return;
}

void TBinaryMisc::Ror (Byte _c) {
  asm Push AX
  for (int i = 0; i <StreamLength; i++) {
    _AL = Stream[i];
    _CL = _c;
    asm Ror AL, CL
    Stream[i] = _AL;
  }
  asm Pop AX
  return;
}

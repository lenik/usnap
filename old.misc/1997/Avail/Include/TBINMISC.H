#ifndef __TBINMISC_H

#define __TBINMISC_H

#include "TopType.h"

class TBinaryMisc {
  Byte *Stream;
  Word StreamLength;
  TVarSet x;

public:
  TBinaryMisc (Byte *_Binary, Word _Length);

public:
  void operator = (Byte _n); 	// Assignment

  void operator ++ ();		// Increment
  void operator -- ();		// Decrement

  void operator += (Byte _n);	// Addition
  void operator -= (Byte _n);	// Substraction
  void operator *= (Byte _n);	// Multiply
  void operator /= (Byte _n);	// Divide
  void operator %= (Byte _n);	// Remainder

  void operator &= (Byte _n);	// Logical AND
  void operator |= (Byte _n);	// Logical OR
  void operator ^= (Byte _n);	// Logical XOR

  void operator <<= (Byte _c);	// Left Shift
  void operator >>= (Byte _c);	// Right Shift

public:
  void SubFrom (Byte _n);
  void DivFrom (Byte _n);
  void Not ();
  void Neg ();
  void Rol (Byte _c);
  void Ror (Byte _c);
};

#endif
#include <stdio.h>


#define BYTE	unsigned char

struct SFlag {		//	       0/1
  int CF:	1;	// Carry	/Carry
  int AF:	1;	// Aux
  int OF:	1;	// Overflow	/Over
  int LF:	1;	// Loss		/Loss
  int PF:	1;	// Parity	/Even
  int r:	1;
  int ZF:	1;	// Zero		/Zero
  int SF:	1;	// Sign		/Neg
};

struct SNum {
  BYTE *d;
  SFlag Flag;
  unsigned l;
  unsigned p;	// l-1..p: int, p-1..0: dec
};

class _SNumClass {
protected:
  int Radix;
  SNum *r;
protected:
  void shift(SNum &, int);
protected:
  public:
  void add(SNum &b, SNum a);
  void sub(SNum &b, SNum a);
  void mul(SNum &c, SNum a, SNum b);
  void Div(SNum &c, SNum a, SNum b);
public:
  void setr(SNum *_r) { r = _r; }
};

class SNumClass : public _SNumClass {
protected:
  int MaxLength, MaxDecimal;
protected:
  void adjust(SNum &, int si, int sd);
public:
  void init(SNum &, BYTE *, BYTE);
  void init(SNum &, BYTE *, int);
  void init(SNum &, BYTE *, char *);
//  void init(SNum &, BYTE *, long);
//  void init(SNum &, BYTE *, float);

//  void Add
public:
  SNumClass() { Radix = 0x100; }
//  SNumClass(int r) { Radix = r; }
};

void _SNumClass::shift(SNum &n, int i) {
  int t, d = n.l - n.p;	// integer width
  if (i > 0) {		// shift right, smaller
    if (d > 0) {
      if (d >= i) {
	n.p += i;
	i = 0;
      } else {
	i -= d;
	n.p = n.l;
      }
    }
    if (i > 0) {	// pad zero on left
      for (t = 0; t < i; t++) {
	(n.d + n.l)[t] = 0;
      }
      n.l += i;
      n.p += i;
    }
  } else {		// shift left, bigger
    i = -i;
    if (n.p >= i) {
      n.p -= i;
      i = 0;
    } else {
      i -= n.p;
      n.p = 0;
    }
    if (i > 0) {	// move block
      for (t = n.l - 1; t >= 0; t--) {
	(n.d + i)[t] = n.d[t];
      }
      for (t = 0; t < i; t++) {
	n.d[t] = 0;
      }
      n.l += i;
    }
  }
}

void _SNumClass::add(SNum &b, SNum a) {
  int t, d, s, carry = 0;
  d = b.p - a.p;		 // b.d[d] += a.d[0]
  if (b.l < a.l) { b.l = a.l; }
  for (t = 0; t < a.l; t++) {
    s = (b.d + d)[t] + a.d[t] + carry;
    carry = s / Radix;
    (b.d + d)[t] = s % Radix;
  }
  while (carry > 0 && d + t < b.l) {
    s = (b.d + d)[t] + carry;
    carry = s / Radix;
    (b.d + d)[t] = s % Radix;
    t++;
  }
  if (carry > 0) {
    b.d[b.l++] = carry;
  }
}

void _SNumClass::sub(SNum &b, SNum a) {
  int t, d, s, borrow = 0;
  d = b.p - a.p;		 // b.d[d] -= a.d[0]
  for (t = 0; t < a.l; t++) {
    s = (b.d + d)[t] - a.d[t] + borrow;
    borrow = s / Radix;
    (b.d + d)[t] = (s + Radix) % Radix;
  }
  while (borrow < 0 && d + t < b.l) {
    s = (b.d + d)[t] + borrow;
    borrow = s / Radix;
    (b.d + d)[t] = (s + Radix) & Radix;
    t++;
  }
  if (borrow < 0) {
    b.d[b.l++] = Radix + borrow;
  }
}

void _SNumClass::mul(SNum &c, SNum b, SNum a) {
  int t1, t2, m, s, carry = 0;
  c.l = c.p = r->p = 0;
  for (t1 = a.l - 1; t1 >= 0; t1--) {	// from left to right
    m = a.d[t1];
    r->l = b.l;
    for (t2 = 0; t2 < b.l; t2++) {	// nums mul num
      s = b.d[t2] * m + carry;
      carry = s / Radix;
      r->d[t2] = s % Radix;
    }
    while (carry > 0) {	        // put reminder
      r->d[r->l++] = carry % Radix;
      carry /= Radix;
    }
    add(c, *r);
    if (t1 != 0) {		// not the last
      shift(c, -1);
    }
  }
  c.p = a.p + b.p;
}

void _SNumClass::div(SNum &c, SNum b, SNum a) {

}

// Copy
void SNumClass::adjust(SNum &n, int si, int sd) {
  int d, t;
  d = sd - n.p;			// inc decimal width
  if (d > 0) {			// shift
    for (t = n.l - 1; t >= 0; t--) {
      (n.d + d)[t] = n.d[t];
    }
    for (t = 0; t < d; t++) {
      n.d[t] = 0;
    }
    n.l += d;
  }
  d = si - (n.l - n.p);		 // inc integer width
  if (d > 0) {
    for (t = 0; t < d; t++) {	 // pad
      (n.d + n.l)[t] = 0;
    }
    n.l += d;
    n.p += d;
  }
}

/*
  add:
    adjust(b, max(a.p, b.p), max(a.l - a.p, b.l - b.p));
    Compress(..)
  sub:
*/

void print(SNum n) {
  int t;
  for (t = n.l - 1; t >= 0; t--) {
    printf("%2x", n.d[t]);
    if (t == n.p) printf(".");
  }
}

main(){
  SNum a, b, c, r;
  SNumClass nc;
  nc.init(r, new BYTE[200], 0);
  nc.init(a, new BYTE[100], 0x1234);
  nc.init(b, new BYTE[100], 0x89);
  nc.init(c, new BYTE[100], 0x1);
  nc.setr(&r);
  printf("a = ["); print(a); printf("]\n");
  printf("b = ["); print(b); printf("]\n");
  nc.add(c, a);
  printf("a+1 = ["); print(c); printf("]\n");
  nc.add(c, b);
  printf("c+b = ["); print(c); printf("]\n");

}

void SNumClass::init(SNum &n, BYTE *d, BYTE v) {
  n.p = 0;
  n.l = 1;
  if (d != NULL) {
    n.d = d;
    d[0] = v;
  }
}

void SNumClass::init(SNum &n, BYTE *d, int v) {
  n.p = 0;
  n.l = 1;
  if (d != NULL) {
    n.d = d;
    d[0] = v & 0xFF;
    v = v >> 8;
    if (v != 0) {
      d[1] = v;
      n.l++;
    }
  }
}

void SNumClass::init(SNum &n, BYTE *d, char *s) {
  int t = strlen(s) - 1;
  int sr = 10;		// s radix
  n.p = 0;
  n.l = 0;
  if (d != NULL) {
    while (t >= 0) {
    }}}

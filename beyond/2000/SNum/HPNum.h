
struct Flag {
	int CF:	1;	// Carry
	int AF:	1;	// Aux
	int OF:	1;	// Overflow
	int LF:	1;	// Loss
	int PF:	1;	// Parity
	int rF:	1;
	int ZF:	1;	// Zero
	int SF:	1;	// Sign
	Flag();
};

struct HPNum {
	UINT m_nRadix;
	BYTE *m_sData;
	UINT m_nLength;
	UINT m_nDL;	// int[l-1..d], dec[d-1..0]
	Flag m_fFlag;
	HPNum();
};

class _HPBaseArith {
protected:
	HPNum *m_hnNum;
public:
	void AddI(HPNum &, UINT nPos, UINT nI);
	void SubI(HPNum &, UINT nPos, UINT nI);

	void Shift(int);
	void Adjust(HPNum &, UINT nIL, UINT nDL);
public:
	void Add(HPNum &b, HPNum a);
	void Sub(HPNum &b, HPNum a);
	void Mul(HPNum &c, HPNum a, HPNum b);
	void Div(HPNum &c, HPNum a, HPNum b);
};

class HPBaseArith : public _HPBaseArith {
protected:
	int MaxLength, MaxDecimal;
protected:

public:
	void init(SNum &, BYTE *, BYTE);
	void init(SNum &, BYTE *, int);
	void init(SNum &, BYTE *, char *);
//	void init(SNum &, BYTE *, long);
//	void init(SNum &, BYTE *, float);

//	void Add
public:
	SNumClass() { Radix = 0x100; }
//  SNumClass(int r) { Radix = r; }
};


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

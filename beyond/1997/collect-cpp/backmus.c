#include <stdlib.h>
#include <dos.h>

#define L0	1300
#define L1	660
#define L2	L1/2
#define L3	L1*3/2
#define L4	L1/4
#define L5	L2*3/2
#define L8	L4/2

int MHZ[4][8] = {
  {1, 131, 147, 165, 175, 196, 220, 247},
  {1, 262, 294, 330, 349, 392, 440, 494},
  {1, 523, 587, 659, 698, 784, 880, 988},
  {1, 1047, 1174, 1319, 1397, 1568, 1760, 1976}
};
int *mds, *mdp;
int md[] = {
  16, L2, 16, L2, 21, L2, 22, L2, 23, L2, 23, L4, 22, L4,
  21, L2, 16, L2, 16, L2, 16, L2, 17, L2, 16, L2, 17, L4, 16, L4,
  15, L1, 16, L2, 16, L2, 16, L2, 16, L2, 15, L2, 16, L2, 16, L4,
  15, L4, 12, L2, 13, L2, 13, L2, 13, L2, 13, L2, 13, L1, 15, L1,
  16, L2, 16, L2, 16, L2, 21, L2, 22, L2, 23, L2, 23, L4, 22, L4,
  21, L2, 16, L2, 16, L2, 16, L2, 17, L2, 16, L2, 17, L4, 16, L4,
  15, L1, 22, L2, 22, L2, 22, L2, 22, L2, 17, L2, 16, L2, 15, L2,
  13, L2, 22, L2, 22, L2, 22, L2, 22, L2, 17, L2, 16, L2, 15, L2,
  13, L2, 16, L0,  0, L0, 11, L4, 12, L4, 13, L2, 15, L2, 15, L5, 16, L4,
  15, L2, 13, L2, 11, L5, 12, L4, 13, L2, 13, L2, 12, L2, 11, L2, 12, L3,
  11, L4, 12, L4, 13, L2, 15, L2, 15, L5, 16, L4, 15, L2, 13, L2, 11, L5,
  12, L4, 13, L2, 13, L2, 12, L2, 12, L2, 11, L0, 14, L1, 14, L1, 16, L2,
  16, L1, 16, L2, 15, L5, 15, L4, 13, L2, 11, L2, 12, L3, 11, L4, 12, L4,
  13, L2, 15, L2, 15, L5, 16, L4, 15, L2, 13, L2, 11, L5, 12, L4, 13, L2,
  13, L2, 12, L2, 12, L2, 11, L0,  0, L0, -1, -1, -1
};

void interrupt new();
void interrupt (*old)();

play (int *ms) {
  mds = ms;
  mdp = ms;
  old = getvect (0x1c);
  setvect (0x1c, new);
}

void interrupt new() {
  static int count, mtt, mdt, mdz = 1;
  if (mdz) {
    count++;
    if (*mds != -1) {
      if (mtt-count == 1) nosound ();
      if (count >= mtt) {
	if (*mds != 0) {
	  sound (MHZ[*mds / 10][*mds % 10]);
	} else nosound ();
	mds++;
	mtt = *mds * 18.2 / 1000;
	mds++;
	count = 0;
      }
    }
  }
  if (*mds == -1) mds = mdp;
  if (mdt > 0) mdt--;
  if ((peekb (0x40, 0x17) & 8) && (peekb (0x40, 0x17) & 4)) {
    mdz = 1 - mdz;
    mdt = 18;
    nosound();
  }
}

main () {
  play (md);
  while (1) {
    system ("C:\\Command");
  }
}

#ifndef COS51_CONST_H
#define COS51_CONST_H

#define TFREQ (XTAL / XMUL)

#define MHZ2C(f)    (~(unsigned) (TFREQ / (1000000 * (f))) + 1)
#define KHZ2C(f)    (~(unsigned) (TFREQ / (1000 * (f))) + 1)
#define HZ2C(f)     (~(unsigned) (TFREQ / (f)) + 1)

// (us/1000000) / (1 / TFREQ) = us * TFREQ / 1000000
#define US2C(us)    (~(unsigned) ((us) * TFREQ / 1000000.0) + 1)

// (ms/1000) / (1 / TFREQ) = ms * TFREQ / 1000
#define MS2C(ms)    (~(unsigned) ((ms) * TFREQ / 1000.0) + 1)

#endif

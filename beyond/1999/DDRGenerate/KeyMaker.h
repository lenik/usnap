
#ifndef __KEYMAKER_H

#define __KEYMAKER_H

// definitions for DDR keys

#define DDR_PAD			'0'

#define DDR_LEFT		'4'
#define DDR_RIGHT		'6'
#define DDR_UP			'8'
#define DDR_DOWN		'2'
#define DDR_UPLEFT		'7'
#define DDR_UPRIGHT		'9'
#define DDR_DOWNLEFT	'1'
#define DDR_DOWNRIGHT	'3'
#define DDR_UPDOWN		'A'
#define DDR_LEFTRIGHT	'B'

#define DDR_LEFTRIGHTUP		'?'
#define DDR_LEFTRIGHTDOWN	'?'
#define DDR_UPDOWNLEFT		'?'
#define DDR_UPDOWNRIGHT		'?'


// definitions for timing constants (ms)

#ifndef TIME_SLOWEST_COMKEYS
#	define TIME_SLOWEST_COMKEYS		100
#endif

// definitions for keybuffer

#ifndef MAXKEYS
#	define MAXKEYS					10000
#endif

// number of frequencies bases
#ifndef MAXFREQS
#	define MAXFREQS					50
#endif

// output atributates

#ifndef LENGTH_OUTPUTLINE
#	define LENGTH_OUTPUTLINE		40
#endif


typedef int key_t;


// key maker class
class keymaker {
public:
	key_t	keybuf[MAXKEYS], lastkey;
	clock_t	presstime[MAXKEYS], lasttime;
	clock_t	freqbase[MAXFREQS], nfreqs;
	int		bufpointer;
	int		buflength;

	long	gap;
	float	freqmain, bpm;

public:
	void initbuf();

	key_t noteKey(key_t key);

public:
	float calculateBpm();
	void digitalize(key_t *, long);
	int printOut();
	int printToFile(FILE *f);

};

#endif	// __KEYMAKER_H

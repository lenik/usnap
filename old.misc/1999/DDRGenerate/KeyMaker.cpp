
#include "stdafx.h"

#include <time.h>

#include "KeyMaker.h"

void keymaker::initbuf() {
	// default record loop
	lasttime = clock();
	lastkey = DDR_PAD;
	bufpointer = buflength = 0;
}

key_t keymaker::noteKey(key_t key) {
	clock_t currenttime = clock();
	clock_t deltat = currenttime - lasttime;

	if (lastkey == DDR_PAD) {
		lastkey = key;
	}
	if (deltat <= TIME_SLOWEST_COMKEYS) {
		// combination of keys
		switch (lastkey) {
		case DDR_LEFT:
			switch (key) {
			case DDR_UP:
				lastkey = DDR_UPLEFT; break;
			case DDR_DOWN:
				lastkey = DDR_DOWNLEFT; break;
			case DDR_RIGHT:
				lastkey = DDR_LEFTRIGHT; break;
			}
			break;
		case DDR_RIGHT:
			switch (key) {
			case DDR_UP:
				lastkey = DDR_UPRIGHT; break;
			case DDR_DOWN:
				lastkey = DDR_DOWNRIGHT; break;
			case DDR_LEFT:
				lastkey = DDR_LEFTRIGHT; break;
			}
			break;
		case DDR_UP:
			switch (key) {
			case DDR_LEFT:
				lastkey = DDR_UPLEFT; break;
			case DDR_RIGHT:
				lastkey = DDR_UPRIGHT; break;
			case DDR_DOWN:
				lastkey = DDR_UPDOWN; break;
			}
			break;
		case DDR_DOWN:
			switch (key) {
			case DDR_LEFT:
				lastkey = DDR_DOWNLEFT; break;
			case DDR_RIGHT:
				lastkey = DDR_DOWNRIGHT; break;
			case DDR_UP:
				lastkey = DDR_UPDOWN; break;
			}
			break;
		case DDR_UPLEFT:
			if (key == DDR_RIGHT)
				lastkey = DDR_LEFTRIGHTUP;
			if (key == DDR_DOWN)
				lastkey = DDR_UPDOWNLEFT;
			break;
		case DDR_UPRIGHT:
			if (key == DDR_LEFT)
				lastkey = DDR_LEFTRIGHTUP;
			if (key == DDR_DOWN)
				lastkey = DDR_UPDOWNRIGHT;
			break;
		case DDR_DOWNLEFT:
			if (key == DDR_RIGHT)
				lastkey = DDR_LEFTRIGHTDOWN;
			if (key == DDR_UP)
				lastkey = DDR_UPDOWNLEFT;
			break;
		case DDR_DOWNRIGHT:
			if (key == DDR_LEFT)
				lastkey = DDR_LEFTRIGHTDOWN;
			if (key == DDR_UP)
				lastkey = DDR_UPDOWNRIGHT;
			break;
		} //
	} // if deltaT <= slowest comkeys
	else
	{
		// record "lastkey" to keybuffer and increase
		// pointer which point to key buffer
		keybuf[bufpointer] = lastkey;
		presstime[bufpointer] = lasttime;

		bufpointer++;

		lastkey = DDR_PAD;
		// combinate some keys in ONE timestep
		// so we put this line here not the whole "if" body
		lasttime = currenttime;
	}
	return lastkey;
}

// max different kinds of frequency
#define MAX_FREQ_KIND			MAXFREQS
#define FREQ_BASE_COUNT			0
#define FREQ_AVERAGE			1

#define FREQ_BASE_WIDTH			(10 * 2)

// Beats per Minute calculation function
float keymaker::calculateBpm() {
	// first calculate most common frequency as main speed
	// scale:	freq +/- 10ms

	float mainfreq;
	float freqbase[MAX_FREQ_KIND];
	float freqbaseaverage[MAX_FREQ_KIND][2];
	int nKinds = 0;
	int i, j;

	// sort frequncies
	for (i = 0; i < buflength; i++) {
		float thisfreqbase =
			(presstime[i] + FREQ_BASE_WIDTH / 2) /
			(float)FREQ_BASE_WIDTH;
		thisfreqbase = thisfreqbase * FREQ_BASE_WIDTH - FREQ_BASE_WIDTH / 2;
		// search this freqbase
		int found = 0;
		for (j = 0; j < nKinds; j++) {
			if (freqbase[j] == thisfreqbase) {
				float t =
					freqbaseaverage[j][FREQ_AVERAGE] *
					freqbaseaverage[j][FREQ_BASE_COUNT] +
					thisfreqbase;
				freqbaseaverage[j][FREQ_BASE_COUNT]++;
				t /= freqbaseaverage[j][FREQ_BASE_COUNT];
				freqbaseaverage[j][FREQ_AVERAGE] = t;
				found = 1;
				break;
			}
		}
		if (!found) {
			// not found thisfreqbase in freqbase table
			// just add it
			freqbase[nKinds] = thisfreqbase;
			freqbaseaverage[nKinds][FREQ_BASE_COUNT] = 0;
			freqbaseaverage[nKinds][FREQ_AVERAGE] = 0;
			nKinds++;
		}
		// search ended
	} // sort

	// second, we find the most common frequency
	j = 0;
	for (i = 0; i < nKinds; i++) {
		if (freqbaseaverage[j][FREQ_BASE_COUNT] <
			freqbaseaverage[i][FREQ_BASE_COUNT])
			j = i;
	}
	mainfreq = freqbaseaverage[j][FREQ_AVERAGE];
	// we get the freq means how much millisecond a beat lasted
	// so BPM = 60 / ((in second)(freq / 1000))
	// at last, we calc BPM using BPM = 60 / (1 / mainfreq)
	freqmain = mainfreq;
	bpm = 60000 / mainfreq;
	// save freqbaseaverage[][FREQ_AVERAGE] to freqbase table
	for (i = 0; i < nKinds; i++) {
		freqbase[i] = freqbaseaverage[i][FREQ_AVERAGE];
	}
	nfreqs = nKinds;

	return bpm;
}

#ifdef WIN32
#	define MAX_TEMPLATE			9999999
#else
#	define MAX_TEMPLATE			32767
#endif

void keymaker::digitalize(key_t *buf, long bufsize) {
	// 1.trim interval of keybuffer
	// and 2.insert DDR_PADs into buf[]

	// 1:

	for (int i = 0; i < buflength; i++) {
		// 最逼近的延时 freqbase[mindiffi]
		int mindiff = MAX_TEMPLATE;
		int mindiffi = 0;
		for (int j = 0; j < nfreqs; i++) {
			if (abs(presstime[i] - freqbase[j]) < mindiff) {
				mindiffi = j;
				mindiff = abs(presstime[i] - freqbase[j]);
			}
			if (mindiff == 0) break;
		}

		if (i + 1 < buflength)	// last press only valid the key, ignore its lasting time
			presstime[i + 1] += presstime[i] - freqbase[j];
		presstime[i] = freqbase[j];
	}
/*
	// 2
	// note 4 keys in 1 beat, insert pads...
	i = j = 0;
	while (j < buflength) {

(easy monitor)
先保存整个踩步代码, 踩步全局时间(或时间差)
并作即时显示, 待完成后将复合步时间延迟内的
踩步合成, 叠加时间(如果是时间差).

	clock_t
*/
}
int keymaker::printOut() {
	return printToFile(stdout);
}

int keymaker::printToFile(FILE *f) {
	int i = 0;
	int r;
	do {
		r = fputc(keybuf[i++], f);
		if (r < 0 || r == EOF) return r;
		if (i % LENGTH_OUTPUTLINE == 0) fputc('\n', f);
	} while (i < buflength);

	return 0;
}

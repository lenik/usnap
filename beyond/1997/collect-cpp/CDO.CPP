
/***********************************************************
		CD-ROM LOW LEVEL OPERATION

		AUTHOR: DANSEI
		DATE:	2000.08.28
 ***********************************************************/

#include <stdio.h>

#include "cdo.h"

#include "cdo_dir.cpp"

int main(int argc, char **argv) {
	CLowCdrom		cdrom;
	BOOL			b;
	dirEntry_highsierra	dirEntry;

	printf("low level cdrom operating tool\nauthor by dansei, 2k\n\n");

	if (argc < 2) {
		printf("syntax: %s path\n", argv[0]);
		return 0;
	}

	GetDirectoryEntry(argv[1], &dirEntry, 0);

	printf("\
length 		= %d\n\
lengthXAR	= %d\n\
LBN_intel	= %lu\n\
lengthFile_intel= %lu\n\
interleaveSize	= %d\n\
interleaveSkipFa= %d\n\
volumeSequence  = %d\n\
lengthName	= %d\n\
filename_pad_sys= %s\n",
		(int)dirEntry.length,
		(int)dirEntry.lengthXAR,
		dirEntry.LBN_intel,
		dirEntry.lengthFile_intel,
		dirEntry.interleaveSize,
		dirEntry.interleaveSkipFactor,
		dirEntry.volumeSequence_intel,
		dirEntry.lengthName,
		dirEntry.filename_pad_systemdata
	);
}

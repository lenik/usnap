
#include <stdio.h>

#include "cdo.h"

main() {
	FILE *f;
	CLowCdrom c(100);
	LPBYTE lp;

	f = fopen("cdrom.$$$", "wb");
	if (f == NULL) {
		perror("");
		return 0;
	}

	BOOL b = c.absoluteRead(2 * 2048);
	lp = c.LockBuffer();
	fwrite(lp, 2048, 100, f);
	c.UnlockBuffer();
	fclose(f);

	return 0;
}

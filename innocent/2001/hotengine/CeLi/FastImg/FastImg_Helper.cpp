

memset(&bmiDest, 0, sizeof(BITMAPINFO));
memset(&bmiSrc, 0, sizeof(BITMAPINFO));
bmiDest.bmiHeader.biSize =
	bmiSrc.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
bmiDest.bmiHeader.biPlanes =
	bmiSrc.bmiHeader.biPlanes = 1;
bmiDest.bmiHeader.biBitCount =
	bmiSrc.bmiHeader.biBitCount = 32;

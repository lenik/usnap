
static BOOL hasbeeninited = FALSE;

void initvar() {
	DWORD	alpha, color;

	memset(&bmiDest, 0, sizeof(BITMAPINFO));
	memset(&bmiSrc, 0, sizeof(BITMAPINFO));
	bmiDest.bmiHeader.biSize =
		bmiSrc.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmiDest.bmiHeader.biPlanes =
		bmiSrc.bmiHeader.biPlanes = 1;
	bmiDest.bmiHeader.biBitCount =
		bmiSrc.bmiHeader.biBitCount = 32;

	for (alpha = 0; alpha <= 256; alpha++)
		for (color = 0; color < 256; color++)
			alphaColor[alpha][color] = (BYTE)(alpha * color / 256);

	FI_Init_Alpha(0x000000FF);

	hasbeeninited = TRUE;
}

void cleanup() {
	hasbeeninited = FALSE;
}


#pragma once


// take ideas:
//	- simple, useful
//	- font: extendable for any blocks-based collection
//

#define AEIMG_RGB32		0
#define AEIMG_RGB24		1
#define AEIMG_RGB16_565		2
#define AEIMG_SCALAR_I8		3
#define AEIMG_SCALAR_FLOAT	4
#define AEIMG_SCALAR_DOUBLE	5
#define AEIMG_NON_RASTERIZED	0x80000000

struct AEImage;
struct AEFont;
struct CharAttribute;
struct AETextLayout;

struct AEImage {
	DWORD id;	// for char-shape, this is used for char-id
	DWORD type;
	int width;
	int height;
	int bits;
	int iTypeSpecfic;
	void *pvTypeSpecfic;
	int iUserTag;
	void *pvUserTag;
	void *pImage;
	struct ImageRef {
		DWORD ValidBits;
		int Pitch;
		int BitsStorage;
	};
};

struct AEFont {
	DWORD id;	// font-class id
	int chars;

	/*
		AEImage described shapes:
		width/height is for the defined font-item shape.
			because a font shape may smaller than the character.
		pvTypeSpecfic may point to charshape structure.

		it is strong recommend that the font is rasterized.
		the kernel-support doesn't has vector-shape feature.
	*/
	struct charshape {
		LOGFONT logfont;
		BOOL colorized;
		BOOL vector_image;
		DWORD reserved;
	};
	AEImage *pShapes;

};

struct CharAttribute {
	// text coordinate:
	//	the graphics is always 2-Dimensions.
	//	graph<x,y> <font id> <char id> <color id>
	DWORD id;	// reserved.
	double x;
	double y;
	AEFont *pFont;
	AEImage *pCharShape;
	DWORD color_info;
	int iUserTag;
	void *pvUserTag;
};

struct TextLayout {
	// for root layout, this is reserved.
	// for sub-group, this is group-id.
	DWORD id;

	BYTE name[160];	// reserved for group name.

	int nSubGroups;	// sub-group, group nesting is supported.
	TextLayout *pSubGroups;

	int nElements;
	CharAttribute *pChars;

	double bound_x0;
	double bound_y0;
	double bound_w;
	double bound_h;
};


#pragma once


#include "fontdata.h"


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
#define AEIMG_MONO		6
#define AEIMG_NON_RASTERIZED	0x80000000

struct AEImage;
struct AEFont;
struct CharAttribute;
struct AETextLayout;

struct AEImage {
	void *pImage;
	DWORD id;	// for char-shape, this is used for char-id
	DWORD type;
	int width;
	int height;
	int bits;
	int iTypeSpecfic;	// this is the order (the precedence) for char in font.
	void *pvTypeSpecfic;
	int iUserTag;
	void *pvUserTag;
	DWORD colorKey;
	struct ImageRef {
		DWORD ValidBits;
		int Pitch;
		int BitsStorage;
	} ex;
};

struct AEFont {
	/*
		AEImage described shapes:
		width/height is for the defined font-item shape.
			because a font shape may smaller than the character.
		pvTypeSpecfic may point to charshape structure.

		it is strong recommend that the font is rasterized.
		the kernel-support doesn't has vector-shape feature.
	*/
	DWORD id;	// font-class id
	int chars;
	AEImage *pShapes;

	// pointer to the raw font data (AEF file format)
	FontHeader *pFontHdr;

	// internal font shape *declaration* :
	struct charshape {
		LOGFONT logfont;
		BOOL colorized;		// not support
		BOOL vector_image;	// not support
		DWORD reserved;
	};
	// the default shape is used if char_shape doesn't give the definition.
	// of course, it is obviously the same if char_shape point to this structure.
	charshape default_shape;

};

struct CharAttribute {
	// text coordinate:
	//	the graphics is always 2-Dimensions.
	//	graph<x,y> <font id> <char id> <color id>
	// here:
	//	<font id> is font name,	pFont->id
	//	<char id> is char ascii, pCharShape->id
	//	<color id> is color index, color_info
	//
	AEImage *pCharShape;	// this is a reference, not definition.
	DWORD id;	// reserved.
	double x;
	double y;
	// this is a font reference, the font structure contains meta definitions.
	// and these definitions are for all items of the font.
	AEFont *pFont;
	DWORD color_info;
	int iUserTag;
	void *pvUserTag;
};

struct AETextLayout {
	// for root layout, this is reserved.
	// for sub-group, this is group-id.
	DWORD id;

	BYTE name[160];	// reserved for group name.

	BOOL bIgnored;	// ignored sub-group.

	int nSubGroups;	// sub-group, group nesting is supported.
	AETextLayout *pSubGroups;

	int nElements;
	CharAttribute *pChars;

	double bound_x0;
	double bound_y0;
	double bound_w;
	double bound_h;
};


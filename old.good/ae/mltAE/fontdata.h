
#pragma once

#include "AEtype.h"
#include "SmartShape.h"

struct FontHeader;
struct FontBasicShape;
struct FontRuntime;

// FontHeader describes the font data stored in disk.
struct FontHeader {
	DWORD dwMagic;		// 0x54464541 'AEFT'
	short major;
	short minor;
	char szName[16];
	char szClass[16];
	char szFullname[64];
	char szAuthor[64];
	char szCompany[64];
	char szEmail[32];
	char szWeb[32];
	DWORD dwCharSet;
	DWORD dwLocale;		// reserved, = 0
	DWORD dwLanguage;	// reserved, = 0
	long nShapes;
	struct {
		int bColorized: 1;	// if colorized, RGB32 is always used.
		int bRasterized: 1;	// vector if not set.
	} Flags;
	enum _t_purpose {
		normal = 0,
		fixed,
		variable,
		script,
		cartoon,
		arbitrary,
		_force_dword = 0xFFFFFFFF
	} purpose;
	FontBasicShape basic_shape;
	// the default_guidelines give some descriptions, it shows what the font looks like,
	// so to let user do more precise work.
	FontRuntime default_guidelines;

	// offset of shape data definition after this DWORD.
	// this is generally zero, so the shape is immediately after the structure.
	DWORD dwDataOffset;

	// FontShape_Raster or FontShape_Vector array follows...
	//
};

struct FontBasicShape {
	int Height;
	int Width;
	int Escapement;
	int Orientation;
	int Weight;
};

struct FontRuntime {
	int weight;
	int italic;
	int underline;
	int strikeOut;
	int mirrorV;
	int mirrorH;
	int invertColor;
	int smooth;
	int outline;
	int marginH;
	int marginV;
	int scaleH;
	int scaleV;
	DWORD dwEffectCode;	// add-on graphics effect
	DWORD dwIndexOffset;	// font-level ascii offset
	int iUserTag;
	void *pvUserTag;
	int iSpecific;
	void *pvSpecfic;
};

struct FontShape_Raster {
	// size(bytes) of the shape. the shape structure may contains pad bytes.
	// generally it == sizeof(FontShape_Raster) + image.w * image.h * image.bits / 8)
	DWORD cbSize;
	// font image:
	//	image bits is 1 or 32, or else ignored.
	//	  1-bit when not colorized, 32-bit when colorized.
	//	pImage is always point at &colorData, and image.colorKey is the transparency color.
	//	  featherFactor define how transparency color will be used.
	AEImage image;
	DWORD dwReserved;
	int featherFactor;
	DWORD colorData[1];
};

struct FontShape_Vector {
	// size(bytes) of the shape. the shape structure may contains pad bytes.
	// generally it == (sizeof(shape) + each shape->npts*sizeof(point)) * nShapes
	DWORD cbSize;
	int nShapes;
	shape shapes[1];

	// shape::pvSpecfics can point to the shape_Specific structure, so as to contain cache.
	struct shape_Specific {
		// cached rasterized image for different size.
		int nInstances;
		AEImage *pCached;
	};

};

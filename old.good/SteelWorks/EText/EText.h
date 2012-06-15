
// Easy Text
// dansei 2001.2.5

struct ETextFont {
	LPTSTR		name;
	float		size;
	BOOL		bold;
	BOOL		italic;
	BOOL		underline;
	BOOL		strikeline;

	ETextFont() :
		name(NULL),
		size(0),
		bold(FALSE),
		italic(FALSE),
		underline(FALSE),
		strikeline(FALSE) {}
};

struct ETextGradient {
	RGBQUAD		c1;
	RGBQUAD		c2;
	enum DIRECTION {
		horiz = 0,
		vert
	} d;

	ETextGradient() : d(horiz) {
		*(LPDWORD)&c1 = 0;
		*(LPDWORD)&c2 = 0;
	}

};

struct ETextEffect {
	BOOL		bGradient;
	ETextGradient	gradient;

	ETextEffect() : bGradient(FALSE) {}
};

struct ETextChar {
	LPTSTR		chars;
	RGBQUAD		foreColor;
	RGBQUAD		backColor;
	ETextFont	font;
	ETextEffect	fx;

	ETextChar() {
		chars = NULL;
		*(LPDWORD)&foreColor = 0;
		*(LPDWORD)&backColor = 0;
	}
};

typedef CArray<ETextChar, ETextChar&> ETextCharArray;

enum ETextAlign {
	bottom = 0,
	middle,
	top
};

struct ETextStr : public ETextCharArray {
	ETextAlign	m_align;

	ETextStr() : ETextCharArray() {
		m_align = bottom;
	}
};

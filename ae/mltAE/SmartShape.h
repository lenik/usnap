
#pragma once

struct shape;

// interface
//	ISmartShapes:		using provided engine, drawing the graphics(include advanced) for specified platform.
//	ISmartShapesCreator:	generate vector points for many shapes(include advanced.)
//	IGraphEngine:		all methods drawing the basic graphics for specified platform.
class ISmartShapes;
class ISmartShapesCreator;
class IGraphEngine;

// class
//	SmartShapes_GDI: draw out shapes, advanced shapes
//	SmartShapesCreator: generate vector points for graphics
//	GraphEngine_RasterGDI: the WinGDI engine
class SmartShapes_GDI;
class SmartShapesCreator;
class GraphEngine_RasterGDI;


struct shape {
	enum predefined_shape_code {
		none = 0,
		pixel,		// p p p ...
		seg,		// p-p p-p p-p...
		line,		// p-p-p-p-...
		star,		// p-(p,p,p,p,...)
		tri,		// p-p-p p-p-p p-p-p ...
		trifan,		// p-(p,p,p,p,...)
		rect,		// p-p-p-p p-p-p-p ...
		ellipse,	// p-p-p-p p-p-p-p ...
		poly,		// p0-p-p-p-...-p(-p0)
		bezier,		// p-cp-cp-cp-...-cp-p
		bezier2,	// p-p-p-p-...-p
		nurb,		// cp-cp-cp-cp-...
	};
	struct point {
		double x;
		double y;
		DWORD color;
		union {
			int fill_group: 1;
		} flags;
		DWORD id;
		int iUserTag;
		void *pvUserTag;
		virtual ~point() {}
	};
	predefined_shape_code code;
	point *pts;
public:
	int id;
	int iSpecific;
	void *pvSpecific;
	int iUserTag;
	void *pvUserTag;
public:
	BOOL setnpts(int npts);
	shape() {
		code = none;
		pts = NULL;
		m_npts = 0;
	}
	~shape() {
		SAFE_DELETE_ARRAY(pts);
	}

	int m_npts;
protected:
	int m_nalloc;
};


//
// interfaces:
//	ISmartShapes
//	ISmartShapesCreator
//	IGraphEngine : ISmartShapesCreator
//
class ISmartShapes {
public:
	virtual BOOL paint() = 0;
	virtual BOOL clear() = 0;
	void move() {
		if (bPainted) clear();
		paint();
	}
protected:
	BOOL bPainted;
	// paint() is expected to draw the pWishPaintData
	// and clear() is expected to clear the pWishClearData
	void *pShapes;
	void *pLastShapes;
public:
	ISmartShapes() {
		bPainted = FALSE;
		pShapes = NULL;
		pLastShapes = NULL;
	}
};

class ISmartShapesCreator {
public:
	// basics
	virtual BOOL Pixel(int x, int y) = 0;
	virtual BOOL Line(int x0, int y0, int x1, int y1) = 0;
	virtual BOOL Triangle(int x0, int y0, int x1, int y1, int x2, int y2) {
		return Line(x0, y0, x1, y1) &&
			Line(x1, y1, x2, y2) &&
			Line(x2, y2, x0, y0);
	}
	virtual BOOL Rectangle(int x0, int y0, int x1, int y1) {
		return Line(x0, y0, x1, y0) &&
			Line(x1, y0, x1, y1) &&
			Line(x1, y1, x0, y1) &&
			Line(x0, y1, x0, y0);
	}
	virtual BOOL Bezier(int npts, int *pts) = 0;
	virtual BOOL Ellipse(int x0, int y0, int x1, int y1) {
		int pts[10];	// 5 pts
		pts[0] = (x0 + x1) / 2;
		pts[1] = y0;
		pts[2] = x1;
		pts[3] = (y0 + y1) / 2;
		pts[4] = pts[0];
		pts[5] = y1;
		pts[6] = x0;
		pts[7] = pts[3];
		pts[8] = pts[0];
		pts[9] = pts[1];
		return Bezier(5, pts);
	}
public:
	// advances
public:
	BOOL visible;
	DWORD rop2;
public:
	ISmartShapesCreator() {
		visible = FALSE;
		rop2 = SRCCOPY;
	}
};

class IGraphEngine : public ISmartShapesCreator {
public:
	DWORD fg_color;
	DWORD bg_color;
	DWORD fill_color;
	DWORD line_style;
	DWORD line_graph;
	DWORD fill_style;
	DWORD fill_graph;
};



//
// classes
//	SmartShapes_GDI: draw out shapes, advanced shapes
//	SmartShapesCreator: generate vector points for graphics
//	GraphEngine_RasterGDI: the WinGDI engine
//
class SmartShapes_GDI : public ISmartShapes {
public:
	virtual BOOL paint();
	virtual BOOL clear();
public:
	int m_nShapes;
	int m_nLastShapes;
	BOOL m_bAutoDestroy;
	inline shape *&get_shapes() {
		return (shape *&)pShapes;
	}
	inline shape *&get_lastshapes() {
		return (shape *&)pLastShapes;
	}

	HDC m_hDC;
	IGraphEngine *m_pEngine;
public:
	SmartShapes_GDI(IGraphEngine *pEngineUsing) {
		m_nShapes = m_nLastShapes = 0;
		m_hDC = NULL;
		m_bAutoDestroy = TRUE;
		m_pEngine = pEngineUsing;
	}
	~SmartShapes_GDI() {
		if (m_bAutoDestroy) {
			SAFE_DELETE_ARRAY(get_shapes());
			SAFE_DELETE_ARRAY(get_lastshapes());
		}
	}
};


class SmartShapesCreator : public ISmartShapesCreator {
public:
	// SmartDrawing_Int
	virtual BOOL Pixel(int x, int y);
	virtual BOOL Line(int x0, int y0, int x1, int y1);
	virtual BOOL Triangle(int x0, int y0, int x1, int y1, int x2, int y2);
	virtual BOOL Rectangle(int x0, int y0, int x1, int y1);
	virtual BOOL Bezier(int npts, int *pts);
	virtual BOOL Ellipse(int x0, int y0, int x1, int y1);
public:
	BOOL bVectorColorMode;
	DWORD *pCurrentColors;

	ISmartShapes *m_pshapes;
public:
	SmartShapesCreator(ISmartShapes *pBindShapes);
};

class GraphEngine_RasterGDI : public IGraphEngine {
public:
	virtual BOOL Pixel(int x, int y);
	virtual BOOL Line(int x0, int y0, int x1, int y1);
	virtual BOOL Triangle(int x0, int y0, int x1, int y1, int x2, int y2);
	virtual BOOL Rectangle(int x0, int y0, int x1, int y1);
	virtual BOOL Bezier(int npts, int *pts);
	virtual BOOL Ellipse(int x0, int y0, int x1, int y1);

public:
	HDC m_hDC;
	HBRUSH m_hBrush;
	HPEN m_hPen;
public:
	BOOL UpdateTool();
	GraphEngine_RasterGDI(HDC hBindDC) {
		m_hDC = hBindDC;
		m_hBrush = NULL;
		m_hPen = NULL;
	}
};

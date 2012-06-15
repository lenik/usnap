// LightDemoView.h : interface of the CLightDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIGHTDEMOVIEW_H__4BA31B4C_C07A_11D3_8AD1_484C0001E209__INCLUDED_)
#define AFX_LIGHTDEMOVIEW_H__4BA31B4C_C07A_11D3_8AD1_484C0001E209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

struct pos {
	double x;
	double y;
	double z;
	double w;
};
struct rgba {
	double r;
	double g;
	double b;
	double a;
};
struct f3v {
	double Kc;
	double Ki;
	double Kq;
};

char *actiondesc[] = {
	"移动光源坐标     PgUp/PgDn移动Z坐标	-Ww+",
	"[ a环境光  d漫反射  m镜面反射  -RGBArgba+ ]",
	"改变聚光灯  轴向 PgUp/PgDn移动Z坐标  +理论坐标/-自然坐标",
	"改变会聚强度 +/-  改变聚光张角 -10<,-2  +2.>+10    改变衰减系数     定常0/) 线性1/! 二次2/@"
};

class CLightDemoView : public CView
{
protected: // create from serialization only
	CLightDemoView();
	DECLARE_DYNCREATE(CLightDemoView)

// Attributes
public:
	CLightDemoDoc* GetDocument();
public:
	CRect viewrect;
	pos lpos[8];		// 光源坐标
	rgba ambient[8];
	rgba diffuse[8];
	rgba specular[8];
	double spotCutoff[8];
	double spotExponent[8];
	f3v attenuation[8]; // 衰减系数
public:
	int currentLight;
	int currentAction;
	// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLightDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLightDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void DrawLight(pos);
	void DrawSpotLight(pos, pos);
	void DrawAllLights();

	pos GetRasPos(pos);
	pos GetGlPos(pos);

// Generated message map functions
protected:
	//{{AFX_MSG(CLightDemoView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LightDemoView.cpp
inline CLightDemoDoc* CLightDemoView::GetDocument()
   { return (CLightDemoDoc*)m_pDocument; }
#endif

pos GetRasPos(pos glpos);
pos GetGlPs(pos raspos);

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIGHTDEMOVIEW_H__4BA31B4C_C07A_11D3_8AD1_484C0001E209__INCLUDED_)

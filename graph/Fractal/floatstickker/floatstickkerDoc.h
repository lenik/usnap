// floatstickkerDoc.h : interface of the CFloatstickkerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLOATSTICKKERDOC_H__1362773D_9E48_4B7A_AA14_D603388B8682__INCLUDED_)
#define AFX_FLOATSTICKKERDOC_H__1362773D_9E48_4B7A_AA14_D603388B8682__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFloatstickkerDoc : public CDocument
{
protected: // create from serialization only
	CFloatstickkerDoc();
	DECLARE_DYNCREATE(CFloatstickkerDoc)

// Attributes
public:
	struct PT {
		double x;
		double y;
		PT() { x = y = 0; }
		PT(double _x, double _y) : x(_x), y(_y) {}
	};
	typedef CList<PT,PT> CPointList;

	CPointList stickked;

	int	p_nums;
	double	p_speed;
	double	p_power;
	double	p_radius;

	BOOL notcollision(PT);

	void regenerate();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFloatstickkerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFloatstickkerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFloatstickkerDoc)
	afx_msg void OnButtonSetParameters();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOATSTICKKERDOC_H__1362773D_9E48_4B7A_AA14_D603388B8682__INCLUDED_)

// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__7FD334E7_EBA6_4EB0_95E8_3598BF428C27__INCLUDED_)
#define AFX_DLGPROXY_H__7FD334E7_EBA6_4EB0_95E8_3598BF428C27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COleDlg;

/////////////////////////////////////////////////////////////////////////////
// COleDlgAutoProxy command target

class COleDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(COleDlgAutoProxy)

	COleDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	COleDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~COleDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(COleDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(COleDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(COleDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__7FD334E7_EBA6_4EB0_95E8_3598BF428C27__INCLUDED_)

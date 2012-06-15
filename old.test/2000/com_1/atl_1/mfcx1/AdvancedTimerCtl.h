#if !defined(AFX_ADVANCEDTIMERCTL_H__F09917AB_A70F_4198_B21E_48678F24EB88__INCLUDED_)
#define AFX_ADVANCEDTIMERCTL_H__F09917AB_A70F_4198_B21E_48678F24EB88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AdvancedTimerCtl.h : Declaration of the CAdvancedTimerCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CAdvancedTimerCtrl : See AdvancedTimerCtl.cpp for implementation.

class CAdvancedTimerCtrl : public COleControl
{
	DECLARE_DYNCREATE(CAdvancedTimerCtrl)

// Constructor
public:
	CAdvancedTimerCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdvancedTimerCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CAdvancedTimerCtrl();

	DECLARE_OLECREATE_EX(CAdvancedTimerCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CAdvancedTimerCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CAdvancedTimerCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CAdvancedTimerCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CAdvancedTimerCtrl)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CAdvancedTimerCtrl)
	long m_interval;
	afx_msg void OnIntervalChanged();
	long m_timerEnabled;
	afx_msg void OnTimerEnabledChanged();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CAdvancedTimerCtrl)
	void FireOnTimer(short _Timer)
		{FireEvent(eventidOnTimer,EVENT_PARAM(VTS_I2), _Timer);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CAdvancedTimerCtrl)
	dispidInterval = 1L,
	dispidTimerEnabled = 2L,
	eventidOnTimer = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADVANCEDTIMERCTL_H__F09917AB_A70F_4198_B21E_48678F24EB88__INCLUDED)

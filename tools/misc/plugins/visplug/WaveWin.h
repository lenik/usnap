// WaveWin.h
//
//////////////////////////////////////////////////////////////////////

#ifndef CWAVEWIN_H
#define CWAVEWIN_H

class CWaveWin : public CWnd
{
	CRect winRect;
	BOOL m_bClosed;
public:
	BOOL IsClosed() { return m_bClosed; }
public:
	CWaveWin();
	virtual ~CWaveWin();
	virtual BOOL Create(const CString& title,int icon);
	void WriteIni(LPCSTR iniFilename);
	void ReadIni(LPCSTR iniFilename);

	enum { TIMER_ID = 1, TIMER_ELAPSE = 25 };
	UINT m_nTimerID;
	//{{AFX_MSG(CWaveWin)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif

#pragma once

#include "t03cv.h"

class CMainFrame : public CFrameWnd {
public:
        CMainFrame();
protected:
        DECLARE_DYNAMIC(CMainFrame);
public:
        virtual BOOL PreCreateWindow(CREATESTRUCT &cs);
        virtual BOOL OnCmdMsg(UINT nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo);

        virtual BOOL ~CMainFrame();
#ifdef _DEBUG
        virtual BOOL AssertValid() const;
        virtual BOOL Dump(CDumpContext &dc) const;
#endif
        CChildView m_wndView;
protected:
        afx_msg void OnSetFocus(CWnd *pOldWnd);
};

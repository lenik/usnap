#pragma once

class CChildView : public CWnd {
public:
        CChildView();

        virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

        virtual ~CChildView();

protected:
        afx_msg void OnPaint();

};

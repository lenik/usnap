// CatPropPage.h : Declaration of the CCatPropPage

#ifndef __CATPROPPAGE_H_
#define __CATPROPPAGE_H_

#include "resource.h"       // main symbols

#include "Cat002.h"
typedef CComObject<CCat002> RawCat;

EXTERN_C const CLSID CLSID_CatPropPage;

/////////////////////////////////////////////////////////////////////////////
// CCatPropPage
class ATL_NO_VTABLE CCatPropPage :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCatPropPage, &CLSID_CatPropPage>,
	public IPropertyPageImpl<CCatPropPage>,
	public CDialogImpl<CCatPropPage>
{
public:
	CCatPropPage()
	{
		m_dwTitleID = IDS_TITLECatPropPage;
		m_dwHelpFileID = IDS_HELPFILECatPropPage;
		m_dwDocStringID = IDS_DOCSTRINGCatPropPage;
	}

	enum {IDD = IDD_CATPROPPAGE};

DECLARE_REGISTRY_RESOURCEID(IDR_CATPROPPAGE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCatPropPage)
	COM_INTERFACE_ENTRY(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP(CCatPropPage)
	CHAIN_MSG_MAP(IPropertyPageImpl<CCatPropPage>)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	STDMETHOD(Apply)(void)
	{
		ATLTRACE(_T("CCatPropPage::Apply\n"));
		for (UINT i = 0; i < m_nObjects; i++)
		{
			// Do something interesting here
			// ICircCtl* pCirc;
			// m_ppUnk[i]->QueryInterface(IID_ICircCtl, (void**)&pCirc);
			// pCirc->put_Caption(CComBSTR("something special"));
			// pCirc->Release();

            HRESULT hr;
            ICat002 *pCat = 0;
            hr = m_ppUnk[i]->QueryInterface(IID_ICat002, (void **)&pCat);
            if (SUCCEEDED(hr)) {

                RawCat *pRaw = 0;
                hr = pCat->GetRawObject((long *)&pRaw);
                ATLASSERT(SUCCEEDED(hr));

                HWND hTxtName = GetDlgItem(IDC_EDIT_NAME);
                int nText;
                char buf[100];

                nText = ::SendMessage(hTxtName, WM_GETTEXTLENGTH, 0, 0);
                // assert ok.
                ::SendMessage(hTxtName, WM_GETTEXT, nText+1, (LPARAM)buf);

                pRaw->m_szName = strdup(buf);
                pRaw->Release();
            }
		}
		m_bDirty = FALSE;
		return S_OK;
	}
};

#endif //__CATPROPPAGE_H_

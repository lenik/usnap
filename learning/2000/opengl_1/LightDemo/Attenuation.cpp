// Attenuation.cpp : implementation file
//

#include "stdafx.h"
#include "LightDemo.h"
#include "Attenuation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Attenuation dialog


Attenuation::Attenuation(CWnd* pParent /*=NULL*/)
	: CDialog(Attenuation::IDD, pParent)
{
	//{{AFX_DATA_INIT(Attenuation)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Attenuation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Attenuation)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Attenuation, CDialog)
	//{{AFX_MSG_MAP(Attenuation)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Attenuation message handlers

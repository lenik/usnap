// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "ole.h"
#include "DlgProxy.h"
#include "oleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COleDlgAutoProxy

IMPLEMENT_DYNCREATE(COleDlgAutoProxy, CCmdTarget)

COleDlgAutoProxy::COleDlgAutoProxy()
{
	EnableAutomation();

	// To keep the application running as long as an automation
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(COleDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (COleDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

COleDlgAutoProxy::~COleDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void COleDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(COleDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(COleDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COleDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(COleDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOle to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the
//  dispinterface in the .ODL file.

// {BA7DA016-D2E8-4C48-8FF5-380CC0FD2A6F}
static const IID IID_IOle =
{ 0xba7da016, 0xd2e8, 0x4c48, { 0x8f, 0xf5, 0x38, 0xc, 0xc0, 0xfd, 0x2a, 0x6f } };

BEGIN_INTERFACE_MAP(COleDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(COleDlgAutoProxy, IID_IOle, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {D792264A-68A2-46F4-85EB-1D8EC5440146}
IMPLEMENT_OLECREATE2(COleDlgAutoProxy, "Ole.Application", 0xd792264a, 0x68a2, 0x46f4, 0x85, 0xeb, 0x1d, 0x8e, 0xc5, 0x44, 0x1, 0x46)

/////////////////////////////////////////////////////////////////////////////
// COleDlgAutoProxy message handlers

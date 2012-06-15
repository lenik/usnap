// WNetAddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WNetAdd.h"
#include "WNetAddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
			// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWNetAddDlg dialog

CWNetAddDlg::CWNetAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWNetAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWNetAddDlg)
	m_strLocalName = _T("");
	m_strProvider = _T("");
	m_strRemoteName = _T("");
	m_strStatus = _T("");
	m_strComment = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWNetAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWNetAddDlg)
	DDX_Control(pDX, IDC_COMBO_DISPLAY, m_cboDisplayType);
	DDX_Control(pDX, IDC_COMBO_USAGE, m_cboUsage);
	DDX_Control(pDX, IDC_COMBO_SCOPE, m_cboScope);
	DDX_Control(pDX, IDC_COMBO_RESOURCE_TYPE, m_cboResourceType);
	DDX_Text(pDX, IDC_EDIT_LOCAL_NAME, m_strLocalName);
	DDV_MaxChars(pDX, m_strLocalName, 512);
	DDX_Text(pDX, IDC_EDIT_PROVIDER, m_strProvider);
	DDV_MaxChars(pDX, m_strProvider, 512);
	DDX_Text(pDX, IDC_EDIT_REMOTE_NAME, m_strRemoteName);
	DDV_MaxChars(pDX, m_strRemoteName, 512);
	DDX_Text(pDX, IDC_STATIC_STATUS, m_strStatus);
	DDX_Text(pDX, IDC_EDIT_COMMENT, m_strComment);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWNetAddDlg, CDialog)
	//{{AFX_MSG_MAP(CWNetAddDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD_CONNECTION2, OnButtonAddConnection2)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON_RE_ENUM, OnButtonReEnum)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE2, OnButtonClose2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWNetAddDlg message handlers

BOOL CWNetAddDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
			CString strAboutMenu;
			strAboutMenu.LoadString(IDS_ABOUTBOX);
			if (!strAboutMenu.IsEmpty())
			{
				pSysMenu->AppendMenu(MF_SEPARATOR);
				pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
			}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);				// Set big icon
	SetIcon(m_hIcon, FALSE);			// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWNetAddDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
			CAboutDlg dlgAbout;
			dlgAbout.DoModal();
	}
	else
	{
			CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWNetAddDlg::OnPaint()
{
	if (IsIconic())
	{
			CPaintDC dc(this); // device context for painting

			SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

			// Center icon in client rectangle
			int cxIcon = GetSystemMetrics(SM_CXICON);
			int cyIcon = GetSystemMetrics(SM_CYICON);
			CRect rect;
			GetClientRect(&rect);
			int x = (rect.Width() - cxIcon + 1) / 2;
			int y = (rect.Height() - cyIcon + 1) / 2;

			// Draw the icon
			dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
			CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWNetAddDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWNetAddDlg::OnButtonAddConnection2()
{
	// TODO: Add your control notification handler code here
	NETRESOURCE nr;
	TCHAR buf[512];

	this->UpdateData();

	nr.dwType = RESOURCETYPE_ANY;
	nr.lpLocalName = (LPTSTR)(LPCTSTR)this->m_strLocalName;
	nr.lpRemoteName = (LPTSTR)(LPCTSTR)this->m_strRemoteName;
	nr.lpProvider = NULL; //(LPCTSTR)this->m_strProvider;
	ltoa(this->m_cboResourceType.GetCurSel(), buf, 10);

	TCHAR szUserName[32] = "",
			  szPassword[32] = "";

	status(WNetAddConnection2(&nr, NULL, NULL, FALSE));

	this->UpdateData(FALSE);
}

void CWNetAddDlg::status(DWORD status) {
	TCHAR buf[1024], *p;
	TCHAR provider[512];
	ltoa(status, buf, 10);
	p = buf + strlen(buf);

	switch (status) {
	case WN_SUCCESS:		strcpy(p, "WN_SUCCESS"); break;
	case WN_NOT_SUPPORTED:		strcpy(p, "WN_NOT_SUPPORTED"); break;
	case WN_CANCEL:			strcpy(p, "WN_CANCEL"); break;
	case WN_RETRY:			strcpy(p, "WN_RETRY"); break;
	case WN_NET_ERROR:		strcpy(p, "WN_NET_ERROR"); break;
	case WN_MORE_DATA:		strcpy(p, "WN_MORE_DATA"); break;
	case WN_BAD_POINTER:		strcpy(p, "WN_BAD_POINTER"); break;
	case WN_BAD_VALUE:		strcpy(p, "WN_BAD_VALUE"); break;
	case WN_BAD_USER:		strcpy(p, "WN_BAD_USER"); break;
	case WN_BAD_PASSWORD:		strcpy(p, "WN_BAD_PASSWORD"); break;
	case WN_ACCESS_DENIED:		strcpy(p, "WN_ACCESS_DENIED"); break;
	case WN_FUNCTION_BUSY:		strcpy(p, "WN_FUNCTION_BUSY"); break;
	//case WN_WINDOWS_ERROR:	strcpy(p, "WN_WINDOWS_ERROR"); break;
	case WN_OUT_OF_MEMORY:		strcpy(p, "WN_OUT_OF_MEMORY"); break;
	case WN_NO_NETWORK:		strcpy(p, "WN_NO_NETWORK"); break;
	case WN_EXTENDED_ERROR:		strcpy(p, "WN_EXTENDED_ERROR"); break;
	case WN_BAD_LEVEL:		strcpy(p, "WN_BAD_LEVEL"); break;
	case WN_BAD_HANDLE:		strcpy(p, "WN_BAD_HANDLE"); break;
	case WN_NOT_INITIALIZING:	strcpy(p, "WN_NOT_INITIALIZING"); break;
	case WN_NO_MORE_DEVICES:	strcpy(p, "WN_NO_MORE_DEVICES"); break;
	case WN_NOT_CONNECTED:		strcpy(p, "WN_NOT_CONNECTED"); break;
	case WN_OPEN_FILES:		strcpy(p, "WN_OPEN_FILES"); break;
	case WN_DEVICE_IN_USE:		strcpy(p, "WN_DEVICE_IN_USE"); break;
	case WN_BAD_NETNAME:		strcpy(p, "WN_BAD_NETNAME"); break;
	case WN_BAD_LOCALNAME:		strcpy(p, "WN_BAD_LOCALNAME"); break;
	case WN_ALREADY_CONNECTED:	strcpy(p, "WN_ALREADY_CONNECTED"); break;
	case WN_DEVICE_ERROR:		strcpy(p, "WN_DEVICE_ERROR"); break;
	case WN_CONNECTION_CLOSED:	strcpy(p, "WN_CONNECTION_CLOSED"); break;
	case WN_NO_NET_OR_BAD_PATH:	strcpy(p, "WN_NO_NET_OR_BAD_PATH"); break;
	case WN_BAD_PROVIDER:		strcpy(p, "WN_BAD_PROVIDER"); break;
	case WN_CANNOT_OPEN_PROFILE:	strcpy(p, "WN_CANNOT_OPEN_PROFILE"); break;
	case WN_BAD_PROFILE:		strcpy(p, "WN_BAD_PROFILE"); break;
	case WN_BAD_DEV_TYPE:		strcpy(p, "WN_BAD_DEV_TYPE"); break;
	case WN_DEVICE_ALREADY_REMEMBERED:
					strcpy(p, "WN_DEVICE_ALREADY_REMEMBERED"); break;
	case WN_CONNECTED_OTHER_PASSWORD:
					strcpy(p, "WN_CONNECTED_OTHER_PASSWORD"); break;

	case WN_NO_MORE_ENTRIES:	strcpy(p, "WN_NO_MORE_ENTRIES"); break;
	case WN_NOT_CONTAINER:		strcpy(p, "WN_NOT_CONTAINER"); break;

	case WN_NOT_AUTHENTICATED:	strcpy(p, "WN_NOT_AUTHENTICATED"); break;
	case WN_NOT_LOGGED_ON:		strcpy(p, "WN_NOT_LOGGED_ON"); break;
	case WN_NOT_VALIDATED:		strcpy(p, "WN_NOT_VALIDATED"); break;
	default: ;
	}

	p = buf + strlen(buf);

	WNetGetLastError(&status, p, sizeof(buf) + p - buf, provider, sizeof(provider));


	this->m_strStatus = (LPCTSTR)buf;
	this->UpdateData(FALSE);
}

int CWNetAddDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
			return -1;

	// TODO: Add your specialized creation code here
	this->m_strStatus = "No error";
	this->m_strLocalName = "Y:";
	this->m_strRemoteName = "\\\\tc-info\\packs";

	return 0;
}

void CWNetAddDlg::OnButtonReEnum()
{
	// TODO: Add your control notification handler code here

	NETRESOURCE nr;
	DWORD dwScope = RESOURCE_CONNECTED,
		  dwType = RESOURCETYPE_ANY,
		  dwUsage = RESOURCEUSAGE_ALL,
		  dwDisplayType = RESOURCEDISPLAYTYPE_GENERIC;

	this->UpdateData();

	switch (this->m_cboScope.GetCurSel()) {
	case 0: dwScope = RESOURCE_CONNECTED; break;
	case 1: dwScope = RESOURCE_GLOBALNET; break;
	case 2: dwScope = RESOURCE_REMEMBERED; break;
	case 3: dwScope = RESOURCE_RECENT; break;
	case 4: dwScope = RESOURCE_CONTEXT; break;
	default: ;
	}

	switch (this->m_cboResourceType.GetCurSel()) {
	case 0: dwType = RESOURCETYPE_ANY; break;
	case 1: dwType = RESOURCETYPE_DISK; break;
	case 2: dwType = RESOURCETYPE_PRINT; break;
	case 3: dwType = RESOURCETYPE_RESERVED; break;
	case 4: dwType = RESOURCETYPE_UNKNOWN; break;
	default: ;
	}

	switch (this->m_cboUsage.GetCurSel()) {
	case 0: dwUsage = RESOURCEUSAGE_CONNECTABLE; break;
	case 1: dwUsage = RESOURCEUSAGE_CONTAINER; break;
	case 2: dwUsage = RESOURCEUSAGE_NOLOCALDEVICE; break;
	case 3: dwUsage = RESOURCEUSAGE_SIBLING; break;
	case 4: dwUsage = RESOURCEUSAGE_ATTACHED; break;
	case 5: dwUsage = RESOURCEUSAGE_ALL; break;
	case 6: dwUsage = RESOURCEUSAGE_RESERVED; break;
	default: ;
	}

	switch (this->m_cboDisplayType.GetCurSel()) {
	case 0: dwDisplayType = RESOURCEDISPLAYTYPE_GENERIC; break;
	case 1: dwDisplayType = RESOURCEDISPLAYTYPE_DOMAIN; break;
	case 2: dwDisplayType = RESOURCEDISPLAYTYPE_SERVER; break;
	case 3: dwDisplayType = RESOURCEDISPLAYTYPE_SHARE; break;
	case 4: dwDisplayType = RESOURCEDISPLAYTYPE_FILE; break;
	case 5: dwDisplayType = RESOURCEDISPLAYTYPE_GROUP; break;
	case 6: dwDisplayType = RESOURCEDISPLAYTYPE_NETWORK; break;
	case 7: dwDisplayType = RESOURCEDISPLAYTYPE_ROOT; break;
	case 8: dwDisplayType = RESOURCEDISPLAYTYPE_SHAREADMIN; break;
	case 9: dwDisplayType = RESOURCEDISPLAYTYPE_DIRECTORY; break;
	case 10: dwDisplayType = RESOURCEDISPLAYTYPE_TREE; break;
	case 11: dwDisplayType = RESOURCEDISPLAYTYPE_NDSCONTAINER; break;
	default: ;
	}

	nr.dwScope = dwScope;
	nr.dwType = dwType;
	nr.dwUsage = dwUsage;
	nr.dwDisplayType = dwDisplayType;
	nr.lpLocalName = (LPSTR)(LPCTSTR)this->m_strLocalName;
	nr.lpRemoteName = (LPSTR)(LPCTSTR)this->m_strRemoteName;
	nr.lpProvider = (LPSTR)(LPCTSTR)this->m_strProvider;
	nr.lpComment = (LPSTR)(LPCTSTR)this->m_strComment;

	DWORD result = WNetOpenEnum(dwScope, dwType, dwUsage, &nr, &hEnum);
	if (result != NO_ERROR)
		hEnum = 0;
	else
		show(nr);
	status(result);
}

void CWNetAddDlg::OnButtonNext()
{
	// TODO: Add your control notification handler code here
	DWORD nCount = 1;
	NETRESOURCE buf[10];
	DWORD bufsize = sizeof(NETRESOURCE) * 10;
	DWORD r;

	if (hEnum) {
		r = WNetEnumResource(hEnum, &nCount, &buf, &bufsize);
		status(r);
		if (r == NO_ERROR) show(buf[0]);
	} else {
		this->m_strStatus = "Ã¶¾Ù¾ä±ú´í!";
		UpdateData(FALSE);
	}
}

void CWNetAddDlg::show(NETRESOURCE nr) {
	this->m_strLocalName = nr.lpLocalName;
	this->m_strRemoteName = nr.lpRemoteName;
	this->m_strProvider = nr.lpProvider;
	this->m_strComment = nr.lpComment;

	switch (nr.dwScope) {
	case RESOURCE_CONNECTED: this->m_cboScope.SetCurSel(0); break;
	case RESOURCE_GLOBALNET: this->m_cboScope.SetCurSel(1); break;
	case RESOURCE_REMEMBERED: this->m_cboScope.SetCurSel(2); break;
	case RESOURCE_RECENT: this->m_cboScope.SetCurSel(3); break;
	case RESOURCE_CONTEXT: this->m_cboScope.SetCurSel(4); break;
	default: ;
	}

	switch (nr.dwType) {
	case RESOURCETYPE_ANY: this->m_cboResourceType.SetCurSel(0); break;
	case RESOURCETYPE_DISK: this->m_cboResourceType.SetCurSel(1); break;
	case RESOURCETYPE_PRINT: this->m_cboResourceType.SetCurSel(2); break;
	case RESOURCETYPE_RESERVED: this->m_cboResourceType.SetCurSel(3); break;
	case RESOURCETYPE_UNKNOWN: this->m_cboResourceType.SetCurSel(4); break;
	default: ;
	}

	switch (nr.dwUsage) {
	case RESOURCEUSAGE_CONNECTABLE: this->m_cboUsage.SetCurSel(0); break;
	case RESOURCEUSAGE_CONTAINER: this->m_cboUsage.SetCurSel(1); break;
	case RESOURCEUSAGE_NOLOCALDEVICE: this->m_cboUsage.SetCurSel(2); break;
	case RESOURCEUSAGE_SIBLING: this->m_cboUsage.SetCurSel(3); break;
	case RESOURCEUSAGE_ATTACHED: this->m_cboUsage.SetCurSel(4); break;
	case RESOURCEUSAGE_ALL: this->m_cboUsage.SetCurSel(5); break;
	case RESOURCEUSAGE_RESERVED: this->m_cboUsage.SetCurSel(6); break;
	default: ;
	}

	switch (nr.dwDisplayType) {
	case RESOURCEDISPLAYTYPE_GENERIC: this->m_cboDisplayType.SetCurSel(0); break;
	case RESOURCEDISPLAYTYPE_DOMAIN: this->m_cboDisplayType.SetCurSel(1); break;
	case RESOURCEDISPLAYTYPE_SERVER: this->m_cboDisplayType.SetCurSel(2); break;
	case RESOURCEDISPLAYTYPE_SHARE: this->m_cboDisplayType.SetCurSel(3); break;
	case RESOURCEDISPLAYTYPE_FILE: this->m_cboDisplayType.SetCurSel(4); break;
	case RESOURCEDISPLAYTYPE_GROUP: this->m_cboDisplayType.SetCurSel(5); break;
	case RESOURCEDISPLAYTYPE_NETWORK: this->m_cboDisplayType.SetCurSel(6); break;
	case RESOURCEDISPLAYTYPE_ROOT: this->m_cboDisplayType.SetCurSel(7); break;
	case RESOURCEDISPLAYTYPE_SHAREADMIN: this->m_cboDisplayType.SetCurSel(8); break;
	case RESOURCEDISPLAYTYPE_DIRECTORY: this->m_cboDisplayType.SetCurSel(9); break;
	case RESOURCEDISPLAYTYPE_TREE: this->m_cboDisplayType.SetCurSel(10); break;
	case RESOURCEDISPLAYTYPE_NDSCONTAINER: this->m_cboDisplayType.SetCurSel(11); break;
	default: ;
	}

	this->UpdateData(FALSE);
}

void CWNetAddDlg::OnButtonClose2()
{
	// TODO: Add your control notification handler code here

}

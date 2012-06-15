// ProcessView.cpp : implementation file
//

#include "stdafx.h"
#include "MDlgCtl01.h"
#include "ProcessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcessView dialog

static DWORD dwSelectPriority;

CProcessView::CProcessView(CWnd* pParent /*=NULL*/)
	: CDialog(CProcessView::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcessView)
	m_dwAddress = 0;
	m_dwValue = 0;
	m_nType = TYPE_DWORD;
	m_nSelectPriority = 0;
	//}}AFX_DATA_INIT
}


void CProcessView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcessView)
	DDX_Text(pDX, IDC_ADDRESS, m_dwAddress);
	DDX_Text(pDX, IDC_VALUE, m_dwValue);
	DDX_CBIndex(pDX, IDC_TYPE, m_nType);
	DDX_Slider(pDX, IDC_SLIDER_PRIORITY, m_nSelectPriority);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProcessView, CDialog)
	//{{AFX_MSG_MAP(CProcessView)
	ON_BN_CLICKED(IDC_READ, OnRead)
	ON_BN_CLICKED(IDC_WRITE, OnWrite)
	ON_BN_CLICKED(IDC_REFRESH, OnRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcessView message handlers

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam) {
	HWND hWndProcessList = (HWND)lParam;
	DWORD dwThreadId, dwProcessId;
	TCHAR TextBuffer[256];
	TCHAR szTitle[200];
	UINT Index;

	if (hWnd) {
		dwThreadId = GetWindowThreadProcessId(hWnd, &dwProcessId);
		GetWindowText(hWnd, (LPTSTR)szTitle, sizeof(szTitle));
		if (lstrlen(szTitle) > 0) {
			DWORD dwPriorityClass;
			HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, dwProcessId);
			dwPriorityClass = GetPriorityClass(hProcess);
			if (dwPriorityClass >= dwSelectPriority) {
				wsprintf(TextBuffer, "[%8X-%8X] %s", dwProcessId, dwThreadId, szTitle);
				Index = SendMessage(hWndProcessList, CB_ADDSTRING, 0, (LPARAM)TextBuffer);
				SendMessage(hWndProcessList, CB_SETITEMDATA, (WPARAM)Index, (LPARAM)dwProcessId);
			}
		}

	}
	return TRUE;
}

void CProcessView::OnRead()
{
	HWND hWndProcessList = GetDlgItem(IDC_PROCESS_LIST)->m_hWnd;
	UINT nIndex;
	DWORD dwProcessId;
	UpdateData(TRUE);
	if (hWndProcessList) {
		nIndex = ::SendMessage(hWndProcessList, CB_GETCURSEL, 0, 0);
		dwProcessId = ::SendMessage(hWndProcessList, CB_GETITEMDATA, (WPARAM)nIndex, 0);
		if (dwProcessId) {
			HANDLE hProcess = OpenProcess(PROCESS_VM_READ, FALSE, dwProcessId);
			ReadProcessMemory(hProcess, (LPCVOID)m_dwAddress, (LPVOID)&m_dwValue, 4, NULL);
			switch (m_nType) {
			case TYPE_BYTE: m_dwValue %= 0x100; break;
			case TYPE_WORD: m_dwValue %= 0x10000; break;
			}
			CloseHandle(hProcess);
			UpdateData(FALSE);
		}
	}
}

void CProcessView::OnWrite()
{
	// TODO: Add your control notification handler code here
	HWND hWndProcessList = GetDlgItem(IDC_PROCESS_LIST)->m_hWnd;
	UINT nIndex;
	DWORD dwProcessId;
	UpdateData(TRUE);
	if (hWndProcessList) {
		nIndex = ::SendMessage(hWndProcessList, CB_GETCURSEL, 0, 0);
		dwProcessId = ::SendMessage(hWndProcessList, CB_GETITEMDATA, (WPARAM)nIndex, 0);
		if (dwProcessId) {
			HANDLE hProcess = OpenProcess(PROCESS_VM_WRITE, FALSE, dwProcessId);
			switch (m_nType) {
			case TYPE_BYTE:
				WriteProcessMemory(hProcess, (LPVOID)m_dwAddress,
					(LPVOID)&m_dwValue, 1, NULL);
				break;
			case TYPE_WORD:
				WriteProcessMemory(hProcess, (LPVOID)m_dwAddress,
					(LPVOID)&m_dwValue, 2, NULL);
				break;
			case TYPE_DWORD:
				WriteProcessMemory(hProcess, (LPVOID)m_dwAddress,
					(LPVOID)&m_dwValue, 4, NULL);
				break;
			}
			CloseHandle(hProcess);
			UpdateData(FALSE);
		}
	}
}

void CProcessView::OnRefresh()
{
	HWND hWndProcessList = GetDlgItem(IDC_PROCESS_LIST)->m_hWnd;
	if (hWndProcessList) {
		UpdateData(TRUE);
		dwSelectPriority = (DWORD)m_nSelectPriority;
		::SendMessage(hWndProcessList, CB_RESETCONTENT, 0, 0);
		EnumWindows((WNDENUMPROC)EnumWindowsProc, (LPARAM)hWndProcessList);
	}
}

BOOL CProcessView::OnInitDialog()
{
	CSliderCtrl *sc;

	CDialog::OnInitDialog();

	sc = (CSliderCtrl *)GetDlgItem(IDC_SLIDER_PRIORITY);
	sc->SetRange(0, REALTIME_PRIORITY_CLASS, TRUE);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

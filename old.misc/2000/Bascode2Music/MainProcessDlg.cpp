// MainProcessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BasCodeToSimple.h"
#include "MainProcessDlg.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainProcessDlg dialog


CMainProcessDlg::CMainProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainProcessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainProcessDlg)
	m_DestName = _T("");
	m_SourceName = _T("");
	m_TransReport = _T("");
	m_chkSourceClip = FALSE;
	m_chkDestClip = FALSE;
	m_nBeats = 0;
	//}}AFX_DATA_INIT
}


void CMainProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainProcessDlg)
	DDX_Text(pDX, IDC_EDITDEST, m_DestName);
	DDV_MaxChars(pDX, m_DestName, 512);
	DDX_Text(pDX, IDC_EDITSOURCE, m_SourceName);
	DDV_MaxChars(pDX, m_SourceName, 512);
	DDX_Text(pDX, IDC_TRANS_REPORT, m_TransReport);
	DDV_MaxChars(pDX, m_TransReport, 32);
	DDX_Check(pDX, IDC_CHECK_SOURCE, m_chkSourceClip);
	DDX_Check(pDX, IDC_CHECK_DEST, m_chkDestClip);
	DDX_Text(pDX, IDC_EDIT_BEATS_NUM, m_nBeats);
	DDV_MinMaxInt(pDX, m_nBeats, 1, 4);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMainProcessDlg, CDialog)
	//{{AFX_MSG_MAP(CMainProcessDlg)
	ON_BN_CLICKED(IDC_BUTTONSOURCE, OnButtonSource)
	ON_BN_CLICKED(IDC_BUTTONDEST, OnButtonDest)
	ON_BN_CLICKED(IDC_BEGIN_TRAN, OnBeginTran)
	ON_BN_CLICKED(IDC_CHECK_SOURCE, OnCheckSource)
	ON_BN_CLICKED(IDC_CHECK_DEST, OnCheckDest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainProcessDlg message handlers

void CMainProcessDlg::OnButtonSource()
{
	// TODO: Add your control notification handler code here
	CFileDialog CBrowser(TRUE); // Show open file dialog
	if (CBrowser.DoModal() == IDOK) {
		m_SourceName = CBrowser.GetFileName();
		m_TransReport = "";
		this->UpdateData(FALSE);
	}
}

void CMainProcessDlg::OnButtonDest()
{
	// TODO: Add your control notification handler code here
	CFileDialog CBrowser(FALSE); // Show save file dialog
	if (CBrowser.DoModal() == IDOK) {
		m_DestName = CBrowser.GetFileName();
		m_TransReport = "";
		this->UpdateData(FALSE);
	}
}

void CMainProcessDlg::OnBeginTran()
{
	// TODO: Add your control notification handler code here
	if (this->UpdateData()) {
		if (Translate()) {
			m_TransReport = "ת���ɹ�!";
		} else {
			m_TransReport = "ת��ʧ��!";
		}
		this->UpdateData(FALSE);
	}
}

struct Note {
public:
	static int defo;	// ��ǰ����
	static int defl;	// ��ǰ����
	CHAR i;	// ����
	int o;	// ����
	int l;	// ����
	CHAR m1;	// ��ע ����1
	CHAR m2;	// ��ע ����2
	CHAR c1;	// ��ע ����1
	CHAR c2;	// ��ע ����2
	Note *n;
public:
	Note() { o = defo; l = defl; i = '0'; n = NULL; m1 = m2 = c1 = c2 = '\0'; }
};

int Note::defo = 0;
int Note::defl = 4;

struct Music {
	Note *line;
	int beats;	// ÿ���ڽ�����
	int btop;		// ����������
	int bbot;		// ����������
	struct Music *next;
	Music() { line = NULL; beats = 4; btop = bbot = 0; next = NULL; }
};

int CMainProcessDlg::Translate() {
	HLOCAL hSrc, hDest;
	LPSTR lpSrc, lpDest;
	CHAR c; // con: O ȱʡ���� L ȱʡ���� l ָ������
	UINT nRead, nCount = 0, nPoint = 0;
	CFile *fin, *fout;

	// ��������
	hSrc = LocalAlloc(LMEM_MOVEABLE, MUSIC_FILE_MAXSIZE);
	lpSrc = (LPSTR)LocalLock(hSrc);

	if (!m_chkSourceClip) {
		fin = new CFile(m_SourceName, CFile::modeRead);
		while (nCount < MUSIC_FILE_MAXSIZE) {
			nRead = fin->Read((LPVOID)(lpSrc + nCount), BLOCKSIZE);
			nCount += nRead;
			if (nRead != BLOCKSIZE) break;
		}
		fin->Close();
		delete fin;
	} else {
		//...
	}

	// ת������
	Note *line, *nFirst;
	nFirst = line = new Note;
	while (nPoint < nCount) {
		c = tolower(lpSrc[nPoint++]);
		if (isspace(c)) continue;
		switch (c) {
		case 'o':
			Note::defo = GetNum(lpSrc + nPoint, 3) - 3; break;
		case 'l':
			Note::defl = GetNum(lpSrc + nPoint, 4); break;
		case '>':
			Note::defo++; break;
		case '<':
			Note::defo--; break;
		case '.':
			line->l += line->l >> 1;	// line->l *= 1.5;
			break;
		default:
			if (c >= 'a' && c <= 'g') {
				line = line->n = new Note;
				line->i = c > 'b' ? c - 'c' + '1' : c - 'a' + '6';
				line->l = GetNum(lpSrc + nPoint, Note::defl);
			}
			if (c == 'p' || c == 'r') {	// ��ֹ��
				line = line->n = new Note;
				line->i = '0';
				line->o = 0;
				line->l = GetNum(lpSrc + nPoint, Note::defl);
			}
			break;
		}
	}

	// ���׽��������ʼ��
	// nFirst = nFirst->n;		// ��ȥ���ý��

	LocalUnlock(hSrc);
	LocalFree(hSrc);

	// ��ʽ����

	// 1. ���ɷ���
	float fullbeat;			// ������ʣ������
	float delaybeat = 0;	// ��һ������������
	float cbeat;			// ��ǰ����ռ������
	Note *addn;
	nFirst->i = '|';

	line = nFirst->n;
	while (line != NULL) {
		if (delaybeat < m_nBeats) {
			// �κ�һ������֮��delaybeat(����0)��������, �������������!
			fullbeat = m_nBeats - delaybeat;	// ������ʣ�������ȥ������������������
			delaybeat = 0;
			for (; fullbeat > 0 && line != NULL;) {
				cbeat = TakeBeat(line->l);
				if (cbeat <= fullbeat) {	// �ڱ�������
					//{ ... } // ����������
					fullbeat -= cbeat;
					if (fullbeat > 0 && line->n != NULL) line = line->n;
					else break;
				} else {					// ����������һ����
					line->l = Takel(fullbeat);
					delaybeat = cbeat - fullbeat;
					fullbeat = 0;
				}
			}
			if (fullbeat > 0) {	// ��ĩ����
				addn = new Note;
				addn->i = '0';
				addn->l = Takel(fullbeat);
				fullbeat = 0;
				addn->n = line->n;
				line = line->n = addn;
			}
		} else {
			delaybeat -= m_nBeats;
		}
		// һ�����ڽ���, ���ɽڷ�
		addn = new Note;
		addn->i = '|';
		// �޸�����
		addn->n = line->n;
		line->n = addn;
		if (delaybeat > 0) {		// ����������������  \__/
			line->c1 = (line->c1 == '/') ? '_' : '\\';
			addn->c1 = '_';
			Note *addi = new Note;
			addi->i = line->i;
			addi->c1 = '/';
			// ��������
			addi->n = addn->n;
			addn->n = addi;
			line->n = addn;
			// ָ����һ����������
			line = addi;
			if (delaybeat < m_nBeats) {
				line->l = Takel(delaybeat); // ����һ��������, �������
				// ָ����һ����������ʼ
				line = line->n;
			} else {
				line->l = Takel(m_nBeats);
			}
		} else {
			// ָ����һ����������ʼ
			line = addn->n;
		}
	}
	line = nFirst->n;

	// 2. ���ɶ���
	int scount = 0;			// ���ڼ���
	Music *m = new Music, *mFirst = m, *addm;
	m->line = line;
	// 2.1 �ֶ�
	while (line != NULL && line->n != NULL) {
		if (line->i == '|') scount++;
		if (scount >= 5) {
			addm = new Music;
			addm->line = line->n;
			line->n = NULL;
			line = addm->line;
			m->next = addm;
			m = m->next;
			scount = 0;
		}
		line = line->n;
	}
	// 2.2 ���δ���, ����������
	int omax = 0;		// �������
	int omin = 0;		// �������
	int lmax = 0;		// ������ʵ����� (l4 = 0, l8 = 2, l16 = 3, ...)
	int tmax = 0;		// ��߶���ע
	int tmin = 0;		// ��͵ױ�ע
	m = mFirst;
	while (m != NULL) {
		line = m->line;
		while (line != NULL) {
			if (line->m1 != '\0' && tmin < 1) tmin = 1;
			if (line->m2 != '\0' && tmin < 2) tmin = 2;
			if (line->c1 != '\0' && tmax < 1) tmax = 1;
			if (line->c2 != '\0' && tmax < 2) tmax = 2;
			if (line->o < omin) omin = line->o;
			if (line->o > omax) omax = line->o;
			if (line->l > lmax) lmax = line->l;
			line = line->n;
		}
		lmax = (int)(log((double)lmax) / log(2)) - 2;
		m->btop = tmin + omax;
		m->bbot = tmax - omin;		// omin < 0
		m->bbot += lmax;
		m = m->next;
	}

	// ���ɼ�����
	hDest = LocalAlloc(LMEM_MOVEABLE, MUSIC_FILE_MAXSIZE * 5);
	lpDest = (LPSTR)LocalLock(hDest);
	nPoint = 0;

	m = mFirst;
	while (m != NULL) {
		// ���ɸ�������
		int mbegin = 0, cbegin = 0;		// ��ע��ʼ��
		int t;
		BOOL ddelay = FALSE;
		for (int si = m->btop; si >= -(m->bbot); si--) {
			line = m->line;
			while (line != NULL) {
				lpDest[nPoint] = ' ';
				if (si > 0) {	// ��ÿ�л����Ϸ��������
					t = line->o;
					if ((t + 1) / 2 >= si) lpDest[nPoint] = (2 * si > t) ? '.' : ':';
					if (si == (t + 1) / 2 + 1 && line->m1 != '\0') lpDest[nPoint] = line->m1;
					if (si == (t + 1) / 2 + 2 && line->m2 != '\0') lpDest[nPoint] = line->m2;
				}
				if (si == 0) {	// ����������������ֽڷ�
					lpDest[nPoint] = line->i;
				}
				if (si < 0) {
					t = -si;
					int tl = (TakeLines(line->l) + 1) / 2;
					if (tl >= t) lpDest[nPoint] = (2 * t > TakeLines(line->l)) ? '-' : '=';
					if (t > tl) {
						if (line->o < 0) { // �����׷����»�������
							int o = -line->o;
							if (tl + (o + 1) / 2 >= t) {
								lpDest[nPoint] = (2 * (t - tl) > o) ? '.' : ':';
							}
							tl += (o + 1) / 2;
						}
						if (t == tl + 1 && line->c1 != '\0') {
							lpDest[nPoint] = line->c1;
							if (line->c1 == '\\' || line->c1 == '_') ddelay = TRUE;
						}
						if (t == tl + 1 && line->c2 != '\0') lpDest[nPoint] = line->c2;
					}
				}
				nPoint++;
				if (line->l < 4) {
					for (t = line->l; t < 3; t++) {
						lpDest[nPoint] = ' ';
						if (si == 0) lpDest[nPoint] = '-';
						if (ddelay) lpDest[nPoint] = '_';
						nPoint++;
					}
					ddelay = FALSE;
				}
				line = line->n;
			} // while (line != NULL)
			lpDest[nPoint++] = '\r';
			lpDest[nPoint++] = '\n';
		} // for si
		lstrcpy((LPSTR)(lpDest + nPoint), SECSEPARATOR);
		nPoint += lstrlen(SECSEPARATOR); // lpDest[nPoint] == '\0'

		m = m->next;
	}
	lpDest[nPoint] = '\0';

	// �������
	m = mFirst;
	while (m != NULL) {
		line = m->line;
		while (line != NULL) {
			line = line->n;
			delete m->line;
			m->line = line;
		}
		m = m->next;
		delete mFirst;
		mFirst = m;
	}

	// ������ļ�
	if (!m_chkDestClip) {
		int Length = lstrlen(lpDest) + 1;
		fout = new CFile(m_DestName, CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		fout->Write(MUSIC_FILE_HEADER, lstrlen(MUSIC_FILE_HEADER));
		for (nCount = 0;;) {
			if (Length - nCount >= BLOCKSIZE) {
				fout->Write((LPVOID)(lpDest + nCount), BLOCKSIZE);
				nCount += BLOCKSIZE;
			} else {
				fout->Write((LPVOID)(lpDest + nCount), Length - nCount);
				break;
			}
		}
		fout->Write(MUSIC_FILE_FOOTER, lstrlen(MUSIC_FILE_FOOTER));
		fout->Write(MUSIC_FILE_MARKER, lstrlen(MUSIC_FILE_MARKER));
		fout->Close();
		delete fout;
	} else {
		//...
	}

	LocalUnlock(hDest);
	LocalFree(hDest);
	return TRUE;
}

int GetNum(LPSTR s, int Default) {
	CHAR buf[64];
	int p = 0;

	while (s[p] >= '0' && s[p] <= '9') {
		buf[p] = s[p++];
	}
	buf[p] = '\0';

	if (p == 0) return Default;
	return (int)atol(buf);
}

int TakeLines(int l) {
	int r = (int)(log((double)l) / log(2)) - 2;
	return r <= 0 ? 0 : r;
}

inline float TakeBeat(int l) {
	if (l < 4) return float(5 - l);
	return 4 / (float)l;
}

inline int Takel(float beat) {
	if (beat > 1) return (int)(5 - beat);
	return (int)(4 / beat);
}

void CMainProcessDlg::OnCheckSource()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDITSOURCE)->EnableWindow(!m_chkSourceClip);
	UpdateData();
}

void CMainProcessDlg::OnCheckDest()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDITDEST)->EnableWindow(!m_chkDestClip);
	UpdateData();
}

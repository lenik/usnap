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
			m_TransReport = "转换成功!";
		} else {
			m_TransReport = "转换失败!";
		}
		this->UpdateData(FALSE);
	}
}

struct Note {
public:
	static int defo;	// 当前音阶
	static int defl;	// 当前速率
	CHAR i;	// 音名
	int o;	// 音阶
	int l;	// 速率
	CHAR m1;	// 备注 顶行1
	CHAR m2;	// 备注 顶行2
	CHAR c1;	// 备注 底行1
	CHAR c2;	// 备注 底行2
	Note *n;
public:
	Note() { o = defo; l = defl; i = '0'; n = NULL; m1 = m2 = c1 = c2 = '\0'; }
};

int Note::defo = 0;
int Note::defl = 4;

struct Music {
	Note *line;
	int beats;	// 每音节节拍数
	int btop;		// 留出顶行数
	int bbot;		// 留出底行数
	struct Music *next;
	Music() { line = NULL; beats = 4; btop = bbot = 0; next = NULL; }
};

int CMainProcessDlg::Translate() {
	HLOCAL hSrc, hDest;
	LPSTR lpSrc, lpDest;
	CHAR c; // con: O 缺省音阶 L 缺省速率 l 指定速率
	UINT nRead, nCount = 0, nPoint = 0;
	CFile *fin, *fout;

	// 读入数据
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

	// 转化数据
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
			if (c == 'p' || c == 'r') {	// 休止符
				line = line->n = new Note;
				line->i = '0';
				line->o = 0;
				line->l = GetNum(lpSrc + nPoint, Note::defl);
			}
			break;
		}
	}

	// 将首结点用于起始符
	// nFirst = nFirst->n;		// 弃去无用结点

	LocalUnlock(hSrc);
	LocalFree(hSrc);

	// 格式处理

	// 1. 生成符号
	float fullbeat;			// 本音节剩余拍数
	float delaybeat = 0;	// 上一音节延续拍数
	float cbeat;			// 当前音符占用拍数
	Note *addn;
	nFirst->i = '|';

	line = nFirst->n;
	while (line != NULL) {
		if (delaybeat < m_nBeats) {
			// 任何一个音节之内delaybeat(包括0)都将到这, 且延续处理完毕!
			fullbeat = m_nBeats - delaybeat;	// 本音节剩余节拍数去掉上音节延续节拍数
			delaybeat = 0;
			for (; fullbeat > 0 && line != NULL;) {
				cbeat = TakeBeat(line->l);
				if (cbeat <= fullbeat) {	// 在本音节内
					//{ ... } // 非整数处理
					fullbeat -= cbeat;
					if (fullbeat > 0 && line->n != NULL) line = line->n;
					else break;
				} else {					// 有延续至下一音节
					line->l = Takel(fullbeat);
					delaybeat = cbeat - fullbeat;
					fullbeat = 0;
				}
			}
			if (fullbeat > 0) {	// 最末音节
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
		// 一个音节结束, 生成节符
		addn = new Note;
		addn->i = '|';
		// 修改链表
		addn->n = line->n;
		line->n = addn;
		if (delaybeat > 0) {		// 有延续加上延音符  \__/
			line->c1 = (line->c1 == '/') ? '_' : '\\';
			addn->c1 = '_';
			Note *addi = new Note;
			addi->i = line->i;
			addi->c1 = '/';
			// 插入链表
			addi->n = addn->n;
			addn->n = addi;
			line->n = addn;
			// 指向下一个延续音符
			line = addi;
			if (delaybeat < m_nBeats) {
				line->l = Takel(delaybeat); // 延续一个音节内, 处理完毕
				// 指向下一个新音符开始
				line = line->n;
			} else {
				line->l = Takel(m_nBeats);
			}
		} else {
			// 指向下一个新音符开始
			line = addn->n;
		}
	}
	line = nFirst->n;

	// 2. 生成段落
	int scount = 0;			// 音节计数
	Music *m = new Music, *mFirst = m, *addm;
	m->line = line;
	// 2.1 分段
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
	// 2.2 各段处理, 生成留空数
	int omax = 0;		// 最高音阶
	int omin = 0;		// 最低音阶
	int lmax = 0;		// 最快速率底线数 (l4 = 0, l8 = 2, l16 = 3, ...)
	int tmax = 0;		// 最高顶备注
	int tmin = 0;		// 最低底备注
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

	// 生成简唱数据
	hDest = LocalAlloc(LMEM_MOVEABLE, MUSIC_FILE_MAXSIZE * 5);
	lpDest = (LPSTR)LocalLock(hDest);
	nPoint = 0;

	m = mFirst;
	while (m != NULL) {
		// 生成各段数据
		int mbegin = 0, cbegin = 0;		// 备注起始点
		int t;
		BOOL ddelay = FALSE;
		for (int si = m->btop; si >= -(m->bbot); si--) {
			line = m->line;
			while (line != NULL) {
				lpDest[nPoint] = ' ';
				if (si > 0) {	// 在每行基线上方输出音阶
					t = line->o;
					if ((t + 1) / 2 >= si) lpDest[nPoint] = (2 * si > t) ? '.' : ':';
					if (si == (t + 1) / 2 + 1 && line->m1 != '\0') lpDest[nPoint] = line->m1;
					if (si == (t + 1) / 2 + 2 && line->m2 != '\0') lpDest[nPoint] = line->m2;
				}
				if (si == 0) {	// 基线上输出音名及分节符
					lpDest[nPoint] = line->i;
				}
				if (si < 0) {
					t = -si;
					int tl = (TakeLines(line->l) + 1) / 2;
					if (tl >= t) lpDest[nPoint] = (2 * t > TakeLines(line->l)) ? '-' : '=';
					if (t > tl) {
						if (line->o < 0) { // 低音阶放在下划线下面
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

	// 清除链表
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

	// 输出至文件
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

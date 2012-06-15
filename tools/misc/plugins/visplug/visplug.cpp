// visplug.cpp : Defines the initialization routines for the DLL.
//
//======================================================
//	HeroMp3 vis plug demo v1.0
//  copyright(c) 1999 Herosoft Inc. All rights reserved.
//======================================================

/* ˵����
����һ��HeroMp3 vis plug ʾ���������Ǽ�����Ҫ�ļ�:
WaveWin.h      ���δ�����
WaveWin.cpp    ���δ�����
SpecWin.h      Ƶ�״�����
SpecWin.cpp    Ƶ�״�����
visplug.h      DLL
visplug.cpp    DLL

��ʾ:
1.�Ƚ�һ��������(��CWnd�̳�),����winamp�Ĳ��,���ﴰ��Ӧ���ѿ�һ����ʱ����
  ��ʱͨ��GetVisData()��������ȡ��������ʾ(�μ�CWaveWin::OnTimer)��
2.д�������������:
	vis_start ��������������ｨ�����ڡ��������ڵ����������ǰ������visModule�ṹ������Ӧ������(��HeroMp3Win,hDllInstance��)��
	vis_end   ����رգ�������رմ��ڡ����ִ���������ʱ���в�������Ѿ����û��رգ�Ӧ����FALSE;
	vis_config ������ز��������û���"����"��ťʱ��������������������
	vis_about  ��ʾ������Ϣ�����û���"����"��ťʱ��������������������
	vis_OnHeroMp3WinMoveSize �������򴰿��ƶ���ı��С��������������������
3.����һ��HeroMp3VisModuleʵ��(visModule),����������ݡ�������ͨ������ṹ��������һ����Ϣ��
  ÿ�β������GetVisData()ʱ����������������������spectrumData��waveformData���顣
4.�����������HeroMp3_GetVisModule(),ע�⻹Ҫ��visplug.def�ļ���������
5.���DLL����VC++6.0�У�ѡFile->New,�����Ի���ѡProjectsҳ,ѡMFC AppWizard(dll)���ɿ�ܡ�
(���кõ��뷨����ӭ����̽��ָ����email:aaqiang@263.net)
*/

#include "stdafx.h"
#include "visplug.h"
#include "HeroMp3Vis.h"

#include "specwin.h"
#include "wavewin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//
/////////////////////////////////////////////////////////////////////////////


extern HeroMp3VisModule visModule;

CSpecWin* win=NULL;
CWaveWin* win1=NULL;

// CVisplugApp

BEGIN_MESSAGE_MAP(CVisplugApp, CWinApp)
	//{{AFX_MSG_MAP(CVisplugApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVisplugApp construction

CVisplugApp::CVisplugApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


BOOL CVisplugApp::InitInstance()
{
	// TODO: Add your specialized code here and/or call the base class
	win=new CSpecWin;
	win1=new CWaveWin;
	m_pMainWnd=win;
	return CWinApp::InitInstance();
}


/////////////////////////////////////////////////////////////////////////////
// The one and only CVisplugApp object

CVisplugApp theApp;

CString GetIniFilePath()
{
	char filename[MAX_PATH];
	GetModuleFileName(AfxGetInstanceHandle(),filename,MAX_PATH);
	CString s;
	s=filename;
	s=s.Mid(0,s.ReverseFind('\\')+1);
	return s;
}

BOOL APIENTRY vis_start()
{
	win->ReadIni(GetIniFilePath()+VISINI_FILENAME);
	win1->ReadIni(GetIniFilePath()+VISINI_FILENAME);
	if (!win->Create("vis plug demo v1.0",NULL))
		return FALSE;
	if (!win1->Create("vis plug demo v1.0",NULL))
		return FALSE;


	win->ShowWindow(SW_NORMAL);
	win->UpdateWindow();
	win1->ShowWindow(SW_NORMAL);
	win1->UpdateWindow();

	return TRUE;
}

BOOL APIENTRY vis_end()
{
	win->WriteIni(GetIniFilePath()+VISINI_FILENAME);
	win1->WriteIni(GetIniFilePath()+VISINI_FILENAME);
	if (win->IsClosed() && win1->IsClosed())
		return FALSE;

	::SendMessage(win->GetSafeHwnd(),WM_CLOSE,0,0);
	::SendMessage(win1->GetSafeHwnd(),WM_CLOSE,0,0);

	return TRUE;
}

BOOL APIENTRY vis_config()
{
	AfxMessageBox("��������...");
	return TRUE;
}

BOOL APIENTRY vis_about()
{
	AfxMessageBox("����һ��VIS���ʾ��");
	return TRUE;
}

void APIENTRY vis_OnHeroMp3WinMoveSize()
{
	//when main app window move or size, call this funciton.
}


HeroMp3VisModule visModule =
{
  sizeof(HeroMp3VisModule),       // this struct size,filled in use sizeof(HeroMp3VisModule)
  "Vis Plug Demo 1.0", // vis plug description
  NULL, 	//  HeroMp3 main window's handle
  NULL,     // instance handle to this DLL
  0,		 // sample rate (filled in by calling app)
  0,			 // number of channels (filled by calling app)
  20,     // latency from call of GetVisData() to actual drawing
  2,         //spectrumNch
  2,         // waveformNch
  {0,},      // spectrumData[2][DATA_SIZE];
  {0,},      // waveformData[2][DATA_SIZE];
  NULL,      // GetVisData //filled by calling app
  vis_start,  // VisStart;
  vis_end,    // VisEnd;
  vis_config, // VisConfig;
  vis_about,  // VisAbout;
  vis_OnHeroMp3WinMoveSize,
  VISCAPS_WINDOW, //visCaps,
				 //assume your visplug is work on full screen,direct draw, you must set VISCAPS_FULLSCREEN|VISCAPS_DIRECTDRAW
  NULL       //  userData
};

HeroMp3VisModule* APIENTRY HeroMp3_GetVisModule() // dll output function
{
	return &visModule;
}

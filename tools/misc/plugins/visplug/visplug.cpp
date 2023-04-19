// visplug.cpp : Defines the initialization routines for the DLL.
//
//======================================================
//	HeroMp3 vis plug demo v1.0
//  copyright(c) 1999 Herosoft Inc. All rights reserved.
//======================================================

/* 说明：
这是一个HeroMp3 vis plug 示例，以下是几个主要文件:
WaveWin.h      波形窗口类
WaveWin.cpp    波形窗口类
SpecWin.h      频谱窗口类
SpecWin.cpp    频谱窗口类
visplug.h      DLL
visplug.cpp    DLL

提示:
1.先建一个窗口类(从CWnd继承),不象winamp的插件,这里窗口应自已开一个定时器，
  定时通过GetVisData()从主程序取得数据显示(参见CWaveWin::OnTimer)。
2.写好如下五个函数:
	vis_start 插件启动，在这里建立窗口。主程序在调用这个函数前，会在visModule结构中填入应填数据(如HeroMp3Win,hDllInstance等)。
	vis_end   插件关闭，在这里关闭窗口。如果执行这个函数时所有插件窗口已经被用户关闭，应返回FALSE;
	vis_config 设置相关参数，当用户按"配置"按钮时，主程序调用这个函数。
	vis_about  显示关于信息，当用户按"关于"按钮时，主程序调用这个函数。
	vis_OnHeroMp3WinMoveSize 当主程序窗口移动或改变大小，主程序调用这个函数。
3.定义一个HeroMp3VisModule实例(visModule),填入相关数据。主程序通过这个结构与插件交换一切信息。
  每次插件调用GetVisData()时，主程序会把最新数据填入spectrumData和waveformData数组。
4.定义输出函数HeroMp3_GetVisModule(),注意还要在visplug.def文件中声明。
5.这个DLL可在VC++6.0中，选File->New,弹出对话框选Projects页,选MFC AppWizard(dll)生成框架。
(如有好的想法，欢迎来信探讨指正。email:aaqiang@263.net)
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
	AfxMessageBox("进行设置...");
	return TRUE;
}

BOOL APIENTRY vis_about()
{
	AfxMessageBox("这是一个VIS插件示例");
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

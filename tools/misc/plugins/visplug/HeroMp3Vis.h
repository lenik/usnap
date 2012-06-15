//=============================================================
// HeroMp3Vis.h -- HeroMp3 vis plug API header file(v0.01-test)
//=============================================================

//-----------------------------------------------------
// 这是测试版的vis插件接口，如发现有不对或需改进的地方，
// 请赐教！ email:aaqiang@263.net
//-----------------------------------------------------


#ifndef HEROMP3VIS_H
#define HEROMP3VIS_H

#pragma pack(push,4)


//****************************************************************************
//* VISPLUG CAPABILITY FLAGS
//****************************************************************************

// This bit is reserved. It should not be specified.
#define VISCAPS_RESERVED1                       0x00000001l

//can work on full screen mode
#define VISCAPS_FULLSCREEN                      0x00000002l

//can work on window mode
#define VISCAPS_WINDOW                          0x00000004l

//use DirectDraw
#define VISCAPS_DIRECTDRAW                      0x00000008l

//use Direct3D
#define VISCAPS_DIRECT3D                        0x00000010l

//use OpenGL
#define VISCAPS_OPENGL                          0x00000020l






#define DATA_SIZE 576

typedef struct HeroMp3VisModule {
  DWORD dwSize;       // this struct size,filled in use sizeof(HeroMp3VisModule)
  LPCSTR description; // vis plug description
  HWND HeroMp3Win;	//  HeroMp3 main window's handle (filled in by calling app)
  HINSTANCE hDllInstance; // instance handle to this DLL (filled in by calling app)
  int sRate;		 // sample rate (filled in by calling app)
  int nCh;			 // number of channels (filled in by calling app)
  int latencyMs;     // latency from call of GetVisData() to actual drawing
					 // (calling app looks at this value when getting data)
  // the data is filled in according to the respective Nch entry
  int spectrumNch;
  int waveformNch;
  unsigned char spectrumData[2][DATA_SIZE];
  unsigned char waveformData[2][DATA_SIZE];
  BOOL (APIENTRY *GetVisData)(); //filled by calling app
  BOOL (APIENTRY *VisStart)();
  BOOL (APIENTRY *VisEnd)();
  BOOL (APIENTRY *VisConfig)();
  BOOL (APIENTRY *VisAbout)();
  void (APIENTRY *OnHeroMp3WinMoveSize)();
  DWORD visCaps; //capabilities of visplug wanted
  void *userData;   //user data, optional
} HeroMp3VisModule;

typedef BOOL (APIENTRY *GetVisDataType)();
typedef BOOL (APIENTRY *VisStartType)();
typedef BOOL (APIENTRY *VisConfigType)();
typedef BOOL (APIENTRY *VisAboutType)();
typedef BOOL (APIENTRY *VisEndType)();
typedef void (APIENTRY *OnHeroMp3WinMoveSizeType)();

typedef HeroMp3VisModule* (APIENTRY *HeroMp3_GetVisModuleType)();


#define VISINI_FILENAME "visplug.ini"


#pragma pack(pop)

#endif

// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DLLE1_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DLLE1_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLLE1_EXPORTS
#define DLLE1_API __declspec(dllexport)
#else
#define DLLE1_API __declspec(dllimport)
#endif

// This class is exported from the dlle1.dll
class DLLE1_API CDlle1 {
public:
	CDlle1(void);
	// TODO: add your methods here.
};

extern DLLE1_API int nDlle1;

DLLE1_API int fnDlle1(void);
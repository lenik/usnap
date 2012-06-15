
// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the INCALC_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// INCALC_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef INCALC_EXPORTS
#define INCALC_API __declspec(dllexport)
#else
#define INCALC_API __declspec(dllimport)
#endif

// This class is exported from the incalc.dll
class INCALC_API CIncalc {
public:
	CIncalc(void);
	// TODO: add your methods here.
};

extern INCALC_API int nIncalc;

INCALC_API int fnIncalc(void);

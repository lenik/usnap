
// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DLL_WITHMEM_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DLL_WITHMEM_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLL_WITHMEM_EXPORTS
#define DLL_WITHMEM_API __declspec(dllexport)
#else
#define DLL_WITHMEM_API __declspec(dllimport)
#endif

// This class is exported from the DLL_withmem.dll
class DLL_WITHMEM_API CDLL_withmem {
public:
	CDLL_withmem(void);
	// TODO: add your methods here.
	virtual void m_F1() = 0;
};

extern DLL_WITHMEM_API int nDLL_withmem;

DLL_WITHMEM_API int fnDLL_withmem(void);
DLL_WITHMEM_API	CDLL_withmem *fnDLL_getobject(void);


CDLL_withmem *	_stdcall fn_getobject();

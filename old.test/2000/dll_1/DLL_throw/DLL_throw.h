
// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DLL_THROW_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DLL_THROW_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLL_THROW_EXPORTS
#define DLL_THROW_API __declspec(dllexport)
#else
#define DLL_THROW_API __declspec(dllimport)
#endif

// This class is exported from the DLL_throw.dll
class DLL_THROW_API CDLL_throw {
public:
	CDLL_throw(void);
	// TODO: add your methods here.
};

class DLL_THROW_API CDLL_throw_exception {
public:
	CDLL_throw_exception(char *desc);
public:
	char *description;
	void msg();
};

DLL_THROW_API int fnDLL_throw(void) throw(CDLL_throw_exception);

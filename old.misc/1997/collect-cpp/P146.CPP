
#include "IFace.h"
#include "Registry.h"

void trace(LPCTSTR msg) { cout << "Component1: \t" << msg << endl; }

static HMODULE g_hModule		= NULL;
static ULONG g_cComponents		= 0;
static ULONG g_cServerLocks		= 0;

const char g_szFriendlyName[]		= "Inside COM, Chapter 8 Example 2, Component 1";
const char g_szVerIndProgID[]		= "InsideCOM.Chap08.Ex2.Cmpnt1";
const char g_szProgID[]			= "InsideCOM.Chap08.Ex2.Cmpnt1.1";

class CA : public IX {
public:
	virtual HRESULT _stdcall QueryInterface(REFIID riid, LPVOID *ppv);
	virtual ULONG _stdcall AddRef();
	virtual ULONG _stdcall Release();

	virtual void _stdcall Fx() { cout << "Fx" << endl; }
	virtual void _stdcall Fy() { m_pIY->Fy(); }

	CA();
	~CA();

	HRESULT _stdcall Init();

private:
	long m_cRef;

	// Pointer to the aggregated components' IY interface
	// (We do not have to retain an IY pointer, However, we
	// can use it in QueryInteface. )
	IY *m_pIY;

	IUnknown *m_pUnknownInner;
};

CA::CA() : m_cRef(1), m_pUnknownInner(NULL) {
	InterlockedIncrement(&g_cComponents);
}

CA::~CA() {
	InterlockedDecrement(&g_cComponents);
	trace("Destroy self. ");

	m_cRef = 1;

	IUnknown *pUnknownOuter = this;
	pUnknownOuter->AddRef();

	m_pIY->Release();

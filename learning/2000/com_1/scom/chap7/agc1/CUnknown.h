
#ifndef __CUNKNOWN_H

#define __CUNKNOWN_H

#include <objbase.h>

//////////////////////////////////////////////
//
// Nondelegating IUnknown interface
//    - Nondelegating version of IUnknown
//

interface INondelegatingUnknown {
	virtual HRESULT _stdcall NondelegatingQueryInterface(REFIID riid, LPVOID *ppv);
	virtual ULONG _stdcall NondelegatingAddRef();
	virtual ULONG _stdcall NondelegatingRelease();
};

class CUnknown : public INondelegatingUnknown {
public:
	virtual HRESULT _stdcall NondelegatingQueryInterface(REFIID riid, LPVOID *ppv);
	virtual ULONG _stdcall NondelegatingAddRef();
	virtual ULONG _stdcall NondelegatingRelease();

	CUnknown(IUnknown *pUnknownOuter);
	virtual ~CUnknown();

	virtual HRESULT Init() { return S_OK; }

	// Notification to derived classes that we are releasing
	virtual void FinalRelease();

	// Count of currently ctive components
	static long ActiveComponents() { return s_cActiveComponents; }

	HRESULT FinishQI(IUnknown *pI, LPVOID *ppv);

protected:
	IUnknown *GetOuterUnknown() const { return m_pUnknownOuter; }

private:
	long m_cRef;

	IUnknown *m_pUnknownOuter;

	static long s_cActiveComponents;
};

#define DECLARE_IUNKNOWN														\
	virtual HRESULT _stdcall QueryInterface(REFIID riid, LPVOID *ppv) {			\
		return GetOuterUnknown()->QueryInterface(riid, ppv);					\
	}																			\
	virtual ULONG _stdcall AddRef() { return GetOuterUnknown()->AddRef(); }		\
	virtual ULONG _stdcall Release() { return GetOuterUnknown()->Release(); }

#endif // __CUNKNOWN_H
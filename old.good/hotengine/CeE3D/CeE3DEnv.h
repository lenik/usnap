
#pragma once

class CeE3DEnv :
	public CComObjectRoot,
	public CComCoClass<CeE3DEnv, &CLSID_CeE3DEnv>,
	public IDispatchImpl<ICeE3DEnv, &IID_ICeE3DEnv> {
public:
	CeE3DEnv();
	virtual ~CeE3DEnv();

public:
	STDMETHOD(StartLighting)(BOOL *ret);
	STDMETHOD(EndLighting)(BOOL *ret);
	STDMETHOD(EnableLight)(GLint whichlight, BOOL *ret);
	STDMETHOD(DisableLight)(GLint whichLight, BOOL *ret);
	STDMETHOD(SetAmbientModelfv)(GLfloat *params, BOOL *ret);
	STDMETHOD(SetLocalViewerModel)(BOOL enable, BOOL *ret);
	STDMETHOD(SetTwoSideModel)(BOOL enable, BOOL *ret);
	STDMETHOD(SetLightAmbientf)(GLint whichlight, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, BOOL *ret);
	STDMETHOD(SetLightDiffusef)(GLint whichlight, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, BOOL *ret);
	STDMETHOD(SetLightSpecularf)(GLint whichlight, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha, BOOL *ret);
	STDMETHOD(SetLightPositionf)(GLint whichlight, GLfloat x, GLfloat y, GLfloat z, GLfloat w, BOOL *ret);
	STDMETHOD(SetLightSpotDirectionf)(GLint whichlight, GLfloat x, GLfloat y, GLfloat z, BOOL *ret);
	STDMETHOD(SetLightSpotExponentf)(GLint whichlight, GLfloat exponent, BOOL *ret);
	STDMETHOD(SetLightSpotCutofff)(GLint whichlight, GLfloat cutoff, BOOL *ret);
	STDMETHOD(SetLightAttenuationf)(GLint whichlight, GLfloat quadratic, GLfloat linear, GLfloat constant, BOOL *ret);
	STDMETHOD(SetLightConstantAttenuationf)(GLint whichlight, GLfloat attenuation, BOOL *ret);
	STDMETHOD(SetLightLinearAttenuationf)(GLint whichlight, GLfloat attenuation, BOOL *ret);
	STDMETHOD(SetLightQuadraticAttenuationf)(GLint whichlight, GLfloat attenuation, BOOL *ret);

	BEGIN_COM_MAP(CeE3DEnv)
		COM_INTERFACE_ENTRY2(IDispatch, ICeE3DEnv)
		COM_INTERFACE_ENTRY(ICeE3DEnv)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_CeE3DEnv)
	DECALRE_NOT_AGGREGATABLE(CeE3DEnv);

protected:
	BOOL	m_bLightingEnabled;
	BOOL	m_bLightEnabled[32];
};

typedef CeE3DEnv	*PCEE3DENV, *LPCEE3DENV;

// DiskAddress.h : Declaration of the CDiskAddress

#ifndef __DISKADDRESS_H_
#define __DISKADDRESS_H_

#include "resource.h"       // main symbols

#define InRange(v, a, b)        ((v) >= (a) && (v) <= (b))

/////////////////////////////////////////////////////////////////////////////
// CDiskAddress
class ATL_NO_VTABLE CDiskAddress :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDiskAddress, &CLSID_DiskAddress>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CDiskAddress>,
	public IDispatchImpl<IDiskAddress, &IID_IDiskAddress, &LIBID_HDR_KernelsLib>
{
public:
	CDiskAddress()
	{
        m_Mode = amLBA;
        memset(&m_Addr, 0, sizeof(m_Addr));
	}

protected:
    enum AddressModeConstants m_Mode;

    long    m_nCylinders;
    short   m_nHeads;
    short   m_nSectors;

    union Address {
        struct _CHS {
            int Cylinder;
            short Head;
            short Sector;
            short Offset;
            inline bool IsValid() const {
                return InRange(Offset, 0, 511) && InRange(Sector, 1, 63);
            }
        } CHS;
        struct _LBA {
            DWORD Index;
            short Offset;
            inline bool IsValid() const {
                return Index > 0 && InRange(Offset, 0, 511);
            }
        } LBA;
        struct _Linear {
            DWORD Low;
            LONG High;
            inline bool IsValid() const {
                return true;
            }
        } Linear;
    };

    union Address   m_Addr;

    bool _IsValid() const {
        switch (m_Mode) {
        case amLBA:
            return m_Addr.LBA.IsValid();
        case amCHS:
            return m_Addr.CHS.IsValid() &&
                InRange(m_Addr.CHS.Head, 0, m_nHeads - 1) &&
                InRange(m_Addr.CHS.Cylinder, 0, m_nCylinders - 1);
        case amByte:
            return m_Addr.Linear.IsValid();
        default:
            return false;
        }
    }

public:
    inline void AssertValid() {
        ASSERT(_IsValid());
    }

    void UpdateByLinear();

public:
DECLARE_REGISTRY_RESOURCEID(IDR_DISKADDRESS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDiskAddress)
	COM_INTERFACE_ENTRY(IDiskAddress)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CDiskAddress)
END_CONNECTION_POINT_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IDiskAddress
public:
	STDMETHOD(IsValid)(/*[out,retval]*/VARIANT_BOOL *retVal);
	STDMETHOD(SetLinear)(/*[in]*/long Low, /*[in]*/long High);
	STDMETHOD(SetCHS)(/*[in]*/long Cylinder, /*[in]*/short Head, /*[in]*/short Sector, /*[in]*/short Offset);
	STDMETHOD(SetLBA)(/*[in]*/long LBA, /*[in]*/short Offset);
	STDMETHOD(Update)();
	STDMETHOD(get_Sectors)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_Sectors)(/*[in]*/ short newVal);
	STDMETHOD(get_Heads)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_Heads)(/*[in]*/ short newVal);
	STDMETHOD(get_Cylinders)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Cylinders)(/*[in]*/ long newVal);
	STDMETHOD(get_Mode)(/*[out, retval]*/ AddressModeConstants *pVal);
	STDMETHOD(put_Mode)(/*[in]*/ AddressModeConstants newVal);
	STDMETHOD(get_LinearHigh)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_LinearLow)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_OffsetWithinSector)(/*[out, retval]*/ short *pVal);
	STDMETHOD(get_Sector)(/*[out, retval]*/ short *pVal);
	STDMETHOD(get_Head)(/*[out, retval]*/ short *pVal);
	STDMETHOD(get_Cylinder)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_LBA)(/*[out, retval]*/ long *pVal);
};

#endif //__DISKADDRESS_H_

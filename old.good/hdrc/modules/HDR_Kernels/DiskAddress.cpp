// DiskAddress.cpp : Implementation of CDiskAddress
#include "stdafx.h"
#include "HDR_Kernels.h"
#include "DiskAddress.h"

#define LBA_TO_64_LOW(lba)          (DWORD)( ((DWORD)(lba)) << 9  )
#define LBA_TO_64_HIGH(lba)         (LONG) ( ((DWORD)(lba)) >> 23 )


/////////////////////////////////////////////////////////////////////////////
// CDiskAddress

void CDiskAddress::UpdateByLinear() {
    // Linear -> LBA
    m_Addr.LBA.Offset = (short)(m_Addr.Linear.Low % 512);

    // max 2^ (28+9) = 128G
    DWORD sectors = (m_Addr.Linear.Low >> 9) | (m_Addr.Linear.High << 23);
    m_Addr.LBA.Index = sectors;

    m_Addr.CHS.Offset = m_Addr.LBA.Offset;
    m_Addr.CHS.Sector = (short)(sectors % 63 + 1);
    sectors = (sectors - sectors % 63) / 63;

    m_Addr.CHS.Head = (short)(sectors % m_nHeads);
    sectors = (sectors - sectors % m_nHeads) / m_nHeads;

    m_Addr.CHS.Cylinder = sectors % m_nCylinders;
    sectors = (sectors - sectors % m_nCylinders);
    ASSERT(sectors == 0);

    AssertValid();
}


STDMETHODIMP CDiskAddress::get_LBA(long *pVal)
{
	if (!pVal) return E_POINTER;
    *pVal = (long)m_Addr.LBA.Index;
	return S_OK;
}

STDMETHODIMP CDiskAddress::get_Cylinder(long *pVal)
{
	if (!pVal) return E_POINTER;
    *pVal = (long)m_Addr.CHS.Cylinder;
	return S_OK;
}

STDMETHODIMP CDiskAddress::get_Head(short *pVal)
{
	if (!pVal) return E_POINTER;
    *pVal = (short)m_Addr.CHS.Head;
	return S_OK;
}

STDMETHODIMP CDiskAddress::get_Sector(short *pVal)
{
	if (!pVal) return E_POINTER;
    *pVal = (short)m_Addr.CHS.Sector;
	return S_OK;
}

STDMETHODIMP CDiskAddress::get_OffsetWithinSector(short *pVal)
{
	if (!pVal) return E_POINTER;
    switch (m_Mode) {
    case amLBA:
        *pVal = m_Addr.LBA.Offset;
        break;
    case amCHS:
        *pVal = m_Addr.CHS.Offset;
        break;
    case amByte:
        *pVal = (short)(m_Addr.Linear.Low % 512);
        break;
    default:
        ASSERT(FALSE);
        return E_UNEXPECTED;
    }
	return S_OK;
}

STDMETHODIMP CDiskAddress::get_LinearLow(long *pVal)
{
	if (!pVal) return E_POINTER;
    *pVal = (long)m_Addr.Linear.Low;
	return S_OK;
}

STDMETHODIMP CDiskAddress::get_LinearHigh(long *pVal)
{
	if (!pVal) return E_POINTER;
    *pVal = (long)m_Addr.Linear.High;
	return S_OK;
}

STDMETHODIMP CDiskAddress::get_Mode(AddressModeConstants *pVal)
{
	if (!pVal) return E_POINTER;
    *pVal = m_Mode;
	return S_OK;
}

STDMETHODIMP CDiskAddress::put_Mode(AddressModeConstants newVal)
{
    if (newVal != amLBA &&
        newVal != amCHS &&
        newVal != amByte)
        return E_INVALIDARG;

	m_Mode = newVal;
    AssertValid();
	return S_OK;
}

STDMETHODIMP CDiskAddress::get_Cylinders(long *pVal)
{
	if (!pVal) return E_POINTER;
    *pVal = (long)m_nCylinders;
	return S_OK;
}

STDMETHODIMP CDiskAddress::put_Cylinders(long newVal)
{
	m_nCylinders = newVal;
    UpdateByLinear();
	return S_OK;
}

STDMETHODIMP CDiskAddress::get_Heads(short *pVal)
{
	if (!pVal) return E_POINTER;
    *pVal = (short)m_nHeads;
	return S_OK;
}

STDMETHODIMP CDiskAddress::put_Heads(short newVal)
{
    m_nHeads = newVal;
    UpdateByLinear();
	return S_OK;
}

STDMETHODIMP CDiskAddress::get_Sectors(short *pVal)
{
	if (!pVal) return E_POINTER;
    *pVal = (short)m_nSectors;
	return S_OK;
}

STDMETHODIMP CDiskAddress::put_Sectors(short newVal)
{
	m_nSectors = newVal;
    UpdateByLinear();
	return S_OK;
}

STDMETHODIMP CDiskAddress::Update()
{
	UpdateByLinear();
	return S_OK;
}

STDMETHODIMP CDiskAddress::SetLBA(long LBA, short Offset)
{
	if (LBA < 1 || Offset < 0 || Offset >= 512) return E_INVALIDARG;

    m_Addr.Linear.Low  = LBA_TO_64_LOW(LBA) + Offset;
    m_Addr.Linear.High = LBA_TO_64_HIGH(LBA);
    UpdateByLinear();
	return S_OK;
}

STDMETHODIMP CDiskAddress::SetCHS(long Cylinder, short Head, short Sector, short Offset)
{
	if (!InRange(Cylinder, 0, m_nCylinders - 1) ||
        !InRange(Head, 0, m_nHeads - 1) ||
        !InRange(Sector, 1, m_nSectors) ||
        !InRange(Offset, 0, 511))
        return E_INVALIDARG;

    typedef unsigned __int64 U64;
    U64 linear =
        (
            (
                (U64)Cylinder * m_nHeads +
                (U64)Head
            ) * m_nSectors +
            (U64)(Sector - 1)
        ) * 512 + (U64)Offset;

    DWORD *dw = (DWORD *)&linear;
    m_Addr.Linear.Low  = dw[0];
    m_Addr.Linear.High = (long)dw[1];
    ASSERT((m_Addr.Linear.High >> 9) == 0);

    UpdateByLinear();
	return S_OK;
}

STDMETHODIMP CDiskAddress::SetLinear(long Low, long High)
{
	m_Addr.Linear.Low  = (DWORD)Low;
    m_Addr.Linear.High = High;
    UpdateByLinear();
	return S_OK;
}


STDMETHODIMP CDiskAddress::IsValid(VARIANT_BOOL *retVal)
{
    if (!retVal) return E_POINTER;

    *retVal = _IsValid() ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}


STDMETHODIMP CDiskAddress::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IDiskAddress
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

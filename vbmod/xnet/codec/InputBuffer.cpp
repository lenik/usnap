// InputBuffer.cpp : Implementation of CInputBuffer
#include "stdafx.h"
#include "Codec.h"
#include "InputBuffer.h"

/////////////////////////////////////////////////////////////////////////////
// CInputBuffer


STDMETHODIMP CInputBuffer::AddBytes(SAFEARRAY **bytes)
{
    if (bytes == 0)
        return E_POINTER;

    SAFEARRAY *sa = *bytes;
    if (sa == 0)
        return E_POINTER;

    int cb = sa->cbElements;
    for (int i = 0; i < sa->cDims; i++)
        cb *= sa->rgsabound[i].cElements;

    m_Buf.write((unsigned char *)sa->pvData, cb);
    return S_OK;
}

STDMETHODIMP CInputBuffer::StatementReady(VARIANT_BOOL *ret)
{
    if (ret == 0)
        return E_POINTER;

    *ret = FALSE;

    while (! stmt_ok) {
        if (! nextParam) {
            // start new param
            int unread = m_Buf.getUnread();
            if (unread == 0)
                break;
            nextParam = new Decoder;
            const char *pStop = nextParam->process(
                (char *)(unsigned char *)m_Buf, unread);
            int processed = pStop - (char *)(unsigned char *)m_Buf;
            if (processed > 0)
                m_Buf.skip(processed);
        }

        if (nextParam) {
            if (! nextParam->term())    // stop at non-term param
                return S_FALSE;

            int size = nextParam->buf.getSize();
            char *part = (char *)nextParam->buf.detach();
            stmt_ok = nextParam->termLine();

            delete nextParam;
            nextParam = 0;

            if (nextStmt == 0)
                nextStmt = new CStatementObject;

            HRESULT hr = nextStmt->Add(part, size);
            _assert_(SUCCEEDED(hr));
        }
    }

    if (stmt_ok) {
        *ret = TRUE;
        return S_OK;
    }

    return S_FALSE;
}

STDMETHODIMP CInputBuffer::GetStatement(IStatement **ppStatement)
{
    HRESULT hr;

    if (ppStatement == 0)
        return E_POINTER;

    *ppStatement = 0;

    VARIANT_BOOL ready;
    hr = StatementReady(&ready);

    if (FAILED(hr))
        return E_FAIL;

    if (! ready)
        return S_FALSE;

    *ppStatement = nextStmt;
    nextStmt = 0;
    stmt_ok = 0;

    (*ppStatement)->AddRef();

    // TODO opt.
    // m_Buf.truncate();

    return S_OK;
}

STDMETHODIMP CInputBuffer::get_AllocatedSize(long *pVal)
{
    if (pVal == 0)
        return E_POINTER;
    *pVal = m_Buf.getAllocated();

    return S_OK;
}

STDMETHODIMP CInputBuffer::get_UsedSize(long *pVal)
{
    if (pVal == 0)
        return E_POINTER;
    *pVal = m_Buf.getSize();

    return S_OK;
}

STDMETHODIMP CInputBuffer::get_UnreadSize(long *pVal)
{
    if (pVal == 0)
        return E_POINTER;
    *pVal = m_Buf.getUnread();

    return S_OK;
}

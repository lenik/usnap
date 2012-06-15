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

    m_Buf.write((BYTE *)sa->pvData, cb);
    return S_OK;
}

STDMETHODIMP CInputBuffer::StatementReady(VARIANT_BOOL *ret)
{
    if (ret == 0)
        return E_POINTER;

    *ret = FALSE;

    while (! stmt_ok) {
        if (! nextParam)
            nextParam = new Decoder;

        if (! nextParam->term()) {
            int unread = m_Buf.getUnread();
            if (unread == 0)
                break;
            const BYTE *pStop = nextParam->process(
                (BYTE *)m_Buf, unread);
            int processed = pStop - m_Buf;
            if (processed > 0)
                m_Buf.skip(processed);
        }

        if (! nextParam->term())    // stop at non-term param
            return S_FALSE;

        int size = nextParam->buf.getSize();
        BYTE *part = (BYTE *)nextParam->buf.detach();
        int quoted = nextParam->quoted;
        stmt_ok = nextParam->termLine();

        delete nextParam;
        nextParam = 0;

        int have_segs = 0;
        if (nextStmt)
            nextStmt->get_Count(&have_segs);

        if (have_segs == 0 && part == 0)
            // skip empty stmt.
            stmt_ok = 0;

        if (nextStmt == 0)
            nextStmt = new CStatementObject;

        HRESULT hr;
        if (part) {
            hr = nextStmt->Add(part, size);
            free(part);
        } else if (quoted) {
            hr = nextStmt->Add(0, 0);
        }

        _assert_(SUCCEEDED(hr));
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
    _assert_(nextParam == 0);
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

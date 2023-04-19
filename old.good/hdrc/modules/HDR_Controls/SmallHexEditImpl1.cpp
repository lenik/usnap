//$$---- Active Form CPP ---- (stActiveFormSource)
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <atl\atlvcl.h>

#include <stdio.h>
#include "SmallHexEditImpl1.h"
#include "SHE_About1.h"

#include <dbg_id.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSmallHexEdit *SmallHexEdit;
//---------------------------------------------------------------------------
__fastcall TSmallHexEdit::TSmallHexEdit(HWND ParentWindow)
    : TActiveForm(ParentWindow)
{
    X_OnCreate = NULL;
}
//---------------------------------------------------------------------------


TSmallHexEditImpl::TSmallHexEditImpl() {
    m_nRows         = 16;
    m_nColumns      = 16;
    m_pbBinary      = (BYTE *)
        "2	微型十六进制编辑器 SmallHexEditor，ISmallHexEditor\n"
        "  w	BinaryPointer, Length, Font, Rows, Columns\n"
        "  w	AsiaSupport, ReadOnly, Dirty\n"
        "  w	~PassBOF à BOOL	绕回底部，总是刷新。\n"
        "  w	~PageEOF à BOOL	绕回顶部，总是刷新。\n"
        "  w	~Modified\n"
        "   n	Motivation\n"
        "   n	Objective\n"
        "   n	Sandbox\n"
        "   1	治学要不要严谨？还是严谨一点的好。\n"
        "   2\n"
        "  w	BinaryPointer, Length, Font, Rows, Columns\n"
        "  w	AsiaSupport, ReadOnly, Dirty\n"
        "  w	~PassBOF à BOOL	绕回底部，总是刷新。\n"
        "  w	~PageEOF à BOOL	绕回顶部，总是刷新。\n"
        "  w	~Modified\n"
        ;
    m_nLength       = strlen((char *)m_pbBinary);

    m_bDirty        = FALSE;
    m_bReadOnly     = FALSE;

    m_bAsiaSupport  = FALSE;

    m_nOffset       = 0;
    m_nColumn       = 0;
    m_nRow          = 0;
    m_iWord         = 0;

    m_bAsciiView    = FALSE;

    memset(&m_tm, 0, sizeof(TEXTMETRIC));
    m_hDC           = NULL;
    m_bInited       = FALSE;
}


void __fastcall TSmallHexEditImpl::ActivateEvent(TObject *Sender)
{
    // Lazy Initializing.
    InitView();

    if (m_bmCaret == NULL) {
        // Load caret shape.
        // m_bmCaret = LoadBitmap(HInstance, MAKEINTRESOURCE(SHE_CARET));
        m_bmCaret =
            m_VclCtl->imgSheCaret->Picture->Bitmap->Handle;
    }

    EnableCaret();
    UpdateCaret();
    Fire_OnActivate();
}


void __fastcall TSmallHexEditImpl::DeactivateEvent(TObject *Sender)
{
    DisableCaret();
    Fire_OnDeactivate();
}


void __fastcall TSmallHexEditImpl::ClickEvent(TObject *Sender)
{
    Fire_OnClick();
}


void __fastcall TSmallHexEditImpl::DblClickEvent(TObject *Sender)
{
}


void __fastcall TSmallHexEditImpl::DestroyEvent(TObject *Sender)
{
    if (m_bmCaret) {
        DeleteObject(m_bmCaret);
        m_bmCaret = NULL;
    }
    Fire_OnDestroy();
}


void __fastcall TSmallHexEditImpl::PaintEvent(TObject *Sender)
{
    UpdateView();
    Fire_OnPaint();
}


STDMETHODIMP TSmallHexEditImpl::_set_Font(IFontDisp** Value)
{
  try
  {
    const DISPID dispid = -512;
    if (FireOnRequestEdit(dispid) == S_FALSE)
      return S_FALSE;
    SetVclCtlProp(m_VclCtl->Font, Value);

    // Update the internal Font metrics.
    GetTextMetrics(m_hDC, &m_tm);

    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::AboutBox()
{
  try
  {
  ShowSmallHexEditAbout();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_Active(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Active;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_AlignDisabled(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->AlignDisabled;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_AutoScroll(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->AutoScroll;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_AutoSize(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->AutoSize;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_AxBorderStyle(
  TxActiveFormBorderStyle* Value)
{
  try
  {
   *Value = (TxActiveFormBorderStyle)(m_VclCtl->AxBorderStyle);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_BorderWidth(long* Value)
{
  try
  {
   *Value = (long)(m_VclCtl->BorderWidth);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_Caption(BSTR* Value)
{
  try
  {
    *Value = WideString(m_VclCtl->Caption).Copy();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_Color(::OLE_COLOR* Value)
{
  try
  {
   *Value = (::OLE_COLOR)(m_VclCtl->Color);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_DoubleBuffered(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->DoubleBuffered;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_DropTarget(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->DropTarget;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_Enabled(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Enabled;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_Font(IFontDisp** Value)
{
  try
  {
    GetVclCtlProp(m_VclCtl->Font, Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_HelpFile(BSTR* Value)
{
  try
  {
    *Value = WideString(m_VclCtl->HelpFile).Copy();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_KeyPreview(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->KeyPreview;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_PixelsPerInch(long* Value)
{
  try
  {
   *Value = (long)(m_VclCtl->PixelsPerInch);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_PrintScale(TxPrintScale* Value)
{
  try
  {
   *Value = (TxPrintScale)(m_VclCtl->PrintScale);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_Scaled(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Scaled;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_Visible(VARIANT_BOOL* Value)
{
  try
  {
   *Value = m_VclCtl->Visible;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_VisibleDockClientCount(long* Value)
{
  try
  {
   *Value = (long)(m_VclCtl->VisibleDockClientCount);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_AutoScroll(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 2;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->AutoScroll = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_AutoSize(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 3;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->AutoSize = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_AxBorderStyle(
  TxActiveFormBorderStyle Value)
{
  try
  {
    const DISPID dispid = 4;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->AxBorderStyle = (TActiveFormBorderStyle)(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_BorderWidth(long Value)
{
  try
  {
    const DISPID dispid = 5;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->BorderWidth = (int)(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_Caption(BSTR Value)
{
  try
  {
    const DISPID dispid = -518;
    if (FireOnRequestEdit(dispid) == S_FALSE)
      return S_FALSE;
    m_VclCtl->Caption = AnsiString(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_Color(::OLE_COLOR Value)
{
  try
  {
    const DISPID dispid = -501;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->Color = (TColor)(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_DoubleBuffered(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 13;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->DoubleBuffered = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_DropTarget(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 11;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->DropTarget = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_Enabled(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = -514;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->Enabled = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_Font(IFontDisp* Value)
{
  try
  {
    const DISPID dispid = -512;
    if (FireOnRequestEdit(dispid) == S_FALSE)
      return S_FALSE;
    SetVclCtlProp(m_VclCtl->Font, Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_HelpFile(BSTR Value)
{
  try
  {
    const DISPID dispid = 12;
    if (FireOnRequestEdit(dispid) == S_FALSE)
      return S_FALSE;
    m_VclCtl->HelpFile = AnsiString(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_KeyPreview(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 6;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->KeyPreview = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_PixelsPerInch(long Value)
{
  try
  {
    const DISPID dispid = 7;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->PixelsPerInch = (int)(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_PrintScale(TxPrintScale Value)
{
  try
  {
    const DISPID dispid = 8;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->PrintScale = (TPrintScale)(Value);
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_Scaled(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 9;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->Scaled = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_Visible(VARIANT_BOOL Value)
{
  try
  {
    const DISPID dispid = 1;
    if (FireOnRequestEdit(dispid) == S_FALSE)
     return S_FALSE;
    m_VclCtl->Visible = Value;
    FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_AsiaSupport(VARIANT_BOOL* Value)
{
  try
  {
    *Value = (VARIANT_BOOL)m_bAsiaSupport;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_BinaryPointer(long* Value)
{
  try
  {
    *Value = (long)m_pbBinary;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_Columns(int* Value)
{
  try
  {
    *Value = m_nColumns;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_Dirty(VARIANT_BOOL* Value)
{
  try
  {
    *Value = (VARIANT_BOOL)m_bDirty;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_Length(long* Value)
{
  try
  {
    *Value = m_nLength;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_ReadOnly(VARIANT_BOOL* Value)
{
  try
  {
    *Value = (VARIANT_BOOL)m_bReadOnly;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_Rows(int* Value)
{
  try
  {
    *Value = m_nRows;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_AsiaSupport(VARIANT_BOOL Value)
{
  try
  {
    // for TRUE, they may be any value except 0, so use ! here.
    if (!m_bAsiaSupport != !Value) {
        m_bAsiaSupport = !m_bAsiaSupport;
        UpdateView();
    }
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_Columns(int Value)
{
  try
  {
    long AbsoluteOffset = ViewToOffset(m_nRow, m_nColumn);
    m_nColumns = Value;
    OffsetToView(AbsoluteOffset, m_nRow, m_nColumn);

    UpdateView();
    UpdateCaret();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_Length(long Value)
{
  try
  {

  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_ReadOnly(VARIANT_BOOL Value)
{
  try
  {
    m_bReadOnly = Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_Rows(int Value)
{
  try
  {
    long AbsoluteOffset = ViewToOffset(m_nRow, m_nColumn);
    m_nRows = Value;
    OffsetToView(AbsoluteOffset, m_nRow, m_nColumn);

    UpdateView();
    UpdateCaret();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_LeftMargin(int* Value)
{
  try
  {
    *Value = m_nLeftMargin;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::get_TopMargin(int* Value)
{
  try
  {
    *Value = m_nTopMargin;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_LeftMargin(int Value)
{
  try
  {
    m_nLeftMargin = Value;
    UpdateView();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::set_TopMargin(int Value)
{
  try
  {
    m_nTopMargin = Value;
    UpdateView();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


STDMETHODIMP TSmallHexEditImpl::SetBinary(void* BinaryPointer, long Length)
{
  try
  {
    // Nothing happened, if NULL => NULL.
    if (!m_pbBinary && !BinaryPointer) return S_OK;

    // Don't destroy old binary pointer, it's out of my responsibility.
    m_pbBinary = (BYTE *)BinaryPointer;
    m_nLength = Length;

    UpdateView();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ISmallHexEdit);
  }
  return S_OK;
};


void TSmallHexEditImpl::SetCurrentPos(int Row, int Column) {
    long off = ViewToOffset(Row, Column);
    if (off >= m_nLength) off = m_nLength - 1;

    if (off < 0) return;

    OffsetToView(off, Row, Column);

    m_nRow = Row;
    m_nColumn = Column;

    // SetCaretPos(m_nRow, m_nColumn);
}

long TSmallHexEditImpl::ViewToOffset(int Row, int Column) {
    return m_nOffset + Row * m_nColumns + Column;
}
void TSmallHexEditImpl::OffsetToView(long AbsoluteOffset, int& Row, int& Column) {
    long off = AbsoluteOffset - m_nOffset;
    Row = off / m_nColumns;
    Column = off - Row * m_nColumns;
}

int TSmallHexEditImpl::ViewRows() {
    long ViewSize = m_nLength - m_nOffset;
    if (ViewSize <= 0) return 0;

    // 0 [1..10] [11..20] [21..30] ... ==> 0 1 2 3 ...
    return (ViewSize + m_nColumns - 1) / m_nColumns;
}

int TSmallHexEditImpl::ViewColumns(int Row) {
    long off = m_nOffset + Row * m_nColumns;
    long ViewSize = m_nLength - off;
    if (ViewSize >= m_nColumns) return m_nColumns;
    if (ViewSize <= 0) return 0;
    return ViewSize;
}

void TSmallHexEditImpl::ScrollUp() {
    // Differ to ScrollDown, The first page starting from 0
    //  is allowed.
    if (m_nOffset >= m_nColumns) {
        m_nOffset -= m_nColumns;

        // Scrolling allowed the cursor out of the view.
        m_nRow++;

        UpdateCaret();
    }
}

void TSmallHexEditImpl::ScrollDown() {
    // int PageSize = m_nRows * m_nColumns;

    // Here <= will display an empty page without a single line.
    // So use '<' instead.
    if (m_nOffset + m_nColumns < m_nLength) {
        m_nOffset += m_nColumns;

        // Scrolling allowed the cursor out of the view.
        m_nRow--;

        UpdateCaret();
    }
}

void TSmallHexEditImpl::MoveToEnd() {
    if (m_nLength <= 0) {
        m_nOffset = m_nRow = m_nColumn = m_iWord = 0;
        // Don't update the view or caret.
        return;
    }

    long PageSize       = m_nRows * m_nColumns;
    long Pages          = (m_nLength + PageSize - 1) / PageSize;
    long LastPageSize   = m_nLength - (Pages - 1) * PageSize;

    m_nOffset = m_nLength - LastPageSize;
    // 0 [1..10] [11..20] [21..30] ... ==> 0 1 2 3 ...
    //   and Row get the last integer.
    m_nRow = (LastPageSize + m_nColumns - 1) / m_nColumns - 1;
    if (m_nRow < 0) m_nRow = 0;

    m_nColumn = LastPageSize - m_nRow * m_nColumns - 1;
    if (m_nColumn < 0) m_nColumn = 0;

    UpdateCaret();
}

void TSmallHexEditImpl::InitView() {
    if (!m_bInited) {
        m_hDC = m_VclCtl->Canvas->Handle;
        GetTextMetrics(m_hDC, &m_tm);
        m_bInited = TRUE;
    }
}

void TSmallHexEditImpl::ClearView() {
    // Lazy initializing.
    InitView();

    RECT rcClient;
    // this will always return 0 in .left/.top member.
    GetClientRect(m_hWnd, &rcClient);

    // Notice: Draw borders as well.
    Rectangle(m_hDC, rcClient.left, rcClient.top,
        rcClient.right, rcClient.bottom);
}

void TSmallHexEditImpl::UpdateView() {
    // Lazy initializing.
    InitView();

    int r, c;
    int rMax = ViewRows() - 1;

    long off = m_nOffset;
    char sLine[256], *ps;

    BOOL b;

//    ClearView();
    for (r = 0; r <= rMax; r++, off += m_nColumns) {
        sprintf(sLine, "%08X", off);

        m_VclCtl->Canvas->TextOutA(
            m_nLeftMargin, m_nTopMargin + r * m_tm.tmHeight,
            sLine);
        //SIZE size;
        //b = GetTextExtentPoint(m_hDC, sLine, strlen(sLine), &size);
        //ASSERT(b);

        int cMax = ViewColumns(r) - 1;
        //ASSERT(cMax >= 0);
        ps = sLine;
        for (c = 0; c <= cMax; c++) {
            ps += sprintf(ps, "%02X ", m_pbBinary[off + c]);
        }
        m_VclCtl->Canvas->TextOutA(
            m_nLeftMargin + 9 * m_tm.tmAveCharWidth,
            m_nTopMargin + r * m_tm.tmHeight,
            sLine);

        ps = sLine;
        for (c = 0; c <= cMax; c++) {
            int a_char = m_pbBinary[off + c];
            if (!m_bAsiaSupport && a_char > 0x7F) a_char = '?';
            if (a_char < 0x20) a_char = '?';
            *ps++ = a_char;
        }
        *ps = '\0';

        m_VclCtl->Canvas->TextOutA(
            m_nLeftMargin + (9 + m_nColumns * 3) * m_tm.tmAveCharWidth,
            m_nTopMargin + r * m_tm.tmHeight,
            sLine);
    }
}

void TSmallHexEditImpl::EnableCaret() {
    CreateCaret(m_hWnd, m_bmCaret,
        m_tm.tmAveCharWidth,
        m_tm.tmHeight);
    ShowCaret(m_hWnd);
}

void TSmallHexEditImpl::DisableCaret() {
    HideCaret(m_hWnd);
    DestroyCaret();
}

void TSmallHexEditImpl::UpdateCaret() {
    // Lazy initializing.
    InitView();

    if (m_bAsciiView) {
        SetCaretPos(
            m_nLeftMargin + (9 + 3 * m_nColumns + m_nColumn) *
                m_tm.tmAveCharWidth,
            m_nTopMargin + m_nRow * m_tm.tmHeight
            );
    } else {
        SetCaretPos(
            m_nLeftMargin + (9 + m_nColumn * 3 + m_iWord) *
                m_tm.tmAveCharWidth,
            m_nTopMargin + m_nRow * m_tm.tmHeight
            );
    }
}

BYTE *TSmallHexEditImpl::GetCurrentByte() {
    long AbsoluteOffset = ViewToOffset(m_nRow, m_nColumn);
    if (AbsoluteOffset < 0 || AbsoluteOffset >= m_nLength) {
        return NULL;
    }
    return m_pbBinary + AbsoluteOffset;
}


void __fastcall TSmallHexEditImpl::KeyDownEvent(TObject *Sender,
      WORD &Key, TShiftState Shift)
{

    // Never consider an empty block.
    if (m_nLength <= 0) return;

    int Row = m_nRow;
    int Col = m_nColumn;
    int Off = m_nOffset;
    BOOL bUpdate = TRUE;

    switch (Key) {
    case VK_LEFT:
        if (m_bAsciiView) {
            Col--;
        } else {
            if (m_iWord > 0) {
                m_iWord--;
            } else {
                m_iWord = 1;
                Col--;
            }
        }
        break;
    case VK_RIGHT:
        if (m_bAsciiView) {
            Col++;
        } else {
            if (m_iWord < 1) {
                m_iWord++;
            } else {
                m_iWord = 0;
                Col++;
            }
        }
        break;
    case VK_UP:
        if (Shift.Contains(ssCtrl)) {
            ScrollUp();
            bUpdate = FALSE;
         } else {
            Row--;
        }
        break;
    case VK_DOWN:
        if (Shift.Contains(ssCtrl)) {
            ScrollDown();
            bUpdate = FALSE;
        } else {
            Row++;
        }
        break;
    case VK_PRIOR:
        if (Shift.Contains(ssCtrl)) {
            Row = 0;
            Col = 0;
        } else {
            Row -= m_nRows;
        }
        break;
    case VK_NEXT:
        if (Shift.Contains(ssCtrl)) {
            Row = ViewRows() - 1;
            Col = ViewColumns(m_nRow) - 1;
        } else {
            Row += m_nRows;
        }
        break;
    case VK_HOME:
        if (Shift.Contains(ssCtrl)) {
            Off = 0;
            Row = 0;
            Col = 0;
        } else {
            Col = 0;
        }
        break;
    case VK_END:
        if (Shift.Contains(ssCtrl)) {
            MoveToEnd();
            bUpdate = FALSE;
        } else {
            Col = ViewColumns(Row) - 1;
        }
        break;
    case VK_TAB:
        m_bAsciiView = !m_bAsciiView;
        break;
    default:
        break;
    }

    if (bUpdate) {
        long AbsoluteOffset =
            Off + Row * m_nColumns + Col;
        if (AbsoluteOffset < 0) {
            // !!! (So PassBOF raised)
            // Fire_OnPassBOF(BOOL&);
            AbsoluteOffset = 0;
            Off = Row = Col = 0;
        } else if (AbsoluteOffset >= m_nLength) {
            // !!! (So PassEOF raised)
            // Fire_OnPassEOF(BOOL&);
            MoveToEnd();
            return;
        }

        // And SCROLLING Never come here.
        // 1) If (X,Y) is before Body, then Drag View Down;
        // 2)   Set to the beginning if drag down too much.
        // 3) If (X,Y) is after Body, then Drag View Up;
        // 4)   Set to the end if drag up too much.
        if (Col < 0) {
            // [-1..-10] [-11..-20] [-21..-30] ... Y- ==> 1 2 3
            // X ==> [9..0] [9..0] [9..0] ...
            Row -= 1 + -((Col + 1) / m_nColumns);
            Col = m_nColumns + (Col % m_nColumns);
        }

        if (Row < 0) {
            // -1 -2 -3 ... Off- ==> 10 20 30 ...
            // Y ==> 0 0 0 ...
            Off -= m_nColumns * -Row;
            Row = 0;
        }

        // Offset must > 0
        if (Off < 0) {
            Col += Off;
            Off = 0;
        }

        if (Col >= m_nColumns) {
            // [0..9] [10..19] [20..29] ... Y+ ==> 0 1 2 ...
            // X ==> [0..9] [0..9] [0..9] ...
            Row += Col / m_nColumns;
            Col %= m_nColumns;
        }

        if (Row >= m_nRows) {
            // 0 1 2 ... H H+1 H+2 H+3 ... Off+ ==> 0 0 0 ... W 2W 3W 4W ...
            Off += m_nColumns * (Row - (m_nRows - 1));
            Row = m_nRows - 1;
        }

        if (Off >= m_nLength) {
            MoveToEnd();
            return;
        }

        // ASSERT(m_nRow >= 0 && m_nCol >= 0 && m_nOffset >= 0);
        if (Off == m_nOffset && Row == m_nRow && Col == m_nColumn) {
            // Nothing about position has been changed.
            if (!m_bAsciiView) {
                // (m_iWord may be changed.)
                UpdateCaret();
            }
            return;
        }

        m_nRow      = Row;
        m_nColumn   = Col;

        if (m_nOffset != Off) {
            m_nOffset = Off;
            UpdateView();
        }
        UpdateCaret();
    }
}
//---------------------------------------------------------------------------


int __fastcall ParseDigit(int Ascii) {
    static int DigitsTbl[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,       /* 30h ~ 39h */
        -1, -1, -1, -1, -1, -1, -1,         /* 3Ah ~ 40h */
        10, 11, 12, 13, 14, 15,             /* 41h ~ 46h */
    };
    if (Ascii >= 'a' && Ascii <= 'z') Ascii = Ascii & ~0x20;
    if (Ascii < 0x30 || Ascii > 0x46) return -1;
    return DigitsTbl[Ascii - 0x30];
}

void __fastcall TSmallHexEditImpl::KeyPressEvent(TObject *Sender,
      char &Key)
{
    BYTE *pBinary = GetCurrentByte();
    if (pBinary == NULL) return;

    if (m_bAsciiView) {
        // Write the character into binary, directly.
        *pBinary = (BYTE)Key;
    } else {
        BYTE& by = *pBinary;
        int nDigit = ParseDigit(Key);

        // Invalid input
        if (nDigit < 0) return;

        if (m_iWord == 0) {
            // The high 4 bits.
            by = (by & 0x0F) | (nDigit << 4);
        } else {
            // The Low 4 bits.
            by = (by & 0xF0) | (nDigit & 0x0F);
        }
    }

    WORD SimKey = VK_RIGHT;
    TShiftState Shift;
    KeyDownEvent(Sender, SimKey, Shift);
}
//---------------------------------------------------------------------------

void __fastcall TSmallHexEditImpl::MouseDownEvent(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
/*    if (m_bmCaret == NULL) {
        // Load caret shape.
        // m_bmCaret = LoadBitmap(HInstance, MAKEINTRESOURCE(SHE_CARET));
        m_bmCaret =
            m_VclCtl->imgSheCaret->Picture->Bitmap->Handle;
    }
    CreateCaret(m_hWnd, m_bmCaret, 1, m_tm.tmHeight);
    ShowCaret(m_hWnd);
    UpdateCaret();
*/

    int Row = (Y - m_nTopMargin) / m_tm.tmHeight;
    int Col = (X - m_nLeftMargin) / m_tm.tmAveCharWidth - 9;

    if (Col < 0) Col = 0;
    if (Col < 3 * m_nColumns) {
        m_iWord = (Col % 3 == 0) ? 0 : 1;
        Col /= 3;
        m_bAsciiView = FALSE;
    } else {
        Col -= 3 * m_nColumns;
        if (Col < 0) Col = 0;
        m_bAsciiView = TRUE;
    }

    if (Row >= ViewRows()) Row = ViewRows() - 1;
    if (Col >= ViewColumns(Row)) Col = ViewColumns(Row) - 1;

    m_nRow = Row;
    m_nColumn = Col;

    UpdateCaret();
}
//---------------------------------------------------------------------------

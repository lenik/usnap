
#include "stdafx.h"

#include "ComEntry.h"

CEntry::CEntry() { m_bDisabled = FALSE; }
CEntry::CEntry(int nYear, int nMonth, int nDay, int nHour, int nMinute, int bDisabled, CString &sText) : m_tTime(nYear, nMonth + 1, nDay, nHour, nMinute, 0), m_sText(sText) {
	m_bDisabled = bDisabled;
}

CEntry::~CEntry() {
	// Nothing to do here; the destructor for the Cime and CString are invoked automatically
}

CTime CEntry::GetTime() {
	return m_tTime;
}

CString CEntry::GetText() {
	return m_sText;
}

int CEntry::GetDisabled() {
	return m_bDisabled;
}

int CEntry::SetDisabled(int bNewState) {
	int bOldState = m_bDisabled;
	m_bDisabled = bNewState;
	return bOldState;
}

int CEntry::Serialize(CArchive& ar) {
	static CString sTestString("Personal_entry: ");
	if (ar.IsStoring()) {
		ar << sTestString;
		ar << m_tTime;
		ar << (WORD)m_bDisabled;
		ar << m_sText;
		return 0;
	} else {
		CString sTest;
		ar >> sTest;
		if (sTest != sTestString) {
			return -1;
		}
		ar >> m_tTime;
		WORD bDisabled;
		ar >> bDisabled;
		m_bDisabled = bDisabled;
		ar >> m_sText;
		return 0;
	}
}
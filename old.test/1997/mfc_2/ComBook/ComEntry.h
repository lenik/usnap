#pragma once

class CEntry {
protected:
	int m_bDisabled;
	CTime m_tTime;
	CString m_sText;
public:
	CEntry();
	CEntry(int nYear, int nMonth, int nDay, int nHour, int nMinute, int bDisabled, CString &sText);
	~CEntry();
public:
	CTime GetTime();
	CString GetText();
	int GetDisabled();
	int SetDisabled(int bNewValue = TRUE);
	int Serialize(CArchive &ar);
};

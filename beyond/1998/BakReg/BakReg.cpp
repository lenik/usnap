#include "BakReg.h"
#include "Reporter.cpp"
#include "RegFuncs.cpp"
#include "CopyFunc.cpp"

WINAPI WinMain(
			   HINSTANCE hInstance,
			   HINSTANCE hPrevInstance,
			   LPSTR lpCmdLine,
			   int nCmdShow
			   ) {
	HKEY hKeyS = HKEY_USERS, hKeyD = HKEY_USERS;
	GWin w(hInstance, nCmdShow);
	Copy *c;
	LPSTR lpNA, lpNB, lpBegin;

	w.param.lpClassName = "EDIT";
	w.param.dwStyle |= WS_HSCROLL | WS_VSCROLL;
	w.param.dwStyle |= ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL;
	w.Init();
	w.Create();

	r = new Reporter(w.hWnd, "Reports: \r\n");

	if (PerCmdLine(lpCmdLine, &hKeyS, &hKeyD, &lpNA, &lpNB) == 0) {
		lpBegin = new CHAR[4096];
		wsprintf(lpBegin,
			"��ʼ����ע����� %s �� %s%s \n�� YES ��ʼ, �����˳�. \n�ҿ���� / л���� \nTopCroak Software / DanSei \n��Ȩ����  1999.6 �й�.�㽭",
			lpNA,
			lpNB,
			bSub == TRUE ? "(���Ӽ�)" : "");
		if (MessageBox(NULL, lpBegin, "��ʼ����", MB_YESNO) == IDYES) {
			c = new Copy(hKeyD);
			c->CopyKey(hKeyS, hKeyD, bSub);
			delete c;
		}
		delete lpBegin;
		RegClose(hKeyS, hKeyD);
		MessageBox(NULL, "ע��������!", "�ɹ�����", MB_OK);
	} else {
		MessageBox(NULL, "��ʽ: BakReg [-s] [Դ��] [Ŀ���] \n(ȱʡԤ��������Ϊ HKEY_USERS)", "��������!", MB_OK);
	}

	return 0;
}
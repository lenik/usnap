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
			"开始备份注册表项 %s 到 %s%s \n按 YES 开始, 否则退出. \n桃壳软件 / 谢继雷 \nTopCroak Software / DanSei \n版权保留  1999.6 中国.浙江",
			lpNA,
			lpNB,
			bSub == TRUE ? "(带子键)" : "");
		if (MessageBox(NULL, lpBegin, "开始备份", MB_YESNO) == IDYES) {
			c = new Copy(hKeyD);
			c->CopyKey(hKeyS, hKeyD, bSub);
			delete c;
		}
		delete lpBegin;
		RegClose(hKeyS, hKeyD);
		MessageBox(NULL, "注册表备份完毕!", "成功结束", MB_OK);
	} else {
		MessageBox(NULL, "格式: BakReg [-s] [源键] [目标键] \n(缺省预定义主键为 HKEY_USERS)", "参数错误!", MB_OK);
	}

	return 0;
}
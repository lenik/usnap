
//	城市对象模型	COM
//
//	自动测试程序
//
//	初稿		2000.12.1

//
// 综合各模块数据结构
//

#include "coGuider.h"
#include "coRouter.h"

// 装入城市对象数据文件
coRet	read_city_file(coSTR map_file, coCity_r city);

coRet	read_city_file(coSTR map_file, coCity_r city) {
	coRet r;
	co_setok(r);

	CFile f;
	f.Open(map_file, 0);
	f.Close();
	return r;
}

// 用户界面
#include <GWin.h>

int PASCAL WinMain(HINSTANCE hInstance,
		   HINSTANCE hPrevInstance,
		   LPSTR lpCmdLine,
		   int nCmdShow) {
	return 0;
}


//	���ж���ģ��	COM
//
//	�Զ����Գ���
//
//	����		2000.12.1

//
// �ۺϸ�ģ�����ݽṹ
//

#include "coGuider.h"
#include "coRouter.h"

// װ����ж��������ļ�
coRet	read_city_file(coSTR map_file, coCity_r city);

coRet	read_city_file(coSTR map_file, coCity_r city) {
	coRet r;
	co_setok(r);

	CFile f;
	f.Open(map_file, 0);
	f.Close();
	return r;
}

// �û�����
#include <GWin.h>

int PASCAL WinMain(HINSTANCE hInstance,
		   HINSTANCE hPrevInstance,
		   LPSTR lpCmdLine,
		   int nCmdShow) {
	return 0;
}

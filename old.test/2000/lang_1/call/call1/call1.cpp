// call1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdarg.h>

struct function_proto {
	string name;
	list<
		struct {
			argument_datatypename,
			argument_name,
			[argument_size](for cache)
		}
	> args;
};
struct datatype {
	string name;
	list<
		struct {
			string typename;
			datatype typedesc;
		}
	> elements;
	long type_size;
};

enum callproto {
	_cdecl,
	pascal,
	_stdcall
};

struct callproto {
	string protoname;		// cdecl, pascal, stdcall, etc...
};

int call(void *address, enum callproto, ...) {
}

// �����ද̬װ�ؿ�ĺ������ã�
//	1������ͨ��ϵͳ
//	2��������APIϵͳ
// ����2��������Ҫ�����û��������������������ֻ�轫��Ҫ�����ݽṹд��procĿ¼
// ������ģ��� IO �ӿڼ��ɡ�

// ����һ�������ں�������̫�鷳�ĵ��ǾͿ��Խ���ˡ�

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	return 0;
}

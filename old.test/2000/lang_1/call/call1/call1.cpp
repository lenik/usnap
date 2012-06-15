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

// 两大类动态装载库的函数调用：
//	1、核心通信系统
//	2、命令行API系统
// 对于2，命令主要用于用户界面输入输出，而核心只需将必要的数据结构写入proc目录
// 并接受模块的 IO 接口即可。

// 这样一来，关于函数调用太麻烦的担忧就可以解决了。

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	return 0;
}

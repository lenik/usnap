
#pragma once

#include <his/base.h>

// hiFS
// 暂时由它提供文件系统支持

// 核心文件系统

// 新的文件系统尽可能使程序不必考虑文件当前位置的概念
// 这样SEEK取消
// 文件的长度：只能重新指定，一旦指定就不改变。
// 这样就没有APPEND这种属性
// 文件都是可读可写，安全性可以考虑另外的层次
// 这样就没有ATTRIBUTE这种东西
// 并发操作暂不考虑
// 目录的问题，可以使用\或/作分隔符，内部将其划分成数组，用\0作分隔符，后加\0
// 操作系统没有把内存的使用划分成树，hiFS是。

// 内存没有关闭了重新打开的特性，但FS是持久的，需要open、close命令
//

// 传递过来的核心内存位于(hisroot)/proc/core/
// 仅用于核心间模块的交互。

struct hi_core_memory {
	hicode	(hiapi *init)(char *name);
	hicode	(hiapi *uninit)();
	hicode	(hiapi *get)(hisize pos, char *retchar);
	hicode	(hiapi *set)(hisize pos, char newchar);
}


#pragma once

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define XPFILE	"z:\\t\l\\share\\bison.simple"
#define XPFILE1	"z:\\t\l\\share\\bison.hairy"

#define getpid	GetCurrentProcessId

#ifdef __cplusplus
extern "C" {
#endif
	unsigned long _stdcall GetCurrentProcessId();
#ifdef __cplusplus
};
#endif

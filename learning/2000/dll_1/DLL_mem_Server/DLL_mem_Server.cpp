// DLL_mem_Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "..\DLL_withmem\DLL_withmem.h"

int main(int argc, char* argv[])
{
	int	i = fnDLL_withmem();
	CDLL_withmem	*p;
	p	= fnDLL_getobject();
	p->m_F1();

	p	= fn_getobject();
	p->m_F1();

	printf("Hello World!\n");
	return 0;
}

#include "leak.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <Windows.h>

leak::leak()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}


leak::~leak()
{
	if (_CrtDumpMemoryLeaks())
	{
		::MessageBox(NULL, L"Memory Leak", NULL, NULL);
	}
}

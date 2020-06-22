// dllmain.cpp : Defines the entry point for the DLL application.
#include "Main.h"
#include "Client.h"
#ifdef _WIN32

#include <Windows.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
#else
	unsigned long long min(unsigned long long X, unsigned long long Y) { return ((X) < (Y) ? (X) : (Y)); }
	unsigned long long max(unsigned long long X, unsigned long long Y) { return ((X) > (Y) ? (X) : (Y)); }
#endif


char* StaticString512()
{
	static char Strings[512][1024];
	static int index;
	index &= 0x3FF;	//Limit to 2^10 - 1 
	return Strings[index++];
}


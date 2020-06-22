/*
	Main include file.

	Created:		2017-12-04 17:13

	Revision:
		Christopher Békési - 2017-12-04 19:09	- Initial
*/

/*
	1: Load file index
	2: Load config files
	3: Load Memcache

*/

#ifdef MAINFRAME_EXPORTS
	#ifdef _WIN32
		#define MAINFRAME_API __declspec(dllexport)
	#else
		#define MAINFRAME_API __attribute__ ((visibility ("default")))
	#endif
#else
	#ifdef _WIN32
		#define MAINFRAME_API //__declspec(dllimport)
	#else
		#define MAINFRAME_API
	#endif
#endif

//Inline or not inline.. Compatibility with old MSVC++ compiler.
#ifdef USEFORCEINLINE
#define FORCEINLINE__ __forceinline
#else
#define FORCEINLINE__
#endif


#ifdef _WIN32
//Get rid of some warnings
	#pragma warning(disable:4312)
	#pragma warning(disable:1786)
	#pragma warning(disable:4244)
	#pragma warning(disable:864)
	#pragma warning(disable:597)
	#define DLLIMPORT __declspec(dllimport)
	#define DLLEXPORT __declspec(dllexport)
	#define TSOCK SOCKET 
	#define SOCKERR WSAGetLastError()
	#include <WinSock2.h>
	#include <inaddr.h>
#else
	#define __int64 long long
	#define _CSTD ::
	#define __forceinline __attribute__((always_inline))
unsigned long long min(unsigned long long X, unsigned long long Y);
unsigned long long max(unsigned long long X, unsigned long long Y);
	#define stdext std
	#define BYTE unsigned char
	#define UINT64 unsigned long long
	#define INT64 long long
	#define INT int
	#define UINT unsigned int
	#define SHORT short
	#define USHORT unsigned short
	#define strcpy_s(a,b,c) strcpy(a,c)
	#define strcat_s(a,b,c) strcat(a,c)
	#include <cstring>
	#include <dirent.h>
	#include <dlfcn.h> 
	#define DLLIMPORT
	#define DLLEXPORT __attribute__ ((visibility ("default")))
	#define TSOCK int
	#define IPPROTO_TCP 6
	#include <errno.h>
	#define SOCKERR strerror(errno)
	#include <unistd.h>
	/* For socket functions */
	#include <sys/socket.h>
#endif

//#ifdef _WIN32
//Assembly optimized functions.
	/*	Fast check if two strings are equal using SSE 4.2	*/
	//MAINFRAME_API bool appstreq(const char*, const char*);
		/*	Full compare of two strings using SSE 4.2	*/
	//MAINFRAME_API int appstrcmp(const char*, const char*);
	//MAINFRAME_API int appstrlen(const char*);
	//MAINFRAME_API unsigned __int64 appstrstr(const char * str1, const char * str2 );
//#else
#define appstreq(a,b) strcmp(a,b) == 0
#define appstrcmp strcmp
#define appstrlen strlen
#define appstrstr(a,b) (strstr(a,b) - a)
//#endif

//Disable warning(s)
#define _CRT_SECURE_NO_WARNINGS

#ifndef NODEBUG
#define debugf(s,...) printf(s,__VA_ARGS__);
#else
#define debugf(s,...)
#endif

#ifdef _WIN32
#define PATHDEL "\\"
#else
#define PATHDEL "/"
#endif


/* For fcntl */
#include <fcntl.h>

#include <thread>
#include <stdio.h>
//#include <tchar.h>
#include <iostream>
#include <fstream>
//#include <SDKDDKVer.h>
#include <sys/stat.h>
#include <vector>

#ifdef WIN32
	#include "Windows\dirent.h"
	#include <Windows.h>
#undef OPTIONAL
#endif
#include <limits.h>
#include "Hash.h"
#include "sparseconfig.h"
#include "dense_hash_map.h"
#include "dense_hash_set.h"
#include "flat_hash_map.hpp"
#include "Config.h"
#include "ResourceManager.h"
#include "Timer.h"
#include "ServerManager.h"
#include "CTMLCompress.h"
#include "Client.h"
//Get your static string here
MAINFRAME_API char* StaticString512();
/*
	A thread manager class.
	Main purpose of this is to create abstraction for different operating systems.
	Aswell as implementing a highly efficient timer event manager.
	
	Created:		2017-12-13 09:04

	Revision:
		Christopher Békési - 2017-12-13 09:04	- Initial
*/

#ifdef WIN32
#define THREAD HANDLE
#define THREADID unsigned int
#else
#define THREAD pthread_t*
#define THREADID pthread_t

#endif

MAINFRAME_API FORCEINLINE__ THREAD createThread( void(*func)(void*), void* param, unsigned short stackSize = 1024);

MAINFRAME_API FORCEINLINE__ void	 terminateThread(THREAD Thread);

MAINFRAME_API FORCEINLINE__ void	 endThisThread();

MAINFRAME_API FORCEINLINE__ THREAD currentThread();

MAINFRAME_API FORCEINLINE__ THREADID currentThreadID();	//Same as above for linux.

MAINFRAME_API FORCEINLINE__ void	 threadSleep(unsigned __int64 ms);

MAINFRAME_API FORCEINLINE__ unsigned int numHWThreads();
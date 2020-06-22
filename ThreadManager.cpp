#include "Main.h"

#ifdef WIN32
#include <process.h>
#include <thread>
#else
#include <pthread.h>
#endif


THREAD createThread( void(*func)(void*), void* param, unsigned short stackSize)
{
	THREAD T;
#ifdef WIN32
	if((T = (THREAD)_beginthread(func,stackSize*1024,param)) == (THREAD)-1)
	{
		std::cout << "Unable to create thread, errno = " << errno << "n";
		return NULL;
	}
#else
	pthread_attr_t  attr;
	if(pthread_attr_init(&attr))
	{
		std::cout << "Unable to create thread\n";
		return NULL;
	}
	if(pthread_attr_setstacksize(&attr, stackSize*1024))
	{
		std::cout << "Unable to create thread\n";
		return NULL;
	}
	if(pthread_create(T, &attr, (void*(*)(void*))func, 
   param))
    {
		std::cout << "Unable to create thread\n";
		return NULL;
	}
#endif
	return T;
}

MAINFRAME_API void	 terminateThread(THREAD Thread)
{
#ifdef WIN32
	TerminateThread(Thread,0);
#else
	pthread_cancel(*Thread);
#endif
}

MAINFRAME_API void	 endThisThread()
{
#ifdef WIN32
	_endthread();
#else
	pthread_exit(0);
#endif
}

THREAD currentThread()
{
#ifdef WIN32
	return (THREAD)GetCurrentThread();
#else
	return (THREAD)pthread_self();
#endif
}

MAINFRAME_API FORCEINLINE__ THREADID currentThreadID()
{
#ifdef WIN32
	return GetCurrentThreadId();
#else
	return pthread_self();
#endif
}

void threadSleep(unsigned __int64 ms)
{
#ifdef WIN32
	Sleep(ms);
#else
	struct timespec timeOut,remains;

	timeOut.tv_sec = 0;
	timeOut.tv_nsec = ms*1000000; /* 50 milliseconds */

	nanosleep(&timeOut, &remains);
#endif
}

MAINFRAME_API FORCEINLINE__ unsigned int numHWThreads()
{
	return std::thread::hardware_concurrency();
}

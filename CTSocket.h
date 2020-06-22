/*
	This is a wrapper class to abstract the differences between Windows and Linux.

	Revision
		- Christopher 8:53 AM 25 - 2 - 2018

*/
//AF_INET
//SOCK_STREAM


MAINFRAME_API int NetInit();
MAINFRAME_API TSOCK Create();
MAINFRAME_API int Connect(TSOCK, sockaddr*,int);
MAINFRAME_API int Listen(TSOCK);
MAINFRAME_API int Bind(TSOCK);
MAINFRAME_API int Accept(TSOCK);
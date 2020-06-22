#include "Main.h"
#include "CTSocket.h"

int NetInit()
{
#ifdef _WIN32 
	WSADATA wsaData;
	return WSAStartup(MAKEWORD(2, 2), &wsaData);
#else


#endif
}

TSOCK Create()
{
	return socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

int Connect(TSOCK S, sockaddr *addr, int len)
{
	return connect(S, addr, len);
}

int Listen(TSOCK S)
{
	return listen(S, SOMAXCONN);
}
/*
	Server request managers.
	These are the core components of the environment.
	By using a modular system it allows us to add many different
	protocols.
	!!!!
	You can only store one server per library

		Created:		2017-12-13 12:51

	Revision:
		Christopher Békési - 2017-12-13 12:51	- Initial

*/

//Add this macro to the dll
#ifdef _WIN32
#define IMPLEMENT_SERVER(cls)	\
			extern "C" DLLEXPORT cls* CreateServer() { return new cls; }	\
			extern "C" DLLEXPORT void FreeServer(ServerManager* M) { delete M; }						\
			BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved){return TRUE;}
#else
#define IMPLEMENT_SERVER(cls)	\
			extern "C" DLLEXPORT cls* CreateServer() { return new cls; }	\
			extern "C" DLLEXPORT void FreeServer(ServerManager* M) { delete M; }
#endif

class ServerManager
{
public:

	//Starting point for server
	virtual void Initiate() = 0;

	//Decrement clients and flag outdated ones
	virtual void Inspect() = 0;

	//Cleanup
	virtual void RequestExit() = 0;

	//Server signature
	virtual const char* Signature() = 0;
};
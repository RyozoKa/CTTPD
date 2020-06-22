/*
	Time based events, running async

		Created:		2017-12-13 10:32

	Revision:
		Christopher Békési - 2017-12-13 10:32	- Initial

*/

enum
{
	LMONITOR

};

//interval in miliseconds
//bRepeat if event should be repeated indefinitely
//eventID, give the event a unique and static ID
MAINFRAME_API FORCEINLINE__ void newTimerEvent(void(*)(void),unsigned __int64 interval, bool bRepeat, int eventID);

MAINFRAME_API FORCEINLINE__ void terminateEvent(int eventID);
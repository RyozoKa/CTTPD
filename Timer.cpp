#include "Main.h"

struct TimerEvent
{
	void(*event)(void);		//Function to be executed
	unsigned __int64 interval;
	bool bRepeat;
};

void Dispatch(TimerEvent* TE)
{
	do
	{
		std::this_thread::sleep_for (std::chrono::milliseconds(TE->interval));
		TE->event();
	}
	while(TE->bRepeat);
}

google::dense_hash_map<int, TimerEvent*> Events;

void newTimerEvent(void(*event)(void),unsigned __int64 interval, bool bRepeat, int eventID)
{
	TimerEvent* T = new TimerEvent;
	T->event = event;
	T->bRepeat = bRepeat;
	T->interval = interval;
	new std::thread(Dispatch,T);
	Events[eventID] = T;
}

void terminateEvent(int eventID)
{
	Events[eventID]->bRepeat = false;
}
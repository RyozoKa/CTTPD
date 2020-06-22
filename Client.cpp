#include "Main.h"

void Client::Disconnect()
{
#ifdef WIN32
	closesocket(S);
#else
	close(S);
#endif

	//Might be useful in the future.
	S = NULL;

	Detach();
}

void Client::Detach()
{
	//If we don't have any other nodes, return.
	if (!next || next == this) return;

	next->prev = prev;
	prev->next = next;

	//Doesn't matter where in the list it goes.
	bin->Attach(this);
	bin = NULL;
}

Client* Client::NewClient()
{
	if (bin && bin->next != bin)
		return bin->Recycle();
	return new Client;
}

void Client::Attach(Client * in)
{
	//Assign iterator nodes
	in->prev = this;
	next = in;

	in->bin = bin;
}

Client * Client::Initiate()
{
	Client* C = new Client;
	C->bin = new Client;
	C->bin->bin = C->bin;
	C->bin->next = C->bin;
	C->bin->prev = C->bin;
	C->next = C;
	C->prev = C;
	return C;
}

Client * Client::Recycle()
{
	//Disconnect the node
	next->prev = prev;
	prev->next = next;
	
	return this;
}


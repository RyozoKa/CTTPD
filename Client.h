#pragma once


class Client
{
public:

	//Socket conenction belonging to this client
	TSOCK S;
	sockaddr addr;
	int addrsize;

	/*Last request*/
	char lastreq[128];

	//Next node
	Client* next;
	Client* prev;

	//Recycle queue
	Client* bin;

	void Disconnect();

	/*Detach this client from the node list*/
	void Detach();

	/*Get a new or recycled client handle,
	must be called on the queue that belongs to the right thread.*/
	Client* NewClient();

	/*Attach right after this node,
	may only be called from the listener thread*/
	void Attach(Client*);

	/*Create new client, initiate it and return it*/
	static Client* Initiate();

private:

	/*Remove the node from the bin and move it to our active list.
	This assumes that we have at least two nodes in the recycle bin,
	and that this is only called on nodes in the bin.			*/
	Client * Recycle();

	Client();
	~Client();
};
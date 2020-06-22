/*
	A parser which parses and compiles web documents (HTML / CSS) to something
	a lot more efficient

		Created:		2017-12-13 15:35

	Revision:
		Christopher Békési - 2017-12-13 15:35	- Initial

*/

/*
	A HTML/CSS/JS specific compression algorithm
*/

FORCEINLINE__ BYTE* Compress(BYTE*);	//Incoming buffer must be a text stream
FORCEINLINE__ HypBuffer* Extract(HypBuffer*);		//Buffer returned will be a text stream
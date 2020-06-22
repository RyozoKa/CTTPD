/*
	Copyright© 2017 Christopher Békesi
	A complex resource manager including memcache and file indexing

	Created:		2017-12-06 16:37

	Revision:
		Christopher Békési - 2017-12-06 16:37	- Initial
*/



#define FILE_READ	std::fstream::in
#define FILE_WRITE	std::fstream::out
#define FILE_BIN		std::fstream::binary
#define FILE_APP		std::fstream::app
#define FILE_MOD		FILE_READ | FILE_WRITE

//In memory buffer
class MAINFRAME_API HypBuffer
{
public:
	BYTE *bytes;
	unsigned int len;
	unsigned int pos;
	bool bReadOnly;
	FORCEINLINE__ HypBuffer(BYTE* d,unsigned int Size,bool rdOnly=0) : len(Size), pos(NULL),bytes(d), bReadOnly(rdOnly) {}
	FORCEINLINE__ HypBuffer(bool rdOnly=0) : len(NULL), pos(NULL), bReadOnly(rdOnly),bytes(NULL) {}
	FORCEINLINE__ HypBuffer(unsigned int size, bool rdOnly=0) : len(size), pos(NULL), bReadOnly(rdOnly) {bytes = (BYTE*)malloc(size);}

	FORCEINLINE__ operator bool()
	{
		return pos < len;
	}
	/*Not foolproof. */
	FORCEINLINE__ void clear() { free(bytes); pos=0;len=0; }
	FORCEINLINE__ unsigned int	getSize() {return len;}

 	FORCEINLINE__ void	putByte(BYTE byte);
	FORCEINLINE__ void	putInt(int num);
	FORCEINLINE__ void	putUInt(unsigned int num);
	FORCEINLINE__ void	putShort(short num);
	FORCEINLINE__ void	putUShort(unsigned short num);
	FORCEINLINE__ void	putFloat(float fl);
	FORCEINLINE__ void	putDouble(double db);
	FORCEINLINE__ void	putString(char* str);
	FORCEINLINE__ void	putInt64(__int64 longs);
	FORCEINLINE__ void	putUInt64(unsigned __int64 longs);

 	BYTE				getByte();
	int					getInt();
	unsigned int		getUInt();
	short				getShort();
	unsigned short		getUShort();
	float				getFloat();
	double				getDouble();
	char*				getString();
	__int64				getInt64();
	unsigned __int64	getUInt64();
	bool				eof();


};
class HypFile
{
public:
MAINFRAME_API FORCEINLINE__ HypFile() {}
MAINFRAME_API FORCEINLINE__ HypFile(const char* filename, std::ios_base::openmode flags=FILE_BIN);
MAINFRAME_API FORCEINLINE__ ~HypFile() { stream.close(); }

MAINFRAME_API FORCEINLINE__ unsigned __int64 getSize()
{
	unsigned __int64 sz = stream.tellg();
	stream.seekg(0, std::ios::end);
	unsigned __int64 size = stream.tellg();
	stream.seekg(sz);
	return size;
}

//Library loading
#ifdef WIN32
#define LoadLib (void*)LoadLibraryA
#define LoadRes GetProcAddress
#else
#define LoadLib(a) dlopen(a,RTLD_NOW)
#define LoadRes dlsym
#endif

MAINFRAME_API FORCEINLINE__ bool		Open(const char* filename, std::ios_base::openmode flags= FILE_BIN);
MAINFRAME_API FORCEINLINE__ bool		setrwable(bool binary); /*Returns true if sucessfully opened file for writing and reading*/
MAINFRAME_API FORCEINLINE__ bool		isopen() { return stream.is_open(); }
MAINFRAME_API FORCEINLINE__ bool		exists();
MAINFRAME_API FORCEINLINE__ void		create();
MAINFRAME_API FORCEINLINE__ void		close() { stream.close(); }
MAINFRAME_API FORCEINLINE__ void		writeByte(BYTE byte);//Only single byte
MAINFRAME_API FORCEINLINE__ void		writeInt(int wr);
MAINFRAME_API FORCEINLINE__ void		writeUInt(unsigned int wr);
MAINFRAME_API FORCEINLINE__ void		writeShort(short wr);
MAINFRAME_API FORCEINLINE__ void		writeUShort(unsigned short wr);
MAINFRAME_API FORCEINLINE__ void		writeInt64(__int64 wr);
MAINFRAME_API FORCEINLINE__ void		writeUInt64(unsigned __int64 wr);
MAINFRAME_API FORCEINLINE__ void		writeDouble(double write);
MAINFRAME_API FORCEINLINE__ void		writeLong(long wr);
MAINFRAME_API FORCEINLINE__ void		writeFloat(float wr);
MAINFRAME_API FORCEINLINE__ void		writeString(char* wr);

MAINFRAME_API FORCEINLINE__ HypBuffer* createBuffer();

//Memory safe, copy string from buffer.
MAINFRAME_API FORCEINLINE__ void		writeLine(char *str);//Only for nonbinary
MAINFRAME_API FORCEINLINE__ void		writeLine(const wchar_t *str);//Only for nonbinary
MAINFRAME_API FORCEINLINE__ char*		readLineANSI();//Only for nonbinary
MAINFRAME_API FORCEINLINE__ wchar_t*	readLineUni();//Only for nonbinary

MAINFRAME_API FORCEINLINE__ BYTE		readByte();
MAINFRAME_API FORCEINLINE__ unsigned int		readUInt();
MAINFRAME_API FORCEINLINE__ int					readInt();
MAINFRAME_API FORCEINLINE__ unsigned __int64	readUInt64();
MAINFRAME_API FORCEINLINE__ __int64		readInt64();
MAINFRAME_API FORCEINLINE__ double		readDouble();
MAINFRAME_API FORCEINLINE__ long		readLong();
MAINFRAME_API FORCEINLINE__ float		readFloat();
MAINFRAME_API FORCEINLINE__ short		readShort();
MAINFRAME_API FORCEINLINE__ unsigned short	readUShort();
MAINFRAME_API FORCEINLINE__ char*		readString();				//!!BE RESPONSIBLE, free memory
MAINFRAME_API FORCEINLINE__ bool		writeable();
MAINFRAME_API FORCEINLINE__ bool		readable();
MAINFRAME_API FORCEINLINE__ void		setPos(long tpos) {pos = tpos; stream.seekg(pos);}
MAINFRAME_API FORCEINLINE__ __int64	getPos() {return stream.tellg();}
MAINFRAME_API FORCEINLINE__ bool		Eof() {return stream.eof();}
MAINFRAME_API FORCEINLINE__ bool		Eol() { return eol; }
MAINFRAME_API FORCEINLINE__ int		Bad()	{return stream.badbit; }
MAINFRAME_API FORCEINLINE__ char*	getFilename() { return filename;}
MAINFRAME_API FORCEINLINE__ char*	getFilepath() { return filepath; }
private:
	char filename[64];
	char filepath[512];
	std::fstream stream;
	long pos;
	bool eol;
	bool read;
	bool write;
	bool append;
	bool binary;
	char buf[256];
	wchar_t wbuf[256];
};

MAINFRAME_API void FIndexInit(const char*);

MAINFRAME_API void FMemCacheInit();

//Is resource cached in memory already?
MAINFRAME_API bool isMemCached(char*);
MAINFRAME_API bool isMemCached(UINT64);

//Return buffer associated with the Meta File.
MAINFRAME_API HypBuffer* getMemCacheResource(struct FIndex*);
MAINFRAME_API HypFile*	 getDiskResource(struct FIndex*, std::ios_base::openmode);

struct FIndex
{
	char *Path;
	HypBuffer* buf;

	//c_tor
	FIndex(const char* _path, HypBuffer* _buf);
	FIndex(const char* _path);
	bool unloadMemCache();

	//d_tor
	~FIndex();
};

//Iterator interface
class ResourceIterator
{
	ska::flat_hash_map<UINT64, FIndex*>::iterator rciterator;
	const char* Root;
public:

	MAINFRAME_API FORCEINLINE__ ResourceIterator(char* Root);	//Create iterator with given directory
	MAINFRAME_API FORCEINLINE__ void operator++();					//Increment
	MAINFRAME_API FORCEINLINE__ operator bool();
	MAINFRAME_API FORCEINLINE__ FIndex& operator*();
	MAINFRAME_API FORCEINLINE__ FIndex* operator->();
	MAINFRAME_API FORCEINLINE__ operator FIndex*();
};





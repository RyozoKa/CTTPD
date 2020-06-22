
#include "Main.h"

/*
	File index register
	Full path and name, Hash value, pointer to buffer if loaded in memory.
*/

	//c_tor
	FIndex::FIndex(const char* _path, HypBuffer* _buf)
	{
		Path = new char[appstrlen(_path)];
		strcpy(Path,_path);
		buf = _buf;
	}
	FIndex::FIndex(const char* _path)
	{
		Path = new char[appstrlen(_path)];
		strcpy(Path,_path);
		buf = NULL;
	}

	bool FIndex::unloadMemCache()
	{
		if(!buf)
			return false;
		buf->clear();
		delete buf;
		return true;
	}

	//d_tor

	FIndex::~FIndex()
	{
		delete Path;
		if(buf)
		{
			buf->clear();
			delete buf;
		}
	}
	ska::flat_hash_map<UINT64, FIndex*> FileIndex;
int RootIndex;
const char* RootDirectory;
void IndexDirectory(const char*);	//To recursively index all directories and subdirectories
//This must be called before Config or any other file parser
void FIndexInit(const char* root) //Root must be 
{
	RootIndex = appstrlen(root);
	RootDirectory = root;
	IndexDirectory(root);
}

void FMemCacheInit()
{
	char* path;
	int i=0;
	Config::SelectFile("Startup.txt");
	while((path = Config::GetString("MemCache",i++)) != NULL)
	{
		for(ResourceIterator it(path);
			it;
			++it
			)
		{
			std::cout << "Loading file: " << it->Path << "\n";
			HypFile* f = getDiskResource(it,FILE_READ | FILE_BIN);
			it->buf = f->createBuffer();
		}
	}
}

void IndexDirectory(const char* dir)
{
	DIR *dirs;
	dirent *ent;
	char fullname[512];
	int last = appstrlen(dir);
	strcpy(fullname,dir);
	if ((dirs = opendir (dir)) != NULL) 
	{
		while ((ent = readdir (dirs)) != NULL)
		{
			if(ent->d_name[0] == L'.') continue;
			if(ent->d_type == DT_DIR)
			{	
				strcpy_s(fullname + last,511 -  last,ent->d_name);
				strcat_s(fullname, 511, PATHDEL );
				IndexDirectory(fullname);
			}
			else	//File
			{

				strcpy_s(fullname + last,511 -  last,ent->d_name);	//Continue overwriting the last file
				//unsigned __int64 Hash = hashName(fullname + RootIndex);
				FileIndex[hashName(fullname + RootIndex)] = new FIndex(fullname + RootIndex);
				std::cout << "Indexing: " << fullname + RootIndex << '\n';
			}
		}
	}
	closedir(dirs);
}

ResourceIterator::ResourceIterator(char* _Root)
{
	Root = _Root;
	rciterator = FileIndex.begin();
	if (rciterator != FileIndex.end() && appstrstr(rciterator->second->Path, Root) != 0)
	{
		++rciterator;
		debugf("Debugf: Skipping: %s\n",rciterator->second->Path)
			while (rciterator != FileIndex.end() && appstrstr(rciterator->second->Path, Root) != 0)
			{
				debugf("Debugf: Skipping: %s\n", rciterator->second->Path)
				++rciterator;
			}
	}
		//operator++();
}

void ResourceIterator::operator++()
{
	if (rciterator == FileIndex.end()) return;
	++rciterator;
	while (rciterator != FileIndex.end() && appstrstr(rciterator->second->Path, Root) != 0)
	{
		debugf("Debugf: Skipping: %s\n", rciterator->second->Path)
		++rciterator;
	}
}

ResourceIterator::operator bool()
{
	return rciterator != FileIndex.end();
}

FIndex& ResourceIterator::operator*()
{
	return *rciterator->second;
}

MAINFRAME_API FIndex* ResourceIterator::operator->()
{
	return rciterator->second;
}

ResourceIterator::operator FIndex*()
{
	return rciterator->second;
}

//
//Is resource cached in memory already?
bool isMemCached(char* c)
{
	for(auto it = FileIndex.begin(); it != FileIndex.end(); ++it)
	{
		if(appstreq(it->second->Path,c))
			if(it->second->buf)
				return true;
	}
	return false;
}
bool isMemCached(UINT64 c)
{
	return FileIndex.find(c) != FileIndex.end();
}

//Return buffer associated with the Meta File.
HypBuffer* getMemCacheResource(FIndex* f)
{
	return f->buf;
}

HypFile*	 getDiskResource(FIndex* F, std::ios_base::openmode B)
{
	char* c = StaticString512();
	strcpy(c,RootDirectory);	//TODO: Optimize
	strcat(c,F->Path);
	return new HypFile(c,B);
}

//

//HypFile
HypFile::HypFile(const char* filename, std::ios_base::openmode flags) : pos(NULL)
{
	read	=		!!(flags & FILE_READ	);
	write	=		!!(flags & FILE_WRITE	);
	append	=		!!(flags & FILE_APP		);
	binary	=		!!(flags & FILE_BIN		);
	eol = false;
	for(int i=appstrlen((char*)filename) - 1;i>=0;i--)
	{
		if(filename[i] == L'/' || filename[i] == L'\\')
		{
			strcpy(this->filename,(char*)&filename[i+1]);
			if(i > 0)
				strcpy(filepath, (char*)filename);
			break;
		}
		else if(i == 0)
			strcpy(this->filename,(char*)filename);
	}
	if(write)
		create();
	stream.open(filepath, flags);
}
bool HypFile::Open(const char* filename, std::ios_base::openmode flags)
{
	read	=		!!(flags & FILE_READ	);
	write	=		!!(flags & FILE_WRITE	);
	append	=		!!(flags & FILE_APP		);
	binary	=		!!(flags & FILE_BIN		);
	eol = false;
	if(stream.is_open())
		stream.close();
	stream.clear();
	for(int i=appstrlen(filename) - 1;i>=0;i--)
	{
		if(filename[i] == L'/' || filename[i] == L'\\')
		{
			strcpy(this->filename,(char*)&filename[i+1]);
			if(i > 0)
				strcpy(filepath, (char*)filename);
			break;
		}
		else if(i == 0)
			strcpy(this->filename,(char*)filename);
	}
	if(write)
		create();
	stream.open(filepath, flags);
	return isopen();
}
bool HypFile::setrwable(bool binary)
{
	stream.open(filepath,FILE_WRITE | (binary? (FILE_READ | FILE_BIN): FILE_READ));
	return stream.is_open();
}
bool HypFile::exists()
{
	  struct stat buffer;   
	  return (stat(filepath, &buffer) == 0);
}
void HypFile::create()
{
	stream.open(filepath,std::ios_base::out);
	stream.close();
}

bool HypFile::writeable()
{
	if(!exists())
		return false;
	if(!stream)
		return false;
	if(!stream.is_open())
		return false;
	return true;
}
void HypFile::writeByte(BYTE in)
{
	stream.write((char*)&in,1);
}
void HypFile::writeInt(int in)
{
	stream.write((char*)&in,sizeof(int));
}
void HypFile::writeUInt(unsigned int in)
{
	stream.write((char*)&in,sizeof(in));
}
void HypFile::writeUInt64(unsigned __int64 in)
{
	stream.write((char*)&in,sizeof(in));
}
void HypFile::writeInt64(__int64 in)
{
	stream.write((char*)&in,sizeof(in));
}
void HypFile::writeLong(long in)
{
	stream.write((char*)&in,sizeof(in));
}
void HypFile::writeFloat(float in)
{
	stream.write((char*)&in,sizeof(in));
}
void HypFile::writeShort(short in)
{
	stream.write((char*)&in,sizeof(in));
}
void HypFile::writeUShort(unsigned short in)
{
	stream.write((char*)&in,2);
}
void HypFile::writeDouble(double in)	//Fix this
{
	stream.write((char*)&in,sizeof(in));
}
void HypFile::writeString(char* str)
{
	int len = appstrlen(str);
	stream.write((char*)&len,2);
	stream.write(str,len + 1);
}

HypBuffer* HypFile::createBuffer()
{
	HypBuffer* b = new HypBuffer((int)getSize(),true);	//They will never be modified.
	stream.read((char*)b->bytes,b->len);
	return b;
}

void HypFile::writeLine(char *line)
{
	stream << line << '\n';
	stream.flush();
}
void HypFile::writeLine(const wchar_t *line)
{
	stream << line << '\n';
	stream.flush();
}
char* HypFile::readLineANSI()
{
	eol = !(stream >> buf);
	return buf;
}
wchar_t* HypFile::readLineUni()
{
	char C = NULL;
	int i=0;
	for(eol = !stream.get(C);i < 255 && C != 0 && !eol && C != '\n'; eol = !stream.get(C), ++i)
		wbuf[i] = C;
	return wbuf;
}

BYTE HypFile::readByte()
{
	BYTE byte;
	stream.read((char*)&byte,1);
	return byte;
}
int HypFile::readInt()
{
	int in;
	stream.read((char*)&in,sizeof(INT));
	return in;
}
UINT HypFile::readUInt()
{
	UINT in;
	stream.read((char*)&in,sizeof(UINT));
	return in;
}
INT64 HypFile::readInt64()
{
	INT64 in;
	stream.read((char*)&in,sizeof(INT64));
	return in;
}
UINT64 HypFile::readUInt64()
{
	UINT64 in;
	stream.read((char*)&in,sizeof(UINT64));
	return in;
}
SHORT HypFile::readShort()
{
	SHORT in;
	stream.read((char*)&in,sizeof(SHORT));
	return in;
}
USHORT HypFile::readUShort()
{
	USHORT in;
	stream.read((char*)&in,sizeof(USHORT));
	return in;
}
float HypFile::readFloat()
{
 float f;
 stream.read((char*)&f,sizeof(float));
 return f;
}

double HypFile::readDouble()
{
	double f;
	stream.read( (char*)&f,sizeof(double));
	return f;
}
long HypFile::readLong()
{
	long un;
	stream.read((char*)&un,sizeof(long));
	return un;
}
char* HypFile::readString()
{
	unsigned short len;
	stream.read((char*)&len,2);
	char* C = (char*)malloc(len);
	stream.read(C,len);
	return C;
}


void HypBuffer::putByte(BYTE tbyte)
{
	bytes = (BYTE*)realloc(bytes, len + 1);
	len += 1;
	bytes[len - 1] = tbyte;
}
BYTE HypBuffer::getByte()
{
	if (len < pos + 1) return 0;
	return bytes[pos++];
}
void HypBuffer::putInt(int num)
{
	bytes = (BYTE*)realloc(bytes, len + 4);
	len += 4;
	*(int*)(bytes + len - 4) = num;
}
int HypBuffer::getInt()
{
	pos += 4;
	return *(int*)&bytes[pos - 4];
}
UINT HypBuffer::getUInt()
{
	pos += 4;
	return *(UINT*)&bytes[pos - 4];
}
void HypBuffer::putUInt(UINT fl)
{
	bytes = (BYTE*)realloc(bytes, len + 4);
	len += 4;
	*(UINT*)(bytes + len - 4) = fl;
}
void HypBuffer::putFloat(float fl)
{
	bytes = (BYTE*)realloc(bytes, len + 4);
	len += 4;
	*(float*)(bytes + len - 4) = fl;
}
float HypBuffer::getFloat()
{
	pos += 4;
	return *(float*)&bytes[pos - 4];
}
void HypBuffer::putDouble(double db)
{
	bytes = (BYTE*)realloc(bytes, len + 8);
	len += 8;
	*(double*)(bytes + len - 8) = db;
}
double HypBuffer::getDouble()
{
	pos += 8;
	return *(double*)(&bytes[pos - 8]);
}
void HypBuffer::putInt64(INT64 l)
{
	bytes = (BYTE*)realloc(bytes, len + 8);
	len += 8;
	*(INT64*)(bytes + len - 8) = l;
}
void HypBuffer::putUInt64(UINT64 l)
{
	bytes = (BYTE*)realloc(bytes, len + 8);
	len += 8;
	*(UINT64*)(bytes + len - 8) = l;
}
void HypBuffer::putShort(SHORT l)
{
	bytes = (BYTE*)realloc(bytes, len + 2);
	len += 2;
	*(SHORT*)(bytes + len - 2) = l;
}
SHORT HypBuffer::getShort()
{
	pos += 2;
	return *(SHORT*)(&bytes[pos - 2]);
}
void HypBuffer::putUShort(USHORT l)
{
	bytes = (BYTE*)realloc(bytes, len + 2);
	len += 2;
	*(USHORT*)(bytes + len - 2) = l;
}
USHORT HypBuffer::getUShort()
{
	pos += 2;
	return *(USHORT*)(&bytes[pos - 2]);
}
INT64 HypBuffer::getInt64()
{
	pos += 8;
	return *(INT64*)(&bytes[pos - 8]);
}
UINT64 HypBuffer::getUInt64()
{
	pos += 8;
	return *(UINT64*)(&bytes[pos - 8]);
}
bool HypBuffer::eof()
{
		return pos == len;
}
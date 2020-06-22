
#include "Main.h"

//	Type containers

struct ConfigLane
{
	char* attribute;
	unsigned __int64 num;
};

struct ConfigBase
{
	char* filename;
	google::dense_hash_set<ConfigLane*> atts;
};

struct ConfigNum : public ConfigLane
{
	long long val;
};

struct ConfigUNum : public ConfigLane
{
	unsigned long long val;
};

struct ConfigDouble : public ConfigLane
{
	double val;
};

struct ConfigBool : public ConfigLane
{
	bool val;
};

struct ConfigString : public ConfigLane
{
	char val[256];	
};


//Data table
google::dense_hash_set<ConfigBase*> Data;
ConfigBase* current = NULL;

bool isNumreric(const char* c)
{
	int len = appstrlen(c);
	for(int i=0;i<len;++i)
		if(c[i] > '9' || c[i] < '0')
			return false;
	return true;
}

bool isDouble(const char* c)
{
	int len = appstrlen(c);
	bool bDel = false;
	for(int i=0;i<len;++i)
	{
		if(c[i] > '9' || c[i] < '0')
			return false;
		else if(c[i] == '.')
		{
			if(bDel)
				return false;	//Two delimiters?..
			bDel = true;
		}
	}
	if(!bDel)
		return false;
	return true;
}

unsigned __int64 toUNum(const char* c)
{
	int len = appstrlen(c);
	unsigned __int64 num;
	num = c[0] - '0';
	for(int i=1;i<len;++i)
	{
		num *= 10;
		num += c[i] - '0';
	}
	return num;
}

//ResourceManager is required to be initialized before this!!
void Config::ConfigInit()
{
	for(ResourceIterator it("Config");
		it;
		++it)
	{
		HypFile* file= getDiskResource(it, FILE_READ);
		std::cout << it->Path << "\n";
		//Parse config file attribute
		ConfigBase* CB = new ConfigBase;
		CB->filename = new char[64];
		strcpy(CB->filename,file->getFilename());
		Data.insert(CB);

		while(!file->Eol())
		{
			const char* c = file->readLineANSI();
			if(c[0] == 0 || c[0] == ' ' || c[0] == ';') continue;
			unsigned __int64 num=0;
			int sub = 0;
			char* attr;
			const char *val;
			bool bHasAssign = false;
			int len = appstrlen(c);
			for(int i=0;i<len;++i)
			{
				if(c[i] == '=')
				{
					bHasAssign = true;	//Safety check
					attr = new char[i];
					for(int j=0;j<i-sub;++j)
						attr[j] = c[j];
					attr[i-sub] = 0;
					
					if( i == len )
					{
						std::cout << "Error parsing config: " << it->Path << "\n" <<
							"Entry: " << attr << " has no value\n";
						exit(1);
					}
					val = c + i + 1;
					//Figure out what type we've got

					if(appstreq(val,"True") || appstreq(val,"true") || appstreq(val,"TRUE"))
					{
						ConfigBool* b = new ConfigBool;
						b->num = num;
						b->attribute = attr;
						b->val = true;
						CB->atts.insert(b);
					}
					else if(appstreq(val,"False") || appstreq(val,"false") || appstreq(val,"FALSE"))
					{
						ConfigBool* b = new ConfigBool;
						b->num = num;
						b->attribute = attr;
						b->val = false;
						CB->atts.insert(b);
					}
					else if((val[0] == '-' || val[0] == 'u') && isNumreric(val +1))	//Negative values
					{
						ConfigUNum *b = new ConfigUNum;
						b->num = num;
						b->attribute = attr;
						b->val = -(__int64)toUNum(c);
						CB->atts.insert(b);
					}
					else if(isNumreric(val))
					{
						ConfigNum *b = new ConfigNum;
						b->num = num;
						b->attribute = attr;
						b->val = toUNum(c);
						CB->atts.insert(b);
					}
					else if(isDouble(val))
					{
						ConfigDouble *d = new ConfigDouble;
						d->num = num;
						d->attribute = attr;
						d->val = atof(val);
						CB->atts.insert(d);
					}
					else 
					{
						ConfigString *d = new ConfigString;
						d->num = num;
						d->attribute = attr;
						strcpy_s(d->val, 255, val);
						CB->atts.insert(d);
					}
				}

				//Deal with arrays
				if(c[i] == '[')
				{
					if(c[i+1] == ']')
					{
						std::cout << "Error: Array property must have a number\n" << c << "\n";
						exit(1);
					}
					num = c[i + 1] - '0';
					sub = 3;
					if(c[i+2] != ']')
					{
						std::cout << "Error: Array property must have a closing bracket\n" << c << "\n";
						exit(1);
					}
				}
			}
			if(!bHasAssign)
			{
				std::cout << "Error parsing config: " << it->Path << "\n" <<
							"Entry: " << attr << " has no assigned value\n";
				exit(1);
			}
		}
	}
}

void Config::ConfigShutdown()
{
	std::cout << "Flushing and cleaning up configurations \n";
	//Flush

	//Clean up
	for(auto it = Data.begin(); it != Data.end(); ++it)
		delete *it;
	Data.clear();
}

bool Config::SelectFile(const char* filename)
{
	for(auto it=Data.begin(); it != Data.end(); ++it)
		if(appstreq((*it)->filename,filename))
		{
			current = *it;
			return true;
		}
	return false;
}

bool Config::GetBool (char* attr, unsigned char num)
{
	for(auto it = current->atts.begin(); it != current->atts.end(); ++it)
	{
		if(appstreq(attr,(*it)->attribute) && (*it)->num == num)
			return ((ConfigBool*)(*it))->val;
	}
	return 0;
}

long long Config::GetNum (char* attr, unsigned char num)
{
	for(auto it = current->atts.begin(); it != current->atts.end(); ++it)
	{
		if(appstreq(attr,(*it)->attribute) && (*it)->num == num)
			return ((ConfigNum*)(*it))->val;
	}
	return 0;
}

unsigned long long Config::GetUNum (char* attr, unsigned char num)
{
	for(auto it = current->atts.begin(); it != current->atts.end(); ++it)
	{
		if(appstreq(attr,(*it)->attribute) && (*it)->num == num)
			return ((ConfigUNum*)(*it))->val;
	}
	return 0;
}

char* Config::GetString	(char* attr, unsigned char num)
{
	for(auto it = current->atts.begin(); it != current->atts.end(); ++it)
	{
		if(appstreq(attr,(*it)->attribute) && (*it)->num == num)
			return ((ConfigString*)(*it))->val;
	}
	return 0;
}

void Config::SetBool(char* attr, bool val, unsigned char num)
{
	auto it = current->atts.begin();
	for(; it != current->atts.end(); ++it)
	{
		if(appstreq(attr,(*it)->attribute) && (*it)->num == num)
			((ConfigBool*)(*it))->val = val;
	}
	if(it == current->atts.end())
		//Create new entry
	{
		ConfigBool* d = new ConfigBool;
		d->attribute = attr;
		d->val = val;
		d->num = num;
		current->atts.insert(d);
	}
}

void Config::SetNum(char* attr, long long val, unsigned char num)
{
	auto it = current->atts.begin();
	for(auto it = current->atts.begin(); it != current->atts.end(); ++it)
	{
		if(appstreq(attr,(*it)->attribute) && (*it)->num == num)
			((ConfigNum*)(*it))->val = val;
	}
	if(it == current->atts.end())
		//Create new entry
	{
		ConfigNum* d = new ConfigNum;
		d->attribute = attr;
		d->val = val;
		d->num = num;
		current->atts.insert(d);
	}
}

void Config::SetUNum(char* attr, unsigned __int64 val, unsigned char num)
{
	auto it = current->atts.begin();
	for(; it != current->atts.end(); ++it)
	{
		if(appstreq(attr,(*it)->attribute) && (*it)->num == num)
			((ConfigUNum*)(*it))->val = val;
	}
	if(it == current->atts.end())
		//Create new entry
	{
		ConfigUNum* d = new ConfigUNum;
		d->attribute = attr;
		d->val = val;
		d->num = num;
		current->atts.insert(d);
	}
}

void Config::SetDouble(char* attr, double val, unsigned char num)
{
	auto it = current->atts.begin();
	for(; it != current->atts.end(); ++it)
	{
		if(appstreq(attr,(*it)->attribute) && (*it)->num == num)
			((ConfigDouble*)(*it))->val = val;
	}
	if(it == current->atts.end())
		//Create new entry
	{
		ConfigDouble* d = new ConfigDouble;
		d->attribute = attr;
		d->val = val;
		d->num = num;
		current->atts.insert(d);
	}
}

void Config::SetString(char* attr, char* val, unsigned char num)
{
	auto it = current->atts.begin();
	for(; it != current->atts.end(); ++it)
	{
		if(appstreq(attr,(*it)->attribute) && (*it)->num == num)
			strcpy_s( ((ConfigString*)(*it))->val ,255, val);
	}
	if(it == current->atts.end())
		//Create new entry
	{
		ConfigString* d = new ConfigString;
		d->attribute = attr;
		d->num = num;
		strcpy_s(d->val, 255, val);
		current->atts.insert(d);
	}
}


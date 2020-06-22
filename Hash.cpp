#include "Main.h"

void toLower(char* w)
{
	size_t Len = strlen(w);
	for(int i=0;i<Len;i++)
	{
		if(w[i] >= L'A' && w[i] <= L'Z')
			w[i] = L'a' + (w[i] - L'A');
	}
}

void checkAlpha(const char* s)
{
	while(*s)
	{
		if((*s > 'z' || *s < 'a') && (*s < '0' || *s > '9') && *s != '_' && *s != '@' && *s != '?' && *s != '.' && *s != ' ' && *s != ':' && *s != '\\' && *s != '/')
		{
			std::cout << "Error: " << *s << " is not an alpha character!" << "\n";
			throw L"Not an alpha string.";
		}
		++s;
	}
}

unsigned long long hashName(const char *s)
{
    union { unsigned long long h; unsigned char u[8]; };
    int i=0; h=strlen(s);
	char* st = StaticString512();
	strcpy(st,s);
	toLower(st);
    while (*st) { u[i%8] += *st + i + (*st >> ((h/(i+1)) % 5)); st++; i++; }
    return h; //64-bit
}
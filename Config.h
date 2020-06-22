/*
	Copyright© 2017 Christopher Békesi
	Include header for reading/writing Config files.
	Config files are parsed during startup, they are all located in the ./Config folder.

	Created:		2017-12-04 17:13

	Revision:
		Christopher Békési - 2017-12-04 17:13	- Initial
*/
namespace Config
{

	MAINFRAME_API void ConfigInit();
	MAINFRAME_API void ConfigShutdown();
	
	//Select what file to read from. Create if it doesn't exist.
	MAINFRAME_API bool				SelectFile(const char* filename);
	
	//attr = attribute, optional num = array index if any
	MAINFRAME_API bool					GetBool		(char* attr	, unsigned char num = 0U);
	MAINFRAME_API long long				GetNum		(char* attr	, unsigned char num = 0U);
	MAINFRAME_API unsigned long long	GetUNum		(char* attr	, unsigned char num = 0U);
	MAINFRAME_API char*					GetString	(char* attr	, unsigned char num = 0U);
	
	
	MAINFRAME_API void				SetBool		(char* attr, bool val				, unsigned char num = 0U);
	MAINFRAME_API void				SetNum		(char* attr, long long val			, unsigned char num = 0U);
	MAINFRAME_API void				SetUNum		(char* attr, unsigned __int64 val	, unsigned char num = 0U);
	MAINFRAME_API void				SetDouble	(char* attr, double val				, unsigned char num = 0U);
	MAINFRAME_API void				SetString	(char* attr, char* val				, unsigned char num = 0U);


};
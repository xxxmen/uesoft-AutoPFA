#if !defined DATABASEDRIVERHEADER_H
#define DATABASEDRIVERHEADER_H

#ifdef DATABASEDRIVER_EXPORT
#define DataBaseDriver_Exp _declspec ( dllexport )
#else 
#define DataBaseDriver_Exp _declspec ( dllimport )
#endif

typedef CString StdString ;

#endif


#include <string>

#ifdef UNICODE
typedef std::wstring UeStdString;
#define UELPCSTR LPCWSTR
#else
typedef std::string UeStdString;
#define UELPCSTR LPCTSTR
#endif
#ifndef QUANTITY_SHARE
#define QUANTITY_SHARE
#ifdef QUANTITY_EXPORT
#define QUANTITY_API __declspec( dllexport )
#else
#define QUANTITY_API __declspec( dllimport )
#endif
#endif
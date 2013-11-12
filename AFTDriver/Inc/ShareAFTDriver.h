#ifndef SHARE_AFTDRIVER_H_ 
#define SHARE_AFTDRIVER_H_

#ifdef  SHARE_AFTDRIVER_DATA
#define SHARE_AFTDRIVER_CLASS __declspec(dllexport)
#else
#define SHARE_AFTDRIVER_CLASS __declspec(dllimport)
#endif

#endif
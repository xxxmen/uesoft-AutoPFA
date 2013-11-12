#ifndef ERROESTATUS_H
#define ERROESTATUS_H

typedef struct 
{
	
	typedef enum ErrorType{
		UnRegisterType,
		eFileTypeError,
			   eFileOK,
		eReadFileError,
		eSaveFileError
	} FileError;
} ErrorStatus;
#endif
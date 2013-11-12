// Driver.cpp: implementation of the Driver class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Driver.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Driver::Driver()
{

}

Driver::~Driver()
{

}

BOOL Driver::Open(LPCTSTR filename,CStdioFile &File,UINT nOpenFlags)
{
	CFileException ex;
    if (!File.Open(filename,nOpenFlags))
    {
        ex.ReportError();
        return FALSE;
    }
	else
	{
		return TRUE;
	}
}
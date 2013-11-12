// ImpulseDataMgr.cpp: implementation of the ImpulseDataMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImpulseDataMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ImpulseDataMgr::ImpulseDataMgr()
{
	Init();
}

ImpulseDataMgr::~ImpulseDataMgr()
{

}
ImpulseDataMgr& ImpulseDataMgr::Instance()
{
	static ImpulseDataMgr mgr;
	return mgr;
}
void ImpulseDataMgr::Init()
{
	TCHAR exeFullPath[MAX_PATH];
	::GetModuleFileName(NULL,exeFullPath,MAX_PATH);
	CString strPath(exeFullPath);
	int index = strPath.ReverseFind('\\');
	ASSERT(index != -1);
	strPath = strPath.Left(index+1);
	strPath += _T("AutoPFA.txt");
	CStdioFile File;
	if(File.Open(strPath,CFile::typeText))
	{
		m_FuildMgr.Init(File);
	}
}

FuildDataMgr& ImpulseDataMgr::FuildMgr()
{
	return m_FuildMgr;
}

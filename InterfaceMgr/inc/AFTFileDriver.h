// AFTDriver.h: interface for the AFTDriver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTDRIVER_H__7D2AC49F_7CE8_48EE_A772_DAB625E33720__INCLUDED_)
#define AFX_AFTDRIVER_H__7D2AC49F_7CE8_48EE_A772_DAB625E33720__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Driver.h"
#include "AFTScenarioMgr.h"
#include "AFTDriverMgr.h"

class AFTFileDriver : public Driver  
{
public:
	static CString ms_fileMark;
	CString changefilemark( bool strfilemark ) ;
	static Driver* CreatAFTDriver();
	ErrorStatus::FileError Read(LPCTSTR filename,PersistentModel& model);
	ErrorStatus::FileError Save(LPCTSTR filename,PersistentModel& model);
    AFTFileDriver();
	virtual ~AFTFileDriver();

private:
	ErrorStatus::FileError Read(CStdioFile &File,PersistentModel& model);
	ErrorStatus::FileError Save(CStdioFile &File,PersistentModel& model);
	BOOL CheckMark(CString strMark);
	AFTScenarioMgr m_ScenarioMgr;
	
};

#endif // !defined(AFX_AFTDRIVER_H__7D2AC49F_7CE8_48EE_A772_DAB625E33720__INCLUDED_)

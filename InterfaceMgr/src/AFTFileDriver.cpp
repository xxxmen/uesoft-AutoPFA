// AFTDriver.cpp: implementation of the AFTDriver class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTFileDriver.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CString AFTFileDriver::ms_fileMark("AFT IMPULSE VERSION 3.0 INPUT FILE");

AFTFileDriver::AFTFileDriver()
{

}

AFTFileDriver::~AFTFileDriver()
{

}

CString AFTFileDriver::changefilemark( bool strfilemark )
{
	if ( strfilemark )
	{
		ms_fileMark = _T("AFT IMPULSE VERSION 3.0 INPUT FILE");
	}
	else
	{
		ms_fileMark = _T("AFT FATHOM VERSION 6.0 INPUT FILE");
	}
	return ms_fileMark ;
}

Driver* AFTFileDriver::CreatAFTDriver()
{
	return new AFTFileDriver;
}

ErrorStatus::FileError AFTFileDriver::Read(LPCTSTR filename,PersistentModel& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	CStdioFile File;
	if(Open(filename,File,CFile::modeRead|CFile::typeText))
	{
		errorMark = Read(File,model);
		File.Close();
	}
	else
	{
		
	}
	return errorMark;
}

ErrorStatus::FileError AFTFileDriver::Save(LPCTSTR filename,PersistentModel& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	CStdioFile File;
	if(Open(filename,File,CFile::modeWrite|CFile::modeCreate|CFile::typeText))
	{
		errorMark = Save(File,model);
		File.Close();
	}
	else
	{
		
	}	

	return errorMark;
}


ErrorStatus::FileError AFTFileDriver::Read(CStdioFile &File,PersistentModel& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	CString strData;
	File.ReadString(strData);
	if(CheckMark(strData))
	{
		AFTDriverMgr mgr;
		if(mgr.Read(File))
		{
			errorMark = m_ScenarioMgr.Read(mgr.GetScenarioMgr(),model.GetScenarioPersist());
		}
		else
		{
			
		}
	}
	else
	{
		errorMark = ErrorStatus::eFileTypeError;
	}
	return errorMark;
}

ErrorStatus::FileError AFTFileDriver::Save(CStdioFile &File,PersistentModel& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	AFTDriverMgr mgr;
	mgr.Init();
	errorMark = m_ScenarioMgr.Save(mgr.GetScenarioMgr(),model.GetScenarioPersist());
	File.WriteString(ms_fileMark+"\n");
	mgr.Save(File);
	return errorMark;
}

BOOL AFTFileDriver::CheckMark(CString strMark)
{
	bool changeflag ;
	strMark.TrimLeft();
	strMark.TrimRight();
	changeflag = PersistentObj::isImpFile ;
	strMark = changefilemark( changeflag ) ;
	if(0 ==ms_fileMark.CompareNoCase(strMark))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}




// CalcFileDriver.cpp: implementation of the CalcFileDriver class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcFileDriver.h"
#include "CaclDriverMgr.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcFileDriver::CalcFileDriver()
{

}

CalcFileDriver::~CalcFileDriver()
{

}

Driver* CalcFileDriver::CreatCalcDriver()
{
	return new CalcFileDriver;
}

ErrorStatus::FileError CalcFileDriver::Read(LPCTSTR filename,PersistentModel& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	return errorMark;
}

ErrorStatus::FileError CalcFileDriver::Save(LPCTSTR filename,PersistentModel& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	ofstream File;
	File.open(filename,ios::out);
	if(!File.fail())
	{
		errorMark = Save(File,model);
		File.close();
	}
	else
	{
		errorMark = ErrorStatus::eSaveFileError;
	}
	return errorMark;
}

ErrorStatus::FileError CalcFileDriver::Save(ofstream &File,PersistentModel& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	CalcDriverMgr CalcDriver;
	errorMark = m_fileFace.Save(CalcDriver,model);
	CalcDriver.Save(File);
	return errorMark;
}
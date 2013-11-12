// PCFDriver.cpp: implementation of the PCFDriver class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFFileDriver.h"
#include "PCFDriverModel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFFileDriver::PCFFileDriver()
{

}

PCFFileDriver::~PCFFileDriver()
{

}

Driver* PCFFileDriver::CreatPCFDriver()
{
	return new PCFFileDriver;
}

ErrorStatus::FileError PCFFileDriver::Read(LPCTSTR filename, PersistentModel &model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	CStdioFile File;
	if(Open(filename,File,CFile::modeRead))
	{
		errorMark = Read(File,model);
		File.Close();
	}
	else
	{
		AfxMessageBox(_T("¶ÁÈ¡pcfÎÄ¼þÊ§°Ü"));
		errorMark = ErrorStatus::eReadFileError;
	}
	return errorMark;
}

ErrorStatus::FileError PCFFileDriver::Save(LPCTSTR filename, PersistentModel &model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	return errorMark;
}

ErrorStatus::FileError PCFFileDriver::Read(CStdioFile &File, PersistentModel &model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	PCFDriverModel driver;
	if(driver.Read(File))
	{
		m_fileFce.Read(driver,model);
	}
	return errorMark;
}

// PCFDriver.h: interface for the PCFDriver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFDRIVER_H__E0D040A7_39A9_4CB3_A0EB_8AEC6F3AEAA0__INCLUDED_)
#define AFX_PCFDRIVER_H__E0D040A7_39A9_4CB3_A0EB_8AEC6F3AEAA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Driver.h"
#include "PCFFileFace.h"

class PCFFileDriver : public Driver  
{
public:
	static Driver* CreatPCFDriver();
	ErrorStatus::FileError Save(LPCTSTR filename,PersistentModel& model);
	ErrorStatus::FileError Read(LPCTSTR filename,PersistentModel& model);
	PCFFileDriver();
	virtual ~PCFFileDriver();

private:
	ErrorStatus::FileError Read(CStdioFile &File,PersistentModel& model);
	PCFFileFace m_fileFce;
};

#endif // !defined(AFX_PCFDRIVER_H__E0D040A7_39A9_4CB3_A0EB_8AEC6F3AEAA0__INCLUDED_)

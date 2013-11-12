// CalcFileDriver.h: interface for the CalcFileDriver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCFILEDRIVER_H__1BE59830_C7B6_4F29_AF18_0AE5862CE7FE__INCLUDED_)
#define AFX_CALCFILEDRIVER_H__1BE59830_C7B6_4F29_AF18_0AE5862CE7FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Driver.h"
#include "CalcFileFace.h"

class CalcFileDriver : public Driver    
{
public:
	CalcFileDriver();
	virtual ~CalcFileDriver();
	static Driver* CreatCalcDriver();
	ErrorStatus::FileError Read(LPCTSTR filename,PersistentModel& model);
	ErrorStatus::FileError Save(LPCTSTR filename,PersistentModel& model);
private:
	ErrorStatus::FileError Save(ofstream &File,PersistentModel& model);
	CalcFileFace m_fileFace;
};

#endif // !defined(AFX_CALCFILEDRIVER_H__1BE59830_C7B6_4F29_AF18_0AE5862CE7FE__INCLUDED_)

// EduceFromFile.h: interface for the CEduceFromFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDUCEFROMFILE_H__D0517337_9435_40EE_8C54_207D1ACC83D9__INCLUDED_)
#define AFX_EDUCEFROMFILE_H__D0517337_9435_40EE_8C54_207D1ACC83D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEduceFromFile  
{
public:
	CEduceFromFile();
	virtual ~CEduceFromFile();
	BOOL ReadFile(CalcTable<2> &DBTable);
	
private:	
	void SlipeString(CString &strFront, CString &strBack, CString strSource);
	CString m_strFilePath;
	void GetFilePath();
};

#endif // !defined(AFX_EDUCEFROMFILE_H__D0517337_9435_40EE_8C54_207D1ACC83D9__INCLUDED_)

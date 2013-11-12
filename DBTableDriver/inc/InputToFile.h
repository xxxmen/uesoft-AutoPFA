// InputToFile.h: interface for the CInputToFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INPUTTOFILE_H__C0ABB3AD_8D15_45D6_BC57_99C0A723EACC__INCLUDED_)
#define AFX_INPUTTOFILE_H__C0ABB3AD_8D15_45D6_BC57_99C0A723EACC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CInputToFile  
{
public:	
	void SetDAtaToFile(CalcTable<2> &DBTable);
	CInputToFile();
	virtual ~CInputToFile();

private:
	CString m_strFilePath;
	void GetFilePath();
};

#endif // !defined(AFX_INPUTTOFILE_H__C0ABB3AD_8D15_45D6_BC57_99C0A723EACC__INCLUDED_)
